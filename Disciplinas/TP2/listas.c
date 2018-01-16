/*!
* \file listas.c
* \brief Modulo de implementacao de listas.
*/

#ifndef STDIO_H_INCLUDED
	#define STDIO_H_INCLUDED
	#include <stdio.h>
#endif
#ifndef STDLIB_H_INCLUDED
	#define STDLIB_H_INCLUDED
	#include <stdlib.h>
#endif
#ifndef STRING_H_INCLUDED
	#define STRING_H_INCLUDED
	#include <string.h>
#endif
#ifndef LISTAS_H_INCLUDED
	#define LISTAS_H_INCLUDED
	#include "listas.h"
#endif

/*!
* \brief Cria uma lista de projetos.
*
* \return Ponteiro para a lista vazia.
*/
listaDeProjetos* criaListaDeProjetos(void){
	return NULL;
}

/*!
* \brief Cria uma lista de professores.
*
* \return Ponteiro para a lista vazia.
*/
listaDeProfessores* criaListaDeProfessores(void){
	return NULL;
}

/*!
* \brief Cria uma lista de alunos.
*
* \return Ponteiro para a lista vazia.
*/
listaDeAlunos*criaListaDeAlunos(void){
	return NULL;
}

/*!
* \brief Cria uma lista de autores.
*
* \return Ponteiro para a lista vazia.
*/
listaDeAutores* criaListaDeAutores(void){
	return NULL;
}

/*!
* \brief Cria uma lista de eventos.
*
* \return Ponteiro para a lista vazia.
*/
listaDeEventos* criaListaDeEventos(void){
	return NULL;
}

/*!
* \brief Cria uma lista de periodicos.
*
* \return Ponteiro para a lista vazia.
*/
listaDePeriodicos* criaListaDePeriodicos(void){
	return NULL;
}

/*!
* \brief Insere um novo periodico em uma lista de periodicos.
*
* \param ListaPeriodicos Lista a receber as informacoes.
* \param ListaAutores Lista de autores do periodico.
* \param nomeProfessor Nome do professor (ate 100 caracteres).
* \param nomeParaCitacao_Professor String com nomes para citacao do professor (ate 300 caracteres).
* \param natureza Natureza do periodico (ate 30 caracteres).
* \param tituloArtigo Titulo do artigo (ate 200 caracteres).
* \param tituloPeriodico Titulo do periodico (ate 200 caracteres).
* \param idioma Idioma do periodico (ate 30 caracteres).
* \param ano Ano da publicacao (ate 10 caracteres).
* \param serie Serie (ate 50 caracteres).
* \param volume Volume (ate 30 caracteres).
* \param paginaInicial Pagina Inicial (ate 10 caracteres).
* \param paginaFinal Pagina final (ate 10 caracteres).
*
* \return Ponteiro para lista atualizada.
*/
listaDePeriodicos* insereEmListaDePeriodicos(listaDePeriodicos *ListaPeriodicos, listaDeAutores *ListaAutores , char* nomeProfessor,
											char* nomeParaCitacao_Professor, char* natureza, char* tituloArtigo, char* tituloPeriodico, 
											char* idioma, char* ano, char* serie, char* volume, char* paginaInicial, char* paginaFinal){
	listaDePeriodicos *Nodo = (listaDePeriodicos*) malloc(sizeof(listaDePeriodicos));

	strcpy(Nodo->nomeProfessor, nomeProfessor);
	strcpy(Nodo->nomeParaCitacao_Professor, nomeParaCitacao_Professor);
	strcpy(Nodo->natureza, natureza);
	strcpy(Nodo->tituloArtigo, tituloArtigo);
	strcpy(Nodo->tituloPeriodico, tituloPeriodico);
	strcpy(Nodo->idioma, idioma);
	strcpy(Nodo->ano, ano);
	strcpy(Nodo->serie, serie);
	strcpy(Nodo->volume, volume);
	strcpy(Nodo->paginaInicial, paginaInicial);
	strcpy(Nodo->paginaFinal, paginaFinal);
	Nodo->autores = ListaAutores;
	
	if (ListaPeriodicos == NULL){
		ListaPeriodicos = Nodo;
	}else{ 
		Nodo->proximoPeriodico = ListaPeriodicos->proximoPeriodico;
		ListaPeriodicos->proximoPeriodico = Nodo;
	}

	return ListaPeriodicos;	
}

/*!
* \brief Insere um novo evento em uma lista de eventos.
*
* \param ListaEventos Ponteiro para a lista de eventos a reeber as informacoes.
* \param ListaAutores Ponteiro para a lista de autores do evento.
* \param nomeParaCitacao_Professor Nome do professor (ate 100 caracteres).
* \param nomeParaCitacao_Professor String com os nomes para citacao do professor (ate 300 caracteres).
* \param natureza Natureza do evento (ate 30 caracteres).
* \param titulo Titulo da publicacao (ate 200 caracteres).
* \param pais Pais em que o evento foi realizado (ate 30 caracteres).
* \param idioma Idioma da publicacao (ate 30 caracteres).
* \param nomeEvento Nome do evento (ate 100 caracteres).
* \param ano Ano da realizacao (ate 10 caracteres).
* \param proceedings Procedimentos (ate 300 caracteres)
* \param volume Volume (ate 30 caracteres).
* \param paginaInicial Pagina inicial (ate 10 caracteres).
* \param paginaFinal Pagina final (ate 10 caracteres).
*
* \return Ponteiro para a lista atualizada.
*/
listaDeEventos* insereEmListaDeEventos(listaDeEventos *ListaEventos, listaDeAutores *ListaAutores, char* nomeProfessor, char* nomeParaCitacao_Professor, 
										char* natureza, char* titulo, char* pais, char* idioma, char* nomeEvento, char* ano, char* proceedings, char* volume,
										char* paginaInicial, char* paginaFinal){

	listaDeEventos *Nodo = (listaDeEventos*) malloc(sizeof(listaDeEventos));

	strcpy(Nodo->nomeProfessor, nomeProfessor);
	strcpy(Nodo->nomeParaCitacao_Professor , nomeParaCitacao_Professor);
	strcpy(Nodo->natureza, natureza);
	strcpy(Nodo->titulo, titulo);
	strcpy(Nodo->pais, pais);
	strcpy(Nodo->idioma, idioma);
	strcpy(Nodo->nomeEvento, nomeEvento);
	strcpy(Nodo->ano, ano);
	strcpy(Nodo->proceedings, proceedings);
	strcpy(Nodo->volume, volume);
	strcpy(Nodo->paginaInicial, paginaInicial);
	strcpy(Nodo->paginaFinal, paginaFinal);
	Nodo->autores = ListaAutores;

	if (ListaEventos == NULL){
		ListaEventos = Nodo;
	}else{ 
		Nodo->proximoEvento = ListaEventos->proximoEvento;
		ListaEventos->proximoEvento = Nodo;
	}

	return ListaEventos;
}

/*!
* \brief Insere um novo autor em uma lista de autores.
* 
* \param Lista Ponteiro para lista de autores a receber a informacao.
* \param nomeAutor Nome do autor a ser inserido (ate 100 caracteres).
* \param nomeParaCitacao String com nomes para citacao do professor (ate 300 caracteres).
* \param ordemDeAutoria Ordem de autoria (ate 4 caracteres).
*
* \return Ponteiro para a lista atualizada.
*/
listaDeAutores* insereEmListaDeAutores(listaDeAutores *Lista, char* nomeAutor, char* nomeParaCitacao, char* ordemDeAutoria){
	listaDeAutores *Nodo = (listaDeAutores*) malloc(sizeof(listaDeAutores));
	Nodo->proximoAutor = NULL;
	strcpy(Nodo->nomeAutor, nomeAutor);
	strcpy(Nodo->nomeParaCitacao, nomeParaCitacao);
	strcpy(Nodo->ordemDeAutoria, ordemDeAutoria);

	if (Lista == NULL){
		Lista = Nodo;
	}else{ 
		Nodo->proximoAutor = Lista->proximoAutor;
		Lista->proximoAutor = Nodo;
	}
	return Lista;
}

/*!
* \brief Insere um novo projeto em uma lista de projetos.
*
* \param Lista Lista de projetos a receber a informacao.
* \param nomeProjeto Nome do projeto (ate 300 caracteres).
* \param anoInicio Ano de incio.
* \param mesFim Mes do fim do projeto.
* \param anoFim Ano do fim do projeto.
* \param situacao Situação do projeto (ate 20 caracteres).
* \param natureza Natureza do projeto (ate 20 caracteres).
* \param descricao Descricao do projeto (ate 500 caracteres).
* \param responsavel Responsavel do projeto (ate 100 caracteres).
* \param integrante1 Nome de participante (ate 100 caracteres).
* \param integrante2 Nome de participante (ate 100 caracteres).
*
* \return Ponteiro para a lista atualizada.
*/
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

/*!
* \brief Confere se um Professor esta presente em uma lista de professores.
*
* \param Lista Ponteiro para lista de professores a ser verificada.
* \param nomeProfessor Nome do professor a ser pesquisado (ate 100 caracteres).
*
* \return Se o nome do professor consta na lista retorna 1, se nao retorna 0.
*/
int confereSeProfessorJaEstaNaLista(listaDeProfessores* Lista, char* nomeProfessor){
	while(Lista!=NULL){
	if (strcmp(Lista->nomeProfessor, nomeProfessor)==0)
		return 1;
		Lista = Lista->proximoProfessor;
	}
	return 0;
}

/*!
* \brief Insere um nome de professor em uma lista de professores.
*
* \param Lista Ponteiro para lista de professores a receber a informacao.
* \param nomeProfessor Nome do professor a ser inserido (ate 100 caracteres).
* \param nomeParaCitacao String com os nomes para citacao do professor (ate 300 caracteres).
*
* \return Ponteiro para a lista atualizada.
*/
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

/*!
* \brief Insere um nome de aluno em uma lista de alunos.
*
* \param Lista Ponteiro para lista de alunos a receber a informacao.
* \param nomeAluno Nome do aluno a ser inserido (ate 100 caracteres).
* \param matricula Matricula do aluno (ate 10 caracteres).
* \param tipo 1 para mestrado, 2 para doutorado.
*
* \return Ponteiro para a lista atualizada.
*/
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
