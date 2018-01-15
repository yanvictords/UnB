public class Not extends ExpressaoBinaria {

	public Not(Expressao expDireita) {
		super(expDireita, expDireita);
	}

	@Override
	public ValorBooleano avaliar() {
		try{
			ValorBooleano v1 = (ValorBooleano) expDireita.avaliar();
	
			return new ValorBooleano(!v1.getValor());

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
