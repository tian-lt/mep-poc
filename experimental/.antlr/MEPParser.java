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
		Dot=1, Plus=2, Minus=3, Mul=4, Div=5, Caret=6, Percent=7, E=8, Comma=9, 
		LeftParen=10, RightParen=11, Integer=12, Float=13, Identifier=14, Whitespace=15, 
		Newline=16;
	public static final int
		RULE_translation_unit = 0, RULE_expr = 1, RULE_paren_expr = 2, RULE_unary_expr = 3, 
		RULE_lexpr = 4, RULE_rexpr = 5, RULE_binary_expr = 6, RULE_function = 7, 
		RULE_number = 8, RULE_sci_number = 9, RULE_sign = 10, RULE_sci_num_base = 11, 
		RULE_sci_num_exp = 12, RULE_binary_opt = 13;
	private static String[] makeRuleNames() {
		return new String[] {
			"translation_unit", "expr", "paren_expr", "unary_expr", "lexpr", "rexpr", 
			"binary_expr", "function", "number", "sci_number", "sign", "sci_num_base", 
			"sci_num_exp", "binary_opt"
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
			setState(28);
			expr();
			setState(29);
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
		public NumberContext number() {
			return getRuleContext(NumberContext.class,0);
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
			setState(37);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(31);
				paren_expr();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(32);
				function();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(33);
				binary_expr();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(34);
				unary_expr();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(35);
				match(Identifier);
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(36);
				number();
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
			setState(39);
			match(LeftParen);
			setState(40);
			expr();
			setState(41);
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
			setState(50);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Plus:
				enterOuterAlt(_localctx, 1);
				{
				setState(43);
				match(Plus);
				setState(44);
				expr();
				}
				break;
			case Minus:
				enterOuterAlt(_localctx, 2);
				{
				setState(45);
				match(Minus);
				setState(46);
				expr();
				}
				break;
			case LeftParen:
			case Integer:
			case Float:
			case Identifier:
				enterOuterAlt(_localctx, 3);
				{
				setState(47);
				lexpr();
				setState(48);
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
		public NumberContext number() {
			return getRuleContext(NumberContext.class,0);
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
			setState(55);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LeftParen:
				enterOuterAlt(_localctx, 1);
				{
				setState(52);
				paren_expr();
				}
				break;
			case Identifier:
				enterOuterAlt(_localctx, 2);
				{
				setState(53);
				function();
				}
				break;
			case Integer:
			case Float:
				enterOuterAlt(_localctx, 3);
				{
				setState(54);
				number();
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
			setState(57);
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
			setState(59);
			lexpr();
			setState(60);
			binary_opt();
			setState(61);
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
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode RightParen() { return getToken(MEPParser.RightParen, 0); }
		public List<TerminalNode> Comma() { return getTokens(MEPParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(MEPParser.Comma, i);
		}
		public FunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function; }
	}

	public final FunctionContext function() throws RecognitionException {
		FunctionContext _localctx = new FunctionContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_function);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(63);
			match(Identifier);
			setState(64);
			match(LeftParen);
			setState(65);
			expr();
			setState(70);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(66);
				match(Comma);
				setState(67);
				expr();
				}
				}
				setState(72);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(73);
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

	public static class NumberContext extends ParserRuleContext {
		public Sci_numberContext sci_number() {
			return getRuleContext(Sci_numberContext.class,0);
		}
		public TerminalNode Float() { return getToken(MEPParser.Float, 0); }
		public TerminalNode Integer() { return getToken(MEPParser.Integer, 0); }
		public NumberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_number; }
	}

	public final NumberContext number() throws RecognitionException {
		NumberContext _localctx = new NumberContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_number);
		try {
			setState(78);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(75);
				sci_number();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(76);
				match(Float);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(77);
				match(Integer);
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

	public static class Sci_numberContext extends ParserRuleContext {
		public Sci_num_baseContext sci_num_base() {
			return getRuleContext(Sci_num_baseContext.class,0);
		}
		public TerminalNode E() { return getToken(MEPParser.E, 0); }
		public SignContext sign() {
			return getRuleContext(SignContext.class,0);
		}
		public Sci_num_expContext sci_num_exp() {
			return getRuleContext(Sci_num_expContext.class,0);
		}
		public Sci_numberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sci_number; }
	}

	public final Sci_numberContext sci_number() throws RecognitionException {
		Sci_numberContext _localctx = new Sci_numberContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_sci_number);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(80);
			sci_num_base();
			setState(81);
			match(E);
			setState(82);
			sign();
			setState(83);
			sci_num_exp();
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

	public static class SignContext extends ParserRuleContext {
		public TerminalNode Plus() { return getToken(MEPParser.Plus, 0); }
		public TerminalNode Minus() { return getToken(MEPParser.Minus, 0); }
		public SignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sign; }
	}

	public final SignContext sign() throws RecognitionException {
		SignContext _localctx = new SignContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_sign);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(85);
			_la = _input.LA(1);
			if ( !(_la==Plus || _la==Minus) ) {
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

	public static class Sci_num_baseContext extends ParserRuleContext {
		public TerminalNode Float() { return getToken(MEPParser.Float, 0); }
		public TerminalNode Integer() { return getToken(MEPParser.Integer, 0); }
		public Sci_num_baseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sci_num_base; }
	}

	public final Sci_num_baseContext sci_num_base() throws RecognitionException {
		Sci_num_baseContext _localctx = new Sci_num_baseContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_sci_num_base);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(87);
			_la = _input.LA(1);
			if ( !(_la==Integer || _la==Float) ) {
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

	public static class Sci_num_expContext extends ParserRuleContext {
		public TerminalNode Integer() { return getToken(MEPParser.Integer, 0); }
		public Sci_num_expContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sci_num_exp; }
	}

	public final Sci_num_expContext sci_num_exp() throws RecognitionException {
		Sci_num_expContext _localctx = new Sci_num_expContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_sci_num_exp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(89);
			match(Integer);
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
		public TerminalNode Caret() { return getToken(MEPParser.Caret, 0); }
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
		enterRule(_localctx, 26, RULE_binary_opt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(91);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Plus) | (1L << Minus) | (1L << Mul) | (1L << Div) | (1L << Caret))) != 0)) ) {
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\22`\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\4"+
		"\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\5\3(\n\3\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\5\5\65\n\5\3\6\3"+
		"\6\3\6\5\6:\n\6\3\7\3\7\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\7\tG\n\t\f"+
		"\t\16\tJ\13\t\3\t\3\t\3\n\3\n\3\n\5\nQ\n\n\3\13\3\13\3\13\3\13\3\13\3"+
		"\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3\17\2\2\20\2\4\6\b\n\f\16\20\22\24"+
		"\26\30\32\34\2\5\3\2\4\5\3\2\16\17\3\2\4\b\2]\2\36\3\2\2\2\4\'\3\2\2\2"+
		"\6)\3\2\2\2\b\64\3\2\2\2\n9\3\2\2\2\f;\3\2\2\2\16=\3\2\2\2\20A\3\2\2\2"+
		"\22P\3\2\2\2\24R\3\2\2\2\26W\3\2\2\2\30Y\3\2\2\2\32[\3\2\2\2\34]\3\2\2"+
		"\2\36\37\5\4\3\2\37 \7\2\2\3 \3\3\2\2\2!(\5\6\4\2\"(\5\20\t\2#(\5\16\b"+
		"\2$(\5\b\5\2%(\7\20\2\2&(\5\22\n\2\'!\3\2\2\2\'\"\3\2\2\2\'#\3\2\2\2\'"+
		"$\3\2\2\2\'%\3\2\2\2\'&\3\2\2\2(\5\3\2\2\2)*\7\f\2\2*+\5\4\3\2+,\7\r\2"+
		"\2,\7\3\2\2\2-.\7\4\2\2.\65\5\4\3\2/\60\7\5\2\2\60\65\5\4\3\2\61\62\5"+
		"\n\6\2\62\63\7\t\2\2\63\65\3\2\2\2\64-\3\2\2\2\64/\3\2\2\2\64\61\3\2\2"+
		"\2\65\t\3\2\2\2\66:\5\6\4\2\67:\5\20\t\28:\5\22\n\29\66\3\2\2\29\67\3"+
		"\2\2\298\3\2\2\2:\13\3\2\2\2;<\5\4\3\2<\r\3\2\2\2=>\5\n\6\2>?\5\34\17"+
		"\2?@\5\f\7\2@\17\3\2\2\2AB\7\20\2\2BC\7\f\2\2CH\5\4\3\2DE\7\13\2\2EG\5"+
		"\4\3\2FD\3\2\2\2GJ\3\2\2\2HF\3\2\2\2HI\3\2\2\2IK\3\2\2\2JH\3\2\2\2KL\7"+
		"\r\2\2L\21\3\2\2\2MQ\5\24\13\2NQ\7\17\2\2OQ\7\16\2\2PM\3\2\2\2PN\3\2\2"+
		"\2PO\3\2\2\2Q\23\3\2\2\2RS\5\30\r\2ST\7\n\2\2TU\5\26\f\2UV\5\32\16\2V"+
		"\25\3\2\2\2WX\t\2\2\2X\27\3\2\2\2YZ\t\3\2\2Z\31\3\2\2\2[\\\7\16\2\2\\"+
		"\33\3\2\2\2]^\t\4\2\2^\35\3\2\2\2\7\'\649HP";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}