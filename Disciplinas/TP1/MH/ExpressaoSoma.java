public class ExpressaoSoma extends ExpressaoBinaria {

	public ExpressaoSoma(Expressao expDireita, Expressao expEsquerda) {
		super(expDireita, expEsquerda);
	}

	@Override
	public ValorInteiro avaliar() {
		try{
			ValorInteiro ve = (ValorInteiro)expEsquerda.avaliar();
			ValorInteiro vd = (ValorInteiro)expDireita.avaliar();
		
			return new ValorInteiro(ve.getValor() + vd.getValor());
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
