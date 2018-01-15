#include "CaMaterial.h"




int CaMaterial::getEscalaNat( void )/*Compara o material com a escala natural                                //mais plausível que ele possa pertencer.
                              //Caso haja mais de uma com o igualmente
                                //aceitável, uma será escolhida.
                                //Retorna um inteiro entre 0 a 24.
                                //Sendo as escalas maiores entre 1 a 12.
                                //As menores entre 13 e 24.
                                //1 é para DóMaior, 2 é para RéBemol Maior.
                                //3 é Ré Maior e 13 é para Dó Menor, etc.
								//0 é atonal. */
{
    int* notas;
    int dif[24], escala[24][7];
    int tam, ini, menordif =  0; 
    MuNote nota_aux;

    tam      = this->NumberOfNotes(); //Salva o número de notas do material.
    notas    = new int[tam];

    for(int i = 0; i < 23; i++)
        dif[i]  = 0; //Troca todos os valores de dif por 0;

   	//Laços de geração das Escalas Naturais.
    for(int j = 0; j < 12; j ++) //Gera as escalas maiores 
    						//com intervalos TTsTTTs;
    {
        ini = j;
        for(int i = 0; i < 3; i ++)
        {
            escala[j][i] = (ini+2*i)%12;
        }


        for(int i = 0; i < 4; i ++)
        {
            escala[j][i+3] = (ini+5+2*i)%12;
        }
    }

    for(int j = 12; j < 24; j ++) //Gera as escalas menores
    							//com intervalos TsTTsTTs
    {
        ini          = j-12;
        escala[j][0] = ini%12;
        escala[j][1] = (ini+2)%12;
        escala[j][2] = (ini+3)%12;

        for(int i = 0; i<2; i ++)
        {
            escala[j][i+3] = (ini+5+2*i)%12;
        }

        escala[j][5] = (ini+8)%12;
        escala[j][6] = (ini+10)%12;
    }


    //Armazena-se a altura de cada nota do material.
    for(int i = 0; i < tam; i++){
        nota_aux = this->GetNote(i);
        notas[i] = (nota_aux.Pitch())%12; //Quer-se comparar com as escalas 
                                            //Independentemente da oitava.
    }

    //Aqui será feito a comparação entre as notas do material e da
    //as escalas naturais.
    for(int k = 0; k < 24; k++) //Laço que passa de escala em escala.
    {
        for( int j = 0; j < tam; j++) //Cada altura de nota do material.
        {
            for( int i = 0; i < 7; i++) //Cada altura de nota da escala.
            {
             if(notas[j] != escala[k][i]) dif[k]++; //Se a nota não for igual
                                                    //o grau de diferença
                                                    //entre a escala possível
                                                    //e a escala real aumenta.
            }
            dif[k] -= 6; //Fica 0, se há a nota na escala e 1 se não há.
        }
        if(dif[menordif] > dif[k]) menordif = k; //Salva a escala com menor
	                               		       //diferença com a real.
    }

    delete[] notas;


    if(dif[menordif] != 0) return 0;//Não encaixou em nenhuma escala natural 
    								//então é atonal.

    return menordif+1;
}


int* CaMaterial::getVetorGraus(int tom) /*Função que recebe o tom e retorna um vetor com 24 elementos
                            em que os índices são relacionados aos graus que esses elementos tem na escala. A relação matemática é de
                            índice + 1 = grau + 7*Oitava. Sendo a oitava o número de oitavas acima do Dó 2 que a nota se encontra.*/
{
    int ini;
    int escala[7];
    int* vetor;


    if(tom > 24 || tom < 1) exit(2); //Número inválido.

    //Laços para criação das escalas sem se preocupar com oitavas.
    if(tom < 13)//Escala Maior TTsTTTs
    {
        ini = tom - 1;
        for(int i = 0; i < 3; i ++)
        {
            escala[i] = (ini)%12 + i*2;
        }


        for(int i = 0; i < 4; i ++)
        {
            escala[i+3] = (ini)%12 + 5 + i*2 ;
        }
    } else //Escala Menor TsTTsTT
    {
        ini       = tom-1;
        escala[0] = ini%12;
        escala[1] = (ini)%12 + 2;
        escala[2] = (ini)%12 + 3;

        for(int i = 0; i<2; i ++)
        {
            escala[i+3] = (ini)%12 + 5 + i*2;
        }

        escala[5] = (ini)%12 + 8;
        escala[6] = (ini)%12 + 10;
    }


    vetor = new int[TAMANHO_ESCALA]; //Aloca dinamicamente um vetor que será retornado ao fim da função.
    ini = INICIO;


    for(int i = 0; i < TAMANHO_ESCALA; i++)
    {   
        if(i != 0 && i%7 == 0)    //Sempre que a escala completa um ciclo, é necessário mudar o começo.
            if(escala[i%7] != 0)    ini = vetor[i-1]; //É como se a escala começasse de um novo ponto.
                else if(tom > 12)   ini = vetor[i-1] + 2; //Caso seja uma escala menor.
                    else            ini = vetor[i-1] + 1; //Caso seja uma escala maior.

        vetor[i] = escala[i%7] + ini;
    }


    return vetor;
}


void CaMaterial::GeraTriade(int notaref, int posicao, MuMaterial *paux) //Cria uma tríade no material paux
                                                                        //com base na nota de ref e a posição.
{
    int i, j, dur;
    int grau_aux;
    int *graus;
    MuNote note_aux, note_aux1, note_aux2;

        i     = this->getEscalaNat();
        graus = getVetorGraus(i); //pega vetor contendo a escala tonal da melodia

        for(j = 4; j < TAMANHO_ESCALA; j++) 
        {
            if(notaref%12 == (graus[j])%12)
            { 
                grau_aux = j;
                j = TAMANHO_ESCALA+1;
            }
        }

        if(j == TAMANHO_ESCALA) exit(1);

        i = grau_aux - posicao*2;
        dur = paux->Dur();

        note_aux.SetStart(dur);
        note_aux.SetDur(2);
        note_aux.SetAmp(0.25);

        note_aux2 = note_aux;
        note_aux1 = note_aux;

        note_aux.SetPitch(graus[i]);
        note_aux1.SetPitch(graus[i+2]);
        note_aux2.SetPitch(graus[i+4]);

        paux->AddNote(0, note_aux);
        paux->AddNote(0, note_aux1);
        paux->AddNote(0, note_aux2);

    delete[] graus;
}

int CaMaterial::ProximaAltura(int notaref, int salto)
{
    int * graus = Graus[0];
    int grau_atual, grau_post;

    if(graus[0]> 128)
    { 
        cout << "Erro no Vetor de Graus." << endl;
        exit(3);
    }


    for(int i = 0; i < TAMANHO_ESCALA; i++)
        if(graus[i] == notaref)
            {   
                grau_atual = i;
                i = TAMANHO_ESCALA;
            }

    if(salto < 0)//Caso seja um movimento descendente.
    grau_post = salto + 1 + grau_atual;
    else if(salto > 0)//Caso seja um movimento ascendente.
    grau_post = salto - 1 + grau_atual;
    else return notaref; //Caso não haja movimento.

    if(grau_post < 0)
    {
        cout <<"Nota abaixo do vetor de graus analisados." << endl;
        exit(3);
    } else if( grau_post > TAMANHO_ESCALA)
    {
        cout <<"Nota acima do vetor de graus analisados." << endl;
        exit(3);
    }

    return graus[grau_post];

}


int* CaMaterial::getCompassos(int tempos, int *numero_compassos)
{

    int tamanho, duracao;


    duracao           = this->Dur();
    *numero_compassos = (int)duracao/tempos;
    int *compassos    = new int[*numero_compassos];

    for(int j = 0; j < *numero_compassos; j++)   //encontra o compasso correspondente para a criaçao
        compassos[j]  = j*tempos;



    return compassos;
}


void CaMaterial::setGraus(void) //Armazena o grau da voz zero em graus[0];
{
    CaMaterial aux;
    int escala;

    aux            = this->GetVoice(0);
    escala         = aux.getEscalaNat();
    this->Graus[0] = getVetorGraus(escala);
}

void CaMaterial::setGraus(int numero_voz) //Armazena o grau da voz escolhida em graus[0];
{
    CaMaterial aux;
    int escala;

    if(numero_voz >= NUMERO_DE_VOZES ) exit (2);

    aux                     = this->GetVoice(numero_voz);
    escala                  = aux.getEscalaNat();
    this->Graus[numero_voz] = getVetorGraus(escala);
}

int* CaMaterial::getGraus(void)//Retorna o vetor com os graus da voz zero.
{   
    return Graus[0];
}

int* CaMaterial::getGraus(int voz)//Retorna o vetor com os graus da voz escolhida.
{   
    return Graus[voz];
}

void CaMaterial::ShowGraus(void)//Imprime na tela os graus da voz zero do material.
{
    int* graus = this->getGraus();

    for(int i = 0; i < TAMANHO_ESCALA; i++)
        cout << graus[i] << " ";

    delete[] graus;
}

void CaMaterial::ShowGraus(int voz)//Imprime na tela os graus da voz escolhida do material.
{
    int* graus = this->getGraus(voz);

    for(int i = 0; i < TAMANHO_ESCALA; i++)
        cout << graus[i] << " ";

    delete[] graus;
}

CaMaterial & CaMaterial::operator=(const CaMaterial & inMaterial)
{   
    MuMaterial::operator=(inMaterial);

    for(int i = 0; i < 16; i++)
        Graus[i]= inMaterial.Graus[i];

    return *this;
}

CaMaterial & CaMaterial::operator=(const MuMaterial & inMaterial)
{   
    MuMaterial::operator=(inMaterial);

    return *this;
}
