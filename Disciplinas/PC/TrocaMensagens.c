// [Estudo Dirigido] Produtor consumidor com troca de mensagens
// YAN VICTOR DOS SANTOS
// PROGRAMAÇÃO CONCORRENTE - 1/2018

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#include <math.h>
#include <unistd.h>


void producer(MPI_Status status, int tag){
	int id_consumer;

	while(1){
    	MPI_Recv(&id_consumer, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG,MPI_COMM_WORLD, &status);
		printf("Consumidor %d quer consumir\n", id_consumer);
		sleep(1);
		MPI_Send(&id_consumer, 1, MPI_INT, id_consumer, tag, MPI_COMM_WORLD);
	}
}

void consumer(int myid, MPI_Status status, int tag){
	int item;
	while(1){
		MPI_Send(&myid, 1, MPI_INT, myid, tag, MPI_COMM_WORLD);
     	MPI_Recv(&item, 1, MPI_INT, myid, MPI_ANY_TAG,MPI_COMM_WORLD, &status);
		printf("Consumidor %d esta consumindo item %d\n\n", myid, item);
		sleep(1);
	}
}

int main(int argc, char *argv[]) {
   int myid, otherid, size;
   int length = 1, tag = 1;
   MPI_Status status;
   /* initialize MPI and get own id (rank) */
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &myid);
   MPI_Comm_size(MPI_COMM_WORLD, &size); 
   
   if(myid == 1)
		producer(status, tag);
   else
	    consumer(myid, status, tag);

   MPI_Finalize();
   return 0;
}
