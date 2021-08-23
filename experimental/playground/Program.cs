using System;
using Antlr4.Runtime;

namespace playground
{
    class Program
    {
        const string testSource = " 10 1a 1.1111";
        static void Main(string[] args)
        {
            var stream = CharStreams.fromstring(testSource);
            var lexer = new MEPLexer(stream);
            var tokens = new CommonTokenStream(lexer);
            tokens.Fill();
            var c = tokens.GetTokens();
        }
    }
}
