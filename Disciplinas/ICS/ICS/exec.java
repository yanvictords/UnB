import java.text.DecimalFormat;
import java.io.File;
import java.io.IOException;
import javax.swing.*;
import javax.swing.filechooser.FileFilter;
import javax.swing.event.*;
import javax.swing.border.EtchedBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.sound.midi.*;
import sintese.*;


public class exec extends JFrame{  
	private  int largura = 500;
        private  int altura  = 400;      
        private  int posx   = 430;
        private  int posy   = 270;

	

	 public static void main(String args[]){
   		new exec();
  	 }
	public exec(){
		ImageIcon logo   = new javax.swing.ImageIcon(getClass().getResource("cavalo.jpg")); //NOVO ICONE
        	setIconImage(logo.getImage());
		 
		JButton InstrA = constroiBotao("AM Band-pass noise", 13);
		JButton InstrB = constroiBotao("FM Band-pass noise", 13);
		JButton InstrC = constroiBotao("Periodic plus rand vibrato", 13);
		JButton InstrA1 = constroiBotao("Melodia 1", 13);
		JButton InstrB1 = constroiBotao("Melodia 1", 13);
		JButton InstrC1 = constroiBotao("Melodia 1", 13);
		JButton InstrA2 = constroiBotao("Melodia 2", 13);
		JButton InstrB2 = constroiBotao("Melodia 2", 13);
		JButton InstrC2 = constroiBotao("Melodia 2", 13);
		JButton InstrA3 = constroiBotao("Melodia 3", 13);
		JButton InstrB3 = constroiBotao("Melodia 3", 13);
		JButton InstrC3 = constroiBotao("Melodia 3", 13);
		Container painel = getContentPane();
   	        JLabel Titulo = new JLabel("Instrumentos A B C",JLabel.CENTER);
		Titulo.setForeground(new Color(222 ,184 ,135));
		Titulo.setFont(new Font("broadway",Font.BOLD,17));
		Titulo.setBounds(20,20,300,20);
		painel.add(Titulo);
		JLabel SubTitulo = new JLabel("Computação Sônica 2016/1",JLabel.CENTER);

		SubTitulo.setForeground(new Color( 	222 ,184 ,135  ));

		SubTitulo.setFont(new Font("broadway",Font.BOLD,18));

		SubTitulo.setBounds(180,70,500,20); painel.add(SubTitulo);
		Color corOPR = new Color(100, 160, 10);
	        Color corARQ = new Color( 255, 250, 240   );
        	InstrA.setBackground(corARQ);
        	InstrB.setBackground(corARQ);
        	InstrC.setBackground(corARQ);
        	InstrA1.setBackground(corOPR);
        	InstrB1.setBackground(corOPR);
        	InstrC1.setBackground(corOPR);
        	InstrA2.setBackground(corOPR);
        	InstrB2.setBackground(corOPR);
        	InstrC2.setBackground(corOPR);
        	InstrA3.setBackground(corOPR);
        	InstrB3.setBackground(corOPR);
        	InstrC3.setBackground(corOPR);
		InstrA.setEnabled(true);
		InstrB.setEnabled(true);
		InstrC.setEnabled(true);
		InstrA1.setEnabled(true);
		InstrB1.setEnabled(true);
		InstrC1.setEnabled(true);
		InstrA2.setEnabled(true);
		InstrB2.setEnabled(true);
		InstrC2.setEnabled(true);
		InstrA3.setEnabled(true);
		InstrB3.setEnabled(true);
		InstrC3.setEnabled(true);
		try{
 			
			JPanel p1 = new JPanel();
			JPanel p2 = new JPanel();
			JPanel p3 = new JPanel();		
	 	     painel.setLayout(new GridLayout(10,5));
		
			InstrA1.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					Runtime run = Runtime.getRuntime();
					try {
						String command = "javac testei2A1.java";
        	   				run.exec(command);
        	   				command = "java testei2A1";
        	   				run.exec(command);
	        			}catch(IOException a) {	
        	   				a.printStackTrace();
       				 	}	
        	         	}
        	        });  
			InstrB1.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					Runtime run = Runtime.getRuntime();
					try {
						String command = "javac testei2B1.java";
        	   				run.exec(command);
        	   				command = "java testei2B1";
        	   				run.exec(command);
	        			}catch(IOException a) {	
        	   				a.printStackTrace();
       				 	}
        	         	}
        	        });  
			InstrC1.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					Runtime run = Runtime.getRuntime();
					try {
						String command = "javac testei2C1.java";
        	   				run.exec(command);
        	   				command = "java testei2C1";
        	   				run.exec(command);
	        			}catch(IOException a) {	
        	   				a.printStackTrace();
       				 	}
        	         	}
        	        });  	


			InstrA2.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					Runtime run = Runtime.getRuntime();
					try {
						String command = "javac testei2A2.java";
        	   				run.exec(command);
        	   				command = "java testei2A2";
        	   				run.exec(command);
	        			}catch(IOException a) {	
        	   				a.printStackTrace();
       				 	}	
        	         	}
        	        });  
			InstrB2.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					Runtime run = Runtime.getRuntime();
					try {
						String command = "javac testei2B2.java";
        	   				run.exec(command);
        	   				command = "java testei2B2";
        	   				run.exec(command);
	        			}catch(IOException a) {	
        	   				a.printStackTrace();
       				 	}
        	         	}
        	        });  
			InstrC2.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					Runtime run = Runtime.getRuntime();
					try {
						String command = "javac testei2C2.java";
        	   				run.exec(command);
        	   				command = "java testei2C2";
        	   				run.exec(command);
	        			}catch(IOException a) {	
        	   				a.printStackTrace();
       				 	}
        	         	}
        	        }); 


			InstrA3.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					Runtime run = Runtime.getRuntime();
					try {
						String command = "javac testei2A3.java";
        	   				run.exec(command);
        	   				command = "java testei2A3";
        	   				run.exec(command);
	        			}catch(IOException a) {	
        	   				a.printStackTrace();
       				 	}	
        	         	}
        	        });  
			InstrB3.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					Runtime run = Runtime.getRuntime();
					try {
						String command = "javac testei2B3.java";
        	   				run.exec(command);
        	   				command = "java testei2B3";
        	   				run.exec(command);
	        			}catch(IOException a) {	
        	   				a.printStackTrace();
       				 	}
        	         	}
        	        });  
			InstrC3.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					Runtime run = Runtime.getRuntime();
					try {
						String command = "javac testei2C3.java";
        	   				run.exec(command);
        	   				command = "java testei2C3";
        	   				run.exec(command);
	        			}catch(IOException a) {	
        	   				a.printStackTrace();
       				 	}
        	         	}
        	        }); 
			p1.add(InstrA);
			p2.add(InstrB);
			p3.add(InstrC);
			
			p1.add(InstrA1);
			p2.add(InstrB1);
			p3.add(InstrC1);
			
			p1.add(InstrA2);
			p2.add(InstrB2);
			p3.add(InstrC2);
			
			p1.add(InstrA3);
			p2.add(InstrB3);
			p3.add(InstrC3);
			             

	                painel.add(p1);                     
        	        painel.add(p2);                     
	                painel.add(p3);                     

			setSize(largura, altura);
                    	setLocation(posx,posy); 
	              	setDefaultCloseOperation(EXIT_ON_CLOSE);                     
        	      	setVisible(true);
                	
            }
        	catch(Exception e){
                    System.out.println(e.getMessage());
            	}
	}
	
	
	public JButton constroiBotao(String legenda)
        {
            JButton botao = new JButton(legenda);
            botao.setMargin(new Insets(2, 2, 2, 2));
            botao.setFocusable(false);
            botao.setFont(botao.getFont().deriveFont(Font.PLAIN));
            return botao;
	}
        
	public JButton constroiBotao(String legenda, float tamanhoFonte)
        {
            JButton botao = new JButton(legenda);
            botao.setMargin(new Insets(2, 2, 2, 2));
            botao.setFocusable(false);
            botao.setFont(botao.getFont().deriveFont(Font.PLAIN));
            botao.setFont(botao.getFont().deriveFont(tamanhoFonte));
            return botao;
	}
	
}
