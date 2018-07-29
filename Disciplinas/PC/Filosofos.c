// [Estudo dirigido] Problema dos filosofos
// YAN VICTOR DOS SANTOS
// PROGRAMAÇÃO CONCORRENTE - 1/2018
// CÓDIGO FEITO POR MIM!

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include 	"pthread.h"
#include "string.h"
#include <stdbool.h>
#include "semaphore.h"

#define QTD_F 5


sem_t filosofos[5];
pthread_mutex_t  vez = PTHREAD_MUTEX_INITIALIZER;

int get_abs(int i){
	if(i < 0)
		return 4;
	return i;
}

void * filosofo(void *arg){
	int i = *((int*) arg);	
	int fil_dir, fil_esq;
	while(1){
		pthread_mutex_lock(&vez);
			printf("Filosofo %d Esta pensando...\n\n", i);
			sleep(1);
			printf("Filosofo %d quer comer...\n\n", i);

			sem_getvalue(&filosofos[get_abs(i-1)%5], &fil_dir);
			sem_getvalue(&filosofos[(i+1)%5], &fil_esq);
			if( fil_dir == 1 && fil_esq == 1){
				sem_wait(&filosofos[i]);
				pthread_mutex_unlock(&vez);
				printf("[SUCESSO] Garfos %d e %d livres. Filosofo %d vai comer. Pegando os garfos...\n\n", i, i+1, i);
				sleep(0.5);
				printf("Filosofo %d comendo...\n\n", i);	
				sleep(1);
				printf("Filosofo %d terminou de comer. Liberando os garfos...\n\n",i);
				sem_post(&filosofos[i]);
			}else{
				printf("Filosofo %i nao pode pergar os garfos porque já estao ocupados.\n\n", i);
				sleep(1);
				printf("Filosofo %i voltando a pensar...\n\n", i);
				pthread_mutex_unlock(&vez);
			}		
	}
}

void inicializa_semaforos(){
	for(int i =0; i<QTD_F;i++)
    	sem_init(&filosofos[i], 1, 1); // semaforo, pista compartilhada por todos, capacidade C
}

int main(){
	pthread_t a[QTD_F];
	int i;
	int *id_filosofo;
	
	inicializa_semaforos();
	printf("\n============================= INICIO =============================\n");
	for(i=0; i<QTD_F; i++){
		id_filosofo = (int *) malloc(sizeof(int));
		*id_filosofo = i;
		pthread_create(&a[i], NULL, filosofo, (void *) (id_filosofo));
	}

	
	pthread_join(a[0],NULL);
	return 0;
}


