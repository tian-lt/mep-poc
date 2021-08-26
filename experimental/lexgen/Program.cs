using System;

namespace LexGen
{
    class Program
    {
        static void Main(string[] args)
        {
            NFAUtils.ParseRE("(a|b|cd)*");
            NFAUtils.ParseRE("(a|b|(cd))*c");
        }
    }
}
