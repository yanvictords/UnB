all: file limpa

file: main.o modulo2.o modulo1.o listas.o
	gcc main.o modulo2.o listas.o -o teste

main.o: main.c modulo2.c modulo2.h modulo1.c modulo1.h listas.c listas.h
	gcc -c main.c

modulo2.o: modulo2.c modulo2.h
	gcc -c modulo2.c
modulo1.o: modulo1.c modulo1.h
	gcc -c modulo1.c
listas.o: listas.c listas.h
	gcc -c listas.c

limpa:
	rm *.o
