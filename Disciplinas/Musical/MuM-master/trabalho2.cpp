#include <iostream>
#include "MuMaterial.h"

using namespace std;

//Constantes
const int MAX_MOTIF	=	20;
const int MENOR2	=	1; // SEGUNDA MENOR
const int MAIOR2	=	2; // SEGUNDA MAIOR
const int MENOR3	=	3; // TERÇA MENOR
const int MAIOR3	=	4; // TERÇA MAIOR
const int JUSTA4	=	5; // QUINTA JUSTA
const int JUSTA5	=	7; // QUINTA JUSTA
const int MENOR6	=	8; // SEXTA MENOR
const int MAIOR6	=	9; // SEXTA MAIOR
const int MENOR7	=	10; // SEXTA MENOR
const int MAIOR7	=	11; // SEXTA MAIOR
const int OITAVA	=	12; // OITAVA

//Funcoes extras
/*void setEscalaNat(MuMaterial* pmat, int escalaD);	/* Converte o material para a escala desejada. 1 a 12 para Dó a Si Maior. 13 a 24 
para Dó a Si Menor  

int cmpfunc(const void* a, const void *); //Função para auxiliar o qsort usado em outras funções.

MuNote setProxMel(MuMaterial* pmat, int ind, int voz);/* Verifica na voz escolhida, a nota anterior ao índice
 colocado para decidir a próxima nota.		
MuNote setProxHar(MuMaterial* pmat, int ind, int voz1, int voz2);/*Retorna a ṕróxima nota que pode ser adicionada 
ao à segunda voz em relação a primeira voz

MuNote setProxRep(MuMaterial* pmat,int ind, int voz1, int voz2); /*Rertona a próxima nota que pode ser adicionada 
em relação à repetição de notas na própria voz. */
 /*-------------------------------------------*/
 /*---------FIM DAS FUNÇOES EXTRAS------------*/
 /*-------------------------------------------*/


// FUNCOES PRINCIPAIS --------------


// 1) A FUNCAO ABAIXO DEFINE SE PODE OU NAO USAR TAL NOTA, USANDO AS REGRAS DO CONTRA PONTO. A ESCOLHA DOS SALTOS E FEITA PELA FUNCAO DEFINE_SALTOS. TAMBEM CHAMA A FUNCAO FLAGS(). CASO POSSA, ELE RETORNA O PITCH PRA MAIN, E INSERE NO CONTRAPONTO.
short contrapt(MuNote nota, int *flag8, int *flag5, int *flag3, int *flag6, int intervalo, MuNote anterior); //+IMPORTANTE

/* 2) ESTA FUNÇAO DEFINE TODAS AS FLAGS PARA EVITAR REPETICOES DE 5ª e 8ª e 3x DE 3ª E 6ª DURANTE O SALTO DAS NOTAS NO CONTRAPONTO. (flag8 e flag5 evitam oitavas e quintas paralelas. flag3 e flag6 evitam + de tres 3ªs e 6ªs). FORNECE PARA CONTRAPT()*/
void flags(int *flag8, int *flag5, int *flag3, int *flag6, int caso); //AUXILIAR

// 3) ESTA FUNÇAO DEFINE OS CASOS PARA CADA SALTO SORTEADO, DANDO PREFERENCIA PARA OS MENORES. CHAMA SORTEIA(), CONSONANTE(), E RETORNA PARA CONTRAPT() E MAIN()
int define_saltos(MuNote anterior, MuNote nota); //+IMPORTANTE

// 4) ESTA FUNÇAO SORTEIA CASES PARA DEFINE_SALTOS(), PREFERINDO MENORES SALTOS
int sorteia();  //AUXILIAR

// 5) ESTA FUNÇAO VERIFICA SE A NOTA SORTEADA RESULTANTE DO SALTO É CONSONANTE COM A NOTA DO CANTUS FIRMUS. SE NAO FOR, SORTEIA OUTRA
int consonante(int valor, MuNote nota); //AUXILIAR


// 6) COLOCA A PENULTIMA NOTA DO CP
void penultima(MuNote *nota, MuNote tonicacp, MuNote tonicacf);
// 7) COLOCA A ULTIMA NOTA DO CP
void tonica(MuNote *nota, MuNote tonicacf);

/*---------------------------------------------------------------------------------*/
/*--------------------------INICIO FUNÇÃO PRINCIPAL--------------------------------*/
/*---------------------------------------------------------------------------------*/
int main(void)
{
	MuInit();
	MuMaterial cantusfirmus, contraponto, materialfinal; //Construcao do motivo, material final e material auxiliar
	MuNote nota, tonicacp, tonicacf, anterior;
	int j, flag8=0, flag5=0, flag3=0, flag6=0, intervalo;

	cantusfirmus.LoadScore("/home/yan/Documentos/Musical/MuM-master/cantusfirmus.sco");
	//cantusfirmus.PlaybackWithCsound("/home/yan/Documentos/Musical/MuM-master/teste1");	
	cantusfirmus.SetInstrument(0,2);
	contraponto.SetInstrument(0,2);
/*--------------------------FIM DA CONSTRUCAO DO MOTIVO---------------------------------------*/
	nota.SetInstr(1); //fixo
	nota.SetAmp(0.7); //fixo
	nota.SetDur(1); //fixo
	tonicacf =cantusfirmus.GetNote(0, 0); //pegando a tonica do cf
	cout << "--------------------------------" << endl;
	cout << "NOTA TONICA DO CANTUSFIRMUS: " << tonicacf.Pitch() << endl;
	cout << "---------------" << endl;
/*---------------------------------*/
for(int j=0; j<cantusfirmus.NumberOfNotes()-1 ; j++){ //Enquanto j < (numero de compasso do CantusFirmus -1) para inserir a tonica no fim do contraponto
	nota.SetStart(j);
	nota = cantusfirmus.GetNote(0, j);
// NOTA = CADA NOTA INSTANTANEA DO CANTUS FIRMUS

	cout << "->CF: " << nota.Pitch()<< endl;
	if((j>0)&&(j<cantusfirmus.NumberOfNotes()-2)){ // NOTAS ALEATORIAS ENTRE A PRIMEIRA E A PENULTIMA NOTA DO CONTRA PONTO	
		intervalo = define_saltos(anterior,nota);
		nota.SetPitch(contrapt(nota, &flag8, &flag5, &flag3, &flag6, intervalo, anterior));
		anterior = nota;
	}
		//setProxMel(&contraponto, j,0);
	if(j==0){ // CRIACAO DA NOTA TONICA
		tonica(&nota, tonicacf);
		tonicacp = nota;
		anterior = tonicacp;
	}
	if(j==cantusfirmus.NumberOfNotes()-2)  // CRIACAO DA PENULTIMA NOTA COMO SENDO A SENSIVEL
		penultima(&nota, tonicacp, tonicacf);	
	cout << "---------------" << endl;
	contraponto+=nota;
}
/*---------------------------------*/
	contraponto+=tonicacp; // inserindo a tonica no fim do contraponto
	nota = cantusfirmus.GetNote(0, cantusfirmus.NumberOfNotes()-1); // PEGANDO A ULTIMA NOTA DO CONTRA PONTO
	cout << "->CF: " << nota.Pitch()<< endl;
	cout << "CP: " << tonicacp.Pitch()<< endl;
	cout << "---------------" << endl;
	cout << "NOTA TONICA DO CONTRAPONTO: " << tonicacp.Pitch() << endl;
	cout << "--------------------------------" << endl;

// A FUNCAO SETVOICE ABAIXO COPIA A VOZ 0 DO CONTRAPONTO, PARA A VOZ 1 DO CANTUSFIRMUS, FICANDO EM UM SO MATERIAL
	cantusfirmus.SetVoice(1, contraponto, 0);
	cantusfirmus.SetInstrument(1,2);
	materialfinal = cantusfirmus; // MATERIAL FINAL CRIADO
	materialfinal.Show();
	materialfinal.PlaybackWithCsound("/home/yan/Documentos/Musical/MuM-master/teste");
	materialfinal.SetDefaultFunctionTables();
	materialfinal.Score("/home/yan/Documentos/Musical/MuM-master/Saida");
	materialfinal.Orchestra("/home/yan/Documentos/Musical/MuM-master/Saida");


	return 0;	

}

/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
void flags(int *flag8, int *flag5, int *flag3, int *flag6, int caso){ /*DEFINE TODAS AS FLAGS PARA EVITAR REPETICOES DE 5ª, 8ª E 3VEZES DE 3ª E 6ª. (flag8 e flag5 evitam oitavas e quintas paralelas. flag3 e flag6 evitam + de tres 3ªs e 6ªs)*/

	switch(caso){
	case 0:  //CASO PARA EVITAR QUE 3ªS APAREÇAM 3X CONSECUTIVAS. FLAG3 SOMA ATÉ CONTAR 3, E EVITA UMA 4X
		*flag3=*flag3+1;
		*flag5=0;
		*flag8=0;
		*flag6=0;
		break;
	case 1: //EVITA QUE QUINTAS APAREÇAM 2X CONSECUTIVAS
		*flag5=1;
		*flag8=0;
		*flag3=0;
		*flag6=0;
		break;
	case 2: //CASO PARA EVITAR QUE 6ªS APAREÇAM 3X CONSECUTIVAS. FLAG6 SOMA ATÉ CONTAR 3, E EVITA UMA 4X
		*flag6=*flag6+1;
		*flag5=0;
		*flag8=0;
		*flag3=0;
		break;
	case 3: //EVITA QUE OITAVAS APAREÇAM 2X CONSECUTIVAS
		*flag8=1;
		*flag5=0;
		*flag3=0;
		*flag6=0;
		break;
/*ATENCAOO: E NECESSARIO QUE OS OUTROS ESTEJAM ' = 0 '. POR EXEMPLO: SE O CASO 0 SE REPETIR 3X, E NA QUARTA VIER OUTRO CASO, O CASO 0 PODERA APARECER NOVAMENTE APOS OUTRO CASO. EX: 3M 3M 3M '5J' 3M 3M ...etc E PARA ISSO É NECESSARIO ZERAR ELE TODA VEZ QUE APARECER OUTRO CASO*/
	}
}
/*---------------------------------------------------------------------------------*/
/*------------------------------SORTEIA O SALTO-------------------------------------*/
/*---------------------------------------------------------------------------------*/
int sorteia(){ // ESTA FUNÇAO SORTEIA DANDO PRIORIDADE PARA OS MENORES SALTOS
	int x, salto;
	x = Between(0,5); // SORTEIA OS CASES
	if(x==0){
		salto = 0; // SALTO DE SEGUNDA 
			
	}else{ 
		if(x==1){ // SALTO DE TERCEIRA
			salto = Between(0,1);
		}else{

			if(x==2){ // SALTO DE QUARTA 
				salto = Between(0,2);
			}else{
				if(x==3){ // ETC
					salto = Between(0,3);	
				}else{
						salto = Between(0,5);	
				}
			}
		}		
	}
	return salto; // RETORNA O CASE
}
/*---------------------------------------------------------------------------------*/
/*-------------------------------VERIFICA CONSONANTE----------------------------------*/
/*---------------------------------------------------------------------------------*/

int consonante(int valor, MuNote nota){ // ESTA FUNÇAO VERIFICA SE A NOTA SORTEADA PELO SALTO É CONSONANTE COM A NOTA DO CANTUS FIRMUS
	int intervalo = -1;
		if((valor+7) == nota.Pitch()) // QUINTA JUSTA
			intervalo = 1;
		if((valor+12)== nota.Pitch()) // OITAVA
			intervalo = 3;
		if(((valor + 12 - nota.Pitch()) == 3) || ((valor + 12 - nota.Pitch()) == 4)) // TERÇA MENOR OU MAIOR
			intervalo = 0;
		if(((valor + 12 - nota.Pitch()) == 8) || ((valor + 12 - nota.Pitch()) == 9)) // SEXTA MENOR OU MAIOR
			intervalo = 2;
		if(intervalo!=-1)
			return intervalo; // SE SOAR CONSONANTE RETORNA ELA, SENAO
return -1; // RETORNA -1 PARA INDICAR QUE ESSA NOTA NAO PODE SER INSERIDA, POIS FICA DISSONANTE
}

/*---------------------------------------------------------------------------------*/
/*--------------------------- DEFINE SALTOS ---------------------------------------*/
/*---------------------------------------------------------------------------------*/
int define_saltos(MuNote anterior, MuNote nota){ // ESTA FUNÇAO DEFINE OS CASOS PARA CADA SALTO SORTEADO, DANDO PREFERENCIA PARA OS MENORES
	int x=0, aviso=0, intervalo=-1, valor=0, flag=0, sortear;
	int caso0=0, caso1=0, caso2=0, caso3=0, caso4=0, caso5=0;

//CASO0, CASO1, CASO2, CASO3, CASO4, CASO5 SAO FLAGS QUE INDICAM SE AQUELE CASO PODE OU NAO SER ESCOLHIDO. 0 PODE, 1 NAO PODE
//'AVISO' INDICA SE JA ENTROU NO MAIOR OU MENOR, CASO NAO SEJA INTERVALO MAIOR, OBRIGA A ENTRAR NO MENOR ANTES DE TENTAR IR PARA OUTROS CASES...
// 'VALOR' SERA O VALOR DO PITCH SORTEADO PARA SOAR CONTRA A DO CF
// INTERVALO SERA RETORNADO PARA A FUNÇAO CONTRAPT INFORMANDO QUAL CASE ELE DEVERA ENTRAR (CADA CASE É UM INTERVALO)
// FLAG INDICA SE JA USOU O 'IF' E 'ELSE' ANTES DE IR PARA OUTRO CASO
// SORTEAR É INTERVALO SORTEADO, COM PREFERENCIA PARA SALTOS DE GRAU CONJUNTO



/*ANTES DE TUDO ESSA FUNCAO SORTEIA O SALTO DANDO PREFERENCIA PARA GRAUS CONJUNTOS, E DECIDE SE ELE VAI SOMAR OU SUBTRAIR COM A NOTA ANTERIOR DO CONTRAPONTO. CASO A 'SOMA' NAO DE EM UMA NOTA CONSONANTE COM O CF, ELE TENTA 'SUBTRAIR' NO MESMO CASE E VERIFICA SE É CONSONANTE COM O CF. SE FOR, ELE RETORNA DIRETO ESSE PITCH. SE NAO FOR, ELE ENTRA EM OUTRO CASE SORTEADO PARA FAZER AS MESMAS VERIFICAÇOES. ESTA FUNCAO RETORNA O CASO QUE A FUNCAO CONTRAPT DEVERA USAR PARA INSERIR A NOTA NO MATERIAL DO CONTRAPONTO.*/




	while(((x<6)&&(valor==0))||(intervalo==-1)){ 
// X<6 PARA CONTROLE DE EVITAR LOOPS INFINITOS. GARANTE QUE ELE NAO FARÁ REDUNDÂNCIAS, ENTRARÁ 1 OU 2X APENAS EM CADA CASO, SEM REPETIR O 'IF' E 'ELSE'
		sortear = sorteia(); //sorteia o caso usando preferencia


		while(((sortear==0)&&(caso0==1))||((sortear==1)&&(caso1==1))||((sortear==2)&&(caso2==1))||((sortear==3)&&(caso3==1))||((sortear==4)&&(caso4==1))||((sortear==5)&&(caso5==1))){ //ESSE WHILE EVITA QUE ALGUM CASO SEJA REPETIDO DESNECESSARIAMENTE
		sortear = sorteia(); //sorteia novamente caso o caso seja repetido desnecessariamente
			if((caso0==1)&&(caso1==1)&&(caso2==1)&&(caso3==1)&&(caso4==1)&&(caso5==1)) //CASO OCORRA DE NENHUM INTERVALO FOR CONSONANTE, PELO SORTEIO, ELE SORTEIA DIRETAMENTE E RETORNA EVITANDO ENTRAR EM LOOP INFINITO
				return Between(0,3);
		}


		if(flag==0){ // if para indicar que ja pode mudar de caso
			aviso = Between(0,1);
			
		}else{ 
// else indica que o caso nao podera mudar ainda , apenas o valor do 'aviso' sera invertido para ele trocar o 'IF' 'ELSE' NO MESMO CASO
			if(aviso==0){
				aviso=1;
			}else{
				aviso=0;
			}
		}
/*--------------------------------------------*/
		switch(sortear){ 	
			case 0: // SALTO DE 2ª MENOR OU MAIOR
				if(aviso==0){  //indica se vai ser + ou -
					valor = anterior.Pitch() - MAIOR2; 
//O IF ABAIXO VERIFICA SE O INTERVALO MAIOR2 CAUSA ACIDENTES OU NAO DEPOIS DE OPERAR COM A NOTA ANTERIOR DO CP
					if((valor%12 == 0)||(valor%12 == 2)||(valor%12 == 4)||(valor%12 == 5)||(valor%12 == 7)||(valor%12 == 9)||(valor%12 == 11)){			
						if((anterior.Pitch() - MAIOR2)>54){ // >54 DEFINE LIMITES PARA CONTRALTO
							valor = anterior.Pitch() - MAIOR2; 
							intervalo = consonante(valor, nota);

							flag++;   //SE ELE JA TIVER ENTRADO NO ELSE ABAIXO, E AGORA ELE SOMAR+1, INDICA QUE ELE NAO ENTRARA MAIS NO CASO 0 E ELE DEVE MUDAR DE CASO, SE O INTERVALO ENCONTRADO PARA SALTO DE 2ª NAO FOR CONSONANTE NEM EM 2M NEM EM 2m. SE O INTERVALO ENCONTRADO FOR SUFICIENTE, ELE NAO CHEGA NEM A ENTRAR NOS OUTROS CASOS, POIS O SALTO DE 2ª É O PREFERIDO

							if(flag==2){ 
//INDICA QUE ELE ENTROU NO IF E ELSE, SE FOR = 2 ENTAO MUDA O CASO OU RETORNA O INTERVALO PARA A FUNCAO CONTRAPT
								flag=0; //INDICA PARA O IF ACIMA DO WHILE(sorteio), QUE DEVE MUDAR O CASO
								caso0=1; // INDICA QUE O CASO 0 NAO PODE SER USADO
							}
						}else {
//TODO O RESTO ABAIXO SEGUE A MESMA LOGICA DA EXPLICAÇAO ACIMA
							flag++; 
							if(flag==2) {
								flag=0;
								caso0=1;
							}
							valor =0;
						}
					}else{ //usando menor2 agora, caso o maior2 cause acidentes
						if((anterior.Pitch() - MENOR2)>54){
							valor = anterior.Pitch() - MENOR2; 
							intervalo = consonante(valor, nota);
							flag++; 
							if(flag==2){ 
								flag=0;
								caso0=1;
							}
						}else {
							flag++;
							if(flag==2){
								flag=0; 
								caso0=1;
							}
							valor = 0;
						}
					}
				}else{ // ESTE É O ELSE PRINCIPAL, QUE SEPARA A OPERACAO DE SOMA E SUBTRAÇAO
					valor = anterior.Pitch() + MAIOR2;
					if((valor%12 == 0)||(valor%12 == 2)||(valor%12 == 4)||(valor%12 == 5)||(valor%12 == 7)||(valor%12 == 9)||(valor%12 == 11)){
						if((anterior.Pitch() + MAIOR2)<73){
							valor = anterior.Pitch() + MAIOR2; 
							intervalo = consonante(valor, nota);
							flag++; 
							if(flag==2){
								flag=0;
								caso0=1;
							}
						}else{
						 	flag++;
							if(flag==2){
								flag=0;
								caso0=1;
							}
							valor = 0;
						}
					}else{
						if((anterior.Pitch() + MENOR2)<73){
							valor = anterior.Pitch() + MENOR2; 
							intervalo = consonante(valor, nota);
							aviso=0;
							flag++; 
							if(flag==2){
								flag=0;
								caso0=1;
							}
							
						}else{
							flag++;  
							if(flag==2){
								flag=0;
								caso0=1;
							}
							aviso=0; 
							valor = 0;
						}
					}
				}
		x++; // X++ PARA EVITAR QUE O WHILE PASSE DE 6X, EVITANDO POSSIVEIS LOOPS INFINITOS
		break;
/*----------------------- SALTO DE 3ª MAIOR OU MENOR ---------------------*/
		case 1: 
			if(aviso == 0){
				valor = anterior.Pitch() - MAIOR3; 
				if((valor%12 == 0)||(valor%12 == 2)||(valor%12 == 4)||(valor%12 == 5)||(valor%12 == 7)||(valor%12 == 9)||(valor%12 == 11)){
					if((anterior.Pitch() - MAIOR3)>54){
						valor = anterior.Pitch() - MAIOR3;
						intervalo = consonante(valor, nota);
						flag++; 
						if(flag==2){
							caso1=1;
							flag=0;
						}
					}else{ 
						flag++; 
						if(flag==2){ 
							caso1=1; 
							flag=0;
						} 
						valor = 0;
					}
				}else{
					if((anterior.Pitch() - MENOR3)>54){
						valor = anterior.Pitch() - MENOR3; 
						intervalo = consonante(valor, nota);
						flag++; 
						if(flag==2){
							caso1=1;
							flag=0;		
						}
					}else{
						flag++; 
						if(flag==2){
							flag=0;
							caso1=1;
						}
						valor =0;
					}
				}
			}else{
				valor = anterior.Pitch() + MAIOR3;
				if((valor%12 == 0)||(valor%12 == 2)||(valor%12 == 4)||(valor%12 == 5)||(valor%12 == 7)||(valor%12 == 9)||(valor%12 == 11)){
					if((anterior.Pitch() + MAIOR3)<73){
						valor = anterior.Pitch() + MAIOR3; 
						intervalo = consonante(valor, nota);
						flag++;
						if(flag==2){
							flag=0;	
							caso1=1;
						}
					}else{
						flag++; 
						if(flag==2){
							flag=0; 
							caso1=1;
						}
						valor = 0;
					}
				}else{	
					if((anterior.Pitch() + MENOR3)<73){
						valor = anterior.Pitch() + MENOR3; 
						intervalo = consonante(valor, nota);
						flag++; 
						if(flag==2){
							flag=0;
							caso1=1;
						}	
					}else{
						flag++; 
						if(flag==2){  
							flag=0;
							caso1=1;
						}
						valor =0;
					}
				}
			}
		x++;
		break;
/*-------------------------SALTO DE 4 JUSTA -------------------*/
		case 2:
			if(aviso==0){
				if((anterior.Pitch() - JUSTA4)>54){
					valor = anterior.Pitch() - JUSTA4; 
					intervalo = consonante(valor, nota);
				}else {
					flag++; 
					if(flag==2){
						flag=0; 
						caso2=1;
					}
					valor =0;
				}
			}else{
				if((anterior.Pitch() + JUSTA4)<73){
					valor = anterior.Pitch() + JUSTA4;
					intervalo = consonante(valor, nota);
					
					flag++; 
					if(flag==2){
						flag=0; 
						caso2=1;
					}
				}else{
					flag++; 
					if(flag==2){
						flag=0; 
						caso2=1;
					}
					valor =0;
				}
			}
		x++;
		break;
/*----------------------- SALTO DE 5 JUSTA ---------------------*/
		case 3:
			if(aviso==0){
				if((anterior.Pitch() - JUSTA5)>54){
					valor = anterior.Pitch() - JUSTA5; 
					intervalo = consonante(valor, nota);
					flag++; 
					if(flag==2){
						flag=0; 
						caso3=1;
					}
				}else{
					flag++; 
					if(flag==2){
						flag=0; 
						caso3=1;
					} 
					valor = 0;
				}
			}else{
				if((anterior.Pitch() + JUSTA5)<73){
					valor = anterior.Pitch() + JUSTA5; 
					intervalo = consonante(valor, nota);
					flag++; 
					if(flag==2){
						flag=0; 
						caso3=1;
					}
				}else{
					flag++; 
					if(flag==2){
						flag=0; 
						caso3=1;
					}
					valor =0;
				}
			}
		x++;
		break;
/*----------------------- SALTO DE 6 MENOR ASCENDENTE ---------------------*/
		case 4: valor = anterior.Pitch() + MENOR6;
			if((valor%12 == 0)||(valor%12 == 2)||(valor%12 == 4)||(valor%12 == 5)||(valor%12 == 7)||(valor%12 == 9)||(valor%12 == 11)){
				if((anterior.Pitch() + MENOR6)<73){
					valor = anterior.Pitch() + MENOR6; 
					intervalo = consonante(valor, nota);
					flag=0;
					caso4=1;
				}else{
					flag = 0; 
					valor =0;
					caso4=1;
				}
			}else{
				caso4=1;
				flag = 0;
				valor = 0;
			}
		x++;
		break;
/*-----------------------SALTO DE OITAVA ---------------------*/
		case 5:
			
			if(aviso==0){
				if((anterior.Pitch() - OITAVA)>54){
					valor = anterior.Pitch() - OITAVA; 
					intervalo = consonante(valor, nota);
					flag++; 
					if(flag==2){
						flag=0; 
						caso5=1;
					}
				}else{
					flag++;  
					if(flag==2){
						flag=0; 
						caso5=1;
					} 
					valor =0;
				}
			}else{
				if((anterior.Pitch() + OITAVA)<73){
					valor = anterior.Pitch() + OITAVA; 
					intervalo = consonante(valor, nota);
					flag++; 
					if(flag==2){
						flag=0; 
						caso5=1;
					}
				}else{
					flag++; 
					if(flag==2){
						flag=0; 
						caso5=1;
					}
					valor = 0;
				}
			}
		x++;
		break;
		}
	}
	return intervalo; 
}
/*---------------------------------------------------------------------------------*/
/*------------------------CRIA CONTRA PONTO---------------------------------------*/
/*---------------------------------------------------------------------------------*/
short contrapt(MuNote nota, int *flag8, int *flag5, int *flag3, int *flag6, int intervalo, MuNote anterior){  //DEFINE SE PODE OU NAO USAR TAL NOTA, USANDO AS REGRAS DO CONTRA PONTO. CASO POSSA, ELE RETORNA O PITCH PRA MAIN, E INSERE NO CONTRAPONTO
	short pitch; 
	switch(intervalo){ // intervalo e o valor retornado da funcao define_saltos

/*--------------------------------------------*/
		case 0:
		if(*flag3<3){ // 6 maior/menor ~~ FLAG3 VERIFICA SE JA NAO TEM 3 SALTOS DE 3ª ANTERIORES, USANDO A FUNCAO FLAGS()
			if((nota.Pitch()%12 == 2)||(nota.Pitch()%12 == 4)||(nota.Pitch()%12 == 9)||(nota.Pitch()%12 == 11)){ //VERIFICA SE VAI USAR NOS CASOS D, E, A e B(3menor)	
			
				pitch =  nota.Pitch()+ MENOR3 -12;
				if(pitch < 55)
					{
					intervalo = define_saltos(anterior,nota);
					pitch = contrapt(nota,flag8, flag5, flag3, flag6, intervalo, anterior);
				}
				cout << "CP 6 MAIOR: " << pitch<< endl;
				flags(flag8, flag5, flag3, flag6, 0); //CASO 0
			}else{ // USA 3ª MAIOR NOS CASOS C, F e G 
				
				pitch =  nota.Pitch()+ MAIOR3 -12;
				cout << "CP 6 MENOR: " << pitch<< endl; 
				if(pitch < 55)
					{
					intervalo = define_saltos(anterior,nota);
					pitch = contrapt(nota,flag8, flag5, flag3, flag6, intervalo, anterior);
				}
				flags(flag8, flag5, flag3, flag6, 0); //CASO 0		
			}
		}else{
			intervalo = define_saltos(anterior,nota);
			pitch = contrapt(nota,flag8, flag5, flag3, flag6, intervalo, anterior);
		}
			break;

/*--------------------------------------------*/

		case 1: // 5 JUSTA 

			if(*flag5==0){   //SE AS NOTAS ANTERIORES DO CP E CF NAO SOAREM EM 'QUINTA'	
				pitch =  nota.Pitch() - 7; 
				if(pitch < 55){
					intervalo = define_saltos(anterior,nota);
					pitch = contrapt(nota,flag8, flag5, flag3, flag6, intervalo, anterior);
				}
				cout << "CP 5JUSTA: " << pitch<< endl;
				flags(flag8, flag5, flag3, flag6, 1); // CASO 1
			}else{intervalo = define_saltos(anterior,nota);
				pitch = contrapt(nota,flag8, flag5, flag3, flag6, intervalo,anterior);
			}			
			break;

/*--------------------------------------------*/

		case 2: // 3 MAIOR/MENOR
		if(*flag6<3){ 
			if((nota.Pitch()%12 == 4)||(nota.Pitch()%12 == 9)||(nota.Pitch()%12 == 11)){ //USA 6ª MENOR PARA O CASOS E A B
				pitch =  nota.Pitch()+ MENOR6 -12;
				if(pitch < 55)	{
					intervalo = define_saltos(anterior,nota);
					pitch = contrapt(nota,flag8, flag5, flag3, flag6, intervalo, anterior);
				}
				flags(flag8, flag5, flag3, flag6, 2); //CASO 2
				cout << "CP 3 MAIOR: " << pitch<< endl;
			}else{ 
				//USA 6ª MAIOR PARA OS CASOS C D F G
				flags(flag8, flag5, flag3, flag6, 2); //CASO 2		
				pitch =  nota.Pitch()+ MAIOR6 -12; 
				if(pitch < 55)	{
					intervalo = define_saltos(anterior,nota);
					pitch = contrapt(nota,flag8, flag5, flag3, flag6, intervalo, anterior);
				}
				cout << "CP 3 MENOR: " << pitch<< endl; 		
			}
		}else{intervalo = define_saltos(anterior,nota);
			pitch = contrapt(nota,flag8, flag5, flag3, flag6,intervalo, anterior);
		}
			break;


		case 3:  // OITAVA
			if(*flag8==0){// SE AS NOTAS ANTERIORES DO CP E CF NAO SOAREM EM 'OITAVAS'
				flags(flag8, flag5, flag3, flag6, 3); //CASO 3		
				pitch =  nota.Pitch()-12; 
				if(pitch < 55)	{
					intervalo = define_saltos(anterior,nota);
					pitch = contrapt(nota,flag8, flag5, flag3, flag6, intervalo, anterior);
				}
				cout << "CP OITAVA ABAIXO: " << pitch<< endl;
			}else{// SE AS ANTERIORES SOAREM EM OITAVAS, FLAG8=1 E NAO PODE MAIS USAR 8ª COMO INTERVALO. TENTA OUTRO INTERVALO
				intervalo = define_saltos(anterior,nota);
				pitch = contrapt(nota,flag8, flag5, flag3, flag6, intervalo, anterior);
			}

		break;
		default:
			intervalo = define_saltos(anterior,nota);
			pitch = contrapt(nota,flag8, flag5, flag3, flag6, intervalo,anterior);
		break;
	}
	return pitch;

}


/*---------------------------------------------------------------------------------*/
/*--------------------------DEFINE NO CP A TONICA----------------------------------*/
/*---------------------------------------------------------------------------------*/
void tonica(MuNote *nota, MuNote tonicacf){ //FUNCAO RESPONSAVEL POR GERAR A NOTA TONICA (3ªm ou 3ªM OU 5ªJ PARA CONTRALTO NO CONTRAPONTO)
		nota->SetPitch(tonicacf.Pitch()); 
		cout << "UNISSONO: " << nota->Pitch() << endl;

}

/*---------------------------------------------------------------------------------*/
/*---------------------------DEFINE A PENULTIMA------------------------------------*/

void penultima(MuNote *nota, MuNote tonicacp, MuNote tonicacf){ //Penultima nota como sendo o 2º grau da escala do contraponto
	if((nota->Pitch()-2 == tonicacf.Pitch()) || (nota->Pitch()-1 == tonicacf.Pitch())){ //SE A PENULTIMA DO CF FOR O 2º GRAU
		nota->SetPitch(tonicacp.Pitch()-1);       //NO CASO DORICO, SERA C#
		cout << "CP PENULTIMA: " << nota->Pitch() << endl;
		}else{  //SENAO ELE COLOCA UMA CONSONANTE QUE NAO SEJA SENSIVEL	
			if((tonicacp.Pitch()%12 == 11)||(tonicacp.Pitch()%12 == 4)){ // CASO A TONICA SEJA E ou B, SOMA-SE APENAS 1(1SEMI-TOM) PARA SE EVITAR ACIDENTES
				nota->SetPitch(tonicacp.Pitch()+1-12);
				cout << "CP PENULTIMA: " << tonicacp.Pitch()+1 << endl;
			}else{ // CASO DOS DEMAIS, SOMA-SE 2(1TOM) PARA EVITAR ACIDENTES
				nota->SetPitch(tonicacp.Pitch()+2-12);
				cout << "CP PENULTIMA: " << tonicacp.Pitch()+2 << endl;
			}
		}
}


/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*------------------------------FUNÇOES EXTRAS-------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------


MuNote setProxMel(MuMaterial* pmat, int ind, int voz)//Material com a voz que deve ser analisada. Índice deve ser da nota que se quer colocar.
{
	MuMaterial material_aux;
	MuNote note_aux;
	int alt;

	note_aux 	=	(*pmat).GetNote(voz,ind-1);//Verifica a nota anterior.
	alt 		= 	note_aux.Pitch();

	cout << alt << endl;

	switch(Between(0,29))
	{
	
	//2ªm -  s(1)
		case 0:
		case 1:
		case 2: //Ascendente
			alt +=	1;
		break;

		case 3:
		case 4:
		case 5://Descendente
			alt -=	1;
		break;


	//2ªM -  T(2)
		case 6:
		case 7:
		case 8: //Ascen.
			alt +=	2;
		break;

		case 9:
		case 10:
		case 11://Descen.
			alt -= 	2;
		break;


	//3ªm - sT(3)
		case 12:
		case 13:
		case 14://Ascen.
			alt +=	3;
		break;

		case 17:
		case 15:
		case 16://Descen.
			alt -=	3;
		break;


	//3ªM - TT(4)
		case 20:
		case 18:
		case 19://Ascen.
			alt +=	4;
		break;

		case 23:
		case 21:
		case 22://Descen.
			alt -=	4;
		break;


	//5ªP - TTTs(7)
		case 25:
		case 24://Ascen.
			alt +=	7;
		break;

		case 27:
		case 26://Descen.
			alt -=	7;
		break;


	//6ªM - TTTTs(9)
		case 28://Ascen.
			alt +=	9;
		break;

	//8ªP - TTTTTT(12)
		case 29://Ascen.
			alt +=	12;
		break;

		case 30://Descen.
			alt -=	12;
		break;
	}


	if(alt > 127) 	alt 	=	 127;//Garantindo que a altura fique dentro da escala Midi.
	if(alt < 0) 	alt 	=	 0;

	note_aux.SetPitch( alt );
	material_aux	 +=		note_aux;
	setEscalaNat( &material_aux , 1 ); //Converte para Dó Maior, que não possui acidentes.

	note_aux	= 	material_aux.GetNote(0);
	alt 		=	note_aux.Pitch();
	
	if(alt%12 == 11) //Transforma Si em Sibemol.
	{
		 alt -=	1;
		 note_aux.SetPitch(alt);
	}

	cout << alt << endl;
	return note_aux;
}

/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------

MuNote setProxHar(MuMaterial* pmat, int ind, int voz1, int voz2)/*Retorna uma possível nota para a voz 2
com base na harmonia que essa tem com a voz 1.
{
	MuNote note_aux, note_harm;
	MuMaterial material_aux;
	int alt1, alt2, correto = 1, quinta;


	note_aux		=	 (*pmat).GetNote( voz1 , 0 ); //Supondo que a primeira nota defina a escala da música.
	quinta 			=	 note_aux.Pitch()%12 + 7; //Uma quinta justa. 
	note_aux.SetPitch( quinta );
	material_aux 	+=	 note_aux;
	setEscalaNat( &material_aux , 1 ); //Converte para modal.
	quinta 			= 	note_aux.Pitch(); //Quinta sem acidente.


	note_harm 	= 	(*pmat).GetNote( voz1 , ind );
	alt1 		= 	note_harm.Pitch()%12; //Pega o semitom da nota da voz1.


	do
	{

		correto 	=	1;
		note_aux 	= 	setProxMel( pmat , ind , voz2 );
		alt2 		=	note_aux.Pitch()%12; //Semitom da nota da voz2.
		if(alt1 == quinta && alt2 == quinta) correto = 0; //Quintas paralelas, o laço roda mais uma vez.
		
	} while(!correto);

	cout << alt1 << endl;

	return note_aux;

}

/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------

MuNote setProxRep(MuMaterial* pmat,int ind, int voz1, int voz2) //Material, índice da nota a ser adicionada, voz 1 e voz 2.
{
	MuNote note_aux1, note_aux2, note_aux3, note_aux4;
	MuMaterial material_aux;
	int alt1, alt2, alt3, alt4, correto = 1, terca, sexta, oitava;


	note_aux1		=	(*pmat).GetNote( voz1 , 0 ); //Supondo que a primeira nota defina a escala da música.
	terca			=	(note_aux1.Pitch()%12 + 3 ); //Uma terca maior.
	sexta 			= 	(note_aux1.Pitch()%12 + 9 );
	oitava			=   (note_aux1.Pitch()%12);  //Armazena a oitava dessa escala.


	note_aux1.SetPitch(terca);
	material_aux 	+=	 note_aux1;
	setEscalaNat( &material_aux , 1); //Converte para modal.
	note_aux1 		= 	material_aux.GetNote(0);
	terca 			= 	note_aux1.Pitch(); //Armazena a sexta dessa escala.
	material_aux.Clear();


	note_aux1.SetPitch(sexta);
	material_aux 	+=	note_aux1;
	setEscalaNat( &material_aux , 1 ); //Converte para modal.
	note_aux1 		= 	material_aux.GetNote(0);
	sexta			= 	note_aux1.Pitch(); //Armazena a sexta dessa escala.
	material_aux.Clear();



	do
	{
		correto = 1;

		note_aux4	=	setProxHar( pmat , ind , voz1 , voz2 );
		alt4 		= 	note_aux4.Pitch()%12;


		if(ind > 2) //Verifica se há quarta repetição da terca ou da sexta.
		{

			note_aux1 = (*pmat).GetNote( voz2 , ind - 3 );
			note_aux2 = (*pmat).GetNote( voz2 , ind - 2 );
			note_aux3 = (*pmat).GetNote( voz2 , ind - 1 );
			
			alt1 = (note_aux1.Pitch())%12;
			alt2 = (note_aux2.Pitch())%12;
			alt3 = (note_aux3.Pitch())%12;

			if(alt1 == alt2 && alt2 == alt3 && alt3 == alt4)
			{
				if(alt1 == terca || alt1 == sexta) correto = 0;
			}
		}

		if(ind > 0) //Verifica se há repetição de oitava.
		{
			note_aux3	= 	(*pmat).GetNote(voz2, ind-1);
			alt3 		= 	(note_aux3.Pitch())%12;

			if( alt4 == alt3 && alt3 == oitava ) correto = 0;
		}

	} while(!correto);

	cout << alt4 << endl;

	return note_aux4;
}
/*---------------------------------------------------------------------------------


int cmpfunc(const void* a, const void * b)
{
	return (*(int*)a - *(int*)b);
}


/*---------------------------------------------------------------------------------

void setEscalaNat(MuMaterial* pmat, int escalaD)//Converte o material				
{												//na escala desejada.
	int i, j, k, tam, ini;
	int escala[7], notas[MAX_MOTIF];
	MuNote nota_aux;

	tam = (*pmat).NumberOfNotes();

	if(escalaD > 24 || escalaD < 1) exit(2); //Número inválido.
	if(escalaD < 13)//Escala Maior TTsTTTs
	{
		ini = escalaD - 1;
        for(i = 0; i < 3; i ++)
        {
            escala[i]=(ini+2*i)%12;
        }


        for(i = 0; i < 4; i ++)
        {
            escala[i+3]=(ini+5+2*i)%12;
        }
	} else //Escala Menor TsTTsTT
	{
		ini = escalaD-1;
        escala[0]=ini%12;
        escala[1]=(ini+2)%12;
        escala[2]=(ini+3)%12;

        for(i = 0; i<2; i ++)
        {
            escala[i+3]=(ini+5+2*i)%12;
        }

        escala[5]=(ini+8)%12;
        escala[6]=(ini+10)%12;
	}

	qsort(escala, 7, sizeof(int), cmpfunc);


	for( i = 0; i < tam; i++) //Laço para obter as alturas das notas
	{						// do material.
        nota_aux = (*pmat).GetNote(i);
        notas[i] = nota_aux.Pitch();
    }

    for(j = 0; j < tam; j++)
    {
    	for(i = 0; i < 7; i++)
    	{
    		if((notas[j])%12 <= escala[i]) //Se a nota estiver fora da escala, ela é convertida
    		{								//para o grau acima mais próximo.	 							
				notas[j]-=(notas[j])%12;
				notas[j]+=(escala[i]);
				i=7;
				
			} else if(i == 6 && (notas[j])%12 == 11)
			{
				notas[j] -= (notas[j])%12;
				notas[j] += (escala[0])%12 + 12;
				i=7;//Passa para próxima nota.
			}
		}
		nota_aux = (*pmat).GetNote(j);
		nota_aux.SetPitch(notas[j]);
		(*pmat).SetNote(j,nota_aux);
    }
}





/*

//2ª e 3ª Maior ou Menor
//5ª Justa
//6ª Maior em Ascendente
//8ª Justa.



- Começa e termina na tônica;
- a Penultima nota é o 2º grau da escala;
- Fazer movimentos naturais;
- Pode usar 2ª e 3ª maior ou menor
-  Pode usar 5ª justa;
- Pode usar 6ª maior em ascendente;
- Pode usar a 8ª. 
- Alteração cromática: 1)Penúltimo compasso, para se ter a sensação de conclusão, pode usar um sustenido. Por exemplo: Modo dórico, posso usar C# para a penúltima.
2) Quando houver situação conflitante, entre F e B, posso trocar o B por Bb.
- Não pode 4ª e 7ª;
- Não pode 5ªs paralelas;
- 5ªs não podem aparecer 2x seguidas e nem uníssonas;
- 3ªs e 6ªs podem aparecer consecutivamente no máximo até 3x;
- Os dois últimos compassos tem que ser em grau conjunto.

*/
