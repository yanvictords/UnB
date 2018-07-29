// [Estudo dirigido] Canibais
// YAN VICTOR DOS SANTOS
// PROGRAMAÇÃO CONCORRENTE - 1/2018
// CÓDIGO FEITO POR MIM!

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "pthread.h"
#include "string.h"
#include <stdbool.h>


pthread_mutex_t  vez = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  co = PTHREAD_COND_INITIALIZER;
pthread_cond_t  ca = PTHREAD_COND_INITIALIZER;
#define T 10

int qtd_comida=0;

void cozinhar(){
	qtd_comida=rand() % 10;
		printf("Cozinheiro: Jogando %d comida(s) na mesa\n\n", qtd_comida);
}

void comer(int id){
	if(qtd_comida){
		printf("Canibal %d Comendo...\n\n", id);
		qtd_comida--;
	}else{
		printf("Canibal %d: 'Sdds comida. Acorda o cozinheiro!'\n\n", id);
		sleep(0.5);
		pthread_cond_signal(&co);
		pthread_cond_wait(&ca, &vez);
	}
}

void * cozinheiro(void *arg){
	while(1){
		pthread_mutex_lock(&vez);
		printf("Cozinheiro: Acordando..........\n\n");
		sleep(0.5);
		cozinhar();
		pthread_cond_broadcast(&ca);
		printf("Cozinheiro: Acordando geral\n\n");
		sleep(1);
		printf("Cozinheiro: 'Que sono, acho que vou dormir'\n\n");
		sleep(1);
		pthread_cond_wait(&co, &vez);
		pthread_mutex_unlock(&vez);
	}
}

void * canibais(void *arg){
	int i=*((int*) arg);
	while(1){
		pthread_mutex_lock(&vez);
		comer(i);
		pthread_mutex_unlock(&vez);
		sleep(1 );
	}
}

int main(){
	pthread_t a[T];
	int i;
	int *id_coz ;
	int *id_can;
	printf("\n============================= INICIO =============================\n");
	id_coz = (int *) malloc(sizeof(int));
	*id_coz = 0;
	for(i=1; i<=T; ++i){
		id_can = (int *) malloc(sizeof(int));
		*id_can = i;
		pthread_create(&a[i], NULL, canibais, (void *) (id_can));
	}
	pthread_create(&a[0], NULL, cozinheiro, (void *) (id_coz));
	
	pthread_join(a[0],NULL);
	return 0;
}


