// [Estudo Dirigido] Problema do consumidor/produtor
// YAN VICTOR DOS SANTOS
// PROGRAMAÇÃO CONCORRENTE - 1/2018
// CÓDIGO FEITO POR MIM!

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "pthread.h"
#include "string.h"
#include <stdbool.h>

pthread_mutex_t  m = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t  cons = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t  prod = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t  busy = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t  empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t  full = PTHREAD_COND_INITIALIZER;

#define N 10
#define T 4
typedef struct item ITEM;
struct item{
	int id;
	char name[10];
	ITEM *prox;
};
ITEM * item_pc;
int count = 0;
int cont_p = 0;
int cont_c = 0; 	 
_Bool producers_sleeping = true;
_Bool consumers_sleeping = true;
	
void insert_item(int id_item, char name_item[]){
	int i;
	ITEM * new_item = malloc(sizeof(ITEM));
	ITEM * aux;
    	for(i=0;i<strlen(name_item);i++)
    		new_item->name[i] = name_item[i];
    	new_item->id = id_item;
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
	printf("Id do item: %d\n\n", aux->id);
	
}

void remove_item(){
	ITEM * aux = item_pc;
	if(aux->prox==NULL){
		item_pc = NULL;
		free(item_pc);
	}else{
		while(aux->prox->prox!=NULL)
			aux = aux->prox;
		printf("**CONSUMINDO ITEM***\n");
		printf("Nome do item: %s\n", aux->name);
		printf("Id do item: %d\n\n", aux->id);	
		aux->prox=NULL;
	}
}

void * producer(void *arg){
	int i=*((int*) arg);
	while(1){
        	pthread_mutex_lock(&m);
		printf("==> Produtor %d: Tentando produzir.\n\n", i);
		pthread_mutex_lock(&prod);
		cont_p++;
		if(cont_p == 1){
			pthread_mutex_lock(&busy);
		}
		pthread_mutex_unlock(&prod);
		printf("-----------\n");
		while(count == N){
			printf("Produtor %d: Já tem itens demais! Indo dormir zZzZzZz\n\n", i);
			sleep(1);
			producers_sleeping = true;
			pthread_mutex_unlock(&busy);
			pthread_cond_wait(&full, &m);
		}
		count++;
		insert_item(count, "item");
		printf("Produtor %d: Um item acabou de ser produzido. Total de %d itens.\n\n", i, count);
		sleep(1);


		if(count > 0 && consumers_sleeping){
			printf("Produtor %d: Já tem um item para consumir. Acordando o cliente.\n\n", i);
			sleep(1);
			pthread_cond_signal(&empty);
			consumers_sleeping = false;
		}

		pthread_mutex_unlock(&m);
		sleep(1);
		pthread_mutex_lock(&prod);
		cont_p--;
		if(cont_p == 0){
			pthread_mutex_unlock(&busy);
		}
		pthread_mutex_unlock(&prod);
	}
	pthread_exit(0);
}

void * consumer(void *arg){
	int i=*((int*) arg);
	while(1){
        	pthread_mutex_lock(&m);
		printf("==> Consumidor %d: Tentando consumir.\n\n", i);
		pthread_mutex_lock(&cons);
		cont_c++;
		if(cont_c == 1){
			pthread_mutex_lock(&busy);
		}
		pthread_mutex_unlock(&cons);
		while(count == 0){
			printf("Cliente %d: Sem itens para consumir. Indo dormir zZzZzZz\n\n", i);
			sleep(1);
			consumers_sleeping = true;
			pthread_mutex_unlock(&busy);
			pthread_cond_wait(&empty, &m);
		}
		remove_item();
		count--;
		printf("Cliente %d: Consumindo 1 item. Existe(m) %d item/itens para consumir.\n\n", i, count);
		sleep(1);

		if(count < N && producers_sleeping){
			printf("Cliente %d: Total de itens ainda não está completo. Acordando o produtor.\n\n", i);
			sleep(1);
			pthread_cond_signal(&full);
			producers_sleeping = false;	
		}

		pthread_mutex_unlock(&m);		
		pthread_mutex_lock(&cons);
		cont_c--;
		if(cont_c == 0 ){
			pthread_mutex_unlock(&busy);			
		}	
		pthread_mutex_unlock(&cons);	
	}
	pthread_exit(0);
}

int main(){
	pthread_t a[T+T];
	int i;
	int *id_prod;
	int *id_cons;
	
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


