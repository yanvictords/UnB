// [Estudo dirigido] Problema da barbearia com semárforos.
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

#define QTD_CLIENTES 10
#define QTD_CADEIRAS 7

sem_t cadeira_barb;
sem_t total_cadeiras;
sem_t tem_clientes;
sem_t cortando;

void barbeiro_cortando(){
	printf("\n=> Barbeiro está cortando o cabelo de um dos clientes.\n");
	sleep(1);
	printf("\n=> Barbeiro terminou o corte de cabelo do cliente... cliente dispensado.\n");
}

void cliente_cortando(int id_cliente){
	printf("\n=> Cliente %d está cortando o cabelo na cadeira do barbeiro.\n", id_cliente);
}

void * barbeiro(void *arg){
	int i=*((int*) arg);
	while(1){
		sem_wait(&tem_clientes);
		barbeiro_cortando();
		sem_post(&cortando);
	}
	pthread_exit(0);
}

void * clientes(void *arg){
	int i=*((int*) arg);
	while(1){
		if(sem_trywait(&total_cadeiras) == 0){
			printf("\n[CADEIRA]: Cliente %d encontrou vaga em uma das cadeiras.\n", i);
			sem_wait(&cadeira_barb);
			sem_post(&total_cadeiras);
			sem_post(&tem_clientes);
			sleep(0.3);
			cliente_cortando(i);
			sem_wait(&cortando);
			sem_post(&cadeira_barb);
			sleep(1);
		}else{
			sleep(0.3);
			printf("\nCliente %d não encontrou cadeira vazia e foi embora :(\n", i);
			sleep(1);
		}
	}
	pthread_exit(0);
}

void inicializa_semaforos(){
    	sem_init(&cadeira_barb, 0, 1); // semaforo, pista compartilhada por todos os processos, capacidade C
	sem_init(&total_cadeiras, 0, QTD_CADEIRAS);
	sem_init(&tem_clientes, 0, 0);
	sem_init(&cortando, 0, 0);
}

int main(){
	pthread_t a[QTD_CLIENTES+1];
	int i;
	int *id_pessoa;
	
	inicializa_semaforos();

	printf("\n============================= INICIO =============================\n");
	id_pessoa = (int *) malloc(sizeof(int));
	*id_pessoa = 0;
	pthread_create(&a[0], NULL, barbeiro, (void *) (id_pessoa));
	for(i=1; i<=QTD_CLIENTES; ++i){
		id_pessoa = (int *) malloc(sizeof(int));
		*id_pessoa = i;
		pthread_create(&a[i], NULL, clientes, (void *) (id_pessoa));
	}

	
	pthread_join(a[0],NULL);
	return 0;
}


