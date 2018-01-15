// Generated from Mini.g4 by ANTLR 4.6
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link MiniParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface MiniVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by the {@code Multiplicacao}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMultiplicacao(MiniParser.MultiplicacaoContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Avaliar}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAvaliar(MiniParser.AvaliarContext ctx);
	/**
	 * Visit a parse tree produced by the {@code MenorIgual}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMenorIgual(MiniParser.MenorIgualContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Parenteses}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParenteses(MiniParser.ParentesesContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Load}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLoad(MiniParser.LoadContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Or}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOr(MiniParser.OrContext ctx);
	/**
	 * Visit a parse tree produced by the {@code True}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTrue(MiniParser.TrueContext ctx);
	/**
	 * Visit a parse tree produced by the {@code False}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFalse(MiniParser.FalseContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Subtracao}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSubtracao(MiniParser.SubtracaoContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Divisao}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDivisao(MiniParser.DivisaoContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Not}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNot(MiniParser.NotContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Maior}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMaior(MiniParser.MaiorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Menor}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMenor(MiniParser.MenorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code And}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnd(MiniParser.AndContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Soma}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSoma(MiniParser.SomaContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Igual}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIgual(MiniParser.IgualContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Let}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLet(MiniParser.LetContext ctx);
	/**
	 * Visit a parse tree produced by the {@code MaiorIgual}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMaiorIgual(MiniParser.MaiorIgualContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Identificador}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentificador(MiniParser.IdentificadorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code If}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIf(MiniParser.IfContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Inteiro}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInteiro(MiniParser.InteiroContext ctx);
}