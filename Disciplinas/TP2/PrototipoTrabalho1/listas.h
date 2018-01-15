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



