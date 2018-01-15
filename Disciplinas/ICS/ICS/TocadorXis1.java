/* GUILHERME ANDREUCE E YAN VICTOR - INTRODUCAO A COMPUTACAO SONICA - 2016/1 TRABALHO 1 */

import java.text.DecimalFormat;
import java.io.File;
import java.io.IOException;

import javax.swing.SwingUtilities;
import javax.swing.JFileChooser;
import javax.swing.JSlider;
import javax.swing.JProgressBar;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.ImageIcon;
import javax.swing.filechooser.FileFilter;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.UIManager;

import java.awt.Dimension;
import java.awt.Container;
import java.awt.Insets;
import java.awt.Font;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.sound.midi.MidiEvent;
import javax.sound.midi.MetaMessage;
import javax.sound.midi.MidiMessage;

import javax.sound.midi.Track;	
import javax.sound.midi.Sequence;
import javax.sound.midi.Sequencer;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.Receiver;
import javax.sound.midi.ShortMessage;
import javax.sound.midi.MidiUnavailableException;
import javax.sound.midi.InvalidMidiDataException;




public class TocadorXis extends JFrame implements Runnable
{                          
        private  int largura = 450;
        private  int altura  = 310;      
        private  int posx   = 430;
        private  int posy   = 270;
	ImageIcon logo      = null;
       
        private String diretorio = System.getProperty("user.dir");
        final JButton botaoABRIR             = constroiBotao("Abrir", 9);   
        final JButton botaoTOCAR             = constroiBotao("\u25b6", 9);  
        final JButton botaoFAZERPAUSA        = constroiBotao("\u25ae\u25ae", 9); 
        final JButton botaoPARAR             = constroiBotao("\u25fc", 9);  
        final JButton botaoMOSTRADORcaminho  = constroiBotao(" DIR: "+ diretorio, 9); 
        final JButton botaoMOSTRADORarquivo  = constroiBotao(" Arquivo: ", 9); 
        final JButton botaoMOSTRADORduracao  = constroiBotao(" Dura\u00e7\u00e3o: ", 9); 
        final JButton botaoMOSTRADORinstante = constroiBotao(" ", 9);  
        final JButton botaoMOSTRADORvalorvolume = constroiBotao(" ", 9);
	final JButton botaoDIMINUIinstante = constroiBotao("<", 9);
        final JButton botaoADICIONAinstante = constroiBotao(">", 9);
	final JButton botaoDIMINUIMAISinstante = constroiBotao("<<", 9);
        final JButton botaoADICIONAMAISinstante = constroiBotao(">>", 9);
	final JButton botaoFORMULAcompasso = constroiBotao("Compasso:", 9);
      	final JButton botaoMETRO = constroiBotao("Metronomo: ", 9);
      	final JButton botaoANDAMENTO = constroiBotao("Andamento: ", 9);
      	final JButton botaoARMADURAtonalidade = constroiBotao("Tonalidade: ", 9);
        final JButton botaoREDEFINEinstante = constroiBotao("Inicio", 9);
        final JButton botaoTRILHA = constroiBotao("Trilha", 9);
        final JButton botaoEVENTO = constroiBotao("Evento", 9);
        final JButton botaoMENSAGEM = constroiBotao("Mensagem", 9);
        final JButton botaoINSTANTE = constroiBotao("Instante", 9);
	final JButton botaoBPMAUMENTA = constroiBotao("+", 9);
        final JButton botaoBPMDIMINUI = constroiBotao("-", 9);
	final JButton botaoBPMAUMENTAMAIS = constroiBotao("++", 9);
        final JButton botaoBPMDIMINUIMAIS = constroiBotao("--", 9);
        
	
	private Sequencer  sequenciador = null;
	private Sequence   sequencia;
	private Receiver   receptor                = null;
	private long       inicio = 0; 
	private int k=0; //Variavel que e a posicao atual no sequenciador. Estara em constante atualizacao
	private int flag = 0;  //Variavel que define se a musica ira começar ou continuar de determinado ponto
  
        float durseminima;
        float bpm;
	private int          volumeATUAL             = 75;
	private JSlider      sliderVolume            = new JSlider(JSlider.HORIZONTAL,0, 127, volumeATUAL);        
	private JProgressBar sliderPROGRESSOinstante = new JProgressBar();    
	private Container painel = getContentPane(); 
	private boolean   soando = false;  

	public static void main(String[] args)
        {
          TocadorXis tocador = new TocadorXis();
          Thread     thread  = new Thread(tocador);
          thread.start();
	}

	

	public TocadorXis()
        {  
        	super("MIDHorse");  
        	personalizarInterfaceUsuario();     
        	ImageIcon logo   = new javax.swing.ImageIcon(getClass().getResource("cavalo.jpg")); //NOVO ICONE
        	setIconImage(logo.getImage());            
        	Color corOPR = new Color(180, 220, 220);
        	Color corARQ = new Color(216, 191, 216);
        	botaoABRIR.setBackground(corOPR);
        	botaoTOCAR.setBackground(corOPR);
        	botaoFAZERPAUSA.setBackground(corOPR);
        	botaoPARAR.setBackground(corOPR);
        	botaoABRIR.setEnabled(true);
        	botaoTOCAR.setEnabled(false);
        	botaoFAZERPAUSA.setEnabled(false);
        	botaoPARAR.setEnabled(false);
	        botaoREDEFINEinstante.setEnabled(false);
        	botaoADICIONAinstante.setEnabled(false);
		botaoADICIONAMAISinstante.setEnabled(false);
            	botaoDIMINUIinstante.setEnabled(false);
           	botaoDIMINUIMAISinstante.setEnabled(false); 
		botaoBPMAUMENTA.setEnabled(false);
		botaoBPMAUMENTAMAIS.setEnabled(false);
            	botaoBPMDIMINUI.setEnabled(false);
           	botaoBPMDIMINUIMAIS.setEnabled(false); 
            try{

                    JPanel p1 = new JPanel();
                    JPanel p2 = new JPanel();
                    JPanel p3 = new JPanel();
                    JPanel p4 = new JPanel();
                    JPanel p5 = new JPanel();
                    JPanel p6 = new JPanel();
                    JPanel p7 = new JPanel();
                    JPanel p8 = new JPanel();
                    JPanel p9 = new JPanel();
                    
                    JPanel painelOPERACOES = new JPanel();
	
                    painelOPERACOES.setLayout(new GridLayout(5,0));
                    painel.setLayout(new GridLayout(10,0));
                    
         
                    botaoABRIR.addActionListener(new ActionListener()
                    { public void actionPerformed(ActionEvent e)
                      { abrir();
                      }
                    });                    

                    botaoTOCAR.addActionListener(new ActionListener()
                    { public void actionPerformed(ActionEvent e)
                      { tocar(botaoMOSTRADORcaminho.getText(),k);
                      }
                    });

                    botaoFAZERPAUSA.addActionListener(new ActionListener()
                    { public void actionPerformed(ActionEvent e)
                      { inicio = sequenciador.getMicrosecondPosition();
                        k=fazerpausa();	//atualiza a posicao de k

                      }
                    });

                    botaoPARAR.addActionListener(new ActionListener()
                    { public void actionPerformed(ActionEvent e)
                      { parar();  
			        
                      }
                    });

			botaoADICIONAinstante.addActionListener(new ActionListener(){ 
				public void actionPerformed(ActionEvent e){
				k=adicionar(k, 0); //atualiza a posicao de k
			         
                      	}

                    	});

			botaoDIMINUIinstante.addActionListener(new ActionListener()
                    { public void actionPerformed(ActionEvent e)
                      {k=diminuir(k,0);  //atualiza a posicao de k
			     
                      }

                    });
			botaoADICIONAMAISinstante.addActionListener(new ActionListener(){ 
				public void actionPerformed(ActionEvent e){
				k=adicionar(k, 1); //atualiza a posicao de k
			         
                      	}

                    	});
			botaoDIMINUIMAISinstante.addActionListener(new ActionListener()
                    { public void actionPerformed(ActionEvent e)
                      {k=diminuir(k,1);  //atualiza a posicao de k
			     
                      }

                    });
			botaoBPMAUMENTA.addActionListener(new ActionListener(){ 
				public void actionPerformed(ActionEvent e){
				aumentabpm(0); //atualiza a posicao de k
			  }       
                      	});


			botaoBPMDIMINUI.addActionListener(new ActionListener()
                    { public void actionPerformed(ActionEvent e)
                      {diminuibpm(0);  //atualiza a posicao de k
			   }  
                      });

			botaoBPMAUMENTAMAIS.addActionListener(new ActionListener(){ 
				public void actionPerformed(ActionEvent e){
				aumentabpm(1); //atualiza a posicao de k
			         
                      }

                    	});
			botaoBPMDIMINUIMAIS.addActionListener(new ActionListener()
                    { public void actionPerformed(ActionEvent e)
                      {diminuibpm(1);  //atualiza a posicao de k
			  }   
                      });
			
		

			botaoREDEFINEinstante.addActionListener(new ActionListener()
                    { public void actionPerformed(ActionEvent e)
                      { k=redefinir();            //atualiza a posicao de k
                      }
                    });
			

		    JLabel vol = new JLabel("Volume: ");
                    sliderVolume.setPreferredSize(new Dimension(150,20));
                    sliderVolume.setFocusable(false);
                    
                    //-----   ADICIONANDO BOTOES
			
		    p1.add(botaoABRIR);
		    p1.add(botaoMOSTRADORcaminho);  
		    p2.add(botaoMOSTRADORarquivo);                                                               
                    painelOPERACOES.add(p3);                    
                    painelOPERACOES.add(p4); 
		    p2.add(botaoTOCAR);
        	    p2.add(botaoFAZERPAUSA);
        	    p2.add(botaoPARAR);     
		    p2.add(botaoMOSTRADORduracao);                        
        	    painelOPERACOES.add(p3);
		    p2.add(botaoBPMDIMINUIMAIS);
        	    p2.add(botaoBPMDIMINUI);
        	    p2.add(botaoBPMAUMENTA);     
		    p2.add(botaoBPMAUMENTAMAIS);

			
		    sliderPROGRESSOinstante.setPreferredSize(new Dimension(200,20));
        	    sliderPROGRESSOinstante.setFocusable(false);
        	    p4.add(botaoDIMINUIMAISinstante);
		    p4.add(botaoDIMINUIinstante);
        	    p4.add(botaoREDEFINEinstante);
        	    p4.add(botaoADICIONAinstante);
        	    p4.add(botaoADICIONAMAISinstante);
        	    p5.add(sliderPROGRESSOinstante);
        	    p5.add(botaoMOSTRADORinstante);
		    p6.add(vol); 
                    p6.add(sliderVolume);
                    p6.add(botaoMOSTRADORvalorvolume);
        	    p7.add(botaoFORMULAcompasso); 
        	    p7.add(botaoMETRO);
        	    p8.add(botaoTRILHA);
        	    p8.add(botaoEVENTO);
        	    p9.add(botaoMENSAGEM);
        	    p9.add(botaoINSTANTE);                 
        	    p9.add(botaoANDAMENTO);            
        	    p8.add(botaoARMADURAtonalidade);    


                    //-----  BACKGROUND              

        	    botaoTRILHA.setBackground(corARQ);
        	    botaoEVENTO.setBackground(corARQ);
        	    botaoMENSAGEM.setBackground(corARQ);
        	    botaoINSTANTE.setBackground(corARQ);
		    

		    botaoBPMAUMENTAMAIS.setBackground(corOPR);
		    botaoBPMAUMENTA.setBackground(corOPR);
		    botaoBPMDIMINUIMAIS.setBackground(corOPR);
		    botaoBPMDIMINUI.setBackground(corOPR);
        	    botaoMOSTRADORcaminho.setBackground(corOPR);
        	    botaoMOSTRADORarquivo.setBackground(corOPR);
        	    botaoMOSTRADORduracao.setBackground(corOPR);
        	    botaoMOSTRADORinstante.setBackground(corOPR);
        	    botaoADICIONAinstante.setBackground(corOPR);
		    botaoADICIONAMAISinstante.setBackground(corOPR);  	
	            botaoREDEFINEinstante.setBackground(corOPR);
            	    botaoDIMINUIinstante.setBackground(corOPR);
        	    botaoDIMINUIMAISinstante.setBackground(corOPR);
        	    botaoMOSTRADORvalorvolume.setBackground(corOPR);               
        	    botaoFORMULAcompasso.setBackground(corARQ);
		    botaoMETRO.setBackground(corARQ);
        	    botaoANDAMENTO.setBackground(corARQ);
        	    botaoARMADURAtonalidade.setBackground(corARQ);
                    


                    painel.add(painelOPERACOES);       
                    painel.add(p1);                                  
                    painel.add(p2);                     
                    painel.add(p3);                     
                    painel.add(p4);                     
                    painel.add(p5);                     
                    painel.add(p6);
                    painel.add(p7);
                    painel.add(p8);
                    painel.add(p9);                     
                    
                    botaoMOSTRADORvalorvolume.setText("" + (volumeATUAL*100)/127 + "%");
                                        
                    sliderVolume.addChangeListener(new ChangeListener()
                    {
                        public void stateChanged(ChangeEvent e)
                        {
                            JSlider source = (JSlider)e.getSource();
                            if(!source.getValueIsAdjusting())
                            {
                                int valor = (int)source.getValue();

                                ShortMessage mensagemDeVolume = new ShortMessage();
                                for(int i=0; i<16; i++)
                                {
                                    try { mensagemDeVolume.setMessage(ShortMessage.CONTROL_CHANGE, i, 7, valor);
                                          receptor.send(mensagemDeVolume, -1);
                                        }
                                    catch (InvalidMidiDataException e1) {}
                                }
                                volumeATUAL = valor;
                                botaoMOSTRADORvalorvolume.setText("" + (volumeATUAL*100)/127 + "%");
                            }
                        }
                    });

                    setSize(largura, altura);  
                    setLocation(posx,posy); 
                    setDefaultCloseOperation(EXIT_ON_CLOSE);                     
                    setVisible(true);  
                    this.setResizable(false);
            }
            catch(Exception e){
                    System.out.println(e.getMessage());
            }
                        
	}

//------------------------- PLAY

	public void tocar(String caminho, int k)
        {  

            try{
            if(flag == 0)  //flag=o para começar a musica
            {  
                File arqmidi = new File(caminho);
                sequencia    = MidiSystem.getSequence(arqmidi);  
                sequenciador = MidiSystem.getSequencer();  

                sequenciador.setSequence(sequencia); 
                sequenciador.open();  
                retardo(500);
                sequenciador.start();  
                
                receptor = sequenciador.getTransmitters().iterator().next().getReceiver();
                sequenciador.getTransmitter().setReceiver(receptor);
             
                botaoMOSTRADORarquivo.setText("Arquivo: \"" + arqmidi.getName() + "\"");
                                               
		long duracao  = sequencia.getMicrosecondLength()/1000000;
                botaoMOSTRADORduracao.setText("\nDura\u00e7\u00e3o:"+ formataInstante(duracao)); 
                botaoMOSTRADORinstante.setText(formataInstante(k));

		//MOSTRANDO EVENTOS, TRILHA, COMPASSO, TONALIDADE, METRO E INSTANTE
		
              	Track[] trilhas = sequencia.getTracks();
              	for(int i=0; i<trilhas.length; i++)
              {
                Track trilha =  trilhas[i];
		Par fc;
                String st  = "--";
                String stx = "--";

                 //---MetaMensagem de fórmula de compasso
                fc = getFormulaDeCompasso(trilha);{
               	if(i==0)
			botaoFORMULAcompasso.setText("Compasso:"+ fc.getX() + ":" + (int)(Math.pow(2, fc.getY())) );
                botaoMETRO.setText("Metro: 1/"+ (int)(Math.pow(2, fc.getY())) );
				}
                //---MetaMensagem de tonalidade
                if(i==0){
                try{ st =  getTonalidade(trilha);
                   }
                catch(Exception e){}
                botaoARMADURAtonalidade.setText("Tonalidade: "+ st);
                }
                //---MetaMensagem de texto
                try{ stx =  getTexto(trilha);
                   }
                catch(Exception e){}
                
            	 for(int j=0; j<trilha.size(); j++)
                {
                //botaoTRILHA.setText("Trilha nº: "+i);
                //botaoEVENTO.setText("Evento nº: "+j);
		  System.out.println("Trilha nº: "+i);
                  System.out.println("Evento nº: "+j);


                  MidiEvent   e          = trilha.get(j);
                  MidiMessage mensagem   = e.getMessage();
                  long        tique      = e.getTick();
                  
                  int n = mensagem.getStatus();
                  String nomecomando = ""+n;

                  switch(n)
                  {
                      case 128: nomecomando = "noteON"; break;
                      case 144: nomecomando = "noteOFF"; break;
                      case 255: nomecomando = "System_Reset"; break;
                      case 176: nomecomando = "Control_change"; break;
                      case 224: nomecomando = "Pitch_Bend"; break;
                      case 254: nomecomando = "Active_Sensing"; break;
                      case 208: nomecomando = "Channel_Pressure"; break;
                      case 251: nomecomando = "Continue"; break;
                      case 247: nomecomando = "End_Of_Exclusive"; break;
                      case 241: nomecomando = "Midi_Time_Code"; break;
                      case 160: nomecomando = "Poly_pressure"; break;
                      case 192: nomecomando = "Program_change"; break;
                      case 242: nomecomando = "Song_Position_Pointer"; break;
                      case 243: nomecomando = "Song_select"; break;
                      case 250: nomecomando = "Start"; break;
                      case 252: nomecomando = "Stop"; break;
                      case 248: nomecomando = "Timing_Clock"; break;
                      case 246: nomecomando = "Tune_Request"; break;
                      }
                      //  botaoMENSAGEM.setText("Mensagem: "+nomecomando);
                      // botaoINSTANTE.setText("Instante: "+tique);
			System.out.println("Mensagem: "+nomecomando);
                        System.out.println("Instante: "+tique);
                }


                int resolucao = sequencia.getResolution();
                long totaltiques = sequencia.getTickLength();
                durtique       = (float)duracao/totaltiques;
                durseminima    = durtique*resolucao;
                bpm            = 60/durseminima;
                botaoANDAMENTO.setText(+Math.round(bpm)+ " bpm");
                int   totalseminimas = (int)(duracao/durseminima);
                                                                
                                                
                sequenciador.setMicrosecondPosition(k);

                if (sequenciador.isRunning())
                { duracao = sequenciador.getMicrosecondLength();
                  soando = true;
	
                } 
                else { soando = false; 
                       sequenciador.stop();
                       flag = 0;  
                       sequenciador.close();
                       k = 0;
                       duracao = 0;
                     }            
                 botaoABRIR.setEnabled(false);
                 botaoTOCAR.setEnabled(false);
                 botaoFAZERPAUSA.setEnabled(true);
                 botaoPARAR.setEnabled(true);
           	 botaoREDEFINEinstante.setEnabled(false);
		 botaoADICIONAMAISinstante.setEnabled(false);
        	 botaoADICIONAinstante.setEnabled(false);
             	 botaoDIMINUIinstante.setEnabled(false);  
		 botaoDIMINUIMAISinstante.setEnabled(false); 
		 botaoBPMAUMENTA.setEnabled(false);
		 botaoBPMAUMENTAMAIS.setEnabled(false);
            	 botaoBPMDIMINUI.setEnabled(false);
           	 botaoBPMDIMINUIMAIS.setEnabled(false); 
                
            }
}			//flag=1 para continuar a musica
        else{
        	sequenciador.start();
        	botaoABRIR.setEnabled(false);
        	botaoTOCAR.setEnabled(false);
         	botaoFAZERPAUSA.setEnabled(true);
	        botaoPARAR.setEnabled(true);
           	botaoREDEFINEinstante.setEnabled(false);
        	botaoADICIONAinstante.setEnabled(false);
		botaoADICIONAMAISinstante.setEnabled(false);
        	botaoDIMINUIinstante.setEnabled(false);  
		botaoDIMINUIMAISinstante.setEnabled(false);
		botaoBPMAUMENTA.setEnabled(false);
		botaoBPMAUMENTAMAIS.setEnabled(false);
            	botaoBPMDIMINUI.setEnabled(false);
           	botaoBPMDIMINUIMAIS.setEnabled(false); 
		if (sequenciador.isRunning())
                { long duracao = sequenciador.getMicrosecondLength();
                  soando = true;
                } 
                else { soando = false; 
                       sequenciador.stop();
                       flag = 0;  
                       sequenciador.close();
                       k = 0;
                       long duracao = 0;
               }  

        }

        }
            catch(MidiUnavailableException e1) { System.out.println(e1+" : Dispositivo midi nao disponivel.");}
            catch(InvalidMidiDataException e2) { System.out.println(e2+" : Erro nos dados midi."); }
            catch(IOException              e3) { System.out.println(e3+" : O arquivo midi nao foi encontrado.");   }
            catch(Exception e){  System.out.println(e.toString());  }  
	}  
//------------------------- RETARDO
	void retardo(int miliseg)
	{  
            try { Thread.sleep(miliseg);
                }
            catch(InterruptedException e) { }
	}
        
//------------------------- PAUSA
	public int fazerpausa()
        {	
        	flag = 1;
        	soando = false;
	        sequenciador.stop();
        	long  posicao = sequenciador.getMicrosecondPosition();
                int   seg     = Math.round(posicao*0.000001f);
        	botaoABRIR.setEnabled(false);            
	        botaoTOCAR.setEnabled(true);
        	botaoFAZERPAUSA.setEnabled(false);
        	botaoPARAR.setEnabled(true);
        	botaoADICIONAinstante.setEnabled(true);
		botaoADICIONAMAISinstante.setEnabled(true);
		botaoDIMINUIMAISinstante.setEnabled(true);
	        botaoDIMINUIinstante.setEnabled(true);
    		botaoREDEFINEinstante.setEnabled(true);
		botaoBPMAUMENTA.setEnabled(true);
		botaoBPMAUMENTAMAIS.setEnabled(true);
            	botaoBPMDIMINUI.setEnabled(true);
           	botaoBPMDIMINUIMAIS.setEnabled(true); 
	return seg;
	}
//------------------------- Ponto de partida >
	public int adicionar(int x, int mais){
		long dur = sequenciador.getMicrosecondLength()/1000000;
		flag=1;
		int z;
		
		if(mais==1){
			z = (int) (x+(dur/8));	// Calculo da posição, em seg, após um clique em >
		}else{
			z = (int) (x+(dur/dur));	// Calculo da posição, em seg, após um clique em >
		}
		if(z>=(int)dur){	//Se 'z' for maior que a duraçao da musica
			z=(int)dur;	// Entao 'z' = o tempo final da musica ~ Limite superior
			flag=0;
			botaoADICIONAinstante.setEnabled(false);
			botaoADICIONAMAISinstante.setEnabled(false);
		}
		int y = (int) (z*100/dur);	// Calculo da posicao do progresso ~ barra de progresso
		botaoABRIR.setEnabled(true);            
	        botaoTOCAR.setEnabled(true);
        	botaoFAZERPAUSA.setEnabled(false);
        	botaoPARAR.setEnabled(false);
		if(flag!=0){
        		botaoADICIONAinstante.setEnabled(true);
			botaoADICIONAMAISinstante.setEnabled(true);
		}
	        botaoDIMINUIinstante.setEnabled(true);
		botaoDIMINUIMAISinstante.setEnabled(true);
		botaoREDEFINEinstante.setEnabled(true);	
		botaoBPMAUMENTA.setEnabled(true);
		botaoBPMAUMENTAMAIS.setEnabled(true);
            	botaoBPMDIMINUI.setEnabled(true);
           	botaoBPMDIMINUIMAIS.setEnabled(true); 
		sliderPROGRESSOinstante.setValue(y);             
	        botaoMOSTRADORinstante.setText(formataInstante(z));
	        long  posicao = sequenciador.getMicrosecondPosition();	// Encontrando a posicao atual no sequenciador
        	int seg = Math.round(posicao*0.000001f);      
		long sec = (long)(z)*1000000;
		sequenciador.setMicrosecondPosition(sec);	// Atualizando a posicao atual para o proximo sequenciador.start();


	return z;
	}


//------------------------- Ponto de partida <
	public int diminuir(int x, int menos){
		long	dur   = sequenciador.getMicrosecondLength()/1000000;	
		flag=1;
		int z;
		if(menos==1){
			z = (int) (x-(dur/8));	// Calculo da posição, em seg, após um clique em <
		}else{
			z = (int) (x-(dur/dur));	// Calculo da posição, em seg, após um clique em <
		}
       		int y = (int) ((z*100)/dur); 	// Calculo da posicao do progresso ~ barra de progresso
		if(z<=0){	//Se 'z' for menor ou igual ao inicio da musica
			z=0;	//Então 'z' sera igual ao incio da musica ~ limite inferior
			flag=0;
			botaoDIMINUIinstante.setEnabled(false);
			botaoDIMINUIMAISinstante.setEnabled(false);
			botaoREDEFINEinstante.setEnabled(false);
		}
		botaoABRIR.setEnabled(true);            
        	botaoTOCAR.setEnabled(true);
        	botaoFAZERPAUSA.setEnabled(false);
        	botaoPARAR.setEnabled(false);
        	botaoADICIONAinstante.setEnabled(true);
		botaoADICIONAMAISinstante.setEnabled(true);
		botaoBPMAUMENTA.setEnabled(true);
		botaoBPMAUMENTAMAIS.setEnabled(true);
            	botaoBPMDIMINUI.setEnabled(true);
           	botaoBPMDIMINUIMAIS.setEnabled(true); 
		if(flag!=0){
		        botaoDIMINUIinstante.setEnabled(true);
			botaoDIMINUIMAISinstante.setEnabled(true);	
		}
		sliderPROGRESSOinstante.setValue(y);             
        	botaoMOSTRADORinstante.setText(formataInstante(z)); 
		long  posicao = sequenciador.getMicrosecondPosition(); // Encontrando a posicao atual no sequenciador
	        int   seg     = Math.round(posicao*0.000001f);      
		long sec = (long) z*1000000;
		sequenciador.setMicrosecondPosition(sec);	// Atualizando a posicao atual para o proximo sequenciador.start();

	return z;
	}

//------------------------- AUMENTA BPM
	public float aumentabpm(int mais){
		float bpm2;
		if(flag==1){
			bpm2 = bpm+50;
		}else{
			bpm2 = bpm+10;
		}
		bpm = bpm2;
		sequenciador.setTempoInBPM(bpm);
	return bpm;
	}

//------------------------- DIMINUI BPM
	public float diminuibpm(int mais){
                bpm            = 60/durseminima;
		float bpm2;
		if(flag==1){
			bpm2 = bpm-50;
		}else{
			bpm2 = bpm-10;
		}
		bpm = bpm2;
		sequenciador.setTempoInBPM(bpm);
	return bpm;
	}


//------------------------- Redefinir
	public int redefinir(){
		flag=0;
		k=0;
		botaoABRIR.setEnabled(true);            
      		botaoTOCAR.setEnabled(true);
      		botaoFAZERPAUSA.setEnabled(false);
        	botaoPARAR.setEnabled(false);
        	botaoADICIONAinstante.setEnabled(true);
        	botaoDIMINUIinstante.setEnabled(false);
		botaoREDEFINEinstante.setEnabled(false);
		botaoADICIONAMAISinstante.setEnabled(true);
		botaoDIMINUIMAISinstante.setEnabled(false);
		botaoBPMAUMENTA.setEnabled(true);
		botaoBPMAUMENTAMAIS.setEnabled(true);
            	botaoBPMDIMINUI.setEnabled(true);
           	botaoBPMDIMINUIMAIS.setEnabled(true); 
		sliderPROGRESSOinstante.setValue(0);             
        	botaoMOSTRADORinstante.setText(formataInstante(0));

	return k;
	}
//------------------------- PARAR
	public void parar()
        {
        	flag = 0;
	        soando = false;
        	sequenciador.stop();  
        	k = 0;
        	sequenciador.setMicrosecondPosition(0);
        	botaoABRIR.setEnabled(true);            
        	botaoTOCAR.setEnabled(true);
        	botaoFAZERPAUSA.setEnabled(false);
        	botaoPARAR.setEnabled(false);
        	botaoADICIONAinstante.setEnabled(true);
	        botaoDIMINUIinstante.setEnabled(false);
        	botaoREDEFINEinstante.setEnabled(false);
		botaoADICIONAMAISinstante.setEnabled(true);
		botaoDIMINUIMAISinstante.setEnabled(false);
		botaoBPMAUMENTA.setEnabled(true);
		botaoBPMAUMENTAMAIS.setEnabled(true);
            	botaoBPMDIMINUI.setEnabled(true);
           	botaoBPMDIMINUIMAIS.setEnabled(true); 
		sliderPROGRESSOinstante.setValue(0);             
	        botaoMOSTRADORinstante.setText(formataInstante(0));   
	}
//------------------------- ABRIR ARQUIVO MIDI
	public void abrir() 
        {  
           	JFileChooser selecao = new JFileChooser(".");  
	        selecao.setFileSelectionMode(JFileChooser.FILES_ONLY);              
        	selecao.setFileFilter(new FileFilter(){
                public boolean accept(File f)
                {
                    if (!f.isFile()) return true;
                    String name = f.getName().toLowerCase();
                    if (name.endsWith(".mid"))  return true;
                    if (name.endsWith(".midi")) return true;
                    return false;
                }
                public String getDescription()
                { return "Arquivo Midi (*.mid,*.midi)";
                }
            });
            selecao.showOpenDialog(this);              
            botaoMOSTRADORcaminho.setText(selecao.getSelectedFile().toString());  
            File arqseqnovo = selecao.getSelectedFile();
            try { 
                  if(sequenciador!=null && sequenciador.isRunning()) { sequenciador.stop();
                                                                       sequenciador.close();
                                                                       sequenciador = null;
                                                                     }
                  Sequence sequencianova = MidiSystem.getSequence(arqseqnovo);           
                  double duracao = sequencianova.getMicrosecondLength()/1000000.0d;
                 
                  botaoMOSTRADORarquivo.setText("Arquivo: \"" + arqseqnovo.getName() + "\"");                
                  botaoMOSTRADORduracao.setText("\nDura\u00e7\u00e3o:"+ formataInstante(duracao));                   
                  
                  botaoTOCAR.setEnabled(true);
                  botaoFAZERPAUSA.setEnabled(false);
                  botaoPARAR.setEnabled(false);

                }
		
            catch (Throwable e1) { System.out.println("Erro em carregaArquivoMidi: "+ e1.toString());
                                 }      
		                  
	} 

//------------------------- RUN
	public void run()
        { 
            double dur;
            double t;
            int    pos =0;
            
            while(true) 
            {                      
                if (soando)
                { dur   = sequenciador.getMicrosecondLength()/1000000;
                  t     = sequenciador.getMicrosecondPosition()/1000000;
                  pos   = (int) ((t*100)/dur);
                  try {  		
                        sliderPROGRESSOinstante.setValue(pos);								
                        botaoMOSTRADORinstante.setText(formataInstante(t));     
                        retardo(1000);
                        if(t>=dur) {  sliderPROGRESSOinstante.setValue(0);								
                                      botaoMOSTRADORinstante.setText(formataInstante(0));   
                                      
                                      botaoABRIR.setEnabled(true);
                                      botaoTOCAR.setEnabled(false);
                                      botaoFAZERPAUSA.setEnabled(false);
                                      botaoPARAR.setEnabled(false); 
				      parar();                       
                                   }
                      }
                  catch(Exception e) { System.out.println(e.getMessage());  
                                     }  
                }  
                
                else{ try{ retardo(1000);                                          
                         }
                      catch(Exception e) { System.out.println(e.getMessage());  
                                         }
                     }                                       
            }
            
     
	}        

        
      public String formataInstante(double t1)
      {
        String inicio    = "";

        //--------início
        double h1  = (int)(t1/3600.0);
        double m1  = (int)((t1 - 3600*h1)/60);
        double s1  = (t1 - (3600*h1 +60*m1));


        double h1r  = t1/3600.0;
        double m1r  = (t1 - 3600*h1)/60.0f;
        double s1r  = (t1 - (3600*h1 +60*m1));

        String sh1="";
        String sm1="";
        String ss1="";

        if     (h1 ==0) sh1 = "00";
        else if(h1 <10) sh1 = "0"+reformata(h1, 0);
        else if(h1<100) sh1 = "" +reformata(h1, 0);
        else            sh1 = "" +reformata(h1, 0);

        if     (m1 ==0) sm1 = "00";
        else if(m1 <10) sm1= "0"+reformata(m1, 0);
        else if(m1 <60) sm1 = ""+reformata(m1, 0);

        if     (s1 ==0) ss1 = "00";
        else if(s1 <10) ss1 = "0"+reformata(s1r, 2);
        else if(s1 <60) ss1 = reformata(s1r, 2);

        return inicio = "\n" + "   "+sh1+"h "+       sm1+"m "+    ss1+"s";
      }
       
      
      public String reformata(double x, int casas)
      { DecimalFormat df = new DecimalFormat() ;
        df.setGroupingUsed(false);
        df.setMaximumFractionDigits(casas);
        return df.format(x);
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

    static final int FORMULA_DE_COMPASSO = 0x58;
    
    static Par getFormulaDeCompasso(Track trilha)
    {   int p=1;
        int q=1;

        for(int i=0; i<trilha.size(); i++)
        {
          MidiMessage m = trilha.get(i).getMessage();
          if(m instanceof MetaMessage) 
          {
            if(((MetaMessage)m).getType()==FORMULA_DE_COMPASSO)
            {
                MetaMessage mm = (MetaMessage)m;
                byte[] data = mm.getData();
                p = data[0];
                q = data[1];
                return new Par(p,q);
            }
          }
        }
        return new Par(p,q);
    }          
    
    
    
    static private class Par
    { int x, y;
      
      Par (int x_, int y_)  
      { this.x = x_;
        this.y = y_;          
      }
    
      int getX()
      { return x;
      }
      
      int getY()
      { return y;
      }
    
    }
    
    
    
    static final int MENSAGEM_TONALIDADE = 0x59;  
    
    static String getTonalidade(Track trilha) throws InvalidMidiDataException
    {       
       String stonalidade = "";
       for(int i=0; i<trilha.size(); i++)
       { MidiMessage m = trilha.get(i).getMessage();
       
              
       if(((MetaMessage)m).getType() == MENSAGEM_TONALIDADE)    
       {
            MetaMessage mm        = (MetaMessage)m;
            byte[]     data       = mm.getData();
            byte       tonalidade = data[0];
            byte       maior      = data[1];

            String       smaior = "Maior";
            if(maior==1) smaior = "Menor";

            if(smaior.equalsIgnoreCase("Maior"))
            {
                switch (tonalidade)
                {
                    case -7: stonalidade = "Dób Maior"; break;
                    case -6: stonalidade = "Solb Maior"; break;
                    case -5: stonalidade = "Réb Maior"; break;
                    case -4: stonalidade = "Láb Maior"; break;
                    case -3: stonalidade = "Mib Maior"; break;
                    case -2: stonalidade = "Sib Maior"; break;
                    case -1: stonalidade = "Fá Maior"; break;
                    case  0: stonalidade = "Dó Maior"; break;
                    case  1: stonalidade = "Sol Maior"; break;
                    case  2: stonalidade = "Ré Maior"; break;
                    case  3: stonalidade = "Lá Maior"; break;
                    case  4: stonalidade = "Mi Maior"; break;
                    case  5: stonalidade = "Si Maior"; break;
                    case  6: stonalidade = "Fá# Maior"; break;
                    case  7: stonalidade = "Dó# Maior"; break;
                }
            }

            else if(smaior.equalsIgnoreCase("Menor"))
            {
                switch (tonalidade)
                {
                    case -7: stonalidade = "Láb Menor"; break;
                    case -6: stonalidade = "Mib Menor"; break;
                    case -5: stonalidade = "Sib Menor"; break;
                    case -4: stonalidade = "Fá Menor"; break;
                    case -3: stonalidade = "Dó Menor"; break;
                    case -2: stonalidade = "Sol Menor"; break;
                    case -1: stonalidade = "Ré Menor"; break;
                    case  0: stonalidade = "Lá Menor"; break;
                    case  1: stonalidade = "Mi Menor"; break;
                    case  2: stonalidade = "Si Menor"; break;
                    case  3: stonalidade = "Fá# Menor"; break;
                    case  4: stonalidade = "Dó# Menor"; break;
                    case  5: stonalidade = "Sol# Menor"; break;
                    case  6: stonalidade = "Ré# Menor"; break;
                    case  7: stonalidade = "Lá# Menor"; break;
                }
            }
         }
      }
      return stonalidade;
    }
          



    static final int MENSAGEM_TEXTO = 0x01;  
    
    static String getTexto(Track trilha) throws InvalidMidiDataException
    {       
       String stexto = "";

       for(int i=0; i<trilha.size(); i++)
       { MidiMessage m = trilha.get(i).getMessage();
              
         if(((MetaMessage)m).getType() == MENSAGEM_TEXTO)    
         {                
           MetaMessage mm  = (MetaMessage)m;
           byte[]     data = mm.getData();

           for(int j=0; j<data.length; j++)
           { stexto += (char)data[j];
           }         
        }       
     }    
     return stexto;
    }
        
        
    //---procedimento para customizar a interface GUI
    private void personalizarInterfaceUsuario()
    {
            UIManager.put("FileChooser.openDialogTitleText", "Abrir arquivo midi");
            UIManager.put("FileChooser.lookInLabelText", "Buscar em");
            UIManager.put("FileChooser.openButtonText", "Abrir");
            UIManager.put("FileChooser.cancelButtonText", "Cancelar");
            UIManager.put("FileChooser.fileNameLabelText", "Nome do arquivo");
            UIManager.put("FileChooser.filesOfTypeLabelText", "Tipo");
            UIManager.put("FileChooser.openButtonToolTipText", "Abrir o arquivo selecionado");
            UIManager.put("FileChooser.cancelButtonToolTipText","Cancelar");
            UIManager.put("FileChooser.fileNameHeaderText","Nome");
            UIManager.put("FileChooser.upFolderToolTipText", "Subir um nível");
            UIManager.put("FileChooser.homeFolderToolTipText","Nível home");
            UIManager.put("FileChooser.newFolderToolTipText","Criar pasta");
            UIManager.put("FileChooser.listViewButtonToolTipText","Em lista");
            UIManager.put("FileChooser.newFolderButtonText","Criar pasta");
            UIManager.put("FileChooser.renameFileButtonText", "Mudar o nome");
            UIManager.put("FileChooser.deleteFileButtonText", "Deletar");
            UIManager.put("FileChooser.filterLabelText", "Extensão de arquivo");
            UIManager.put("FileChooser.detailsViewButtonToolTipText", "Com detalhes");
            UIManager.put("FileChooser.fileSizeHeaderText","Tamanho");
            UIManager.put("FileChooser.fileDateHeaderText", "Data de modificação");
            UIManager.put("FileChooser.acceptAllFileFilterText", "Binário");

            UIManager.put("FileChooser.saveButtonText", "Salvar");
            UIManager.put("FileChooser.saveDialogTitleText", "Salvar em");
            UIManager.put("FileChooser.saveInLabelText", "Salvar em");
            UIManager.put("FileChooser.saveButtonToolTipText", "Salvar arquivo selecionado");

            UIManager.put("OptionPane.yesButtonText",    "Sim");
            UIManager.put("OptionPane.noButtonText",     "Não");
            UIManager.put("OptionPane.cancelButtonText", "Cancelar");

            UIManager.put("FileChooser.listFont", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("FileChooser.fileNameLabelText", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("FileChooser.filesOfTypeLabelText", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));

            UIManager.put("JSlider.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("JSlider.listFont", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("JSlider", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("JFileChooser.listFont", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("JFileChooser.fileNameLabelText", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("JFileChooser.filesOfTypeLabelText", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("JButton", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));

            UIManager.put("OptionPane.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("Button.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("RadioButton.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 10)));

            UIManager.put("Label.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("JLabel.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("JLabel", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            
            
            UIManager.put("ComboBox.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("ToolTip.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 10)));
            UIManager.put("EditorPane.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("List.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("Panel.listFont", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("Panel.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("Table.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 10)));
            UIManager.put("TextArea.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 10)));
            UIManager.put("TextField.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 10)));
            UIManager.put("TextPane.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 10)));
            UIManager.put("JTextArea.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 10)));
            UIManager.put("JTextField.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 10)));
            UIManager.put("JTextPane.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 10)));
            UIManager.put("InternalFrame.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("InternalFrame.titleFont",new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("Frame.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("Frame.titleFont",new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));
            UIManager.put("ScrollPane.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 11)));

            UIManager.put("ProgressBar.font", new javax.swing.plaf.FontUIResource(new Font("Arial", java.awt.Font.PLAIN, 10)));
        }
        
                
 
 
}

//-----18/05/2013 (ICS 2013/1)

