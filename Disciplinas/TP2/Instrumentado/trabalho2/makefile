all: trabalho2 limpa
trabalho2: main.o modulo1_inst.o modulo2_inst.o grafos_inst.o listas.o modulo4_inst.o
	gcc -g main.o listas.o grafos_inst.o modulo1_inst.o modulo2_inst.o modulo4_inst.o -o trabalho2 
main.o: main.c modulo1_inst.c modulo1_inst.h modulo2_inst.c modulo2_inst.h listas.c listas.h grafos_inst.c grafos_inst.h modulo4_inst.c modulo4_inst.h
	gcc -c main.c
listas.o: listas.c listas.h
	gcc -c listas.c
modulo2_inst.o: modulo2_inst.c modulo2_inst.h 
	gcc -c modulo2_inst.c
grafos_inst.o: grafos_inst.c grafos_inst.h
	gcc -c grafos_inst.c		
modulo1_inst.o: modulo1_inst.c modulo1_inst.h 
	gcc -c modulo1_inst.c
modulo4_inst.o: modulo4_inst.c modulo4_inst.h
	gcc -c modulo4_inst.c
limpa:
	rm *.o

