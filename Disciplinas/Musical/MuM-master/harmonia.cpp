#include "MuMaterial.h"
#include <stdio.h>
using namespace std;
#define PATH "/root/Documentos/UnB/Disciplinas/Musical/MuM-master/"
void EscolheHarmonia(int numerocompassos, int acordeescolhido[], MuMaterial compassos);
int main (){
	
MuInit();
MuMaterial melodia, harmonia, triadC, compassos;
float tempototal;
int i=0, numerocompassos; //numerocompassos eh o numero de compassos que a melodia possui, assim sabemos quantas notas usaremos na harmonizacao


melodia.LoadScore((string) PATH + "melodia1.sco");
tempototal = melodia.Dur();
numerocompassos = tempototal/2;
cout << tempototal << endl;
cout << numerocompassos;

compassos = melodia.Segments(numerocompassos);

/*
 * pegar as notas de cada compasso e ver em quais acordes elas aparecem mais, pontuando eles.
 * primeira nota do compasso (tempo forte) da 2 pontos qdo aparecer
 * 
 * 
 * 
 * 
 * */
int acordeescolhido[numerocompassos];

//Função que escolhe acordes e coloca no vetor acordeescolhido
EscolheHarmonia(numerocompassos, acordeescolhido, compassos);

for (i=0;i<numerocompassos;i++){
	triadC.Clear();
	triadC.MajorTriad(1, 2); //triade de do maior
	triadC.SetInstrument(1,2);
	triadC.SetAmp(1,0.2);
	switch(acordeescolhido[i]){
		case 0:
			harmonia += triadC;
			break;
		case 1:
			triadC.DiatonicTranspose(0, MAJOR_MODE, 2, ASCENDING);
			harmonia += triadC;
			break;
		case 2:
			triadC.DiatonicTranspose(0, MAJOR_MODE, 4, ASCENDING);
			harmonia += triadC;
			break;
		case 3:
			triadC.DiatonicTranspose(0, MAJOR_MODE, 5, ASCENDING);
			harmonia += triadC;
			break;
		case 4:
			triadC.DiatonicTranspose(0, MAJOR_MODE, 7, ASCENDING);
			harmonia += triadC;
			break;
		case 5:
			triadC.DiatonicTranspose(0, MAJOR_MODE, 9, ASCENDING);
			harmonia += triadC;
			break;
		case 6:
			triadC.DiatonicTranspose(0, MAJOR_MODE, 11, ASCENDING);
			harmonia += triadC;
			break;	
	}
}	


harmonia.Mix(1,melodia,0);
harmonia.Show();
harmonia.PlaybackWithCsound((string) PATH + "teste");
harmonia.SetDefaultFunctionTables();
	harmonia.Orchestra((string) PATH + "Saida");
	harmonia.Score((string) PATH + "Saida");
return 0;

}


void EscolheHarmonia(int numerocompassos, int acordeescolhido[], MuMaterial compassos){
int i;
int acordes [7][3] = {
	{60, 64, 67},
	{62, 65, 69},
	{64, 67, 71},
	{65, 69, 72},
	{67, 71, 74},
	{69, 72, 76},
	{71, 74, 77},
	};
	
for (i=0;i<numerocompassos;i++){
	MuMaterial temp;
	MuNote notatmp;
	int numeroTotal = compassos.NumberOfNotes(i);
	int j,k, notas[numeroTotal], score[7]={0,0,0,0,0,0,0}, max, iguais[7] = {0,0,0,0,0,0};
	
	
	for (j=0;j<numeroTotal;j++){
		notatmp = compassos.GetNote(j);
		notas[j] = notatmp.Pitch();
	}
	
	for (j=0;j<7;j++){	
		for (k=0;k<numeroTotal;k++){			
			for (int l=0; l<3;l++){	
				if ((acordes[j][l])%12 == (notas[k])%12){
					if(k==0)
					score[j]=score[j]+2;
					else
					score[j]++;	
				}
			}
		}
	}
	
	max = 0;
	for (j=0;j<7;j++){
		if(score[j] > score[max])
			max = j;
	}
	
	int flagiguais = 0;
	k=0;
	
	cout << endl << "VETOR SCORE: ";
	for (j=0;j<7;j++){
		cout << score[j] << " ";
		if(score[max] == score[j]){
			iguais[k] = j;
			flagiguais++;
			k++;
		}
	}
	
	if (flagiguais == 0)
		acordeescolhido[i] = max;
	
	else
		acordeescolhido[i] = iguais[Between(0,flagiguais)];			
	
	cout << "FLAG IGUAIS " << flagiguais;
	cout << endl<< "ACORDE ESCOLHIDO " << acordeescolhido[i];
	
}

}
