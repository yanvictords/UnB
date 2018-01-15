all: trabalho2 limpa
trabalho2: main.o modulo1.o modulo2.o grafos.o listas.o modulo4.o
	gcc -g main.o listas.o grafos.o modulo1.o modulo2.o modulo4.o -o trabalho
main: main.c modulo1.c modulo1.h modulo2.c modulo2.h listas.c listas.h grafos.c grafos.h modulo4.c modulo4.h
	gcc -c main.c
listas.o: listas.c listas.h
	gcc -c listas.c
modulo2.o: modulo2.c modulo2.h 
	gcc -c modulo2.c
grafos.o: grafos.c grafos.h
	gcc -c grafos.c		
modulo1.o: modulo1.c modulo1.h 
	gcc -c modulo1.c
modulo4.o: modulo4.c modulo4.h
	gcc -c modulo4.c
limpa:
	rm *.o

