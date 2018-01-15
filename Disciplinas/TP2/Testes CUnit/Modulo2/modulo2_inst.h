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


#define INST_INSERE_NA_LISTADEPROJETOSFINAL INSERE_NA_LISTADEPROJETOSFINAL 
#define INST_insereNaListadeEventosFinal insereNaListadeEventosFinal
#define INST_insereNaListadePeriodicosFinal insereNaListadePeriodicosFinal
#define INST_crialistadeprojetosfinal crialistadeprojetosfinal


/*!
* \file modulo2.h
* \brief Modulo de declaracao das funcoes e estruturas do modulo2.c.
*
*/
typedef struct listaProj listaDeProjetos;
typedef struct listaEventos listaDeEventos;
typedef struct listaPeriodicos listaDePeriodicos;

typedef struct listadocentes{
	struct listadocentes*prox;
	char nomedocente[100];
}Listadocentes;

typedef struct listaAlunos listaDeAlunos;
typedef struct listaProf listaDeProfessores;

typedef struct listadiscentes{
	struct listadiscentes*prox;
	char nomediscente[100];
}Listadiscentes;


typedef struct listadiscentesexternos{
	struct listadiscentesexternos*prox;
	char nomediscenteexterno[300];
}Listadiscentesexternos;

typedef struct listadeprojetos {	
	char responsavel[100];
	char nomeprojeto[100];
	int anodeinicio;
	int anofim;
	char situacao[200];
	char natureza[200];
	char descricao[200];
	Listadocentes*docentes;
	Listadiscentes*discentes;
	Listadiscentesexternos*discentesexternos;
	struct listadeprojetos*prox;	
}listadeprojetosfinal;


struct listaEventosFinal{
	struct listaEventosFinal*prox;
	char nomeProfessor[100];
	char nomeParaCitacao_Professor[400];
	char natureza[30];
	char titulo[200];
	char pais[30];
	char idioma[30];
	char nomeEvento[100];
	char ano[10];
	char proceedings[300];
	char volume[30];
	char paginaInicial[10];
	char paginaFinal[10];
	Listadocentes*docentes;
	Listadiscentes*discentes;
	Listadiscentesexternos*discentesexternos;
}typedef listaDeEventosFinal;

struct listaPeriodicosFinal{
	struct listaPeriodicosFinal *prox;
	char nomeProfessor[100];
	char nomeParaCitacao_Professor[300];
	char natureza[30];
	char tituloArtigo[200];
	char tituloPeriodico[200];
	char idioma[30];
	char ano[10];
	char serie[50];
	char volume[30];
	char paginaInicial[10];
	char paginaFinal[10];
	Listadocentes*docentes;
	Listadiscentes*discentes;
	Listadiscentesexternos*discentesexternos;
}typedef listaDePeriodicosFinal;


listadeprojetosfinal*INSERE_NA_LISTADEPROJETOSFINAL(listadeprojetosfinal*lista1,listaDeProjetos*lista2, listaDeAlunos*lista3,listaDeProfessores*lista4);
listaDeEventosFinal*insereNaListadeEventosFinal(listaDeEventosFinal*lista1,listaDeEventos*lista2, listaDeAlunos*lista3,listaDeProfessores*lista4);
listaDePeriodicosFinal*insereNaListadePeriodicosFinal(listaDePeriodicosFinal*lista1,listaDePeriodicos*lista2, listaDeAlunos*lista3,listaDeProfessores*lista4);
listadeprojetosfinal *crialistadeprojetosfinal(void);
