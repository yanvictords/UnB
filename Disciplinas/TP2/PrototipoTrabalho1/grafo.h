#define VISITADO        1
#define NAOVISITADO     0
/* Definicao do Vertice dos Grafos como uma string de 100 caracteres */
typedef char ValorVertice[100];
typedef struct listaProj listaDeProjetos;
typedef struct listaProf listaDeProfessores;
/* Estrutura das listas que compoem o Grafo */
struct lista_do_grafo{
	ValorVertice nome_Professor;
	struct lista_do_grafo *prox;
}typedef ListaG;

/* Estrutura do Grafo */
struct graf{
	ListaG** Docentes;
	int numProfs;
	int* MARCA;
}typedef Grafo;

Grafo* criaGrafoVazio(int numProfs);


/* Relaciona dois professores no grafo */
Grafo* insereRelacionamento(listaDeProfessores*list, Grafo* grafo, listaDeProjetos* aux);

/* Funcao que coloca um professor dentro de uma lista */
ListaG* anexa(ValorVertice Prof, ListaG* lista);

/* Funcao que confere se dentro de uma lista de professores ja possui algum nome
para evitar repeticoes */
Grafo* iniciagrafoind(listaDeProfessores* listaProfessores, Grafo*grafo);
int confererepeticao(ValorVertice responsavel, ListaG* lista);
