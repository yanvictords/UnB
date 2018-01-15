#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "listas.h"

Grafo* criaGrafoVazio(int numProfs){
	Grafo* graf = (Grafo*) malloc(sizeof(Grafo));
	graf->numProfs = numProfs;
	graf->MARCA = (int*)malloc(sizeof(int));

	int i;
	for(i=0;i<numProfs;i++)
		graf->MARCA[i] = NAOVISITADO;

	graf->Docentes = (ListaG**) malloc(numProfs*sizeof(ListaG*));

	for(i=0;i<numProfs;i++)
		graf->Docentes[i] = NULL;

	return graf;
}

ListaG* anexa(ValorVertice Prof, ListaG* Lista){
	ListaG*aux2=Lista;
	ListaG* auxiliar = (ListaG*) malloc(sizeof(ListaG));
	strcpy(auxiliar->nome_Professor,Prof);
	while(aux2->prox!=NULL){aux2=aux2->prox;}
		aux2->prox=auxiliar;

	return Lista;
}

Grafo* iniciagrafoind(listaDeProfessores* listaProfessores, Grafo*grafo){
	int i;
	listaDeProfessores* aux = listaProfessores;
	for(i=0;i<aux->numDeProfessores;i++){
		ListaG* auxiliar = (ListaG*) malloc(sizeof(ListaG));
		strcpy(auxiliar->nome_Professor,listaProfessores->nomeProfessor);
		auxiliar->prox = NULL;
		grafo->Docentes[i]=auxiliar;
		listaProfessores = listaProfessores->proximoProfessor;		
	}
	return grafo;
}

int confererepeticao(ValorVertice responsavel, ListaG* lista){
	while(lista!=NULL){
		if(strcmp(lista->nome_Professor, responsavel)==0)
			return 0;
		lista=lista->prox;
	}
	return 1;
}





Grafo* insereRelacionamento(listaDeProfessores*list, Grafo* grafo, listaDeProjetos* aux){
		int Prof1 = list->id;
	
	while(aux!=NULL){
		if(strcmp(grafo->Docentes[Prof1]->nome_Professor, aux->integrante1)==0){
			if(confererepeticao(aux->responsavel, grafo->Docentes[Prof1])==1)
			grafo->Docentes[Prof1]=anexa(aux->responsavel, grafo->Docentes[Prof1]); 
		}
		if(strcmp(grafo->Docentes[Prof1]->nome_Professor, aux->integrante2)==0){
			if(confererepeticao(aux->responsavel, grafo->Docentes[Prof1])==1)
			grafo->Docentes[Prof1]=anexa(aux->responsavel, grafo->Docentes[Prof1]); 
		}
		aux = aux->proximoProjeto;	
	}
	return grafo;	
}




