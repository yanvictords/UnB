public class Divisao extends ExpressaoBinaria {

	public Divisao(Expressao expDireita, Expressao expEsquerda) {
		super(expDireita, expEsquerda);
	}

	@Override
	public ValorInteiro avaliar() {
		try{
			ValorInteiro v1 = (ValorInteiro) expDireita.avaliar();
			ValorInteiro v2 = (ValorInteiro) expEsquerda.avaliar();
			return new ValorInteiro( (int) (v1.getValor() / v2.getValor()));

		}catch(Exception e){
			System.out.println("ERRO");
			System.exit(0);
			return new ValorInteiro(null);
		}
	}

	@Override
	public Tipo tipo() {
		return (expEsquerda.tipo() == Tipo.Inteiro && expDireita.tipo() == Tipo.Inteiro) ? Tipo.Inteiro : Tipo.Error;
	}

	@Override
	public void aceitar(Visitor v) {
		v.visitar(this);
	}

}
