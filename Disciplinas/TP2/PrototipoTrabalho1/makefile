all: compila limpa

compila: trabmain.o listas.o modulo1.o modulo2.o grafo.o modulo4.o
	gcc trabmain.o listas.o modulo1.o modulo2.o grafo.o modulo4.o -o Compilado -g

trabmain.o: trabmain.c listas.c listas.h modulo1.c modulo1.h modulo2.c modulo2.h grafo.c grafo.h modulo4.c modulo4.h
	gcc -c trabmain.c

listas.o: listas.c listas.h
	gcc -c listas.c

modulo1.o: modulo1.c modulo1.h
	gcc -c modulo1.c

modulo2.o: modulo2.c modulo2.h
	gcc -c modulo2.c

grafo.o: grafo.c grafo.h
	gcc -c grafo.c

modulo4.o: modulo4.c modulo4.h
	gcc -c modulo4.c

limpa: 
	rm *.o
