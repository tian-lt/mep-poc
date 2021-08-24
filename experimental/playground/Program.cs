using System;
using Antlr4.Runtime;

namespace playground
{
    class Program
    {
        const string testSource = " 10 1a 1.1111 1e+10 1.e+10 1.23e-10 .1 1.";
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
