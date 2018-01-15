/*!
* \file grafos_inst.c
* \brief Modulo de implementacao instrumentada de grafos.
*
* O objetivo desse modulo e a implementacao de funcoes que possibilitem
* a criacao de grafos de relacionamento para publicacoes, seus autores e
* participantes, sempre monitorando a execeucao de todas as funcoes por
* meio de varias verificacoes.
* E importante obsservar os sinonimos de tipos:
* Listadocentes* 			pDocentes
* Listadiscentes* 			pDiscentes
* Listadiscentesexternos*	pDiscentesEXT
* listadeprojetosfinal*		pProjetos
* listaDePeriodicosFinal*	pPeriodicos
* listaDeEventosFinal*		pEventos
*
* \author Icaro Marcelino Miranda.
* \since 01/07/2015.
* \version 1.0.
*
*/

#ifndef GRAFOS_INST_H_INCLUDED
	#define GRAFOS_INST_H_INCLUDED
	#include "grafos_inst.h"
#endif

/** 
* Funcoes internas de manipulacao de listas de string
* (Nao estao disponiveis para os modulos clientes).
**/
int 	GRF_INST_Lista_Vazia(PLista);
int 	GRF_INST_Buscar_Lista(string, PLista);
int 	GRF_INST_Member(string, string*, int);
int 	GRF_INST_Verificar_Estrutura_Lista(PLista);
int 	GRF_INST_Verificar_Estrutura_Grafo(Grafo*);
int 	GRF_INST_Verificar_Estrutura_ListaPrdcs(pPeriodicos);
int 	GRF_INST_Verificar_Estrutura_ListaPrjts(pProjetos);
int 	GRF_INST_Verificar_Estrutura_ListaEvnts(pEventos);
void	GRF_INST_Liberar_Lista(PLista);
void	GRF_INST_Print_Lista(PLista);
void	GRF_INST_filePrint_Lista(PLista, FILE*);
PLista	GRF_INST_Criar_Lista(void);
PLista	GRF_INST_Insere_Inicio_Lista(PLista, string);
PLista	GRF_INST_Insere_Fim_Lista(PLista, string);
string	GRF_INST_Car(PLista);
Grafo* 	GRF_INST_Insere_Listas_participantes(Grafo*, string, pDocentes, pDiscentes, pDiscentesEXT);

/*!
* \brief Verifica a estrutura de uma lista.
*
* \param lista Lista a ser verificada.
* \return Quantidade de elementos da lista.
*/
int GRF_INST_Verificar_Estrutura_Lista(PLista lista){
	if(lista == NULL){
		return 0;
	}

	PLista aux;
	int cont = 0;

	for(aux = lista; aux != NULL; aux = aux->down){
		cont += 1;
	}
	return cont;
}

/*!
* \brief Verifica a estrutura de uma lista de periodicos.
*
* \param lista Lista a ser verificada.
* \return Quantidade de elementos da lista.
* \see modulo2.h
*/
int GRF_INST_Verificar_Estrutura_ListaPrdcs(pPeriodicos lista){

/*	string profsPPGI[25] = {"Alba Cristina Magalhães Alves de Melo", "Aletéia Patrícia Favacho",
"Anderson Clayton Nascimento", "André Costa Drummond", "Bruno Luiggi Macchiavello Espinoza",
"Camilo Chang Dorea", "Carla Denise Castanho", "Cláudia Nalon", "Célia Ghedini Ralha",
"Diego de Freitas Aranha", "Flávio de Barros Vidal", "Genaína Nunes Rodrigues", 
"George Luiz Medeiros Teodoro", "Jan Mendonca Correa" "Jacir Luiz Bordim", "Jorge Carlos Lucero",
"Li Weigang", "Maria Emília Machado Telles Walter", "Maristela Terto de Holanda", "Maurício Ayala Rincón",
"Mylène C. Q. Farias", "Priscila América Solís Mendez Barreto", "Ricardo Lopes de Queiroz",
"Ricardo Pezzuol Jacobi", "Vander Ramos Alves"};*/

	if(lista == NULL){
		return 0;
	}

	pPeriodicos aux;
	int cont = 0;

	for(aux = lista; aux != NULL; aux = aux->prox){
		/*if(!GRF_INST_Member(aux->nomeProfessor, profsPPGI, 25)){
			printf("\nAviso: Professor %s nao consta na lista do PPGI.\n", aux->nomeProfessor);
			GRF_INST_Pause();
		}*/
		cont += 1;
	}
	return cont;
}

/*!
* \brief Verifica a estrutura de uma lista de projetos.
*
* \param lista Lista a ser verificada.
* \return Quantidade de elementos da lista.
* \see modulo2.h
*/
int GRF_INST_Verificar_Estrutura_ListaPrjts(pProjetos lista){

/*	string profsCIC[48] = {	"Alba Cristina M. de Melo",	"Aleteia Patricia Favacho",	"Alexandre Zaghetto", 
"Aluizio Arcela Junior", "André Costa Drummond", "Bruno Luiggi Macchiavello", "Camilo Chang Dórea",
"Carla Denise Castanho", "Carla Maria Chagas e Cavalcante Koike", "Célia Ghedini Ralha", "Claudia Nalon",
"Díbio Leandro Borges", "Edison Ishikawa", "Eduardo Adilio Pelinson Alchieri", "Fernanda Lima",
"Fernando Antonio de A. Chacon de Albuquerque", "Flávio Leonardo Cavalcanti de Moura",
"Flávio de Barros Vidal", "Francisco de Assis Cartaxo Pinheiro", "Genaina Nunes Rodrigues", 
"George Luiz Medeiros Teodoro", "Germana Menezes da Nóbrega", "Guilherme Novaes Ramos", 
"Homero Luiz Piccolo", "Jacir Luiz Bordim", "Jan Mendonça Corrêa", "João José Costa Gondim",
"José Carlos Loureiro Ralha", "Jorge Carlos Lucero", "Jorge Henrique Cabral Fernandes", "Li Weigang",
"Marcelo Ladeira", "Marcio da Costa Perreira Brandão", "Marcos Fagundes Caetano", "Marcus Vinicius Lamar",
"Maria de Fátima Ramos Brandão", "Maria Emilia Machado Telles Walter", "Maristela Terto de Holanda",
"Mauricio Ayala Rincón", "Murilo Silva de Camargo", "Pedro Antônio Dourado de Rezende", 
"Pedro de Azevedo Berger", "Priscila América Solis M. Barreto", "Ricardo Lopes de Queiroz",
"Ricardo Pezzoul Jacobi", "Rodrigo Bonifacio de Almeida", "Vander Ramos Alves",  "Wilson Henrique Veneziano"};
*/
	if(lista == NULL){
		return 0;
	}

	pProjetos aux;
	int cont = 0;

	for(aux = lista; aux != NULL; aux = aux->prox, cont++){
		/*if(!GRF_INST_Member(aux->responsavel, profsCIC, 48)){
			printf("\nAviso: Professor %s nao consta na lista do CIC.\n", aux->responsavel);
			GRF_INST_Pause();
		}*/
		cont += 1;
	}
	return cont;
}

/*!
* \brief Verifica a estrutura de uma lista de eventos.
*
* \param lista Lista a ser verificada.
* \return Quantidade de elementos da lista.
* \see modulo2.h
*/
int GRF_INST_Verificar_Estrutura_ListaEvnts(pEventos lista){

/*	string profsPPGI[25] = {"Alba Cristina Magalhães Alves de Melo", "Aletéia Patrícia Favacho",
"Anderson Clayton Nascimento", "André Costa Drummond", "Bruno Luiggi Macchiavello Espinoza",
"Camilo Chang Dorea", "Carla Denise Castanho", "Cláudia Nalon", "Célia Ghedini Ralha",
"Diego de Freitas Aranha", "Flávio de Barros Vidal", "Genaína Nunes Rodrigues", 
"George Luiz Medeiros Teodoro", "Jan Mendonca Correa" "Jacir Luiz Bordim", "Jorge Carlos Lucero",
"Li Weigang", "Maria Emília Machado Telles Walter", "Maristela Terto de Holanda", "Maurício Ayala Rincón",
"Mylène C. Q. Farias", "Priscila América Solís Mendez Barreto", "Ricardo Lopes de Queiroz",
"Ricardo Pezzuol Jacobi", "Vander Ramos Alves"};*/

	if(lista == NULL){
		return 0;
	}

	pEventos aux;
	int cont = 0;

	for(aux = lista; aux != NULL; aux = aux->prox, cont++){
		/*if(!GRF_INST_Member(aux->nomeProfessor, profsPPGI, 25)){
			printf("\nAviso: Professor %s nao consta na lista do PPGI.\n", aux->nomeProfessor);
			GRF_INST_Pause();
		}*/
		cont += 1;
	}
	return cont;
}

/*!
* \brief Verifica a estrutura de um grafo.
*
* \param G Grafo a ser verificado.
* \return Quantidade total de autores presentes no grafo, 
* caso a estrutura esteja correta ou -1 caso a estrutura esteja
* incorreta.
*/
int GRF_INST_Verificar_Estrutura_Grafo(Grafo* G){
	if(GRF_INST_Grafo_Vazio(G)){
		return 0;
	}

	PLista aux;
	int n_pub = 0; /* Numero de publicacoes. */
	int n_aut = 0; /* Numero total de autores. */

	for(aux = G->inicio; aux != NULL; aux = aux->up, n_pub++){
		n_aut += GRF_INST_Verificar_Estrutura_Lista(aux->down);
	}
	if(n_pub == G->qnt){
		return n_aut;
	}
	return -1;
}

/*!
* \brief Verfica se uma palavra existe em um array de palavras.
*
* \param elem Palavra a ser pesquisada.
* \param lista Array de palavras.
* \param tam Tamanho do array.
* \return 1 se a palavra exite no array, 0 se nao existir.
*/
int GRF_INST_Member(string elem, string* lista, int tam){
	int i;

	for(i = 0; i < tam-1; i++){
		if(strstr(lista[i], elem) != NULL){
			return 1;
		}
	}
	return 0;
}

/*!
* \brief Busca por ano uma publicacao em um grafo, imprimindo seus autores.
*
* \param G Ponteiro para o grafo contendo a publicacao.
* \param Ano Ano da publicacao.
*/
void GRF_INST_Busca_por_Ano(Grafo* G, int Ano){
	PLista aux;
	if(GRF_INST_Verificar_Estrutura_Grafo(G) == -1){
		printf("Erro no Grafo\n");
		return;
	}
	if(GRF_INST_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
	}
	else{
		printf("(%d)\n", Ano);
		for(aux = G->inicio; aux != NULL; aux = aux->up){
			if(aux->ano == Ano){
				printf("%s:\n", aux->info);
				GRF_INST_Print_Lista(aux->down);
			}
		}
	}
	printf("Fim da busca.\n\n");
	return;
}

/*!
* \brief Verfica se dada lista e vazia.
*
* \param lista Ponteiro para lista a ser verificada.
* \return 1 para lista vazia, 0 para nao vazia.
*/
int GRF_INST_Lista_Vazia(PLista lista){
	return (lista == NULL);
}

/*!
* \brief Verifica se existe certo elemento em uma lista.
*
* \param lista Ponteiro para lista pesquisada.
* \param valor String a ser pesquisada.
* \return 1 para elemento presente, 0 para elemento nao presente ou lista vazia.
*/
int GRF_INST_Buscar_Lista(string valor, PLista lista){
	PLista L;

	if((valor != NULL)&&(lista != NULL)){
		for (L = lista; L != NULL; L = L->down){
			if (strstr(L->info, valor) != NULL){
				return 1;
			}
		}
	} 
	return 0;			
}

/*!
* \brief Destroi uma lista.
*
* \param lista Ponteiro para lista a ser destruida.
*/
void GRF_INST_Liberar_Lista(PLista lista){
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
void GRF_INST_Print_Lista(PLista lista){
	PLista L;
	
	if(lista == NULL){
		printf("Lista vazia.\n");
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
void GRF_INST_filePrint_Lista(PLista lista, FILE* Arquivo){
	PLista L;
	
	if(lista == NULL){
		printf("GRF_INST_filePrint_Lista> Lista Vazia, arquivo nao gerado.\n");
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
PLista GRF_INST_Criar_Lista(void){
	return NULL;
}

/*!
* \brief Insere uma nova string no inicio de uma lista.
*
* \param lista Ponteiro para lista que vai receber a insercao.
* \param valor String a ser inserida.
* \return Ponteiro para a lista atualizada.
*/
PLista GRF_INST_Insere_Inicio_Lista(PLista lista, string valor){
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
PLista GRF_INST_Insere_Fim_Lista(PLista lista, string valor){
	PLista novo = (PLista) malloc(sizeof(lista));
	PLista ref;

	if(GRF_INST_Lista_Vazia(lista)){
		return lista = GRF_INST_Insere_Inicio_Lista(lista, valor);
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
string GRF_INST_Car(PLista L){
	return L->info;
}


/*	Fucoes para a manipulacao de grafos 	*/
/*!
* \brief Verifica se um grafo esta vazio.
*
* \param G Grafo a ser testado.
* \return 1 para grafo vazio, 0 para grafo nao vazio.
*/
int GRF_INST_Grafo_Vazio(Grafo* G){
	return ((G->inicio == NULL) || (G->qnt == 0));
}

/*!
* \brief Consulta quantos projetos, periodicos ou eventos um grafo possui.
*
* \param G Grafo a ser consultado.
* \return Numero de projetos.
*/
int GRF_INST_Quantidade_Publicacoes(Grafo* G){
	return G->qnt;
}

/*!
* \brief Destroi um grafo.
*
* \param G Ponteiro para o grafo a ser destruido.
*/
void GRF_INST_Liberar_Grafo(Grafo* G){
	PLista aux, ref;
	if(!GRF_INST_Grafo_Vazio(G)){
		for(aux = G->inicio; aux->up != NULL; ){
			GRF_INST_Liberar_Lista(aux->down);
			ref = aux->up;
			free(aux);
			aux = ref;
		}
		free(G);
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
int GRF_INST_Verificar_Autor(Grafo* G, string Nome){
	PLista aux;
	if(!GRF_INST_Grafo_Vazio(G)){
		for(aux = G->inicio; aux != NULL; aux = aux->up){
			if (GRF_INST_Buscar_Lista(Nome, aux->down) == 1){
				printf("Autor %s encontrado na publicacao %s.\n", Nome, aux->info);
				return 1;
			}
		}
	}
	printf("Autor %s nao encontrado.\n", Nome);
	return 0;
}

/*!
* \brief Verifica por nome ou trecho de nome uma publicacao em um grafo.
*
* \param G Ponteiro para o grafo contendo a publicacao.
* \param Nome String com o nome da pulicacao.
* \return 1 se encontrar, 0 se nao encontrar.
*/
int GRF_INST_Verificar_Publicacao(Grafo* G, string Nome){
	PLista aux;
	if(!GRF_INST_Grafo_Vazio(G)){
		for(aux = G->inicio; aux != NULL; aux = aux->up){
			if(strstr(aux->info, Nome) != NULL){
				return 1;
			}
		}
	}
	printf("Publicacao %s nao encontrada.\n", Nome);
	return 0;
}


/*!
* \brief Imprime em tela as informacoes de um grafo.
*
* \param G Ponteiro para o grafo a ser impresso.
*/
void GRF_INST_Imprimir_Grafo(Grafo* G){
	PLista aux;
	if(GRF_INST_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
	}
	else{
		printf("> Impressao Grafo de Relacionamentos:\n");
		for(aux = G->inicio; aux->up != NULL; aux = aux->up){
			printf("%s (%d):\n", aux->info, aux->ano);
			GRF_INST_Print_Lista(aux->down);
			printf("---\n");

		}
		printf("%s (%d):\n", aux->info, aux->ano);
		GRF_INST_Print_Lista(aux->down);
		printf("---\n\n");
	}
	return;
}

/*!
* \brief Busca por nome ou trecho de nome uma publicacao em um grafo, imprimindo seus autores.
*
* \param G Ponteiro para o grafo contendo a publicacao.
* \param Publicacao String com o nome da pulicacao.
*/
void GRF_INST_Busca_por_Publicacao(Grafo* G, string Nome){
	PLista aux;
	if(GRF_INST_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
	}
	else{
		for(aux = G->inicio; aux != NULL; aux = aux->up){
			if(strstr(aux->info, Nome) != NULL){
				printf("%s:\n", aux->info);
				GRF_INST_Print_Lista(aux->down);
				break;
			}
		}
	}
	return;
}

/*!
* \brief Gera um arquivo contendo as informacoes de um grafo.
*
* \param G grafo a ser impresso.
* \param Nome String com o nome desejado para o novo arquivo.
*/
void GRF_INST_Gerar_Arquivo(Grafo* G, string Nome){
	if(GRF_INST_Grafo_Vazio(G)){
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
			GRF_INST_filePrint_Lista(aux->down, Arquivo);
		}
		fprintf(Arquivo,"%s (%d):\n", aux->info, aux->ano);
		GRF_INST_filePrint_Lista(aux->down, Arquivo);
		fclose(Arquivo);

		printf("\nArquivo <%s> gerado com sucesso.\n", Nome);
	}
	return;
}

/*!
* \brief Busca por nome ou trecho de nome as ocorrencias de um autor em um grafo, imprimindo suas publicacoes.
*
* \param G Ponteiro para o grafo contendo a publicacao.
* \param Autor String com o nome do autor.
*/
void GRF_INST_Busca_por_Autor(Grafo* G, string Nome){
	PLista aux;
	if(GRF_INST_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
	}
	else{
		printf("%s:\n", Nome);
		for(aux = G->inicio; aux != NULL; aux = aux->up){
			if (GRF_INST_Buscar_Lista(Nome, aux->down) == 1){
				printf("%s\n", aux->info);
			}
		}
		printf("-\n");
	}
	return;
}

/*!
* \brief Cria um grafo vazio.
*
* \return Ponteiro para o novo grafo.
*/
Grafo* GRF_INST_Criar_Grafo(void){
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
Grafo* GRF_INST_Insere_Nova_Publicacao(Grafo* G, string Nome, int ano){
	PLista L = (PLista)malloc(sizeof(struct lista));
	int n_pub = G->qnt;

		L->info = Nome;
		L->down = GRF_INST_Criar_Lista();
		L->ano = ano;

	if(GRF_INST_Grafo_Vazio(G)){
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

	if(G->qnt == n_pub + 1){
		return G;
	}
	else{
		printf("Grafo corrompido. Retornando grafo vazio.\n");
		GRF_INST_Pause();
		GRF_INST_Liberar_Grafo(G);
		G = GRF_INST_Criar_Grafo();
		return G;
	}
}

/*!
* \brief Remove uma publicacao de um grafo.
*
* \param G Ponteiro para o Grafo desejado.
* \param Publicacao Nome da publicacao a ser removida.
* \return Ponteiro para o Grafo atualizado.
*/
Grafo* GRF_INST_Remove_Publicacao(Grafo* G, string Publicacao){
	PLista aux, L1, L2;
	int n_pub = G->qnt;

	if(GRF_INST_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
	}
	else{
		for(aux = G->inicio; aux != NULL; aux = aux->up){
			if(strstr(aux->info, Publicacao) != NULL){
				GRF_INST_Liberar_Lista(aux->down);
				L2 = aux->up;
				free(aux);
				L1->up = L2;
				G->qnt--;
				break;
			}
			L1 = aux;
		}
	}
	if(G->qnt == n_pub-1){
		return G;
	}
	else{
		printf("Grafo corrompido. Retornando grafo vazio.\n");
		GRF_INST_Pause();
		GRF_INST_Liberar_Grafo(G);
		G = GRF_INST_Criar_Grafo();
		return G;
	}
}

/*!
* \brief Insere um novo autor para uma publicacao contida em um grafo.
*
* \param G Ponteiro para o grafo contendo a publicacao.
* \param Autor String com o nome do autor.
* \param Publicacao String com o nome da pulicacao.
* \return Ponteiro para o grafo atualizado.
*/
Grafo* GRF_INST_Insere_Autor(Grafo* G, string Autor, string Publicacao){
	PLista aux;
		for(aux = G->inicio; ; aux = aux->up){
			if(aux == NULL){
				printf("\nPublicacao nao encontrada.\n");
				break;
			}
			if(strstr(GRF_INST_Car(aux), Publicacao) != NULL){
				if(!GRF_INST_Buscar_Lista(Autor, aux->down)){
					aux->down = GRF_INST_Insere_Fim_Lista(aux->down, Autor);
				}				
				break;
			}
		}

	if(GRF_INST_Verificar_Estrutura_Grafo(G) != -1){
		return G;
	}
	else{
		printf("Grafo corrompido. Retornando grafo vazio.\n");
		GRF_INST_Pause();
		GRF_INST_Liberar_Grafo(G);
		G = GRF_INST_Criar_Grafo();
		return G;
	}
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
* \see modulo2.h
*
* \return Grafo atualizado.
*/
Grafo* GRF_INST_Insere_Listas_participantes(Grafo* G, string Titulo, pDocentes Lista_Docentes, pDiscentes Lista_Discentes, pDiscentesEXT Lista_Discentes_EXT){
	
	if(GRF_INST_Grafo_Vazio(G)){
		printf("Grafo Vazio\n");
		return G;
	}

	string Docente, Discente, ParticipanteExterno;

	while((Lista_Docentes != NULL)||(Lista_Discentes != NULL)||(Lista_Discentes_EXT != NULL)){

			if(Lista_Docentes != NULL){
				Docente = strcat(Lista_Docentes->nomedocente, " (Docente)");
				G = GRF_INST_Insere_Autor(G, Docente, Titulo);
				Lista_Docentes = Lista_Docentes->prox;
			}
			if(Lista_Discentes != NULL){
				Discente = strcat(Lista_Discentes->nomediscente, " (Discente)");
				G = GRF_INST_Insere_Autor(G, Discente, Titulo);
				Lista_Discentes = Lista_Discentes->prox;
			}
			if(Lista_Discentes_EXT != NULL){
				ParticipanteExterno = strcat(Lista_Discentes_EXT->nomediscenteexterno, " (ParticipanteExterno)");
				G = GRF_INST_Insere_Autor(G, ParticipanteExterno, Titulo);
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
Grafo* GRF_INST_ListaPeriodicos_Grafo(pPeriodicos L){
	Grafo* G = GRF_INST_Criar_Grafo();
	printf("GRF_INST_ListaPeriodicos_Grafo> Chamada de funcao.\n");

	if(GRF_INST_Verificar_Estrutura_ListaPrdcs(L) == 0){
		printf("GRF_INST_ListaProjetos_Grafo> Lista Vazia recebida, retornando grafo vazio.\n");
		return G;
	}
	if(L != NULL){
		pDocentes Lista_Docentes;
		pDiscentes Lista_Discentes;
		pDiscentesEXT Lista_Discentes_EXT;
		pPeriodicos LP;

		string Titulo, Autor;
		int Ano;

		for(LP = L; LP != NULL; LP = LP->prox){
			Titulo = LP->tituloPeriodico;
			Ano = atoi(LP->ano);

			G = GRF_INST_Insere_Nova_Publicacao(G, Titulo, Ano);

			Lista_Docentes = LP->docentes;
			Lista_Discentes = LP->discentes;
			Lista_Discentes_EXT = LP->discentesexternos;
			Autor = LP->nomeProfessor;

			G = GRF_INST_Insere_Autor(G, Autor, Titulo);
			G = GRF_INST_Insere_Listas_participantes(G, Titulo, Lista_Docentes, Lista_Discentes, Lista_Discentes_EXT);
		}
	}
	else{
		printf("GRF_INST_ListaPeriodicos_Grafo> Lista recebida vazia, gerando grafo vazio.\n");
	}
	printf("GRF_INST_ListaPeriodicos_Grafo> Grafo gerado com sucesso: %d publicacoes, %d autores\n\n", G->qnt, GRF_INST_Verificar_Estrutura_Grafo(G));

	return G;
}

/*!
* \brief Gera um grafo com as informacoes de uma struct listaDeEventos.
*
* \param L lista a ser colocada no Grafo.
* \return Grafo de relacionamento dos eventos.
*/
Grafo* GRF_INST_ListaEventos_Grafo(pEventos L){
	Grafo* G = GRF_INST_Criar_Grafo();
	printf("GRF_INST_ListaEventos_Grafo> Chamada de funcao.\n");

	if(GRF_INST_Verificar_Estrutura_ListaEvnts(L) == 0){
		printf("GRF_INST_ListaEventos_Grafo> Lista Vazia recebida, retornando grafo vazio.\n");
		return G;
	}
	if(L != NULL){
		pDocentes Lista_Docentes;
		pDiscentes Lista_Discentes;
		pDiscentesEXT Lista_Discentes_EXT;
		pEventos LP;

		string Titulo, Autor;
		int Ano;

		for(LP = L; LP != NULL; LP = LP->prox){
			Titulo = LP->titulo;
			Ano = atoi(LP->ano);

			G = GRF_INST_Insere_Nova_Publicacao(G, Titulo, Ano);

			Lista_Docentes = LP->docentes;
			Lista_Discentes = LP->discentes;
			Lista_Discentes_EXT = LP->discentesexternos;
			Autor = LP->nomeProfessor;

			G = GRF_INST_Insere_Autor(G, Autor, Titulo);
			G = GRF_INST_Insere_Listas_participantes(G, Titulo, Lista_Docentes, Lista_Discentes, Lista_Discentes_EXT);
		}
	}
	else{
		printf("GRF_INST_ListaEventos_Grafo> Lista recebida vazia, gerando grafo vazio.\n");
	}
	printf("GRF_INST_ListaEventos_Grafo> Grafo gerado com sucesso: %d publicacoes, %d autores\n\n", G->qnt, GRF_INST_Verificar_Estrutura_Grafo(G));
	return G;
}

/*!
* \brief Gera um grafo com as informacoes de uma struct listaDeProjetos.
*
* \param L lista a ser colocada no Grafo.
* \return Grafo de relacionamento dos projetos.
*/
Grafo* GRF_INST_ListaProjetos_Grafo(pProjetos L){
	printf("GRF_INST_ListaProjetos_Grafo> Chamada de funcao.\n");
	Grafo* G = GRF_INST_Criar_Grafo();

	if(GRF_INST_Verificar_Estrutura_ListaPrjts(L) == 0){
		printf("GRF_INST_ListaProjetos_Grafo> Lista Vazia recebida, retornando grafo vazio.\n");
		return G;
	}
	if(L != NULL){
		pDocentes Lista_Docentes;
		pDiscentes Lista_Discentes;
		pDiscentesEXT Lista_Discentes_EXT;
		pProjetos LP;

		string Titulo, Autor;
		int Ano;

		for(LP = L; LP != NULL; LP = LP->prox){
			Titulo = LP->nomeprojeto;
			Ano = LP->anodeinicio;

			G = GRF_INST_Insere_Nova_Publicacao(G, Titulo, Ano);

			Lista_Docentes = LP->docentes;
			Lista_Discentes = LP->discentes;
			Lista_Discentes_EXT = LP->discentesexternos;
		
			Autor = LP->responsavel;

			G = GRF_INST_Insere_Autor(G, Autor, Titulo);
			G = GRF_INST_Insere_Listas_participantes(G, Titulo, Lista_Docentes, Lista_Discentes, Lista_Discentes_EXT);
		}
	}
	else{
		printf("GRF_INST_ListaProjetos_Grafo> Lista recebida vazia, gerando grafo vazio.\n");
	}
	printf("GRF_INST_ListaProjetos_Grafo> Grafo gerado com sucesso: %d publicacoes, %d autores\n\n", G->qnt, GRF_INST_Verificar_Estrutura_Grafo(G));
	return G;
}

/*!
* \brief Cria um grafo de relacionamento de uma lista de projetos.
* 
* \param L Lista de projetos.
* \return Grafo de relacionamento dos participantes.
*/
Grafo* GRF_INST_Grafo_Relacionamentos_Projetos(pProjetos L){
	Grafo* G = GRF_INST_Criar_Grafo();

	if(GRF_INST_Verificar_Estrutura_ListaPrjts(L) == 0){
		printf("Grafo Relacionamentos Projetos> Lista Vazia recebida, retornando grafo vazio.\n");
		return G;
	}

	pDocentes Lista_Docentes;
	pDiscentesEXT Lista_Discentes_EXT;
	pProjetos LP;

	string Autor;
	int Ano;

	for(LP = L; LP != NULL; LP = LP->prox){
		Autor = LP->responsavel;
		Ano = LP->anodeinicio;
		Lista_Docentes = LP->docentes;
		Lista_Discentes_EXT = LP->discentesexternos;

		if(GRF_INST_Verificar_Publicacao(G, Autor)){
			G = GRF_INST_Insere_Listas_participantes(G, Autor, Lista_Docentes, NULL, Lista_Discentes_EXT);
		}
		else{
			G = GRF_INST_Insere_Nova_Publicacao(G, Autor, Ano);
			G = GRF_INST_Insere_Listas_participantes(G, Autor, Lista_Docentes, NULL, Lista_Discentes_EXT);
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
Grafo* GRF_INST_Grafo_Relacionamentos_Eventos(pEventos L){
	Grafo* G = GRF_INST_Criar_Grafo();

	if(GRF_INST_Verificar_Estrutura_ListaEvnts(L) == 0){
		printf("Grafo Relacionamentos Eventos> Lista Vazia recebida, retornando grafo vazio.\n");
		return G;
	}

	pDocentes Lista_Docentes;
	pDiscentesEXT Lista_Discentes_EXT;
	pEventos LP;

	string Autor;
	int Ano;

	for(LP = L; LP != NULL; LP = LP->prox){
		Ano = atoi(LP->ano);
		Autor = LP->nomeProfessor;
		Lista_Docentes = LP->docentes;
		Lista_Discentes_EXT = LP->discentesexternos;

		if(GRF_INST_Verificar_Publicacao(G, Autor)){
			G = GRF_INST_Insere_Listas_participantes(G, Autor, Lista_Docentes, NULL, Lista_Discentes_EXT);
		}
		else{
			G = GRF_INST_Insere_Nova_Publicacao(G, Autor, Ano);
			G = GRF_INST_Insere_Listas_participantes(G, Autor, Lista_Docentes, NULL, Lista_Discentes_EXT);
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
Grafo* GR_INST_Grafo_Relacionamentos_Periodicos(pPeriodicos L){
	Grafo* G = GRF_INST_Criar_Grafo();

	if(GRF_INST_Verificar_Estrutura_ListaPrdcs(L) == 0){
		printf("Grafo Relacionamentos Periodicos> Lista Vazia recebida, retornando grafo vazio.\n");
		return G;
	}

	pDiscentesEXT Lista_Discentes_EXT;
	pDocentes Lista_Docentes;
	pPeriodicos LP;

	string Autor;
	int Ano;

	for(LP = L; LP != NULL; LP = LP->prox){
		Ano = atoi(LP->ano);
		Autor = LP->nomeProfessor;
		Lista_Docentes = LP->docentes;
		Lista_Discentes_EXT = LP->discentesexternos;

		if(GRF_INST_Verificar_Publicacao(G, Autor)){
			G = GRF_INST_Insere_Listas_participantes(G, Autor, Lista_Docentes, NULL, Lista_Discentes_EXT);
		}
		else{
			G = GRF_INST_Insere_Nova_Publicacao(G, Autor, Ano);
			G = GRF_INST_Insere_Listas_participantes(G, Autor, Lista_Docentes, NULL, Lista_Discentes_EXT);
		}	
	}
	return G;
}

/*	Funcoes genericas	*/
/*!
* \brief "Para" a execucao do programa, pedindo ao usuario que digite uma tecla.
*
*/
void GRF_INST_Pause(void){
	printf("\n\nPressione qualquer tecla para continuar...\n");
	getchar();
	return;
}