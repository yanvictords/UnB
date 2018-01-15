all: listas.o listas_teste.c
	gcc -I./CUnit -L./CUnit listas_teste.c -lcunit -o teste
	rm *.o
	./teste

listas.o: listas.h listas.c
	gcc -c -Wall listas.c
