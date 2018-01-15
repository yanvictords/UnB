#include <iostream>
#include "MuMaterial.h"
using namespace std;
/*-------------- Declarando funcoes suporte e funcoes com mais relevancia --------------*/
/*sup*/short estrutural(short notas[], MuMaterial auxiliar, int); //retorna o sorteio de uma nota estrutural
/*sup*/void Zera_probPitch(int probPitch[]); //zera o vetor probabilidades de pitch
/*sup*/void Preenche_probPitch(int acordeCompasso,int probPitch[]); //preenche o vetor de probab. para pitch com tendências
/*sup*/void melhora_pitch_prob(int probPitch[], int notant, short notas[]); //altera probabilidades baseada na nota anterior. Menores saltos + preferencia
/*sup*/int num_compassos(MuMaterial acorde, MuNote lastnote); //retorna o numero de compassos
/*sup*/void vet_infors(int *compassos, int *duracao, MuMaterial acorde, MuNote lastnote); //cria 2 vetores de informaçoes (inicio, dur)
/*sup*/void melhora_tempo(float *tempos, int *probabilidades, float tant);
/*sup*/void reset_probtempo(int *probtempo);
MuMaterial mat_acorde(MuMaterial acorde, int compasso, int i); //retorna material contendo todas as notas de um compasso
int verifica_acorde(MuMaterial auxiliar); //retorna o valor do acorde 0-11 ou 20+ de cada compasso
float SorteiaTempo(float tempos[], int probabilidade[]); //Retorna uma duração sorteada para uma nota
short SorteiaPitch(short pitches[], int probPitch[]); //Retorna uma nota sorteada


//*O QUE EU PRECISO*
// material contendo todas as notas.  	MATERIAL AUXILIAR
// acorde de cada compasso VAI ESTAR NO MATERIAL AUXILIAR
// vetor 'compassos' contendo o inicio de cada compasso, para eu poder vazer compassos[i]+inicio da nota
// vetor 'duração' pra eu usar como condição de parada de adição de notas para um compasso.
// vetores contendo notas e tempos, e suas respectivas probabilidades para criar tendências e SORTEAR 

/*---------------------------------------------------------------------------*/
/*---------------------------FUNCAO PRINCIPAL-------------------------------------*/
int main(void)
{
	MuInit();
	MuMaterial acorde, auxiliar, improviso; //acorde = material principal, auxiliar contem notas do acorde, improviso = melodia
	MuNote nota, lastnote; //nota a ser acrescentada no material improviso, lastnote como parametro para laços

	float somadur, tempo, tant, tempovet[8] = {0.25, 0.5, 0.75, 1, 1.5, 2, 3, 4}; // tempos possiveis para este trabalho
	short ant, notas[7] = {72, 74, 76, 77, 79, 81, 83}; // notas para improviso
	int i, num_comp, probPitch[7], probPitch2[7], probtempo[8] = {5, 7, 4, 6, 3, 1, 1, 1}; // num. de compassos e probabilidades 
	acorde.LoadScore("/home/yan/Documentos/Musical/MuM-master/acordes1.sco");
	lastnote = acorde.GetNote(0, acorde.NumberOfNotes(0)-1); //pegando a ultima nota do ultimo compasso ou material
	num_comp = num_compassos(acorde, lastnote); //encontrando o numero total de compassos
	int compassos[num_comp]; //contem o inicio em segundos de cada compasso
	int duracao[num_comp]; //contem a duracao de cada compasso
	vet_infors(compassos, duracao, acorde, lastnote); //Preenchendo os vetores com o inicio e a duracao de cada compasso




	/*------------ ...Começando... CODIGO PRINCIPAL... Para cada compasso--------------*/

	for(i=0;i<num_comp;i++){ 
		auxiliar = mat_acorde(acorde, compassos[i], i); //material auxiliar contendo as notas do acorde
		Zera_probPitch(probPitch); // zera o vetor de probabilidades para as notas
		Preenche_probPitch(verifica_acorde(auxiliar),probPitch); //preenche de acordo com o acorde do compasso
		somadur=0;  //compasso sem notas ainda
		
		/*-----dentro do um compasso-----*/
		if((num_comp==i+1)&&(duracao[i]==8))
			duracao[i]=4;
		while(somadur<duracao[i]){ //enquanto a soma das notas for menor que a duracao do compasso, ele continua adc...
			nota.SetAmp(0.7);
			nota.SetStart(compassos[i]+somadur); //adiciona no final da nota anterior pertencente ao compasso[i]
			if(nota.Start()==compassos[i]){ //se for a primeira nota do compasso, sorteia uma estrutural
				if(i==0) //se for a primeira nota da melodia
					nota.SetPitch(estrutural(notas,auxiliar,-1));
				else //sorteia a primeira nota do compasso se baseando na ultima nota do compasso anterior para saltos
					nota.SetPitch(estrutural(notas,auxiliar,ant));
				ant = nota.Pitch();
			}else{ 
				melhora_pitch_prob(probPitch, ant, notas); //melhora probPitch baseado na nota anterior (saltos)
				for(int i =0;i<7;i++)
					probPitch2[i] = probPitch[i]; //pitch2 é o pitc melhorado
	
				Zera_probPitch(probPitch); // reseta o vetorpitch
				Preenche_probPitch(verifica_acorde(auxiliar),probPitch); //reseta baseado no compasso
				nota.SetPitch(SorteiaPitch(notas, probPitch2));
				if(nota.Pitch()==ant) //tende a nao repetir a nota anterior
					nota.SetPitch(SorteiaPitch(notas, probPitch2));
				if(nota.Pitch()==ant) //tende a nao repetir a nota anterior2
					nota.SetPitch(SorteiaPitch(notas, probPitch2));
				ant = nota.Pitch();
			}
			if(i!=0) //como nao tem tempo anterior na primeira nota do primeiro compasso
				melhora_tempo(tempovet, probtempo, tant);
			tempo = SorteiaTempo(tempovet, probtempo); //sorteia uma duracao para a nota
			while(i==0&&tempo==0.25) //evitar que  a primeira nota seja rapida
				tempo = SorteiaTempo(tempovet, probtempo);
			while((tempo+somadur)>duracao[i]) //enquanto a duracao da ultima nota do compasso passar da duracao do compasso
				tempo = SorteiaTempo(tempovet, probtempo); //sorteia uma nova duracao para nao ultrapassar o limite
			reset_probtempo(probtempo);
			somadur+=tempo;  //para controlar a quantidade de notas e duraçao total delas em um compasso
			nota.SetDur(tempo); //duracao
			tant=nota.Dur();
			improviso += nota; //adiciona nota no material improviso
		}
	}
	//Agora para criar a ultima nota da melodia
	auxiliar = mat_acorde(acorde, compassos[i-1], i-1);
	Zera_probPitch(probPitch);
	Preenche_probPitch(verifica_acorde(auxiliar),probPitch);
	melhora_pitch_prob(probPitch, ant, notas);
	for(int i =0;i<7;i++)
		probPitch2[i] = probPitch[i];
	nota.SetAmp(0.7);
	nota.SetStart(compassos[i-1]+duracao[i-1]);
	nota.SetDur(4);
	nota.SetPitch(estrutural(notas,auxiliar,ant));
	improviso += nota; 
	/*--------------------------*/
	acorde.SetVoice(2, improviso, 0);
	acorde.SetInstrument(2,4);
	acorde.SetInstrument(1,2);
	acorde.SetInstrument(0,3);
	acorde.SetAmp(0,0.3);
	acorde.SetAmp(1, 0.3);
	acorde.SetAmp(2, 0.5);
	acorde.Show();
	acorde.PlaybackWithCsound("/home/yan/Documentos/Musical/MuM-master/teste");
	acorde.SetDefaultFunctionTables();
	acorde.Score("/home/yan/Documentos/Musical/MuM-master/Saida");
	acorde.Orchestra("/home/yan/Documentos/Musical/MuM-master/Saida");
	return 0;	
}
/*---------------------------------------------------------------------------*/
/*---------------------------FIM DA FUNCAO PRINCIPAL-------------------------------------*/
/*--------------------melhor a probabilidade dos tempos de acordo com o anterior------------------------*/
void melhora_tempo(float *tempos, int *probabilidades, float tant){
	int k;
	for(int i=0;i<8;i++){
		if(tempos[i]==tant)
			k=i;
	}
	switch(k){ //k e o valor do indica da nota anterior
		case 0:
			probabilidades[0]+=5;	
			probabilidades[1]+=7;
			probabilidades[2]+=2;		
			break;
		case 1:
			probabilidades[0]+=6;
			probabilidades[1]+=5;
			probabilidades[2]+=6;		
			probabilidades[3]+=5;
			break;
		case 2:
			probabilidades[0]+=3;
			probabilidades[1]+=6;
			probabilidades[2]+=3;		
			probabilidades[3]+=6;
			probabilidades[4]+=3;
			break;
		case 3:
			probabilidades[1]+=6;
			probabilidades[3]+=5;
			probabilidades[2]+=7;		
			probabilidades[4]+=6;
			break;
		case 4:
			probabilidades[2]+=6;
			probabilidades[3]+=7;		
			break;
		case 5:
			probabilidades[3]+=8;
			probabilidades[4]+=4;		
			break;
		case 6:
			probabilidades[4]+=7;	
			break;
		case 7:
			probabilidades[4]+=7;	
			break;
	}	
}
/*--------------------reseta as probabilidades dos tempos------------------------*/
void reset_probtempo(int *probtempo){
	probtempo[0]=5;
	probtempo[1]=7;
	probtempo[2]=4;
	probtempo[3]=6;
	probtempo[4]=3;
	probtempo[5]=1;
	probtempo[6]=1;
	probtempo[7]=1;
}
/*--------------------melhor sorteio pitc de acordo com a nota anterior------------------------*/
void melhora_pitch_prob(int probPitch[], int notant, short notas[]){ //
	int *probPitch2;
	probPitch2=probPitch;
	for(int i=0;i<7;i++){
		if(notant-notas[i]==1||notant-notas[i]==-1||notant-notas[i]==2||notant-notas[i]==-2){ //se intervalo for 2M ou 2m
			if(probPitch[i]!=0&&probPitch[i]!=1){ //se for diferente de evitada e prob2
				if(probPitch[i]==4) //se for estrutural
					probPitch2[i]+=10;
				if(probPitch[i]==3) //se for tensao
					probPitch2[i]+=7;
			}
		}
		if(notant-notas[i]==3||notant-notas[i]==-3||notant-notas[i]==4||notant-notas[i]==-4){//se intervalo for 3M ou 3m
			if(probPitch[i]!=0&&probPitch[i]!=1){ //se for diferente de evitada e prob2
				if(probPitch[i]==4) //se for estrutural
					probPitch2[i]+=6;
				if(probPitch[i]==3) //se for tensao
					probPitch2[i]+=3;
	
			}
		}	
		if(notant-notas[i]>6||notant-notas[i]<-6){ //se intervalo for maior que uma 4
			if(probPitch[i]=!0)			
				probPitch2[i]=1;
		}		
	}
	
}
/*--------------------verifica qual o acorde de tal compasso------------------------*/
int verifica_acorde(MuMaterial auxiliar){
	int contador=0, flag=0;
	MuMaterial auxiliar2;
	for(int i = 0; i<auxiliar.NumberOfNotes();i++){ //percore o auxiliar
		for(int j=0;j<auxiliar2.NumberOfNotes();j++){ //percorre o auxiliar2
			if((auxiliar2.GetNote(0,j).Pitch()%12)==(auxiliar.GetNote(0,i).Pitch()%12)) //verifica se nota ja esta contida
				flag=1; //quer dizer que a nota%12 ja esta contida no material, mesmo com pitchs diferentes
		}
		if(flag==0){  //se a nota nao estiver no material
			auxiliar2+=auxiliar.GetNote(0,i);
		}
		flag=0;

	}	
	auxiliar = auxiliar2; //vamos trabalhar apenas com o auxiliar
	int triade[7][3]={{0, 4, 7},{2, 5, 9},{4, 7, 11},{5, 9, 0},{7,11,2},{9,0,4},{11,2,5}}; 
	int tetrade[7][4]={{0, 4, 7, 11},{2, 5, 9, 0},{4, 7, 11, 2},{5, 9, 0, 4},{7,11,2, 5},{9,0,4, 7},{11,2,5,9}};
	if(auxiliar.NumberOfNotes()==3){ //se o auxiliar conter apenas 3 notas, e porque eh uma triade
		for(int i=0;i<7;i++){ //qual o acorde
			for(int j = 0;j<3;j++){ //qual a nota estrutural
				for(int k=0;k<3; k++){ //qual a nota do material auxiliar
					if((auxiliar.GetNote(0,k).Pitch()%12)==triade[i][j])
						contador++; //conta a quantidade de notas iguais.
				}
			}
			if(contador==3) //se tiver 3 notas iguais em um acorde x, entao achou o acorde
				return triade[i][0]; //retorna o acorde
			else
				contador=0;
		}	
	}  // *A LOGICA ABAIXO E A MESMA PARA A TRIADE*
	if(auxiliar.NumberOfNotes()==4){ //se o auxiliar conter apenas 4 notas, e porque eh uma tetrade
		for(int i=0;i<7;i++){
			for(int j = 0;j<4;j++){
				for(int k=0;k<4; k++){
					if((auxiliar.GetNote(0,k).Pitch()%12)==tetrade[i][j])
						contador++;
				}
			}
			if(contador==4)
				return tetrade[i][0]+20;
			else
				contador=0;
		}	
	}
	return -1; //caso nao ache o acorde
}
/*--------------------retorna o numero de compassos---------------------------*/
int num_compassos(MuMaterial acorde, MuNote lastnote){ //retorna o numero de compassos
	int num_comp=1;
	for(int i = 0; acorde.GetNote(0, i).Start()!=lastnote.Start(); i++){ 
		if(acorde.GetNote(0, i).Start()!=acorde.GetNote(0, i+1).Start()) //se tp da nota for diferente da posterior, muda o compasso
			num_comp++;
	}
	return num_comp;
}
/*--------------------preenche vetores de informacoes----------------------*/
void vet_infors(int *compassos, int *duracao, MuMaterial acorde, MuNote lastnote){ //cria 2 vetores de informaçoes (inicio, dur)
	int j = 0;
	for(int i = 0; acorde.GetNote(0, i).Start()!=lastnote.Start();i++){
		compassos[j] = acorde.GetNote(0, i).Start(); //pegando o inicio em segundos de cada compasso
		duracao[j] = acorde.GetNote(0, i).Dur(); //pegando a duracao de cada compasso
		if(compassos[j]!=acorde.GetNote(0, i+1).Start()){	
			j++;
		}
	}
	compassos[j] = lastnote.Start(); //pegando para o ultimo compasso
	duracao[j] = lastnote.Dur(); //pegando para o ultimo compasso
}

/*--------------------retorna material com notas do acorde----------------------*/
MuMaterial mat_acorde(MuMaterial acorde, int compasso, int i){ //retorna material contendo todas as notas de um compasso
	MuMaterial auxiliar;
	auxiliar=acorde.GetNotesStartingAt(0, compasso); //Notas da mão direita
	auxiliar+= acorde.GetNote(1, i); //Nota da mão esquerda
	return auxiliar;
}



/*---------------------sorteia nota qualquer--------------------------------*/
short SorteiaPitch(short pitches[], int *probPitch) {
	int i, j, prob, ultimaparada = 0;

	short vetorzao[100]; //vetor que contera todos as notas, com suas tendencias
	for (i=0;i<7;i++){
		prob = probPitch[i]; //quantidade de vezes que aquela nota ira aparecer no vetor
		for (j=0;j<prob;j++){
			vetorzao[ultimaparada + j] = pitches[i];
		}
		ultimaparada = ultimaparada + j;
	}
	ultimaparada--;
	int valor = rand(); //sorteia um  indice do vetor
	valor = valor >> 16;
	valor%=ultimaparada;
	return (vetorzao[valor]);		
}

/*-------------------Sorteia uma duracao para as notas--------------------*/
float SorteiaTempo(float tempos[], int probabilidade[]) {
	int i, j, TEMPOS=8, prob, ultimaparada = 0;
	float vetorzao[100]; //vetor que contera todos os tempos, com suas tendencias
	for (i=0;i<TEMPOS;i++){
		prob = probabilidade[i]; //quantidade de vezes que aquele tempo ira aparecer no vetor
		for (j=0;j<prob;j++){
			vetorzao[ultimaparada + j] = tempos[i];
		}
		ultimaparada = ultimaparada + j;
	}
	ultimaparada--;
	int valor = rand(); //sorteia um  indice do vetor
	valor = valor >> 16;
	valor%=ultimaparada;
	return vetorzao[valor];			
}
/*-----------------------------sorteia nota estrutural---------------------------------*/
short estrutural(short notas[], MuMaterial auxiliar, int ant){
	short nota, notaf;
	int x, y;
	MuNote notasorteada;
	if(ant==-1){ //se for a primeira nota da melodia apenas sorteia uma
		notasorteada = auxiliar.GetNote(0, Between(0,auxiliar.NumberOfNotes()-1));
		for(int a=0; a<7;a++){
			if(notasorteada.Pitch()%12==notas[a]%12)
				return notas[a]; 
		}		
		return notasorteada.Pitch(); //se for acidente
	}else{
		nota=-1; //ver se nao tem acidente
		for(int a=0; a<7;a++){
			if(auxiliar.GetNote(0,0).Pitch()%12==notas[a]%12)
				nota = notas[a];
		}
		if(nota==-1) //se for acidente pega o pitch original do acorde
			nota = auxiliar.GetNote(0,0).Pitch();
		x = nota - ant;
		notaf=nota;
		if(x<0) //se x for negativo
			x*=-1;
		for(int i=1;i<auxiliar.NumberOfNotes();i++){ //for para descobrir quem tem menor raio
			nota=-1; //ver se nao tem acidente
			for(int a=0; a<7;a++){
				if(auxiliar.GetNote(0,i).Pitch()%12==notas[a]%12)
					nota = notas[a];
			}
			if(nota==-1) //se for um acidente
				nota = auxiliar.GetNote(0,i).Pitch();
			y = nota-ant;
			if(y<0)
				y*=-1;
			if(y<x){ //se a nova nota é um intervalo menor
				x=y;
				notaf=nota;
			}
		}
	}
	return notaf;	

}

/*-------------------zera vetor probabilidade para notas--------------------*/
void Zera_probPitch(int probPitch[]){
	for (int i =0; i<7;i++)
		probPitch[i] = 0; 
}

/*----------------preenche vetor de probabilidades para notas----------------------*/
void Preenche_probPitch(int acordeCompasso,int *probPitch){
	switch(acordeCompasso){ //qual o acorde do compasso
		case 20: //C7M
			probPitch[0] = 4;
			probPitch[2] = 4;
			probPitch[4] = 4;
			probPitch[6] = 4;
			probPitch[1] = 3;
			probPitch[5] = 3;
			break;
		case 0: //C
			probPitch[0] = 4;
			probPitch[2] = 4;
			probPitch[4] = 4;
			probPitch[1] = 3;
			probPitch[5] = 3;
			break;
		case 22: //Dm7
			probPitch[1] = 4;
			probPitch[3] = 4;
			probPitch[5] = 4;
			probPitch[0] = 4;
			probPitch[2] = 3;
			probPitch[4] = 3;			
			break;
		case 2: //Dm
			probPitch[1] = 4;
			probPitch[3] = 4;
			probPitch[5] = 4;
			probPitch[2] = 3;
			probPitch[4] = 3;
			probPitch[0] = 3;
			break;
		case 24: //Em7
			probPitch[2] = 4;
			probPitch[4] = 4;
			probPitch[6] = 4;
			probPitch[1] = 4;
			probPitch[5] = 3;
			break;
		case 4: //Em
			probPitch[2] = 4;
			probPitch[4] = 4;
			probPitch[6] = 4;
			probPitch[1] = 3;
			probPitch[5] = 3;
			break;
		case 25: //F7M
			probPitch[3] = 4;
			probPitch[5] = 4;
			probPitch[0] = 4;
			probPitch[2] = 4;
			probPitch[4] = 3;
			probPitch[6] = 1;
			probPitch[1] = 1;
			break;
		case 5: //F
			probPitch[3] = 4;
			probPitch[5] = 4;
			probPitch[0] = 4;
			probPitch[4] = 3;
			probPitch[6] = 1;
			probPitch[1] = 1;
			break;
		case 27: //G7
			probPitch[4] = 4;
			probPitch[6] = 4;
			probPitch[1] = 4;
			probPitch[3] = 4;
			probPitch[5] = 3;
			probPitch[2] = 3;
			break;
		case 7: //G
			probPitch[4] = 4;
			probPitch[6] = 4;
			probPitch[1] = 4;
			probPitch[3] = 3;
			probPitch[5] = 3;
			probPitch[2] = 3;
			break;
		case 29: //Am7
			probPitch[5] = 4;
			probPitch[0] = 4;
			probPitch[2] = 4;
			probPitch[4] = 4;
			probPitch[6] = 3;
			probPitch[1] = 3;
			break;
		case 9: //Am
			probPitch[5] = 4;
			probPitch[0] = 4;
			probPitch[2] = 4;
			probPitch[4] = 3;
			probPitch[6] = 3;
			probPitch[1] = 3;
			break;
		case 31: //Bm7(b5)
			probPitch[6] = 4;
			probPitch[1] = 4;
			probPitch[3] = 4;
			probPitch[5] = 4;
			probPitch[2] = 3;
			probPitch[4] = 3;
			break;
		case 11: //Bm(b5)
			probPitch[6] = 4;
			probPitch[1] = 4;
			probPitch[3] = 4;
			probPitch[5] = 3;
			probPitch[2] = 3;
			probPitch[4] = 3;
			break;
		case -1: //caso ele nao tenha achado o acorde, todos serao considerados notas de tensao
			probPitch[6] = 2;
			probPitch[1] = 4;
			probPitch[3] = 4;
			probPitch[5] = 4;
			probPitch[2] = 4;
			probPitch[4] = 4;
			probPitch[0] = 4;
			break;
	}
}

