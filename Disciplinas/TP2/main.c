
/*!
* \file main.c
* \brief Modulo principal do programa
*
* \author Todos os integrantes do grupo.
* \since 01/06/2015.
* \version 1.6.
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
#ifndef GRAFOS_H_INCLUDED
	#define GRAFOS_H_INCLUDED
	#include "grafos.h"
#endif
#ifndef MODULO1_H_INCLUDED
	#define MODULO1_H_INCLUDED
	#include "modulo1.h"
#endif
#ifndef MODULO2_H_INCLUDED
	#define MODULO2_H_INCLUDED
	#include "modulo2.h"
#endif
#ifndef MODULO4_H_INCLUDED
	#define MODULO4_H_INCLUDED
	#include "modulo4.h"
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
printf("OBS.: Nao digite no final do seu diretorio '/TrabalhoPS/Arquivos/' !!! Pois o programa fara isso por voce. Um diretorio incorreto pode causar falhas de segmentacao ou erros no arquivo de saida ja que o programa nao podera encontrar os arquivos para a leitura!\n");
printf("**************---------AVISO------------**************\n");

char diretorio[300] = "/root/Documentos/UnB/Disciplinas/"; /*ALTERE O DIRETORIO PARA O LUGAR ONDE COLOCASTES A PASTA "TrabalhoPS"*/

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



print(listaFinal, listaFinal2,listaFinal3, Relacionamento_Periodico, Relacionamento_Eventos, Relacionamento_Projetos);

GRF_Pause();






busca:

system("clear");

int op, Ano;
char Nome[100];

printf("\n> Pesquisa em Grafo:\n");
printf("\t(1) Pesquisa por nome.\n");
printf("\t(2) Pesquisa por publicacao.\n");
printf("\t(3) Pesquisa por ano.\n ");
printf("\t(0) Sair.\n> ");

 scanf("%d", &op);

switch(op){
 case 0:
  system("clear");
  break;
 case 1:
  printf("> Digite o nome do autor da publicacao ou responsavel por projeto:\n> ");
  scanf("%s", Nome); getchar();
  printf("Grafo de Periodicos:\n(%s)\n", Nome);
  GRF_Busca_por_Autor(Relacionamento_Periodico, Nome);
  GRF_Pause();
  system("clear");
  printf("Grafo de Eventos:\n(%s)\n",Nome);
  GRF_Busca_por_Autor(Relacionamento_Eventos, Nome);
  GRF_Pause();
  system("clear");
  printf("Grafo de Projetos:\n(%s)\n",Nome);
  GRF_Busca_por_Autor(Relacionamento_Projetos, Nome);
  GRF_Pause();
  system("clear");
  break;
 case 2:
  printf("> Digite o titulo do projeto, periodico ou evento:\n> ");
  scanf("%s", Nome); getchar();
  printf("Grafo de Periodicos:\n(%s)\n",Nome);
  GRF_Busca_por_Publicacao(Relacionamento_Periodico, Nome);
  GRF_Pause();
  system("clear");
  printf("Grafo de Eventos:\n(%s)\n",Nome);
  GRF_Busca_por_Publicacao(Relacionamento_Eventos, Nome);
  GRF_Pause();
  system("clear");
  printf("Grafo de Projetos:\n(%s)\n",Nome);
  GRF_Busca_por_Publicacao(Relacionamento_Projetos, Nome);
  GRF_Pause();
  system("clear");
  break;
 case 3:
  printf("> Digite o ano da publicacao:\n> ");
  scanf("%d", &Ano);
  printf("Grafo de Periodicos:\n(%d)\n",Ano);
  GRF_Busca_por_Ano(Relacionamento_Periodico, Ano);
  GRF_Pause();
  system("clear");
  printf("Grafo de Eventos:\n(%d)\n",Ano);
  GRF_Busca_por_Ano(Relacionamento_Eventos, Ano);
  GRF_Pause();
  system("clear");
  printf("Grafo de Projetos:\n(%d)\n",Ano);
  GRF_Busca_por_Ano(Relacionamento_Projetos, Ano);
  GRF_Pause();
  system("clear");
  break;
 default:
  system("clear");
  break;
}

 if(op != 0){
  printf("> Deseja realizar uma nova consulta?\n(1) Sim\n(0) Nao\n> ");
  scanf("%d", &op);

  if(op == 1) goto busca; else GRF_Pause();
 }



 GRF_Liberar_Grafo(Relacionamento_Periodico);
 GRF_Liberar_Grafo(Relacionamento_Eventos);
 GRF_Liberar_Grafo(Relacionamento_Projetos);


printf("\n\n.......................................\n");
printf("Trabalho feito por: Hugo Fagundes, Icaro Marcelino, Pedro Gonzaga e Yan Victor.\n");
printf(".......................................\n\n");
	return 0;
}
