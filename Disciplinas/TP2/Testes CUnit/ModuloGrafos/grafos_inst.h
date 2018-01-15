/*!
* \file grafos_inst.h
* \brief Modulo de declaracao das funcoes instrumentadas e estruturas de grafos.
*
* \author Icaro Marcelino Miranda.
* \since 01/07/2015.
* \version 1.0.
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

#ifndef GRAFOS_INST_ATIVO
	#define GRF_INST_Grafo_Vazio 			GRF_Grafo_Vazio
	#define GRF_INST_Verificar_Autor		GRF_Verificar_Autor
	#define GRF_INST_Verificar_Publicacao	GRF_Verificar_Publicacao
	#define GRF_INST_Quantidade_Publicacoes GRF_Quantidade_Publicacoes
	#define GRF_INST_Busca_por_Ano			GRF_Busca_por_Ano
	#define GRF_INST_Liberar_Grafo 			GRF_Liberar_Grafo
	#define GRF_INST_Imprimir_Grafo 		GRF_Imprimir_Grafo
	#define GRF_INST_Busca_por_Publicacao 	GRF_Busca_por_Publicacao
	#define GRF_INST_Gerar_Arquivo 			GRF_Gerar_Arquivo
	#define GRF_INST_Busca_por_Autor 		GRF_Busca_por_Autor
	#define GRF_INST_Criar_Grafo 			GRF_Criar_Grafo
	#define GRF_INST_Insere_Nova_Publicacao GRF_Insere_Nova_Publicacao
	#define GRF_INST_Remove_Publicacao 		GRF_Remove_Publicacao
	#define GRF_INST_Insere_Autor 			GRF_Insere_Autor
	#define GRF_INST_ListaPeriodicos_Grafo 	GRF_ListaPeriodicos_Grafo
	#define GRF_INST_ListaEventos_Grafo 	GRF_ListaEventos_Grafo
	#define GRF_INST_ListaProjetos_Grafo 	GRF_ListaProjetos_Grafo
	#define	GRF_INST_Pause 					GRF_Pause
	#define GRAFOS_INST_ATIVO
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

/* Para facilitar a manutencao do modulo, caso o servidor
* mude o nome das suas estruturas.
*/
typedef Listadocentes* pDocentes;
typedef Listadiscentes* pDiscentes;
typedef Listadiscentesexternos* pDiscentesEXT;
typedef listadeprojetosfinal* pProjetos;
typedef listaDePeriodicosFinal* pPeriodicos;
typedef listaDeEventosFinal* pEventos;

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

/** Funcões genericas **/
/* 18 */	void GRF_Pause(void);