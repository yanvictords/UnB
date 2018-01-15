typedef struct listadeprojetos listadeprojetosfinal;
typedef struct listadocentes Listadocentes;
typedef struct listadiscentes Listadiscentes;
typedef struct listadiscentesexternos Listadiscentesexternos;
typedef struct listaAlunos listaDeAlunos;
typedef struct listaProf listaDeProfessores;
typedef struct listaProj listaDeProjetos;

struct listadocentes{
struct listadocentes*prox;
char nomedocente[100];
};


struct listadiscentes{
struct listadiscentes*prox;
char nomediscente[100];
};


struct listadiscentesexternos{
struct listadiscentesexternos*prox;
char nomediscenteexterno[100];
};


struct listadeprojetos{	
	char responsavel[200];
	char nomeprojeto[200];
	int anodeinicio;
	int anofim;
	char situacao[200];
	char natureza[200];
	char descricao[200];
	Listadocentes*docentes;
	Listadiscentes*discentes;
	Listadiscentesexternos*discentesexternos;
	struct listadeprojetos*prox;	
};


listadeprojetosfinal *crialistadeprojetosfinal(void);
listadeprojetosfinal*INSERE_NA_LISTADEPROJETOSFINAL(listadeprojetosfinal*lista1,listaDeProjetos*lista2, listaDeAlunos*lista3,listaDeProfessores*lista4);
