/*****************************************************************************************************************
--> Modulo 1: Lê os arquivos textos e gera listas com as informações lidas
-->Módulo 2: Cria Listas separando os autores dos projetos, eventos e periodicos em docentes, discentes e discentes externos
-->Módulo 4: Salva as informações nos arquivos
OBS: Para informações mais detalhadas, favor olhar a documentação do Doxygen.
OBS2: Para o dirent.h funcionar corretamente, mude o diretorio na main.c. P/ Linux 64-bits


Módulo de Grafos:

* Trabalho II – Modulo III - Grafos
* Ícaro Marcelino Miranda - Mat.: 14/0022139
*
* Turma A - Programação Sistemática (113956)
*
* 	O objetivo do módulo é a criação de grafos de relacionamento, para isso, foram criadas as seguintes
* funções:
*
* Funções diponibilizadas para os módulos clientes:
*
* 01.	int GRF_Grafo_Vazio(Grafo* G);
*	Verifica se um grafo está vazio, retornando true ou false.
*
* 02.	int GRF_Quantidade_Publicacoes(Grafo*);
*	Retorna a quantidade de periódicos, grafos ou eventos um grafo possui.
*
* 03. 	void GRF_Liberar_Grafo(Grafo* G);
*	Destroi um grafo.
*
* 04. 	void GRF_Imprimir_Grafo(Grafo* G);
*	Imprime em tela um grafo.
*
* 05. 	void GRF_Busca_por_Publicacao(Grafo* G, string Publicacao);
*	Busca periódicos ou eventos contidos em um grafo, imprimindo, caso encontre, seus autores em tela.
* 
* 06. 	void GRF_Gerar_Arquivo(Grafo* G, string Nome_Arquivo);
*	Imprime em um arquivo passado como parâmetro as informações de um grafo.
*
* 07. 	void GRF_Busca_por_Autor(Grafo* G, string Autor);
*	Busca todas as ocorrências de um autor em um grafo, imprimindo eventos ou periódicos relacionados.
*
* 08. 	Grafo* GRF_Criar_Grafo(void);
*	Gera um grafo vazio.
*
* 09. 	Grafo* GRF_Insere_Nova_Publicacao(Grafo* G, string Publicacao);
*	Insere um novo evento ou periódico em um grafo.
*
* 10. 	Grafo* GRF_Remove_Publicacao(Grafo* G, string Publicacao);
*	Remove um evento ou periódico do grafo.
*
* 11. 	Grafo* GRF_Insere_Autor(Grafo* G, string, string);
*	Insere em um grafo um autor em um evento ou periódico já existente.
*
* 12. 	Grafo* GRF_ListaPeriodicos_Grafo(listaDePeriodicosFinal*);
*	Gera um grafo através de uma struct de informação listaDePeriodicos, disponível no modulo 2.
*
* 13. 	Grafo* GRF_ListaEventos_Grafo(listaDeEventosFinal*);
*	Gera um grafo através de uma struct de informação listaDeEventos, disponível no modulo 2.
*
* 14.	Grafo*	GRF_ListaProjetos_Grafo(listadeprojetosfinal*);
*	Gera um grafo através de uma struct de informação listaDeProjetos, disponível no modulo 2.
*
* 15.	void GRF_Pause(void);
*	Para a execução do programa, solicitando ao usuário que digite alguma tecla para continuar.
*
*****************************************************************************************************************/
