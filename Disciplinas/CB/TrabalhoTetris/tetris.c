/* TRABALHO 3, DE TETRIS - YAN VICTOR DOS SANTOS/140033599 - CARLA KOIKE - COMPUTAÇÃO BÁSICA - 
OBS.: FUNÇÕES NOMEADAS E COMENTADAS DE ACORDO COM O ROTEIRO PARA FACILITAR A LEITURA.*/



#include <stdio.h>
#include <stdlib.h>
/*-----------------------------------------------------------------------------*/
/*FUNÇÃO 1*//*FUNÇÃO 1*//*FUNÇÃO 1*//*FUNÇÃO 1*//*FUNÇÃO 1*//*FUNÇÃO 1*//*FUNÇÃO 1*/
/*-----------------------------------------------------------------------------*/
/*IRÁ MOSTRAR A TELA INICIAL DO JOGO. A TELA INICIAL FEITA DE PRINTF'S DE FORMA SIMPLES MESMO.*/
	void funcao1(void){
		printf("***BEM VINDO AO CBETRIS***\n\n");
		printf("  +--------------------+\n");
		printf("  |                    |\n");
		printf("  |                    |\n");
        	printf("  |                    |\n");
		printf("  |                    |\n");
		printf("  |                    |\n");
		printf("  |                    |\n");
		printf("=>+                    +<=\n");
		printf("  |                    |\n");
		printf("  |                    |\n");
		printf("  |                    |\n");
		printf("  |                    |\n");
		printf("  |                    |\n");
		printf("  |                    |\n");
		printf("  |                    |\n");
		printf("  |                    |\n");
		printf("  +--------------------+\n\n");
		printf("Pressione <ENTER> para iniciar o jogo\n\n");
		getchar();
		system("clear");
	}
/*FIM DA FUNÇÃO 1.*/
/*-----------------------------------------------------------------------------*/
/*FUNÇÃO 2*//*FUNÇÃO 2*//*FUNÇÃO 2*//*FUNÇÃO 2*//*FUNÇÃO 2*//*FUNÇÃO 2*//*FUNÇÃO 2*/
/*-----------------------------------------------------------------------------*/
/*ESTA FUNÇÃO SERÁ O INICIO DO JOGO. IRÁ LER O ARQUIVO,
MOSTRAR A PONTUAÇÃO INICIAL E AS SEQUENCIAS DO JOGO.
A MATRIZ SERÁ INSERIDA DENTRO DAS BORDAS FEITAS POR PRINTF'S.*/
	void funcao2(char matriz1[15][20], int pont){
		int i, j;
		system("clear");
		printf("***BEM VINDO AO CBETRIS***\n\n");
		printf("  +--------------------+");
		printf("           PONTUACAO: %d\n", pont);
/*---------*/
/*PRIMEIRO ELE MOSTRA, ATÉ A 6ª LINHA, AS BORDAS NORMAIS. QUANDO CHEGA NA 7ª LINHA,
ELE ACRESCENTA '=>' E '<=' E TROCA AS '|'s POR SINAIS DE '+'s. DEPOIS ELE CONTINUA MOSTRANDO O RESTO DAS BORDAS.*/
		for (i=0; i<6; i++){
			printf("  |");
			for(j=0; j<20; j++){
				printf("%c", matriz1[i][j]);
			}	
			printf("|\n");
		}
/*--------- ACRESCENTANDO '=>+' e '+<='*/
		printf("=>+");
		for(j=0;j<20;j++){
			printf("%c", matriz1[6][j]);
		}
        	printf("+<=\n");
/*--------- CONTINUANDO*/
		for(i=7; i<15; i++){
			printf("  |");
			for(j=0; j<20; j++){
				printf("%c", matriz1[i][j]);
			}
			printf("|\n");
		}
/*---------*/
		printf("  +--------------------+\n\n");
		printf("R-rotar D-direita E-esquerda C-cair");
		printf("\nACAO:");
	}
/*FIM DA FUNÇÃO 2.*/
/*-----------------------------------------------------------------------------*/
/*FUNÇÃO 4*//*FUNÇÃO 4*//*FUNÇÃO 4*//*FUNÇÃO 4*//*FUNÇÃO 4*//*FUNÇÃO 4*//*FUNÇÃO 4*/
/*-----------------------------------------------------------------------------*/
/*ESTA FUNÇÃO IRÁ ROTACIONAR A SEQUÊNCIA*/
	void funcao4(char matriz1[15][20], int x, int rot, int pont){
		int i, j;
		if(rot%2!=0){       /*VOLTANDO A FICAR EM PÉ*/
			for(i=0;i<6;i++){
				matriz1[1][x+i]= matriz1[i][x];
				if(i!=1){
					matriz1[i][x]=' ';
				}
			}
		}else{            /*DE PÉ PARA DEITADA*/
			for(i=0;i<6;i++){ 
				matriz1[i][x]=matriz1[1][x+i];
				for(j=0;j<20;j++){
					if(j!=x){     
						matriz1[1][x+i]=' ';
					}
				}
			}
		} 
	}
/*FIM DA FUNÇÃO 4.*/
/*-----------------------------------------------------------------------------*/
/*FUNÇÃO 5*//*FUNÇÃO 5*//*FUNÇÃO 5*//*FUNÇÃO 5*//*FUNÇÃO 5*//*FUNÇÃO 5*//*FUNÇÃO 5*/
/*-----------------------------------------------------------------------------*/
/*ESSA FUNÇÃO IRÁ MOVER A SEQUÊNCIA PARA A DIREITA.*/
	void funcao5(char matriz1[15][20], int x, int rot, int pont, int seq){
		int i;
		if(rot%2==0){         /*SE A PEÇA ESTIVER EM PÉ*/
			for(i=0;i<6;i++){
				matriz1[i][x]=matriz1[i][x-1];
				matriz1[i][x-1]=' ';
			}
		}else{            /*SE A PEÇA ESTIVER DEITADA*/
			for(i=seq;i>=0;i--){
				matriz1[1][x+i-1]=matriz1[1][x+i-2];
			}
			matriz1[1][x-1]=' ';
		}
	}
/*FIM DA FUNÇÃO 5.*/
/*-----------------------------------------------------------------------------*/
/*FUNÇÃO 6*//*FUNÇÃO 6*//*FUNÇÃO 6*//*FUNÇÃO 6*//*FUNÇÃO 6*//*FUNÇÃO 6*//*FUNÇÃO 6*/
/*-----------------------------------------------------------------------------*/
/*ESSA FUNÇÃO IRÁ MOVER A SEQUÊNCIA PARA A ESQUERDA.*/
	void funcao6(char matriz1[15][20], int x, int rot, int pont, int seq){
		int i;
		if(rot%2==0){            /*SE A PEÇA ESTIVER EM PÉ*/
			for(i=0;i<6;i++){
				matriz1[i][x]=matriz1[i][x+1];
				matriz1[i][x+1]=' ';
			}
		}else{            /*SE A PEÇA ESTIVER DEITADA*/
			for(i=0;i<=seq;i++){
				matriz1[1][x+i-1]=matriz1[1][x+i];
			}
			matriz1[1][x+seq]=' ';
		}
	}
/*FIM DA FUNÇÃO 6.*/
/*-----------------------------------------------------------------------------*/
/*FUNÇÃO 7*//*FUNÇÃO 7*//*FUNÇÃO 7*//*FUNÇÃO 7*//*FUNÇÃO 7*//*FUNÇÃO 7*//*FUNÇÃO 7*/
/*-----------------------------------------------------------------------------*/
/*ESSA FUNÇÃO IRÁ FAZER A SEQUÊNCIA "CAIR".*/
	void funcao7(char matriz1[15][20], int x, int rot, int c, int seq){
		int i=0; 
		if(rot%2!=0){            /*SE A PEÇA ESTIVER DEITADA*/          
			while((matriz1[c][x+i]==' ')&&(c<15)){ /*'c'=> linha, inicialmente ='7' / 'x'=> coluna da primeira peça da sequência*/
/*Este 'while' indica que enquanto houver 'espaço' relativo ao tamanho da sequencia, ele descerá de linha*/
				if(i<=seq){ /*'i' vai contar de 0 até o tamanho da sequência*/
					i++;
				}
				if(i==seq){ /*se o 'i' chegar ao fim da sequência e só tiver espaços na linha atual, ele descerá de linha*/
					c++;
					i=0; /*'i' volta a ser zero para atuar na linha de baixo*/
				}
			}c--; /* 'c--' anula último 'c' somado, pois o valor anterior foi a condição de saída do while*/
/*-----------------*/

			for(i=0;matriz1[1][x+i]!=' ';i++){
				matriz1[c][x+i]=matriz1[1][x+i];
			}

/*---------------------------------------------*/
		}else{                /*SE A PEÇA ESTIVER EM PÉ*/
			while((matriz1[c][x]==' ')&&(c<15)){ /*verifica onde há local diferente de 'espaço'*/
				c++;
			}c--;  /* 'c--' anula último 'c' somado, pois o valor anterior foi a condição de saída do while*/

/*-----------------*/

			for(i=0;i<5;i++){
				matriz1[c-i][x]=matriz1[i][x];
			}

/*-----------------*/
		}
	}
/*FIM DA FUNÇÃO 7.*/
/*-----------------------------------------------------------------------------*/
/*FUNÇÃO 3*//*FUNÇÃO 3*//*FUNÇÃO 3*//*FUNÇÃO 3*//*FUNÇÃO 3*//*FUNÇÃO 3*//*FUNÇÃO 3*/
/*-----------------------------------------------------------------------------*/
/*ESSA FUNÇÃO IRÁ FAZER TODOS OS MOVIMENTOS DO JOGO*/
	void funcao3(char matriz1[15][20], int x, int seq, int pont){
		int rot=0, c=7, i, j, cont;  /*'rot' = contador flag para saber se a sequencia é horizontal ou vertical // c = Linha 7 da matriz*/
		char acao;
		scanf("%c", &acao);
		getchar();
		while((acao!='c')&&(acao!='C')){
			cont=0;        
			if((acao=='r')||(acao=='R')){   
				if(x<=20-seq){ 
					rot++;
					funcao4(matriz1, x, rot, pont);
				}
				funcao2(matriz1, pont);
			}
			if((acao=='d')||(acao=='D')){
				if(rot%2!=0){
					if(x+seq<=19){
						x++;
						funcao5(matriz1, x, rot, pont, seq);
					}
					funcao2(matriz1, pont);
				}else{
					if(x<19){
						x++;
						funcao5(matriz1, x, rot, pont, seq);
					}
					funcao2(matriz1, pont);
				}
			}
			if((acao=='e')||(acao=='E')){
				if(x>0){
					x--;
					funcao6(matriz1, x, rot, pont, seq);
				}
				funcao2(matriz1, pont);
			}

/*--------Este 'while' garante que o jogo não irá executar nada se o usuário digitar uma letra desconhecida---------*/     
			while((acao!='r')&&(acao!='R')&&(acao!='d')&&(acao!='D')&&(acao!='e')&&(acao!='E')&&(acao!='c')&&(acao!='C')){            
				funcao2(matriz1, pont);
				scanf("%c", &acao);
/*-------*/
				if((acao=='r')||(acao=='R')||(acao=='d')||(acao=='D')||(acao=='e')||(acao=='E')||(acao=='c')||(acao=='C')){             
                    			cont=1; /* 'cont' = flag para o comando 'if' abaixo */
                		}
                		getchar();
                	}
/*---------------FIM DO 'WHILE'---------------*/

                	if(cont==0){    /*'if' impede que o comando 'scanf' se repita em caso do 'while' anterior seja usado*/         
                		scanf("%c", &acao);
                		getchar();
                	}
        	}
/*---------------*/
        	if((acao=='c')||(acao=='C')){
           		funcao7(matriz1, x, rot, c, seq);
            		for(i=0;i<6;i++){
                		for(j=0;j<20;j++){
                    			if(j!=10){
                        			matriz1[i][j]=' ';
                    			}
                		}
            		}
       		}
          	funcao2(matriz1, pont);
	}
/*FIM DA FUNÇÃO 3.*/
/*-----------------------------------------------------------------------------*/
/*FUNÇÃO 8*//*FUNÇÃO 8*//*FUNÇÃO 8*//*FUNÇÃO 8*//*FUNÇÃO 8*//*FUNÇÃO 8*//*FUNÇÃO 8*/
/*-----------------------------------------------------------------------------*/
/*ESSA FUNÇÃO VERIFICA SE UMA LINHA ESTÁ PREENCHIDA, E SE ESTIVER, SOMA OS PONTOS, FAZ A LINHA SUMIR E FAZ AS PEÇAS CAIREM ATÉ ELA.*/	
	void funcao8(char matriz1[15][20], int *pont){
		int i, j, y, cont, flag=0;
/*primeiro ela verifica onde tudo está preenchido, e se estiver, anuncia na flag(cont=20), e então substitui toda a linha por X'S*/
		for(y=7;y<15;y++){     
			cont=0;
			for(i=0;i<20;i++){
				if(matriz1[y][i]!=' '){
					cont++; /*se 'cont' for igual a 20, então toda a linha é preenchida por algo que não seja espaço*/
				}
				if(cont==20){
					flag++;
					for(i=0;i<20;i++){
						matriz1[y][i]='X';
					}
				}
			}
		}
		if(flag!=0){   /*se houver uma linha completa, mostra a matriz antes de fazer as peças caírem até a linha preenchida*/
			funcao2(matriz1, *pont);
			getchar();
		}
/*-------------------*/
/*Esse 'for' irá buscar as linhas substituídas por x's e faz as peças caírem até essa linha. E soma os pontos adequados.*/
		for(y=7;y<15;y++){     
			cont=0;   
			for(i=0;i<20;i++){
				if(matriz1[y][i]!=' '){
					cont++; /*se 'cont' for igual a 20, então toda a linha é preenchida por X's*/
				}
			}
			if(cont==20){ /*'if' que fará as linhas acima da linha preenchida, caírem até ela.*/
			*pont=*pont+100;
				for(i=y;i>5;i--){
					for(j=0;j<20;j++){
						matriz1[i][j]=matriz1[i-1][j];   
					}   
				}
			}
		}
		if(flag!=0){
			funcao2(matriz1, *pont);
		} 
	}   
 
/*FIM DA FUNÇÃO 8.*/
/*-----------------------------------------------------------------------------*/
/*FUNÇÃO 9*//*FUNÇÃO 9*//*FUNÇÃO 9*//*FUNÇÃO 9*//*FUNÇÃO 9*//*FUNÇÃO 9*//*FUNÇÃO 9*/
/*-----------------------------------------------------------------------------*/
/*ELA LÊ O ARQUIVO E O GUARDA EM UMA MATRIZ.
FILE = ARQUIVO. 'FILE *seta' É UM PONTEIRO PARA O ARQUIVO. FOPEN = FILE OPEN.
POSSO ESCREVER NO ARQUIVO(FPRINTF), LER DO ARQUIVO(FSCANF) E IMPRIMIR NO TERMINAL (PRINTF), ENTRE OUTROS.*/
	void funcao9(char arquivo[50], char matriz2[21][7]){
		int i;
		FILE *seta;
		seta = fopen(arquivo, "r+");
		while(!feof(seta)){
			for(i=0; i<20; i++){
				fscanf(seta, "%[^\n]\n", &matriz2[i][0]);
			}
		}
		fclose(seta);
	}
/*AS SEQUÊNCIAS FORAM INSERIDAS DENTRO DA MATRIZ.
AGORA É SÓ CHAMAR A FUNÇÃO 9 QUANDO PRECISAR USÁ-LAS.
FIM DA FUNÇÃO 9.*/
/*-----------------------------------------------------------------------------*/
/*FUNÇÃO 10*//*FUNÇÃO 10*//*FUNÇÃO 10*//*FUNÇÃO 10*//*FUNÇÃO 10*//*FUNÇÃO 10*/
/*-----------------------------------------------------------------------------*/
/*FUNÇÃO QUE FAZ A MATRIZ1 RECEBER OS ARQUIVOS DA MATRIZ COM AS SEQUÊNCIAS*/
	void funcao10(char matriz1[15][20], char matriz2[21][7], int k, int *seq){
		int i;
		for(i=0;matriz2[k][i]!='\0';i++){
			matriz1[i][10]=matriz2[k][i];
			*seq=*seq+1;
		}
		while(i<6){
			matriz1[i][10]=' ';
			i++;
		}
	}
/*FIM DA FUNÇÃO 10.*/
/*-----------------------------------------------------------------------------*/
/*FUNÇÃO 11*//*FUNÇÃO 11*//*FUNÇÃO 11*//*FUNÇÃO 11*//*FUNÇÃO 11*//*FUNÇÃO 11*/
/*-----------------------------------------------------------------------------*/
/*FUNÇÃO QUE É USADA EM CASO SE O JOGADOR PERDER. SUBSTITUI TODA A MATRIZ POR X'S*/
	void funcao11(char matriz1[15][20], int pont, int *perdeu){
		int i, j, perder=0;
		for(i=0;i<20;i++){
			if(matriz1[6][i]!=' '){
				perder++;
			}
		}
		if(perder!=0){
			system("clear");
			for(i=0;i<15;i++){
				for(j=0;j<20;j++){
					matriz1[i][j]='X';
					}
			}
			*perdeu+=1;
			funcao2(matriz1, pont);
		}
	}       
 
/*FIM DA FUNÇÃO 11.*/
/*-----------------------------------------------------------------------------*/
/*FUNCAO PRINCIPAL*//*FUNCAO PRINCIPAL*//*FUNCAO PRINCIPAL*//*FUNCAO PRINCIPAL*/
/*-----------------------------------------------------------------------------*/
	int main () {
		char arquivo[50]="sequencias.txt";
		char matriz1[15][20];/*MATRIZ QUE GUARDA O JOGO.*/
		char matriz2[21][7];/*MATRIZ QUE GUARDA AS SEQUÊNCIAS.*/
		int i, j, k, x=10, seq, pont=0, perdeu=0;
		system("clear");
/*------------FIM DAS DECLARAÇÕES-----------*/
/*------------------INICIO------------------*/
		for(i=0; i<15; i++){
			for(j=0; j<20; j++){
				matriz1[i][j]=' ';
			}
		}
/*-----------------*/
		funcao1();
		funcao9(arquivo, matriz2);
		for(k=0;((k<20)&&(perdeu==0)); k++){
			seq=0;
			funcao10(matriz1, matriz2, k, &seq);
/*---------*/
			funcao2(matriz1, pont);
			funcao3(matriz1, x, seq, pont);
			funcao8(matriz1, &pont);
			funcao11(matriz1, pont, &perdeu);
		}
		if(k==20){
			printf("\n\n\n**PARABENS, VOCE GANHOU!!!**\n");
			printf("        PONTUAÇÃO: %d\n\n\n", pont);
			printf("Pressione <ENTER> para encerrar\n\n\n");
			getchar();
		}
		if(perdeu!=0){
			printf("\n\n\n      **GAME OVER**\n");
			printf("        PONTUAÇÃO: %d\n\n\n\n", pont);
			printf("Pressione <ENTER> para encerrar\n\n\n");
			getchar();
		}
	return(0);
	}
