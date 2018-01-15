/* Modulo de decalaracao das funcoes */

/* Funcoes para corrigir o nome, visto que a leitura nos arquivos 
seria feia ate encontrar o "\n" */
void corrigeNome(char nome[100]);
void corrigeNome2(char nome[100]);

/* Funcoes que pega os dados dos arquivos txt e inserem nas listas
declaradas no lista.h */
listaDeAlunos* txtDiscentesEmLista(void);
listaDeProfessores* txtDocentesEmLista(void);
listaDeProjetos* txtProjetosEmLista(void);
