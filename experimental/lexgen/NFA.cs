using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text.Json;

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
                     <'('> <expr> <')'>
                   | <expr> <'|'> <expr>
                   | (<character> | (<'('> <expr> <')'>)) <'*'>
                   | <expr> (omitted AND) <expr>
                   | <character>
          - character ::= <[a-zA-Z0-9_]>
          - escape character: '\'
          - RE('\\') represents TEXT('\')

         Remove the left-recursive rules and then we have below rules:
          - expr ::=
                     <and_expr>
                   | <or_expr>
                   | <lexpr>
          - and_expr ::=
                   | <lexpr> <expr>
          - or_expr ::= <lexpr> <'|'> <expr>
          - lexpr ::=
                     <repeat_expr>
                   | <pexpr>
                   | <character>
          - repeat_expr ::=
                     <character> <'*'>
                   | <pexpr> <'*'>
          - pexpr ::= <'('> expr <')'>
          - character ::= <[a-zA-Z0-9_]>
         */
        public static void ParseRE(string text)
        {
            Expr(text, out var txtView, out var expr);
#if DEBUG
            Console.WriteLine(JsonSerializer.Serialize(expr));
            Debug.Assert(txtView.Length == 0);
#endif
        }

        private static bool Expr(StringView text, out StringView outText, out ASTNodeExpr outExpr)
        {
            outExpr = null;
            outText = text.Clone();
            if(OrExpr(outText, out var tmpText, out var oexpr))
            {
                outExpr = Ensure(outExpr);
                outExpr.OrExpr = oexpr;
                outText = tmpText;
                return true;
            }
            if(AndExpr(outText, out tmpText, out var aexpr))
            {
                outExpr = Ensure(outExpr);
                outExpr.AndExpr = aexpr;
                outText = tmpText;
                return true;
            }
            if(LExpr(outText, out tmpText, out var lexpr))
            {
                outExpr = Ensure(outExpr);
                outExpr.LHSExpr = lexpr;
                outText = tmpText;
                return true;
            }
            return false;
        }
        private static bool AndExpr(StringView text, out StringView outText, out ASTNodeAndExpr outExpr)
        {
            outExpr = null;
            outText = text.Clone();
            if(LExpr(outText, out var tmpText, out var lexpr)
                && tmpText.Length > 0
                && Expr(tmpText, out tmpText, out var expr))
            {
                outExpr = Ensure(outExpr);
                outExpr.LeftExpr = lexpr;
                outExpr.RightExpr = expr;
                outText = tmpText;
                return true;
            }
            return false;
        }

        private static bool OrExpr(StringView text, out StringView outText, out ASTNodeOrExpr outExpr)
        {
            outExpr = null;
            outText = text.Clone();
            if(LExpr(text, out var tmpText, out var lexpr)
                && tmpText.Matches('|'))
            {
                tmpText.IncLeftBound();
                if (Expr(tmpText, out tmpText, out var expr))
                {
                    outExpr = Ensure(outExpr);
                    outExpr.LeftExpr = lexpr;
                    outExpr.RightExpr = expr;
                    outText = tmpText;
                    return true;
                }
            }
            return false;
        }

        private static bool RepeatExpr(StringView text, out StringView outText, out ASTNodeRepeatExpr outExpr)
        {
            outExpr = null;
            outText = text.Clone();
            if(text.Length > 1)
            {
                if(IsCharacter(text[0]) && text[1] == '*')
                {
                    outExpr = Ensure(outExpr);
                    outExpr.Character = text[0];
                    outText.IncLeftBound(2);
                    return true;
                }
            }
            if(PExpr(outText, out var tmpText, out var pexpr)
                && tmpText.Matches('*'))
            {
                outExpr = Ensure(outExpr);
                outExpr.ParenExpr = pexpr;
                outText = tmpText;
                outText.IncLeftBound();
                return true;
            }
            return false;
        }

        private static bool LExpr(StringView text, out StringView outText, out ASTNodeLExpr outExpr)
        {
            outExpr = null;
            outText = text.Clone();
            if(RepeatExpr(outText, out var tmpText, out var rexpr))
            {
                outExpr = Ensure(outExpr);
                outExpr.RepeatExpr = rexpr;
                outText = tmpText;
                return true;
            }
            if(PExpr(outText, out tmpText, out var pexpr))
            {
                outExpr = Ensure(outExpr);
                outExpr.ParenExpr = pexpr;
                outText = tmpText;
                return true;
            }
            if(outText.Length > 0 && IsCharacter(outText[0]))
            {
                outExpr = Ensure(outExpr);
                outExpr.Character = outText[0];
                outText.IncLeftBound();
                return true;
            }
            return false;
        }
        
        private static bool PExpr(StringView text, out StringView outText, out ASTNodeParenthesizedExpr outExpr)
        {
            outExpr = null;
            outText = text.Clone();
            if(text.Matches('('))
            {
                outText.IncLeftBound();
                if(Expr(outText, out var tmpText, out var expr)
                    && tmpText.Matches(')'))
                {
                    outText = tmpText;
                    outText.IncLeftBound();
                    outExpr = Ensure(outExpr);
                    outExpr.Expr = expr;
                    return true;
                }
            }
            return false;
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

        private static bool IsCharacter(char c)
        {
            return ('a' <= c && c <= 'z')
                || ('A' <= c && c <= 'Z')
                || ('0' <= c && c <= '9')
                || c == '_';
        }

        private static bool IsExprStartingSymbol(char c)
        {
            return IsCharacter(c)
                || c == '(';
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
            [System.Text.Json.Serialization.JsonIgnore(Condition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull)]
            public ASTNodeAndExpr AndExpr { get; set; }
            [System.Text.Json.Serialization.JsonIgnore(Condition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull)]
            public ASTNodeOrExpr OrExpr { get; set; }
            [System.Text.Json.Serialization.JsonIgnore(Condition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull)]
            public ASTNodeLExpr LHSExpr { get; set; }
        }

        private class ASTNodeRepeatExpr
        {
            public char Character { get; set; } = (char)0;
            [System.Text.Json.Serialization.JsonIgnore(Condition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull)]
            public ASTNodeParenthesizedExpr ParenExpr { get; set; }
        }

        private class ASTNodeOrExpr
        {
            public ASTNodeLExpr LeftExpr { get; set; }
            public ASTNodeExpr RightExpr { get; set; }
        }

        private class ASTNodeAndExpr
        {
            public ASTNodeLExpr LeftExpr { get; set; }
            [System.Text.Json.Serialization.JsonIgnore(Condition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull)]
            public ASTNodeExpr RightExpr { get; set; }
        }

        private class ASTNodeLExpr
        {
            [System.Text.Json.Serialization.JsonIgnore(Condition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull)]
            public ASTNodeRepeatExpr RepeatExpr { get; set; }
            [System.Text.Json.Serialization.JsonIgnore(Condition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull)]
            public ASTNodeParenthesizedExpr ParenExpr { get; set; }
            [System.Text.Json.Serialization.JsonIgnore(Condition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingDefault)]
            public char Character { get; set; } = (char)0;
        }

        private class ASTNodeParenthesizedExpr
        {
            public ASTNodeExpr Expr { get; set; } 
        }

        private class StringView
        {
            public StringView()
            {
                Begin = 0;
                End = 0;
                Source = null;
            }

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

            public StringView SubView(int beg, int end = 0)
            {
                var result = this.Clone();
                result.Begin = this.Begin + beg;
                result.End = this.End + end;
                return result;
            }

            public StringView Clone()
            {
                return new StringView
                {
                    Source = this.Source,
                    Begin = this.Begin,
                    End = this.End
                };
            }
            public void IncLeftBound()
            {
                ++Begin;
            }

            public void IncLeftBound(int count)
            {
                Begin += count;
            }

            public bool Matches(char c)
            {
                return Length > 0
                    && this[0] == c;
            }

            public char this [int key] => Source[key + Begin];
            public static implicit operator StringView(string src) => new StringView(src);
        }
    }
}