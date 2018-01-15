#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulo2.h"
#include "listas.h"


listadeprojetosfinal*INSERE_NA_LISTADEPROJETOSFINAL(listadeprojetosfinal*lista1,listaDeProjetos*lista2, listaDeAlunos*lista3,listaDeProfessores*lista4){ /*lista2=lista ja existente proveniente do modulo 1, lista2= lista de alunos ja existente, lista1=lista a ser criada*/
int conta,conta2,conta3,conta4;


/**************************/
		if(lista1==NULL){
			
			lista1=(listadeprojetosfinal*)malloc(sizeof(listadeprojetosfinal));
			lista1->prox=NULL;
		
			lista1->discentes=(Listadiscentes*)malloc(sizeof(Listadiscentes));
			lista1->discentes->prox=NULL;		
			
			lista1->docentes=(Listadocentes*)malloc(sizeof(Listadocentes));
			lista1->docentes->prox=NULL;
			
			lista1->discentesexternos=(Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
			lista1->discentesexternos->prox=NULL;
			
				
		}

/************************/

		listadeprojetosfinal*aux=(listadeprojetosfinal*)malloc(sizeof(listadeprojetosfinal));
		aux->prox=NULL;		
		aux->discentes=(Listadiscentes*)malloc(sizeof(Listadiscentes));
		aux->docentes=(Listadocentes*)malloc(sizeof(Listadocentes));
		aux->discentesexternos=(Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
		aux->discentes->prox=NULL;		
		aux->docentes->prox=NULL;
		aux->discentesexternos->prox=NULL;
		lista1->anodeinicio=lista2->anoInicio;
		lista1->anofim=lista2->anoFim;
		strcpy(lista1->situacao,lista2->situacao);
		strcpy(lista1->descricao, lista2->descricao);
		strcpy(lista1->natureza, lista2->natureza);
		strcpy(lista1->nomeprojeto,lista2->nomeProjeto);
		strcpy(lista1->responsavel, lista2->responsavel);
		listaDeAlunos*temp1;
		listaDeProfessores*temp10;					
		temp1=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
		temp10=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));					
		temp1=lista3;
		temp10=lista4;
		conta=0,conta3=0;







			while(temp10->proximoProfessor!=NULL){/*variavel temp que percorre a lista de professores comparando o nome da lista de professores com o nome da lista de integrantes da lista 2*/
				if(strcmp(lista2->integrante1,temp10->nomeProfessor)==0){/*se o nome for igual, ele o salva na lista1-> nomedocentes*/					
					strcpy(lista1->docentes->nomedocente, lista2->integrante1);												
					conta3=1;
				}/*terceiro if*/
					
				temp10=temp10->proximoProfessor;						   										
			}/*while da verificacao do professor*/ 




			while(temp1->proximoAluno!=NULL){/*variavel temp que percorre a lista de alunos comparando o nome da lista de alunos com o nome da lista de integrantes da lista 2*/
				if(strcmp(lista2->integrante1,temp1->nomeAluno)==0){/*se o nome for igual, ele o salva na lista1-> nomediscente*/
					strcpy(lista1->discentes->nomediscente, lista2->integrante1);															
					conta=1;	
				}/*terceiro if*/
				temp1=temp1->proximoAluno;						   										
			}/*segundo while*/



			
			if((conta==0)&&(conta3==0)){/*se for 0 eh pq o nome nao foi encontrado na lista de alunos e nem na de professores, entao eh um aluno externo*/										
				strcpy(lista1->discentesexternos->nomediscenteexterno, lista2->integrante1);																								
			}/*quarto if*/	




				

		listaDeAlunos*temp12;
		listaDeProfessores*temp100;					
		temp12=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
		temp100=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));					
		temp12=lista3;
		temp100=lista4;
		conta2=0,conta4=0;



			while(temp100->proximoProfessor!=NULL){/*variavel temp que percorre a lista de professores comparando o nome da lista de professores com o nome da lista de integrantes da lista 2*/
				if(strcmp(lista2->integrante2,temp100->nomeProfessor)==0){/*se o nome for igual, ele o salva na lista1-> nomedocentes*/
					Listadocentes*nodo200;
					nodo200=(Listadocentes*)malloc(sizeof(Listadocentes));
					strcpy(nodo200->nomedocente, lista2->integrante2);								
					nodo200->prox=lista1->docentes;
					lista1->docentes=nodo200;
					conta4=1;
						
				}/*terceiro if*/
				temp100=temp100->proximoProfessor;						   										
			}/*while da verificacao do professor*/ 





			while(temp12->proximoAluno!=NULL){/*variavel temp que percorre a lista de alunos comparando o nome da lista de alunos com o nome da lista de integrantes da lista 2*/
				if(strcmp(lista2->integrante2,temp12->nomeAluno)==0){/*se o nome for igual, ele o salva na lista1-> nomediscente*/
					Listadiscentes*nodo20;
					nodo20=(Listadiscentes*)malloc(sizeof(Listadiscentes));
					strcpy(nodo20->nomediscente, lista2->integrante2);								
					nodo20->prox=lista1->discentes;
					lista1->discentes=nodo20;							
					conta2=1;	
				}/*terceiro if*/
				temp12=temp12->proximoAluno;						   										
			}/*segundo while*/






			
			if((conta2==0)&&(conta4==0)){/*se for 0 eh pq o nome nao foi encontrado na lista de alunos e nem de professores, entao eh um aluno externo*/				
				Listadiscentesexternos*nodo30;
				nodo30=(Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));								
				strcpy(nodo30->nomediscenteexterno, lista2->integrante2);											
				nodo30->prox=lista1->discentesexternos;
				lista1->discentesexternos=nodo30;													
			}/*quarto if*/		



			
				aux->prox=lista1;
				lista1=aux;
				
			return lista1;
}
