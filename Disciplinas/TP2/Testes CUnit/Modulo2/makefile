
all: modulo2.o modulo2_teste.c
	gcc -I./CUnit -L./CUnit modulo2_teste.c modulo2.c -lcunit -o testemod2

modulo2.o: listas.o modulo1.o modulo2.c modulo2.h
	gcc -c -Wall modulo2.c 

listas.o: listas.c listas.h
	gcc -c -Wall listas.c

modulo1.o: modulo1.c modulo1.h
	gcc -c -Wall modulo1.c
