#ifdef DEBUG
	#include "grafos_inst.h"
	#define GRAFOS_INST_H_INCLUDED
#else
	#include "grafos.h"
	#define GRAFOS_H_INCLUDED
#endif

/********************************************************
* Teste das funcoes do modulo de implementacao do grafo *
*********************************************************/
int main(int argc, char* argv[]){

	Grafo* G;

	G = GRF_Criar_Grafo();

	printf("> \t[Inserindo novas publicacoes no grafo...]\n");
	G = GRF_Insere_Nova_Publicacao(G, "LP", 2015);
	G = GRF_Insere_Nova_Publicacao(G, "PS", 2014);
	G = GRF_Insere_Nova_Publicacao(G, "C3", 2013);
	G = GRF_Insere_Nova_Publicacao(G, "CA", 2011);
	G = GRF_Insere_Nova_Publicacao(G, "LC", 2000);

	printf("> \t[Inserindo novos autores nos grafo...]\n\n");
	G = GRF_Insere_Autor(G, "Icaro M Miranda", "PS");
	G = GRF_Insere_Autor(G, "Icaro Miranda", "LP");
	G = GRF_Insere_Autor(G, "Icaro M", "PS");
	G = GRF_Insere_Autor(G, "Icaro M Miranda", "LC");
	G = GRF_Insere_Autor(G, "Icaro Miranda", "CA");
	G = GRF_Insere_Autor(G, "Icaro MM", "C3"); 
	
	printf("> \t[Teste de impressao em tela do grafo]\n");
	GRF_Imprimir_Grafo(G);

	printf("\n> \t[Teste das funcoes de busca]\n> \t[Por nome da publicacao]\n");
	GRF_Busca_por_Publicacao(G, "PS");
	GRF_Busca_por_Publicacao(G, "CA");

	printf("\n> \t[Por nome do autor]\n");
	GRF_Busca_por_Autor(G, "Icaro M");
	GRF_Busca_por_Autor(G, "Icaro M Miranda");

	printf("\n> \t[Por ano:]\n");
	GRF_Busca_por_Ano(G, 2015);
	GRF_Busca_por_Ano(G, 2014);
	GRF_Busca_por_Ano(G, 2011);
	GRF_Busca_por_Ano(G, 2013);
	GRF_Busca_por_Ano(G, 2000);
	GRF_Busca_por_Ano(G, 2055);

	printf("\n> \t[Teste da geracao de arquivo <publics.txt>]\n");
	GRF_Gerar_Arquivo(G, "publics.txt");

	printf("\n> \t[Teste da funcao de remocao]\n");
	printf("\n> \t[Remove publicacao <CA>]\n");
	GRF_Remove_Publicacao(G, "CA");
	GRF_Imprimir_Grafo(G);

	printf("\n> \t[Liberando o Grafo...]\n");
	GRF_Liberar_Grafo(G);

	GRF_Pause();
	return 0;
}