using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace LexGen
{
    public class NFA
    {
        public const char Epsilon = (char)0;
        public class State 
        {
            public Dictionary<char, List<State>> NextStates { get; set; } = new Dictionary<char, List<State>>();
            public int StateId { get; set; }

            public State()
            {
                StateId = ++GlobalStateId;
            }

            public void AddNextState(char c, State s)
            {
                if(!NextStates.ContainsKey(c))
                {
                    NextStates[c] = new List<State>();
                }
                NextStates[c].Add(s);
            }

            private static int GlobalStateId = 0;
        }

        public State iState { get; set; } = new State();
        public State fState { get; set; } = new State();

        public NFA()
        {}
    }

    public static class NFAUtils
    {
        /*
         Regular Expression(RE) syntax rule
          - expr ::=
                   | <'('> <expr> <')'>
                   | <expr> <'|'> <expr>
                   | <expr> <'*'>
                   | <word>
          - word ::= <[a-zA-Z0-9_]>+
          - escape character: '\'
          - RE('\\') represents TEXT('\')

         Remove the left-recursive rules and then we have below rules:
          - expr ::=
                   | <pexpr>
                   | <lexpr> <'|'> <expr>
                   | <lexpr> <'*'>
                   | <word>
          - lexpr ::=
                   | <pexpr>
                   | <word>
          - pexpr ::= <'('> expr <')'>
          - word ::= <[a-zA-Z0-9_]>+
         */
        public static void ParseRE(string text)
        {
            Expr(text, out var txtView, out var expr);
        }

        private static void Expr(StringView text, out StringView outText, out ASTNodeExpr outExpr)
        {
            outExpr = null;
            PExpr(text, out var tmpText, out var pexpr);
            if(pexpr != null)
            {
                outExpr = Ensure(outExpr);
                outExpr.ParenExpr = pexpr;
                outText = tmpText;
                return;
            }
            Word(text, out tmpText, out var word);
            if(word != null)
            {
                outExpr = Ensure(outExpr);
                outExpr.Word = word;
                outText = tmpText;
                return;
            }
            outText = text;
        }

        private static void LExpr(StringView text, out StringView outText, out ASTNodeLExpr outExpr)
        {
            outExpr = null;
            PExpr(text, out var tmpText, out var pexpr);
            if(pexpr != null)
            {
                outExpr = Ensure(outExpr);
                outExpr.ParenExpr = pexpr;
                outText = tmpText;
                return;
            }
            Word(text, out tmpText, out var word);
            if(word != null)
            {
                outExpr = Ensure(outExpr);
                outExpr.Word = word;
                outText = tmpText;
                return;
            }
            outText = text;
        }

        private static void PExpr(StringView text, out StringView outText, out ASTNodeParenthesizedExpr outExpr)
        {
            outExpr = null;
            outText = text;
            if(text.Length <= 0)
            {
                return;
            }
            else
            {
                if(text[0] == '(')
                {
                    ++text.Begin;
                    Expr(text, out var tmpText, out var expr);
                    if(expr != null && tmpText.Length > 0 && tmpText[0] == ')')
                    {
                        outText = tmpText;
                        ++outText.Begin;
                        outExpr = Ensure(outExpr);
                        outExpr.Expr = expr;
                        return;
                    }
                }
            }
        }

        private static void Word(StringView text, out StringView outText, out ASTNodeWord outWord)
        {
            outWord = null;
            outText = text;
            if(text.Length <= 0)
            {
                return;
            }
            else
            {
                int cursor = text.Begin;
                while(cursor < text.End)
                {
                    var c = text[cursor++];
                    if(IsWord(c))
                    {
                        outWord = Ensure(outWord);
                        outWord.Word += c;
                    }
                    else
                    {
                        --cursor;
                        break;
                    }
                }
                outText.Begin = cursor;
            }
        }

        /*
         RE: r = s*
         ---start--> s(i) ---e--> s(i) N(s) s(f) ---e--> s(f)
                      |            ^         |            ^
                      |            |---------|            |
                      |-----------------e-----------------|
         */
        private static NFA CreateRepeatingNFA(NFA s)
        {
            var r = new NFA();
            r.iState.AddNextState(NFA.Epsilon, s.iState);
            r.iState.AddNextState(NFA.Epsilon, r.fState);
            s.fState.AddNextState(NFA.Epsilon, s.iState);
            return r;
        }

        /*
         RE: r = s|t
                        ---e--> s(i) N(s) s(f) --e--
                       /                             \
                      /                               *
        ---start--> s(i)                             s(f)
                      \                               ^
                       \                             /
                        ---e--> s(i) N(t) s(f) --e--
         */
        private static NFA CreateOrNFA(NFA s, NFA t)
        {
            var r = new NFA();
            r.iState.AddNextState(NFA.Epsilon, s.iState);
            r.iState.AddNextState(NFA.Epsilon, t.iState);
            s.fState.AddNextState(NFA.Epsilon, r.fState);
            t.fState.AddNextState(NFA.Epsilon, r.fState);
            return r;
        }

        /*
         RE: r = st
         ---start--> s(i) N(s) s(f) N(t) s(f)
         */
        private static NFA CreateAndNFA(NFA s, NFA t)
        {
            var r = new NFA();
            r.iState = s.iState;
            s.fState = t.iState;
            r.fState = t.fState;
            return r;
        }

        /*
         RE: r = a
                           N(a)
         ---start--> s(i) ---a--> s(f)
         */
        private static NFA CreateBasicNFA(char a)
        {
            var r = new NFA();
            var m = new NFA.State();
            r.iState.AddNextState(a, m);
            m.AddNextState(NFA.Epsilon, r.fState);
            return r;
        }

        private static bool IsWord(char c)
        {
            return ('a' <= c && c <= 'z')
                || ('A' <= c && c <= 'Z')
                || ('0' <= c && c <= '9')
                || c == '_';
        }

        private static bool IsOperator(char c)
        {
            return (c == '('
                || c == ')'
                || c == '*'
                || c == '|');
        }

        private static bool IsParenthesis(char c)
        {
            return c == '(' || c == ')';
        }

        private static T Ensure<T>(T target) where T : class, new()
        {
            if(target == null)
            {
                target = new T();
            }
            return target;
        }

        private class ASTNodeExpr
        {
            public ASTNodeWord Word { get; set; }
            public ASTNodeParenthesizedExpr ParenExpr { get; set; }
        }

        private class ASTNodeWord
        {
            public string Word { get; set; } = string.Empty;
        }

        private class ASTNodeLExpr
        {
            public ASTNodeWord Word { get; set; }
            public ASTNodeParenthesizedExpr ParenExpr { get; set; }
        }

        private class ASTNodeParenthesizedExpr
        {
            public ASTNodeExpr Expr { get; set; } 
        }

        private class StringView
        {
            public StringView(string src)
            {
                Source = src;
                Begin = 0;
                End = src.Length;
            }

            public StringView(string src, int beg, int end)
            {
                Source = src;
                Begin = beg;
                End = end;
            }

            public int Begin { get; set; }
            public int End { get; set; }
            public string Source { get; set; }

            public int Length { get => End - Begin; }

            public char this [int key] => Source[key + Begin];
            public static implicit operator StringView(string src) => new StringView(src);
        }

        private class ParseContext
        {
            public string Text { get; set; }
            public char Symbol { get; set; } = (char)0;
            public bool EOT { get; set; } = false;
            public int Cursor { get; set; } = -1;

            public void NextSymbol()
            {
                ++Cursor;
                if(Cursor < Text.Length)
                {
                    Symbol = Text[Cursor];
                }
                else
                {
                    EOT = true;
                }
            }
        }
    }

    public static partial class DebugUtils
    {
        public static string DumpState(this NFA.State s)
        {
            string eages = "";
            foreach(var n in s.NextStates)
            {
                string ns = $"{n.Key}->{{";
                foreach(var e in n.Value)
                {
                    ns += $"{e},";
                }
                ns += "}";
                eages += $"{ns},";
            }
            return $"s({s.StateId}, {eages})";
        }

        public static string DumpNFA(this NFA nfa)
        {
            return $"i={nfa.iState.DumpState()}, f={nfa.fState.DumpState()}";
        }
    }
}