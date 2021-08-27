using System;

namespace LexGen
{
    class Program
    {
        static void Main(string[] args)
        {
            NFAUtils.ParseRE("abc|d");
            Console.WriteLine();
        }
    }
}
