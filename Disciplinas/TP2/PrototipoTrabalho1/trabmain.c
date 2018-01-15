#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "modulo2.h"
#include "modulo1.h"
#include "modulo4.h"
#include "grafo.h"


int main(){
int idProf;
listaDeAlunos* listaAlunos = txtDiscentesEmLista();
listaDeProfessores* listaProfessores = txtDocentesEmLista();
listaDeProjetos* listaProjetos = txtProjetosEmLista();
listadeprojetosfinal* listafinal = NULL;
listaDeProjetos* auxil=listaProjetos;
	while(auxil!=NULL){
		listafinal = INSERE_NA_LISTADEPROJETOSFINAL(listafinal,auxil,listaAlunos,listaProfessores);
		auxil = auxil->proximoProjeto;
	}
	listafinal=listafinal->prox;
	
	Grafo* grafo = criaGrafoVazio(listaProfessores->numDeProfessores);
	grafo = iniciagrafoind(listaProfessores, grafo);

	listaDeProfessores* auxiliar = listaProfessores;

	while(auxiliar!=NULL){		    
		grafo = insereRelacionamento(auxiliar, grafo, listaProjetos);
		auxiliar = auxiliar->proximoProfessor;
	}

	print(listafinal, grafo, listaProfessores);

return 0;
}
