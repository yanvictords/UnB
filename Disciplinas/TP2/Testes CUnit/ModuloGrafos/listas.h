typedef char ValorVertice[100];

/* Estrutura da Lista dos Projetos */
struct listaProj{
	struct listaProj *proximoProjeto;	
	char nomeProjeto[300];
	int anoInicio;
	int mesFim;
	int anoFim;
	char situacao[20];
	char natureza[20];
	char descricao[500];
	char responsavel[100]; /* Somente 1 responsavel e 2 integrantes fixos */
	char integrante1[100], integrante2[100]; 
}typedef listaDeProjetos;

struct listaProf{
	struct listaProf *proximoProfessor;	
	char nomeProfessor[100];
	char nomeParaCitacao[300];
	int numDeProfessores;
	int id; /* Identifica o professor de 0 a "n" */
}typedef listaDeProfessores;

struct listaAlunos{
	struct listaAlunos *proximoAluno;	
	char nomeAluno[100];
	char matricula[10];
	int tipo; /* Mestrado(1) ou Doutorado(2) */

}typedef listaDeAlunos;

struct listaAutores{
	char nomeAutor[100];
	char nomeParaCitacao[300];
	int ordemDeAutoria;
	struct listaAutores *proximoAutor;
}typedef listaDeAutores;

struct listaEventos{
	struct listaEventos *proximoEvento;
	char nomeProfessor[100];
	char nomeParaCitacao_Professor[300];
	char natureza[30];
	char titulo[200];
	char pais[30];
	char idioma[30];
	char nomeEvento[100];
	char ano[10];
	char proceedings[300];
	char volume[30];
	char paginaInicial[10];
	char paginaFinal[10];
	listaDeAutores *autores;
}typedef listaDeEventos;

struct listaPeriodicos{
	struct listaPeriodicos *proximoPeriodico;
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
}typedef listaDePeriodicos;

/* Cria a lista de Projetos */
listaDeProjetos* criaListaDeProjetos(void);

/* Insere um novo projeto na lista */
listaDeProjetos* insereEmListaDeProjetos(listaDeProjetos* Lista, char *nomeProjeto, int anoInicio, 
											int mesFim, int anoFim, char *situacao, char *natureza, 
												char *descricao, char *responsavel, char *integrante1, char *integrante2);

/* Cria a lista dos Professores */
listaDeProfessores* criaListaDeProfessores(void);

/* Insere um novo professor na lista */
listaDeProfessores* insereEmListaDeProfessores(listaDeProfessores *Lista, char* nomeProfessor, char* nomeParaCitacao);

/* Confere se professor ja esta na lista, para nao repetir */
int confereSeProfessorJaEstaNaLista(listaDeProfessores* Lista, char* nomeProfessor);

/* Cria a lista dos Alunos */
listaDeAlunos* criaListaDeAlunos(void);

/* Insere um novo professor na lista */
listaDeAlunos* insereEmListaDeAlunos(listaDeAlunos *Lista, char* nomeAluno, char* matricula, int tipo);

listaDeAutores* criaListaDeAutores(void);

listaDeAutores* insereEmListaDeAutores(listaDeAutores *Lista, char* nomeAutor, char* nomeParaCitacao, int ordemDeAutoria);

listaDeEventos* criaListaDeEventos(void);

listaDeEventos* insereEmListaDeEventos(listaDeEventos *ListaEventos, listaDeAutores *ListaAutores, char* nomeProfessor, char* nomeParaCitacao_Professor, 
										char* natureza, char* titulo, char* pais, char* idioma, char* nomeEvento, char* ano, char* proceedings, char* volume,
										char* paginaInicial, char* paginaFinal);

listaDePeriodicos* criaListaDePeriodicos(void);

listaDePeriodicos* insereEmListaDePeriodicos(listaDePeriodicos *ListaPeriodicos, listaDeAutores *ListaAutores , char* nomeProfessor,
											char* nomeParaCitacao_Professor, char* natureza, char* tituloArtigo, char* tituloPeriodico, 
											char* idioma, char* ano, char* serie, char* volume, char* paginaInicial, char* paginaFinal);



