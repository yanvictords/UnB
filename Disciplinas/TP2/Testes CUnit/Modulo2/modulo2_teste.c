#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#ifndef MODULO2_H_INCLUDED
	#define MODULO2_H_INCLUDED
	#include "modulo2.h"
#endif 
#ifndef LISTAS_H_INCLUDED 
	#define LISTAS_H_INCLUDED 	
	#include "listas.h"
#endif
#ifndef MODULO1_H_INCLUDED 
	#define MODULO1_H_INCLUDED 	
	#include "modulo1.h"
#endif




void Add_Suite_Testes(void);

void Teste_ListaProVazias(void){

	listaDeProfessores*nodoP,*nodoP2,*nodoP3,*listaProfessores=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));
	listaDeAlunos*nodoA,*nodoA2,*nodoA3,*listaAlunos=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
	char nome1[10]="andre", nome2[10]="Pedro", nome3[10]="gustavo";
	char nome4[10]="julia",nome5[10]="Turing",nome6[10]="valeska",nome12[10]="bob",nome7[10]="gabi",nome9[10]="Daniel",nome10[10]="rafaela";
	char nome8[10]="paulo",nomeProjeto[300]="ProjetoTeste",nomeProjeto2[300]="ProjetoTeste2",nomeProjeto3[300]="ProjetoTeste3";
	char  natureza[20]="Cientifica",nomeProfessor[10]="eu";
	char  natureza2[20]="Cientifica2",nomeProfessor2[10]="eu2";
	char  natureza3[20]="Cientifica3",nomeProfessor3[10]="eu3";

	int conta=1,conta2=0;

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



 	listadeprojetosfinal*listaFinal=NULL;
 	listaDeProjetos*listaProjetos=(listaDeProjetos*)malloc(sizeof(listaDeProjetos));
 	listaDeProjetos*listaAux=listaProjetos;

 	while(listaAux!=NULL){
		listaFinal = INSERE_NA_LISTADEPROJETOSFINAL(listaFinal,listaAux,listaAlunos,listaProfessores);
		listaAux=listaAux->proximoProjeto;																																								
	}


	while(listaProjetos!=NULL){
		conta+=1;
		listaProjetos=listaProjetos->proximoProjeto;
	}

	
	while(listaFinal!=NULL){
		conta2+=1;
		listaFinal=listaFinal->prox;
	}

 CU_ASSERT_EQUAL(conta, conta2);
return;
	/*CU_ASSERT_TRUE(1);*/
}

void Teste_ListaEveVazias(void){
	listaDeProfessores*nodoP,*nodoP2,*nodoP3,*listaProfessores=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));
	listaDeAlunos*nodoA,*nodoA2,*nodoA3,*listaAlunos=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
	char nome1[10]="andre", nome2[10]="Pedro", nome3[10]="gustavo";
	char nome4[10]="julia",nome5[10]="Turing",nome6[10]="valeska",nome12[10]="bob",nome7[10]="gabi",nome9[10]="Daniel",nome10[10]="rafaela";
	char nome8[10]="paulo",nomeProjeto[300]="ProjetoTeste",nomeProjeto2[300]="ProjetoTeste2",nomeProjeto3[300]="ProjetoTeste3";
	char  natureza[20]="Cientifica",nomeProfessor[10]="eu";
	char  natureza2[20]="Cientifica2",nomeProfessor2[10]="eu2";
	char  natureza3[20]="Cientifica3",nomeProfessor3[10]="eu3";

	int conta=0,conta2=0;
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

	listaDeEventos*listaEventos=NULL;
	listaDeEventosFinal*listaFinal=NULL;
	listaDeEventos*listaAux=listaEventos;

	while(listaAux!=NULL){
		listaFinal = insereNaListadeEventosFinal(listaFinal,listaAux,listaAlunos,listaProfessores);
		listaAux=listaAux->proximoEvento;
	}

	while(listaEventos!=NULL){
		conta+=1;
		listaEventos=listaEventos->proximoEvento;
	}
	
	while(listaFinal!=NULL){
		conta2+=1;
		listaFinal=listaFinal->prox;
	}
	CU_ASSERT_EQUAL(conta, conta2);
	return;
}


void Teste_ListaPerVazias(void){

	listaDeProfessores*nodoP,*nodoP2,*nodoP3,*listaProfessores=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));
	listaDeAlunos*nodoA,*nodoA2,*nodoA3,*listaAlunos=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
	char nome1[10]="andre", nome2[10]="Pedro", nome3[10]="gustavo";
	char nome4[10]="julia",nome5[10]="Turing",nome6[10]="valeska",nome12[10]="bob",nome7[10]="gabi",nome9[10]="Daniel",nome10[10]="rafaela";
	char nome8[10]="paulo",nomeProjeto[300]="ProjetoTeste",nomeProjeto2[300]="ProjetoTeste2",nomeProjeto3[300]="ProjetoTeste3";
	char  natureza[20]="Cientifica",nomeProfessor[10]="eu";
	char  natureza2[20]="Cientifica2",nomeProfessor2[10]="eu2";
	char  natureza3[20]="Cientifica3",nomeProfessor3[10]="eu3";

	int conta=0,conta2=0;
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

	listaDePeriodicos*listaPeriodicos=NULL;
	listaDePeriodicosFinal*listaFinal=NULL;
	listaDePeriodicos*listaAux=listaPeriodicos;

	while(listaAux!=NULL){
		listaFinal = insereNaListadePeriodicosFinal(listaFinal,listaAux,listaAlunos,listaProfessores);
		listaAux=listaAux->proximoPeriodico;																																								
	}

	while(listaPeriodicos!=NULL){
		conta=conta+1;
		listaPeriodicos=listaPeriodicos->proximoPeriodico;
	}
	
	while(listaFinal!=NULL){
		conta2=conta2+1;
		listaFinal=listaFinal->prox;
	}

	
	CU_ASSERT_EQUAL(conta,conta2);
}


void Teste_ListaProNaoVazia3elem(void){

	listaDeProjetos*listaProjetos=(listaDeProjetos*)malloc(sizeof(listaDeProjetos));
	listadeprojetosfinal*listaFinal=NULL;
	listaDeProjetos*aux,*aux2,*aux3;
	listaDeProfessores*nodoP,*nodoP2,*nodoP3,*listaProfessores=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));
	listaDeAlunos*nodoA,*nodoA2,*nodoA3,*listaAlunos=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
	char nome1[10]="andre", nome2[10]="Pedro", nome3[10]="gustavo";
	char nome4[10]="julia",nome5[10]="Turing",nome6[10]="valeska",nome12[10]="bob",nome7[10]="gabi",nome9[10]="Daniel",nome10[10]="rafaela";
	char nome8[10]="paulo",nomeProjeto[300]="ProjetoTeste",nomeProjeto2[300]="ProjetoTeste2",nomeProjeto3[300]="ProjetoTeste3";
	int anoInicio=2010,mesFim=9, anoFim=2012,i=0,anoInicio2=2011,mesFim2=10, anoFim2=2019,anoInicio3=2012,mesFim3=11, anoFim3=2015,conta=2,conta2=1;
	char situacao[20]="Desativado", natureza[20]="Cientifica", descricao[500]="SeiLA",responsavel[10]="eu";
	char situacao2[20]="Desativado2", natureza2[20]="Cientifica2", descricao2[500]="SeiLA2",responsavel2[10]="eu2";
	char situacao3[20]="Desativado3", natureza3[20]="Cientifica3", descricao3[500]="SeiLA3",responsavel3[10]="eu3";

	/*listaProjetos,listaProfessores,listaAlunos = Listas geradas a partir dos dados lidos do arquivo*/
	/*listaFinal = Lista gerada a partir das listas que foram criadas do arquivo*/

	/*Insercao no primeiro nodo da listaProjetos---*/
	listaProjetos->anoInicio=anoInicio;
	listaProjetos->anoFim=anoFim;
	strcpy(listaProjetos->integrante1,nome1);
	strcpy(listaProjetos->integrante2,nome12);
	strcpy(listaProjetos->situacao,situacao);
	strcpy( listaProjetos->descricao,descricao);
	strcpy(listaProjetos->natureza,natureza);
	strcpy(listaProjetos->nomeProjeto,nomeProjeto);
	strcpy(listaProjetos->responsavel,responsavel);	
/*_______________segunda insercao na listaProjetos----------------------*/
	aux2=(listaDeProjetos*)malloc(sizeof(listaDeProjetos));
	aux2->anoInicio=anoInicio2;
	aux2->anoFim=anoFim2;
	strcpy(aux2->integrante1,nome4);
	strcpy(aux2->integrante2,nome2);
	strcpy(aux2->situacao,situacao2);
	strcpy(aux2->descricao,descricao2);
	strcpy(aux2->natureza,natureza2);
	strcpy(aux2->nomeProjeto,nomeProjeto2);
	strcpy(aux2->responsavel,responsavel2);	
	aux2->proximoProjeto=NULL;
	aux2->proximoProjeto=listaProjetos;
	listaProjetos=aux2;
/*Terceira insercao na listaProjetos------------------------------*/

	aux3=(listaDeProjetos*)malloc(sizeof(listaDeProjetos));
	aux3->anoInicio=anoInicio3;
	aux3->anoFim=anoFim3;
	strcpy(aux3->integrante1,nome7);
	strcpy(aux3->integrante2,nome3);
	strcpy(aux3->situacao,situacao3);
	strcpy(aux3->descricao,descricao3);
	strcpy(aux3->natureza,natureza3);
	strcpy(aux3->nomeProjeto,nomeProjeto3);
	strcpy(aux3->responsavel,responsavel3);	
	aux3->proximoProjeto=NULL;
	aux3->proximoProjeto=listaProjetos;
	listaProjetos=aux3;


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


	listaDeProjetos*listaAux=listaProjetos;
	while(listaAux!=NULL){
		listaFinal = INSERE_NA_LISTADEPROJETOSFINAL(listaFinal,listaAux,listaAlunos,listaProfessores);
		listaAux=listaAux->proximoProjeto;																																								
	}


	while(listaProjetos!=NULL){
		conta+=1;
		listaProjetos=listaProjetos->proximoProjeto;
	}
	
	
	while(listaFinal!=NULL){
		conta2+=1;
		listaFinal=listaFinal->prox;
	}
		
	CU_ASSERT_EQUAL(conta,conta2);



return;
}

void Teste_ListaEveNaoVazia3elem(void){

	listaDeEventos*aux,*aux2,*aux3;
	listaDeProfessores*nodoP,*nodoP2,*nodoP3,*listaProfessores=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));
	listaDeAlunos*nodoA,*nodoA2,*nodoA3,*listaAlunos=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
	char nome1[10]="andre", nome2[10]="Pedro", nome3[10]="gustavo";
	char nome4[10]="julia",nome5[10]="Turing",nome6[10]="valeska",nome12[10]="bob",nome7[10]="gabi",nome9[10]="Daniel",nome10[10]="rafaela";
	char nome8[10]="paulo",nomeProjeto[300]="ProjetoTeste",nomeProjeto2[300]="ProjetoTeste2",nomeProjeto3[300]="ProjetoTeste3";
	char  natureza[20]="Cientifica",nomeProfessor[10]="eu";
	char  natureza2[20]="Cientifica2",nomeProfessor2[10]="eu2";
	char  natureza3[20]="Cientifica3",nomeProfessor3[10]="eu3";

	int conta=0,conta2=0;
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

	listaDeEventos*listaEventos=(listaDeEventos*)malloc(sizeof(listaDeEventos));
	listaDeEventosFinal*listaFinal=NULL;
	listaDeEventos*listaAux=listaEventos;



/*Insercao no primeiro nodo da listaEventos---*/
	listaDeAutores*auz=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auz->nomeAutor,nome1);
	auz->proximoAutor=listaEventos->autores;
	listaEventos->autores=auz;

/*segundo nome do nodo-----------------*/
	listaDeAutores*auz1=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auz1->nomeAutor,nome2);
	auz1->proximoAutor=listaEventos->autores;
	listaEventos->autores=auz1;
	
	strcpy(listaEventos->natureza,natureza);
	strcpy(listaEventos->nomeProfessor,nomeProfessor);	
/*_______________segunda insercao na listaEventos----------------------*/
	aux2=(listaDeEventos*)malloc(sizeof(listaDeEventos));
	listaDeAutores*auz2=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auz2->nomeAutor,nome4);
	auz2->proximoAutor=aux2->autores;
	aux2->autores=auz2;
/*--------------segundo nome---------------*/
	listaDeAutores*auz21=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auz21->nomeAutor,nome7);
	auz21->proximoAutor=aux2->autores;
	aux2->autores=auz21;

	strcpy(aux2->natureza,natureza2);
	strcpy(aux2->nomeProfessor,nomeProfessor2);	
	aux2->proximoEvento=NULL;
	aux2->proximoEvento=listaEventos;
	listaEventos=aux2;
/*Terceira insercao na listaEventos------------------------------*/

	aux3=(listaDeEventos*)malloc(sizeof(listaDeEventos));
	listaDeAutores*auz3=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auz3->nomeAutor,nome8);
	auz3->proximoAutor=aux3->autores;
	aux3->autores=auz3;
/*--------------segundo nome---------------*/
	listaDeAutores*auz31=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auz31->nomeAutor,nome12);
	auz31->proximoAutor=aux3->autores;
	aux3->autores=auz31;

	listaDeAutores*auz312=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auz312->nomeAutor,nome5);
	auz312->proximoAutor=aux3->autores;
	aux3->autores=auz312;

	listaDeAutores*auz313=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auz313->nomeAutor,nome6);
	auz313->proximoAutor=aux3->autores;
	aux3->autores=auz313;


	while(listaAux!=NULL){
		listaFinal = insereNaListadeEventosFinal(listaFinal,listaAux,listaAlunos,listaProfessores);
		listaAux=listaAux->proximoEvento;
	}

	while(listaEventos!=NULL){
		conta+=1;
		listaEventos=listaEventos->proximoEvento;
	}
	
	while(listaFinal!=NULL){
		conta2+=1;
		listaFinal=listaFinal->prox;
	}
	CU_ASSERT_EQUAL(conta, conta2);
	return;
}


void Teste_ListaPerNaoVazia3elem(void){

	listaDeProfessores*nodoP,*nodoP2,*nodoP3,*listaProfessores=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));
	listaDeAlunos*nodoA,*nodoA2,*nodoA3,*listaAlunos=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
	int conta=2,conta2=3;
	char nome1[10]="andre", nome2[10]="Pedro", nome3[10]="gustavo";
	char nome4[10]="julia",nome5[10]="Turing",nome6[10]="valeska",nome12[10]="bob",nome7[10]="gabi",nome9[10]="Daniel",nome10[10]="rafaela";
	char nome8[10]="paulo",nomeProjeto[300]="ProjetoTeste",nomeProjeto2[300]="ProjetoTeste2",nomeProjeto3[300]="ProjetoTeste3";
	char  natureza[20]="Cientifica",nomeProfessor[10]="eu";
	char  natureza2[20]="Cientifica2",nomeProfessor2[10]="eu2";
	char  natureza3[20]="Cientifica3",nomeProfessor3[10]="eu3";


	listaDePeriodicos*listaPeriodicos=(listaDePeriodicos*)malloc(sizeof(listaDePeriodicos));
	listaDePeriodicosFinal*listaFinal=NULL;
	listaDePeriodicos*listaAux=listaPeriodicos;
	listaDePeriodicos*auxx,*auxx2,*auxx3;

	
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


	/*Insercao no primeiro nodo da listaPeriodicoss---*/
	listaDeAutores*auzz=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auzz->nomeAutor,nome1);
	auzz->proximoAutor=listaPeriodicos->autores;
	listaPeriodicos->autores=auzz;

/*segundo nome do nodo-----------------*/
	listaDeAutores*auzz1=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auzz1->nomeAutor,nome2);
	auzz1->proximoAutor=listaPeriodicos->autores;
	listaPeriodicos->autores=auzz1;
	
	strcpy(listaPeriodicos->natureza,natureza);
	strcpy(listaPeriodicos->nomeProfessor,nomeProfessor);	
/*_______________segunda insercao na listaPeriodicos----------------------*/
	auxx2=(listaDePeriodicos*)malloc(sizeof(listaDePeriodicos));
	listaDeAutores*auzz2=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auzz2->nomeAutor,nome4);
	auzz2->proximoAutor=auxx2->autores;
	auxx2->autores=auzz2;
/*--------------segundo nome---------------*/
	listaDeAutores*auzz21=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auzz21->nomeAutor,nome7);
	auzz21->proximoAutor=auxx2->autores;
	auxx2->autores=auzz21;

	strcpy(auxx2->natureza,natureza2);
	strcpy(auxx2->nomeProfessor,nomeProfessor2);	
	auxx2->proximoPeriodico=NULL;
	auxx2->proximoPeriodico=listaPeriodicos;
	listaPeriodicos=auxx2;
/*Terceira insercao na listaPeriodicos------------------------------*/

	auxx3=(listaDePeriodicos*)malloc(sizeof(listaDePeriodicos));
	listaDeAutores*auzz3=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auzz3->nomeAutor,nome8);
	auzz3->proximoAutor=auxx3->autores;
	auxx3->autores=auzz3;
/*--------------segundo nome---------------*/
	listaDeAutores*auzz31=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auzz31->nomeAutor,nome12);
	auzz31->proximoAutor=auxx3->autores;
	auxx3->autores=auzz31;

	listaDeAutores*auzz312=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auzz312->nomeAutor,nome5);
	auzz312->proximoAutor=auxx3->autores;
	auxx3->autores=auzz312;

	listaDeAutores*auzz313=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auzz313->nomeAutor,nome6);
	auzz313->proximoAutor=auxx3->autores;
	auxx3->autores=auzz313;

	strcpy(auxx3->natureza,natureza3);
	strcpy(auxx3->nomeProfessor,nomeProfessor3);	
	auxx3->proximoPeriodico=NULL;
	auxx3->proximoPeriodico=listaPeriodicos;
	listaPeriodicos=auxx3;
/*---------------------------------------------------------------------------------*/

	while(listaAux!=NULL){
		listaFinal = insereNaListadePeriodicosFinal(listaFinal,listaAux,listaAlunos,listaProfessores);
		listaAux=listaAux->proximoPeriodico;																																								
	}

	while(listaPeriodicos!=NULL){
		conta=conta+1;
		listaPeriodicos=listaPeriodicos->proximoPeriodico;
	}
	
	while(listaFinal!=NULL){
		conta2=conta2+1;
		listaFinal=listaFinal->prox;
	}
	
		
	CU_ASSERT_EQUAL(conta,conta2);

}





void Teste_ListaPerNaoVazia1elem(void){


	listaDeProfessores*nodoP,*nodoP2,*nodoP3,*listaProfessores=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));
	listaDeAlunos*nodoA,*nodoA2,*nodoA3,*listaAlunos=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
	char nome1[10]="andre", nome2[10]="Pedro", nome3[10]="gustavo";
	char nome4[10]="julia",nome5[10]="Turing",nome6[10]="valeska",nome12[10]="bob",nome7[10]="gabi",nome9[10]="Daniel",nome10[10]="rafaela";
	char nome8[10]="paulo",nomeProjeto[300]="ProjetoTeste",nomeProjeto2[300]="ProjetoTeste2",nomeProjeto3[300]="ProjetoTeste3";
	char  natureza[20]="Cientifica",nomeProfessor[10]="eu";
	char  natureza2[20]="Cientifica2",nomeProfessor2[10]="eu2";
	char  natureza3[20]="Cientifica3",nomeProfessor3[10]="eu3";


	listaDePeriodicos*listaPeriodicos=(listaDePeriodicos*)malloc(sizeof(listaDePeriodicos));
	listaDePeriodicosFinal*listaFinal=NULL;
	listaDePeriodicos*listaAux=listaPeriodicos;
	listaDePeriodicos*auxx,*auxx2,*auxx3;

	int conta=0,conta2=0;
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


	/*Insercao no primeiro nodo da listaPeriodicoss---*/
	listaDeAutores*auzz=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auzz->nomeAutor,nome1);
	auzz->proximoAutor=listaPeriodicos->autores;
	listaPeriodicos->autores=auzz;

/*segundo nome do nodo-----------------*/
	listaDeAutores*auzz1=(listaDeAutores*)malloc(sizeof(listaDeAutores));
	strcpy(auzz1->nomeAutor,nome2);
	auzz1->proximoAutor=listaPeriodicos->autores;
	listaPeriodicos->autores=auzz1;
	
	strcpy(listaPeriodicos->natureza,natureza);
	strcpy(listaPeriodicos->nomeProfessor,nomeProfessor);	


	while(listaAux!=NULL){
		listaFinal = insereNaListadePeriodicosFinal(listaFinal,listaAux,listaAlunos,listaProfessores);
		listaAux=listaAux->proximoPeriodico;																																								
	}

	while(listaPeriodicos!=NULL){
		conta=conta+1;
		listaPeriodicos=listaPeriodicos->proximoPeriodico;
	}
		conta=conta+1;
	while(listaFinal!=NULL){
		conta2=conta2+1;
		listaFinal=listaFinal->prox;
	}
	
		
	CU_ASSERT_EQUAL(conta,conta2);




}




void Teste_ListaProNaoVazia1elem(void){

listaDeProjetos*listaProjetos=(listaDeProjetos*)malloc(sizeof(listaDeProjetos));
	listadeprojetosfinal*listaFinal=NULL;
	listaDeProjetos*aux,*aux2,*aux3;
	listaDeProfessores*nodoP,*nodoP2,*nodoP3,*listaProfessores=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));
	listaDeAlunos*nodoA,*nodoA2,*nodoA3,*listaAlunos=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
	char nome1[10]="andre", nome2[10]="Pedro", nome3[10]="gustavo";
	char nome4[10]="julia",nome5[10]="Turing",nome6[10]="valeska",nome12[10]="bob",nome7[10]="gabi",nome9[10]="Daniel",nome10[10]="rafaela";
	char nome8[10]="paulo",nomeProjeto[300]="ProjetoTeste",nomeProjeto2[300]="ProjetoTeste2",nomeProjeto3[300]="ProjetoTeste3";
	int anoInicio=2010,mesFim=9, anoFim=2012,i=0,anoInicio2=2011,mesFim2=10, anoFim2=2019,anoInicio3=2012,mesFim3=11, anoFim3=2015,conta=2,conta2=1;
	char situacao[20]="Desativado", natureza[20]="Cientifica", descricao[500]="SeiLA",responsavel[10]="eu";
	char situacao2[20]="Desativado2", natureza2[20]="Cientifica2", descricao2[500]="SeiLA2",responsavel2[10]="eu2";
	char situacao3[20]="Desativado3", natureza3[20]="Cientifica3", descricao3[500]="SeiLA3",responsavel3[10]="eu3";

	/*listaProjetos,listaProfessores,listaAlunos = Listas geradas a partir dos dados lidos do arquivo*/
	/*listaFinal = Lista gerada a partir das listas que foram criadas do arquivo*/

	/*Insercao no primeiro nodo da listaProjetos---*/
	listaProjetos->anoInicio=anoInicio;
	listaProjetos->anoFim=anoFim;
	strcpy(listaProjetos->integrante1,nome1);
	strcpy(listaProjetos->integrante2,nome12);
	strcpy(listaProjetos->situacao,situacao);
	strcpy( listaProjetos->descricao,descricao);
	strcpy(listaProjetos->natureza,natureza);
	strcpy(listaProjetos->nomeProjeto,nomeProjeto);
	strcpy(listaProjetos->responsavel,responsavel);	
/*_______________segunda insercao na listaProjetos----------------------*/
	aux2=(listaDeProjetos*)malloc(sizeof(listaDeProjetos));
	aux2->anoInicio=anoInicio2;
	aux2->anoFim=anoFim2;
	strcpy(aux2->integrante1,nome4);
	strcpy(aux2->integrante2,nome2);
	strcpy(aux2->situacao,situacao2);
	strcpy(aux2->descricao,descricao2);
	strcpy(aux2->natureza,natureza2);
	strcpy(aux2->nomeProjeto,nomeProjeto2);
	strcpy(aux2->responsavel,responsavel2);	
	aux2->proximoProjeto=NULL;
	aux2->proximoProjeto=listaProjetos;
	listaProjetos=aux2;
/*Terceira insercao na listaProjetos------------------------------*/

	aux3=(listaDeProjetos*)malloc(sizeof(listaDeProjetos));
	aux3->anoInicio=anoInicio3;
	aux3->anoFim=anoFim3;
	strcpy(aux3->integrante1,nome7);
	strcpy(aux3->integrante2,nome3);
	strcpy(aux3->situacao,situacao3);
	strcpy(aux3->descricao,descricao3);
	strcpy(aux3->natureza,natureza3);
	strcpy(aux3->nomeProjeto,nomeProjeto3);
	strcpy(aux3->responsavel,responsavel3);	
	aux3->proximoProjeto=NULL;
	aux3->proximoProjeto=listaProjetos;
	listaProjetos=aux3;


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


	listaDeProjetos*listaAux=listaProjetos;
	
	while(listaAux!=NULL){
		listaFinal = INSERE_NA_LISTADEPROJETOSFINAL(listaFinal,listaAux,listaAlunos,listaProfessores);
		listaAux=listaAux->proximoProjeto;																																								
	}


	while(listaProjetos!=NULL){
		conta+=1;
		listaProjetos=listaProjetos->proximoProjeto;
	}
	
	
	while(listaFinal!=NULL){
		conta2+=1;
		listaFinal=listaFinal->prox;
	}
		
	CU_ASSERT_EQUAL(conta,conta2);

}



/*void Teste_ListaEveNaoVazia1elem(void){

}*/


void Add_Suite_Testes(void){
	CU_pSuite pSuite = NULL;

	pSuite = CU_add_suite( "Teste CUnit do Modulo 2", NULL, NULL);

	CU_ADD_TEST(pSuite, Teste_ListaProVazias);
	CU_ADD_TEST(pSuite, Teste_ListaEveVazias);
	CU_ADD_TEST(pSuite, Teste_ListaPerVazias);
	CU_ADD_TEST(pSuite, Teste_ListaProNaoVazia3elem);
	CU_ADD_TEST(pSuite, Teste_ListaEveNaoVazia3elem);
	CU_ADD_TEST(pSuite,	Teste_ListaPerNaoVazia3elem);
	CU_ADD_TEST(pSuite, Teste_ListaProNaoVazia1elem);
	/*CU_ADD_TEST(pSuite, Teste_ListaEveNaoVazia1elem);*/
	CU_ADD_TEST(pSuite,	Teste_ListaPerNaoVazia1elem);
	
	
   return;
}



int main(void){
	

   if (CUE_SUCCESS != CU_initialize_registry()){
         return CU_get_error();
      }
    
   Add_Suite_Testes();
   CU_basic_set_mode(CU_BRM_VERBOSE);
   
   CU_basic_run_tests();
   CU_cleanup_registry();

   return CU_get_error();
}
