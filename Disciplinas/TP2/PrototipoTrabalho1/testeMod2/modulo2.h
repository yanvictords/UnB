typedef struct listadocentes{
struct listadocentes*prox;
char nomedocente[100];
}Listadocentes;


typedef struct listadiscentes{
struct listadiscentes*prox;
char nomediscente[100];
}Listadiscentes;


typedef struct listadiscentesexternos{
struct listadiscentesexternos*prox;
char nomediscenteexterno[100];
}Listadiscentesexternos;


typedef struct listadeprojetos {	
	char responsavel[100];
	char nomeprojeto[100];
	int anodeinicio;
	int anofim;
	char situacao[100];
	char natureza[100];
	char descricao[100];
	Listadocentes*docentes;
	Listadiscentes*discentes;
	Listadiscentesexternos*discentesexternos;
	struct listadeprojetos*prox;	
}listadeprojetosfinal;


struct listaEventosFinal{
	struct listaEventosFinal*prox;
	char nomeProfessor[100];
	char nomeParaCitacao_Professor[400];
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
	Listadocentes*docentes;
	Listadiscentes*discentes;
	Listadiscentesexternos*discentesexternos;
}typedef listaDeEventosFinal;

listadeprojetosfinal *crialistadeprojetosfinal(void);
