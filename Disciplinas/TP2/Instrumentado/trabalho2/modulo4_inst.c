
/*!
* \file modulo4.c
* \brief Modulo de implementacao do arquivo de saida do programa
* 
*\author Yan Victor Dos Santos
* \since 01/06/2015.
* \version 1.6.
*/

#ifndef STDIO_INST_H_INCLUDED
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
#ifndef GRAFOS_INST_H_INCLUDED
	#define GRAFOS_INST_H_INCLUDED
	#include "grafos_inst.h"
#endif
#ifndef MODULO2_INST_H_INCLUDED
	#define MODULO2_INST_H_INCLUDED
	#include "modulo2_inst.h"
#endif
#ifndef MODULO4_INST_H_INCLUDED
	#define MODULO4_INST_H_INCLUDED
	#include "modulo4_inst.h"
#endif

void INST_print(listaDeEventosFinal*listaFinal, listadeprojetosfinal *listaFinal2, listaDePeriodicosFinal*listaFinal3, Grafo* G, Grafo* H, Grafo* I){
/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
int i;
struct listadocentes *aux2;
struct listadiscentes *aux3;
struct listadiscentesexternos *aux4;

FILE *seta;
seta = fopen("PPGI.txt", 	"w+");



/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/

/*!
* \brief Escreve no arquivo as informacoes referentes as listas de projetos.
* \param lista de projetos final
*/

/*------------------------------------------------------------------------*/


/*------------------------------------------------------------------------*/

fprintf(seta, "\n+++++++++++++++++++++++++++++++++ PROJETOS +++++++++++++++++++++++++++++++++\n\n");
	for(i=0;listaFinal2!=NULL;i++){
		fprintf(seta,"NOME COMPLETO = %s\n", listaFinal2->responsavel);
		fprintf(seta,  "Projetos\n");
		fprintf(seta,  "Projeto %d\n", i+1);
		fprintf(seta,  "NOME = %s\n", listaFinal2->nomeprojeto);
		fprintf(seta,  "ANO INICIO = %d\n", listaFinal2->anodeinicio);
		fprintf(seta,  "ANO FIM = %d\n", listaFinal2->anofim);
		fprintf(seta,  "SITUACAO = %s\n", listaFinal2->situacao);
		fprintf(seta,  "NATUREZA = %s\n", listaFinal2->natureza);
		fprintf(seta,  "DESCRICAO = %s\n", listaFinal2->descricao);
		fprintf(seta,  "INTEGRANTES = \n");
/*----------------------------------*/

		aux2=listaFinal2->docentes;
		aux3=listaFinal2->discentes;
		aux4=listaFinal2->discentesexternos;

/*----------------------*/
		fprintf(seta,  "  DOCENTES: ");
		while(aux2!=NULL){
			fprintf(seta,  "| %s | ", aux2->nomedocente);
			aux2=aux2->prox;
		}fprintf(seta,  "\n"); 
/*----------------------*/
		fprintf(seta,  "  DISCENTES: ");
		while(aux3!=NULL){
			fprintf(seta,  "| %s | ", aux3->nomediscente);
			aux3=aux3->prox;
		}fprintf(seta,  "\n"); 
/*----------------------*/
		fprintf(seta,  "  DISCENTES EXTERNOS: ");
		while(aux4!=NULL){
			fprintf(seta,  "| %s | ", aux4->nomediscenteexterno);
			aux4=aux4->prox;
		}fprintf(seta, "\n");	
/*-------------------------------------*/
		listaFinal2=listaFinal2->prox;
	}
	
/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/

/*!
* \brief Escreve no arquivo as informacoes referentes as listas de periodicos
* \param lista de periodicos final
*/

fprintf(seta, "\n\n\n\n+++++++++++++++++++++++++++++++++ PERIODICOS +++++++++++++++++++++++++++++++++\n\n");



int h=1;
while(listaFinal3!=NULL){

fprintf(seta, "\n*PUBLICACAO EM PERIODICO*\n");
fprintf(seta, "NOME COMPLETO = %s\n",listaFinal3->nomeProfessor);
fprintf(seta, "------------------------------------------------------------------\n");	
fprintf(seta, "TITULO = %s\n",listaFinal3->tituloArtigo);
fprintf(seta, "ANO DE PUBLICACAO: %s\n\n",listaFinal3->ano);

fprintf(seta, "ORDEM       CATEGORIA                AUTORES:\n");

		while(listaFinal3->docentes!=NULL){
if((listaFinal3->docentes->nomedocente[0]!='\0')&&(listaFinal3->docentes->nomedocente[1]!=' ')){
			fprintf(seta, "%d           Docente                  %s\n",h++, listaFinal3->docentes->nomedocente);
}
			listaFinal3->docentes=listaFinal3->docentes->prox;
		}

		while(listaFinal3->discentes!=NULL){
if((listaFinal3->discentes->nomediscente[0]!='\0')&&(listaFinal3->discentes->nomediscente[1]!=' ')){
			fprintf(seta, "%d           Discente                 %s\n",h++, listaFinal3->discentes->nomediscente);
}
			listaFinal3->discentes=listaFinal3->discentes->prox;
		}

		while(listaFinal3->discentesexternos!=NULL){	
if((listaFinal3->discentesexternos->nomediscenteexterno[0]!='\0')&&(listaFinal3->discentesexternos->nomediscenteexterno[1]!=' ')){
			if(h<10){
			fprintf(seta, "%d           Participante Externo     %s\n",h++, listaFinal3->discentesexternos->nomediscenteexterno);
			}else{
			fprintf(seta, "%d          Participante Externo     %s\n",h++, listaFinal3->discentesexternos->nomediscenteexterno);
			}
}
			listaFinal3->discentesexternos=listaFinal3->discentesexternos->prox;
		}

fprintf(seta, "\n\n");
fprintf(seta, "NATUREZA: %s\n",listaFinal3->natureza);
fprintf(seta, "NOME DA EDITORA: %s\n",listaFinal3->tituloPeriodico);

fprintf(seta, "IDIOMA: %s\n",listaFinal3->idioma);
fprintf(seta, "VOLUME: %s\n",listaFinal3->volume);
fprintf(seta, "SERIE: %s\n",listaFinal3->serie);

fprintf(seta, "NUMERO DA PAGINA INICIAL: %s\n",listaFinal3->paginaInicial);
fprintf(seta, "NUMERO DA PAGINA FINAL: %s\n",listaFinal3->paginaFinal);
fprintf(seta, "\n\n");

		listaFinal3=listaFinal3->prox;
	}	


/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
/*!
* \brief Escreve no arquivo as informacoes referentes as listas de eventos.
* \param lista de eventos final.
*/
h=1;
fprintf(seta, "\n\n+++++++++++++++++++++++++++++ LISTA DE EVENTOS +++++++++++++++++++++++++++++\n\n");

	while(listaFinal!=NULL){
		fprintf(seta, "\n*PUBLICACAO EM EVENTOS*\n");
		fprintf(seta, "NOME COMPLETO = %s\n",listaFinal->nomeProfessor);
		fprintf(seta, "------------------------------------------------------------------\n");	
		fprintf(seta, "TITULO = %s\n",listaFinal->titulo);
		fprintf(seta, "ANO = %s\n\n",listaFinal->ano);
		fprintf(seta, "ORDEM       CATEGORIA                AUTORES:\n");
		
		while(listaFinal->docentes!=NULL){
if((listaFinal->docentes->nomedocente[0]!='\0')&&(listaFinal->docentes->nomedocente[1]!=' ')){
			fprintf(seta, "%d           Docente                  %s\n",h++, listaFinal->docentes->nomedocente);
}
			listaFinal->docentes=listaFinal->docentes->prox;
		}
		
		while(listaFinal->discentes!=NULL){
if((listaFinal->discentes->nomediscente[0]!='\0')&&(listaFinal->discentes->nomediscente[1]!=' ')){

			fprintf(seta, "%d           Discente                 %s\n",h++, listaFinal->discentes->nomediscente);
}

			listaFinal->discentes=listaFinal->discentes->prox;
		}
	
		while(listaFinal->discentesexternos!=NULL){
		if((listaFinal->discentesexternos->nomediscenteexterno[0]!='\0')&&(listaFinal->discentesexternos->nomediscenteexterno[1]!=' ')){
			if(h<10){
			fprintf(seta, "%d           Participante Externo     %s\n",h++, listaFinal->discentesexternos->nomediscenteexterno);
			}else{
			fprintf(seta, "%d          Participante Externo     %s\n",h++, listaFinal->discentesexternos->nomediscenteexterno);
			}
		}
			listaFinal->discentesexternos=listaFinal->discentesexternos->prox;
		}	

fprintf(seta, "\n\n");
fprintf(seta, "NATUREZA = %s\n",listaFinal->natureza);
fprintf(seta, "PAIS: %s\n",listaFinal->pais);
fprintf(seta, "IDIOMA: %s\n",listaFinal->idioma);
fprintf(seta, "NOME DO EVENTO: %s\n",listaFinal->nomeEvento);
fprintf(seta, "PROCEEDINGS: %s\n",listaFinal->proceedings);
fprintf(seta, "VOLUME: %s\n",listaFinal->volume);
fprintf(seta, "NUMERO DA PAGINA INICIAL: %s\n",listaFinal->paginaInicial);
fprintf(seta, "NUMERO DA PAGINA FINAL: %s\n",listaFinal->paginaFinal);

		h=1;
		listaFinal=listaFinal->prox;

fprintf(seta, "\n\n");
	}	

/*!
* \brief Escreve no arquivo os grafos de relacionamento gerados a partir das listas
* \param Grafo de relacionamentos
*/


/*------------------------------------------------------------------------*/
/************* AQUI COMEÇA O GRAFO DE RELACIONAMENTO ***************/
/*------------------------------------------------------------------------*/

if(GRF_INST_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
	}
	else{

		PLista aux, aux2, aux3;
		
		fprintf(seta, "------------------Grafo de Relacionamentos-----------------\n\n\n");
		fprintf(seta, "Quantidade de Publicacoes: %d\n\n", G->qnt);
		
			for(aux = G->inicio; aux->up != NULL; aux = aux->up){
			fprintf(seta, "%s:\n", aux->info);
			GRF_INST_filePrint_Lista(aux->down, seta);
			
		}
		fprintf(seta,"%s:\n", aux->info);
		GRF_INST_filePrint_Lista(aux->down, seta);

	}

	
if(GRF_INST_Grafo_Vazio(H)){
		fprintf(seta,"Grafo Vazio\n");
	}
	else{
		PLista aux;
		
		fprintf(seta, "Quantidade de Publicacoes: %d\n\n", H->qnt);
		
			for(aux = H->inicio; aux->up != NULL; aux = aux->up){
			fprintf(seta, "%s:\n", aux->info);
			GRF_INST_filePrint_Lista(aux->down, seta);
		}
		fprintf(seta,"%s:\n", aux->info);
		GRF_INST_filePrint_Lista(aux->down, seta);

	}



if(GRF_INST_Grafo_Vazio(I)){
		fprintf(seta,"Grafo Vazio\n");
	}
	else{
		PLista aux;
		
		fprintf(seta, "Quantidade de Publicacoes: %d\n\n", I->qnt);
		
			for(aux = I->inicio; aux->up != NULL; aux = aux->up){
			fprintf(seta, "%s:\n", aux->info);
			GRF_INST_filePrint_Lista(aux->down, seta);
		}
		fprintf(seta,"%s:\n", aux->info);
		GRF_INST_filePrint_Lista(aux->down, seta);

	}



/*------------------------------------------------------------------------*/



printf("\n\n********** 'PPGI.txt' criado com sucesso!!! **********\n");

}
