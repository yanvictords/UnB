
/*!
* \file modulo2.c
* \brief Modulo de implementacao de listas.
* 
*\author Pedro Henrique Santos Gonzaga.
* \since 01/06/2015.
* \version 1.6.
*/
/*Matricula: 140030131*/

#ifndef STDIO_H_INCLUDED
	#define STDIO_H_INCLUDED
	#include <stdio.h>
#endif
#ifndef STDLIB_H_INCLUDED
	#define STDLIB_H_INCLUDED
	#include <stdlib.h>
#endif
#ifndef STRING_H_INCLUDED
	#define STRING_H_INCLUDED
	#include <string.h>
#endif
#ifndef LISTAS_H_INCLUDED
	#define LISTAS_H_INCLUDED
	#include "listas.h"
#endif
#ifndef MODULO2_H_INCLUDED
	#define MODULO2_H_INCLUDED
	#include "modulo2.h"
#endif

/*-----------------------------------------------------Projetos---------------------------------------------------------------------------------------_*/
/*Funcao que gera a lista de projetos com os participantes divididos em Docentes, Discentes e Discentes externos a partir das listas criadas pelo modulo1*/

/*!
* \brief Funcao que mainpula e cria a lista de projetos final
* \param lista1 lista de projetos final
* \param lista2 lista de projetos proveniente do modulo1
* \param lista3 lista de alunos
* \param lista4 lista de professores
* \return lista de projetos com autores separados por categoria academica
*/

listadeprojetosfinal*INSERE_NA_LISTADEPROJETOSFINAL(listadeprojetosfinal*lista1,listaDeProjetos*lista2, listaDeAlunos*lista3,listaDeProfessores*lista4){ /*lista2=lista ja existente proveniente do modulo 1, lista2= lista de alunos ja existente, lista1=lista a ser criada*/
int conta,conta2,conta3,conta4;
		if(lista1==NULL){   /*essa parte do codigo aloca uma espaco de memoria para a lista1, caso ela ainda esteja vazia*/
			
			lista1=(listadeprojetosfinal*)malloc(sizeof(listadeprojetosfinal));
			lista1->prox=NULL;
		
			lista1->discentes=(Listadiscentes*)malloc(sizeof(Listadiscentes));
			lista1->discentes->prox=NULL;		
			
			lista1->docentes=(Listadocentes*)malloc(sizeof(Listadocentes));
			lista1->docentes->prox=NULL;
			
			lista1->discentesexternos=(Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
			lista1->discentesexternos->prox=NULL;
			
				
		}
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
				if(strstr(lista2->integrante1,temp10->nomeProfessor)!=NULL){/*se o nome for igual, ele o salva na lista1-> nomedocentes*/					
					char*auxNome=strstr(lista2->integrante1,temp10->nomeProfessor);
					strcpy(lista1->docentes->nomedocente, auxNome);												
					conta3=1;
				}/*terceiro if*/
					
				temp10=temp10->proximoProfessor;						   										
			}/*while da verificacao do professor*/ 
			while(temp1->proximoAluno!=NULL){/*variavel temp que percorre a lista de alunos comparando o nome da lista de alunos com o nome da lista de integrantes da lista 2*/
				if(strstr(lista2->integrante1,temp1->nomeAluno)!=NULL){/*se o nome for igual, ele o salva na lista1-> nomediscente*/
					char*auxNome2=strstr(lista2->integrante1,temp1->nomeAluno);
					strcpy(lista1->discentes->nomediscente, auxNome2);															
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
				if(strstr(lista2->integrante2,temp100->nomeProfessor)!=NULL){/*se o nome for igual, ele o salva na lista1-> nomedocentes*/
					char*auxNome4=strstr(lista2->integrante2,temp100->nomeProfessor);
					Listadocentes*nodo200;
					nodo200=(Listadocentes*)malloc(sizeof(Listadocentes));
					strcpy(nodo200->nomedocente, auxNome4);								
					nodo200->prox=lista1->docentes;
					lista1->docentes=nodo200;
					conta4=1;
						
				}/*terceiro if*/
				temp100=temp100->proximoProfessor;						   										
			}/*while da verificacao do professor*/ 
			while(temp12->proximoAluno!=NULL){/*variavel temp que percorre a lista de alunos comparando o nome da lista de alunos com o nome da lista de integrantes da lista 2*/
				if(strstr(lista2->integrante2,temp12->nomeAluno)!=NULL){/*se o nome for igual, ele o salva na lista1-> nomediscente*/
					char*auxNome3=strstr(lista2->integrante2,temp12->nomeAluno);
					Listadiscentes*nodo20;
					nodo20=(Listadiscentes*)malloc(sizeof(Listadiscentes));
					strcpy(nodo20->nomediscente, auxNome3);								
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



/*=========================================EVENTOS:==============================================================*/
/*Funcao que gera a lista de Eventos com os participantes divididos em Docentes, Discentes e Discentes externos a partir das listas criadas pelo modulo1*/

/*!
* \brief Funcao que mainpula e cria a lista de eventos final
* \param lista1 lista de eventos final
* \param lista2 lista de eventos proveniente do modulo1
* \param lista4 lista de professores
* \param lista3 lista de alunos
* \return lista de eventos com autores separados por categoria academica
*/

listaDeEventosFinal*insereNaListadeEventosFinal(listaDeEventosFinal*lista1,listaDeEventos*lista2, listaDeAlunos*lista3,listaDeProfessores*lista4){ /*lista2=lista ja existente proveniente do modulo 1, lista2= lista de alunos ja existente, lista1=lista a ser criada*/
int conta,conta2,conta3,conta4;
	
		if(lista1==NULL){ /*essa parte do codigo aloca uma espaco de memoria para a lista1, caso ela ainda esteja vazia*/
			
			lista1=(listaDeEventosFinal*)malloc(sizeof(listaDeEventosFinal));
			lista1->prox=NULL;
					
			lista1->discentes=(Listadiscentes*)malloc(sizeof(Listadiscentes));
			lista1->discentes->prox=NULL;		
			
			lista1->docentes=(Listadocentes*)malloc(sizeof(Listadocentes));
			lista1->docentes->prox=NULL;
			
			lista1->discentesexternos=(Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
			lista1->discentesexternos->prox=NULL;


		}
			
		listaDeEventosFinal*aux=(listaDeEventosFinal*)malloc(sizeof(listaDeEventosFinal));
		aux->prox=NULL;		
		aux->discentes=(Listadiscentes*)malloc(sizeof(Listadiscentes));
		aux->docentes=(Listadocentes*)malloc(sizeof(Listadocentes));
		aux->discentesexternos=(Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
		aux->discentes->prox=NULL;		
		aux->docentes->prox=NULL;
		aux->discentesexternos->prox=NULL;
		strcpy(lista1->nomeProfessor,lista2->nomeProfessor);
		strcpy(lista1->nomeParaCitacao_Professor, lista2->nomeParaCitacao_Professor);
		strcpy(lista1->natureza, lista2->natureza);
		strcpy(lista1->titulo,lista2->titulo);
		strcpy(lista1->pais, lista2->pais);
		strcpy(lista1->idioma, lista2->idioma);
		strcpy(lista1->nomeEvento, lista2->nomeEvento);
		int flag=0,h=0;

		while(flag!=1){
			if(lista2->ano[h]=='"'){
				lista2->ano[h]=lista2->ano[h+1];
				lista2->ano[h+1]=lista2->ano[h+2];
				lista2->ano[h+2]=lista2->ano[h+3];
				lista2->ano[h+3]=lista2->ano[h+4];
				lista2->ano[h+4]='\0';
				flag=1;
			}
			h++;
		}
		strcpy(lista1->ano, lista2->ano);
		strcpy(lista1->proceedings, lista2->proceedings);
		strcpy(lista1->volume, lista2->volume);
		strcpy(lista1->paginaInicial, lista2->paginaInicial);
		strcpy(lista1->paginaFinal, lista2->paginaFinal);
		
		while(lista2->autores!=NULL){ /*while que garante que todos os nodos contendo os nomes dos autores da lista2->autores sejam verificados*/
			listaDeAlunos*temp1;
		listaDeProfessores*temp10;					
		temp1=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
		temp10=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));					
		temp1=lista3;
		temp10=lista4;
		conta=0,conta3=0;
		
			while(temp10->proximoProfessor!=NULL){/*variavel temp que percorre a lista de professores comparando o nome da lista de professores com o nome da lista de integrantes da lista 2*/
			
				if(strcmp(lista2->autores->nomeAutor, temp10->nomeProfessor)==0){/*se o nome for igual, ele o salva na lista1-> nomedocentes*/										
					if(lista1->docentes==NULL){				
						strcpy(lista1->docentes->nomedocente,lista2->autores->nomeAutor);
					}else{
					Listadocentes*nodo20;
					nodo20=(Listadocentes*)malloc(sizeof(Listadocentes));
					strcpy(nodo20->nomedocente, lista2->autores->nomeAutor);								
					nodo20->prox=lista1->docentes;
					lista1->docentes=nodo20;											
					conta3=1;
					}
				}/*terceiro if*/
					
				temp10=temp10->proximoProfessor;						   										
			}/*while da verificacao do professor*/ 
			while(temp1->proximoAluno!=NULL){/*variavel temp que percorre a lista de alunos comparando o nome da lista de alunos com o nome da lista de integrantes da lista 2*/
				
				if(strcmp(lista2->autores->nomeAutor,temp1->nomeAluno)==0){/*se o nome for igual, ele o salva na lista1-> nomediscente*/
					if(lista1->discentes==NULL){
						
						strcpy(lista1->discentes->nomediscente,lista2->autores->nomeAutor);
					}else{
					Listadiscentes*nodo200;
					nodo200=(Listadiscentes*)malloc(sizeof(Listadiscentes));
					strcpy(nodo200->nomediscente, lista2->autores->nomeAutor);								
					nodo200->prox=lista1->discentes;
					lista1->discentes=nodo200;															
					conta=1;
					}	
				}/*terceiro if*/
				temp1=temp1->proximoAluno;						   										
			}/*segundo while*/			
			if((conta==0)&&(conta3==0)){/*se for 0 eh pq o nome nao foi encontrado na lista de alunos e nem na de professores, entao eh um aluno externo*/										
				if(lista1->discentes==NULL){
						
						strcpy(lista1->discentesexternos->nomediscenteexterno,lista2->autores->nomeAutor);
						
					}else{
				
						Listadiscentesexternos*nodo30;
						nodo30=(Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));								
						strcpy(nodo30->nomediscenteexterno, lista2->autores->nomeAutor);											
						nodo30->prox=lista1->discentesexternos;
						lista1->discentesexternos=nodo30;	
					
					}																						
			}/*quarto if*/					
			lista2->autores=lista2->autores->proximoAutor;
		}/*while*/		


			aux->prox=lista1;
			lista1=aux;
				
			return lista1;
}




/*=========================================Periodicos:==============================================================*/
/*Funcao que gera a lista de periodicos com os participantes divididos em Docentes, Discentes e Discentes externos a partir das listas criadas pelo modulo1*/

/*!
* \brief Funcao que mainpula e cria a lista de periodicoss final
* \param lista1 lista de periodicos final
* \param lista2 lista de periodicos proveniente do modulo1
* \param lista4 lista de professores
* \param lista3 lista de alunos
* \return lista de periodicos com autores separados por categoria academica
*/


listaDePeriodicosFinal*insereNaListadePeriodicosFinal(listaDePeriodicosFinal*lista1,listaDePeriodicos*lista2, listaDeAlunos*lista3,listaDeProfessores*lista4){ /*lista2=lista ja existente proveniente do modulo 1, lista2= lista de alunos ja existente, lista1=lista a ser criada*/
int conta,conta2,conta3,conta4;
	
		if(lista1==NULL){ /*essa parte do codigo aloca uma espaco de memoria para a lista1, caso ela ainda esteja vazia*/
			
			lista1=(listaDePeriodicosFinal*)malloc(sizeof(listaDePeriodicosFinal));
			lista1->prox=NULL;
					
			lista1->discentes=(Listadiscentes*)malloc(sizeof(Listadiscentes));
			lista1->discentes->prox=NULL;		
			
			lista1->docentes=(Listadocentes*)malloc(sizeof(Listadocentes));
			lista1->docentes->prox=NULL;
			
			lista1->discentesexternos=(Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
			lista1->discentesexternos->prox=NULL;


		}
			
		listaDePeriodicosFinal*aux=(listaDePeriodicosFinal*)malloc(sizeof(listaDePeriodicosFinal));
		aux->prox=NULL;		
		aux->discentes=(Listadiscentes*)malloc(sizeof(Listadiscentes));
		aux->docentes=(Listadocentes*)malloc(sizeof(Listadocentes));
		aux->discentesexternos=(Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));
		aux->discentes->prox=NULL;		
		aux->docentes->prox=NULL;
		aux->discentesexternos->prox=NULL;
		strcpy(lista1->nomeProfessor,lista2->nomeProfessor);
		strcpy(lista1->nomeParaCitacao_Professor, lista2->nomeParaCitacao_Professor);
		strcpy(lista1->natureza, lista2->natureza);
		strcpy(lista1->tituloArtigo,lista2->tituloArtigo);
		strcpy(lista1->tituloPeriodico,lista2->tituloPeriodico	);
		strcpy(lista1->idioma, lista2->idioma);
		int flag=0,h=0;

		while(flag!=1){
			if(lista2->ano[h]=='"'){
				lista2->ano[h]=lista2->ano[h+1];
				lista2->ano[h+1]=lista2->ano[h+2];
				lista2->ano[h+2]=lista2->ano[h+3];
				lista2->ano[h+3]=lista2->ano[h+4];
				lista2->ano[h+4]='\0';
				flag=1;
			}
			h++;
		}
		strcpy(lista1->ano, lista2->ano);
		strcpy(lista1->serie, lista2->serie);
		strcpy(lista1->volume, lista2->volume);
		strcpy(lista1->paginaInicial, lista2->paginaInicial);
		strcpy(lista1->paginaFinal, lista2->paginaFinal);
		
		while(lista2->autores!=NULL){  /*while que garante que todos os nodos contendo os nomes dos autores da lista2->autores sejam verificados*/
			listaDeAlunos*temp1;
		listaDeProfessores*temp10;					
		temp1=(listaDeAlunos*)malloc(sizeof(listaDeAlunos));
		temp10=(listaDeProfessores*)malloc(sizeof(listaDeProfessores));					
		temp1=lista3;
		temp10=lista4;
		conta=0,conta3=0;
		
			while(temp10->proximoProfessor!=NULL){/*variavel temp que percorre a lista de professores comparando o nome da lista de professores com o nome da lista de integrantes da lista 2*/
			
				if(strcmp(lista2->autores->nomeAutor, temp10->nomeProfessor)==0){/*se o nome for igual, ele o salva na lista1-> nomedocentes*/										
					if(lista1->docentes==NULL){				
						strcpy(lista1->docentes->nomedocente,lista2->autores->nomeAutor);
					}else{
					Listadocentes*nodo20;
					nodo20=(Listadocentes*)malloc(sizeof(Listadocentes));
					strcpy(nodo20->nomedocente, lista2->autores->nomeAutor);								
					nodo20->prox=lista1->docentes;
					lista1->docentes=nodo20;											
					conta3=1;
					}
				}/*terceiro if*/
					
				temp10=temp10->proximoProfessor;						   										
			}/*while da verificacao do professor*/ 
			while(temp1->proximoAluno!=NULL){/*variavel temp que percorre a lista de alunos comparando o nome da lista de alunos com o nome da lista de integrantes da lista 2*/
				
				if(strcmp(lista2->autores->nomeAutor,temp1->nomeAluno)==0){/*se o nome for igual, ele o salva na lista1-> nomediscente*/
					if(lista1->discentes==NULL){
						
						strcpy(lista1->discentes->nomediscente,lista2->autores->nomeAutor);
					}else{
					Listadiscentes*nodo200;
					nodo200=(Listadiscentes*)malloc(sizeof(Listadiscentes));
					strcpy(nodo200->nomediscente, lista2->autores->nomeAutor);								
					nodo200->prox=lista1->discentes;
					lista1->discentes=nodo200;															
					conta=1;
					}	
				}/*terceiro if*/
				temp1=temp1->proximoAluno;						   										
			}/*segundo while*/			
			if((conta==0)&&(conta3==0)){/*se for 0 eh pq o nome nao foi encontrado na lista de alunos e nem na de professores, entao eh um aluno externo*/										
				if(lista1->discentes==NULL){
						
						strcpy(lista1->discentesexternos->nomediscenteexterno,lista2->autores->nomeAutor);
						
				}else{
				
					Listadiscentesexternos*nodo30;
					nodo30=(Listadiscentesexternos*)malloc(sizeof(Listadiscentesexternos));								
					strcpy(nodo30->nomediscenteexterno, lista2->autores->nomeAutor);											
					nodo30->prox=lista1->discentesexternos;
					lista1->discentesexternos=nodo30;	
					
					}																						
			}/*quarto if*/					
			lista2->autores=lista2->autores->proximoAutor;
		}/*while*/		


			aux->prox=lista1; /*conecta o novo nodo com a lista*/
			lista1=aux;
				
			return lista1;
}
