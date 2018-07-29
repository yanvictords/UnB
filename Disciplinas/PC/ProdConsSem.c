// [Estudo Dirigido] Produtor - Consumidor com semáforos
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

#define N 5
#define T 4

sem_t area;

typedef struct item ITEM;
struct item{
	int id;
	char name[10];
	ITEM *prox;
};
ITEM * item_pc;
int count = 0;
	
void insert_item(int id_produtor, char name_item[]){
	int i;
	ITEM * new_item = malloc(sizeof(ITEM));
	ITEM * aux;
    	for(i=0;i<strlen(name_item);i++)
    		new_item->name[i] = name_item[i];
    	new_item->id = id_produtor;
    	new_item->prox = NULL;
    	if(item_pc == NULL){
    	    item_pc = new_item;
    	}else{
		aux = item_pc;
    		while(aux->prox != NULL)
    	     	aux = aux->prox;
    	   	aux->prox = new_item;
    	}  
	printf("***ITEM INSERIDO***\n");
	aux=item_pc;
	while(aux->prox != NULL)
		aux=aux->prox;
	printf("Nome do item: %s\n", aux->name);
	printf("Produzido por produtor %d\n", id_produtor);
	count++;
	printf("Total de itens: %d\n", count);
	printf("******************\n\n");
}

void remove_item(int id_consumidor){
	ITEM * aux = item_pc;
	if(aux->prox==NULL){
		printf("***CONSUMINDO ITEM***\n");
		printf("Nome do item: %s\n", item_pc->name);
		item_pc = NULL;
		free(item_pc);
	}else{
		while(aux->prox->prox!=NULL)
			aux = aux->prox;
		printf("***CONSUMINDO ITEM***\n");
		printf("Nome do item: %s\n", aux->name);
		aux->prox=NULL;
	}
	count--;
	printf("Consumido por consumidor %d\n", id_consumidor);	
	printf("Total de itens: %d\n", count);
	printf("******************\n\n");
}

void * producer(void *arg){
	int i=*((int*) arg);
	while(1){
		sem_wait(&area);
		printf("-> Produtor %d tentará produzir.\n\n", i);
		if(count < N)
			insert_item(i, "item");
		else
			printf("A mesa está cheia!\n\n");
		sem_post(&area);		
		sleep(1);
	}
	pthread_exit(0);
}

void * consumer(void *arg){
	int i=*((int*) arg);
	while(1){
     	sem_wait(&area);
		printf("-> Consumidor %d tentará consumir.\n\n", i);
		if(count>0)
			remove_item(i);
		else
			printf("Sem intens para consumir!\n\n");
		sem_post(&area);
		sleep(1);
	}
	pthread_exit(0);
}

void inicializa_semaforos(){
    sem_init(&area, 1, 1); // semaforo, pista compartilhada por todos, capacidade C
}

int main(){
	pthread_t a[T+T];
	int i;
	int *id_prod;
	int *id_cons;
	
	inicializa_semaforos();
	printf("\n============================= INICIO =============================\n");
	for(i=0; i<T; ++i){
		id_prod = (int *) malloc(sizeof(int));
		id_cons = (int *) malloc(sizeof(int));
		*id_prod = i;
		*id_cons = i+T;
		pthread_create(&a[i], NULL, producer, (void *) (id_prod));
		pthread_create(&a[i+T], NULL, consumer, (void *) (id_cons));
	}

	
	pthread_join(a[0],NULL);
	return 0;
}


