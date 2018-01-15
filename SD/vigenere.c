#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
//O tamanho da chave eh 8
//FATIAS E REPETIÇÕES DE LETRAS
//150/146 
//214      
//148
//21
//0/69
//26
//117
//218

int main(){
	int i=0, k=1, j, mensagem[570], mensagem2[570], flag=0;
	int cont=0;
	int fatia[8][72];
	int probs[8][72];
	int probs2[8][72];
	FILE *arq;
	arq = fopen("mensagem.txt", "r+");
	printf("Mensagem cifrada: \n");
setlocale(LC_ALL, "Portuguese_Brazil");
//mensagem contem os valores em decimais de cada caracter do texto criptografado.
//mensagem2 contem os valores em decimais de cada caracter do texto criptografado sem repetição de nenhum.
//fatia são os blocos contendo os caracteres criptografados pelo mesmo caracter correspondente da chave
//probs[][] eh a matriz que contem as informações da frequencia de cada caracter em cada fatia
//probs2[] contem todos os caracteres de cada fatia, mas sem repeticao. 

	while(fscanf(arq, "%d\n", &mensagem[i])!=EOF){		
		//printf("%c", mensagem[i]);
		i++;
	}
//----- enchendo os vetores/matrizes de -1
	for(i=2;i<8;i++)
		fatia[i][71]=-1;
	
	for(i=0; i<570;i++)
		mensagem2[i]=-1;

	for(i=0;i<8;i++)
		for(j =0; j<72;j++)
			probs2[i][j]=-1;


//-------------- OS PRINTS DE INFORMAÇÕES SOBRE CARACTERES USADOS, E FREQUENCIA DOS MESMOS NO TEXTO CRIPTOGRAFADO INTEIRO
//-------------- TAIS INFORMAÇÕES FORAM USADAS PARA ANALISAR O TEXTO, E ASSIM DESCOBRIR O PADRAO DE REPETICAO PARA ACHAR O
//-------------- TAMANHO DA CHAVE
	mensagem2[0]=mensagem[0];
	for(i=1;i<570;i++){ //este for insere em mensagem2 todos os caracteres do texto criptografado, mas sem repetir
		for(j=0;j<k;j++){
			if(mensagem[i] == mensagem2[j]){
				flag=1;
			}
		}
		if(flag==0){
			mensagem2[k] = mensagem[i];
			k++;		
		}
	 	flag=0;
	}

	printf("\n\n Caracteres usados:\n ");
	int contador =0;
	int repeticao[113];
	//for(j=0;j<k;j++) //printa todos os caracteres usados, sem repeticao
	//	printf("%d) %d\n ",j+1, mensagem2[j]);
//--------
	printf("\n\nContadores:\n");
	for(int i=0;mensagem2[i]!=-1;i++){ //esta parte conta a frequencia de cada caracter do texto criptografado
		for(int j=0;j<570;j++){
			if(mensagem2[i]==mensagem[j]){
				contador++;
			}
		}
	repeticao[i]=contador;
	//if(repeticao[i]>10) //este if serve para mostrar os que mais se repetem
	//printf("%d) %d - %d\n  ", i+1, repeticao[i], mensagem2[i]);
	contador=0;
	}

	for(i=0;i<8;i++){
		for(j=0;j<71;j++){
			fatia[i][j]=mensagem[(j*8)+i];	
	//		printf("fatia[%d][%d] %d\n", i, (j*8)+i, fatia[i][j]);
		}
	}
	fatia[0][71] = mensagem[568];
	fatia[1][71] = mensagem[569];
	//printf("fatia %d %d %d\n", 0,568, fatia[0][71]);
	//printf("fatia %d %d %d\n", 1,569, fatia[1][71]);


//-------------- ANALISE DE FREQUENCIA DOS ELEMENTOS DOS BLOCOS

	flag=0;
	k=1;
	int l;
//--------
	for(j=0;j<8;j++)
		for(l=0;l<72;l++)
			probs[j][l]=-1;
//O segmento de codigo abaixo guarda os caracteres de cada fatia sem repeticao, em probs2
int excessao; //como os blocos 1 e 2 possuem um caracter a mais que os outros
	for(i=0;i<8;i++){
	if(i<2)
		excessao = 72;
	else
		excessao = 71;
		probs2[i][0]=fatia[i][0];
		for(j=1;j<excessao;j++){
			for(l=0;l<k;l++){
				if(fatia[i][j]==probs2[i][l])
					flag++;
			}		
			if(flag==0){
				probs2[i][k] = fatia[i][j];
				k++;
			}
			flag=0;
		}
//O segmento de codigo abaixo conta a frequencia de cada caracter em cada fatia
		for(j=0;probs2[i][j]!=-1;j++){
			contador=0;
			for(l=0;l<excessao;l++){
				if(probs2[i][j]==fatia[i][l])
					contador++;
			}
			probs[i][j] = contador;	
		}
		k=1;
	}

		for(j=0;j<8;j++){
			printf("-----------\n");
			if(j<2)
				excessao = 72;
			else
				excessao = 71;
			for(l=0;l<excessao;l++){				
				if(probs[j][l]!=-1){
					printf("=fatia %d: %d |%d|\n", j, probs[j][l], probs2[j][l]);
				}
			}			
		}
		
		
//-----------------------------//-----------------------------//-----------------------------	
	//-----------------------------//-----------------------------//-----------------------------
		//-----------------------------//-----------------------------//-----------------------------
// O CODIGO ABAIXO COMEÇA A DECRIPTAR O TEXTO. AS INFORS QUE PRECISAMOS SAO:
// TAMANHO DA CHAVE, DIVISAO EM FATIAS E FREQUENCIA DOS CARACTERES EM CADA FATIA(blocos[])

int resultado, r, y, arruma, n;//resultado => binario->decimal / r=>decimal->binario / y = for / arruma = indice em for ao contrario
int vector[8],finalxor[8],chave[8][8],antesxor[8][8], blocos[8] = {211, 214, 148, 21, 0, 89, 117, 149}, frequencia[8]={0,0,1,0,0,0,0,0};
//vector[] é o caracter atual do arquivo texto criptografado / finalxor[] é caracter atual descriptografado  
//bloco[] é mais frequentes de cada bloco em decimal, antesxor[][] é mais frequentes em binario e chave[][]
//é após xor de antesxor com frequencia[]
	arq = fopen("mensagemfinal.txt", "w+");
//Transformando a mais frequente de cada 'bloco' para binario
for(j=0;j<8;j++){
	arruma=0;
	n= blocos[j];
 	for(i = 7; i >= 0; i--) {
   		r = n >> i;
   		if(r & 1) {
        		antesxor[j][arruma]=1;
    		} else {
        		antesxor[j][arruma]=0;
    		}
		printf("%d", antesxor[j][arruma]); 
    		arruma++;

	}
	printf("\n");
 }



//fazendo xor das mais frequentes de cada bloco com a mais frequente no texto = ' '  (frequencia). O vetor 'chave' é a chave em binario
for(i=0;i<8;i++){
	for(j=0;j<8;j++){
		if(antesxor[i][j]==frequencia[j]){
			chave[i][j]=0;
		}else{
			chave[i][j]=1;
		}
	}
}




 //A partir daqui, tenho a chave completa. Cada caracter da chave é um numero binario de 8 bits
 printf("\n\nMENSAGEM:\n\n");
  
  for(y=0;y<570;y++){

  	//conversao decimal-binario do caracter atual do texto criptografado
  	arruma=0;
	n = mensagem[y];
 	for(i = 7; i >= 0; i--) {
   		r = n >> i;
   		if(r & 1) {
        	vector[arruma]=1; //vector é vetor temporario contendo o numero em binario do caracter atual do texto
    	} else {
        	vector[arruma]=0;
    	}
    arruma++;

	}
	for(j=0;j<8;j++){ //fazendo xor do caracter atual com caracter correspondente da chave para descriptografar o caracter
		if(vector[j]==chave[y%8][j]){
			finalxor[j]=0; //finalxor é o vetor contendo o caracter verdadeiro do texto (resultado do xor)
		}else{
			finalxor[j]=1;
		}
	}
	//conversao binario-decimal do caracter atual do texto descriptografado (verdadeiro caracter)
	resultado =0;
	resultado+= finalxor[7];
	resultado+= finalxor[6]*2;
	resultado+= finalxor[5]*2*2;
	resultado+= finalxor[4]*2*2*2;
	resultado+= finalxor[3]*2*2*2*2;
	resultado+= finalxor[2]*2*2*2*2*2;
	resultado+= finalxor[1]*2*2*2*2*2*2;
	resultado+= finalxor[0]*2*2*2*2*2*2*2;

	fprintf(arq,"%c",resultado);
	printf("%c",resultado);

  }
	// arq = fopen("mensagem3.txt", "w+");
//Convertendo a chave do binario para decimal
int chavedecimal[8];
for(i=0;i<8;i++){

	resultado =0;
	resultado+= chave[i][7];
	resultado+= chave[i][6]*2;
	resultado+= chave[i][5]*2*2;
	resultado+= chave[i][4]*2*2*2;
	resultado+= chave[i][3]*2*2*2*2;
	resultado+= chave[i][2]*2*2*2*2*2;
	resultado+= chave[i][1]*2*2*2*2*2*2;
	resultado+= chave[i][0]*2*2*2*2*2*2*2;
	chavedecimal[i]=resultado;
	printf(" %d", chavedecimal[i]);
}
	printf("\n");
	printf("\n\nChave em decimal:");
	for(i=0;i<8;i++)
		printf(" %d", chavedecimal[i]);
	printf("\n");

	int vetorsuporte[8], vetorbinario[8];

printf("caracteres mais frequentes em cada bloco:");
for(k=0;k<8;k++){
	n = chavedecimal[k];
	arruma=0;
 	for(i = 7; i >= 0; i--) {
   		r = n >> i;
   		if(r & 1) {
        	vetorbinario[arruma]=1; 
    	} else {
        	vetorbinario[arruma]=0;
    	}
    arruma++;

	}
	
	for(j=0;j<8;j++){
		if(vetorbinario[j]==frequencia[j]){
			finalxor[j]=0; 
		}else{
			finalxor[j]=1;
		}
	}
	
	resultado =0;
	resultado+= finalxor[7];
	resultado+= finalxor[6]*2;
	resultado+= finalxor[5]*2*2;
	resultado+= finalxor[4]*2*2*2;
	resultado+= finalxor[3]*2*2*2*2;
	resultado+= finalxor[2]*2*2*2*2*2;
	resultado+= finalxor[1]*2*2*2*2*2*2;
	resultado+= finalxor[0]*2*2*2*2*2*2*2;
	printf(" %d",resultado);
}printf("\n");
/*arq = fopen("mensagem3.txt", "w+");
	fprintf(arq, "%c %c %c %c %c %c %c %c", 243, 246, 180, 53, 32, 121, 85, 181); */
 
	fclose(arq);
	printf("\n\n****Arquivo mensagemfinal.txt gerado com sucesso!!! Abra e veja o resultado.****\n");
	return 0;
}



