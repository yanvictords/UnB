/*!
* \file modulo1.h
* \brief Modulo de declaracao das funcoes e estruturas do modulo1.c
*
*/

#ifndef STDIO_H_INCLUDED
	#define STDIO_INST_H_INCLUDED
	#include <stdio.h>
#endif
#ifndef STDLIB_INST_H_INCLUDED
	#define STDLIB_INST_H_INCLUDED
	#include <stdlib.h>
#endif
#ifndef STRING_INST_H_INCLUDED
	#define STRING_INST_H_INCLUDED
	#include <string.h>
#endif
#ifndef LISTAS_H_INCLUDED
	#define LISTAS_H_INCLUDED
	#include "listas.h"
#endif
#ifndef CTYPE_H_INCLUDED
	#define CTYPE_H_INCLUDED
	#include <ctype.h>
#endif

#ifndef M1_INST_ATIVO
	#define INST_abreArquivo			abreArquivo
	#define INST_corrigeNome			corrigeNome
	#define INST_corrigeNome2			corrigeNome2
	#define INST_txtDiscentesEmLista	txtDiscentesEmLista
	#define INST_txtDocentesEmLista		txtDocentesEmLista
	#define INST_txtProjetosEmLista		txtProjetosEmLista
	#define INST_txtEventosEmLista		txtEventosEmLista
	#define INST_txtPeriodicosEmLista	txtPeriodicosEmLista
	#define INST_file_size				file_size
	#define M1_INST_ATIVO
#endif

int file_size(char* file_name);

FILE* abreArquivo(char* arquivo, char* method);

/* Funcoes para corrigir o nome, visto que a leitura nos arquivos 
seria feia ate encontrar o "\n" */
void corrigeNome(char nome[100]);
void corrigeNome2(char nome[100]);

/* Funcoes que pega os dados dos arquivos txt e inserem nas listas
declaradas no lista.h */
listaDeAlunos* txtDiscentesEmLista(char* arquivo_doutorado, char* arquivo_mestrado);
listaDeProfessores* txtDocentesEmLista(char* arquivo);
listaDeProjetos* txtProjetosEmLista(char* arquivo);
listaDeEventos* txtEventosEmLista(char* str, char* arquivo, char*nomepasta);
listaDePeriodicos* txtPeriodicosEmLista(char* src, char* arquivo, char *nomepasta);

	
