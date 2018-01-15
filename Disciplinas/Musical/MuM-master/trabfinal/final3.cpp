#include <iostream>
#include "MuMaterial.h"
using namespace std;


const int MAX_MOTIF = 20;

void pausa();
int tempo();
int * vet_graus(int tom, int maiormenor);
void show_tom(int tom, int maiormenor);
int *seleciona_tom(int *tom, int *maiormenor, int *graus, int parte);
int *vetor_melodia(int tom, int maiormenor);
void cria_oito_compassos(MuMaterial* oitocomp, MuMaterial afinal, int* inf_acorde, int* melodia, int* compassos, int num_oitos);
MuMaterial seleciona_acordes(int acorde[], MuNote notas, int *graus, int maiormenor, int tom, int compassos, int parteA, int inf_acorde[]);

/*sup*/short estrutural(int notas[], MuMaterial auxiliar, int); //retorna o sorteio de uma nota estrutural
/*sup*/void Zera_probPitch(int probPitch[]); //zera o vetor probabilidades de pitch
/*sup*/void Preenche_probPitch(int acordeCompasso,int probPitch[]); //preenche o vetor de probab. para pitch com tendências
/*sup*/void melhora_pitch_prob(int probPitch[], int notant, int notas[]); //altera probabilidades baseada na nota anterior. Menores saltos + preferencia
/*sup*/int num_compassos(MuMaterial acorde, MuNote lastnote); //retorna o numero de compassos
/*sup*/void vet_infors(int *compassos, int *duracao, MuMaterial acorde, MuNote lastnote); //cria 2 vetores de informaçoes (inicio, dur)
MuMaterial mat_acorde(MuMaterial acorde, int compasso); //retorna material contendo todas as notas de um compasso
short SorteiaPitch(int pitches[], int probPitch[]); //Retorna uma nota sorteada


int main(void){
	MuInit();
	MuMaterial acordesA, acordesB, afinal, auxiliar, mauxiliar, improvisoT, improvisoP, improvisoA, improvisoB;
	MuNote notas, nota, lastnote;
	int tom, maiormenor, *graus, acorde[18];
	int *melodiaA= new int[10];
	int *melodiaB= new int[10];
	int inf_acordeA[8];
	int inf_acordeB[8];


	int i, num_comp;// num. de compassos e probabilidades 
	
	afinal.LoadOrchestra("/home/aluno/Documentos/MuM-master/TrompetePiano.orc");
    afinal.LoadFunctionTables("/home/aluno/Documentos/MuM-master/TrompetePiano.tbl");


	acordesA.SetInstrument(0,1);
	acordesB.SetInstrument(0,1);
	system("clear");
	for(int i=0; i<18;i++)
		acorde[i]=i+48;
	
	graus = seleciona_tom(&tom, &maiormenor, graus, 1);
	melodiaA = vetor_melodia(tom, maiormenor);
	acordesA = seleciona_acordes(acorde, notas, graus, maiormenor, tom, 7, 1, inf_acordeA);
	
	for(int i=0;i<4;i++)
		afinal+=acordesA;
	pausa();
	
	graus = seleciona_tom(&tom, &maiormenor, graus, 2);
	melodiaB = vetor_melodia(tom, maiormenor);
	acordesB = seleciona_acordes(acorde, notas, graus, maiormenor, tom, 8, 2, inf_acordeB);
	
	for(int i=0;i<2;i++)
		afinal+=acordesB;

	for(int i=0;i<2;i++)
		afinal+=acordesA;
	afinal.SetInstrument(0,3); //******************** ALTERAR ->>> INSTRUMENTO PIANO HARMONIA


	lastnote = afinal.GetNote(0, afinal.NumberOfNotes(0)-1); //pegando a ultima nota do ultimo compasso ou material
	num_comp = num_compassos(afinal, lastnote); //encontrando o numero total de compassos
	int compassos[num_comp]; //contem o inicio em segundos de cada compasso
	int duracao[num_comp]; //contem a duracao de cada compasso
	vet_infors(compassos, duracao, afinal, lastnote); //Preenchendo os vetores com o inicio e a duracao de cada compasso

/*---------------------------------------------------------------------*/
	cria_oito_compassos(&improvisoA, afinal, inf_acordeA, melodiaA, compassos, 0);

	cria_oito_compassos(&improvisoB, afinal, inf_acordeB, melodiaB, compassos, 8);

	//cout << testa << endl;
	nota.SetAmp(0);
	nota.SetDur(16);
	nota.SetPitch(60);
	improvisoT += improvisoA;//MOTIVO improvisoA ORIGINAL DA PARTEA (nao perca este motivo, varie o improvisoA usando um auxiliar)
	improvisoT += nota;

	auxiliar.Clear();	//********** ->>> VARIE AQUI O IMPROVISOA PARA INSERIR O PRIMEIRO MOTIVO VARIADO ABAIXO (usando funcao)
	cria_oito_compassos(&auxiliar, afinal, inf_acordeA, melodiaA, compassos, 2);

	improvisoT += auxiliar;

	//********** ->>> VARIE AQUI O IMPROVISOA PARA INSERIR O PRIMEIRO MOTIVO VARIADO ABAIXO (usando funcao)
	auxiliar.Clear();	
	cria_oito_compassos(&auxiliar, afinal, inf_acordeA, melodiaA, compassos, 4);

	improvisoT += auxiliar; 	

	//********** ->>> VARIE AQUI O IMPROVISOA PARA INSERIR O PRIMEIRO MOTIVO VARIADO ABAIXO (usando funcao)
	auxiliar.Clear();
	improvisoT += improvisoB; //MOTIVO improvisoB ORIGINAL DA PARTEB (nao perca este motivo, varie o improvisoB usando um auxiliar)

	//********** ->>> VARIE AQUI O IMPROVISOB PARA INSERIR QUE OS FOR'S ABAIXO ATRIBUAM PARA IMPROVISTOT O MOTIVO VARIADO
	cria_oito_compassos(&auxiliar, afinal, inf_acordeB, melodiaB, compassos, 8);

	for(int i=0;	auxiliar.GetNote(0,i).Start()<4;i++)
		improvisoT += auxiliar.GetNote(0,i);

	nota.SetAmp(0);
	nota.SetDur(4);
	nota.SetPitch(60);
	//cout << testa2 << endl;
	improvisoT += nota;

	auxiliar.Clear();
	cria_oito_compassos(&auxiliar, afinal, inf_acordeB, melodiaB, compassos, 10);

	for(int i=0;auxiliar.GetNote(0,i).Start()<12;i++){
		if(auxiliar.GetNote(0,i).Start()>=8)
			improvisoT += auxiliar.GetNote(0,i);
	}
	
	nota.SetAmp(0);
	nota.SetDur(4);
	nota.SetPitch(60);
	improvisoT+=nota;
	
	//********** ->>> VARIE AQUI O IMPROVISOA PARA INSERIR O TERCEIRO MOTIVO VARIADO ABAIXO
	auxiliar.Clear();
	cria_oito_compassos(&auxiliar, afinal, inf_acordeA, melodiaA, compassos, 4);
	improvisoT += auxiliar; 

	
	auxiliar.Clear();
	improvisoT += improvisoA; //original(NAO VARIA)
	

	nota.SetAmp(0);
	nota.SetDur(16);
	nota.SetPitch(60);
	improvisoP += nota;
	improvisoP += improvisoA;
	nota.SetAmp(0);
	nota.SetStart(32);
	nota.SetDur(52);
	nota.SetPitch(60);
	improvisoP += nota;

	cria_oito_compassos(&auxiliar, afinal, inf_acordeB, melodiaB, compassos, 11);

	for(int i = 0;	auxiliar.GetNote(0,i).Start() < 8; i++){
		if(auxiliar.GetNote(0,i).Start() >= 4)
			improvisoP+=auxiliar.GetNote(0,i);
	}


	nota.SetStart(88);
	nota.SetAmp(0);
	nota.SetDur(4);
	nota.SetPitch(60);
	improvisoP += nota;

	auxiliar.Clear();
	cria_oito_compassos(&auxiliar, afinal, inf_acordeB, melodiaB, compassos, 12);

	for(int i=0;	(auxiliar.GetNote(0,i).Start()+ auxiliar.GetNote(0,i).Dur())<=16;i++){
		if(auxiliar.GetNote(0,i).Start()>=12)
			improvisoP += auxiliar.GetNote(0,i);
		if((auxiliar.GetNote(0,i).Start()	+	auxiliar.GetNote(0,i).Dur())==16)
			break;
	}

	nota.SetAmp(0);
	nota.SetDur(16);
	nota.SetPitch(60);
	improvisoP += nota;
	improvisoP+=improvisoA;
	
	afinal.SetVoice(1, improvisoP, 0);
	afinal.SetVoice(2, improvisoT, 0);
	afinal.SetInstrument(1,1);  //******************** ALTERAR ->>> INSTRUMENTO PIANO MELODIA
	afinal.SetInstrument(2,2); //******************** ALTERAR ->>> INSTRUMENTO TROMPETE MELODIA
	
	auxiliar = mat_acorde(afinal, compassos[num_comp-1]);
	nota.SetAmp(0.7);
	nota.SetDur(1);
	nota.SetStart(128);
	nota.SetPitch(estrutural(melodiaA,auxiliar,-1));
	afinal.AddNote(1,nota);
	afinal.Show();
	afinal.PlaybackWithCsound("/home/aluno/Documentos/MuM-master/teste");
	afinal.SetDefaultFunctionTables();
	afinal.Score("/home/aluno/Documentos/MuM-master/Saida");
	afinal.Orchestra("/home/aluno/Documentos/MuM-master/Saida");
	
	delete[] melodiaA;
	delete[] melodiaB;

return 0;
}

int tempo(){
	int sorte = Between(0,10);
	if(sorte==0)
		return 0;
	if(sorte==1)
		return Between(0,2);
	if(sorte==2)
		return Between(0,2);
	if(sorte==3)
		return Between(0,3);
	if(sorte==4)
		return Between(0,4);
	if(sorte==5)
		return Between(0,5);
	
	return Between(0,10);
}

int *vetor_melodia(int tom, int maiormenor){
	int *melodia=new int[10];
	int base[12] = {66, 67, 68, 69, 70, 71, 72, 73,74,75,76,77};
	int mark;
	for(mark=0; mark<12;mark++){
		if(base[mark]%12==tom%12)
			break;
	}
	if(maiormenor == 1){
		melodia[0]=base[mark];
		melodia[1]=base[mark]+2;
		melodia[2]=base[mark]+4;
		melodia[3]=base[mark]+5;
		melodia[4]=base[mark]+7;
		melodia[5]=base[mark]+9;
		melodia[6]=base[mark]+11;
		melodia[7]=base[mark]+12;
		melodia[8]=base[mark]+14;
		melodia[9]=base[mark]+16;



	}else{
		melodia[0]=base[mark];
		melodia[1]=base[mark]+2;
		melodia[2]=base[mark]+3;
		melodia[3]=base[mark]+5;
		melodia[4]=base[mark]+7;
		melodia[5]=base[mark]+8;
		melodia[6]=base[mark]+10;
		melodia[7]=base[mark]+12;
		melodia[8]=base[mark]+14;
		melodia[9]=base[mark]+15;
	}
	
	return melodia;
}

int *seleciona_tom(int *tom, int *maiormenor, int *graus, int parte){
	system("clear");
	cout << "*************** CONCERTO PARA TROMPETE E PIANO ***************\nDivisoes: [PARTE A] [PARTE B]"<< endl;
	cout << "Instrucoes: Primeiro vamos inserir os acordes da musica...\n\n"<< endl;
	if(parte==1)
		cout << "~~ Escolha o tom da parte A ~~" << endl;
	else
		cout << "~~ Escolha o tom da parte B ~~" << endl;
	cout << "0. C\n1. C#\n2. D\n3. D#\n4. E\n5. F\n6. F#\n7. G\n8. G#\n9. A\n10. A#\n11. B " << endl << endl;
	cout << "Digite o Tom:";
	cin >> *tom;
	
	while(*tom<0||*tom>11){
		cout << "Tom incorreto! Digite novamente: ";
		cin >> *tom;
	}
	system("clear");
	cout << "~~ Selecione uma opcao ~~\n";
	cout << "1. Tonalidade Maior\n2. Tonalidade Menor\n";
	cout << "Digite um valor: ";
	cin >> *maiormenor;
	while(*maiormenor<1||*maiormenor>2){
		cout << "Tonalidade incorreta! Digite novamente: ";
		cin >> *maiormenor;
	}
	graus = vet_graus(*tom, *maiormenor);
	return graus;

}
void pausa(){
	system("clear");
	cout << "Fim da primeira parte.";
	getchar();
	system("clear");
	cout << "Fim da primeira parte..";
	getchar();
	system("clear");
	cout << "Fim da primeira parte...";
	getchar();
}
MuMaterial seleciona_acordes(int acorde[], MuNote notas, int *graus, int maiormenor, int tom, int compassos, int parteA, int inf_acorde[]){
	notas.SetDur(2.0);
	notas.SetAmp(0.5);
	MuMaterial acordes;
	int k, nota, mostra[7];
	for(k =0;k<=compassos;k++){
		system("clear");
		cout << "******** Seleção de Acordes ********\n\n";
		cout << "Tom escolhido: "; show_tom(tom, maiormenor); cout << "\n\n";
		if(parteA==1)
			cout << "\nInstrucoes: escolha 7 acordes(Parte A)\nUse a numeracao de 1 a 7 para cada acorde correspondente...\n\n";
		else
			cout << "\nInstrucoes: escolha 8 acordes(Parte B)\nUse a numeracao de 1 a 7 para cada acorde correspondente...\n\n";
		cout << "\nAcordes escolhidos: ";
		for(int x=0; x<k;x++){
			cout <<x+1;
			if(maiormenor==1){
				if(mostra[x]%12==graus[0]%12||mostra[x]%12==graus[3]%12||mostra[x]%12==graus[4]%12||mostra[x]%12==graus[6]%12){
					cout <<"|"; show_tom(mostra[x]%12,1); 
					if(mostra[x]%12==graus[6]%12)
						cout << "dim";					
					cout <<"| ";
				}else{
					cout <<"|"; show_tom(mostra[x]%12,2); cout <<"| ";
				}
			}else{
				if(mostra[x]%12==graus[1]%12||mostra[x]%12==graus[2]%12||mostra[x]%12==graus[4]%12||mostra[x]%12==graus[5]%12||mostra[x]%12==graus[6]%12){
					cout <<"|"; show_tom(mostra[x]%12,1); 
					if(mostra[x]%12==graus[1]%12)
						cout << "dim";					
					cout <<"| ";
				}else{
					cout <<"|"; show_tom(mostra[x]%12,2); cout <<"| ";
				}


			}
		}
		cout << "\n\n--- Selecione um dos acordes abaixo ---" << endl;
		for(int x = 0;x<7;x++){
			if(maiormenor==1){
				if(graus[x]%12 == graus[0]%12 || graus[x]%12 == graus[3]%12 || graus[x]%12 == graus[4]%12 || graus[x]%12 == graus[6]%12){
					cout << "|"; show_tom(graus[x]%12,1);
					if(graus[x]%12 == graus[6]%12)
						cout << "dim";
					cout << "|";
				}else{
					cout <<"|"; show_tom(graus[x]%12,2); cout <<"|";
				}
			}else{
				if(graus[x]%12 == graus[1]%12 || graus[x]%12 == graus[2]%12 || graus[x]%12 == graus[4]%12 || graus[x]%12 == graus[5]%12 || graus[x]%12 == graus[6]%12){
					cout << "|"; show_tom(graus[x]%12,1);
					if(graus[x]%12 == graus[1]%12)
						cout << "dim";
					cout << "|";
				}else{
					cout <<"|"; show_tom(graus[x]%12,2); cout <<"|";
				}
			}
		}
		cout << "\n\n[1][2][3][4][5][6][7] digite o Grau: "; 
		if(k<compassos){
		cin >> nota;
		while(nota<1||nota>7){
			cout << "\nAcorde incorreto! Digite novamente: " ;
			cin >> nota;
		}
		inf_acorde[k]=nota-1;
		mostra[k]=graus[nota-1]%12;
		for(int i = 0; i<18;i++){
			if(acorde[i]%12==graus[nota-1]%12){
				notas.SetPitch(acorde[i]);
				notas.SetStart(k*2);
				acordes.AddNote(notas);	
				if(maiormenor==1){
					if(nota==1||nota==4||nota==5)
						notas.SetPitch(acorde[i]+4);
					else
						notas.SetPitch(acorde[i]+3);
					notas.SetStart(k*2);
					acordes.AddNote(notas);		
					if(nota==7)
						notas.SetPitch(acorde[i]+6);
					else
						notas.SetPitch(acorde[i]+7);
					notas.SetStart(k*2);
					acordes.AddNote(notas);	
				}else{
					if(nota==3||nota==6||nota==7){
						notas.SetPitch(acorde[i]+4);
					}else{	
						if(nota==5)
							notas.SetPitch(acorde[i]+4);
						else
							notas.SetPitch(acorde[i]+3);
					}
					notas.SetStart(k*2);
					acordes.AddNote(notas);		
					if(nota==2)
						notas.SetPitch(acorde[i]+6);
					else
						notas.SetPitch(acorde[i]+7);
					notas.SetStart(k*2);
					acordes.AddNote(notas);
				}
				break;
			}
		}
	}
	}
	if(compassos==7){
		inf_acorde[7]=0;
		for(int i = 0; i<18;i++){
			if(acorde[i]%12==tom%12){
				if(maiormenor==1){
					notas.SetPitch(acorde[i]);
					notas.SetStart((k-1)*2);
					acordes.AddNote(notas);
					notas.SetPitch(acorde[i]+4);
					notas.SetStart((k-1)*2);
					acordes.AddNote(notas);
					notas.SetPitch(acorde[i]+7);
					notas.SetStart((k-1)*2);
					acordes.AddNote(notas);
				}else{
					notas.SetPitch(acorde[i]);
					notas.SetStart((k-1)*2);
					acordes.AddNote(notas);
					notas.SetPitch(acorde[i]+3);
					notas.SetStart((k-1)*2);
					acordes.AddNote(notas);
					notas.SetPitch(acorde[i]+7);
					notas.SetStart((k-1)*2);
					acordes.AddNote(notas);
				}	
				break;
			}	
		}
	}
	if(parteA==1)
		cout << "\nParte A finalizada!\n";
	else
		cout << "\nParte B finalizada!\n";
	getchar();
	getchar();
	return acordes;
}

int * vet_graus(int tom, int maiormenor){
	int graus[7], *vetor=new int[7];
	
	if(maiormenor==1){
		graus[0] = tom;
		graus[1] = tom+2;
		graus[2] = tom+4;
		graus[3] = tom+5;
		graus[4] = tom+7;
		graus[5] = tom+9;
		graus[6] = tom+11;
	}else{
		graus[0] = tom;
		graus[1] = tom+2;
		graus[2] = tom+3;
		graus[3] = tom+5;
		graus[4] = tom+7;
		graus[5] = tom+8;
		graus[6] = tom+10;
	}
	
		for(int i=0;i<7;i++)
			vetor[i] = graus[i];
	return vetor;
}
void show_tom(int tom, int maiormenor){

	if(tom==0){
		if(maiormenor==1)
			cout << "C";
		else
			cout << "Cm";
	}
	if(tom==1){
		if(maiormenor==1)
			cout << "C#";
		else
			cout << "C#m";
	}
	if(tom==2){
		if(maiormenor==1)
			cout << "D";
		else
			cout << "Dm";
	}
	if(tom==3){
		if(maiormenor==1)
			cout << "D#";
		else
			cout << "D#m";
	}
	if(tom==4){
		if(maiormenor==1)
			cout << "E";
		else
			cout << "Em";
	}
	if(tom==5){
		if(maiormenor==1)
			cout << "F";
		else
			cout << "Fm";
	}
	if(tom==6){
		if(maiormenor==1)
			cout << "F#";
		else
			cout << "F#m";
	}
	if(tom==7){
		if(maiormenor==1)
			cout << "G";
		else
			cout << "Gm";
	}
	if(tom==8){
		if(maiormenor==1)
			cout << "G#";
		else
			cout << "G#m";
	}
	if(tom==9){
		if(maiormenor==1)
			cout << "A";
		else
			cout << "Am";
	}
	if(tom==10){
		if(maiormenor==1)
			cout << "A#";
		else
			cout << "A#m";
	}
	if(tom==11){
		if(maiormenor==1)
			cout << "B";
		else
			cout << "Bm";
	}
}



void Preenche_probPitch(int acordeCompasso,int *probPitch){
	switch(acordeCompasso){ //qual o acorde do compasso
		case 0: 
			probPitch[0] = 4;
			probPitch[2] = 4;
			probPitch[4] = 4;
			probPitch[1] = 3;
			probPitch[5] = 3;
			probPitch[0+7] = 4;
			probPitch[2+7] = 4;
			probPitch[1+7] = 3;	
			break;
		case 1: 
			probPitch[1] = 4;
			probPitch[3] = 4;
			probPitch[5] = 4;
			probPitch[2] = 3;
			probPitch[4] = 3;
			probPitch[0] = 3;
			probPitch[1+7] = 4;
			probPitch[2+7] = 3;
			probPitch[0+7] = 3;
			break;
		case 2: 
			probPitch[2] = 4;
			probPitch[4] = 4;
			probPitch[6] = 4;
			probPitch[1] = 3;
			probPitch[5] = 3;
			probPitch[2+7] = 4;		
			probPitch[1+7] = 3;	
			break;

		case 3:
			probPitch[3] = 4;
			probPitch[5] = 4;
			probPitch[0] = 4;
			probPitch[4] = 3;
			probPitch[6] = 1;
			probPitch[1] = 1;
			probPitch[0+7] = 4;
			probPitch[1+7] = 1;
			break;
		case 4: 
			probPitch[4] = 4;
			probPitch[6] = 4;
			probPitch[1] = 4;
			probPitch[3] = 3;
			probPitch[5] = 3;
			probPitch[2] = 3;
			probPitch[1+7] = 4;
			probPitch[2+7] = 3;
			break;

		case 5:
			probPitch[5] = 4;
			probPitch[0] = 4;
			probPitch[2] = 4;
			probPitch[4] = 3;
			probPitch[6] = 3;
			probPitch[1] = 3;
			probPitch[0+7] = 4;
			probPitch[2+7] = 4;
			probPitch[1+7] = 3;
			break;

		case 6: 
			probPitch[6] = 4;
			probPitch[1] = 4;
			probPitch[3] = 4;
			probPitch[5] = 3;
			probPitch[2] = 3;
			probPitch[4] = 3;
			probPitch[1+7] = 4;
			probPitch[2+7] = 3;
			break;
	}
}


/*--------------------melhor sorteio pitc de acordo com a nota anterior------------------------*/
void melhora_pitch_prob(int probPitch[], int notant, int notas[]){ //
	int *probPitch2;
	probPitch2=probPitch;
	for(int i=0;i<10;i++){
		if(notant-notas[i]==1||notant-notas[i]==-1||notant-notas[i]==2||notant-notas[i]==-2){ //se intervalo for 2M ou 2m
			if(probPitch[i]!=0&&probPitch[i]!=1){ //se for diferente de evitada e prob2
				if(probPitch[i]==4) //se for estrutural
					probPitch2[i]+=25;
				if(probPitch[i]==3) //se for tensao
					probPitch2[i]+=19;
			}
		}
		if(notant-notas[i]==3||notant-notas[i]==-3||notant-notas[i]==4||notant-notas[i]==-4){//se intervalo for 3M ou 3m
			if(probPitch[i]!=0&&probPitch[i]!=1){ //se for diferente de evitada e prob2
				if(probPitch[i]==4) //se for estrutural
					probPitch2[i]+=10;
				if(probPitch[i]==3) //se for tensao
					probPitch2[i]+=8;
	
			}
		}	
		if(notant-notas[i]>6||notant-notas[i]<-6){ //se intervalo for maior que uma 4
			if(probPitch[i]=!0)			
				probPitch2[i]=1;
		}		
	}
	
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
MuMaterial mat_acorde(MuMaterial acorde, int compasso){ //retorna material contendo todas as notas de um compasso
	MuMaterial auxiliar, auxiliar2;
	auxiliar=acorde.GetNotesStartingAt(0, compasso);
	auxiliar2+=auxiliar.GetNote(0,0);
	auxiliar2+=auxiliar.GetNote(0,1);
	auxiliar2+=auxiliar.GetNote(0,2);
	return auxiliar2;
}



/*---------------------sorteia nota qualquer--------------------------------*/
short SorteiaPitch(int pitches[], int *probPitch) {
	int i, j, prob, ultimaparada = 0;

	int vetorzao[100]; //vetor que contera todos as notas, com suas tendencias
	for (i=0;i<10;i++){
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


/*-----------------------------sorteia nota estrutural---------------------------------*/
short estrutural(int notas[], MuMaterial auxiliar, int ant){
	short nota, notaf;
	int x, y;
	MuNote notasorteada;
	if(ant==-1){ //se for a primeira nota da melodia apenas sorteia uma
		notasorteada = auxiliar.GetNote(0, Between(0,auxiliar.NumberOfNotes()-1));
		for(int a=0; a<10;a++){
			if(notasorteada.Pitch()%12==notas[a]%12)
				return notas[a]; 
		}		
		return notasorteada.Pitch(); //se for acidente
	}else{
		nota=-1; //ver se nao tem acidente
		for(int a=0; a<10;a++){
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
			for(int a=0; a<10;a++){
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
	for (int i =0; i<10;i++)
		probPitch[i] = 0; 
}

void cria_oito_compassos(MuMaterial* oitocomp, MuMaterial afinal, int* inf_acorde, int* melodia, int* compassos, int num_oitos){
	int contador, sorteio, ant=-1, numB;
	int probPitch[10], probPitch2[10];
	int i, j, y, k;
	MuMaterial auxiliar;
	MuNote nota;

	numB = num_oitos;
	if(num_oitos >= 8) numB = num_oitos - 8;

	int regrinhas[8][3] = 
	{{0, 2, 4}, {-666,-666,-666},
	 {1, 7, -666}, {0, 1, -666},
	 {5, 4, -666}, {10, 7, -666},
	 {0, 2, -666}, {9, 8, 7}};

	float celulas[11][4]=
	{{0.5, 0, 0, 0},{ 0.25,0.25, 0,0 },
	{0.375, 0.125, 0, 0},{0.125, 0.375, 0, 0},
	{0.165, 0.170, 0.165, },{0.335, 0.165, 0, 0},
	{0.165, 0.335, 0, 0},{0.125,0.125 ,0.125 ,0.125 },
	{0.250, 0.125, 0.125, 0},{0.125, 0.125, 0.250, 0},
	{0.125, 0.250, 0.125, 0}};

	/*
		du 
		du-de
		du-te
		du-tu
		du-da-di
		du-di
		du-da
		du-tu-de-te
		du-de-te
		du-tu-de
		du-tu-te
	*/


	
	for(i = 0; i < 8; i++){ 
		for(int k = 0; k < 4; k++){ 	//for para os 2 segundos inteiros
			contador=0;
			do{
				if(num_oitos < 8)
					sorteio = tempo();
				else
					sorteio = Between(0,10);
			} while(sorteio != regrinhas[numB][0] && sorteio != regrinhas[numB][1] 
			&& sorteio != regrinhas[numB][2]);

			for(int y = 0; y < 4; y++){ //inicia contador apenas para encontrar o indice da matriz tempo
				if(celulas[sorteio][y]	!=	0)
					contador++;
				}

				for(int j = 0; j < contador; j++){ //for para gerar cada nota em cada 0,5s
					nota.SetAmp(0.7);
					nota.SetDur(celulas[sorteio][j]);
					auxiliar = mat_acorde(afinal, compassos[i]);
					Zera_probPitch(probPitch);
					Preenche_probPitch(inf_acorde[i],probPitch);
					if(ant!=-1)
						melhora_pitch_prob(probPitch, ant, melodia); //melhora probPitch baseado na nota anterior (saltos)

					for(int g =0;g<10;g++)
						probPitch2[g] = probPitch[g]; //pitch2 é o pitc melhorado
					
					if(ant!=-1)
						nota.SetPitch(SorteiaPitch(melodia, probPitch2));
					else
						nota.SetPitch(estrutural(melodia,auxiliar,-1));
					
					*oitocomp += nota;
					ant = nota.Pitch();
				}
		}
	}

}
