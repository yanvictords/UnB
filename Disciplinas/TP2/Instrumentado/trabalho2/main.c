
/*!
* \file main.c
* \brief Modulo principal do programa
*
* \author Todos os integrantes do grupo.
* \since 01/06/2015.
* \version 1.6.
*/
#ifndef STDIO_INST_H_INCLUDED
	#define STDIO_INST_H_INCLUDED
	#include <stdio.h>
#endif
#ifndef STDLIB_INST_H_INCLUDED
	#define STDLIB_H_INCLUDED
	#include <stdlib.h>
#endif
#ifndef STRING_INST_H_INCLUDED
	#define STRING_H_INCLUDED
	#include <string.h>
#endif
#ifndef LISTAS_H_INCLUDED
	#define LISTAS_H_INCLUDED
	#include "listas.h"
#endif
#ifndef GRAFOS_INST_H_INCLUDED
	#define GRAFOS_INST_H_INCLUDED
	#include "grafos_inst.h"
#endif
#ifndef MODULO1_INST_H_INCLUDED
	#define MODULO1_INST_H_INCLUDED
	#include "modulo1_inst.h"
#endif
#ifndef MODULO2_INST_H_INCLUDED
	#define MODULO2_INST_H_INCLUDED
	#include "modulo2_inst.h"
#endif
#ifndef MODULO4_INST_H_INCLUDED
	#define MODULO4_INST_H_INCLUDED
	#include "modulo4_inst.h"
#endif

typedef struct listadeprojetos listadeprojetosfinal;
typedef struct listaEventosFinal listaDeEventosFinal;
typedef struct listaPeriodicosFinal listaDePeriodicosFinal;
int main(){
listaDeEventosFinal*listaFinal=NULL;
listadeprojetosfinal*listaFinal2=NULL;
listaDePeriodicosFinal*listaFinal3=NULL;
printf("\n**************---------AVISO------------**************\n");
printf("Antes de tudo, verifique se o diretorio digitado na main.c eh valido. Se nao for valido, digite um quando for solicitado a seguir seguindo o modelo do exemplo. Se preferir, altere no array 'diretorio' dentro da main.c e recompile o codigo!\n\n");
printf("OBS.: Nao digite no final do seu diretorio '/trabalho2/Arquivos/' !!! Pois o programa fara isso por voce. Um diretorio incorreto pode causar falhas de segmentacao ou erros no arquivo de saida ja que o programa nao podera encontrar os arquivos para a leitura!\n");
printf("**************---------AVISO------------**************\n");

char diretorio[300] = "/home/yan/Documentos"; /*ALTERE O DIRETORIO PARA O LUGAR ONDE COLOCASTES A PASTA "trabalho2"*/

	listaDeProjetos* ListaProjetos = txtProjetosEmLista("projetos.txt");
	listaDeProfessores* ListaProfessores = txtDocentesEmLista("projetos.txt");
	listaDeAlunos* ListaAlunos = txtDiscentesEmLista("discentes_doutorado.txt", "discentes_mestrado.txt");
	listaDeEventos* ListaEventos = txtEventosEmLista(diretorio, "publicacao_eventos.txt", "Genaina Rodrigues"); //NOME DA PASTA DO PROF
	listaDePeriodicos* ListaPeriodicos = txtPeriodicosEmLista(diretorio, "publicacao_periodico.txt", "Genaina Rodrigues"); //NOME DA PASTA DO PROF

listaDeProjetos* pro = ListaProjetos;
listaDePeriodicos* per = ListaPeriodicos;
listaDeEventos* eve = ListaEventos;


	while(ListaProjetos!=NULL){
	listaFinal2 = INSERE_NA_LISTADEPROJETOSFINAL(listaFinal2,ListaProjetos,ListaAlunos,ListaProfessores);
	ListaProjetos=ListaProjetos->proximoProjeto;
	}
	listaFinal2=listaFinal2->prox;
	
	while(ListaEventos!=NULL){
	listaFinal = insereNaListadeEventosFinal(listaFinal,ListaEventos,ListaAlunos,ListaProfessores);
	ListaEventos=ListaEventos->proximoEvento;
	}
	listaFinal=listaFinal->prox;

	while(ListaPeriodicos!=NULL){
		listaFinal3 = insereNaListadePeriodicosFinal(listaFinal3,ListaPeriodicos,ListaAlunos,ListaProfessores);
		ListaPeriodicos=ListaPeriodicos->proximoPeriodico;
	}
	listaFinal3=listaFinal3->prox;
	


 Grafo* Relacionamento_Periodico;
 Grafo* Relacionamento_Eventos;
 Grafo* Relacionamento_Projetos;

 Relacionamento_Periodico 	= GRF_ListaPeriodicos_Grafo(listaFinal3);
 Relacionamento_Eventos 	= GRF_ListaEventos_Grafo(listaFinal);
 Relacionamento_Projetos 	= GRF_ListaProjetos_Grafo(listaFinal2);

 /*printf("\nImpressão do Grafo de relacionamentos (Periodicos):\n");
 GRF_Pause();
 GRF_Imprimir_Grafo(Relacionamento_Periodico);

 printf("\nImpressão do Grafo de relacionamentos (Eventos):\n");
 GRF_Pause();
 GRF_Imprimir_Grafo(Relacionamento_Eventos);

printf("\nImpressão do Grafo de relacionamentos (Projetos):\n");
 GRF_Pause();
 GRF_Imprimir_Grafo(Relacionamento_Projetos);

 printf("\nGerando arquivo: Relacionamento_Periodicos.txt, Relacionamento_Eventos.txt, Relacionamento_Projetos.txt\n");
 GRF_Gerar_Arquivo(Relacionamento_Periodico, "Relacionamento_Periodicos.txt");
 GRF_Gerar_Arquivo(Relacionamento_Eventos, "Relacionamento_Eventos.txt");
 GRF_Gerar_Arquivo(Relacionamento_Projetos, "Relacionamento_Projetos.txt");
 printf("\nArquivos gerados com sucesso.\n");
*/


print(listaFinal, listaFinal2,listaFinal3, Relacionamento_Periodico, Relacionamento_Eventos, Relacionamento_Projetos);


 GRF_Liberar_Grafo(Relacionamento_Periodico);
 GRF_Liberar_Grafo(Relacionamento_Eventos);
 GRF_Liberar_Grafo(Relacionamento_Projetos);


printf("\n\n.......................................\n");
printf("Trabalho feito por: Hugo Fagundes, Icaro Marcelino, Pedro Gonzaga e Yan Victor.\n");
printf(".......................................\n\n");
	return 0;
}
