// [Estudo Dirigido] Problema dos macacos
// YAN VICTOR DOS SANTOS
// PROGRAMAÇÃO CONCORRENTE - 1/2018
// CÓDIGO FEITO POR MIM!

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "pthread.h"

pthread_mutex_t  LOCAL_mutexA= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t  LOCAL_mutexB = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t  OPPOSITE_bridge = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t  GLOBAL_turn = PTHREAD_MUTEX_INITIALIZER;
#define T 4
int ngoing = 0;
int ncoming = 0;
int flag;
void * m_going(void *arg){
	int i=*((int*) arg);
	while(1){
	        pthread_mutex_lock(&GLOBAL_turn);
        		pthread_mutex_lock(&LOCAL_mutexA);
        			printf("::: >>>>>>>>>>>>>>> O macaco %d está querendo ir >>>>>>>>>>>>>>> :::\n", i);
				ngoing++;
 				if(ngoing == 1){
					printf("TURNO ::: O macaco %d pegou o turno para a tentativa de reserva de IDA ::: TURNO\n", i);
        	     			pthread_mutex_lock(&OPPOSITE_bridge);
					printf("\n>>>>>>>>>>>>>>>-------------------------CORDA RESERVADA PARA IDA------------------------------------\n");
				}
        		pthread_mutex_unlock(&LOCAL_mutexA);
	        pthread_mutex_unlock(&GLOBAL_turn);
		printf("==========>>> O macaco %d está atravessando ==========>>>\n", i);
		sleep(1);
		printf("%d ::::::::::: Saindo da corda :::::::::: \n", i);
	        pthread_mutex_lock(&LOCAL_mutexA);
			ngoing--;
			if(ngoing == 0){
				pthread_mutex_unlock(&OPPOSITE_bridge);
	            		printf("-------------------------------CORDA LIBERADA------------------------------------\n\n");
			}
		pthread_mutex_unlock(&LOCAL_mutexA);
	}
	pthread_exit(0);
}

void * m_coming(void *arg){
	int i=*((int*) arg);
	while(1){
        	pthread_mutex_lock(&GLOBAL_turn);
		        pthread_mutex_lock(&LOCAL_mutexB);
			        printf("::: <<<<<<<<<<<<<<< O macaco %d está querendo voltar <<<<<<<<<<<<<<< :::\n", i);
				ncoming++;
 				if(ncoming == 1){
					printf("TURNO ::: O macaco %d pegou o turno para a tentativa de reserva de VOLTA ::: TURNO\n", i);
					pthread_mutex_lock(&OPPOSITE_bridge);
					printf("\n<<<<<<<<<<<<<<<<-------------------------CORDA RESERVADA PARA VOLTA------------------------------------\n");	
				}
       	 		pthread_mutex_unlock(&LOCAL_mutexB);
       		pthread_mutex_unlock(&GLOBAL_turn);
		printf("<<<========== O macaco %d está atravessando <<<==========\n", i);
		sleep(1);
		printf("%d ::::::::::: Saindo da corda :::::::::: \n", i);
       		pthread_mutex_lock(&LOCAL_mutexB);
			ncoming--;
			if(ncoming == 0){
	            		printf("-------------------------------CORDA LIBERADA------------------------------------\n\n");
				pthread_mutex_unlock(&OPPOSITE_bridge);
			}
		pthread_mutex_unlock(&LOCAL_mutexB);
	}
	pthread_exit(0);
}

int main(){
	pthread_t a[T+T];
	int i;
	int *id_read;
	int *id_write;
	printf("\n============================= INICIO =============================\n");
	for(i=0; i<T; ++i){
		id_read = (int *) malloc(sizeof(int));
		id_write = (int *) malloc(sizeof(int));
		*id_read = i;
		*id_write = i+T;
		pthread_create(&a[i], NULL, m_going, (void *) (id_read));
		pthread_create(&a[i+T], NULL, m_coming, (void *) (id_write));
	}

	
	pthread_join(a[0],NULL);
	return 0;
}


