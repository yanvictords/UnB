import sintese.*;

public class testei2C3
{  
   InstrumentoT2C instrumentoC;
   Envoltoria   envA;
   Envoltoria   envS;
   Envoltoria   envR;   
   Envoltoria   envFREQUENCIACORTE;   
   Curva        curvaA;  
   Curva        curvaS;  
   Curva        curvaR;   

   public testei2C3()
   { 
     //instrumentoC  = new InstrumentoT2C(1);        //---instrumento atonal
     //instrumentoC  = new InstrumentoT2C(0.2f);     //---quase tonal
     //instrumentoC  = new InstrumentoT2C(0.065f);   //---atonal
     //instrumentoC  = new InstrumentoT2C(0.001f);   //---atonal ruidoso
     //instrumentoC  = new InstrumentoT2C(0.0001f);  //---tonal: formante estreita
     instrumentoC  = new InstrumentoT2C(0.00001f); //---tonal: som puro
     envA   = new Envoltoria(); 
     envS   = new Envoltoria(); 	
     envR   = new Envoltoria(); 	
     curvaA = new Curva(720);  
     curvaS = new Curva(720);
     curvaR = new Curva(720);   

     curvaA.addPonto(  0f,   0f);
     curvaA.addPonto( 30f, 400f);
     curvaA.addPonto(240f, 300f);
     curvaA.addPonto(720f,   0f);
     envA.setCURVA(curvaA);

     curvaS.addPonto(  0f,   0f);
     curvaS.addPonto( 60f, 600f);
     curvaS.addPonto(440f, 100f);
     curvaS.addPonto(720f,   0f);
     envS.setCURVA(curvaS);

     curvaR.addPonto(  0f,   0f);
     curvaR.addPonto( 20f, 500f);
     curvaR.addPonto(400f, 200f);
     curvaR.addPonto(720f,   0f);
     envR.setCURVA(curvaR); 
              
     instrumentoC  = new InstrumentoT2C(envA, envS, envR,  0.00001f);
     instrumentoC.setEnvoltoria(envA);
     instrumentoC.setSomador(envS);
     instrumentoC.setRuido(envR);
     instrumentoC.setLambda(0.5f);
     instrumentoC.setFase(0f);
     instrumentoC.setFrequencia(660);
     instrumentoC.setGanho(103);     
     
        
     //Melodia m2 = Tema.tema_aa_fuga1();
     //Melodia m2 = Tema.tema_aa_drawing_quintet_flauta();
     Melodia m2 = Tema.tema_duda_no_frevo_eq();
     
     m2.getAutor();     
     
     //m2.setAndamento(0.45f);
     m2.setAndamento(0.95f);

     Som som = m2.getSom(instrumentoC);     
     som.setNome("INSTRUMENTO C");   
     som.visualiza();

     try{ System.in.read();
          System.exit(0);
        }
     catch(Exception e){};          
     
   }      
      
   public static void main(String args[])
   { new testei2C3();
   }   

}
