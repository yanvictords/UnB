
/*!
*\file modulo1.c
* \brief Modulo de implementacao de listas e leitura do arquivo.
*
 *\author Hugo Fagundes
* \since 01/06/2015.
* \version 1.6.
*/



#define DIR_PUBLICACAO "Arquivos Publicacao/"


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
#ifndef MODULO1_H_INCLUDED
	#define MODULO1_H_INCLUDED
	#include "modulo1.h"
#endif
#ifndef CTYPE_H_INCLUDED
	#define CTYPE_H_INCLUDED
	#include <ctype.h>
#endif

#include <dirent.h>
#include <sys/types.h>
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

/*!
* \brief Funcao que le do arquivo os dados referentes aos discentes e gera uma lista com os nomes.
* \param arquivo_doutorado Arquivos com os nomes dos doutorandos.
* \param arquivo_mestrado Arquivos com os nomes dos mestrandos.
* \return lista de alunos 
*/


listaDeAlunos* txtDiscentesEmLista(char* arquivo_doutorado, char* arquivo_mestrado){
	FILE *doutorado = fopen(arquivo_doutorado, "r");
	FILE *mestrado = fopen(arquivo_mestrado, "r");

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

/*!
* \brief Funcao que le do arquivo os nomes de todos os professores e gera uma lista com os mesmos.
* \param arquivo arquivo de leitura
* \return lista de professores.
*/

listaDeProfessores* txtDocentesEmLista(char* arquivo){
	FILE* projetos = fopen(arquivo, "r");
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


/*!
* \brief Funcao que le do arquivo as informacoes referentes aos projetos e gera uma lista com as informacoes.
* \param arquivo arquivo de leitura com informacoes dos projetos.
* \return lista de projetos
*/


listaDeProjetos* txtProjetosEmLista(char* arquivo){
	FILE* projetos = fopen(arquivo, "r+");

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

		fscanf(projetos, "2 NOME-COMPLETO = %[^\n]\n", nomeIntegrante1);

		fscanf(projetos, "3 NOME-COMPLETO = %[^\n]\n\n", nomeIntegrante2);

		Lista = insereEmListaDeProjetos(Lista, nomeProjeto, anoInicio, mesFim, anoFim, situacao, natureza, descricao, responsavel, nomeIntegrante1, nomeIntegrante2);
	}while(!feof(projetos));

	fclose(projetos);

	return Lista;

}

/*!
* \brief Funcao que le do arquivo as informacoes referentes aos eventos e gera uma lista com as informacoes.
* \param arquivo arquivo de leitura com informacoes dos eventos
* \return lista de eventos
*/

listaDeEventos* txtEventosEmLista(char *str, char* arquivo, char* nomepasta){
	DIR* diretorioDesktop;
  	struct dirent* item_desktop;
   	
	char pastaprof[300];
	char arquivos[300];
	FILE *ev = fopen(arquivo, "r+");
	char suporte[100]="TP2/Arquivos/";
	
/* O codigo a seguir verifica se o diretorio esta com '/' no final antes de adicionar 'TrabalhoPS/Arquivos/'*/
	int k, l;
	k=0;
	while(str[k]!='\0')k++;
	k--;
	if(str[k]!='/') {
		k++; str[k]='/';
	}
	k++;
	for(l=0;suporte[l]!='\0';l++){
		str[k]=suporte[l];
		k++;
	}
/* O codigo acima verifica se o diretorio esta com '/' no final antes de adicionar 'TrabalhoPS/trabalho/Arquivos/'*/

    diretorioDesktop = opendir(str);
   if( !diretorioDesktop )
    {	
	printf("\n -----> O diretorio %s nao foi encontrado!\n", str);
        printf( "\nPor favor, digite um diretorio valido. Exemplo: /home/'pastapessoal'/Documentos\n\n" );
	printf("Diretorio: ");
	for(k=0;str[k]!='\0';k++) /* Serve para limpar o array para armazenar um novo diretorio*/
	str[k]='\0';
	scanf("%s", str); 
	getchar();
	txtEventosEmLista(str, "publicacao_eventos.txt", "Genaina Rodrigues");
    }else{



    int readed = 0, readed2=0, y=0; /* flag pra quando ler */



    while(( item_desktop = readdir(diretorioDesktop)) != NULL){
	if (!strcmp(item_desktop->d_name,".") || !strcmp(item_desktop->d_name,"..")){ // no linux ele acha esse dois arquivos o . e o ..
            continue;
	}else{
        if (!strcmp(nomepasta,item_desktop->d_name)){
        	readed = 1;
		strcpy(pastaprof, str); // copiando a informaçao de um vetor para o outro
		while(pastaprof[y]!='\0') y++; 
		y--;
		if(pastaprof[y]!='/') strcat(pastaprof, "/");
    		strcat(pastaprof, item_desktop->d_name); //Adicionando o diretorio do arquivo
		while(pastaprof[y]!='\0') y++; 
		y--;
		if(pastaprof[y]!='/') strcat(pastaprof, "/");
		strcpy(arquivos, pastaprof);
		}
        }   
    }

if (readed==0){
    	printf("\n\nPasta do professor '%s' nao encontrada neste diretorio. Por favor, reenvie o nome certo da pasta do professor na 'main.c' para esta funcao e recompile o codigo!\n\n", nomepasta);
    	exit(1);
    }

diretorioDesktop = opendir(arquivos);

	while(( item_desktop = readdir(diretorioDesktop)) != NULL){
		if (!strcmp(item_desktop->d_name,".") || !strcmp(item_desktop->d_name,"..")){ // no linux ele acha esse dois arquivos o . e o ..
			continue;
	}else{
        	if (!strcmp(arquivo,item_desktop->d_name)){
			strcat(arquivos, item_desktop->d_name);
			ev = fopen(arquivos, "r+");
			readed2=1;
		}
	}
	}

   
if (readed2==0){
    	printf("\n\nArquivo '%s' nao foi encontrado neste diretorio!\n\n", arquivo);
    	exit(1);
    }





	listaDeEventos *ListaEventos = criaListaDeEventos();

	char nomeProfessor[100], nomeParaCitacao_Professor[300], natureza[30], titulo[200], pais[30]; 
	char idioma[30], nomeEvento[100], ano[10], proceedings[300], volume[30];
    char paginaInicial[10], paginaFinal[10];

	/* Novamente so para descartar indiretorioDesktopformacoes inuteis */
	char descarta[150];

	int i,x,j;

	char letra = 'X', flag;

	char nomeAutor[100];
	char nomeParaCitacao[300];
	char ordemDeAutoria[4];

	char flag2;

	do{
		if (letra=='X')	fscanf(ev, "N%c", &flag);
		else flag = fgetc(ev);

		/* Somente se for de outro professor entra nessa condicao */
		if (flag=='O'){
			fscanf(ev, "ME COMPLETO = %[^\n]\n", nomeProfessor);
			fscanf(ev, "NOME-PARA-CITACAO = %[^\n]\n\n", nomeParaCitacao_Professor);
			fscanf(ev, "%[^\n]\n\n", descarta);
			fscanf(ev, "NATUREZA = %[^\n]\n", natureza);
		}else{
			fscanf(ev, "TUREZA = %[^\n]\n", natureza);
		}

		fscanf(ev, "TITULO = %[^\n]\n", titulo); 
		fscanf(ev, "PAIS = %[^\n]\n", pais);
		fscanf(ev, "IDIOMA = %[^\n]\n", idioma);
		fscanf(ev, "NOME DO EVENTO = %[^\n]\n", nomeEvento);
		fscanf(ev, "ANO = %[^\n]\n", ano);
		fscanf(ev, "PROCEEDINGS = %[^\n]\n", proceedings);
		fscanf(ev, "VOLUME = %[^\n]\n", volume);
		fscanf(ev, "PAGINA INICIAL = %[^\n]\n", paginaInicial);
		fscanf(ev, "PAGINA-FINAL = %[^\n]\n", paginaFinal);
		fscanf(ev, "%[^\n]\n", descarta);

		listaDeAutores *ListaAutores = criaListaDeAutores();

		for(i=0,letra='0';!isalpha(letra)&&!feof(ev);i++){
			if (letra=='0') letra = fgetc(ev);
			fscanf(ev, ".%[^\n]\n", nomeAutor);
			x = strlen(nomeAutor);
			if(nomeAutor[0]==' '){
				for(j=0;j<x;j++){
					nomeAutor[j] = nomeAutor[j+1];
				}nomeAutor[j]='\0';
				x--;
			}
			if(nomeAutor[x-1]==' '){
				nomeAutor[x-1]='\0';
				x--;
			}	
			nomeAutor[x-1]='\0';
			nomeAutor[0]='\0';
			for(j=0;j<x-2;j++){
			nomeAutor[j] = nomeAutor[j+1];
			}nomeAutor[j]='\0';

			while(flag2!='=') fscanf(ev, "%c", &flag2);
			fscanf(ev, " %[^\n]\n", nomeParaCitacao);
			fscanf(ev, "b. Ordem de autoria = %[^\n]\n", ordemDeAutoria);
			fscanf(ev, "%c", &letra);

			ListaAutores = insereEmListaDeAutores(ListaAutores, nomeAutor, nomeParaCitacao, ordemDeAutoria);

		}

		ListaEventos = insereEmListaDeEventos(ListaEventos, ListaAutores, nomeProfessor, nomeParaCitacao_Professor, 
											natureza, titulo, pais, idioma, nomeEvento, ano, proceedings, volume,
											paginaInicial, paginaFinal);

	}while(!feof(ev));


	return ListaEventos;
	fclose(ev);
	closedir(diretorioDesktop);

}}


/*!
* \brief Funcao que le do arquivo as informacoes referentes aos periodicos e gera uma lista com as informacoes.
* \param arquivo arquivo de leitura com informacoes dos periodicos
* \return lista de periodicos
*/


listaDePeriodicos* txtPeriodicosEmLista(char *src, char* arquivo, char* nomepasta){
	DIR* diretorioDesktop;
    struct dirent* item_desktop;
	FILE *pe = fopen(arquivo, "r+");
   
	
	char pastprof[300];
	char arquivos[300];
    diretorioDesktop = opendir(src);

    int readed = 0, readed2=0, y=0; /* flag pra quando ler */
 	
       while(( item_desktop = readdir(diretorioDesktop)) != NULL){
	if (!strcmp(item_desktop->d_name,".") || !strcmp(item_desktop->d_name,"..")){ // no linux ele acha esse dois arquivos o . e o ..
            continue;
	}else{
        if (!strcmp(nomepasta,item_desktop->d_name)){
        	readed = 1;
		strcpy(pastprof, src); // copiando a informaçao de um vetor para o outro
		while(pastprof[y]!='\0') y++; 
		y--;
		if(pastprof[y]!='/') strcat(pastprof, "/");
    		strcat(pastprof, item_desktop->d_name); //Adicionando o diretorio do arquivo
		while(pastprof[y]!='\0') y++; 
		y--;
		if(pastprof[y]!='/') strcat(pastprof, "/");
		strcpy(arquivos, pastprof);
		}
        }   
    }

	if (readed==0){
    	printf("\n\nPasta do professor '%s' nao encontrada neste diretorio. Por favor, reenvie o nome correto da pasta do professor na 'main.c' para esta funcao e recompile o codigo!\n\n", nomepasta);
    	exit(1);
    }

diretorioDesktop = opendir(arquivos);

	while(( item_desktop = readdir(diretorioDesktop)) != NULL){
		if (!strcmp(item_desktop->d_name,".") || !strcmp(item_desktop->d_name,"..")){ // no linux ele acha esse dois arquivos o . e o ..
			continue;
	}else{
        	if (!strcmp(arquivo,item_desktop->d_name)){
			strcat(arquivos, item_desktop->d_name);
			pe = fopen(arquivos, "r+");
			readed2=1;
		}
	}
	}

if (readed2==0){
    	printf("\n\nArquivo '%s' nao foi encontrado neste diretorio!\n\n", arquivo);
    	exit(1);
    }

    
	
	listaDePeriodicos *ListaPeriodicos = criaListaDePeriodicos();
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
	listaDeAutores *autores;
	/* Novamente so para descartar informacoes inuteis */
	char descarta[150];

	int i, x,j;

	char letra = 'X', flag;

	char nomeAutor[100];
	char nomeParaCitacao[300];
	char ordemDeAutoria[4];

	char flag2;

	do{
		if (letra=='X')	fscanf(pe, "N%c", &flag);
		else flag = fgetc(pe);

		/* Somente se for de outro professor entra nessa condicao */
		if (flag=='O'){
			fscanf(pe, "ME COMPLETO = %[^\n]\n", nomeProfessor);
			fscanf(pe, "NOME-PARA-CITACAO = %[^\n]\n\n", nomeParaCitacao_Professor);
			fscanf(pe, "%[^\n]\n\n", descarta);
			fscanf(pe, "NATUREZA = %[^\n]\n", natureza);
		}else{
			fscanf(pe, "TUREZA = %[^\n]\n", natureza);
		}

		fscanf(pe, "TITULO do ARTIGO = %[^\n]\n", tituloArtigo);
		fscanf(pe, "ANO = %[^\n]\n", ano);
		fscanf(pe, "IDIOMA = %[^\n]\n", idioma);
		fscanf(pe, "TITULO do PERIODICO = %[^\n]\n", tituloPeriodico);
		fscanf(pe, "VOLUME = %[^\n]\n", volume);
		fscanf(pe, "SERIE = %[^\n]\n", serie);
		fscanf(pe, "PAGINA INICIAL = %[^\n]\n", paginaInicial);
		fscanf(pe, "PAGINA-FINAL = %[^\n]\n", paginaFinal);
		fscanf(pe, "%[^\n]\n", descarta);

		listaDeAutores *ListaAutores = criaListaDeAutores();
		for(i=0,letra='0';!isalpha(letra)&&!feof(pe);i++){
			if (letra=='0') letra = fgetc(pe);
			fscanf(pe, ".%[^\n]\n", nomeAutor);

			x = strlen(nomeAutor);
			if(nomeAutor[0]==' '){
				for(j=0;j<x;j++){
					nomeAutor[j] = nomeAutor[j+1];
				}nomeAutor[j]='\0';
				x--;
			}
			if(nomeAutor[x-1]==' '){
				nomeAutor[x-1]='\0';
				x--;
			}	
			nomeAutor[x-1]='\0';
			nomeAutor[0]='\0';
			for(j=0;j<x-2;j++){
			nomeAutor[j] = nomeAutor[j+1];
			}nomeAutor[j]='\0';

			
			while(flag2!='=') fscanf(pe, "%c", &flag2);
			fscanf(pe, " %[^\n]\n", nomeParaCitacao);
			fscanf(pe, "b. Ordem de autoria = %[^\n]\n", ordemDeAutoria);
			fscanf(pe, "%c", &letra);

			ListaAutores = insereEmListaDeAutores(ListaAutores, nomeAutor, nomeParaCitacao, ordemDeAutoria);

		}

		ListaPeriodicos = insereEmListaDePeriodicos(ListaPeriodicos, ListaAutores , nomeProfessor,
											nomeParaCitacao_Professor, natureza, tituloArtigo, tituloPeriodico, 
											idioma, ano, serie, volume, paginaInicial, paginaFinal);

	}while(!feof(pe));

	return ListaPeriodicos;
	fclose(pe);
	closedir( diretorioDesktop );
}

