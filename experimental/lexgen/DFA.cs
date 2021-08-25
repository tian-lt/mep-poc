using System.Collections.Generic;

namespace LexGen
{
    public class DFA
    {
        public class State
        {
            public delegate void EnterDelegate(State s);
            public EnterDelegate OnEnter { get; set; }
            public Dictionary<char, State> NextStates;
        }

        public State StartState
        {
            get => s0;
            set => s0 = value;
        }

        public bool Accept(string text)
        {
            State s = s0;
            int idx = 0;
            while(idx < text.Length)
            {
                var c = text[idx];
                s = s.NextStates[c];
                s.OnEnter?.Invoke(s);
                ++idx;
            }
            
            return true;
        }

        private State s0;
    }
}
