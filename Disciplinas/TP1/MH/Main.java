public class Main{
	public static void main(String[] args){
		ValorInteiro exp1 = new ValorInteiro(3);
		ValorInteiro exp2 = new ValorInteiro(10);
		ValorBooleano vb1 = new ValorBooleano(true);
		ValorBooleano vb2 = new ValorBooleano(false);

		Multiplicacao multiplica = new Multiplicacao(exp1, exp2);
		And andand = new And(vb1,vb2);
		Not notnot = new Not(vb1);
		Maior maimai = new Maior(exp1,exp2);
		ExpressaoSoma soma = new ExpressaoSoma(exp1,exp2);
		ValorInteiro executa = multiplica.avaliar();
		ValorInteiro executa2 = soma.avaliar();
		PrettyPrinter printer = new PrettyPrinter();
		printer.visitar(executa);
		ValorBooleano vb3 = maimai.avaliar();
		printer.visitar(executa2);

	}
}