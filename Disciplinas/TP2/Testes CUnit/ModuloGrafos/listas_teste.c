#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "listas.c"

void Add_Suite_Testes(void);
void Teste_criaListaDeProjetos(void);
void Teste_criaListaDeProfessores(void);
void Teste_criaListaDeAlunos(void);
void Teste_criaListaDeAutores(void);
void Teste_criaListaDeEventos(void);
void Teste_criaListaDePeriodicos(void);
void Teste_insereEmListaDeProjetos(void);
void Teste_insereEmListaDeProfessores(void);
void Teste_confereSeProfessorJaEstaNaLista(void);
void Teste_insereEmListaDeAlunos(void);
void Teste_insereEmListaDeAutores(void);
void Teste_insereEmListaDeEventos(void);
void Teste_insereEmListaDePeriodicos(void);
void Teste_insereEmListaDeProjetos_NULL(void);
void Teste_insereEmListaDeProfessores_NULL(void);
void Teste_confereSeProfessorJaEstaNaLista_NAO(void);
void Teste_confereSeProfessorJaEstaNaLista_NULL(void);
void Teste_confereSeProfessorJaEstaNaLista_3(void);
void Teste_insereEmListaDeAlunos_NULL(void);
void Teste_insereEmListaDeAutores_NULL(void);
void Teste_insereEmListaDeEventos_NULL(void);
void Teste_insereEmListaDePeriodicos_NULL(void);

void Teste_criaListaDeProjetos(void){
	listaDeProjetos* L = criaListaDeProjetos();

	CU_ASSERT_EQUAL(L, NULL);
	return;
}

void Teste_criaListaDeProfessores(void){
	listaDeProfessores* L = criaListaDeProfessores();

	CU_ASSERT_EQUAL(L, NULL);
	return;
}
void Teste_criaListaDeAlunos(void){
	listaDeAlunos* L = criaListaDeAlunos();

	CU_ASSERT_EQUAL(L, NULL);
	return;
}

void Teste_criaListaDeAutores(void){
	listaDeAutores* L = criaListaDeAutores();

	CU_ASSERT_EQUAL(L, NULL);
	return;
}

void Teste_criaListaDeEventos(void){
	listaDeEventos* L = criaListaDeEventos();

	CU_ASSERT_EQUAL(L, NULL);
	return;
}

void Teste_criaListaDePeriodicos(void){
	listaDePeriodicos* L = criaListaDePeriodicos();

	CU_ASSERT_EQUAL(L, NULL);
	return;
}

void Teste_insereEmListaDeProjetos(void){
	listaDeProjetos* L = criaListaDeProjetos();
	L = insereEmListaDeProjetos(L, "nome", 2015, 1, 2016, "sit", "nat", "desc", "resp", "integrante1", "inegrante2");

	CU_ASSERT_EQUAL(L->proximoProjeto, NULL);
	CU_ASSERT_EQUAL(L->nomeProjeto, "nome");
	CU_ASSERT_EQUAL(L->anoInicio, 2015);
	CU_ASSERT_EQUAL(L->anoFim, 2016);
	CU_ASSERT_EQUAL(L->mesFim, 1);
	CU_ASSERT_EQUAL(L->situacao, "sit");
	CU_ASSERT_EQUAL(L->natureza, "nat");
	CU_ASSERT_EQUAL(L->descricao, "desc");
	CU_ASSERT_EQUAL(L->responsavel, "resp");
	CU_ASSERT_EQUAL(L->integrante1, "integrante1");
	CU_ASSERT_EQUAL(L->integrante2, "integrante2");

	return;
}

void Teste_insereEmListaDeProjetos_NULL(void){
	listaDeProjetos* L = criaListaDeProjetos();
	L = insereEmListaDeProjetos(L, NULL, 2015, 1, 2016, NULL, NULL, NULL, NULL, NULL, NULL);

	CU_ASSERT_EQUAL(L->proximoProjeto, NULL);
	CU_ASSERT_EQUAL(L->nomeProjeto, NULL);
	CU_ASSERT_EQUAL(L->anoInicio, 2015);
	CU_ASSERT_EQUAL(L->anoFim, 2016);
	CU_ASSERT_EQUAL(L->mesFim, 1);
	CU_ASSERT_EQUAL(L->situacao, NULL);
	CU_ASSERT_EQUAL(L->natureza, NULL);
	CU_ASSERT_EQUAL(L->descricao, NULL);
	CU_ASSERT_EQUAL(L->responsavel, NULL);
	CU_ASSERT_EQUAL(L->integrante1, NULL);
	CU_ASSERT_EQUAL(L->integrante2, NULL);

	return;
}

void Teste_insereEmListaDeProfessores(void){
	listaDeProfessores* L = criaListaDeProfessores();
	L = insereEmListaDeProfessores(L, "nome", "nomecit");

	CU_ASSERT_EQUAL(L->nomeProfessor, "nome");
	CU_ASSERT_EQUAL(L->nomeParaCitacao, "nomecit");
	CU_ASSERT_EQUAL(L->numDeProfessores, 1);

	return;
}

void Teste_insereEmListaDeProfessores_NULL(void){
	listaDeProfessores* L = criaListaDeProfessores();
	L = insereEmListaDeProfessores(L, NULL, NULL);

	CU_ASSERT_EQUAL(L->nomeProfessor, NULL);
	CU_ASSERT_EQUAL(L->nomeParaCitacao, NULL);
	CU_ASSERT_EQUAL(L->numDeProfessores, 0);

	return;
}

void Teste_confereSeProfessorJaEstaNaLista(void){
	listaDeProfessores* L = criaListaDeProfessores();
	L = insereEmListaDeProfessores(L, "nome", "nomecit");

	CU_ASSERT_TRUE(confereSeProfessorJaEstaNaLista(L, "nome"));

	return;
}

void Teste_confereSeProfessorJaEstaNaLista_3(void){
	listaDeProfessores* L = criaListaDeProfessores();
	L = insereEmListaDeProfessores(L, "nome3", "nomecit3");
	L = insereEmListaDeProfessores(L, "nome1", "nomecit1");
	L = insereEmListaDeProfessores(L, "nome2", "nomecit2");

	CU_ASSERT_TRUE(confereSeProfessorJaEstaNaLista(L, "nome1"));
	CU_ASSERT_TRUE(confereSeProfessorJaEstaNaLista(L, "nome2"));
	CU_ASSERT_TRUE(confereSeProfessorJaEstaNaLista(L, "nome3"));

	return;
}

void Teste_confereSeProfessorJaEstaNaLista_NAO(void){
	listaDeProfessores* L = criaListaDeProfessores();
	L = insereEmListaDeProfessores(L, "nome", "nomecit");

	CU_ASSERT_FALSE(confereSeProfessorJaEstaNaLista(L, "bob"));
	
	return;
}

void Teste_confereSeProfessorJaEstaNaLista_NULL(void){
	listaDeProfessores* L = criaListaDeProfessores();
	L = insereEmListaDeProfessores(L, NULL, NULL);

	CU_ASSERT_FALSE(confereSeProfessorJaEstaNaLista(L, "bob"));
	
	return;
}

void Teste_insereEmListaDeAlunos(void){
	listaDeAlunos* L = criaListaDeAlunos();
	L = insereEmListaDeAlunos(L, "aluno1", "14/1234567", 1);

	CU_ASSERT_EQUAL(L->nomeAluno, "aluno1");
	CU_ASSERT_EQUAL(L->matricula, "14/1234567");
	CU_ASSERT_EQUAL(L->tipo; 1);

	return;
}

void Teste_insereEmListaDeAlunos_NULL(void){
	listaDeAlunos* L = criaListaDeAlunos();
	L = insereEmListaDeAlunos(L, NULL, NULL, 1);

	CU_ASSERT_EQUAL(L->nomeAluno, NULL);
	CU_ASSERT_EQUAL(L->matricula, NULL;
	CU_ASSERT_EQUAL(L->tipo; 1);

	return;
}

void Teste_insereEmListaDeAutores(void){
	listaDeAutores* L = criaListaDeAutores();
	L = insereEmListaDeAutores(L, "nomeAutor", "nomeParaCitacao", 1);

	CU_ASSERT_EQUAL(L->nomeAutor, "nomeAutor");
	CU_ASSERT_EQUAL(L->nomeParaCitacao, "nomeParaCitacao");
	CU_ASSERT_EQUAL(L->ordemDeAutoria, 1);
	CU_ASSERT_EQUAL(L->proximoAutor, NULL);
	
	return;
}

void Teste_insereEmListaDeAutores_NULL(void){
	listaDeAutores* L = criaListaDeAutores();
	L = insereEmListaDeAutores(L, NULL, NULL, 1);

	CU_ASSERT_EQUAL(L->nomeAutor, NULL);
	CU_ASSERT_EQUAL(L->nomeParaCitacao, NULL);
	CU_ASSERT_EQUAL(L->ordemDeAutoria, 1);
	
	return;
}

void Teste_insereEmListaDeEventos(void){
	listaDeEventos* L = criaListaDeEventos();
	listaDeAutores* LA = criaListaDeAutores();
	LA = insereEmListaDeAutores(LA, "nomeAutor", "nomeParaCitacao", 1);

	L = insereEmListaDeEventos(L, LA, "prof", "cit", "nat", "titulo", "pais", "idi", "nomeE", "ano", "proc", "vol", "p1", "pf");

	CU_ASSERT_EQUAL(L->proximoEvento, NULL);
	CU_ASSERT_EQUAL(L->nomeProfessor, "prof");
	CU_ASSERT_EQUAL(L->nomeParaCitacao_Professor, "cit");
	CU_ASSERT_EQUAL(L->natureza, "nat");
	CU_ASSERT_EQUAL(L->titulo, "titulo");
	CU_ASSERT_EQUAL(L->pais, "pais");
	CU_ASSERT_EQUAL(L->idioma, "idi");
	CU_ASSERT_EQUAL(L->nomeEvento, "nomeE");
	CU_ASSERT_EQUAL(L->ano, "ano");
	CU_ASSERT_EQUAL(L->proceedings, "proc");
	CU_ASSERT_EQUAL(L->volume, "vol");
	CU_ASSERT_EQUAL(L->paginaInicial, "p1");
	CU_ASSERT_EQUAL(L->paginaFinal, "pf");
	CU_ASSERT_EQUAL(L->autores, LA);

	return;
}

void Teste_insereEmListaDeEventos_NULL(void){
	listaDeEventos* L = criaListaDeEventos();
	listaDeAutores* LA = criaListaDeAutores();
	LA = insereEmListaDeAutores(LA, NULL, NULL, 1);

	L = insereEmListaDeEventos(L, LA, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

	CU_ASSERT_EQUAL(L->proximoEvento, NULL);
	CU_ASSERT_EQUAL(L->nomeProfessor, NULL);
	CU_ASSERT_EQUAL(L->nomeParaCitacao_Professor, NULL);
	CU_ASSERT_EQUAL(L->natureza, NULL);
	CU_ASSERT_EQUAL(L->titulo, NULL);
	CU_ASSERT_EQUAL(L->pais, NULL);
	CU_ASSERT_EQUAL(L->idioma, NULL);
	CU_ASSERT_EQUAL(L->nomeEvento, NULL);
	CU_ASSERT_EQUAL(L->ano, NULL);
	CU_ASSERT_EQUAL(L->proceedings, NULL);
	CU_ASSERT_EQUAL(L->volume, NULL);
	CU_ASSERT_EQUAL(L->paginaInicial, NULL);
	CU_ASSERT_EQUAL(L->paginaFinal, NULL);
	CU_ASSERT_EQUAL(L->autores, LA);

	return;
}

void Teste_insereEmListaDePeriodicos(void){
	listaDePeriodicos* L = criaListaDePeriodicos();
	listaDeAutores* LA = criaListaDeAutores();
	LA = insereEmListaDeAutores(LA, "nomeAutor", "nomeParaCitacao", 1);

	L = insereEmListaDePeriodicos(L, LA, "nome", "cit", "nat", "tituloA", "tituloP", "idi", "ano", "serie", "vol", "p1", "pf");

	CU_ASSERT_EQUAL(L->proximoPeriodico, NULL);
	CU_ASSERT_EQUAL(L->nomeProfessor, "nome");
	CU_ASSERT_EQUAL(L->nomeParaCitacao_Professor, "cit");
	CU_ASSERT_EQUAL(L->natureza, "nat");
	CU_ASSERT_EQUAL(L->tituloArtigo, "tituloA");
	CU_ASSERT_EQUAL(L->tituloPeriodico, "tituloP");
	CU_ASSERT_EQUAL(L->idioma, "idi");
	CU_ASSERT_EQUAL(L->ano, "ano");
	CU_ASSERT_EQUAL(L->serie, "serie");
	CU_ASSERT_EQUAL(L->volume, "vol");
	CU_ASSERT_EQUAL(L->paginaInicial, "p1");
	CU_ASSERT_EQUAL(L->paginaFinal, "pf");
	CU_ASSERT_EQUAL(L->autores, LA);

	return;
}

void Teste_insereEmListaDePeriodicos(void){
	listaDePeriodicos* L = criaListaDePeriodicos();
	listaDeAutores* LA = criaListaDeAutores();
	LA = insereEmListaDeAutores(LA, NULL, NULL, 1);

	L = insereEmListaDePeriodicos(L, LA,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

	CU_ASSERT_EQUAL(L->proximoPeriodico, NULL);
	CU_ASSERT_EQUAL(L->nomeProfessor, NULL);
	CU_ASSERT_EQUAL(L->nomeParaCitacao_Professor, NULL);
	CU_ASSERT_EQUAL(L->natureza, NULL);
	CU_ASSERT_EQUAL(L->tituloArtigo, NULL);
	CU_ASSERT_EQUAL(L->tituloPeriodico, NULL);
	CU_ASSERT_EQUAL(L->idioma, NULL);
	CU_ASSERT_EQUAL(L->ano, NULL);
	CU_ASSERT_EQUAL(L->serie, NULL);
	CU_ASSERT_EQUAL(L->volume, NULL);
	CU_ASSERT_EQUAL(L->paginaInicial, NULL);
	CU_ASSERT_EQUAL(L->paginaFinal, NULL);
	CU_ASSERT_EQUAL(L->autores, LA);

	return;
}

void Add_Suite_Testes(void){
	CU_pSuite pSuite = NULL;
	pSuite = CU_add_suite( "Teste_Listas", NULL, NULL);

	CU_ADD_TEST(pSuite, Teste_Grafo_Vazio);
	CU_ADD_TEST(pSuite, Teste_criaListaDeProjetos);
	CU_ADD_TEST(pSuite, Teste_criaListaDeProfessores);
	CU_ADD_TEST(pSuite, Teste_criaListaDeAlunos);
	CU_ADD_TEST(pSuite, Teste_criaListaDeAutores);
	CU_ADD_TEST(pSuite, Teste_criaListaDeEventos);
	CU_ADD_TEST(pSuite, Teste_criaListaDePeriodicos);
	CU_ADD_TEST(pSuite, Teste_insereEmListaDeProjetos);
	CU_ADD_TEST(pSuite, Teste_insereEmListaDeProfessores);
	CU_ADD_TEST(pSuite, Teste_confereSeProfessorJaEstaNaLista);
	CU_ADD_TEST(pSuite, Teste_insereEmListaDeAlunos);
	CU_ADD_TEST(pSuite, Teste_insereEmListaDeAutores);
	CU_ADD_TEST(pSuite, Teste_insereEmListaDeEventos);
	CU_ADD_TEST(pSuite, Teste_insereEmListaDePeriodicos);
	CU_ADD_TEST(pSuite, Teste_insereEmListaDeProjetos_NULL);
	CU_ADD_TEST(pSuite, Teste_insereEmListaDeProfessores_NULL);
	CU_ADD_TEST(pSuite, Teste_confereSeProfessorJaEstaNaLista_NULL);
	CU_ADD_TEST(pSuite, Teste_confereSeProfessorJaEstaNaLista_NAO);
	CU_ADD_TEST(pSuite, Teste_confereSeProfessorJaEstaNaLista_3);
	CU_ADD_TEST(pSuite, Teste_insereEmListaDeAlunos_NULL);
	CU_ADD_TEST(pSuite, Teste_insereEmListaDeAutores_NULL);
	CU_ADD_TEST(pSuite, Teste_insereEmListaDeEventos_NULL);
	CU_ADD_TEST(pSuite, Teste_insereEmListaDePeriodicos_NULL);

	return;
}

int main(void){
	
	if (CUE_SUCCESS != CU_initialize_registry()){
		return CU_get_error();
	}
   
   Add_Suite_Testes();
   CU_basic_set_mode(CU_BRM_VERBOSE);
   
   CU_basic_run_tests();
   CU_cleanup_registry();

	return CU_get_error();
}