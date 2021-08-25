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
          - expr ::= <character>*
                   | <expr> <|> <expr>
                   | <expr> <*>
                   | <(> <expr> <)>
          - escape character: '\'
          - RE('\\') represents TEXT('\')
         */
        public static void ParseRE(string text)
        {
            ParseContext pc = new ParseContext();
            int idx = 0;
            while (idx < text.Length)
            {
                var c = text[idx];
                if (c == '\\')
                {
                    pc.EscapeMark = !pc.EscapeMark;
                    if (pc.EscapeMark)
                    {
                        ++idx;
                        continue;
                    }
                }

                if (!pc.EscapeMark)
                {
                    if(!IsOperator(c))
                    {
                        // a operand
                        pc.OutputQueue.Enqueue(new ParseContext.ParseElement
                        {
                            ParseElementType = ParseContext.ParseElement.PEType.NFA,
                            Element = CreateBasicNFA(c)
                        });
                    }
                    else if(!IsParenthesis(c))
                    { // a pure operator
                        while(pc.OperatorStack.Count > 0
                            && pc.OperatorStack.Peek().ParseElementType != ParseContext.ParseElement.PEType.LeftParen
                            && IsOperator(pc.OperatorStack.Peek().ParseElementType)) // TODO: compare the precedence
                        {
                            pc.OutputQueue.Enqueue(pc.OperatorStack.Pop());
                        }
                        pc.OperatorStack.Push(new ParseContext.ParseElement
                        {
                            ParseElementType = ParseContext.ParseElement.Char2PEType[c],
                            Element = c
                        });
                    }
                    else if(c == '(')
                    { // a left-parenthesis
                        pc.OperatorStack.Push(new ParseContext.ParseElement
                        {
                            ParseElementType = ParseContext.ParseElement.PEType.LeftParen,
                            Element = c
                        });
                    }
                    else if(c == ')')
                    { // a right-parenthesis
                        while(pc.OperatorStack.Peek().ParseElementType != ParseContext.ParseElement.PEType.LeftParen)
                        {
                            pc.OutputQueue.Enqueue(pc.OperatorStack.Pop());
                        }
                        pc.OperatorStack.Pop();
                    }
                    else
                    {
                        throw new Exception("parser: fatal error: uncaught input character.");
                    }
                }
                ++idx;
            } // While Ends

            while(pc.OperatorStack.Count > 0)
            {
                pc.OutputQueue.Enqueue(pc.OperatorStack.Pop());
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

        private static bool IsOperator(char c)
        {
            return (c == '('
                || c == ')'
                || c == '*'
                || c == '|');
        }

        private static bool IsOperator(ParseContext.ParseElement.PEType pet)
        {
            return pet == ParseContext.ParseElement.PEType.LeftParen
                || pet == ParseContext.ParseElement.PEType.RightParen
                || pet == ParseContext.ParseElement.PEType.Star
                || pet == ParseContext.ParseElement.PEType.Or;
        }

        private static bool IsParenthesis(char c)
        {
            return c == '(' || c == ')';
        }

        private class ParseContext
        {
            public class ParseElement
            {
                public enum PEType
                {
                    NFA,
                    LeftParen,
                    RightParen,
                    Star,
                    Or
                }

                public PEType ParseElementType { get; set; }
                public object Element { get; set; }

                public static readonly Dictionary<char, PEType> Char2PEType = new Dictionary<char, PEType>()
                {
                    {'(', PEType.LeftParen },
                    {')', PEType.RightParen},
                    {'*', PEType.Star},
                    {'|', PEType.Or},
                };
            }

            public bool EscapeMark { get; set; } = false;
            public Queue<ParseElement> OutputQueue = new Queue<ParseElement>();   // Shunting-Yard - Output Queue
            public Stack<ParseElement> OperatorStack = new Stack<ParseElement>(); // Shunting-Yard - Operator Stack
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