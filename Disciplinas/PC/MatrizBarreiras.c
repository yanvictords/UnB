// [Estudo Dirigido] Soma de elementos de matriz com barreira
// YAN VICTOR DOS SANTOS
// PROGRAMAÇÃO CONCORRENTE - 1/2018
// CÓDIGO FEITO POR MIM!

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "pthread.h"
#include "string.h"
#include <stdbool.h>

#define LINHAS 10
#define COLUNAS 10
int matrix[LINHAS][COLUNAS];
int vetor_resultados[COLUNAS];
pthread_barrier_t barreira;
pthread_mutex_t print = PTHREAD_MUTEX_INITIALIZER;

void preenche_matrix(){
	for(int i=0;i<LINHAS;i++){
		for(int j=0; j<COLUNAS; j++){
			matrix[i][j] = j+i;
			printf("%d  ", j+i);
		}
		printf("\n");
	}
}

void preenche_vetor_resultados(){
	for(int i=0; i< COLUNAS; i++)
		vetor_resultados[i]=0;
}

void soma_vetor_resultados(){
	int result=0;
	for(int i=0; i<COLUNAS; i++)
		result += vetor_resultados[i];
	printf("Resultado: %d\n\n", result);
}

void * matrix_threads(void *arg){
	int i = *((int*) arg);	

	for(int j=0; j< COLUNAS; j++){
		vetor_resultados[i]+=matrix[i][j];
	}
	printf("[%d]=%d\n", i, vetor_resultados[i]);
	pthread_barrier_wait(&barreira);
	if(i==0)
		soma_vetor_resultados();

}

int main(){
	pthread_t a[LINHAS];
	int i;
	int *id_thread;	
	printf("\n============================= INICIO =============================\n");

	preenche_matrix();
	preenche_vetor_resultados();
	pthread_barrier_init(&barreira, NULL, LINHAS);

	for(i=0; i<LINHAS; i++){
		id_thread = (int *) malloc(sizeof(int));
		*id_thread = i;
		pthread_create(&a[i], NULL, matrix_threads, (void *) (id_thread));
	}

	
	pthread_join(a[0],NULL);
	return 0;
}


