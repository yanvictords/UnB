/*!
* \file grafos_inst.c
* \brief Modulo controlador de teste de grafos.
*
* \author Icaro Marcelino Miranda.
* \since 05/07/2015.
* \version 1.0.
*
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "grafos.c"

void Add_Suite_Testes(void);
void Teste_Grafo_Vazio(void);
void Teste_Grafo_Nao_Vazio(void);
void Teste_Quantidade_0_Publicacoes(void);
void Teste_Quantidade_Publicacoes(void);
void Teste_Insere_Nova_Publicacao_0(void);
void Teste_Insere_Nova_Publicacao_1(void);
void Teste_Insere_Nova_Publicacao_3(void);
void Teste_Remove_Publicacao_0(void);
void Teste_Remove_Publicacao_1(void);
void Teste_Remove_Publicacao_3(void);
void Teste_Insere_Autor_0(void);
void Teste_Insere_Autor_1(void);
void Teste_Insere_Autor_3(void);
void Teste_ListaPeriodicos_Grafo_0(void);
void Teste_ListaPeriodicos_Grafo(void);
void Teste_ListaEventos_Grafo_0(void);
void Teste_ListaEventos_Grafo(void);
void Teste_ListaProjetos_Grafo_0(void);
void Teste_ListaProjetos_Grafo(void);
void Teste_Lista_Vazia(void);
void Teste_Lista_Nao_Vazia(void);
void Teste_Buscar_Lista_Elemento(void);
void Teste_Buscar_Lista_Nao_Elemento(void);
void Teste_Criar_Lista(void);
void Teste_Insere_Inicio_Lista(void);
void Teste_Insere_Fim_Lista_1(void);
void Teste_Insere_Fim_Lista_3(void);
void Teste_Car(void);
void Teste_Insere_Listas_participantes_Grafo_Vazio(void);
void Teste_Insere_Listas_participantes_Lista_Docentes_Vazia(void);
void Teste_Insere_Listas_participantes_Lista_Discentes_Vazia(void);
void Teste_Insere_Listas_participantes_Lista_DiscentesExt_Vazia(void);
void Teste_Insere_Listas_participantes_Titulo_Vazio(void);
void Teste_Insere_Listas_participantes(void);
void Teste_Insere_Listas_participantes_3(void);

void Teste_Grafo_Vazio(void){
   Grafo* G = GRF_Criar_Grafo();

   CU_ASSERT_TRUE(GRF_Grafo_Vazio(G));
   GRF_Liberar_Grafo(G);

   return;
}

void Teste_Grafo_Nao_Vazio(void){
   Grafo* G = GRF_Criar_Grafo();
   G = GRF_Insere_Nova_Publicacao(G, "pub", 1);

   CU_ASSERT_FALSE(GRF_Grafo_Vazio(G));
   GRF_Liberar_Grafo(G);
   return;
}

void Teste_Quantidade_0_Publicacoes(void){
   Grafo* G = GRF_Criar_Grafo();

   CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 0);
   GRF_Liberar_Grafo(G);

   return;
}

void Teste_Quantidade_Publicacoes(void){
   Grafo* G = GRF_Criar_Grafo();
   G = GRF_Insere_Nova_Publicacao(G, "pub", 1);

   CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 1);
   CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub"));
   GRF_Liberar_Grafo(G);

   return;
}

void Teste_Insere_Nova_Publicacao_0(void){
   Grafo* G = GRF_Criar_Grafo();

   CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 0);
   GRF_Liberar_Grafo(G);

   return;
}

void Teste_Insere_Nova_Publicacao_1(void){
   Grafo* G = GRF_Criar_Grafo();
   	G = GRF_Insere_Nova_Publicacao(G, "pub1", 1);

   CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 1);
   CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub1"));

   GRF_Liberar_Grafo(G);

   return;
}

void Teste_Insere_Nova_Publicacao_3(void){
   Grafo* G = GRF_Criar_Grafo();
   		G = GRF_Insere_Nova_Publicacao(G, "pub1", 1);
   		G = GRF_Insere_Nova_Publicacao(G, "pub2", 1);
   		G = GRF_Insere_Nova_Publicacao(G, "pub3", 1);

   CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 3);
   CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub1"));
   CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub2"));
   CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub3"));

   GRF_Liberar_Grafo(G);

   return;
}

void Teste_Remove_Publicacao_0(void){
   Grafo* G = GRF_Criar_Grafo();
   	G = GRF_Remove_Publicacao(G, "pub");

   CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 0);
   CU_ASSERT_FALSE(GRF_Verificar_Publicacao(G, "pub"));
   GRF_Liberar_Grafo(G);

   return;
}

void Teste_Remove_Publicacao_1(void){
   Grafo* G = GRF_Criar_Grafo();

   		G = GRF_Insere_Nova_Publicacao(G, "pub1", 1);
		CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub1"));

 		G = GRF_Remove_Publicacao(G, "pub1");
		CU_ASSERT_FALSE(GRF_Verificar_Publicacao(G, "pub1"));

   CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 0);
   GRF_Liberar_Grafo(G);

   return;
}

void Teste_Remove_Publicacao_3(void){
   Grafo* G = GRF_Criar_Grafo();
   		G = GRF_Insere_Nova_Publicacao(G, "pub1", 1);
   		G = GRF_Insere_Nova_Publicacao(G, "pub2", 1);
   		G = GRF_Insere_Nova_Publicacao(G, "pub3", 1);

		CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub1"));
		CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub2"));
		CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub3"));

   		G = GRF_Remove_Publicacao(G, "pub1");
   		G = GRF_Remove_Publicacao(G, "pub2");
   		G = GRF_Remove_Publicacao(G, "pub3");

		CU_ASSERT_FALSE(GRF_Verificar_Publicacao(G, "pub1"));
		CU_ASSERT_FALSE(GRF_Verificar_Publicacao(G, "pub2"));
		CU_ASSERT_FALSE(GRF_Verificar_Publicacao(G, "pub3"));

   CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 0);
   GRF_Liberar_Grafo(G);

   return;
}

void Teste_Insere_Autor_0(void){
	Grafo* G = GRF_Criar_Grafo();

	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 0);
	GRF_Liberar_Grafo(G);

	return;
}

void Teste_Insere_Autor_1(void){
	Grafo* G = GRF_Criar_Grafo();
		G = GRF_Insere_Nova_Publicacao(G, "pub,", 1);
		G = GRF_Insere_Autor(G, "autor1", "pub");

   	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "autor1"));
	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 1);
	GRF_Liberar_Grafo(G);

	return;
}

void Teste_Insere_Autor_3(void){
	Grafo* G = GRF_Criar_Grafo();
		G = GRF_Insere_Nova_Publicacao(G, "pub", 1);
		G = GRF_Insere_Autor(G, "autor1", "pub");		
		G = GRF_Insere_Nova_Publicacao(G, "pub1", 1);
		G = GRF_Insere_Autor(G, "autor2", "pub1");		
		G = GRF_Insere_Nova_Publicacao(G, "pub2", 1);
		G = GRF_Insere_Autor(G, "autor3", "pub2");

   	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "autor1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "autor2"));
   	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub2"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "autor3"));
	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 3);
	GRF_Liberar_Grafo(G);

	return;
}

void Teste_ListaPeriodicos_Grafo_0(void){
	listaDePeriodicosFinal* LP = NULL;
	Grafo* G = GRF_ListaPeriodicos_Grafo(LP);

	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 0);
	GRF_Liberar_Grafo(G);

	return;
}

void Teste_ListaPeriodicos_Grafo(void){
	listaDePeriodicosFinal* LP = (listaDePeriodicosFinal*)malloc(sizeof(listaDePeriodicosFinal));
	Listadiscentesexternos* LDiE = (Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
	Listadocentes* 	LDo = (Listadocentes*)malloc(sizeof(Listadocentes));
	Listadiscentes*	LDi = (Listadiscentes*)malloc(sizeof(Listadiscentes));

	strcpy(LP->nomeProfessor, "Prof1");
	strcpy(LP->tituloPeriodico, "Titulo1");
	LP->prox = NULL;

	strcpy(LDo->nomedocente, "docente1");
	LDo->prox = NULL;
	strcpy(LDi->nomediscente, "discente1");
	LDi->prox = NULL;
	strcpy(LDiE->nomediscenteexterno, "discenteExt1");
	LDiE->prox = NULL;

	LP->docentes = LDo;
	LP->discentes = LDi;
	LP->discentesexternos = LDiE;

	Grafo* G = GRF_ListaPeriodicos_Grafo(LP);
   	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "Titulo1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "Prof1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "docente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discenteExt1"));
	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 1);

	GRF_Liberar_Grafo(G);
	free(LDi);	free(LDiE);
	free(LDo);	free(LP);

	return;
}

void Teste_ListaEventos_Grafo_0(void){
	listaDeEventosFinal* LE = NULL;
	Grafo* G = GRF_ListaEventos_Grafo(LE);

	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 0);
	GRF_Liberar_Grafo(G);

	return;
}

void Teste_ListaEventos_Grafo(void){
	listaDeEventosFinal* LE = (listaDeEventosFinal*)malloc(sizeof(listaDeEventosFinal));
	Listadiscentesexternos* LDiE = (Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
	Listadocentes* 	LDo = (Listadocentes*)malloc(sizeof(Listadocentes));
	Listadiscentes*	LDi = (Listadiscentes*)malloc(sizeof(Listadiscentes));

	strcpy(LE->nomeProfessor, "Prof1");
	strcpy(LE->titulo, "Titulo1");
	LE->prox = NULL;

	strcpy(LDo->nomedocente, "docente1");
	LDo->prox = NULL;
	strcpy(LDi->nomediscente, "discente1");
	LDi->prox = NULL;
	strcpy(LDiE->nomediscenteexterno, "discenteExt1");
	LDiE->prox = NULL;

	LE->docentes = LDo;
	LE->discentes = LDi;
	LE->discentesexternos = LDiE;

	Grafo* G = GRF_ListaEventos_Grafo(LE);

   	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "Titulo1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "Prof1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "docente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discenteExt1"));
	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 1);

	GRF_Liberar_Grafo(G);
	free(LDi);	free(LDiE);
	free(LDo);	free(LE);

	return;
}

void Teste_ListaProjetos_Grafo_0(void){
	listadeprojetosfinal* LP = NULL;
	Grafo* G = GRF_ListaProjetos_Grafo(LP);

	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 0);
	GRF_Liberar_Grafo(G);

	return;
}

void Teste_ListaProjetos_Grafo(void){
	listadeprojetosfinal* LP = (listadeprojetosfinal*)malloc(sizeof(listadeprojetosfinal));
	Listadiscentesexternos* LDiE = (Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
	Listadocentes* 	LDo = (Listadocentes*)malloc(sizeof(Listadocentes));
	Listadiscentes*	LDi = (Listadiscentes*)malloc(sizeof(Listadiscentes));

	strcpy(LP->responsavel, "Prof1");
	strcpy(LP->nomeprojeto, "Titulo1");
	LP->prox = NULL;

	strcpy(LDo->nomedocente, "docente1");
	LDo->prox = NULL;
	strcpy(LDi->nomediscente, "discente1");
	LDi->prox = NULL;
	strcpy(LDiE->nomediscenteexterno, "discenteExt1");
	LDiE->prox = NULL;

	LP->docentes = LDo;
	LP->discentes = LDi;
	LP->discentesexternos = LDiE;

	Grafo* G = GRF_ListaProjetos_Grafo(LP);

   	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "Titulo1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "Prof1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "docente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discenteExt1"));
	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 1);

	GRF_Liberar_Grafo(G);
	free(LDi);	free(LDiE);
	free(LDo);	free(LP);

	return;
}

void Teste_Lista_Vazia(void){
	PLista L = GRF_Criar_Lista();

	CU_ASSERT_TRUE(GRF_Lista_Vazia(L));

	return;
}

void Teste_Lista_Nao_Vazia(void){
	PLista L = GRF_Criar_Lista();
	L = GRF_Insere_Inicio_Lista(L, "Nome");

	CU_ASSERT_FALSE(GRF_Lista_Vazia(L));
	GRF_Liberar_Lista(L);

	return;
}

void Teste_Buscar_Lista_Elemento(void){
	PLista L = GRF_Criar_Lista();
	L = GRF_Insere_Inicio_Lista(L, "Nome");

	CU_ASSERT_TRUE(GRF_Buscar_Lista("Nome", L));
	GRF_Liberar_Lista(L);

	return;
}

void Teste_Buscar_Lista_Nao_Elemento(void){
	PLista L = GRF_Criar_Lista();
	L = GRF_Insere_Inicio_Lista(L, "NomeX");

	CU_ASSERT_FALSE(GRF_Buscar_Lista("Bob", L));
	GRF_Liberar_Lista(L);

	return;
}

void Teste_Criar_Lista(void){
	PLista L = GRF_Criar_Lista();

	CU_ASSERT_TRUE(GRF_Lista_Vazia(L));

	return;
}

void Teste_Insere_Inicio_Lista(void){
	PLista L = GRF_Criar_Lista();
	L = GRF_Insere_Inicio_Lista(L, "string");
	L = GRF_Insere_Inicio_Lista(L, "string1");

	CU_ASSERT_EQUAL(GRF_Car(L), "string1");
	GRF_Liberar_Lista(L);

	return;
}

void Teste_Insere_Fim_Lista_1(void){
	PLista L = GRF_Criar_Lista();
	L = GRF_Insere_Fim_Lista(L, "string1");

	CU_ASSERT_EQUAL(GRF_Car(L), "string1");
	GRF_Liberar_Lista(L);

	return;
}

void Teste_Insere_Fim_Lista_3(void){
	PLista L = GRF_Criar_Lista();
	L = GRF_Insere_Fim_Lista(L, "string1");
	L = GRF_Insere_Fim_Lista(L, "string2");
	L = GRF_Insere_Fim_Lista(L, "string3");

	CU_ASSERT_EQUAL(GRF_Car(L), "string1");
	GRF_Liberar_Lista(L);

	return;
}

void Teste_Car(void){
	PLista L = GRF_Criar_Lista();
	L = GRF_Insere_Inicio_Lista(L, "string");
	L = GRF_Insere_Inicio_Lista(L, "string1");

	CU_ASSERT_EQUAL(GRF_Car(L), "string1");
	GRF_Liberar_Lista(L);

	return;
}

void Teste_Insere_Listas_participantes(void){
	Grafo* G = GRF_Criar_Grafo();
	G = GRF_Insere_Nova_Publicacao(G, "pub", 1);

	Listadiscentesexternos* LDiE = (Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
	Listadocentes* 	LDo = (Listadocentes*)malloc(sizeof(Listadocentes));
	Listadiscentes*	LDi = (Listadiscentes*)malloc(sizeof(Listadiscentes));

	strcpy(LDo->nomedocente, "docente1");
	LDo->prox = NULL;
	strcpy(LDi->nomediscente, "discente1");
	LDi->prox = NULL;
	strcpy(LDiE->nomediscenteexterno, "discenteExt1");
	LDiE->prox = NULL;

	G = GRF_Insere_Listas_participantes(G, "pub", LDo, LDi, LDiE);

	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "docente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discenteExt1"));
	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 1);

	free(LDo);	free(LDi);	free(LDiE);
	GRF_Liberar_Grafo(G);

	return;
}

void Teste_Insere_Listas_participantes_3(void){
	Grafo* G = GRF_Criar_Grafo();
	G = GRF_Insere_Nova_Publicacao(G, "pub1", 1);
	G = GRF_Insere_Nova_Publicacao(G, "pub2", 1);
	G = GRF_Insere_Nova_Publicacao(G, "pub3", 1);

	Listadiscentesexternos* LDiE = (Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
	Listadocentes* 	LDo = (Listadocentes*)malloc(sizeof(Listadocentes));
	Listadiscentes*	LDi = (Listadiscentes*)malloc(sizeof(Listadiscentes));

	strcpy(LDo->nomedocente, "docente1");
	LDo->prox = NULL;
	strcpy(LDi->nomediscente, "discente1");
	LDi->prox = NULL;
	strcpy(LDiE->nomediscenteexterno, "discenteExt1");
	LDiE->prox = NULL;

	G = GRF_Insere_Listas_participantes(G, "pub1", LDo, LDi, LDiE);
	G = GRF_Insere_Listas_participantes(G, "pub2", LDo, LDi, LDiE);
	G = GRF_Insere_Listas_participantes(G, "pub3", LDo, LDi, LDiE);

	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub1"));
	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub2"));
	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub3"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "docente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discenteExt1"));
	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 3);

	free(LDo);	free(LDi);	free(LDiE);
	GRF_Liberar_Grafo(G);

	return;
}

void Teste_Insere_Listas_participantes_Grafo_Vazio(void){
	Grafo* G = GRF_Criar_Grafo();

	Listadiscentesexternos* LDiE = (Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
	Listadocentes* 	LDo = (Listadocentes*)malloc(sizeof(Listadocentes));
	Listadiscentes*	LDi = (Listadiscentes*)malloc(sizeof(Listadiscentes));

	strcpy(LDo->nomedocente, "docente1");
	LDo->prox = NULL;
	strcpy(LDi->nomediscente, "discente1");
	LDi->prox = NULL;
	strcpy(LDiE->nomediscenteexterno, "discenteExt1");
	LDiE->prox = NULL;

	G = GRF_Insere_Listas_participantes(G, "pub", LDo, LDi, LDiE);

	CU_ASSERT_FALSE(GRF_Verificar_Publicacao(G, "pub"));
   	CU_ASSERT_FALSE(GRF_Verificar_Autor(G, "docente1"));
   	CU_ASSERT_FALSE(GRF_Verificar_Autor(G, "discente1"));
   	CU_ASSERT_FALSE(GRF_Verificar_Autor(G, "discenteExt1"));
	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 0);

	free(LDo);	free(LDi);	free(LDiE);
	GRF_Liberar_Grafo(G);

	return;
}

void Teste_Insere_Listas_participantes_Titulo_Vazio(void){
	Grafo* G = GRF_Criar_Grafo();
	G = GRF_Insere_Nova_Publicacao(G, "pub", 1);
	string titulo = NULL;

	Listadiscentesexternos* LDiE = (Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
	Listadocentes* 	LDo = (Listadocentes*)malloc(sizeof(Listadocentes));
	Listadiscentes*	LDi = (Listadiscentes*)malloc(sizeof(Listadiscentes));

	strcpy(LDo->nomedocente, "docente1");
	LDo->prox = NULL;
	strcpy(LDi->nomediscente, "discente1");
	LDi->prox = NULL;
	strcpy(LDiE->nomediscenteexterno, "discenteExt1");
	LDiE->prox = NULL;

	G = GRF_Insere_Listas_participantes(G, titulo, LDo, LDi, LDiE);

	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub"));
   	CU_ASSERT_FALSE(GRF_Verificar_Autor(G, "docente1"));
   	CU_ASSERT_FALSE(GRF_Verificar_Autor(G, "discente1"));
   	CU_ASSERT_FALSE(GRF_Verificar_Autor(G, "discenteExt1"));
	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 1);

	free(LDo);	free(LDi);	free(LDiE);
	GRF_Liberar_Grafo(G);

	return;
}

void Teste_Insere_Listas_participantes_Lista_Docentes_Vazia(void){
	Grafo* G = GRF_Criar_Grafo();
	G = GRF_Insere_Nova_Publicacao(G, "pub", 1);
	string titulo = "pub";

	Listadiscentesexternos* LDiE = (Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
	Listadocentes* 	LDo = NULL;
	Listadiscentes*	LDi = (Listadiscentes*)malloc(sizeof(Listadiscentes));

	strcpy(LDi->nomediscente, "discente1");
	LDi->prox = NULL;
	strcpy(LDiE->nomediscenteexterno, "discenteExt1");
	LDiE->prox = NULL;

	G = GRF_Insere_Listas_participantes(G, titulo, LDo, LDi, LDiE);

	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub"));
   	CU_ASSERT_FALSE(GRF_Verificar_Autor(G, "docente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discenteExt1"));
	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 1);

	free(LDi);	free(LDiE);
	GRF_Liberar_Grafo(G);

	return;
}

void Teste_Insere_Listas_participantes_Lista_Discentes_Vazia(void){
	Grafo* G = GRF_Criar_Grafo();
	G = GRF_Insere_Nova_Publicacao(G, "pub", 1);
	string titulo = "pub";

	Listadiscentesexternos* LDiE = (Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
	Listadocentes* 	LDo = (Listadocentes*)malloc(sizeof(Listadocentes));
	Listadiscentes*	LDi = NULL;

	strcpy(LDo->nomedocente, "docente1");
	LDo->prox = NULL;
	strcpy(LDiE->nomediscenteexterno, "discenteExt1");
	LDiE->prox = NULL;

	G = GRF_Insere_Listas_participantes(G, titulo, LDo, LDi, LDiE);

	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub"));
   	CU_ASSERT_FALSE(GRF_Verificar_Autor(G, "discente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "docente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discenteExt1"));
	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 1);

	free(LDo);	free(LDiE);
	GRF_Liberar_Grafo(G);

	return;
}

void Teste_Insere_Listas_participantes_Lista_DiscentesExt_Vazia(void){
	Grafo* G = GRF_Criar_Grafo();
	G = GRF_Insere_Nova_Publicacao(G, "pub", 1);
	string titulo = "pub";

	Listadiscentesexternos* LDiE = NULL;
	Listadocentes* 	LDo = (Listadocentes*)malloc(sizeof(Listadocentes));
	Listadiscentes*	LDi = (Listadiscentes*)malloc(sizeof(Listadiscentes));

	strcpy(LDo->nomedocente, "docente1");
	LDo->prox = NULL;
	strcpy(LDi->nomediscente, "discente1");
	LDi->prox = NULL;

	G = GRF_Insere_Listas_participantes(G, titulo, LDo, LDi, LDiE);

	CU_ASSERT_TRUE(GRF_Verificar_Publicacao(G, "pub"));
   	CU_ASSERT_FALSE(GRF_Verificar_Autor(G, "discenteExt1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "discente1"));
   	CU_ASSERT_TRUE(GRF_Verificar_Autor(G, "docente1"));
	CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 1);

	free(LDo);	free(LDi);
	GRF_Liberar_Grafo(G);

	return;
}

void Add_Suite_Testes(void){
	CU_pSuite pSuite = NULL;

	pSuite = CU_add_suite( "Teste_Grafos", NULL, NULL);

	CU_ADD_TEST(pSuite, Teste_Grafo_Vazio);
	CU_ADD_TEST(pSuite, Teste_Grafo_Nao_Vazio);
	CU_ADD_TEST(pSuite, Teste_Quantidade_0_Publicacoes);
	CU_ADD_TEST(pSuite, Teste_Quantidade_Publicacoes);
	CU_ADD_TEST(pSuite, Teste_Insere_Nova_Publicacao_0);
	CU_ADD_TEST(pSuite, Teste_Insere_Nova_Publicacao_1);
	CU_ADD_TEST(pSuite, Teste_Insere_Nova_Publicacao_3);
	CU_ADD_TEST(pSuite, Teste_Remove_Publicacao_0);
	CU_ADD_TEST(pSuite, Teste_Remove_Publicacao_1);
   	CU_ADD_TEST(pSuite, Teste_Remove_Publicacao_3);
	CU_ADD_TEST(pSuite, Teste_Insere_Autor_0);
	CU_ADD_TEST(pSuite, Teste_Insere_Autor_1);
	CU_ADD_TEST(pSuite, Teste_Insere_Autor_3);
	CU_ADD_TEST(pSuite, Teste_ListaPeriodicos_Grafo_0);
	CU_ADD_TEST(pSuite, Teste_ListaPeriodicos_Grafo);
	CU_ADD_TEST(pSuite, Teste_ListaEventos_Grafo_0);
	CU_ADD_TEST(pSuite, Teste_ListaEventos_Grafo);
	CU_ADD_TEST(pSuite, Teste_ListaProjetos_Grafo_0);
	CU_ADD_TEST(pSuite, Teste_ListaProjetos_Grafo);
	CU_ADD_TEST(pSuite, Teste_Lista_Vazia);
	CU_ADD_TEST(pSuite, Teste_Lista_Nao_Vazia);
	CU_ADD_TEST(pSuite, Teste_Buscar_Lista_Elemento);
	CU_ADD_TEST(pSuite, Teste_Buscar_Lista_Nao_Elemento);
	CU_ADD_TEST(pSuite, Teste_Criar_Lista);
	CU_ADD_TEST(pSuite, Teste_Insere_Inicio_Lista);
	CU_ADD_TEST(pSuite, Teste_Insere_Fim_Lista_1);
	CU_ADD_TEST(pSuite, Teste_Insere_Fim_Lista_3);
	CU_ADD_TEST(pSuite, Teste_Car);
	CU_ADD_TEST(pSuite, Teste_Insere_Listas_participantes_Grafo_Vazio);
	CU_ADD_TEST(pSuite, Teste_Insere_Listas_participantes_Titulo_Vazio);
	CU_ADD_TEST(pSuite, Teste_Insere_Listas_participantes_Lista_Docentes_Vazia);
	CU_ADD_TEST(pSuite, Teste_Insere_Listas_participantes_Lista_Discentes_Vazia);
	CU_ADD_TEST(pSuite, Teste_Insere_Listas_participantes_Lista_DiscentesExt_Vazia);
	CU_ADD_TEST(pSuite, Teste_Insere_Listas_participantes);
	CU_ADD_TEST(pSuite, Teste_Insere_Listas_participantes_3);

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