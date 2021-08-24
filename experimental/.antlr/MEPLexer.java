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
		Dot=1, Plus=2, Minus=3, Mul=4, Div=5, Caret=6, Percent=7, E=8, LeftParen=9, 
		RightParen=10, Integer=11, Float=12, SciNumber=13, Identifier=14, HexNumber=15, 
		Whitespace=16, Newline=17;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"Dot", "Plus", "Minus", "Mul", "Div", "Caret", "Percent", "E", "LeftParen", 
			"RightParen", "DIGIT", "NONDIGIT", "Integer", "Float", "SciNumber", "Identifier", 
			"HEXDIGIT", "HexNumber", "Whitespace", "Newline"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'.'", "'+'", "'-'", "'*'", "'/'", "'^'", "'%'", null, "'('", "')'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "Dot", "Plus", "Minus", "Mul", "Div", "Caret", "Percent", "E", 
			"LeftParen", "RightParen", "Integer", "Float", "SciNumber", "Identifier", 
			"HexNumber", "Whitespace", "Newline"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\23|\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6"+
		"\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\6\16E"+
		"\n\16\r\16\16\16F\3\17\3\17\3\17\5\17L\n\17\3\17\5\17O\n\17\3\17\3\17"+
		"\3\17\5\17T\n\17\3\20\3\20\3\20\3\20\5\20Z\n\20\3\20\3\20\3\21\3\21\3"+
		"\21\7\21a\n\21\f\21\16\21d\13\21\3\22\3\22\3\23\6\23i\n\23\r\23\16\23"+
		"j\3\24\6\24n\n\24\r\24\16\24o\3\24\3\24\3\25\3\25\5\25v\n\25\3\25\5\25"+
		"y\n\25\3\25\3\25\2\2\26\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f"+
		"\27\2\31\2\33\r\35\16\37\17!\20#\2%\21\'\22)\23\3\2\7\4\2GGgg\3\2\62;"+
		"\5\2C\\aac|\5\2\62;CHch\4\2\13\13\"\"\2\u0083\2\3\3\2\2\2\2\5\3\2\2\2"+
		"\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3"+
		"\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2"+
		"\2\2!\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\3+\3\2\2\2\5-\3\2\2\2"+
		"\7/\3\2\2\2\t\61\3\2\2\2\13\63\3\2\2\2\r\65\3\2\2\2\17\67\3\2\2\2\219"+
		"\3\2\2\2\23;\3\2\2\2\25=\3\2\2\2\27?\3\2\2\2\31A\3\2\2\2\33D\3\2\2\2\35"+
		"S\3\2\2\2\37U\3\2\2\2!]\3\2\2\2#e\3\2\2\2%h\3\2\2\2\'m\3\2\2\2)x\3\2\2"+
		"\2+,\7\60\2\2,\4\3\2\2\2-.\7-\2\2.\6\3\2\2\2/\60\7/\2\2\60\b\3\2\2\2\61"+
		"\62\7,\2\2\62\n\3\2\2\2\63\64\7\61\2\2\64\f\3\2\2\2\65\66\7`\2\2\66\16"+
		"\3\2\2\2\678\7\'\2\28\20\3\2\2\29:\t\2\2\2:\22\3\2\2\2;<\7*\2\2<\24\3"+
		"\2\2\2=>\7+\2\2>\26\3\2\2\2?@\t\3\2\2@\30\3\2\2\2AB\t\4\2\2B\32\3\2\2"+
		"\2CE\5\27\f\2DC\3\2\2\2EF\3\2\2\2FD\3\2\2\2FG\3\2\2\2G\34\3\2\2\2HI\5"+
		"\33\16\2IK\5\3\2\2JL\5\33\16\2KJ\3\2\2\2KL\3\2\2\2LT\3\2\2\2MO\5\33\16"+
		"\2NM\3\2\2\2NO\3\2\2\2OP\3\2\2\2PQ\5\3\2\2QR\5\33\16\2RT\3\2\2\2SH\3\2"+
		"\2\2SN\3\2\2\2T\36\3\2\2\2UV\5\35\17\2VY\5\21\t\2WZ\5\5\3\2XZ\5\7\4\2"+
		"YW\3\2\2\2YX\3\2\2\2Z[\3\2\2\2[\\\5\33\16\2\\ \3\2\2\2]b\5\31\r\2^a\5"+
		"\27\f\2_a\5\31\r\2`^\3\2\2\2`_\3\2\2\2ad\3\2\2\2b`\3\2\2\2bc\3\2\2\2c"+
		"\"\3\2\2\2db\3\2\2\2ef\t\5\2\2f$\3\2\2\2gi\5#\22\2hg\3\2\2\2ij\3\2\2\2"+
		"jh\3\2\2\2jk\3\2\2\2k&\3\2\2\2ln\t\6\2\2ml\3\2\2\2no\3\2\2\2om\3\2\2\2"+
		"op\3\2\2\2pq\3\2\2\2qr\b\24\2\2r(\3\2\2\2su\7\17\2\2tv\7\f\2\2ut\3\2\2"+
		"\2uv\3\2\2\2vy\3\2\2\2wy\7\f\2\2xs\3\2\2\2xw\3\2\2\2yz\3\2\2\2z{\b\25"+
		"\2\2{*\3\2\2\2\16\2FKNSY`bjoux\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}