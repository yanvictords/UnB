import sintese.*;

public class TESTEInstrumentoT2B
{  
   InstrumentoT2B instrumentoB;
   Envoltoria   env;   
   Envoltoria   envFREQUENCIACORTE;   
   Curva        curva;      
   
   public TESTEInstrumentoT2B()
   { 
     //instrumentoA  = new InstrumentoT2A(1);        //---instrumento atonal
     //instrumentoA  = new InstrumentoT2A(0.065f);   //---atonal
     //instrumentoA  = new InstrumentoT2A(0.001f);   //---atonal ruidoso
     //instrumentoA  = new InstrumentoT2A(0.0001f);  //---tonal: formante estreita
     //instrumentoA  = new InstrumentoT2A(0.00001f); //---tonal: som puro
     env   = new Envoltoria(); 
     curva = new Curva(720);     

     curva.addPonto(  0f,   0f);
     curva.addPonto( 30f, 400f);
     curva.addPonto(240f, 300f);
     curva.addPonto(720f,   0f);
      
     env.setCURVA(curva);
     instrumentoB  = new InstrumentoT2B(env, env, env, 0.1f);     //---quase tonal
            
     
        
     Melodia m2 = Tema.tema_aa_fuga1();
     //Melodia m2 = Tema.tema_aa_drawing_quintet_flauta();
     //Melodia m2 = Tema.tema_duda_no_frevo_eq();
     
     m2.getAutor();     
     
     //m2.setAndamento(0.45f);
     m2.setAndamento(0.95f);

     Som som = m2.getSom(instrumentoB);     
     som.setNome("teste2B");   
     som.visualiza();

     try{ System.in.read();
          System.exit(0);
        }
     catch(Exception e){};          
     
   }      
      
   public static void main(String args[])
   { new TESTEInstrumentoT2B();
   }   

}
