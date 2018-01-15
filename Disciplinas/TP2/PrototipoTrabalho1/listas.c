#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listas.h"

listaDeProjetos* criaListaDeProjetos(void){
	return NULL;
}

listaDeProfessores* criaListaDeProfessores(void){
	return NULL;
}

listaDeAlunos*criaListaDeAlunos(void){
	return NULL;

}

listaDeProjetos* insereEmListaDeProjetos(listaDeProjetos* Lista, char *nomeProjeto, int anoInicio, 
											int mesFim, int anoFim, char *situacao, char *natureza, 
												char *descricao, char *responsavel, char *integrante1, char *integrante2){
	listaDeProjetos *Nodo = (listaDeProjetos*) malloc(sizeof(listaDeProjetos));
	Nodo->proximoProjeto = NULL;
	strcpy(Nodo->nomeProjeto, nomeProjeto);
	Nodo->anoInicio = anoInicio;
	Nodo->mesFim = mesFim;
	Nodo->anoFim = anoFim;
	strcpy(Nodo->responsavel, responsavel);
	strcpy(Nodo->integrante1, integrante1);
	strcpy(Nodo->integrante2, integrante2);
	strcpy(Nodo->natureza, natureza);
	strcpy(Nodo->situacao, situacao);
	strcpy(Nodo->descricao, descricao);
	if (Lista == NULL){
		Lista = Nodo;
	}else{ 
		Nodo->proximoProjeto = Lista->proximoProjeto;
		Lista->proximoProjeto = Nodo;
	}
	return Lista;
}
int confereSeProfessorJaEstaNaLista(listaDeProfessores* Lista, char* nomeProfessor){
	while(Lista!=NULL){
	if (strcmp(Lista->nomeProfessor, nomeProfessor)==0)
		return 1;
		Lista = Lista->proximoProfessor;
	}
	return 0;
}
listaDeProfessores* insereEmListaDeProfessores(listaDeProfessores *Lista, char* nomeProfessor, char* nomeParaCitacao){


	if (Lista == NULL){
		listaDeProfessores *Nodo = (listaDeProfessores*) malloc(sizeof(listaDeProfessores));
		Nodo->proximoProfessor = NULL;
		strcpy(Nodo->nomeProfessor, nomeProfessor);
		strcpy(Nodo->nomeParaCitacao, nomeParaCitacao);
		Nodo->numDeProfessores = 1;
		Nodo->id = 0;
		return Nodo;

	}else{


		int repeticaoDeProfessores = confereSeProfessorJaEstaNaLista(Lista, nomeProfessor);

		/* Se o valor retornado pela funcao "confereSeProfessorJaEstaNaLista" for 0 eh porque nao esta ainda,
			portanto, acrescenta o professor ah lista */

		if(repeticaoDeProfessores==0){
			listaDeProfessores *Nodo = (listaDeProfessores*) malloc(sizeof(listaDeProfessores));
			Nodo->proximoProfessor = NULL;
			listaDeProfessores *aux2 = Lista;
			strcpy(Nodo->nomeProfessor, nomeProfessor);
			strcpy(Nodo->nomeParaCitacao, nomeParaCitacao);
			Lista->numDeProfessores++;
			Nodo->id = Lista->numDeProfessores - 1;
			while(aux2->proximoProfessor!=NULL)
				aux2 = aux2->proximoProfessor;
				aux2->proximoProfessor = Nodo;
		}
		return Lista;
	}
}



listaDeAlunos* insereEmListaDeAlunos(listaDeAlunos *Lista, char* nomeAluno, char* matricula, int tipo){
	listaDeAlunos *Nodo = (listaDeAlunos*) malloc(sizeof(listaDeAlunos));
	Nodo->proximoAluno = NULL;
	strcpy(Nodo->nomeAluno, nomeAluno);
	strcpy(Nodo->matricula, matricula);
	Nodo->tipo = tipo;

	if (Lista == NULL){
		Lista = Nodo;
	}else{ 
		Nodo->proximoAluno = Lista->proximoAluno;
		Lista->proximoAluno = Nodo;
	}
	return Lista;
}


