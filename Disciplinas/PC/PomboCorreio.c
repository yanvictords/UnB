// [Estudo dirigido] Problema do pombo correio
// YAN VICTOR DOS SANTOS
// PROGRAMAÇÃO CONCORRENTE - 1/2018
// CÓDIGO FEITO POR MIM!

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "pthread.h"
#include "string.h"
#include <stdbool.h>
#include "semaphore.h"

#define PESO 5
#define ESCRITORES 10

sem_t cheio;
sem_t mutex;
sem_t entrega;
int n=0;
int cartas[PESO];
void insere_carta(int id_escritor){
	printf("\n\nEscritor %d inserindo carta na mochila...\n\n", id_escritor);
	sleep(1);	
	cartas[n]=id_escritor;
	n++;
	if(n==PESO) //se lotou a mochila
		sem_post(&entrega); //da sinal verde pro pombo
}

void transporta_cartas(){
	int i;
	printf("\n\nPombo correio entregando as seguintes cartas:");
	for(i=0; i<PESO; i++){
		printf("\nCarta escrita por %d", cartas[i]);
	}
	printf("\n\n");
	sleep(5);
	n=0;
	for(i=0;i<PESO;i++) //é o pombo quem esvazia a mochila
		sem_post(&cheio);
	printf("Cartas entregues com sucesso!\n\n");
}

void * escritores(void *arg){
	int i = *((int *) arg);
	while(1){
		sem_wait(&cheio); //tem vaga na mochila
			sem_wait(&mutex); //pega a escrita
				insere_carta(i);
			sem_post(&mutex); //libera escrita
	}
	pthread_exit(0);
}

void * pombo_correio(void *arg){
	while(1){
		sem_wait(&entrega);
			sem_wait(&mutex); //não deixa mais ninguém escrever
				transporta_cartas();
			sem_post(&mutex); //deixa a galera escrever
	}
	pthread_exit(0);
}

void inicializa_semaforos(){
	sem_init(&cheio, 0, PESO);
	sem_init(&mutex, 0, 1);
	sem_init(&entrega, 0, 0);
}

int main(){
	pthread_t a[ESCRITORES+1];
	int i;
	int *id_esc;
	int *id_pombo;
	
	inicializa_semaforos();
	printf("\n============================= INICIO =============================\n");
	for(i=0; i<ESCRITORES; ++i){
		id_esc = (int *) malloc(sizeof(int));
		*id_esc = i;
		if(i==(ESCRITORES-1)){
			id_pombo = (int *) malloc(sizeof(int));
			*id_pombo = ESCRITORES;
			pthread_create(&a[ESCRITORES], NULL, pombo_correio, (void *) (id_pombo));
		}
		pthread_create(&a[i], NULL, escritores, (void *) (id_esc));
	}
	

	
	pthread_join(a[0],NULL);
	return 0;
}


