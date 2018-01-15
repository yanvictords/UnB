import sintese.*;
/**
 * Constroi um instrumento (formante espectral básico) para o Trabalho T2, item 'a'.
 *
 * @since 02/06/2015
*/
 
public class InstrumentoT2B extends Dispositivo
{
    private boolean    canal;
    private float      lambda;
    private float      ummenoslambda;
    private float      fase;
    private float      ganho = 1;
   
    private Envoltoria envAMPLITUDE;
    private Ruido      geradorRUIDO;   //--unidade de Ruído
    private Oscilador  oscSENOIDAL;    //--unidade Senoidal
    private Envoltoria envSOMADOR;
    private Envoltoria envRUIDO;
   
    private float fatorCorte;

   public InstrumentoT2B(float fc)
    { this(new Envoltoria(), new Envoltoria(), new Envoltoria(), new Ruido(), fc);
    }

    public InstrumentoT2B( Envoltoria env_,Envoltoria env_s, Envoltoria env_r, Ruido ruido_ , float fc_)
    {  
        super();      
        fatorCorte = fc_;
       
        this.geradorRUIDO    = ruido_;
        this.envAMPLITUDE    = env_;
        this.envSOMADOR      = env_s;
        this.envRUIDO        = env_r;
        this.oscSENOIDAL = new Oscilador();
        this.setRelogio(0);
    }
   
   
    public void relogio()
    {
        oscSENOIDAL.relogio();
    }
   
   
    public void setRelogio(long n)
    {
      envAMPLITUDE.setRelogio(n);
      oscSENOIDAL.setRelogio(n);
      geradorRUIDO.setRelogio(n);
      this.saida = oscSENOIDAL.getSaida()*((canal) ? ummenoslambda : lambda);
      canal = !canal;
      reset();
    }
       
 
    public float getSaida()
    {        
      this.saida = oscSENOIDAL.getSaida()*((canal) ? ummenoslambda : lambda);
      canal      = !canal;
      return ganho*this.saida;
    }
   
   
    public void reset()
    {        
        envAMPLITUDE.setDuracao(duracao);
	envSOMADOR.setDuracao(duracao);
	envRUIDO.setDuracao(duracao);
	envRUIDO.reset();
	envSOMADOR.reset();
        envAMPLITUDE.reset();
 
        geradorRUIDO.setDispositivoAmplitude(envRUIDO);
        geradorRUIDO.setFrequencia((float)frequencia*fatorCorte);
        geradorRUIDO.setFase(fase);
        geradorRUIDO.setDuracao(duracao);
        geradorRUIDO.reset();
               
        oscSENOIDAL.setDispositivoAmplitude(envAMPLITUDE);
        oscSENOIDAL.setFrequencia(new Somador( envSOMADOR,geradorRUIDO ).getSaida());
        oscSENOIDAL.setFase(fase);
        oscSENOIDAL.setDuracao(duracao);
        oscSENOIDAL.reset();                
    }
 
 
 
    public void setGanho(float g)
    {this.ganho = g;
     
    }
 
    public void setDuracao(float d)
    {  
        this.duracao = d;
        envAMPLITUDE    .setDuracao(d);
        envSOMADOR      .setDuracao(d);
        envRUIDO        .setDuracao(d);
        geradorRUIDO    .setDuracao(d);
        oscSENOIDAL     .setDuracao(d);
        reset();
    }
 
 
    public void setFrequencia(float freq)
    { this.frequencia = freq;
      reset();
    }
 
    public void setLambda(double lambda_)
    { this.lambda = (float)lambda_;
      this.ummenoslambda = 1 - this.lambda;
      reset();
    }
	 public void setRuido(Envoltoria envRUIDO)
    { this.envRUIDO = envRUIDO;
      reset();
    }
	
	public void setSomador(Envoltoria envSOMADOR)
    { this.envSOMADOR = envSOMADOR;
      reset();
    }
 
	public void setEnvoltoria(Envoltoria envAMPLITUDE)
    { this.envAMPLITUDE = envAMPLITUDE;
      reset();
    }
    public void setFase(float fase)
    { this.fase = fase;
      reset();
    }
 
}
