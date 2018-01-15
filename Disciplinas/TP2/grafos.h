/*!
* \file grafos.h
* \brief Modulo de declaracao das funcoes e estruturas de grafos.
*
* \author Icaro Marcelino Miranda.
* \since 01/06/2015.
* \version 2.0.
*
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
#ifndef MODULO2_H_INCLUDED
	#define MODULO2_H_INCLUDED
	#include "modulo2.h"
#endif

typedef char* string;

struct lista{
	string info;
	struct lista *down;
	struct lista *up;
	int ano;
};
typedef struct lista* PLista;

struct grafo{
	struct lista* inicio;
	int qnt;
};
typedef struct grafo Grafo;

/** Funcoes de manipulacao de grafos. **/
/* 01 */	int 	GRF_Grafo_Vazio(Grafo*);
/* 02 */	int 	GRF_Verificar_Autor(Grafo*, string);
/* 03 */	int 	GRF_Verificar_Publicacao(Grafo*, string);
/* 04 */	int 	GRF_Quantidade_Publicacoes(Grafo*);
/* 05 */	void	GRF_Busca_por_Ano(Grafo*, int);
/* 06 */	void 	GRF_Liberar_Grafo(Grafo*);
/* 07 */	void 	GRF_Imprimir_Grafo(Grafo*);
/* 08 */	void 	GRF_Busca_por_Publicacao(Grafo*, string);
/* 09 */	void 	GRF_Gerar_Arquivo(Grafo*, string);
/* 10 */	void 	GRF_Busca_por_Autor(Grafo*, string);
/* 11 */	Grafo* 	GRF_Criar_Grafo(void);
/* 12 */	Grafo* 	GRF_Insere_Nova_Publicacao(Grafo*, string, int);
/* 13 */	Grafo* 	GRF_Remove_Publicacao(Grafo*, string);
/* 14 */	Grafo* 	GRF_Insere_Autor(Grafo*, string, string);
/* 15 */	Grafo* 	GRF_ListaPeriodicos_Grafo(listaDePeriodicosFinal*);
/* 16 */	Grafo* 	GRF_ListaEventos_Grafo(listaDeEventosFinal*);
/* 17 */	Grafo* 	GRF_ListaProjetos_Grafo(listadeprojetosfinal*);
/* 18 */	Grafo* 	GRF_Grafo_Relacionamentos_Projetos(listadeprojetosfinal*);
/* 19 */	Grafo* 	GRF_Grafo_Relacionamentos_Eventos(listaDeEventosFinal*);
/* 20 */	Grafo* 	GRF_Grafo_Relacionamentos_Periodicos(listaDePeriodicosFinal*);

/** Funcões genericas **/
/* 21 */	void GRF_Pause(void);


