// Generated from g:\work-repos\github\mep-poc\experimental\m1.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class m1Parser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Plus=1, Minus=2, Mul=3, Div=4, Caret=5, Fact=6, Percent=7, LeftP=8, RightP=9, 
		Comma=10, Number=11, Identifier=12, Whitespace=13;
	public static final int
		RULE_translation_unit = 0, RULE_expression = 1, RULE_addition = 2, RULE_subtraction = 3, 
		RULE_continued_addition_or_subtraction = 4, RULE_term = 5, RULE_multiplication = 6, 
		RULE_multiplication_sign_omitted = 7, RULE_division = 8, RULE_continued_multiplication_or_division = 9, 
		RULE_continued_multiplication_sign_omitted = 10, RULE_factor = 11, RULE_postfix_unary_expression = 12, 
		RULE_exponentiation = 13, RULE_continued_exp = 14, RULE_atom = 15, RULE_parenthesized = 16, 
		RULE_prefix_unary_expression = 17, RULE_function = 18, RULE_parameter_list = 19, 
		RULE_continued_parameter_list = 20;
	private static String[] makeRuleNames() {
		return new String[] {
			"translation_unit", "expression", "addition", "subtraction", "continued_addition_or_subtraction", 
			"term", "multiplication", "multiplication_sign_omitted", "division", 
			"continued_multiplication_or_division", "continued_multiplication_sign_omitted", 
			"factor", "postfix_unary_expression", "exponentiation", "continued_exp", 
			"atom", "parenthesized", "prefix_unary_expression", "function", "parameter_list", 
			"continued_parameter_list"
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

	@Override
	public String getGrammarFileName() { return "m1.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public m1Parser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Translation_unitContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
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
			setState(42);
			expression();
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

	public static class ExpressionContext extends ParserRuleContext {
		public AdditionContext addition() {
			return getRuleContext(AdditionContext.class,0);
		}
		public SubtractionContext subtraction() {
			return getRuleContext(SubtractionContext.class,0);
		}
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_expression);
		try {
			setState(48);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(45);
				addition();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(46);
				subtraction();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(47);
				term();
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

	public static class AdditionContext extends ParserRuleContext {
		public List<TermContext> term() {
			return getRuleContexts(TermContext.class);
		}
		public TermContext term(int i) {
			return getRuleContext(TermContext.class,i);
		}
		public TerminalNode Plus() { return getToken(m1Parser.Plus, 0); }
		public Continued_addition_or_subtractionContext continued_addition_or_subtraction() {
			return getRuleContext(Continued_addition_or_subtractionContext.class,0);
		}
		public AdditionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_addition; }
	}

	public final AdditionContext addition() throws RecognitionException {
		AdditionContext _localctx = new AdditionContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_addition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(50);
			term();
			setState(51);
			match(Plus);
			setState(52);
			term();
			setState(53);
			continued_addition_or_subtraction();
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

	public static class SubtractionContext extends ParserRuleContext {
		public List<TermContext> term() {
			return getRuleContexts(TermContext.class);
		}
		public TermContext term(int i) {
			return getRuleContext(TermContext.class,i);
		}
		public TerminalNode Minus() { return getToken(m1Parser.Minus, 0); }
		public Continued_addition_or_subtractionContext continued_addition_or_subtraction() {
			return getRuleContext(Continued_addition_or_subtractionContext.class,0);
		}
		public SubtractionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_subtraction; }
	}

	public final SubtractionContext subtraction() throws RecognitionException {
		SubtractionContext _localctx = new SubtractionContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_subtraction);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(55);
			term();
			setState(56);
			match(Minus);
			setState(57);
			term();
			setState(58);
			continued_addition_or_subtraction();
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

	public static class Continued_addition_or_subtractionContext extends ParserRuleContext {
		public TerminalNode Plus() { return getToken(m1Parser.Plus, 0); }
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public Continued_addition_or_subtractionContext continued_addition_or_subtraction() {
			return getRuleContext(Continued_addition_or_subtractionContext.class,0);
		}
		public TerminalNode Minus() { return getToken(m1Parser.Minus, 0); }
		public Continued_addition_or_subtractionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_continued_addition_or_subtraction; }
	}

	public final Continued_addition_or_subtractionContext continued_addition_or_subtraction() throws RecognitionException {
		Continued_addition_or_subtractionContext _localctx = new Continued_addition_or_subtractionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_continued_addition_or_subtraction);
		try {
			setState(69);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Plus:
				enterOuterAlt(_localctx, 1);
				{
				setState(60);
				match(Plus);
				setState(61);
				term();
				setState(62);
				continued_addition_or_subtraction();
				}
				break;
			case Minus:
				enterOuterAlt(_localctx, 2);
				{
				setState(64);
				match(Minus);
				setState(65);
				term();
				setState(66);
				continued_addition_or_subtraction();
				}
				break;
			case EOF:
			case RightP:
			case Comma:
				enterOuterAlt(_localctx, 3);
				{
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

	public static class TermContext extends ParserRuleContext {
		public MultiplicationContext multiplication() {
			return getRuleContext(MultiplicationContext.class,0);
		}
		public DivisionContext division() {
			return getRuleContext(DivisionContext.class,0);
		}
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	}

	public final TermContext term() throws RecognitionException {
		TermContext _localctx = new TermContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_term);
		try {
			setState(74);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(71);
				multiplication();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(72);
				division();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(73);
				factor();
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

	public static class MultiplicationContext extends ParserRuleContext {
		public List<FactorContext> factor() {
			return getRuleContexts(FactorContext.class);
		}
		public FactorContext factor(int i) {
			return getRuleContext(FactorContext.class,i);
		}
		public TerminalNode Mul() { return getToken(m1Parser.Mul, 0); }
		public Continued_multiplication_or_divisionContext continued_multiplication_or_division() {
			return getRuleContext(Continued_multiplication_or_divisionContext.class,0);
		}
		public Multiplication_sign_omittedContext multiplication_sign_omitted() {
			return getRuleContext(Multiplication_sign_omittedContext.class,0);
		}
		public MultiplicationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multiplication; }
	}

	public final MultiplicationContext multiplication() throws RecognitionException {
		MultiplicationContext _localctx = new MultiplicationContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_multiplication);
		try {
			setState(82);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(76);
				factor();
				setState(77);
				match(Mul);
				setState(78);
				factor();
				setState(79);
				continued_multiplication_or_division();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(81);
				multiplication_sign_omitted();
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

	public static class Multiplication_sign_omittedContext extends ParserRuleContext {
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public List<ParenthesizedContext> parenthesized() {
			return getRuleContexts(ParenthesizedContext.class);
		}
		public ParenthesizedContext parenthesized(int i) {
			return getRuleContext(ParenthesizedContext.class,i);
		}
		public Continued_multiplication_or_divisionContext continued_multiplication_or_division() {
			return getRuleContext(Continued_multiplication_or_divisionContext.class,0);
		}
		public List<FunctionContext> function() {
			return getRuleContexts(FunctionContext.class);
		}
		public FunctionContext function(int i) {
			return getRuleContext(FunctionContext.class,i);
		}
		public Multiplication_sign_omittedContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multiplication_sign_omitted; }
	}

	public final Multiplication_sign_omittedContext multiplication_sign_omitted() throws RecognitionException {
		Multiplication_sign_omittedContext _localctx = new Multiplication_sign_omittedContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_multiplication_sign_omitted);
		try {
			setState(101);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(85);
				factor();
				setState(86);
				parenthesized();
				setState(87);
				continued_multiplication_or_division();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(89);
				parenthesized();
				setState(90);
				parenthesized();
				setState(91);
				continued_multiplication_or_division();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(93);
				factor();
				setState(94);
				function();
				setState(95);
				continued_multiplication_or_division();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(97);
				function();
				setState(98);
				function();
				setState(99);
				continued_multiplication_or_division();
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

	public static class DivisionContext extends ParserRuleContext {
		public List<FactorContext> factor() {
			return getRuleContexts(FactorContext.class);
		}
		public FactorContext factor(int i) {
			return getRuleContext(FactorContext.class,i);
		}
		public TerminalNode Div() { return getToken(m1Parser.Div, 0); }
		public Continued_multiplication_or_divisionContext continued_multiplication_or_division() {
			return getRuleContext(Continued_multiplication_or_divisionContext.class,0);
		}
		public DivisionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_division; }
	}

	public final DivisionContext division() throws RecognitionException {
		DivisionContext _localctx = new DivisionContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_division);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(103);
			factor();
			setState(104);
			match(Div);
			setState(105);
			factor();
			setState(106);
			continued_multiplication_or_division();
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

	public static class Continued_multiplication_or_divisionContext extends ParserRuleContext {
		public TerminalNode Mul() { return getToken(m1Parser.Mul, 0); }
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public Continued_multiplication_or_divisionContext continued_multiplication_or_division() {
			return getRuleContext(Continued_multiplication_or_divisionContext.class,0);
		}
		public TerminalNode Div() { return getToken(m1Parser.Div, 0); }
		public Continued_multiplication_sign_omittedContext continued_multiplication_sign_omitted() {
			return getRuleContext(Continued_multiplication_sign_omittedContext.class,0);
		}
		public Continued_multiplication_or_divisionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_continued_multiplication_or_division; }
	}

	public final Continued_multiplication_or_divisionContext continued_multiplication_or_division() throws RecognitionException {
		Continued_multiplication_or_divisionContext _localctx = new Continued_multiplication_or_divisionContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_continued_multiplication_or_division);
		try {
			setState(118);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Mul:
				enterOuterAlt(_localctx, 1);
				{
				setState(108);
				match(Mul);
				setState(109);
				factor();
				setState(110);
				continued_multiplication_or_division();
				}
				break;
			case Div:
				enterOuterAlt(_localctx, 2);
				{
				setState(112);
				match(Div);
				setState(113);
				factor();
				setState(114);
				continued_multiplication_or_division();
				}
				break;
			case LeftP:
			case Identifier:
				enterOuterAlt(_localctx, 3);
				{
				setState(116);
				continued_multiplication_sign_omitted();
				}
				break;
			case EOF:
			case Plus:
			case Minus:
			case RightP:
			case Comma:
				enterOuterAlt(_localctx, 4);
				{
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

	public static class Continued_multiplication_sign_omittedContext extends ParserRuleContext {
		public ParenthesizedContext parenthesized() {
			return getRuleContext(ParenthesizedContext.class,0);
		}
		public Continued_multiplication_or_divisionContext continued_multiplication_or_division() {
			return getRuleContext(Continued_multiplication_or_divisionContext.class,0);
		}
		public FunctionContext function() {
			return getRuleContext(FunctionContext.class,0);
		}
		public Continued_multiplication_sign_omittedContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_continued_multiplication_sign_omitted; }
	}

	public final Continued_multiplication_sign_omittedContext continued_multiplication_sign_omitted() throws RecognitionException {
		Continued_multiplication_sign_omittedContext _localctx = new Continued_multiplication_sign_omittedContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_continued_multiplication_sign_omitted);
		try {
			setState(126);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LeftP:
				enterOuterAlt(_localctx, 1);
				{
				setState(120);
				parenthesized();
				setState(121);
				continued_multiplication_or_division();
				}
				break;
			case Identifier:
				enterOuterAlt(_localctx, 2);
				{
				setState(123);
				function();
				setState(124);
				continued_multiplication_or_division();
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

	public static class FactorContext extends ParserRuleContext {
		public Postfix_unary_expressionContext postfix_unary_expression() {
			return getRuleContext(Postfix_unary_expressionContext.class,0);
		}
		public ExponentiationContext exponentiation() {
			return getRuleContext(ExponentiationContext.class,0);
		}
		public AtomContext atom() {
			return getRuleContext(AtomContext.class,0);
		}
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_factor);
		try {
			setState(131);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(128);
				postfix_unary_expression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(129);
				exponentiation();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(130);
				atom();
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

	public static class Postfix_unary_expressionContext extends ParserRuleContext {
		public ExponentiationContext exponentiation() {
			return getRuleContext(ExponentiationContext.class,0);
		}
		public TerminalNode Fact() { return getToken(m1Parser.Fact, 0); }
		public TerminalNode Percent() { return getToken(m1Parser.Percent, 0); }
		public AtomContext atom() {
			return getRuleContext(AtomContext.class,0);
		}
		public Postfix_unary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_postfix_unary_expression; }
	}

	public final Postfix_unary_expressionContext postfix_unary_expression() throws RecognitionException {
		Postfix_unary_expressionContext _localctx = new Postfix_unary_expressionContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_postfix_unary_expression);
		int _la;
		try {
			setState(139);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(133);
				exponentiation();
				setState(134);
				_la = _input.LA(1);
				if ( !(_la==Fact || _la==Percent) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(136);
				atom();
				setState(137);
				_la = _input.LA(1);
				if ( !(_la==Fact || _la==Percent) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
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

	public static class ExponentiationContext extends ParserRuleContext {
		public List<AtomContext> atom() {
			return getRuleContexts(AtomContext.class);
		}
		public AtomContext atom(int i) {
			return getRuleContext(AtomContext.class,i);
		}
		public TerminalNode Caret() { return getToken(m1Parser.Caret, 0); }
		public Continued_expContext continued_exp() {
			return getRuleContext(Continued_expContext.class,0);
		}
		public ExponentiationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exponentiation; }
	}

	public final ExponentiationContext exponentiation() throws RecognitionException {
		ExponentiationContext _localctx = new ExponentiationContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_exponentiation);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(141);
			atom();
			setState(142);
			match(Caret);
			setState(143);
			atom();
			setState(144);
			continued_exp();
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

	public static class Continued_expContext extends ParserRuleContext {
		public TerminalNode Caret() { return getToken(m1Parser.Caret, 0); }
		public AtomContext atom() {
			return getRuleContext(AtomContext.class,0);
		}
		public Continued_expContext continued_exp() {
			return getRuleContext(Continued_expContext.class,0);
		}
		public Continued_expContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_continued_exp; }
	}

	public final Continued_expContext continued_exp() throws RecognitionException {
		Continued_expContext _localctx = new Continued_expContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_continued_exp);
		try {
			setState(151);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Caret:
				enterOuterAlt(_localctx, 1);
				{
				setState(146);
				match(Caret);
				setState(147);
				atom();
				setState(148);
				continued_exp();
				}
				break;
			case EOF:
			case Plus:
			case Minus:
			case Mul:
			case Div:
			case Fact:
			case Percent:
			case LeftP:
			case RightP:
			case Comma:
			case Identifier:
				enterOuterAlt(_localctx, 2);
				{
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

	public static class AtomContext extends ParserRuleContext {
		public ParenthesizedContext parenthesized() {
			return getRuleContext(ParenthesizedContext.class,0);
		}
		public Prefix_unary_expressionContext prefix_unary_expression() {
			return getRuleContext(Prefix_unary_expressionContext.class,0);
		}
		public FunctionContext function() {
			return getRuleContext(FunctionContext.class,0);
		}
		public TerminalNode Number() { return getToken(m1Parser.Number, 0); }
		public AtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_atom; }
	}

	public final AtomContext atom() throws RecognitionException {
		AtomContext _localctx = new AtomContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_atom);
		try {
			setState(157);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LeftP:
				enterOuterAlt(_localctx, 1);
				{
				setState(153);
				parenthesized();
				}
				break;
			case Plus:
			case Minus:
				enterOuterAlt(_localctx, 2);
				{
				setState(154);
				prefix_unary_expression();
				}
				break;
			case Identifier:
				enterOuterAlt(_localctx, 3);
				{
				setState(155);
				function();
				}
				break;
			case Number:
				enterOuterAlt(_localctx, 4);
				{
				setState(156);
				match(Number);
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

	public static class ParenthesizedContext extends ParserRuleContext {
		public TerminalNode LeftP() { return getToken(m1Parser.LeftP, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RightP() { return getToken(m1Parser.RightP, 0); }
		public ParenthesizedContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parenthesized; }
	}

	public final ParenthesizedContext parenthesized() throws RecognitionException {
		ParenthesizedContext _localctx = new ParenthesizedContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_parenthesized);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(159);
			match(LeftP);
			setState(160);
			expression();
			setState(161);
			match(RightP);
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

	public static class Prefix_unary_expressionContext extends ParserRuleContext {
		public TerminalNode Plus() { return getToken(m1Parser.Plus, 0); }
		public AtomContext atom() {
			return getRuleContext(AtomContext.class,0);
		}
		public TerminalNode Minus() { return getToken(m1Parser.Minus, 0); }
		public Prefix_unary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prefix_unary_expression; }
	}

	public final Prefix_unary_expressionContext prefix_unary_expression() throws RecognitionException {
		Prefix_unary_expressionContext _localctx = new Prefix_unary_expressionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_prefix_unary_expression);
		try {
			setState(167);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Plus:
				enterOuterAlt(_localctx, 1);
				{
				setState(163);
				match(Plus);
				setState(164);
				atom();
				}
				break;
			case Minus:
				enterOuterAlt(_localctx, 2);
				{
				setState(165);
				match(Minus);
				setState(166);
				atom();
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

	public static class FunctionContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(m1Parser.Identifier, 0); }
		public TerminalNode LeftP() { return getToken(m1Parser.LeftP, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode RightP() { return getToken(m1Parser.RightP, 0); }
		public FunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function; }
	}

	public final FunctionContext function() throws RecognitionException {
		FunctionContext _localctx = new FunctionContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_function);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(169);
			match(Identifier);
			setState(170);
			match(LeftP);
			setState(171);
			parameter_list();
			setState(172);
			match(RightP);
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

	public static class Parameter_listContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Continued_parameter_listContext continued_parameter_list() {
			return getRuleContext(Continued_parameter_listContext.class,0);
		}
		public Parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_list; }
	}

	public final Parameter_listContext parameter_list() throws RecognitionException {
		Parameter_listContext _localctx = new Parameter_listContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_parameter_list);
		try {
			setState(178);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(174);
				expression();
				setState(175);
				continued_parameter_list();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
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

	public static class Continued_parameter_listContext extends ParserRuleContext {
		public TerminalNode Comma() { return getToken(m1Parser.Comma, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Continued_parameter_listContext continued_parameter_list() {
			return getRuleContext(Continued_parameter_listContext.class,0);
		}
		public Continued_parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_continued_parameter_list; }
	}

	public final Continued_parameter_listContext continued_parameter_list() throws RecognitionException {
		Continued_parameter_listContext _localctx = new Continued_parameter_listContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_continued_parameter_list);
		try {
			setState(185);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Comma:
				enterOuterAlt(_localctx, 1);
				{
				setState(180);
				match(Comma);
				setState(181);
				expression();
				setState(182);
				continued_parameter_list();
				}
				break;
			case RightP:
				enterOuterAlt(_localctx, 2);
				{
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

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\17\u00be\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\3\2\3\2\3\3\3\3\3\3\3\3\5\3\63"+
		"\n\3\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3"+
		"\6\3\6\3\6\5\6H\n\6\3\7\3\7\3\7\5\7M\n\7\3\b\3\b\3\b\3\b\3\b\3\b\5\bU"+
		"\n\b\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3"+
		"\t\5\th\n\t\3\n\3\n\3\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\3\13\5\13y\n\13\3\f\3\f\3\f\3\f\3\f\3\f\5\f\u0081\n\f\3\r\3\r\3"+
		"\r\5\r\u0086\n\r\3\16\3\16\3\16\3\16\3\16\3\16\5\16\u008e\n\16\3\17\3"+
		"\17\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3\20\5\20\u009a\n\20\3\21\3\21"+
		"\3\21\3\21\5\21\u00a0\n\21\3\22\3\22\3\22\3\22\3\23\3\23\3\23\3\23\5\23"+
		"\u00aa\n\23\3\24\3\24\3\24\3\24\3\24\3\25\3\25\3\25\3\25\5\25\u00b5\n"+
		"\25\3\26\3\26\3\26\3\26\3\26\5\26\u00bc\n\26\3\26\2\2\27\2\4\6\b\n\f\16"+
		"\20\22\24\26\30\32\34\36 \"$&(*\2\3\3\2\b\t\2\u00c2\2,\3\2\2\2\4\62\3"+
		"\2\2\2\6\64\3\2\2\2\b9\3\2\2\2\nG\3\2\2\2\fL\3\2\2\2\16T\3\2\2\2\20g\3"+
		"\2\2\2\22i\3\2\2\2\24x\3\2\2\2\26\u0080\3\2\2\2\30\u0085\3\2\2\2\32\u008d"+
		"\3\2\2\2\34\u008f\3\2\2\2\36\u0099\3\2\2\2 \u009f\3\2\2\2\"\u00a1\3\2"+
		"\2\2$\u00a9\3\2\2\2&\u00ab\3\2\2\2(\u00b4\3\2\2\2*\u00bb\3\2\2\2,-\5\4"+
		"\3\2-\3\3\2\2\2.\63\3\2\2\2/\63\5\6\4\2\60\63\5\b\5\2\61\63\5\f\7\2\62"+
		".\3\2\2\2\62/\3\2\2\2\62\60\3\2\2\2\62\61\3\2\2\2\63\5\3\2\2\2\64\65\5"+
		"\f\7\2\65\66\7\3\2\2\66\67\5\f\7\2\678\5\n\6\28\7\3\2\2\29:\5\f\7\2:;"+
		"\7\4\2\2;<\5\f\7\2<=\5\n\6\2=\t\3\2\2\2>?\7\3\2\2?@\5\f\7\2@A\5\n\6\2"+
		"AH\3\2\2\2BC\7\4\2\2CD\5\f\7\2DE\5\n\6\2EH\3\2\2\2FH\3\2\2\2G>\3\2\2\2"+
		"GB\3\2\2\2GF\3\2\2\2H\13\3\2\2\2IM\5\16\b\2JM\5\22\n\2KM\5\30\r\2LI\3"+
		"\2\2\2LJ\3\2\2\2LK\3\2\2\2M\r\3\2\2\2NO\5\30\r\2OP\7\5\2\2PQ\5\30\r\2"+
		"QR\5\24\13\2RU\3\2\2\2SU\5\20\t\2TN\3\2\2\2TS\3\2\2\2U\17\3\2\2\2Vh\3"+
		"\2\2\2WX\5\30\r\2XY\5\"\22\2YZ\5\24\13\2Zh\3\2\2\2[\\\5\"\22\2\\]\5\""+
		"\22\2]^\5\24\13\2^h\3\2\2\2_`\5\30\r\2`a\5&\24\2ab\5\24\13\2bh\3\2\2\2"+
		"cd\5&\24\2de\5&\24\2ef\5\24\13\2fh\3\2\2\2gV\3\2\2\2gW\3\2\2\2g[\3\2\2"+
		"\2g_\3\2\2\2gc\3\2\2\2h\21\3\2\2\2ij\5\30\r\2jk\7\6\2\2kl\5\30\r\2lm\5"+
		"\24\13\2m\23\3\2\2\2no\7\5\2\2op\5\30\r\2pq\5\24\13\2qy\3\2\2\2rs\7\6"+
		"\2\2st\5\30\r\2tu\5\24\13\2uy\3\2\2\2vy\5\26\f\2wy\3\2\2\2xn\3\2\2\2x"+
		"r\3\2\2\2xv\3\2\2\2xw\3\2\2\2y\25\3\2\2\2z{\5\"\22\2{|\5\24\13\2|\u0081"+
		"\3\2\2\2}~\5&\24\2~\177\5\24\13\2\177\u0081\3\2\2\2\u0080z\3\2\2\2\u0080"+
		"}\3\2\2\2\u0081\27\3\2\2\2\u0082\u0086\5\32\16\2\u0083\u0086\5\34\17\2"+
		"\u0084\u0086\5 \21\2\u0085\u0082\3\2\2\2\u0085\u0083\3\2\2\2\u0085\u0084"+
		"\3\2\2\2\u0086\31\3\2\2\2\u0087\u0088\5\34\17\2\u0088\u0089\t\2\2\2\u0089"+
		"\u008e\3\2\2\2\u008a\u008b\5 \21\2\u008b\u008c\t\2\2\2\u008c\u008e\3\2"+
		"\2\2\u008d\u0087\3\2\2\2\u008d\u008a\3\2\2\2\u008e\33\3\2\2\2\u008f\u0090"+
		"\5 \21\2\u0090\u0091\7\7\2\2\u0091\u0092\5 \21\2\u0092\u0093\5\36\20\2"+
		"\u0093\35\3\2\2\2\u0094\u0095\7\7\2\2\u0095\u0096\5 \21\2\u0096\u0097"+
		"\5\36\20\2\u0097\u009a\3\2\2\2\u0098\u009a\3\2\2\2\u0099\u0094\3\2\2\2"+
		"\u0099\u0098\3\2\2\2\u009a\37\3\2\2\2\u009b\u00a0\5\"\22\2\u009c\u00a0"+
		"\5$\23\2\u009d\u00a0\5&\24\2\u009e\u00a0\7\r\2\2\u009f\u009b\3\2\2\2\u009f"+
		"\u009c\3\2\2\2\u009f\u009d\3\2\2\2\u009f\u009e\3\2\2\2\u00a0!\3\2\2\2"+
		"\u00a1\u00a2\7\n\2\2\u00a2\u00a3\5\4\3\2\u00a3\u00a4\7\13\2\2\u00a4#\3"+
		"\2\2\2\u00a5\u00a6\7\3\2\2\u00a6\u00aa\5 \21\2\u00a7\u00a8\7\4\2\2\u00a8"+
		"\u00aa\5 \21\2\u00a9\u00a5\3\2\2\2\u00a9\u00a7\3\2\2\2\u00aa%\3\2\2\2"+
		"\u00ab\u00ac\7\16\2\2\u00ac\u00ad\7\n\2\2\u00ad\u00ae\5(\25\2\u00ae\u00af"+
		"\7\13\2\2\u00af\'\3\2\2\2\u00b0\u00b1\5\4\3\2\u00b1\u00b2\5*\26\2\u00b2"+
		"\u00b5\3\2\2\2\u00b3\u00b5\3\2\2\2\u00b4\u00b0\3\2\2\2\u00b4\u00b3\3\2"+
		"\2\2\u00b5)\3\2\2\2\u00b6\u00b7\7\f\2\2\u00b7\u00b8\5\4\3\2\u00b8\u00b9"+
		"\5*\26\2\u00b9\u00bc\3\2\2\2\u00ba\u00bc\3\2\2\2\u00bb\u00b6\3\2\2\2\u00bb"+
		"\u00ba\3\2\2\2\u00bc+\3\2\2\2\20\62GLTgx\u0080\u0085\u008d\u0099\u009f"+
		"\u00a9\u00b4\u00bb";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}