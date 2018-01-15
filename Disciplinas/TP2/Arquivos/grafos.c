/*!
* \file grafos.c
* \brief Modulo de implementacao de grafos.
*
* O objetivo desse modulo e a implementacao de funcoes que possibilitem
* a criacao de grafos de relacionamento para publicacoes, seus autores e
* participantes.
*
* \author Icaro Marcelino Miranda.
* \since 01/06/2015.
* \version 2.0.
*
*/

#ifndef GRAFOS_H_INCLUDED
	#define GRAFOS_H_INCLUDED
	#include "grafos.h"
#endif

/** Funcoes para manipulacao de listas internas dos grafos. **/
/* 01 */	int 	GRF_Lista_Vazia(PLista);
/* 02 */	int 	GRF_Buscar_Lista(string, PLista);
/* 03 */	void	GRF_Liberar_Lista(PLista);
/* 04 */	void	GRF_Print_Lista(PLista);
/* 05 */	void	GRF_filePrint_Lista(PLista, FILE*);
/* 06 */	PLista	GRF_Criar_Lista(void);
/* 07 */	PLista	GRF_Insere_Inicio_Lista(PLista, string);
/* 08 */	PLista	GRF_Insere_Fim_Lista(PLista, string);
/* 09 */	string	GRF_Car(PLista);
/* 10 */	Grafo* 	GRF_Insere_Listas_participantes(Grafo*, string, Listadocentes*, Listadiscentes*, Listadiscentesexternos*);

/*!
* \brief Verfica se dada lista e vazia.
*
* \param lista Ponteiro para lista a ser verificada.
* \return 1 para lista vazia, 0 para nao vazia.
*/
int GRF_Lista_Vazia(PLista lista){
	return (lista == NULL);
}

/*!
* \brief Verifica se existe certo elemento em uma lista.
*
* \param lista Ponteiro para lista pesquisada.
* \param valor String a ser pesquisada.
* \return 1 para elemento presente, 0 para elemento nao presente ou lista vazia.
*/
int GRF_Buscar_Lista(string valor, PLista lista){
	PLista L;
	
	for (L = lista; L != NULL; L = L->down){
		if (strstr(L->info, valor) != NULL){
			return 1;
		}
	} 
	return 0;			
}

/*!
* \brief Destroi uma lista.
*
* \param lista Ponteiro para lista a ser destruida.
*/
void GRF_Liberar_Lista(PLista lista){
	PLista L = lista;
	PLista Ref;

	while (L != NULL) {
		Ref = L->down;
		free(L);
		L = Ref;
	}
	return;
}

/*!
* \brief Imprime em tela os elementos de uma lista.
*
* \param lista Ponteiro para lista a ser impressa.
*/
void GRF_Print_Lista(PLista lista){
	PLista L;
	
	if(lista == NULL){
		printf("Fim da Lista.\n");
		return;
	}
	
	for (L = lista; L!= NULL; L = L->down){
		printf("%s\n", L->info);
	}
	printf("-\n");
}

/*!
* \brief Imprime em um arquivo os elemntos de uma lista.
*
* 	O arquivo ja deve ter sido aberto previamente, e deve ser fechado posteriormente.
* \param lista Ponteiro para lista a ser impressa.
* \param Arquivo Arquivo que vai receber a lista.
*/
void GRF_filePrint_Lista(PLista lista, FILE* Arquivo){
	PLista L;
	
	if(lista == NULL){
		return;
	}
	
	for (L = lista; L!= NULL; L = L->down){
		fprintf(Arquivo, "%s\n", L->info);
	}
	fprintf(Arquivo, "-\n\n");
}

/*!
* \brief Cria uma lista vazia.
*
* \return Ponteiro para uma lista vazia.
*/
PLista GRF_Criar_Lista(void){
	return NULL;
}

/*!
* \brief Insere uma nova string no inicio de uma lista.
*
* \param lista Ponteiro para lista que vai receber a insercao.
* \param valor String a ser inserida.
* \return Ponteiro para a lista atualizada.
*/
PLista GRF_Insere_Inicio_Lista(PLista lista, string valor){
	PLista novo = (PLista)malloc(sizeof(lista));
	
	novo->info = valor;
	novo->down = lista;
	novo->up = NULL;
	
	return novo;
}

/*!
* \brief Insere uma nova string no fim de uma lista.
*
* \param lista Ponteiro para lista que vai receber a insercao.
* \param valor String a ser inserida.
* \return Ponteiro para a lista atualizada.
*/
PLista GRF_Insere_Fim_Lista(PLista lista, string valor){
	PLista novo = (PLista) malloc(sizeof(lista));
	PLista ref;

	if(GRF_Lista_Vazia(lista)){
		return lista = GRF_Insere_Inicio_Lista(lista, valor);
	}

	for(ref = lista ; ref->down != NULL; ref = ref->down);
	
	novo->info = valor;
	ref->down = novo;
	novo->down = NULL;
	novo->up = ref;
	
	return lista;
}

/*!
* \brief Retorna o primeiro elemento da lista.
*
* \param lista Ponteiro para lista.
* \return String na primeira posicao da lista.
*/
string GRF_Car(PLista L){
	return L->info;
}


/*	Fucoes para a manipulacao de grafos 	*/
/*!
* \brief Verifica se um grafo esta vazio.
*
* \param G Grafo a ser testado.
* \return 1 para grafo vazio, 0 para grafo nao vazio.
*/
int GRF_Grafo_Vazio(Grafo* G){
	return ((G->inicio == NULL) || (G->qnt == 0));
}

/*!
* \brief Consulta quantos projetos, periodicos ou eventos um grafo possui.
*
* \param G Grafo a ser consultado.
* \return Numero de projetos.
*/
int GRF_Quantidade_Publicacoes(Grafo* G){
	return G->qnt;
}

/*!
* \brief Destroi um grafo.
*
* \param G Ponteiro para o grafo a ser destruido.
*/
void GRF_Liberar_Grafo(Grafo* G){
	PLista aux, ref;
	if(!GRF_Grafo_Vazio(G)){
		for(aux = G->inicio; aux->up != NULL; ){
			GRF_Liberar_Lista(aux->down);
			ref = aux->up;
			free(aux);
			aux = ref;
		}
		free(G);
	}
	return;
}

/*!
* \brief Imprime em tela as informacoes de um grafo.
*
* \param G Ponteiro para o grafo a ser impresso.
*/
void GRF_Imprimir_Grafo(Grafo* G){
	PLista aux;
	if(GRF_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
	}
	else{
		for(aux = G->inicio; aux->up != NULL; aux = aux->up){
			printf("%s (%d):\n", aux->info, aux->ano);
			GRF_Print_Lista(aux->down);
			printf("---\n");
		}
		printf("%s (%d):\n", aux->info, aux->ano);
		GRF_Print_Lista(aux->down);
		printf("---\n");

	}
	return;
}

/*!
* \brief Busca por nome ou trecho de nome uma publicacao em um grafo, imprimindo seus autores.
*
* \param G Ponteiro para o grafo contendo a publicacao.
* \param Nome String com o nome da pulicacao.
*/
void GRF_Busca_por_Publicacao(Grafo* G, string Nome){
	PLista aux;
	if(GRF_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
	}
	else{
		for(aux = G->inicio; aux != NULL; aux = aux->up){
			if(strstr(aux->info, Nome) != NULL){
				printf("%s:\n", aux->info);
				GRF_Print_Lista(aux->down);
				break;
			}
		}
	}
	return;
}

/*!
* \brief Busca por ano uma publicacao em um grafo, imprimindo seus autores.
*
* \param G Ponteiro para o grafo contendo a publicacao.
* \param Ano Ano da publicacao.
*/
void GRF_Busca_por_Ano(Grafo* G, int Ano){
	PLista aux;
	if(GRF_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
	}
	else{
		printf("(%d)\n", Ano);
		for(aux = G->inicio; aux != NULL; aux = aux->up){
			if(aux->ano == Ano){
				printf("%s:\n", aux->info);
				GRF_Print_Lista(aux->down);
			}
		}
	}
	printf("Fim da busca.\n\n");
	return;
}

/*!
* \brief Verifica por nome ou trecho de nome uma publicacao em um grafo.
*
* \param G Ponteiro para o grafo contendo a publicacao.
* \param Nome String com o nome da pulicacao.
* \return 1 se encontrar, 0 se nao encontrar.
*/
int GRF_Verificar_Publicacao(Grafo* G, string Nome){
	PLista aux;
	if(!GRF_Grafo_Vazio(G)){
		for(aux = G->inicio; aux != NULL; aux = aux->up){
			if(strstr(aux->info, Nome) != NULL){
				return 1;
			}
		}
	}
	return 0;
}

/*!
* \brief Gera um arquivo contendo as informacoes de um grafo.
*
* \param G grafo a ser impresso.
* \param Nome String com o nome desejado para o novo arquivo.
*/
void GRF_Gerar_Arquivo(Grafo* G, string Nome){
	if(GRF_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
	}
	else{
		FILE* Arquivo = fopen(Nome, "w");

		if(Arquivo == NULL){
			printf("Erro ao criar arquivo.\n");
			return;
		}

		PLista aux;
		
		fprintf(Arquivo, "Grafo de Relacionamentos\n\n<%s>\n", Nome);
		fprintf(Arquivo, "Quantidade de Publicacoes: %d\n\n", G->qnt);
		
		for(aux = G->inicio; aux->up != NULL; aux = aux->up){
			fprintf(Arquivo, "%s (%d):\n", aux->info, aux->ano);
			GRF_filePrint_Lista(aux->down, Arquivo);
		}
		fprintf(Arquivo,"%s (%d):\n", aux->info, aux->ano);
		GRF_filePrint_Lista(aux->down, Arquivo);
		fclose(Arquivo);

		printf("\nArquivo <%s> gerado com sucesso.\n", Nome);
	}
	return;
}

/*!
* \brief Busca por nome ou trecho de nome as ocorrencias de um autor em um grafo, imprimindo suas publicacoes.
*
* \param G Ponteiro para o grafo a ser pesquisado.
* \param Nome String com o nome do autor.
*/
void GRF_Busca_por_Autor(Grafo* G, string Nome){
	PLista aux;
	if(GRF_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
	}
	else{
		printf("%s:\n", Nome);
		for(aux = G->inicio; aux != NULL; aux = aux->up){
			if (GRF_Buscar_Lista(Nome, aux->down) == 1){
				printf("%s\n", aux->info);
			}
		}
		printf("-\n");
	}
	return;
}

/*!
* \brief Verifica se um autor existe no Grafo.
*
* \param G Ponteiro para o grafo a ser pesquisado.
* \param Nome String com o nome do autor.
* \return 1 se encontrar, 0 se nao encontrar.
*/
int GRF_Verificar_Autor(Grafo* G, string Nome){
	PLista aux;
	if(!GRF_Grafo_Vazio(G)){
		for(aux = G->inicio; aux != NULL; aux = aux->up){
			if (GRF_Buscar_Lista(Nome, aux->down) == 1){
				return 1;
			}
		}
	}
	return 0;
}

/*!
* \brief Cria um grafo vazio.
*
* \return Ponteiro para o novo grafo.
*/
Grafo* GRF_Criar_Grafo(void){
	Grafo* G = (Grafo*)malloc(sizeof(Grafo));
		G->inicio = NULL;
		G->qnt = 0;
	return G;
}

/*!
* \brief Insere nova publicacao em um grafo.
*
* \param G Ponteiro para o grafo.
* \param Nome String contendo o nome da publicacao.
* \return Ponteiro para o grafo atualizado.
*/
Grafo* GRF_Insere_Nova_Publicacao(Grafo* G, string Nome, int ano){
	PLista L = (PLista)malloc(sizeof(struct lista));
		L->info = Nome;
		L->down = GRF_Criar_Lista();
		L->ano = ano;

	if(GRF_Grafo_Vazio(G)){
		G->inicio = L;
		L->up = NULL;
	}
	else{
		PLista aux;
			for(aux = G->inicio; aux->up != NULL; aux = aux->up){
				if(strstr(aux->info, Nome) != NULL){
					return G;
				}
			}
				aux->up = L;
				L->up = NULL;
	}
	G->qnt++;
	return G;
}

/*!
* \brief Remove uma publicacao de um grafo.
*
* \param G Ponteiro para o Grafo desejado.
* \param Publicacao Nome da publicacao a ser removida.
* \return Ponteiro para o Grafo atualizado.
*/
Grafo* GRF_Remove_Publicacao(Grafo* G, string Publicacao){
	PLista aux, L1, L2;
	if(GRF_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
	}
	else{
		for(L1 = G->inicio, aux = G->inicio; aux != NULL; aux = aux->up){
			
			if(strstr(aux->info, Publicacao) != NULL){
				GRF_Liberar_Lista(aux->down);
				L2 = aux->up;
				L1->up = L2;
				G->qnt--;
				break;
			}
			L1 = aux;
		}
	}
	return G;
}

/*!
* \brief Insere um novo autor para uma publicacao contida em um grafo.
*
* \param G Ponteiro para o grafo contendo a publicacao.
* \param Autor String com o nome do autor.
* \param Publicacao String com o nome da pulicacao.
* \return Ponteiro para o grafo atualizado.
*/
Grafo* GRF_Insere_Autor(Grafo* G, string Autor, string Publicacao){
	PLista aux;
		for(aux = G->inicio; ; aux = aux->up){
			if(aux == NULL){
				printf("\nPublicacao nao encontrada.\n");
				break;
			}
			if(strstr(GRF_Car(aux), Publicacao) != NULL){
				if(!GRF_Buscar_Lista(Autor, aux->down)){
					aux->down = GRF_Insere_Fim_Lista(aux->down, Autor);
				}
				break;
			}
		}
	return G;
}

/*!
* \brief Funcao auxiliar, insere tres listas de autores/participantes em uma publicacao ja existente de um grafo.
*
* \param G Grafo a receber as listas.
* \param Titulo Titulo do periodico, evento ou projeto.
* \param Lista_Docentes Ponteiro para a lista de docentes.
* \param Lista_Discentes Ponteiro para a lista de discentes.
* \param Lista_DiscentesEXT Ponteiro para a lista de discentes externos.
* \param L lista a ser colocada no Grafo.
*
* \return Grafo atualizado.
*/
Grafo* GRF_Insere_Listas_participantes(Grafo* G, string Titulo, Listadocentes* Lista_Docentes, Listadiscentes* Lista_Discentes, Listadiscentesexternos* Lista_Discentes_EXT){
	
	if(GRF_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
		return G;
	}
	if(Titulo == NULL){
		printf("Aviso! Nome da Publicacao nao informados. Autores nao inseridos.\n");
		return G;
	}
	string Docente, Discente, ParticipanteExterno;

	while((Lista_Docentes != NULL)||(Lista_Discentes != NULL)||(Lista_Discentes_EXT != NULL)){

			if(Lista_Docentes != NULL){
				Docente = strcat(Lista_Docentes->nomedocente, " (Docente)");
				G = GRF_Insere_Autor(G, Docente, Titulo);
				Lista_Docentes = Lista_Docentes->prox;
			}
			if(Lista_Discentes != NULL){
				Discente = strcat(Lista_Discentes->nomediscente, " (Discente)");
				G = GRF_Insere_Autor(G, Discente, Titulo);
				Lista_Discentes = Lista_Discentes->prox;
			}
			if(Lista_Discentes_EXT != NULL){
				ParticipanteExterno = strcat(Lista_Discentes_EXT->nomediscenteexterno, " (ParticipanteExterno)");
				G = GRF_Insere_Autor(G, ParticipanteExterno, Titulo);
				Lista_Discentes_EXT = Lista_Discentes_EXT->prox;
			}
		}
	return G;
}

/*!
* \brief Gera um grafo com as informacoes de uma struct listaDePeriodicos.
*
* \param L lista a ser colocada no Grafo.
* \return Grafo de relacionamento dos periodicos.
*/
Grafo* GRF_ListaPeriodicos_Grafo(listaDePeriodicosFinal* L){
	Grafo* G = GRF_Criar_Grafo();

	Listadocentes* Lista_Docentes;
	Listadiscentes* Lista_Discentes;
	Listadiscentesexternos* Lista_Discentes_EXT;
	listaDePeriodicosFinal* LP;

	string Titulo, Autor;
	int Ano;

	for(LP = L; LP != NULL; LP = LP->prox){
		Titulo = LP->tituloPeriodico;
		Ano = atoi(LP->ano);

		G = GRF_Insere_Nova_Publicacao(G, Titulo, Ano);

		Lista_Docentes = LP->docentes;
		Lista_Discentes = LP->discentes;
		Lista_Discentes_EXT = LP->discentesexternos;
		Autor = LP->nomeProfessor;

		G = GRF_Insere_Autor(G, Autor, Titulo);
		G = GRF_Insere_Listas_participantes(G, Titulo, Lista_Docentes, Lista_Discentes, Lista_Discentes_EXT);

	}
	return G;
}

/*!
* \brief Gera um grafo com as informacoes de uma struct listaDeEventos.
*
* \param L lista a ser colocada no Grafo.
* \return Grafo de relacionamento dos eventos.
*/
Grafo* GRF_ListaEventos_Grafo(listaDeEventosFinal* L){
	Grafo* G = GRF_Criar_Grafo();

	Listadocentes* Lista_Docentes;
	Listadiscentes* Lista_Discentes;
	Listadiscentesexternos* Lista_Discentes_EXT;
	listaDeEventosFinal* LP;

	string Titulo, Autor;
	int Ano;

	for(LP = L; LP != NULL; LP = LP->prox){
		Titulo = LP->titulo;
		Ano = atoi(LP->ano);

		G = GRF_Insere_Nova_Publicacao(G, Titulo, Ano);

		Lista_Docentes = LP->docentes;
		Lista_Discentes = LP->discentes;
		Lista_Discentes_EXT = LP->discentesexternos;
		Autor = LP->nomeProfessor;

		G = GRF_Insere_Autor(G, Autor, Titulo);
		G = GRF_Insere_Listas_participantes(G, Titulo, Lista_Docentes, Lista_Discentes, Lista_Discentes_EXT);
	}

	return G;
}

/*!
* \brief Gera um grafo com as informacoes de uma struct listaDeProjetos.
*
* \param L lista a ser colocada no Grafo.
* \return Grafo de relacionamento dos projetos.
*/
Grafo* GRF_ListaProjetos_Grafo(listadeprojetosfinal* L){
	Grafo* G = GRF_Criar_Grafo();

	Listadocentes* Lista_Docentes;
	Listadiscentes* Lista_Discentes;
	Listadiscentesexternos* Lista_Discentes_EXT;
	listadeprojetosfinal* LP;

	string Titulo, Autor;
	int Ano;

	for(LP = L; LP != NULL; LP = LP->prox){
		Titulo = LP->nomeprojeto;
		Ano = LP->anodeinicio;

		G = GRF_Insere_Nova_Publicacao(G, Titulo, Ano);

		Lista_Docentes = LP->docentes;
		Lista_Discentes = LP->discentes;
		Lista_Discentes_EXT = LP->discentesexternos;
		
		Autor = LP->responsavel;

		G = GRF_Insere_Autor(G, Autor, Titulo);
		G = GRF_Insere_Listas_participantes(G, Titulo, Lista_Docentes, Lista_Discentes, Lista_Discentes_EXT);
	}
	
	return G;
}

/*!
* \brief Cria um grafo de relacionamento de uma lista de projetos.
* 
* \param L Lista de projetos.
* \return Grafo de relacionamento dos participantes.
*/
Grafo* GRF_Grafo_Relacionamentos_Projetos(listadeprojetosfinal* L){
	Grafo* G = GRF_Criar_Grafo();

	Listadocentes* Lista_Docentes;
	Listadiscentesexternos* Lista_EXT;
	listadeprojetosfinal* LP;

	string Autor;
	int Ano;

	for(LP = L; LP != NULL; LP = LP->prox){
		Autor = LP->responsavel;
		Ano = LP->anodeinicio;
		Lista_Docentes = LP->docentes;
		Lista_EXT = LP->discentesexternos;

		if(GRF_Verificar_Publicacao(G, Autor)){
			G = GRF_Insere_Listas_participantes(G, Autor, Lista_Docentes, NULL, Lista_EXT);
		}
		else{
			G = GRF_Insere_Nova_Publicacao(G, Autor, Ano);
			G = GRF_Insere_Listas_participantes(G, Autor, Lista_Docentes, NULL, Lista_EXT);
		}
	}

	return G;
}

/*!
* \brief Cria um grafo de relacionamento de uma lista de eventos.
* 
* \param L Lista de eventos.
* \return Grafo de relacionamento dos participantes.
*/
Grafo* GRF_Grafo_Relacionamentos_Eventos(listaDeEventosFinal* L){
	Grafo* G = GRF_Criar_Grafo();

	Listadocentes* Lista_Docentes;
	Listadiscentesexternos* Lista_EXT;
	listaDeEventosFinal* LP;

	string Autor;
	int Ano;

	for(LP = L; LP != NULL; LP = LP->prox){
		Ano = atoi(LP->ano);
		Autor = LP->nomeProfessor;
		Lista_Docentes = LP->docentes;
		Lista_EXT = LP->discentesexternos;

		if(GRF_Verificar_Publicacao(G, Autor)){
			G = GRF_Insere_Listas_participantes(G, Autor, Lista_Docentes, NULL, Lista_EXT);
		}
		else{
			G = GRF_Insere_Nova_Publicacao(G, Autor, Ano);
			G = GRF_Insere_Listas_participantes(G, Autor, Lista_Docentes, NULL, Lista_EXT);
		}	
	}
	return G;
}

/*!
* \brief Cria um grafo de relacionamento de uma lista de periodicos.
* 
* \param L Lista de periodicos.
* \return Grafo de relacionamento dos participantes.
*/
Grafo* GRF_Grafo_Relacionamentos_Periodicos(listaDePeriodicosFinal* L){
	Grafo* G = GRF_Criar_Grafo();

	Listadocentes* Lista_Docentes;
	Listadiscentesexternos* Lista_EXT;
	listaDePeriodicosFinal* LP;

	string Autor;
	int Ano;

	for(LP = L; LP != NULL; LP = LP->prox){
		Ano = atoi(LP->ano);
		Autor = LP->nomeProfessor;
		Lista_Docentes = LP->docentes;
		Lista_EXT = LP->discentesexternos;

		if(GRF_Verificar_Publicacao(G, Autor)){
			G = GRF_Insere_Listas_participantes(G, Autor, Lista_Docentes, NULL, Lista_EXT);
		}
		else{
			G = GRF_Insere_Nova_Publicacao(G, Autor, Ano);
			G = GRF_Insere_Listas_participantes(G, Autor, Lista_Docentes, NULL, Lista_EXT);
		}	
	}
	return G;
}

/*	Funcoes genericas	*/
/*!
* \brief "Para" a execucao do programa, pedindo ao usuario que digite uma tecla.
*
*/
void GRF_Pause(void){
	printf("\n\nPressione qualquer tecla para continuar...\n");
	getchar();
	return;
}