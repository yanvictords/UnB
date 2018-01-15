
//------------------------- METAMENSAGENS: MOSTRANDO EVENTOS, TRILHA, COMPASSO, TONALIDADE, METRO E INSTANTE.
public void metamensagens(){
    int y = 0;
    JFrame.setDefaultLookAndFeelDecorated(true);
    JFrame frame = new JFrame("**MetaMensagens**");
    frame.setSize(300, 300);
    Track[] trilhas = sequencia.getTracks();
    JTextArea textArea = new JTextArea(5, 20);
    JPanel painel = new JPanel();
    textArea.setEditable(false);
    textArea.setFont(new Font("Serif", Font.ITALIC, 16));
    textArea.setLineWrap(true);
    textArea.setWrapStyleWord(true);
    textArea.setVisible(true);
    JScrollPane scrollPane = new JScrollPane(textArea, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS); 
    scrollPane.setBounds(5,5,300,300);
    frame.add(scrollPane);
    frame.setLocationRelativeTo(null);
    frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    frame.setVisible(true);
//-------------------------------------------------------------------------------------------------
    for(int i=0; i<trilhas.length; i++){
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
            try{ 
                st =  getTonalidade(trilha);
            }
            catch(Exception e){
            }
            botaoARMADURAtonalidade.setText("Tonalidade: "+ st);
        }
//---MetaMensagem de texto
        try{ 
            stx =  getTexto(trilha);
        }
        catch(Exception e){
        }

        for(int j=0; j<trilha.size(); j++){
            MidiEvent   e          = trilha.get(j);
            MidiMessage mensagem   = e.getMessage();
            long        tique      = e.getTick();
            int n = mensagem.getStatus();
            String nomecomando = ""+n;
            
            switch(n){

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
            textArea.setLocation(0,y);    
            textArea.append("Trilha nº: "+i+" ||Evento nº: "+j+" ||Mensagem: "+nomecomando+" ||Instante: "+tique + "\n");
            y+=1;
        }
    }   
}
