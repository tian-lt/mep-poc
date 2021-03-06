//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     ANTLR Version: 4.9.2
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from m1.g4 by ANTLR 4.9.2

// Unreachable code detected
#pragma warning disable 0162
// The variable '...' is assigned but its value is never used
#pragma warning disable 0219
// Missing XML comment for publicly visible type or member '...'
#pragma warning disable 1591
// Ambiguous reference in cref attribute
#pragma warning disable 419

using System;
using System.IO;
using System.Text;
using System.Diagnostics;
using System.Collections.Generic;
using Antlr4.Runtime;
using Antlr4.Runtime.Atn;
using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
using DFA = Antlr4.Runtime.Dfa.DFA;

[System.CodeDom.Compiler.GeneratedCode("ANTLR", "4.9.2")]
[System.CLSCompliant(false)]
public partial class m1Parser : Parser {
	protected static DFA[] decisionToDFA;
	protected static PredictionContextCache sharedContextCache = new PredictionContextCache();
	public const int
		Plus=1, Minus=2, Mul=3, Div=4, Caret=5, Fact=6, LeftP=7, RightP=8, Comma=9, 
		Number=10, Identifier=11, Whitespace=12;
	public const int
		RULE_translation_unit = 0, RULE_expression = 1, RULE_addition = 2, RULE_subtraction = 3, 
		RULE_term = 4, RULE_product = 5, RULE_quotient = 6, RULE_factor = 7, RULE_postfix_unary_expression = 8, 
		RULE_exponentiation = 9, RULE_atom = 10, RULE_parenthesized = 11, RULE_prefix_unary_expression = 12, 
		RULE_function = 13;
	public static readonly string[] ruleNames = {
		"translation_unit", "expression", "addition", "subtraction", "term", "product", 
		"quotient", "factor", "postfix_unary_expression", "exponentiation", "atom", 
		"parenthesized", "prefix_unary_expression", "function"
	};

	private static readonly string[] _LiteralNames = {
		null, "'+'", "'-'", "'*'", "'/'", "'^'", "'!'", "'('", "')'", "','"
	};
	private static readonly string[] _SymbolicNames = {
		null, "Plus", "Minus", "Mul", "Div", "Caret", "Fact", "LeftP", "RightP", 
		"Comma", "Number", "Identifier", "Whitespace"
	};
	public static readonly IVocabulary DefaultVocabulary = new Vocabulary(_LiteralNames, _SymbolicNames);

	[NotNull]
	public override IVocabulary Vocabulary
	{
		get
		{
			return DefaultVocabulary;
		}
	}

	public override string GrammarFileName { get { return "m1.g4"; } }

	public override string[] RuleNames { get { return ruleNames; } }

	public override string SerializedAtn { get { return new string(_serializedATN); } }

	static m1Parser() {
		decisionToDFA = new DFA[_ATN.NumberOfDecisions];
		for (int i = 0; i < _ATN.NumberOfDecisions; i++) {
			decisionToDFA[i] = new DFA(_ATN.GetDecisionState(i), i);
		}
	}

		public m1Parser(ITokenStream input) : this(input, Console.Out, Console.Error) { }

		public m1Parser(ITokenStream input, TextWriter output, TextWriter errorOutput)
		: base(input, output, errorOutput)
	{
		Interpreter = new ParserATNSimulator(this, _ATN, decisionToDFA, sharedContextCache);
	}

	public partial class Translation_unitContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public ExpressionContext expression() {
			return GetRuleContext<ExpressionContext>(0);
		}
		public Translation_unitContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_translation_unit; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterTranslation_unit(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitTranslation_unit(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitTranslation_unit(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public Translation_unitContext translation_unit() {
		Translation_unitContext _localctx = new Translation_unitContext(Context, State);
		EnterRule(_localctx, 0, RULE_translation_unit);
		try {
			EnterOuterAlt(_localctx, 1);
			{
			State = 28;
			expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class ExpressionContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public AdditionContext addition() {
			return GetRuleContext<AdditionContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public SubtractionContext subtraction() {
			return GetRuleContext<SubtractionContext>(0);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_expression; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterExpression(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitExpression(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitExpression(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public ExpressionContext expression() {
		ExpressionContext _localctx = new ExpressionContext(Context, State);
		EnterRule(_localctx, 2, RULE_expression);
		try {
			State = 32;
			ErrorHandler.Sync(this);
			switch ( Interpreter.AdaptivePredict(TokenStream,0,Context) ) {
			case 1:
				EnterOuterAlt(_localctx, 1);
				{
				State = 30;
				addition();
				}
				break;
			case 2:
				EnterOuterAlt(_localctx, 2);
				{
				State = 31;
				subtraction();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class AdditionContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public TermContext[] term() {
			return GetRuleContexts<TermContext>();
		}
		[System.Diagnostics.DebuggerNonUserCode] public TermContext term(int i) {
			return GetRuleContext<TermContext>(i);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Plus() { return GetToken(m1Parser.Plus, 0); }
		public AdditionContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_addition; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterAddition(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitAddition(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitAddition(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public AdditionContext addition() {
		AdditionContext _localctx = new AdditionContext(Context, State);
		EnterRule(_localctx, 4, RULE_addition);
		try {
			EnterOuterAlt(_localctx, 1);
			{
			State = 34;
			term();
			State = 35;
			Match(Plus);
			State = 36;
			term();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class SubtractionContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public TermContext[] term() {
			return GetRuleContexts<TermContext>();
		}
		[System.Diagnostics.DebuggerNonUserCode] public TermContext term(int i) {
			return GetRuleContext<TermContext>(i);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Minus() { return GetToken(m1Parser.Minus, 0); }
		public SubtractionContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_subtraction; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterSubtraction(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitSubtraction(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitSubtraction(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public SubtractionContext subtraction() {
		SubtractionContext _localctx = new SubtractionContext(Context, State);
		EnterRule(_localctx, 6, RULE_subtraction);
		try {
			EnterOuterAlt(_localctx, 1);
			{
			State = 38;
			term();
			State = 39;
			Match(Minus);
			State = 40;
			term();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class TermContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public ProductContext product() {
			return GetRuleContext<ProductContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public QuotientContext quotient() {
			return GetRuleContext<QuotientContext>(0);
		}
		public TermContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_term; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterTerm(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitTerm(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitTerm(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public TermContext term() {
		TermContext _localctx = new TermContext(Context, State);
		EnterRule(_localctx, 8, RULE_term);
		try {
			State = 44;
			ErrorHandler.Sync(this);
			switch ( Interpreter.AdaptivePredict(TokenStream,1,Context) ) {
			case 1:
				EnterOuterAlt(_localctx, 1);
				{
				State = 42;
				product();
				}
				break;
			case 2:
				EnterOuterAlt(_localctx, 2);
				{
				State = 43;
				quotient();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class ProductContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public FactorContext[] factor() {
			return GetRuleContexts<FactorContext>();
		}
		[System.Diagnostics.DebuggerNonUserCode] public FactorContext factor(int i) {
			return GetRuleContext<FactorContext>(i);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Mul() { return GetToken(m1Parser.Mul, 0); }
		public ProductContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_product; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterProduct(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitProduct(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitProduct(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public ProductContext product() {
		ProductContext _localctx = new ProductContext(Context, State);
		EnterRule(_localctx, 10, RULE_product);
		try {
			EnterOuterAlt(_localctx, 1);
			{
			State = 46;
			factor();
			State = 47;
			Match(Mul);
			State = 48;
			factor();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class QuotientContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public FactorContext[] factor() {
			return GetRuleContexts<FactorContext>();
		}
		[System.Diagnostics.DebuggerNonUserCode] public FactorContext factor(int i) {
			return GetRuleContext<FactorContext>(i);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Div() { return GetToken(m1Parser.Div, 0); }
		public QuotientContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_quotient; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterQuotient(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitQuotient(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitQuotient(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public QuotientContext quotient() {
		QuotientContext _localctx = new QuotientContext(Context, State);
		EnterRule(_localctx, 12, RULE_quotient);
		try {
			EnterOuterAlt(_localctx, 1);
			{
			State = 50;
			factor();
			State = 51;
			Match(Div);
			State = 52;
			factor();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class FactorContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public Postfix_unary_expressionContext postfix_unary_expression() {
			return GetRuleContext<Postfix_unary_expressionContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public AtomContext atom() {
			return GetRuleContext<AtomContext>(0);
		}
		public FactorContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_factor; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterFactor(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitFactor(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitFactor(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public FactorContext factor() {
		FactorContext _localctx = new FactorContext(Context, State);
		EnterRule(_localctx, 14, RULE_factor);
		try {
			State = 56;
			ErrorHandler.Sync(this);
			switch ( Interpreter.AdaptivePredict(TokenStream,2,Context) ) {
			case 1:
				EnterOuterAlt(_localctx, 1);
				{
				State = 54;
				postfix_unary_expression();
				}
				break;
			case 2:
				EnterOuterAlt(_localctx, 2);
				{
				State = 55;
				atom();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class Postfix_unary_expressionContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public ExponentiationContext exponentiation() {
			return GetRuleContext<ExponentiationContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public Postfix_unary_expressionContext postfix_unary_expression() {
			return GetRuleContext<Postfix_unary_expressionContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public AtomContext atom() {
			return GetRuleContext<AtomContext>(0);
		}
		public Postfix_unary_expressionContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_postfix_unary_expression; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterPostfix_unary_expression(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitPostfix_unary_expression(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitPostfix_unary_expression(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public Postfix_unary_expressionContext postfix_unary_expression() {
		Postfix_unary_expressionContext _localctx = new Postfix_unary_expressionContext(Context, State);
		EnterRule(_localctx, 16, RULE_postfix_unary_expression);
		try {
			State = 64;
			ErrorHandler.Sync(this);
			switch ( Interpreter.AdaptivePredict(TokenStream,3,Context) ) {
			case 1:
				EnterOuterAlt(_localctx, 1);
				{
				State = 58;
				exponentiation();
				State = 59;
				postfix_unary_expression();
				}
				break;
			case 2:
				EnterOuterAlt(_localctx, 2);
				{
				State = 61;
				atom();
				State = 62;
				postfix_unary_expression();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class ExponentiationContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public AtomContext[] atom() {
			return GetRuleContexts<AtomContext>();
		}
		[System.Diagnostics.DebuggerNonUserCode] public AtomContext atom(int i) {
			return GetRuleContext<AtomContext>(i);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Caret() { return GetToken(m1Parser.Caret, 0); }
		public ExponentiationContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_exponentiation; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterExponentiation(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitExponentiation(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitExponentiation(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public ExponentiationContext exponentiation() {
		ExponentiationContext _localctx = new ExponentiationContext(Context, State);
		EnterRule(_localctx, 18, RULE_exponentiation);
		try {
			EnterOuterAlt(_localctx, 1);
			{
			State = 66;
			atom();
			State = 67;
			Match(Caret);
			State = 68;
			atom();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class AtomContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public ParenthesizedContext parenthesized() {
			return GetRuleContext<ParenthesizedContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public Prefix_unary_expressionContext prefix_unary_expression() {
			return GetRuleContext<Prefix_unary_expressionContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public FunctionContext function() {
			return GetRuleContext<FunctionContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Number() { return GetToken(m1Parser.Number, 0); }
		public AtomContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_atom; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterAtom(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitAtom(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitAtom(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public AtomContext atom() {
		AtomContext _localctx = new AtomContext(Context, State);
		EnterRule(_localctx, 20, RULE_atom);
		try {
			State = 74;
			ErrorHandler.Sync(this);
			switch (TokenStream.LA(1)) {
			case LeftP:
				EnterOuterAlt(_localctx, 1);
				{
				State = 70;
				parenthesized();
				}
				break;
			case Plus:
			case Minus:
				EnterOuterAlt(_localctx, 2);
				{
				State = 71;
				prefix_unary_expression();
				}
				break;
			case Identifier:
				EnterOuterAlt(_localctx, 3);
				{
				State = 72;
				function();
				}
				break;
			case Number:
				EnterOuterAlt(_localctx, 4);
				{
				State = 73;
				Match(Number);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class ParenthesizedContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode LeftP() { return GetToken(m1Parser.LeftP, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public ExpressionContext expression() {
			return GetRuleContext<ExpressionContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode RightP() { return GetToken(m1Parser.RightP, 0); }
		public ParenthesizedContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_parenthesized; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterParenthesized(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitParenthesized(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitParenthesized(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public ParenthesizedContext parenthesized() {
		ParenthesizedContext _localctx = new ParenthesizedContext(Context, State);
		EnterRule(_localctx, 22, RULE_parenthesized);
		try {
			EnterOuterAlt(_localctx, 1);
			{
			State = 76;
			Match(LeftP);
			State = 77;
			expression();
			State = 78;
			Match(RightP);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class Prefix_unary_expressionContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Plus() { return GetToken(m1Parser.Plus, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public AtomContext atom() {
			return GetRuleContext<AtomContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Minus() { return GetToken(m1Parser.Minus, 0); }
		public Prefix_unary_expressionContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_prefix_unary_expression; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterPrefix_unary_expression(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitPrefix_unary_expression(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitPrefix_unary_expression(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public Prefix_unary_expressionContext prefix_unary_expression() {
		Prefix_unary_expressionContext _localctx = new Prefix_unary_expressionContext(Context, State);
		EnterRule(_localctx, 24, RULE_prefix_unary_expression);
		try {
			State = 84;
			ErrorHandler.Sync(this);
			switch (TokenStream.LA(1)) {
			case Plus:
				EnterOuterAlt(_localctx, 1);
				{
				State = 80;
				Match(Plus);
				State = 81;
				atom();
				}
				break;
			case Minus:
				EnterOuterAlt(_localctx, 2);
				{
				State = 82;
				Match(Minus);
				State = 83;
				atom();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class FunctionContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Identifier() { return GetToken(m1Parser.Identifier, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode LeftP() { return GetToken(m1Parser.LeftP, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public ExpressionContext[] expression() {
			return GetRuleContexts<ExpressionContext>();
		}
		[System.Diagnostics.DebuggerNonUserCode] public ExpressionContext expression(int i) {
			return GetRuleContext<ExpressionContext>(i);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode RightP() { return GetToken(m1Parser.RightP, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode[] Comma() { return GetTokens(m1Parser.Comma); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Comma(int i) {
			return GetToken(m1Parser.Comma, i);
		}
		public FunctionContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_function; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.EnterFunction(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			Im1Listener typedListener = listener as Im1Listener;
			if (typedListener != null) typedListener.ExitFunction(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override TResult Accept<TResult>(IParseTreeVisitor<TResult> visitor) {
			Im1Visitor<TResult> typedVisitor = visitor as Im1Visitor<TResult>;
			if (typedVisitor != null) return typedVisitor.VisitFunction(this);
			else return visitor.VisitChildren(this);
		}
	}

	[RuleVersion(0)]
	public FunctionContext function() {
		FunctionContext _localctx = new FunctionContext(Context, State);
		EnterRule(_localctx, 26, RULE_function);
		int _la;
		try {
			EnterOuterAlt(_localctx, 1);
			{
			State = 86;
			Match(Identifier);
			State = 87;
			Match(LeftP);
			State = 88;
			expression();
			State = 93;
			ErrorHandler.Sync(this);
			_la = TokenStream.LA(1);
			while (_la==Comma) {
				{
				{
				State = 89;
				Match(Comma);
				State = 90;
				expression();
				}
				}
				State = 95;
				ErrorHandler.Sync(this);
				_la = TokenStream.LA(1);
			}
			State = 96;
			Match(RightP);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	private static char[] _serializedATN = {
		'\x3', '\x608B', '\xA72A', '\x8133', '\xB9ED', '\x417C', '\x3BE7', '\x7786', 
		'\x5964', '\x3', '\xE', '\x65', '\x4', '\x2', '\t', '\x2', '\x4', '\x3', 
		'\t', '\x3', '\x4', '\x4', '\t', '\x4', '\x4', '\x5', '\t', '\x5', '\x4', 
		'\x6', '\t', '\x6', '\x4', '\a', '\t', '\a', '\x4', '\b', '\t', '\b', 
		'\x4', '\t', '\t', '\t', '\x4', '\n', '\t', '\n', '\x4', '\v', '\t', '\v', 
		'\x4', '\f', '\t', '\f', '\x4', '\r', '\t', '\r', '\x4', '\xE', '\t', 
		'\xE', '\x4', '\xF', '\t', '\xF', '\x3', '\x2', '\x3', '\x2', '\x3', '\x3', 
		'\x3', '\x3', '\x5', '\x3', '#', '\n', '\x3', '\x3', '\x4', '\x3', '\x4', 
		'\x3', '\x4', '\x3', '\x4', '\x3', '\x5', '\x3', '\x5', '\x3', '\x5', 
		'\x3', '\x5', '\x3', '\x6', '\x3', '\x6', '\x5', '\x6', '/', '\n', '\x6', 
		'\x3', '\a', '\x3', '\a', '\x3', '\a', '\x3', '\a', '\x3', '\b', '\x3', 
		'\b', '\x3', '\b', '\x3', '\b', '\x3', '\t', '\x3', '\t', '\x5', '\t', 
		';', '\n', '\t', '\x3', '\n', '\x3', '\n', '\x3', '\n', '\x3', '\n', '\x3', 
		'\n', '\x3', '\n', '\x5', '\n', '\x43', '\n', '\n', '\x3', '\v', '\x3', 
		'\v', '\x3', '\v', '\x3', '\v', '\x3', '\f', '\x3', '\f', '\x3', '\f', 
		'\x3', '\f', '\x5', '\f', 'M', '\n', '\f', '\x3', '\r', '\x3', '\r', '\x3', 
		'\r', '\x3', '\r', '\x3', '\xE', '\x3', '\xE', '\x3', '\xE', '\x3', '\xE', 
		'\x5', '\xE', 'W', '\n', '\xE', '\x3', '\xF', '\x3', '\xF', '\x3', '\xF', 
		'\x3', '\xF', '\x3', '\xF', '\a', '\xF', '^', '\n', '\xF', '\f', '\xF', 
		'\xE', '\xF', '\x61', '\v', '\xF', '\x3', '\xF', '\x3', '\xF', '\x3', 
		'\xF', '\x2', '\x2', '\x10', '\x2', '\x4', '\x6', '\b', '\n', '\f', '\xE', 
		'\x10', '\x12', '\x14', '\x16', '\x18', '\x1A', '\x1C', '\x2', '\x2', 
		'\x2', '_', '\x2', '\x1E', '\x3', '\x2', '\x2', '\x2', '\x4', '\"', '\x3', 
		'\x2', '\x2', '\x2', '\x6', '$', '\x3', '\x2', '\x2', '\x2', '\b', '(', 
		'\x3', '\x2', '\x2', '\x2', '\n', '.', '\x3', '\x2', '\x2', '\x2', '\f', 
		'\x30', '\x3', '\x2', '\x2', '\x2', '\xE', '\x34', '\x3', '\x2', '\x2', 
		'\x2', '\x10', ':', '\x3', '\x2', '\x2', '\x2', '\x12', '\x42', '\x3', 
		'\x2', '\x2', '\x2', '\x14', '\x44', '\x3', '\x2', '\x2', '\x2', '\x16', 
		'L', '\x3', '\x2', '\x2', '\x2', '\x18', 'N', '\x3', '\x2', '\x2', '\x2', 
		'\x1A', 'V', '\x3', '\x2', '\x2', '\x2', '\x1C', 'X', '\x3', '\x2', '\x2', 
		'\x2', '\x1E', '\x1F', '\x5', '\x4', '\x3', '\x2', '\x1F', '\x3', '\x3', 
		'\x2', '\x2', '\x2', ' ', '#', '\x5', '\x6', '\x4', '\x2', '!', '#', '\x5', 
		'\b', '\x5', '\x2', '\"', ' ', '\x3', '\x2', '\x2', '\x2', '\"', '!', 
		'\x3', '\x2', '\x2', '\x2', '#', '\x5', '\x3', '\x2', '\x2', '\x2', '$', 
		'%', '\x5', '\n', '\x6', '\x2', '%', '&', '\a', '\x3', '\x2', '\x2', '&', 
		'\'', '\x5', '\n', '\x6', '\x2', '\'', '\a', '\x3', '\x2', '\x2', '\x2', 
		'(', ')', '\x5', '\n', '\x6', '\x2', ')', '*', '\a', '\x4', '\x2', '\x2', 
		'*', '+', '\x5', '\n', '\x6', '\x2', '+', '\t', '\x3', '\x2', '\x2', '\x2', 
		',', '/', '\x5', '\f', '\a', '\x2', '-', '/', '\x5', '\xE', '\b', '\x2', 
		'.', ',', '\x3', '\x2', '\x2', '\x2', '.', '-', '\x3', '\x2', '\x2', '\x2', 
		'/', '\v', '\x3', '\x2', '\x2', '\x2', '\x30', '\x31', '\x5', '\x10', 
		'\t', '\x2', '\x31', '\x32', '\a', '\x5', '\x2', '\x2', '\x32', '\x33', 
		'\x5', '\x10', '\t', '\x2', '\x33', '\r', '\x3', '\x2', '\x2', '\x2', 
		'\x34', '\x35', '\x5', '\x10', '\t', '\x2', '\x35', '\x36', '\a', '\x6', 
		'\x2', '\x2', '\x36', '\x37', '\x5', '\x10', '\t', '\x2', '\x37', '\xF', 
		'\x3', '\x2', '\x2', '\x2', '\x38', ';', '\x5', '\x12', '\n', '\x2', '\x39', 
		';', '\x5', '\x16', '\f', '\x2', ':', '\x38', '\x3', '\x2', '\x2', '\x2', 
		':', '\x39', '\x3', '\x2', '\x2', '\x2', ';', '\x11', '\x3', '\x2', '\x2', 
		'\x2', '<', '=', '\x5', '\x14', '\v', '\x2', '=', '>', '\x5', '\x12', 
		'\n', '\x2', '>', '\x43', '\x3', '\x2', '\x2', '\x2', '?', '@', '\x5', 
		'\x16', '\f', '\x2', '@', '\x41', '\x5', '\x12', '\n', '\x2', '\x41', 
		'\x43', '\x3', '\x2', '\x2', '\x2', '\x42', '<', '\x3', '\x2', '\x2', 
		'\x2', '\x42', '?', '\x3', '\x2', '\x2', '\x2', '\x43', '\x13', '\x3', 
		'\x2', '\x2', '\x2', '\x44', '\x45', '\x5', '\x16', '\f', '\x2', '\x45', 
		'\x46', '\a', '\a', '\x2', '\x2', '\x46', 'G', '\x5', '\x16', '\f', '\x2', 
		'G', '\x15', '\x3', '\x2', '\x2', '\x2', 'H', 'M', '\x5', '\x18', '\r', 
		'\x2', 'I', 'M', '\x5', '\x1A', '\xE', '\x2', 'J', 'M', '\x5', '\x1C', 
		'\xF', '\x2', 'K', 'M', '\a', '\f', '\x2', '\x2', 'L', 'H', '\x3', '\x2', 
		'\x2', '\x2', 'L', 'I', '\x3', '\x2', '\x2', '\x2', 'L', 'J', '\x3', '\x2', 
		'\x2', '\x2', 'L', 'K', '\x3', '\x2', '\x2', '\x2', 'M', '\x17', '\x3', 
		'\x2', '\x2', '\x2', 'N', 'O', '\a', '\t', '\x2', '\x2', 'O', 'P', '\x5', 
		'\x4', '\x3', '\x2', 'P', 'Q', '\a', '\n', '\x2', '\x2', 'Q', '\x19', 
		'\x3', '\x2', '\x2', '\x2', 'R', 'S', '\a', '\x3', '\x2', '\x2', 'S', 
		'W', '\x5', '\x16', '\f', '\x2', 'T', 'U', '\a', '\x4', '\x2', '\x2', 
		'U', 'W', '\x5', '\x16', '\f', '\x2', 'V', 'R', '\x3', '\x2', '\x2', '\x2', 
		'V', 'T', '\x3', '\x2', '\x2', '\x2', 'W', '\x1B', '\x3', '\x2', '\x2', 
		'\x2', 'X', 'Y', '\a', '\r', '\x2', '\x2', 'Y', 'Z', '\a', '\t', '\x2', 
		'\x2', 'Z', '_', '\x5', '\x4', '\x3', '\x2', '[', '\\', '\a', '\v', '\x2', 
		'\x2', '\\', '^', '\x5', '\x4', '\x3', '\x2', ']', '[', '\x3', '\x2', 
		'\x2', '\x2', '^', '\x61', '\x3', '\x2', '\x2', '\x2', '_', ']', '\x3', 
		'\x2', '\x2', '\x2', '_', '`', '\x3', '\x2', '\x2', '\x2', '`', '\x62', 
		'\x3', '\x2', '\x2', '\x2', '\x61', '_', '\x3', '\x2', '\x2', '\x2', '\x62', 
		'\x63', '\a', '\n', '\x2', '\x2', '\x63', '\x1D', '\x3', '\x2', '\x2', 
		'\x2', '\t', '\"', '.', ':', '\x42', 'L', 'V', '_',
	};

	public static readonly ATN _ATN =
		new ATNDeserializer().Deserialize(_serializedATN);


}
