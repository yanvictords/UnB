import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.sound.midi.*;
public class TocaMidi{      
private Sequencer  sequenciador;
private Sequence   sequencia;
	
	public static void main(String args[]){        
		new TocaMidi();    
	}

	public TocaMidi(){ 	 
		File arqmidi = new File("mvioloncelo1.mid");
		JFrame painel = new JFrame("tocamid");
		painel.setSize(300, 300);                    
		painel.setLayout(new GridLayout(10,0));
		painel.setVisible(true); 
		JButton pausa = new JButton("PAUSAR"); 
		JButton play = new JButton("PLAY"); 
		painel.add(pausa);
		painel.add(play);
		try{  
			sequencia = MidiSystem.getSequence(arqmidi);
			sequenciador = MidiSystem.getSequencer();
			sequenciador.setSequence(sequencia);
			sequenciador.open();             
                 		
			pausa.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){ 
				sequenciador.stop();  
                 	}
	                });	
			play.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){ 
				sequenciador.start();
                 	}
	                });	
		
			
		}
		catch(MidiUnavailableException e1) { System.out.println(e1+" : Dispositivo midi nao disponivel.");}
		catch(InvalidMidiDataException e2) { System.out.println(e2+" : Erro nos dados midi."); }
		catch(IOException              e3) { System.out.println(e3+" : O arquivo midi nao foi encontrado."); 
                                                     System.out.println("Sintaxe: "+"java TocaMidi arquivo.mid");
                 }
	}
}
