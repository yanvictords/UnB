public class Maior extends ExpressaoBinaria {

	public Maior(Expressao expDireita, Expressao expEsquerda) {
		super(expDireita, expEsquerda);
	}

	@Override
	public ValorBooleano avaliar() {
		try{
			ValorInteiro v1 = (ValorInteiro) expDireita.avaliar();
			ValorInteiro v2 = (ValorInteiro) expEsquerda.avaliar();
		
			return new ValorBooleano(v1.getValor() > v2.getValor());
		}catch(Exception e){
			System.out.println("ERRO");
			System.exit(0);
			return new ValorBooleano(null);
		}

	}

	@Override
	public Tipo tipo() {
		return (expEsquerda.tipo() == Tipo.Inteiro && expDireita.tipo() == Tipo.Inteiro) ? Tipo.Booleano : Tipo.Error;
	}

	@Override
	public void aceitar(Visitor v) {
		v.visitar(this);
	}

}
