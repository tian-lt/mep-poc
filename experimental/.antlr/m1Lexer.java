// Generated from g:\work-repos\github\mep-poc\experimental\m1.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class m1Lexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Plus=1, Minus=2, Mul=3, Div=4, Caret=5, Fact=6, Percent=7, LeftP=8, RightP=9, 
		Comma=10, Number=11, Identifier=12, Whitespace=13;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"Plus", "Minus", "Mul", "Div", "Caret", "Fact", "Percent", "LeftP", "RightP", 
			"Comma", "Number", "Identifier", "Whitespace"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'+'", "'-'", "'*'", "'/'", "'^'", "'!'", "'%'", "'('", "')'", 
			"','"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "Plus", "Minus", "Mul", "Div", "Caret", "Fact", "Percent", "LeftP", 
			"RightP", "Comma", "Number", "Identifier", "Whitespace"
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


	public m1Lexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "m1.g4"; }

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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\17D\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6"+
		"\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\6\f\63\n\f\r\f\16\f\64"+
		"\3\r\3\r\7\r9\n\r\f\r\16\r<\13\r\3\16\6\16?\n\16\r\16\16\16@\3\16\3\16"+
		"\2\2\17\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17"+
		"\3\2\6\3\2\62;\4\2C\\c|\5\2\62;C\\c|\4\2\13\13\"\"\2F\2\3\3\2\2\2\2\5"+
		"\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2"+
		"\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33"+
		"\3\2\2\2\3\35\3\2\2\2\5\37\3\2\2\2\7!\3\2\2\2\t#\3\2\2\2\13%\3\2\2\2\r"+
		"\'\3\2\2\2\17)\3\2\2\2\21+\3\2\2\2\23-\3\2\2\2\25/\3\2\2\2\27\62\3\2\2"+
		"\2\31\66\3\2\2\2\33>\3\2\2\2\35\36\7-\2\2\36\4\3\2\2\2\37 \7/\2\2 \6\3"+
		"\2\2\2!\"\7,\2\2\"\b\3\2\2\2#$\7\61\2\2$\n\3\2\2\2%&\7`\2\2&\f\3\2\2\2"+
		"\'(\7#\2\2(\16\3\2\2\2)*\7\'\2\2*\20\3\2\2\2+,\7*\2\2,\22\3\2\2\2-.\7"+
		"+\2\2.\24\3\2\2\2/\60\7.\2\2\60\26\3\2\2\2\61\63\t\2\2\2\62\61\3\2\2\2"+
		"\63\64\3\2\2\2\64\62\3\2\2\2\64\65\3\2\2\2\65\30\3\2\2\2\66:\t\3\2\2\67"+
		"9\t\4\2\28\67\3\2\2\29<\3\2\2\2:8\3\2\2\2:;\3\2\2\2;\32\3\2\2\2<:\3\2"+
		"\2\2=?\t\5\2\2>=\3\2\2\2?@\3\2\2\2@>\3\2\2\2@A\3\2\2\2AB\3\2\2\2BC\b\16"+
		"\2\2C\34\3\2\2\2\6\2\64:@\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}