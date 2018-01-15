public class Or extends ExpressaoBinaria {

	public Or(Expressao expDireita, Expressao expEsquerda) {
		super(expDireita, expEsquerda);
	}

	@Override
	public ValorBooleano avaliar() {
		try{
			ValorBooleano v1 = (ValorBooleano) expEsquerda.avaliar();
			ValorBooleano v2 = (ValorBooleano) expDireita.avaliar();
	
			return new ValorBooleano(v1.getValor() || v2.getValor());

		}catch(Exception e){
			System.out.println("ERRO");
			System.exit(0);
			return new ValorBooleano(null);
		}


	}

	@Override
	public Tipo tipo() {
		return (expEsquerda.tipo() == Tipo.Booleano && expDireita.tipo() == Tipo.Booleano) ? Tipo.Booleano : Tipo.Error;
	}

	@Override
	public void aceitar(Visitor v) {
		v.visitar(this);
	}

}
