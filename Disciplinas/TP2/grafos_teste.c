#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "grafos.h"


void Add_Suite_Testes(void);
void Teste_Grafo_Vazio(void);
void Teste_Grafo_Nao_Vazio(void);
void Teste_Quantidade_0_Publicacoes(void);
void Teste_Quantidade_Publicacoes(void);
void Teste_Insere_Nova_Publicacao(void);
void Teste_Remove_Publicacao(void);
void Teste_ListaPeriodicos_Grafo(void);
void Teste_ListaEventos_Grafo(void);
void Teste_ListaProjetos_Grafo(void);

void Teste_Grafo_Vazio(void){
   Grafo* G = GRF_Criar_Grafo();

   CU_ASSERT_TRUE(G);
   GRF_Liberar_Grafo(G);

   return;
}

void Teste_Grafo_Nao_Vazio(void){
   Grafo* G = GRF_Criar_Grafo();

   CU_ASSERT_FALSE(G);
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
   G = GRF_Insere_Nova_Publicacao(G, "pub");

   CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 1);
   GRF_Liberar_Grafo(G);

   return;
}

void Teste_Remove_Publicacao(void){
   Grafo* G = GRF_Criar_Grafo();
   G = GRF_Insere_Nova_Publicacao(G, "pub");
   G = GRF_Remove_Publicacao(G, "pub");
   CU_ASSERT_EQUAL(GRF_Quantidade_Publicacoes(G), 0);
   GRF_Liberar_Grafo(G);

   return;
}

void Add_Suite_Testes(void){
   CU_pSuite pSuite = NULL;

   pSuite = CU_add_suite( "Teste_Grafos", NULL, NULL);

   CU_ADD_TEST(pSuite, Teste_Grafo_Vazio);
   CU_ADD_TEST(pSuite, Teste_Quantidade_0_Publicacoes);
   CU_ADD_TEST(pSuite, Teste_Quantidade_Publicacoes);
   CU_ADD_TEST(pSuite, Teste_Insere_Nova_Publicacao);
   CU_ADD_TEST(pSuite, Teste_Remove_Publicacao);

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