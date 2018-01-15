#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "modulo1.h"

void corrigeNome(char nome[100]){
	char auxiliar[100];
	int flag = 0, i=0;

	do{
		auxiliar[i] = nome[i];
		i++;

		if(auxiliar[i-1] == ' ' && auxiliar[i-2] == ' '){
			flag = 1;
			auxiliar[i-2] = '\0';
		}
	}while (flag==0);

	strcpy(nome, auxiliar);
}

void corrigeNome2(char nome[100]){
	char auxiliar[100];
	int flag = 0, i = 0;

	do{

		auxiliar[i] = nome[i];
		i++;

		if(auxiliar[i-1] == '='){
			flag = 1;
			auxiliar[i-14] = '\0';
		}

	}while(flag==0);

	strcpy(nome, auxiliar);

}

listaDeAlunos* txtDiscentesEmLista(void){
	FILE *doutorado = fopen("discentes doutorado.txt", "r");
	FILE *mestrado = fopen("discentes mestrado.txt", "r");

	listaDeAlunos *Lista = criaListaDeAlunos();

	/* variaveis so pra descartar o que nao vai ser usado do arquivo txt */
	char descarta[200];

	char matricula[10], nome[100];

	fscanf(doutorado, "%[^\n]\n", descarta);
	fscanf(doutorado, "%[^\n]\n", descarta);
	fscanf(doutorado, "%[^\n]\n\n", descarta);
	fscanf(doutorado, "%[^\n]\n\n\n", descarta);
	fscanf(doutorado, "%[^\n]\n", descarta);
	fscanf(doutorado, "%[^\n]\n", descarta);

	do{
		fscanf(doutorado, "            %s    %[^\n]\n", matricula, nome);
		
		corrigeNome(nome);

		if(matricula[0]!='0' && matricula[0]!='1' && matricula[0]!='2' && matricula[0]!='3')
			break;

		Lista = insereEmListaDeAlunos(Lista, nome, matricula, 2);

	}while(!feof(doutorado));

	fclose(doutorado);

	fscanf(mestrado, "%[^\n]\n", descarta);
	fscanf(mestrado, "%[^\n]\n", descarta);
	fscanf(mestrado, "%[^\n]\n\n", descarta);
	fscanf(mestrado, "%[^\n]\n\n\n", descarta);
	fscanf(mestrado, "%[^\n]\n", descarta);
	fscanf(mestrado, "%[^\n]\n", descarta);


	do{
		fscanf(mestrado, "            %s    %[^\n]\n", matricula, nome);

		corrigeNome(nome);

		if(matricula[0]!='0' && matricula[0]!='1' && matricula[0]!='2' && matricula[0]!='3')
			break;

		Lista = insereEmListaDeAlunos(Lista, nome, matricula, 1);
	
	}while(!feof(mestrado));

	fclose(mestrado);

	return Lista;

}

listaDeProfessores* txtDocentesEmLista(void){
	FILE* projetos = fopen("projetos.txt", "r");
	char nome[100], nome2[100], nome3[100], nome4[100], citacao[300];

	/* Novamente so para descartar informacoes inuteis */
	char descarta[150];

	listaDeProfessores* Lista = criaListaDeProfessores();

	do{
		fscanf(projetos, "NOME COMPLETO = %[^\n]\nNOME-PARA-CITACAO = %[^\n]\n", nome, citacao);

		fscanf(projetos, "%[^\n]\n", descarta);
		fscanf(projetos, "%[^\n]\n", descarta);
		fscanf(projetos, "%[^\n]\n", descarta);
		fscanf(projetos, "%[^\n]\n", descarta);
		fscanf(projetos, "%[^\n]\n", descarta);
		fscanf(projetos, "%[^\n]\n", descarta);
		fscanf(projetos, "%[^\n]\n", descarta);
		fscanf(projetos, "%[^\n]\n", descarta);
		fscanf(projetos, "%[^\n]\n", descarta);
		/*fscanf(projetos, "%[^\n]\n", descarta);
		fscanf(projetos, "%[^\n]\n", descarta);
		fscanf(projetos, "%[^\n]\n\n", descarta);*/
		
		Lista = insereEmListaDeProfessores(Lista, nome, citacao);
		fscanf(projetos, "1 NOME-COMPLETO = %[^\n]\n2 NOME-COMPLETO = %[^\n]\n3 NOME-COMPLETO = %[^\n]\n\n", nome2, nome3, nome4);
		corrigeNome2(nome2);
		corrigeNome2(nome3);
		corrigeNome2(nome4);
		Lista = insereEmListaDeProfessores(Lista, nome2, citacao);
		Lista = insereEmListaDeProfessores(Lista, nome3, citacao);
		Lista = insereEmListaDeProfessores(Lista, nome4, citacao);

	}while(!feof(projetos));
	
	fclose(projetos);

	return Lista;
}

listaDeProjetos* txtProjetosEmLista(void){
	FILE* projetos = fopen("projetos.txt", "r");

	int anoInicio, mesFim, anoFim;
	char nomeProjeto[300], situacao[20], natureza[20], descricao[500], nomeIntegrante1[100], nomeIntegrante2[100];
	char responsavel[100];

	/* Novamente so para descartar informacoes inuteis */
	char descarta[150];

	listaDeProjetos* Lista = criaListaDeProjetos();

	do{
		fscanf(projetos, "%[^\n]\n", descarta);
		fscanf(projetos, "%[^\n]\n", descarta);
		fscanf(projetos, "%[^\n]\n", descarta);
		fscanf(projetos, "ANO-INICIO = %d\n", &anoInicio);
		fscanf(projetos, "MES-FIM = %d\n", &mesFim);
		fscanf(projetos, "ANO-FIM = %d\n", &anoFim);
		fscanf(projetos, "NOME-DO-PROJETO = %[^\n]\n", nomeProjeto);
		fscanf(projetos, "SITUACAO = %[^\n]\n", situacao);
		fscanf(projetos, "NATUREZA= %[^\n]\n", natureza);
		fscanf(projetos, "DESCRICAO-DO-PROJETO= %[^\n]\n", descricao);
		fscanf(projetos, "INTEGRANTES-DO-PROJETO\n");
		fscanf(projetos, "1 NOME-COMPLETO = %[^\n]\n", responsavel);



		corrigeNome2(responsavel);

		fscanf(projetos, "2 NOME-COMPLETO = %[^\n]\n", nomeIntegrante1);

		corrigeNome2(nomeIntegrante1);

		fscanf(projetos, "3 NOME-COMPLETO = %[^\n]\n\n", nomeIntegrante2);

		corrigeNome2(nomeIntegrante2);

		Lista = insereEmListaDeProjetos(Lista, nomeProjeto, anoInicio, mesFim, anoFim, situacao, natureza, descricao, responsavel, nomeIntegrante1, nomeIntegrante2);
	}while(!feof(projetos));

	fclose(projetos);

	return Lista;

}

