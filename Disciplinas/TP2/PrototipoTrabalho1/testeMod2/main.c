#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "modulo2.h"
#include "modulo1.h"

int main(){
	listaDeEventos*listaEventos=(listaDeEventos*)malloc(sizeof(listaDeEventos));
	listaDeEventosFinal*ListaFinal2=NULL;
	listaDeEventos*aux,*aux2,*aux3;
	listaDeProfessores*nodoP,*nodoP2,*nodoP3,*listaProfessores=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));
	listaDeAlunos*nodoA,*nodoA2,*nodoA3,*listaAlunos=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
	char nome1[10]="andre", nome2[10]="Pedro", nome3[10]="gustavo";
	char nome4[10]="julia",nome5[10]="Turing",nome6[10]="valeska",nome12[10]="bob",nome7[10]="gabi",nome9[10]="Daniel",nome10[10]="rafaela";
	char nome8[10]="paulo",pais[300]="ProjetoTeste",pais2[300]="ProjetoTeste2",pais3[300]="ProjetoTeste3";
	int ano=2010,mesFim=9, anoFim=2012,i=0,ano2=2011,mesFim2=10, anoFim2=2019,ano3=2012,mesFim3=11, anoFim3=2015;
	char titulo[20]="Desativado", natureza[20]="Cientifica", nomeEvento[500]="SeiLA",nomeProfessor[10]="eu";
	char titulo2[20]="Desativado2", natureza2[20]="Cientifica2", nomeEvento2[500]="SeiLA2",nomeProfessor2[10]="eu2";
	char titulo3[20]="Desativado3", natureza3[20]="Cientifica3", nomeEvento3[500]="SeiLA3",nomeProfessor3[10]="eu3";

	/*listaEventos,listaProfessores,listaAlunos = Listas geradas a partir dos dados lidos do arquivo*/
	/*ListaFinal2 = Lista gerada a partir das listas que foram criadas do arquivo*/

	/*Insercao no primeiro nodo da listaEventos---*/
	
	strcpy(listaEventos->autores->nomeAutor,nome1);
	
	strcpy(listaEventos->titulo,titulo);
	strcpy( listaEventos->nomeEvento,nomeEvento);
	strcpy(listaEventos->natureza,natureza);
	strcpy(listaEventos->pais,pais);
	strcpy(listaEventos->nomeProfessor,nomeProfessor);	
/*_______________segunda insercao na listaEventos----------------------*/
	aux2=(listaDeEventos*)malloc(sizeof(listaDeEventos));

	strcpy(aux2->autores->nomeAutor,nome4);
	
	strcpy(aux2->titulo,titulo2);
	strcpy(aux2->nomeEvento,nomeEvento2);
	strcpy(aux2->natureza,natureza2);
	strcpy(aux2->pais,pais2);
	strcpy(aux2->nomeProfessor,nomeProfessor2);	
	aux2->proximoEvento=NULL;
	aux2->proximoEvento=listaEventos;
	listaEventos=aux2;
/*Terceira insercao na listaEventos------------------------------*/

	aux3=(listaDeEventos*)malloc(sizeof(listaDeEventos));
	
	strcpy(aux3->autores->nomeAutor,nome3);
	strcpy(aux3->titulo,titulo3);
	strcpy(aux3->nomeEvento,nomeEvento3);
	strcpy(aux3->natureza,natureza3);
	strcpy(aux3->pais,pais3);
	strcpy(aux3->nomeProfessor,nomeProfessor3);	
	aux3->proximoEvento=NULL;
	aux3->proximoEvento=listaEventos;
	listaEventos=aux3;


/*----------------primeira insercao na lista de professores*----------------*/
	nodoP=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));
	listaProfessores->proximoProfessor=NULL;
	strcpy(nodoP->nomeProfessor,nome1);
	nodoP->proximoProfessor=listaProfessores;
	listaProfessores=nodoP;
/*-------------------------------------------------------------------*/	
	/*segundo nome a ser inserido na lista de professores*/
	nodoP2=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));
	strcpy(nodoP2->nomeProfessor,nome2);
	nodoP2->proximoProfessor=listaProfessores;
	listaProfessores=nodoP2;
	
/*-------------------------Terceiro nome a ser inserido na lista de professores------*/
	nodoP3=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));
	strcpy(nodoP3->nomeProfessor,nome3);
	nodoP3->proximoProfessor=listaProfessores;
	listaProfessores=nodoP3;
	




/*-------inserindo nomes na lista de alunos-----------------------------------*/
	nodoA=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
	listaAlunos->proximoAluno=NULL;
	strcpy(nodoA->nomeAluno,nome4);
	nodoA->proximoAluno=listaAlunos;
	listaAlunos=nodoA;	
/*----------segundo nome--------------------*/
	nodoA2=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
	strcpy(nodoA2->nomeAluno,nome5);
	nodoA2->proximoAluno=listaAlunos;
	listaAlunos=nodoA2;

/*-------------------Terceiro nome a ser inserido na lista de alunos--------------------------*/
	nodoA3=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
	strcpy(nodoA3->nomeAluno,nome6);
	nodoA3->proximoAluno=listaAlunos;
	listaAlunos=nodoA3;





	while(listaEventos!=NULL){
	ListaFinal2 = insereNaListadeEventosFinal(ListaFinal2,listaEventos,listaAlunos,listaProfessores);
	listaEventos=listaEventos->proximoEvento;
	}

	ListaFinal2=ListaFinal2->prox;
	/*while(ListaFinal2!=NULL){
		printf("======>Nome Do Projeto: %s\n",ListaFinal2->pais);
		printf("->nomeProfessor: %s\n",ListaFinal2->nomeProfessor);
		printf("->Docente: %s\n",ListaFinal2->docentes->nomedocente);
		printf("->Discente: %s\n",ListaFinal2->discentes->nomediscente);
		printf("->Discente Externo: %s\n",ListaFinal2->discentesexternos->nomediscenteexterno);	
		printf("->Natureza: %s\n",ListaFinal2->natureza);
		printf("->titulo: %s\n",ListaFinal2->titulo);
		printf("->nomeEvento: %s\n\n",ListaFinal2->nomeEvento);
		ListaFinal2=ListaFinal2->prox;
	}	*/
	printf("-OBS: Como cada projeto so tem 2 integrantes(tirando o nomeProfessor), um dos campos docentes,discentes ou discentes externos sempre sera igual a NULL\n\n");
	


return 0;	
}