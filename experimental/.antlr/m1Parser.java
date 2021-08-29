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
		RULE_division = 7, RULE_continued_multiplication_or_division = 8, RULE_factor = 9, 
		RULE_postfix_unary_expression = 10, RULE_exponentiation = 11, RULE_atom = 12, 
		RULE_parenthesized = 13, RULE_prefix_unary_expression = 14, RULE_function = 15, 
		RULE_parameter_list = 16, RULE_continued_parameter_list = 17;
	private static String[] makeRuleNames() {
		return new String[] {
			"translation_unit", "expression", "addition", "subtraction", "continued_addition_or_subtraction", 
			"term", "multiplication", "division", "continued_multiplication_or_division", 
			"factor", "postfix_unary_expression", "exponentiation", "atom", "parenthesized", 
			"prefix_unary_expression", "function", "parameter_list", "continued_parameter_list"
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
			setState(36);
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
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
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
			setState(42);
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
				setState(39);
				addition();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(40);
				subtraction();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(41);
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
			setState(44);
			term();
			setState(45);
			match(Plus);
			setState(46);
			term();
			setState(47);
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
			setState(49);
			term();
			setState(50);
			match(Minus);
			setState(51);
			term();
			setState(52);
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
			setState(63);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Plus:
				enterOuterAlt(_localctx, 1);
				{
				setState(54);
				match(Plus);
				setState(55);
				term();
				setState(56);
				continued_addition_or_subtraction();
				}
				break;
			case Minus:
				enterOuterAlt(_localctx, 2);
				{
				setState(58);
				match(Minus);
				setState(59);
				term();
				setState(60);
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
			setState(68);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(65);
				multiplication();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(66);
				division();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(67);
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
		public MultiplicationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multiplication; }
	}

	public final MultiplicationContext multiplication() throws RecognitionException {
		MultiplicationContext _localctx = new MultiplicationContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_multiplication);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(70);
			factor();
			setState(71);
			match(Mul);
			setState(72);
			factor();
			setState(73);
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
		enterRule(_localctx, 14, RULE_division);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(75);
			factor();
			setState(76);
			match(Div);
			setState(77);
			factor();
			setState(78);
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
		public Continued_multiplication_or_divisionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_continued_multiplication_or_division; }
	}

	public final Continued_multiplication_or_divisionContext continued_multiplication_or_division() throws RecognitionException {
		Continued_multiplication_or_divisionContext _localctx = new Continued_multiplication_or_divisionContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_continued_multiplication_or_division);
		try {
			setState(89);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Mul:
				enterOuterAlt(_localctx, 1);
				{
				setState(80);
				match(Mul);
				setState(81);
				factor();
				setState(82);
				continued_multiplication_or_division();
				}
				break;
			case Div:
				enterOuterAlt(_localctx, 2);
				{
				setState(84);
				match(Div);
				setState(85);
				factor();
				setState(86);
				continued_multiplication_or_division();
				}
				break;
			case EOF:
			case Plus:
			case Minus:
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
		enterRule(_localctx, 18, RULE_factor);
		try {
			setState(94);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(91);
				postfix_unary_expression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(92);
				exponentiation();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(93);
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
		enterRule(_localctx, 20, RULE_postfix_unary_expression);
		int _la;
		try {
			setState(102);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(96);
				exponentiation();
				setState(97);
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
				setState(99);
				atom();
				setState(100);
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
		public ExponentiationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exponentiation; }
	}

	public final ExponentiationContext exponentiation() throws RecognitionException {
		ExponentiationContext _localctx = new ExponentiationContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_exponentiation);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(104);
			atom();
			setState(105);
			match(Caret);
			setState(106);
			atom();
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
		enterRule(_localctx, 24, RULE_atom);
		try {
			setState(112);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LeftP:
				enterOuterAlt(_localctx, 1);
				{
				setState(108);
				parenthesized();
				}
				break;
			case Plus:
			case Minus:
				enterOuterAlt(_localctx, 2);
				{
				setState(109);
				prefix_unary_expression();
				}
				break;
			case Identifier:
				enterOuterAlt(_localctx, 3);
				{
				setState(110);
				function();
				}
				break;
			case Number:
				enterOuterAlt(_localctx, 4);
				{
				setState(111);
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
		enterRule(_localctx, 26, RULE_parenthesized);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(114);
			match(LeftP);
			setState(115);
			expression();
			setState(116);
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
		enterRule(_localctx, 28, RULE_prefix_unary_expression);
		try {
			setState(122);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Plus:
				enterOuterAlt(_localctx, 1);
				{
				setState(118);
				match(Plus);
				setState(119);
				atom();
				}
				break;
			case Minus:
				enterOuterAlt(_localctx, 2);
				{
				setState(120);
				match(Minus);
				setState(121);
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
		enterRule(_localctx, 30, RULE_function);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(124);
			match(Identifier);
			setState(125);
			match(LeftP);
			setState(126);
			parameter_list();
			setState(127);
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
		enterRule(_localctx, 32, RULE_parameter_list);
		try {
			setState(133);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(129);
				expression();
				setState(130);
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
		enterRule(_localctx, 34, RULE_continued_parameter_list);
		try {
			setState(140);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Comma:
				enterOuterAlt(_localctx, 1);
				{
				setState(135);
				match(Comma);
				setState(136);
				expression();
				setState(137);
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\17\u0091\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\3\2\3\2\3\3\3\3\3\3\3\3\5\3-\n\3\3\4\3\4\3\4\3\4\3\4\3\5\3"+
		"\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6B\n\6\3\7\3\7\3"+
		"\7\5\7G\n\7\3\b\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3"+
		"\n\3\n\3\n\3\n\3\n\5\n\\\n\n\3\13\3\13\3\13\5\13a\n\13\3\f\3\f\3\f\3\f"+
		"\3\f\3\f\5\fi\n\f\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16\5\16s\n\16\3\17"+
		"\3\17\3\17\3\17\3\20\3\20\3\20\3\20\5\20}\n\20\3\21\3\21\3\21\3\21\3\21"+
		"\3\22\3\22\3\22\3\22\5\22\u0088\n\22\3\23\3\23\3\23\3\23\3\23\5\23\u008f"+
		"\n\23\3\23\2\2\24\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"$\2\3\3\2\b"+
		"\t\2\u0090\2&\3\2\2\2\4,\3\2\2\2\6.\3\2\2\2\b\63\3\2\2\2\nA\3\2\2\2\f"+
		"F\3\2\2\2\16H\3\2\2\2\20M\3\2\2\2\22[\3\2\2\2\24`\3\2\2\2\26h\3\2\2\2"+
		"\30j\3\2\2\2\32r\3\2\2\2\34t\3\2\2\2\36|\3\2\2\2 ~\3\2\2\2\"\u0087\3\2"+
		"\2\2$\u008e\3\2\2\2&\'\5\4\3\2\'\3\3\2\2\2(-\3\2\2\2)-\5\6\4\2*-\5\b\5"+
		"\2+-\5\24\13\2,(\3\2\2\2,)\3\2\2\2,*\3\2\2\2,+\3\2\2\2-\5\3\2\2\2./\5"+
		"\f\7\2/\60\7\3\2\2\60\61\5\f\7\2\61\62\5\n\6\2\62\7\3\2\2\2\63\64\5\f"+
		"\7\2\64\65\7\4\2\2\65\66\5\f\7\2\66\67\5\n\6\2\67\t\3\2\2\289\7\3\2\2"+
		"9:\5\f\7\2:;\5\n\6\2;B\3\2\2\2<=\7\4\2\2=>\5\f\7\2>?\5\n\6\2?B\3\2\2\2"+
		"@B\3\2\2\2A8\3\2\2\2A<\3\2\2\2A@\3\2\2\2B\13\3\2\2\2CG\5\16\b\2DG\5\20"+
		"\t\2EG\5\24\13\2FC\3\2\2\2FD\3\2\2\2FE\3\2\2\2G\r\3\2\2\2HI\5\24\13\2"+
		"IJ\7\5\2\2JK\5\24\13\2KL\5\22\n\2L\17\3\2\2\2MN\5\24\13\2NO\7\6\2\2OP"+
		"\5\24\13\2PQ\5\22\n\2Q\21\3\2\2\2RS\7\5\2\2ST\5\24\13\2TU\5\22\n\2U\\"+
		"\3\2\2\2VW\7\6\2\2WX\5\24\13\2XY\5\22\n\2Y\\\3\2\2\2Z\\\3\2\2\2[R\3\2"+
		"\2\2[V\3\2\2\2[Z\3\2\2\2\\\23\3\2\2\2]a\5\26\f\2^a\5\30\r\2_a\5\32\16"+
		"\2`]\3\2\2\2`^\3\2\2\2`_\3\2\2\2a\25\3\2\2\2bc\5\30\r\2cd\t\2\2\2di\3"+
		"\2\2\2ef\5\32\16\2fg\t\2\2\2gi\3\2\2\2hb\3\2\2\2he\3\2\2\2i\27\3\2\2\2"+
		"jk\5\32\16\2kl\7\7\2\2lm\5\32\16\2m\31\3\2\2\2ns\5\34\17\2os\5\36\20\2"+
		"ps\5 \21\2qs\7\r\2\2rn\3\2\2\2ro\3\2\2\2rp\3\2\2\2rq\3\2\2\2s\33\3\2\2"+
		"\2tu\7\n\2\2uv\5\4\3\2vw\7\13\2\2w\35\3\2\2\2xy\7\3\2\2y}\5\32\16\2z{"+
		"\7\4\2\2{}\5\32\16\2|x\3\2\2\2|z\3\2\2\2}\37\3\2\2\2~\177\7\16\2\2\177"+
		"\u0080\7\n\2\2\u0080\u0081\5\"\22\2\u0081\u0082\7\13\2\2\u0082!\3\2\2"+
		"\2\u0083\u0084\5\4\3\2\u0084\u0085\5$\23\2\u0085\u0088\3\2\2\2\u0086\u0088"+
		"\3\2\2\2\u0087\u0083\3\2\2\2\u0087\u0086\3\2\2\2\u0088#\3\2\2\2\u0089"+
		"\u008a\7\f\2\2\u008a\u008b\5\4\3\2\u008b\u008c\5$\23\2\u008c\u008f\3\2"+
		"\2\2\u008d\u008f\3\2\2\2\u008e\u0089\3\2\2\2\u008e\u008d\3\2\2\2\u008f"+
		"%\3\2\2\2\f,AF[`hr|\u0087\u008e";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}