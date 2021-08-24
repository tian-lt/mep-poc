// Generated from g:\work-repos\github\mep-poc\experimental\MEPParser.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MEPParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Dot=1, Plus=2, Minus=3, Mul=4, Div=5, Caret=6, Percent=7, E=8, LeftParen=9, 
		RightParen=10, Integer=11, Float=12, SciNumber=13, Identifier=14, HexNumber=15, 
		Whitespace=16, Newline=17;
	public static final int
		RULE_translation_unit = 0, RULE_expr = 1, RULE_paren_expr = 2, RULE_unary_expr = 3, 
		RULE_lexpr = 4, RULE_rexpr = 5, RULE_binary_expr = 6, RULE_function = 7, 
		RULE_number_expr = 8, RULE_binary_opt = 9;
	private static String[] makeRuleNames() {
		return new String[] {
			"translation_unit", "expr", "paren_expr", "unary_expr", "lexpr", "rexpr", 
			"binary_expr", "function", "number_expr", "binary_opt"
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

	@Override
	public String getGrammarFileName() { return "MEPParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MEPParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Translation_unitContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode EOF() { return getToken(MEPParser.EOF, 0); }
		public Translation_unitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_translation_unit; }
	}

	public final Translation_unitContext translation_unit() throws RecognitionException {
		Translation_unitContext _localctx = new Translation_unitContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_translation_unit);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(20);
			expr();
			setState(21);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public Paren_exprContext paren_expr() {
			return getRuleContext(Paren_exprContext.class,0);
		}
		public FunctionContext function() {
			return getRuleContext(FunctionContext.class,0);
		}
		public Binary_exprContext binary_expr() {
			return getRuleContext(Binary_exprContext.class,0);
		}
		public Unary_exprContext unary_expr() {
			return getRuleContext(Unary_exprContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(MEPParser.Identifier, 0); }
		public Number_exprContext number_expr() {
			return getRuleContext(Number_exprContext.class,0);
		}
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	}

	public final ExprContext expr() throws RecognitionException {
		ExprContext _localctx = new ExprContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_expr);
		try {
			setState(29);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(23);
				paren_expr();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(24);
				function();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(25);
				binary_expr();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(26);
				unary_expr();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(27);
				match(Identifier);
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(28);
				number_expr();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Paren_exprContext extends ParserRuleContext {
		public TerminalNode LeftParen() { return getToken(MEPParser.LeftParen, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RightParen() { return getToken(MEPParser.RightParen, 0); }
		public Paren_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_paren_expr; }
	}

	public final Paren_exprContext paren_expr() throws RecognitionException {
		Paren_exprContext _localctx = new Paren_exprContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_paren_expr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(31);
			match(LeftParen);
			setState(32);
			expr();
			setState(33);
			match(RightParen);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Unary_exprContext extends ParserRuleContext {
		public TerminalNode Plus() { return getToken(MEPParser.Plus, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode Minus() { return getToken(MEPParser.Minus, 0); }
		public LexprContext lexpr() {
			return getRuleContext(LexprContext.class,0);
		}
		public TerminalNode Percent() { return getToken(MEPParser.Percent, 0); }
		public Unary_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_expr; }
	}

	public final Unary_exprContext unary_expr() throws RecognitionException {
		Unary_exprContext _localctx = new Unary_exprContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_unary_expr);
		try {
			setState(42);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Plus:
				enterOuterAlt(_localctx, 1);
				{
				setState(35);
				match(Plus);
				setState(36);
				expr();
				}
				break;
			case Minus:
				enterOuterAlt(_localctx, 2);
				{
				setState(37);
				match(Minus);
				setState(38);
				expr();
				}
				break;
			case LeftParen:
			case Integer:
			case Float:
			case SciNumber:
			case Identifier:
				enterOuterAlt(_localctx, 3);
				{
				setState(39);
				lexpr();
				setState(40);
				match(Percent);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LexprContext extends ParserRuleContext {
		public Paren_exprContext paren_expr() {
			return getRuleContext(Paren_exprContext.class,0);
		}
		public FunctionContext function() {
			return getRuleContext(FunctionContext.class,0);
		}
		public Number_exprContext number_expr() {
			return getRuleContext(Number_exprContext.class,0);
		}
		public LexprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lexpr; }
	}

	public final LexprContext lexpr() throws RecognitionException {
		LexprContext _localctx = new LexprContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_lexpr);
		try {
			setState(47);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LeftParen:
				enterOuterAlt(_localctx, 1);
				{
				setState(44);
				paren_expr();
				}
				break;
			case Identifier:
				enterOuterAlt(_localctx, 2);
				{
				setState(45);
				function();
				}
				break;
			case Integer:
			case Float:
			case SciNumber:
				enterOuterAlt(_localctx, 3);
				{
				setState(46);
				number_expr();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RexprContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public RexprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rexpr; }
	}

	public final RexprContext rexpr() throws RecognitionException {
		RexprContext _localctx = new RexprContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_rexpr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(49);
			expr();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Binary_exprContext extends ParserRuleContext {
		public LexprContext lexpr() {
			return getRuleContext(LexprContext.class,0);
		}
		public Binary_optContext binary_opt() {
			return getRuleContext(Binary_optContext.class,0);
		}
		public RexprContext rexpr() {
			return getRuleContext(RexprContext.class,0);
		}
		public Binary_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_binary_expr; }
	}

	public final Binary_exprContext binary_expr() throws RecognitionException {
		Binary_exprContext _localctx = new Binary_exprContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_binary_expr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(51);
			lexpr();
			setState(52);
			binary_opt();
			setState(53);
			rexpr();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(MEPParser.Identifier, 0); }
		public TerminalNode LeftParen() { return getToken(MEPParser.LeftParen, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RightParen() { return getToken(MEPParser.RightParen, 0); }
		public FunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function; }
	}

	public final FunctionContext function() throws RecognitionException {
		FunctionContext _localctx = new FunctionContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_function);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(55);
			match(Identifier);
			setState(56);
			match(LeftParen);
			setState(57);
			expr();
			setState(58);
			match(RightParen);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Number_exprContext extends ParserRuleContext {
		public TerminalNode SciNumber() { return getToken(MEPParser.SciNumber, 0); }
		public TerminalNode Float() { return getToken(MEPParser.Float, 0); }
		public TerminalNode Integer() { return getToken(MEPParser.Integer, 0); }
		public Number_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_number_expr; }
	}

	public final Number_exprContext number_expr() throws RecognitionException {
		Number_exprContext _localctx = new Number_exprContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_number_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(60);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Integer) | (1L << Float) | (1L << SciNumber))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Binary_optContext extends ParserRuleContext {
		public TerminalNode Mul() { return getToken(MEPParser.Mul, 0); }
		public TerminalNode Div() { return getToken(MEPParser.Div, 0); }
		public TerminalNode Plus() { return getToken(MEPParser.Plus, 0); }
		public TerminalNode Minus() { return getToken(MEPParser.Minus, 0); }
		public Binary_optContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_binary_opt; }
	}

	public final Binary_optContext binary_opt() throws RecognitionException {
		Binary_optContext _localctx = new Binary_optContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_binary_opt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(62);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Plus) | (1L << Minus) | (1L << Mul) | (1L << Div))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\23C\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\3"+
		"\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\5\3 \n\3\3\4\3\4\3\4\3\4\3\5\3\5\3"+
		"\5\3\5\3\5\3\5\3\5\5\5-\n\5\3\6\3\6\3\6\5\6\62\n\6\3\7\3\7\3\b\3\b\3\b"+
		"\3\b\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3\13\3\13\3\13\2\2\f\2\4\6\b\n\f\16\20"+
		"\22\24\2\4\3\2\r\17\3\2\4\7\2A\2\26\3\2\2\2\4\37\3\2\2\2\6!\3\2\2\2\b"+
		",\3\2\2\2\n\61\3\2\2\2\f\63\3\2\2\2\16\65\3\2\2\2\209\3\2\2\2\22>\3\2"+
		"\2\2\24@\3\2\2\2\26\27\5\4\3\2\27\30\7\2\2\3\30\3\3\2\2\2\31 \5\6\4\2"+
		"\32 \5\20\t\2\33 \5\16\b\2\34 \5\b\5\2\35 \7\20\2\2\36 \5\22\n\2\37\31"+
		"\3\2\2\2\37\32\3\2\2\2\37\33\3\2\2\2\37\34\3\2\2\2\37\35\3\2\2\2\37\36"+
		"\3\2\2\2 \5\3\2\2\2!\"\7\13\2\2\"#\5\4\3\2#$\7\f\2\2$\7\3\2\2\2%&\7\4"+
		"\2\2&-\5\4\3\2\'(\7\5\2\2(-\5\4\3\2)*\5\n\6\2*+\7\t\2\2+-\3\2\2\2,%\3"+
		"\2\2\2,\'\3\2\2\2,)\3\2\2\2-\t\3\2\2\2.\62\5\6\4\2/\62\5\20\t\2\60\62"+
		"\5\22\n\2\61.\3\2\2\2\61/\3\2\2\2\61\60\3\2\2\2\62\13\3\2\2\2\63\64\5"+
		"\4\3\2\64\r\3\2\2\2\65\66\5\n\6\2\66\67\5\24\13\2\678\5\f\7\28\17\3\2"+
		"\2\29:\7\20\2\2:;\7\13\2\2;<\5\4\3\2<=\7\f\2\2=\21\3\2\2\2>?\t\2\2\2?"+
		"\23\3\2\2\2@A\t\3\2\2A\25\3\2\2\2\5\37,\61";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}