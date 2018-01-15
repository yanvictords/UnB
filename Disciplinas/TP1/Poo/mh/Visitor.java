/**
 * Interface com a declaracao dos metodos que 
 * "visitam" aplicando alguma operacao sobre 
 * os elementos sintaticos de uma linguagem 
 * de programacao. 
 * @author rbonifacio
 *
 */
public interface Visitor {
	public void visitar(ValorInteiro exp);
	public void visitar(ValorBooleano exp);
	public void visitar(ExpressaoSoma exp);
	public void visitar(Multiplicacao exp);
	public void visitar(IfThenElse exp);
	public void visitar(AplicacaoFuncao exp);
	public void visitar(Identificador exp);
	public void visitar(Subtracao exp);
	public void visitar(Divisao exp);
	public void visitar(And exp);
	public void visitar(Or exp);
	public void visitar(Not exp);
	public void visitar(Igual exp);
	public void visitar(Maior exp);
	public void visitar(Menor exp);
	public void visitar(MaiorIgual exp);
	public void visitar(MenorIgual exp);
}
