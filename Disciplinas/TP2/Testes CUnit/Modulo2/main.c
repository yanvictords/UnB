#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "modulo2.h"
#include "modulo1.h"

int main(){
	listaDeProjetos*listaProjetos=(listaDeProjetos*)malloc(sizeof(listaDeProjetos));
	listadeprojetosfinal*listaFinal=NULL;
	listaDeProjetos*aux,*aux2,*aux3;
	listaDeProfessores*nodoP,*nodoP2,*nodoP3,*listaProfessores=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));
	listaDeAlunos*nodoA,*nodoA2,*nodoA3,*listaAlunos=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
	char nome1[10]="andre", nome2[10]="Pedro", nome3[10]="gustavo";
	char nome4[10]="julia",nome5[10]="Turing",nome6[10]="valeska",nome12[10]="bob",nome7[10]="gabi",nome9[10]="Daniel",nome10[10]="rafaela";
	char nome8[10]="paulo",nomeProjeto[300]="ProjetoTeste",nomeProjeto2[300]="ProjetoTeste2",nomeProjeto3[300]="ProjetoTeste3";
	int anoInicio=2010,mesFim=9, anoFim=2012,i=0,anoInicio2=2011,mesFim2=10, anoFim2=2019,anoInicio3=2012,mesFim3=11, anoFim3=2015;
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
	int conta=0,conta2=0;
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

	printf("%d\n",conta);
	printf("%d\n",conta2);

	/*while(listaProjetos!=NULL){
	listaFinal = INSERE_NA_LISTADEPROJETOSFINAL(listaFinal,listaProjetos,listaAlunos,listaProfessores);
	listaProjetos=listaProjetos->proximoProjeto;
	}

	listaFinal=listaFinal->prox;
	while(listaFinal!=NULL){
		printf("======>Nome Do Projeto: %s\n",listaFinal->nomeprojeto);
		printf("->Responsavel: %s\n",listaFinal->responsavel);
		printf("->Docente: %s\n",listaFinal->docentes->nomedocente);
		printf("->Discente: %s\n",listaFinal->discentes->nomediscente);
		printf("->Discente Externo: %s\n",listaFinal->discentesexternos->nomediscenteexterno);	
		printf("->Natureza: %s\n",listaFinal->natureza);
		printf("->Situacao: %s\n",listaFinal->situacao);
		printf("Ano de incio: %d\n",listaFinal->anodeinicio);
		printf("Ano do termino: %d\n",listaFinal->anofim);
		printf("->Descricao: %s\n\n",listaFinal->descricao);
		listaFinal=listaFinal->prox;
	}	
	printf("-OBS: Como cada projeto so tem 2 integrantes(tirando o responsavel), um dos campos docentes,discentes ou discentes externos sempre sera igual a NULL\n\n");
	*/


return 0;	
}