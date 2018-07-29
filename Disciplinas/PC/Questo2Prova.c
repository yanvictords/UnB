// [Estudo dirigido] Questão 2 da prova utilizando barreiras
// YAN VICTOR DOS SANTOS
// PROGRAMAÇÃO CONCORRENTE - 1/2018
// CÓDIGO FEITO POR MIM! E
// A lógica foi desenvolvida juntamente com a aluna Dayanne (aluna também da disciplina)

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "pthread.h"
#include "string.h"

#define QTD_A_C 5
#define QTD_B_D 14

pthread_barrier_t barreira;
pthread_mutex_t lock;
int flag=0;
void * mostra_A_C(void *arg){
	int i = *(int *)(arg);
	while(1){
		printf("A");
		pthread_barrier_wait(&barreira); //liberar para B

		pthread_mutex_lock(&lock); // permintindo que no fim uma thread possa dar o "\n"
		if(!flag)
			flag++;
		pthread_mutex_unlock(&lock);

		pthread_barrier_wait(&barreira); //printando B
		printf("C");
		pthread_barrier_wait(&barreira); // libera D
		
		pthread_barrier_wait(&barreira);
	
		pthread_mutex_lock(&lock); //apenas uma thread dara o "\n"
		if(flag){
			printf("\n");
			sleep(1);
			flag--;
		} 
		pthread_mutex_unlock(&lock);
	}
}

void * mostra_B_D(void *arg){
	int i = *(int *)(arg);
	while(1){
		pthread_barrier_wait(&barreira); //printando A
		printf("B");
		pthread_barrier_wait(&barreira); // liberar para C
		
		pthread_barrier_wait(&barreira); 
		printf("D");
		pthread_barrier_wait(&barreira);
	}
}

int main(){
	pthread_t a[QTD_A_C + QTD_B_D];
	int i;
	int *id_thread;	
	printf("\n============================= INICIO =============================\n");

	pthread_barrier_init(&barreira, NULL, QTD_A_C + QTD_B_D);
	
	for(i=0; i<QTD_A_C; i++){
		id_thread = (int *) malloc(sizeof(int));
		*id_thread = i;
		pthread_create(&a[i], NULL, mostra_A_C, (void *) (id_thread));
	}
	for(i=0; i<QTD_B_D; i++){
		*id_thread = QTD_A_C+i;
		pthread_create(&a[QTD_A_C+i], NULL, mostra_B_D, (void *) (id_thread));
	}
	pthread_join(a[0],NULL);
	printf("\n");

	return 0;
}


