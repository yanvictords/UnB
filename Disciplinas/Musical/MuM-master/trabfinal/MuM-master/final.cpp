#include <iostream>
#include "MuMaterial.h"
#include "CaMaterial.h"
using namespace std;

int * vet_graus(int tom, int maiormenor);
void show_tom(int tom, int maiormenor);

int main(void){
	MuInit();
	int tom, maiormenor, *graus, acorde[18], nota=-1, mostra[7];
	MuMaterial acordes, afinal;
	MuNote notas;
	acordes.SetInstrument(0,1);
	system("clear");
	for(int i=0; i<18;i++)
		acorde[i]=i+48;
	cout << "*************** BEM VINDOS À MUM-MASTER ***************\n"<< endl;

	cout << "~~ Escolha o tom ~~" << endl;
	cout << "0. C\n1. C#\n2. D\n3. D#\n4. E\n5. F\n6. F#\n7. G\n8. G#\n9. A\n10. A#\n11. B " << endl << endl;
	cout << "Digite o Tom:";
	cin >> tom;
	
	while(tom<0||tom>11){
		cout << "Tom incorreto! Digite novamente: ";
		cin >> tom;
	}
	
	system("clear");
	cout << "~~ Selecione uma opcao ~~\n";
	cout << "1. Tonalidade Maior\n2. Tonalidade Menor\n";
	cout << "Digite um valor: ";
	cin >> maiormenor; 
	while(maiormenor<1||maiormenor>2){
		cout << "Tonalidade incorreta! Digite novamente: ";
		cin >> maiormenor;
	}
	graus = vet_graus(tom, maiormenor);
	cout << graus << endl;
	notas.SetDur(2.0);
	notas.SetAmp(0.5);
	
	for(int k =0;k<8;k++){
		system("clear");
		cout << "******** Seleção de Acordes ********\n\n";
		show_tom(tom, maiormenor);
		cout << "\nAcordes escolhidos: ";
		for(int x=0; x<k;x++)
			cout <<"|"<< mostra[x] <<"| ";
		cout << "\n--------------Selecione um dos acordes abaixo---------------" << endl;
		cout << "Digite: '1' '2' '3' '4' '5' '6' '7' para escolher o acorde correspondente, abaixo...\n"; 
		for(int x = 0;x<7;x++)
			cout << "|" << graus[x]%12 << "|";
		cout << "\nEntre com um acorde: " ;
		cin >> nota;
		while(nota<1||nota>7){
			cout << "\nAcorde incorreto! Digite novamente: " ;
			cin >> nota;
		}
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
					if(nota==3||nota==4||nota==7)
						notas.SetPitch(acorde[i]+4);
					else
						notas.SetPitch(acorde[i]+3);
					notas.SetStart(k*2);
					acordes.AddNote(notas);		
					if(nota==1)
						notas.SetPitch(acorde[i]+12);
					else
						notas.SetPitch(acorde[i]+7);
					notas.SetStart(k*2);
					acordes.AddNote(notas);
				}
				break;
			}
		}
	}

	for(int i=0;i<10;i++)
		afinal+=acordes;
	afinal.SetInstrument(0,1);
	afinal.Show();
	afinal.PlaybackWithCsound("/home/baragund/Google Drive/Profissional/Engenharia da Computação/2016.1/Composição Algoritmica/Programações/Trabalho FInal/MuM-master/teste");
	afinal.SetDefaultFunctionTables();
	afinal.Score("/home/baragund/Google Drive/Profissional/Engenharia da Computação/2016.1/Composição Algoritmica/Programações/Trabalho FInal/MuM-master/Saida");
	afinal.Orchestra("/home/baragund/Google Drive/Profissional/Engenharia da Computação/2016.1/Composição Algoritmica/Programações/Trabalho FInal/MuM-master/Saida");



return 0;
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
			cout << "Tom escolhido: C\n";
		else
			cout << "Tom escolhido: Cm\n";
	}
	if(tom==1){
		if(maiormenor==1)
			cout << "Tom escolhido: C#\n";
		else
			cout << "Tom escolhido: C#m\n";
	}
	if(tom==2){
		if(maiormenor==1)
			cout << "Tom escolhido: D\n";
		else
			cout << "Tom escolhido: Dm\n";
	}
	if(tom==3){
		if(maiormenor==1)
			cout << "Tom escolhido: D#\n";
		else
			cout << "Tom escolhido: D#m\n";
	}
	if(tom==4){
		if(maiormenor==1)
			cout << "Tom escolhido: E\n";
		else
			cout << "Tom escolhido: Em\n";
	}
	if(tom==5){
		if(maiormenor==1)
			cout << "Tom escolhido: F\n";
		else
			cout << "Tom escolhido: Fm\n";
	}
	if(tom==6){
		if(maiormenor==1)
			cout << "Tom escolhido: F#\n";
		else
			cout << "Tom escolhido: F#m\n";
	}
	if(tom==7){
		if(maiormenor==1)
			cout << "Tom escolhido: G\n";
		else
			cout << "Tom escolhido: Gm\n";
	}
	if(tom==8){
		if(maiormenor==1)
			cout << "Tom escolhido: G#\n";
		else
			cout << "Tom escolhido: G#m\n";
	}
	if(tom==9){
		if(maiormenor==1)
			cout << "Tom escolhido: A\n";
		else
			cout << "Tom escolhido: Am\n";
	}
	if(tom==10){
		if(maiormenor==1)
			cout << "Tom escolhido: A#\n";
		else
			cout << "Tom escolhido: A#m\n";
	}
	if(tom==11){
		if(maiormenor==1)
			cout << "Tom escolhido: B\n";
		else
			cout << "Tom escolhido: Bm\n";
	}
}
