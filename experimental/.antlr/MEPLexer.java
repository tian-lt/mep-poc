// Generated from g:\work-repos\github\mep-poc\experimental\MEPLexer.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MEPLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Dot=1, Plus=2, Minus=3, Mul=4, Div=5, Caret=6, Percent=7, E=8, Comma=9, 
		LeftParen=10, RightParen=11, Integer=12, Float=13, Identifier=14, Whitespace=15, 
		Newline=16;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"Dot", "Plus", "Minus", "Mul", "Div", "Caret", "Percent", "E", "Comma", 
			"LeftParen", "RightParen", "DIGIT", "NONDIGIT", "Integer", "Float", "Identifier", 
			"HEXDIGIT", "Whitespace", "Newline"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'.'", "'+'", "'-'", "'*'", "'/'", "'^'", "'%'", null, "','", "'('", 
			"')'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "Dot", "Plus", "Minus", "Mul", "Div", "Caret", "Percent", "E", 
			"Comma", "LeftParen", "RightParen", "Integer", "Float", "Identifier", 
			"Whitespace", "Newline"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public MEPLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "MEPLexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\22o\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3"+
		"\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\6\17E"+
		"\n\17\r\17\16\17F\3\20\3\20\3\20\5\20L\n\20\3\20\5\20O\n\20\3\20\3\20"+
		"\3\20\5\20T\n\20\3\21\3\21\3\21\7\21Y\n\21\f\21\16\21\\\13\21\3\22\3\22"+
		"\3\23\6\23a\n\23\r\23\16\23b\3\23\3\23\3\24\3\24\5\24i\n\24\3\24\5\24"+
		"l\n\24\3\24\3\24\2\2\25\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f"+
		"\27\r\31\2\33\2\35\16\37\17!\20#\2%\21\'\22\3\2\7\4\2GGgg\3\2\62;\5\2"+
		"C\\aac|\5\2\62;CHch\4\2\13\13\"\"\2t\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2"+
		"\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23"+
		"\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2"+
		"\2\2%\3\2\2\2\2\'\3\2\2\2\3)\3\2\2\2\5+\3\2\2\2\7-\3\2\2\2\t/\3\2\2\2"+
		"\13\61\3\2\2\2\r\63\3\2\2\2\17\65\3\2\2\2\21\67\3\2\2\2\239\3\2\2\2\25"+
		";\3\2\2\2\27=\3\2\2\2\31?\3\2\2\2\33A\3\2\2\2\35D\3\2\2\2\37S\3\2\2\2"+
		"!U\3\2\2\2#]\3\2\2\2%`\3\2\2\2\'k\3\2\2\2)*\7\60\2\2*\4\3\2\2\2+,\7-\2"+
		"\2,\6\3\2\2\2-.\7/\2\2.\b\3\2\2\2/\60\7,\2\2\60\n\3\2\2\2\61\62\7\61\2"+
		"\2\62\f\3\2\2\2\63\64\7`\2\2\64\16\3\2\2\2\65\66\7\'\2\2\66\20\3\2\2\2"+
		"\678\t\2\2\28\22\3\2\2\29:\7.\2\2:\24\3\2\2\2;<\7*\2\2<\26\3\2\2\2=>\7"+
		"+\2\2>\30\3\2\2\2?@\t\3\2\2@\32\3\2\2\2AB\t\4\2\2B\34\3\2\2\2CE\5\31\r"+
		"\2DC\3\2\2\2EF\3\2\2\2FD\3\2\2\2FG\3\2\2\2G\36\3\2\2\2HI\5\35\17\2IK\5"+
		"\3\2\2JL\5\35\17\2KJ\3\2\2\2KL\3\2\2\2LT\3\2\2\2MO\5\35\17\2NM\3\2\2\2"+
		"NO\3\2\2\2OP\3\2\2\2PQ\5\3\2\2QR\5\35\17\2RT\3\2\2\2SH\3\2\2\2SN\3\2\2"+
		"\2T \3\2\2\2UZ\5\33\16\2VY\5\31\r\2WY\5\33\16\2XV\3\2\2\2XW\3\2\2\2Y\\"+
		"\3\2\2\2ZX\3\2\2\2Z[\3\2\2\2[\"\3\2\2\2\\Z\3\2\2\2]^\t\5\2\2^$\3\2\2\2"+
		"_a\t\6\2\2`_\3\2\2\2ab\3\2\2\2b`\3\2\2\2bc\3\2\2\2cd\3\2\2\2de\b\23\2"+
		"\2e&\3\2\2\2fh\7\17\2\2gi\7\f\2\2hg\3\2\2\2hi\3\2\2\2il\3\2\2\2jl\7\f"+
		"\2\2kf\3\2\2\2kj\3\2\2\2lm\3\2\2\2mn\b\24\2\2n(\3\2\2\2\f\2FKNSXZbhk\3"+
		"\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}