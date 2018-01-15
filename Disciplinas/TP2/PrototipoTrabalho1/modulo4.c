#include <stdio.h>
#include <stdlib.h>
#include "modulo2.h"
#include "grafo.h"
#include "listas.h"
void print(listadeprojetosfinal *aux, Grafo* grafo, listaDeProfessores* listaProfessores){
/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
int i;
struct listadocentes *aux2;
struct listadiscentes *aux3;
struct listadiscentesexternos *aux4;

FILE *seta;
seta = fopen("ProjetosPPGI.txt", 	"w+");
fprintf(seta, "------------Projetos------------\n");
	for(i=0;aux!=NULL;i++){
		fprintf(seta, "NOME COMPLETO(RESPONSAVEL) = %s.\n", aux->responsavel);
		fprintf(seta, "Projeto %d.\n", i+1);
		fprintf(seta, "NOME = %s.\n", aux->nomeprojeto);
		fprintf(seta, "ANO INICIO = %d.\n", aux->anodeinicio);
		fprintf(seta, "ANO FIM = %d.\n", aux->anofim);
		fprintf(seta, "SITUACAO = %s.\n", aux->situacao);
		fprintf(seta, "NATUREZA = %s.\n", aux->natureza);
		fprintf(seta, "DESCRICAO = %s.\n", aux->descricao);
		fprintf(seta, "*INTEGRANTES* \n");
/*------------------------------------------------------------------------*/

		aux2=aux->docentes;
		aux3=aux->discentes;
		aux4=aux->discentesexternos;

/*----------------------*/
		fprintf(seta, "DOCENTES: ");
		while(aux2!=NULL){
			fprintf(seta, " %s. ", aux2->nomedocente);
			aux2=aux2->prox;
		}fprintf(seta, "\n"); 
/*----------------------*/
		fprintf(seta, "DISCENTES: ");
		while(aux3!=NULL){
			fprintf(seta, " %s. ", aux3->nomediscente);
			aux3=aux3->prox;
		}fprintf(seta, "\n"); 
/*----------------------*/
		fprintf(seta, "DISCENTES EXTERNOS: ");
		while(aux4!=NULL){
			fprintf(seta, " %s. ", aux4->nomediscenteexterno);
			aux4=aux4->prox;
		}fprintf(seta,"\n");	
/*------------------------------------------------------------------------*/
		aux=aux->prox;
		fprintf(seta, "\n");fprintf(seta, "\n");
	}
	free(aux);

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/

int cont=0; /*Serve para diferenciar o professor responsavel pelo projeto */


	fprintf(seta, "\nGrafo de relacionamentos:\n");
	Grafo *lista = grafo;

	for(i=0;i<grafo->numProfs;i++){ 

		while(lista->Docentes[i]!=NULL){
			if(cont==0){ /* Professor responsável pelo projeto */
				fprintf(seta, "%s -> ", lista->Docentes[i]->nome_Professor);
				cont=1;
			}else{    /* Professores relacionados */
				fprintf(seta, "%s. ", lista->Docentes[i]->nome_Professor);
			}
			lista->Docentes[i] = lista->Docentes[i]->prox; 
		}
		fprintf(seta,"\n"); 
		cont=0;
	}
	free(lista);

	free(seta);
	printf("Arquivo 'ProjetosPPGI.txt' criado com sucesso!\n");
}
