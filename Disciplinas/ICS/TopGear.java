 /**
  * MidiJS
  *
  * @author ICS-CIC-UnB
  * @version 1.0, 06/09/2001
  */

import javax.sound.midi.*;

class MidiJS
{
    Synthesizer   sintetizador;
    Instrument    instrumentos[];
    DadosDeCanal  canais[];
           
    class DadosDeCanal 
    { MidiChannel canalMIDI;
    
      public DadosDeCanal(MidiChannel canal) 
      { this.canalMIDI = canal;
      }
    } 

                        
    public MidiJS() 
    { this.open();
    }
        
    public void note_on(int tec, int vel, int kan) 
    { canais[kan].canalMIDI.noteOn(tec, vel);
    }
    
    public void note_off(int tec, int vel, int kan) 
    { canais[kan].canalMIDI.noteOff(tec, vel);
    }
    
    public void program_change(int programa, int kan) 
    { canais[kan].canalMIDI.programChange(programa);            
    }
    
    public void control_change(int controle, int valor, int kan) 
    { canais[kan].canalMIDI.controlChange(controle, valor);            
    }
  
    public void pan(int valor, int kan) 
    { canais[kan].canalMIDI.controlChange(10, valor);
    }
    
    public void reset(int kan)
    { canais[kan].canalMIDI.controlChange(121, 0);
    }
    
    public void ataque(int valor, int kan) 
    { canais[kan].canalMIDI.controlChange(73, valor);
    }
        
    void bank_select_all(int banco)
    { for (int i=0; i<15; i++)
      this.bank_select(banco, i);
    }
        
    public void bank_select(int bancoMIDI, int kan)
    { canais[kan].canalMIDI.controlChange(0, bancoMIDI);
    }    
            
    public void notes_off_canal(int kan)
    { canais[kan].canalMIDI.controlChange(123, 0);
    }
    
    public void notes_off_geral()
    { for(int i=0; i<canais.length; i++) 
      this.notes_off_canal(i);
    }
    
    
	void toca(int instru, float dur, int tec, int lsb, int msb, int p1, int p2, int p3, int p4, int ort, int kan)
	{
	  int veloc  = p1+p2+p3+p4;
	  int instr  = instru;
	  int tecla  = tec;
	  int orto   = ort;
	  int kanal  = kan;
	
	  program_change(instr, kanal);
	  pan(orto, kanal);
	  //pitch_bend(lsb, msb, kanal);
	  ataque(instru, kanal); 
	  note_on(tecla, veloc, kanal); 
	}
	  
	public void open() 
	{ try { if (sintetizador == null) 
	        { if ((sintetizador = MidiSystem.getSynthesizer()) == null) 
	           { System.out.println("getSynthesizer() falhou!"); return;}
	        } 
	     sintetizador.open();
	   } 
	  catch (Exception ex) { ex.printStackTrace(); return; }
	  Soundbank sb = sintetizador.getDefaultSoundbank();
	  if (sb != null) 
	  { instrumentos = sintetizador.getDefaultSoundbank().getInstruments();
	    sintetizador.loadInstrument(instrumentos[0]);
	  }
	  MidiChannel canaisMidi[] = sintetizador.getChannels();
	  canais = new DadosDeCanal[canaisMidi.length];                
	  for(int i=0; i<canais.length; i++) 
	  { canais[i]= new DadosDeCanal(canaisMidi[i]); 
	  }          
	}
	
	public void close() 
	{ if (sintetizador != null) { sintetizador.close();}
	  sintetizador = null;
	  instrumentos = null;
	  canais       = null;
	}

}    //-----fim da classe MidiJS


public class TopGear   //----toca 5 notas
{
        MidiJS oM; 
        int    canal       = 0;
int i;	
        int    nota        = 48;   
        int    veloc       = 110;
        int    pan         = 64;
        int    banco       = 0;       
        int    instrumento = 0;    //---piano    


public TopGear()
{          
      oM   = new MidiJS();
      oM.reset(canal);
      oM.bank_select(banco, canal);
      oM.program_change(instrumento, canal);
      oM.pan(pan, canal);    


      retardo(250);   //---explicar 

      instrumento = 0;  //----flauta
      oM.program_change(instrumento, canal);
int a;
for(i=0;i<3;i++){
      //---------- MENOR
a=57;
nota = a;
      oM.note_on(nota, veloc, canal+1);
      retardo(1440	);
        oM.note_off(nota, 0, canal+1);


	nota = a;
      oM.note_on(nota, veloc, canal);
      retardo(90	);
        oM.note_off(nota, 0, canal);

      nota = a+3;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+7;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+12;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+15;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+19;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+24;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+27;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+31;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);




 nota = a+27;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+24;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+19;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
      nota = a+15;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
     nota = a+12;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
      nota = a+7;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
    nota = a+3;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
 nota = a;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);


//---------- MAIOR
a=60;
nota = a;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+4;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+7;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+12;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+16;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+19;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+24;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+28;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+31;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);



 nota = a+28;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+24;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+19;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
      nota = a+16;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
     nota = a+12;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
      nota = a+7;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
    nota = a+4;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
 nota = a;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
      //---------- MAIOR
a=55;
 nota = a;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+4;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+7;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+12;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+16;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+19;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+24;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+28;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+31;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);



 nota = a+28;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+24;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

      nota = a+19;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
      nota = a+24;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
     nota = a+28;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
      nota = a+31;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
    nota = a+28;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);


// ----- AM
a=57;
nota = a+31;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
 nota = a+27;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+24;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
 nota = a+19;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
 nota = a+24;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
nota = a+27;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
nota = a+31;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
 nota = a+27;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
nota = a+31;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
 nota = a+27;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

 nota = a+24;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
 nota = a+19;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
 nota = a+24;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
nota = a+27;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
nota = a+31;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);
 nota = a+27;
      oM.note_on(nota, veloc, canal);
      retardo(90);
      oM.note_off(nota, 0, canal);

}
     
     try { System.in.read();
           System.exit(0);
         }
     catch(Exception e){};     
}

public static void main(String args[]) 
{ new TopGear();
}

 static void retardo(int miliseg)
 {  
   try { Thread.sleep(miliseg);
       }
   catch(InterruptedException e) { }
 }

}



