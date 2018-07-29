//[Estudo dirigido] Gerenciamento de escrita e leitura para acesso ao BD.
// YAN VICTOR DOS SANTOS
// PROGRAMAÇÃO CONCORRENTE - 1/2018
// CÓDIGO FEITO POR MIM!

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "pthread.h"

pthread_mutex_t bd = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t to_read = PTHREAD_MUTEX_INITIALIZER;
#define T 4
int nl = 0;

void * p_read(void *arg){
	int i=*((int*) arg);
	while(1){
		printf("R ::: O processo %d está solicitando o BD para LEITURA\n", i);
		pthread_mutex_lock(&to_read);
		nl++;
 		if(nl == 1){
			pthread_mutex_lock(&bd);	
			printf("\n-------------------------BD bloqueado para LEITURA------------------------------------\n");	
		}
		pthread_mutex_unlock(&to_read);
		printf("R ==========> O processo %d está lendo do BD <========== R\n", i);
		sleep(1);
		printf("R%d ::::::::::: Liberando o BD :::::::::: \n", i);
		pthread_mutex_lock(&to_read);
		nl--;
		if(nl == 0){
			pthread_mutex_unlock(&bd);
		printf("-------------------------------BD LIBERADO------------------------------------\n\n");
		}
		pthread_mutex_unlock(&to_read);
		sleep(3);
	}
	pthread_exit(0);
}

void * p_write(void *arg){
	int i=*((int*) arg);
	while(1){
		printf("W ::: O processo %d está solicitando BD para ESCRITA\n", i);
		pthread_mutex_lock(&bd);
		printf("\n-------------------------BD bloqueado para ESCRITA------------------------------------\n");
		printf("W ==========> O processo %d está escrevendo no BD <========== W\n", i);
		sleep(1);
		printf("W%d :::::::::: Liberando o BD :::::::::: \n", i);
		pthread_mutex_unlock(&bd);
		printf("-------------------------------BD LIBERADO------------------------------------\n\n");
		sleep(3);
	}
	pthread_exit(0);
}

int main(){
	pthread_t a[T+T];
	int i;
	int *id_read;
	int *id_write;
	for(i=0; i<T; ++i){
		id_read = (int *) malloc(sizeof(int));
		id_write = (int *) malloc(sizeof(int));
		*id_read = i;
		*id_write = i+T;
		pthread_create(&a[i], NULL, p_read, (void *) (id_read));
		pthread_create(&a[i+T], NULL, p_write, (void *) (id_write));
	}

	
	pthread_join(a[0],NULL);
	return 0;
}


