public class Teste{
	public static void main(String[] args){


		ValorInteiro multiplicacao1 = new ValorInteiro(15);
		ValorInteiro multiplicacao2 = new ValorInteiro(10);

		ValorInteiro soma1 = new ValorInteiro(15);
		ValorInteiro soma2 = new ValorInteiro(10);

		ValorInteiro subtracao1 = new ValorInteiro(15);
		ValorInteiro subtracao2 = new ValorInteiro(10);

		ValorInteiro divisao1 = new ValorInteiro(-5);
		ValorInteiro divisao2 = new ValorInteiro(10);

		ValorBooleano and1 = new ValorBooleano(false);
		ValorBooleano and2 = new ValorBooleano(true);

		ValorBooleano or1 = new ValorBooleano(true);
		ValorBooleano or2 = new ValorBooleano(false);

		ValorBooleano not1 = new ValorBooleano(true);
		ValorBooleano not2 = new ValorBooleano(false);

		ValorInteiro igual1 = new ValorInteiro(10);
		ValorInteiro igual2 = new ValorInteiro(9);

		ValorInteiro maior1 = new ValorInteiro(10);
		ValorInteiro maior2 = new ValorInteiro(9);

		ValorInteiro menor1 = new ValorInteiro(10);
		ValorInteiro menor2 = new ValorInteiro(9);

		ValorInteiro maiorigual1 = new ValorInteiro(9);
		ValorInteiro maiorigual2 = new ValorInteiro(10);

		ValorInteiro menorigual1 = new ValorInteiro(9);
		ValorInteiro menorigual2 = new ValorInteiro(10);

		PrettyPrinter printer = new PrettyPrinter();


		System.out.println("Multiplicacao: ");
		Multiplicacao multiplicacao = new Multiplicacao(multiplicacao1,multiplicacao2);	
		printer.visitar(multiplicacao);
		System.out.print(" = ");
		printer.visitar(multiplicacao.avaliar());
		System.out.println();
		multiplicacao = new Multiplicacao(multiplicacao2,multiplicacao1);	
		printer.visitar(multiplicacao);
		System.out.print(" = ");
		printer.visitar(multiplicacao.avaliar());

		System.out.println("\nSoma: ");
		ExpressaoSoma soma = new ExpressaoSoma(soma1,soma2);	
		printer.visitar(soma);
		System.out.print(" = ");
		printer.visitar(soma.avaliar());
		System.out.println();
		soma = new ExpressaoSoma(soma2,soma1);	
		printer.visitar(soma);
		System.out.print(" = ");
		printer.visitar(soma.avaliar());

		System.out.println("\nSubtracao: ");
		Subtracao subtracao = new Subtracao(subtracao1,subtracao2);	
		printer.visitar(subtracao);
		System.out.print(" = ");
		printer.visitar(subtracao.avaliar());
		System.out.println();
		subtracao = new Subtracao(subtracao2,subtracao1);	
		printer.visitar(subtracao);
		System.out.print(" = ");
		printer.visitar(subtracao.avaliar());


		System.out.println("\nDivisao: ");
		Divisao divisao = new Divisao(divisao1, divisao2);
		printer.visitar(divisao);
		System.out.print(" = ");
		printer.visitar(divisao.avaliar());
		System.out.println();
		divisao = new Divisao(divisao2, divisao1);
		printer.visitar(divisao);
		System.out.print(" = ");
		printer.visitar(divisao.avaliar());

		System.out.println("\nAnd: ");
		And and = new And(and1,and2);
		printer.visitar(and);
		System.out.print(" = ");
		printer.visitar(and.avaliar());
		System.out.println();
		and = new And(and2,and1);
		printer.visitar(and);
		System.out.print(" = ");
		printer.visitar(and.avaliar());
		System.out.println();
		and = new And(and1,and1);
		printer.visitar(and);
		System.out.print(" = ");
		printer.visitar(and.avaliar());
		System.out.println();
		and = new And(and2,and2);
		printer.visitar(and);
		System.out.print(" = ");
		printer.visitar(and.avaliar());

		System.out.println("\nOr: ");
		Or or = new Or(or1,or2);
		printer.visitar(or);
		System.out.print(" = ");
		printer.visitar(or.avaliar());
		System.out.println();
		or = new Or(or2,or1);
		printer.visitar(or);
		System.out.print(" = ");
		printer.visitar(or.avaliar());
		System.out.println();
		or = new Or(or1,or1);
		printer.visitar(or);
		System.out.print(" = ");
		printer.visitar(or.avaliar());
		System.out.println();
		or = new Or(or2,or2);
		printer.visitar(or);
		System.out.print(" = ");
		printer.visitar(or.avaliar());

		System.out.println("\nNot: ");
		Not not = new Not(not1);
		printer.visitar(not);
		System.out.print(" = ");
		printer.visitar(not.avaliar());
		System.out.println();
		not = new Not(not2);
		printer.visitar(not);
		System.out.print(" = ");
		printer.visitar(not.avaliar());


		System.out.println("\nIgual: ");
		Igual igual = new Igual(igual1,igual2);
		printer.visitar(igual);
		System.out.print(" = ");
		printer.visitar(igual.avaliar());
		System.out.println();
		igual = new Igual(igual2,igual1);
		printer.visitar(igual);
		System.out.print(" = ");
		printer.visitar(igual.avaliar());
		System.out.println();
		igual = new Igual(igual1,igual1);
		printer.visitar(igual);
		System.out.print(" = ");
		printer.visitar(igual.avaliar());


		System.out.println("\nMaior: ");
		Maior maior = new Maior(maior1,maior2);
		printer.visitar(maior);
		System.out.print(" = ");
		printer.visitar(maior.avaliar());
		System.out.println();
		maior = new Maior(maior2,maior1);
		printer.visitar(maior);
		System.out.print(" = ");
		printer.visitar(maior.avaliar());

		System.out.println("\nMenor: ");
		Menor menor = new Menor(menor1,menor2);
		printer.visitar(menor);
		System.out.print(" = ");
		printer.visitar(menor.avaliar());
		System.out.println();
		menor = new Menor(menor2,menor1);
		printer.visitar(menor);
		System.out.print(" = ");
		printer.visitar(menor.avaliar());

		System.out.println("\nMaiorIgual: ");
		MaiorIgual maiorigual = new MaiorIgual(maiorigual1,maiorigual2);
		printer.visitar(maiorigual);
		System.out.print(" = ");
		printer.visitar(maiorigual.avaliar());
		System.out.println();
		maiorigual = new MaiorIgual(maiorigual2,maiorigual1);
		printer.visitar(maiorigual);
		System.out.print(" = ");
		printer.visitar(maiorigual.avaliar());
		System.out.println();
		maiorigual = new MaiorIgual(maiorigual1,maiorigual1);
		printer.visitar(maiorigual);
		System.out.print(" = ");
		printer.visitar(maiorigual.avaliar());

		System.out.println("\nMenorIgual: ");
		MenorIgual menorigual = new MenorIgual(menorigual1,menorigual2);
		printer.visitar(menorigual);
		System.out.print(" = ");
		printer.visitar(menorigual.avaliar());
		System.out.println();
		menorigual = new MenorIgual(menorigual2,menorigual1);
		printer.visitar(menorigual);
		System.out.print(" = ");
		printer.visitar(menorigual.avaliar());
		System.out.println();
		menorigual = new MenorIgual(menorigual1,menorigual1);
		printer.visitar(menorigual);
		System.out.print(" = ");
		printer.visitar(menorigual.avaliar());

		System.out.println("\nAs verificacoes de tipo foram feitas dentro de cada funcao.\n ");


	}
}
