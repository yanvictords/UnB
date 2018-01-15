/*!
* \file modulo4.h
* \brief Modulo de declaracao das funcoes e estruturas do modulo4.c
*
*/
typedef struct listadeprojetos listadeprojetosfinal;
typedef struct listaEventosFinal listaDeEventosFinal;
typedef struct listaPeriodicosFinal listaDePeriodicosFinal;
void print(listaDeEventosFinal*listaFinal, listadeprojetosfinal *listaFinal2, listaDePeriodicosFinal*listaFinal3, Grafo* G, Grafo* H, Grafo* I);


/**
\mainpage Pagina De Descricao Do Trabalho:
	->Segundo Trabalho de Programação Sistemática\n
	->Professora Genaina\n
	->Integrantes Do Grupo:\n
	1-Pedro Henrique Santos Gonzaga\n
	2-Yan Victor Dos Santos\n
	3-Icaro Marcelino\n
	4-Hugo Fagundes\n
	->Descricao: O programa tem como arquivo de entrada os Projetos, Eventos e Periodicos dos professores e alunos do departamento de Computacao. Depois de tratar as informacoes\n
	lidas do arquivo, ele separa todos os projetos, eventos e periodicos, classificando seus autores em Docentes, Discentes e Discentes externos, além de criar grafos de relacionamentos\n
	dos envovidos em cada trabalho\n\n
	----> Para compilar e executar o programa, em ambiente Linux, abra o terminal, va ate a pasta com os arquivos .c e .h e digite: make\n
	---->Para rodar o programa, digite: ./trabalho2
*/
