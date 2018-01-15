// Generated from Mini.g4 by ANTLR 4.6
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MiniParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.6", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		ATRIBUICAO=1, Load=2, Mhs=3, Aspas=4, Eval=5, LET=6, IN=7, IF=8, THEN=9, 
		ELSE=10, INT=11, BOOL=12, ARROW=13, DOUBLE_COLON=14, NOT=15, AND=16, OR=17, 
		MAIORQ=18, MAIORIGUALQ=19, MENORQ=20, MENORIGUALQ=21, IGUALA=22, TRUE=23, 
		FALSE=24, EPARENTESES=25, DPARENTESES=26, MAIS=27, MENOS=28, VEZES=29, 
		DIVIDIDOPOR=30, INTEIRO=31, ESPACO=32, RAW_Tipo=33, Fsoma=34, Fsubtracao=35, 
		Fdivisao=36, Fmultiplicacao=37, Virgula=38, IDENTIFICADOR=39;
	public static final int
		RULE_expressao = 0;
	public static final String[] ruleNames = {
		"expressao"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'='", "'loadFile'", "'.mhs'", "'\"'", "'eval'", "'let'", "'in'", 
		"'if'", "'then'", "'else'", "'Int'", "'Bool'", "'->'", "'::'", "'not'", 
		"'&&'", "'||'", "'>'", "'>='", "'<'", "'<='", "'=='", "'True'", "'False'", 
		"'('", "')'", "'+'", "'-'", "'*'", "'/'", null, null, null, "'soma'", 
		"'subtracao'", "'divisao'", "'multiplicacao'", "','"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "ATRIBUICAO", "Load", "Mhs", "Aspas", "Eval", "LET", "IN", "IF", 
		"THEN", "ELSE", "INT", "BOOL", "ARROW", "DOUBLE_COLON", "NOT", "AND", 
		"OR", "MAIORQ", "MAIORIGUALQ", "MENORQ", "MENORIGUALQ", "IGUALA", "TRUE", 
		"FALSE", "EPARENTESES", "DPARENTESES", "MAIS", "MENOS", "VEZES", "DIVIDIDOPOR", 
		"INTEIRO", "ESPACO", "RAW_Tipo", "Fsoma", "Fsubtracao", "Fdivisao", "Fmultiplicacao", 
		"Virgula", "IDENTIFICADOR"
	};
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
	public String getGrammarFileName() { return "Mini.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MiniParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class ExpressaoContext extends ParserRuleContext {
		public ExpressaoContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expressao; }
	 
		public ExpressaoContext() { }
		public void copyFrom(ExpressaoContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class MultiplicacaoContext extends ExpressaoContext {
		public ExpressaoContext esq;
		public ExpressaoContext dir;
		public TerminalNode Fmultiplicacao() { return getToken(MiniParser.Fmultiplicacao, 0); }
		public TerminalNode EPARENTESES() { return getToken(MiniParser.EPARENTESES, 0); }
		public TerminalNode Virgula() { return getToken(MiniParser.Virgula, 0); }
		public TerminalNode DPARENTESES() { return getToken(MiniParser.DPARENTESES, 0); }
		public List<ExpressaoContext> expressao() {
			return getRuleContexts(ExpressaoContext.class);
		}
		public ExpressaoContext expressao(int i) {
			return getRuleContext(ExpressaoContext.class,i);
		}
		public TerminalNode VEZES() { return getToken(MiniParser.VEZES, 0); }
		public MultiplicacaoContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitMultiplicacao(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class AvaliarContext extends ExpressaoContext {
		public ExpressaoContext exp;
		public TerminalNode Eval() { return getToken(MiniParser.Eval, 0); }
		public TerminalNode EPARENTESES() { return getToken(MiniParser.EPARENTESES, 0); }
		public List<TerminalNode> Aspas() { return getTokens(MiniParser.Aspas); }
		public TerminalNode Aspas(int i) {
			return getToken(MiniParser.Aspas, i);
		}
		public TerminalNode DPARENTESES() { return getToken(MiniParser.DPARENTESES, 0); }
		public ExpressaoContext expressao() {
			return getRuleContext(ExpressaoContext.class,0);
		}
		public AvaliarContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitAvaliar(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class MenorIgualContext extends ExpressaoContext {
		public ExpressaoContext esq;
		public ExpressaoContext dir;
		public TerminalNode MENORIGUALQ() { return getToken(MiniParser.MENORIGUALQ, 0); }
		public List<ExpressaoContext> expressao() {
			return getRuleContexts(ExpressaoContext.class);
		}
		public ExpressaoContext expressao(int i) {
			return getRuleContext(ExpressaoContext.class,i);
		}
		public MenorIgualContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitMenorIgual(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class ParentesesContext extends ExpressaoContext {
		public ExpressaoContext exp;
		public TerminalNode EPARENTESES() { return getToken(MiniParser.EPARENTESES, 0); }
		public TerminalNode DPARENTESES() { return getToken(MiniParser.DPARENTESES, 0); }
		public ExpressaoContext expressao() {
			return getRuleContext(ExpressaoContext.class,0);
		}
		public ParentesesContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitParenteses(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class LoadContext extends ExpressaoContext {
		public Token arquivo;
		public TerminalNode Load() { return getToken(MiniParser.Load, 0); }
		public TerminalNode EPARENTESES() { return getToken(MiniParser.EPARENTESES, 0); }
		public List<TerminalNode> Aspas() { return getTokens(MiniParser.Aspas); }
		public TerminalNode Aspas(int i) {
			return getToken(MiniParser.Aspas, i);
		}
		public TerminalNode Mhs() { return getToken(MiniParser.Mhs, 0); }
		public TerminalNode DPARENTESES() { return getToken(MiniParser.DPARENTESES, 0); }
		public TerminalNode IDENTIFICADOR() { return getToken(MiniParser.IDENTIFICADOR, 0); }
		public LoadContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitLoad(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class OrContext extends ExpressaoContext {
		public ExpressaoContext esq;
		public ExpressaoContext dir;
		public TerminalNode OR() { return getToken(MiniParser.OR, 0); }
		public List<ExpressaoContext> expressao() {
			return getRuleContexts(ExpressaoContext.class);
		}
		public ExpressaoContext expressao(int i) {
			return getRuleContext(ExpressaoContext.class,i);
		}
		public OrContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitOr(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class TrueContext extends ExpressaoContext {
		public TerminalNode TRUE() { return getToken(MiniParser.TRUE, 0); }
		public TrueContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitTrue(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class FalseContext extends ExpressaoContext {
		public TerminalNode FALSE() { return getToken(MiniParser.FALSE, 0); }
		public FalseContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitFalse(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class SubtracaoContext extends ExpressaoContext {
		public ExpressaoContext esq;
		public ExpressaoContext dir;
		public TerminalNode Fsubtracao() { return getToken(MiniParser.Fsubtracao, 0); }
		public TerminalNode EPARENTESES() { return getToken(MiniParser.EPARENTESES, 0); }
		public TerminalNode Virgula() { return getToken(MiniParser.Virgula, 0); }
		public TerminalNode DPARENTESES() { return getToken(MiniParser.DPARENTESES, 0); }
		public List<ExpressaoContext> expressao() {
			return getRuleContexts(ExpressaoContext.class);
		}
		public ExpressaoContext expressao(int i) {
			return getRuleContext(ExpressaoContext.class,i);
		}
		public TerminalNode MENOS() { return getToken(MiniParser.MENOS, 0); }
		public SubtracaoContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitSubtracao(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class DivisaoContext extends ExpressaoContext {
		public ExpressaoContext esq;
		public ExpressaoContext dir;
		public TerminalNode Fdivisao() { return getToken(MiniParser.Fdivisao, 0); }
		public TerminalNode EPARENTESES() { return getToken(MiniParser.EPARENTESES, 0); }
		public TerminalNode Virgula() { return getToken(MiniParser.Virgula, 0); }
		public TerminalNode DPARENTESES() { return getToken(MiniParser.DPARENTESES, 0); }
		public List<ExpressaoContext> expressao() {
			return getRuleContexts(ExpressaoContext.class);
		}
		public ExpressaoContext expressao(int i) {
			return getRuleContext(ExpressaoContext.class,i);
		}
		public TerminalNode DIVIDIDOPOR() { return getToken(MiniParser.DIVIDIDOPOR, 0); }
		public DivisaoContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitDivisao(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class NotContext extends ExpressaoContext {
		public ExpressaoContext exp;
		public TerminalNode NOT() { return getToken(MiniParser.NOT, 0); }
		public ExpressaoContext expressao() {
			return getRuleContext(ExpressaoContext.class,0);
		}
		public NotContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitNot(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class MaiorContext extends ExpressaoContext {
		public ExpressaoContext esq;
		public ExpressaoContext dir;
		public TerminalNode MAIORQ() { return getToken(MiniParser.MAIORQ, 0); }
		public List<ExpressaoContext> expressao() {
			return getRuleContexts(ExpressaoContext.class);
		}
		public ExpressaoContext expressao(int i) {
			return getRuleContext(ExpressaoContext.class,i);
		}
		public MaiorContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitMaior(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class MenorContext extends ExpressaoContext {
		public ExpressaoContext esq;
		public ExpressaoContext dir;
		public TerminalNode MENORQ() { return getToken(MiniParser.MENORQ, 0); }
		public List<ExpressaoContext> expressao() {
			return getRuleContexts(ExpressaoContext.class);
		}
		public ExpressaoContext expressao(int i) {
			return getRuleContext(ExpressaoContext.class,i);
		}
		public MenorContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitMenor(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class AndContext extends ExpressaoContext {
		public ExpressaoContext esq;
		public ExpressaoContext dir;
		public TerminalNode AND() { return getToken(MiniParser.AND, 0); }
		public List<ExpressaoContext> expressao() {
			return getRuleContexts(ExpressaoContext.class);
		}
		public ExpressaoContext expressao(int i) {
			return getRuleContext(ExpressaoContext.class,i);
		}
		public AndContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitAnd(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class SomaContext extends ExpressaoContext {
		public ExpressaoContext esq;
		public ExpressaoContext dir;
		public TerminalNode Fsoma() { return getToken(MiniParser.Fsoma, 0); }
		public TerminalNode EPARENTESES() { return getToken(MiniParser.EPARENTESES, 0); }
		public TerminalNode Virgula() { return getToken(MiniParser.Virgula, 0); }
		public TerminalNode DPARENTESES() { return getToken(MiniParser.DPARENTESES, 0); }
		public List<ExpressaoContext> expressao() {
			return getRuleContexts(ExpressaoContext.class);
		}
		public ExpressaoContext expressao(int i) {
			return getRuleContext(ExpressaoContext.class,i);
		}
		public TerminalNode MAIS() { return getToken(MiniParser.MAIS, 0); }
		public SomaContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitSoma(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class IgualContext extends ExpressaoContext {
		public ExpressaoContext esq;
		public ExpressaoContext dir;
		public TerminalNode IGUALA() { return getToken(MiniParser.IGUALA, 0); }
		public List<ExpressaoContext> expressao() {
			return getRuleContexts(ExpressaoContext.class);
		}
		public ExpressaoContext expressao(int i) {
			return getRuleContext(ExpressaoContext.class,i);
		}
		public IgualContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitIgual(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class LetContext extends ExpressaoContext {
		public Token nome;
		public ExpressaoContext valor;
		public ExpressaoContext corpo;
		public TerminalNode LET() { return getToken(MiniParser.LET, 0); }
		public TerminalNode ATRIBUICAO() { return getToken(MiniParser.ATRIBUICAO, 0); }
		public TerminalNode IN() { return getToken(MiniParser.IN, 0); }
		public TerminalNode EPARENTESES() { return getToken(MiniParser.EPARENTESES, 0); }
		public TerminalNode DPARENTESES() { return getToken(MiniParser.DPARENTESES, 0); }
		public TerminalNode IDENTIFICADOR() { return getToken(MiniParser.IDENTIFICADOR, 0); }
		public List<ExpressaoContext> expressao() {
			return getRuleContexts(ExpressaoContext.class);
		}
		public ExpressaoContext expressao(int i) {
			return getRuleContext(ExpressaoContext.class,i);
		}
		public LetContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitLet(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class MaiorIgualContext extends ExpressaoContext {
		public ExpressaoContext esq;
		public ExpressaoContext dir;
		public TerminalNode MAIORIGUALQ() { return getToken(MiniParser.MAIORIGUALQ, 0); }
		public List<ExpressaoContext> expressao() {
			return getRuleContexts(ExpressaoContext.class);
		}
		public ExpressaoContext expressao(int i) {
			return getRuleContext(ExpressaoContext.class,i);
		}
		public MaiorIgualContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitMaiorIgual(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class IdentificadorContext extends ExpressaoContext {
		public TerminalNode IDENTIFICADOR() { return getToken(MiniParser.IDENTIFICADOR, 0); }
		public IdentificadorContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitIdentificador(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class IfContext extends ExpressaoContext {
		public ExpressaoContext condicao;
		public ExpressaoContext clausula_then;
		public ExpressaoContext clausula_else;
		public TerminalNode IF() { return getToken(MiniParser.IF, 0); }
		public TerminalNode THEN() { return getToken(MiniParser.THEN, 0); }
		public TerminalNode ELSE() { return getToken(MiniParser.ELSE, 0); }
		public List<ExpressaoContext> expressao() {
			return getRuleContexts(ExpressaoContext.class);
		}
		public ExpressaoContext expressao(int i) {
			return getRuleContext(ExpressaoContext.class,i);
		}
		public IfContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitIf(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class InteiroContext extends ExpressaoContext {
		public TerminalNode INTEIRO() { return getToken(MiniParser.INTEIRO, 0); }
		public InteiroContext(ExpressaoContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniVisitor ) return ((MiniVisitor<? extends T>)visitor).visitInteiro(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ExpressaoContext expressao() throws RecognitionException {
		return expressao(0);
	}

	private ExpressaoContext expressao(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressaoContext _localctx = new ExpressaoContext(_ctx, _parentState);
		ExpressaoContext _prevctx = _localctx;
		int _startState = 0;
		enterRecursionRule(_localctx, 0, RULE_expressao, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(71);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case EPARENTESES:
				{
				_localctx = new ParentesesContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(3);
				match(EPARENTESES);
				setState(4);
				((ParentesesContext)_localctx).exp = expressao(0);
				setState(5);
				match(DPARENTESES);
				}
				break;
			case LET:
				{
				_localctx = new LetContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(7);
				match(LET);
				setState(8);
				((LetContext)_localctx).nome = match(IDENTIFICADOR);
				setState(9);
				match(ATRIBUICAO);
				setState(10);
				((LetContext)_localctx).valor = expressao(0);
				setState(11);
				match(IN);
				setState(12);
				match(EPARENTESES);
				setState(13);
				((LetContext)_localctx).corpo = expressao(0);
				setState(14);
				match(DPARENTESES);
				}
				break;
			case IF:
				{
				_localctx = new IfContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(16);
				match(IF);
				setState(17);
				((IfContext)_localctx).condicao = expressao(0);
				setState(18);
				match(THEN);
				setState(19);
				((IfContext)_localctx).clausula_then = expressao(0);
				setState(20);
				match(ELSE);
				setState(21);
				((IfContext)_localctx).clausula_else = expressao(23);
				}
				break;
			case INTEIRO:
				{
				_localctx = new InteiroContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(23);
				match(INTEIRO);
				}
				break;
			case IDENTIFICADOR:
				{
				_localctx = new IdentificadorContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(24);
				match(IDENTIFICADOR);
				}
				break;
			case TRUE:
				{
				_localctx = new TrueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(25);
				match(TRUE);
				}
				break;
			case FALSE:
				{
				_localctx = new FalseContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(26);
				match(FALSE);
				}
				break;
			case NOT:
				{
				_localctx = new NotContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(27);
				match(NOT);
				setState(28);
				((NotContext)_localctx).exp = expressao(18);
				}
				break;
			case Fsoma:
				{
				_localctx = new SomaContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(29);
				match(Fsoma);
				setState(30);
				match(EPARENTESES);
				setState(31);
				((SomaContext)_localctx).esq = expressao(0);
				setState(32);
				match(Virgula);
				setState(33);
				((SomaContext)_localctx).dir = expressao(0);
				setState(34);
				match(DPARENTESES);
				}
				break;
			case Fsubtracao:
				{
				_localctx = new SubtracaoContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(36);
				match(Fsubtracao);
				setState(37);
				match(EPARENTESES);
				setState(38);
				((SubtracaoContext)_localctx).esq = expressao(0);
				setState(39);
				match(Virgula);
				setState(40);
				((SubtracaoContext)_localctx).dir = expressao(0);
				setState(41);
				match(DPARENTESES);
				}
				break;
			case Fdivisao:
				{
				_localctx = new DivisaoContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(43);
				match(Fdivisao);
				setState(44);
				match(EPARENTESES);
				setState(45);
				((DivisaoContext)_localctx).esq = expressao(0);
				setState(46);
				match(Virgula);
				setState(47);
				((DivisaoContext)_localctx).dir = expressao(0);
				setState(48);
				match(DPARENTESES);
				}
				break;
			case Fmultiplicacao:
				{
				_localctx = new MultiplicacaoContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(50);
				match(Fmultiplicacao);
				setState(51);
				match(EPARENTESES);
				setState(52);
				((MultiplicacaoContext)_localctx).esq = expressao(0);
				setState(53);
				match(Virgula);
				setState(54);
				((MultiplicacaoContext)_localctx).dir = expressao(0);
				setState(55);
				match(DPARENTESES);
				}
				break;
			case Eval:
				{
				_localctx = new AvaliarContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(57);
				match(Eval);
				setState(58);
				match(EPARENTESES);
				setState(59);
				match(Aspas);
				setState(60);
				((AvaliarContext)_localctx).exp = expressao(0);
				setState(61);
				match(Aspas);
				setState(62);
				match(DPARENTESES);
				}
				break;
			case Load:
				{
				_localctx = new LoadContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(64);
				match(Load);
				setState(65);
				match(EPARENTESES);
				setState(66);
				match(Aspas);
				setState(67);
				((LoadContext)_localctx).arquivo = match(IDENTIFICADOR);
				setState(68);
				match(Mhs);
				setState(69);
				match(Aspas);
				setState(70);
				match(DPARENTESES);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(108);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(106);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
					case 1:
						{
						_localctx = new AndContext(new ExpressaoContext(_parentctx, _parentState));
						((AndContext)_localctx).esq = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expressao);
						setState(73);
						if (!(precpred(_ctx, 17))) throw new FailedPredicateException(this, "precpred(_ctx, 17)");
						setState(74);
						match(AND);
						setState(75);
						((AndContext)_localctx).dir = expressao(18);
						}
						break;
					case 2:
						{
						_localctx = new OrContext(new ExpressaoContext(_parentctx, _parentState));
						((OrContext)_localctx).esq = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expressao);
						setState(76);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(77);
						match(OR);
						setState(78);
						((OrContext)_localctx).dir = expressao(17);
						}
						break;
					case 3:
						{
						_localctx = new MaiorContext(new ExpressaoContext(_parentctx, _parentState));
						((MaiorContext)_localctx).esq = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expressao);
						setState(79);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(80);
						match(MAIORQ);
						setState(81);
						((MaiorContext)_localctx).dir = expressao(16);
						}
						break;
					case 4:
						{
						_localctx = new MaiorIgualContext(new ExpressaoContext(_parentctx, _parentState));
						((MaiorIgualContext)_localctx).esq = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expressao);
						setState(82);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(83);
						match(MAIORIGUALQ);
						setState(84);
						((MaiorIgualContext)_localctx).dir = expressao(15);
						}
						break;
					case 5:
						{
						_localctx = new MenorContext(new ExpressaoContext(_parentctx, _parentState));
						((MenorContext)_localctx).esq = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expressao);
						setState(85);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(86);
						match(MENORQ);
						setState(87);
						((MenorContext)_localctx).dir = expressao(14);
						}
						break;
					case 6:
						{
						_localctx = new MenorIgualContext(new ExpressaoContext(_parentctx, _parentState));
						((MenorIgualContext)_localctx).esq = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expressao);
						setState(88);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(89);
						match(MENORIGUALQ);
						setState(90);
						((MenorIgualContext)_localctx).dir = expressao(13);
						}
						break;
					case 7:
						{
						_localctx = new IgualContext(new ExpressaoContext(_parentctx, _parentState));
						((IgualContext)_localctx).esq = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expressao);
						setState(91);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(92);
						match(IGUALA);
						setState(93);
						((IgualContext)_localctx).dir = expressao(12);
						}
						break;
					case 8:
						{
						_localctx = new SomaContext(new ExpressaoContext(_parentctx, _parentState));
						((SomaContext)_localctx).esq = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expressao);
						setState(94);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(95);
						match(MAIS);
						setState(96);
						((SomaContext)_localctx).dir = expressao(11);
						}
						break;
					case 9:
						{
						_localctx = new SubtracaoContext(new ExpressaoContext(_parentctx, _parentState));
						((SubtracaoContext)_localctx).esq = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expressao);
						setState(97);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(98);
						match(MENOS);
						setState(99);
						((SubtracaoContext)_localctx).dir = expressao(10);
						}
						break;
					case 10:
						{
						_localctx = new MultiplicacaoContext(new ExpressaoContext(_parentctx, _parentState));
						((MultiplicacaoContext)_localctx).esq = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expressao);
						setState(100);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(101);
						match(VEZES);
						setState(102);
						((MultiplicacaoContext)_localctx).dir = expressao(9);
						}
						break;
					case 11:
						{
						_localctx = new DivisaoContext(new ExpressaoContext(_parentctx, _parentState));
						((DivisaoContext)_localctx).esq = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expressao);
						setState(103);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(104);
						match(DIVIDIDOPOR);
						setState(105);
						((DivisaoContext)_localctx).dir = expressao(8);
						}
						break;
					}
					} 
				}
				setState(110);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 0:
			return expressao_sempred((ExpressaoContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expressao_sempred(ExpressaoContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 17);
		case 1:
			return precpred(_ctx, 16);
		case 2:
			return precpred(_ctx, 15);
		case 3:
			return precpred(_ctx, 14);
		case 4:
			return precpred(_ctx, 13);
		case 5:
			return precpred(_ctx, 12);
		case 6:
			return precpred(_ctx, 11);
		case 7:
			return precpred(_ctx, 10);
		case 8:
			return precpred(_ctx, 9);
		case 9:
			return precpred(_ctx, 8);
		case 10:
			return precpred(_ctx, 7);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3)r\4\2\t\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\5\2J\n\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\7\2m\n\2"+
		"\f\2\16\2p\13\2\3\2\2\3\2\3\2\2\2\u0088\2I\3\2\2\2\4\5\b\2\1\2\5\6\7\33"+
		"\2\2\6\7\5\2\2\2\7\b\7\34\2\2\bJ\3\2\2\2\t\n\7\b\2\2\n\13\7)\2\2\13\f"+
		"\7\3\2\2\f\r\5\2\2\2\r\16\7\t\2\2\16\17\7\33\2\2\17\20\5\2\2\2\20\21\7"+
		"\34\2\2\21J\3\2\2\2\22\23\7\n\2\2\23\24\5\2\2\2\24\25\7\13\2\2\25\26\5"+
		"\2\2\2\26\27\7\f\2\2\27\30\5\2\2\31\30J\3\2\2\2\31J\7!\2\2\32J\7)\2\2"+
		"\33J\7\31\2\2\34J\7\32\2\2\35\36\7\21\2\2\36J\5\2\2\24\37 \7$\2\2 !\7"+
		"\33\2\2!\"\5\2\2\2\"#\7(\2\2#$\5\2\2\2$%\7\34\2\2%J\3\2\2\2&\'\7%\2\2"+
		"\'(\7\33\2\2()\5\2\2\2)*\7(\2\2*+\5\2\2\2+,\7\34\2\2,J\3\2\2\2-.\7&\2"+
		"\2./\7\33\2\2/\60\5\2\2\2\60\61\7(\2\2\61\62\5\2\2\2\62\63\7\34\2\2\63"+
		"J\3\2\2\2\64\65\7\'\2\2\65\66\7\33\2\2\66\67\5\2\2\2\678\7(\2\289\5\2"+
		"\2\29:\7\34\2\2:J\3\2\2\2;<\7\7\2\2<=\7\33\2\2=>\7\6\2\2>?\5\2\2\2?@\7"+
		"\6\2\2@A\7\34\2\2AJ\3\2\2\2BC\7\4\2\2CD\7\33\2\2DE\7\6\2\2EF\7)\2\2FG"+
		"\7\5\2\2GH\7\6\2\2HJ\7\34\2\2I\4\3\2\2\2I\t\3\2\2\2I\22\3\2\2\2I\31\3"+
		"\2\2\2I\32\3\2\2\2I\33\3\2\2\2I\34\3\2\2\2I\35\3\2\2\2I\37\3\2\2\2I&\3"+
		"\2\2\2I-\3\2\2\2I\64\3\2\2\2I;\3\2\2\2IB\3\2\2\2Jn\3\2\2\2KL\f\23\2\2"+
		"LM\7\22\2\2Mm\5\2\2\24NO\f\22\2\2OP\7\23\2\2Pm\5\2\2\23QR\f\21\2\2RS\7"+
		"\24\2\2Sm\5\2\2\22TU\f\20\2\2UV\7\25\2\2Vm\5\2\2\21WX\f\17\2\2XY\7\26"+
		"\2\2Ym\5\2\2\20Z[\f\16\2\2[\\\7\27\2\2\\m\5\2\2\17]^\f\r\2\2^_\7\30\2"+
		"\2_m\5\2\2\16`a\f\f\2\2ab\7\35\2\2bm\5\2\2\rcd\f\13\2\2de\7\36\2\2em\5"+
		"\2\2\ffg\f\n\2\2gh\7\37\2\2hm\5\2\2\13ij\f\t\2\2jk\7 \2\2km\5\2\2\nlK"+
		"\3\2\2\2lN\3\2\2\2lQ\3\2\2\2lT\3\2\2\2lW\3\2\2\2lZ\3\2\2\2l]\3\2\2\2l"+
		"`\3\2\2\2lc\3\2\2\2lf\3\2\2\2li\3\2\2\2mp\3\2\2\2nl\3\2\2\2no\3\2\2\2"+
		"o\3\3\2\2\2pn\3\2\2\2\5Iln";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}