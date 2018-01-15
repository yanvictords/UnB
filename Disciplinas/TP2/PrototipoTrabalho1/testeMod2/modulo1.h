/* Modulo de decalaracao das funcoes */

/* Funcoes para corrigir o nome, visto que a leitura nos arquivos 
seria feia ate encontrar o "\n" */
void corrigeNome(char nome[100]);
void corrigeNome2(char nome[100]);

/* Funcoes que pega os dados dos arquivos txt e inserem nas listas
declaradas no lista.h */
listaDeAlunos* txtDiscentesEmLista(char* arquivo_doutorado, char* arquivo_mestrado);
listaDeProfessores* txtDocentesEmLista(char* arquivo);
listaDeProjetos* txtProjetosEmLista(char* arquivo);
listaDeEventos* txtEventosEmLista(char* arquivo);
listaDePeriodicos* txtPeriodicosEmLista(char* arquivo);

	