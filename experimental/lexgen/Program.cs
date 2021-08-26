using System;

namespace LexGen
{
    class Program
    {
        static void Main(string[] args)
        {
            NFAUtils.ParseRE("ab(cdD)abc");
        }
    }
}
