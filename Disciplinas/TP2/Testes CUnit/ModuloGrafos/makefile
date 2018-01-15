all: grafos.o grafos_teste.c
	gcc -I./CUnit -L./CUnit grafos_teste.c -lcunit -o teste
	rm *.o
	./teste

grafos.o: listas.o modulo2.o grafos.h grafos.c
	gcc -c -Wall grafos.c

listas.o: listas.h listas.c
	gcc -c -Wall listas.c

modulo2.o: modulo2.h modulo2.c
	gcc -c modulo2.c
