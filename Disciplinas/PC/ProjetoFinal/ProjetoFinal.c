//-------------------------------------------------------------------------
//------------------------- UNIVERSIDADE DE BRASÍLIA ----------------------
//-------------------------------------------------------------------------
// PROGRAMAÇÃO CONCORRENTE 2018/1
// PROFESSOR: EDUARDO ALCHIERI
// ALUNO: YAN VICTOR DOS SANTOS ~
// EMAIL: -
// Obs.: Código desenvolvido por mim
//-------------------------------------------------------------------------
//--------------------------- BIBLIOTECAS UTILIZADAS ----------------------
//-------------------------------------------------------------------------

#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"
#include "semaphore.h"
#include "unistd.h"
//---------------------------------------------------------------------------------------------------
//-------------------------- TODOS OS DEFINE'S - SESSÃO DE CONFIGURAÇÕES ----------------------------
//---------------------------------------------------------------------------------------------------

#define QTD_ALUNOS 5
#define QTD_CADEIRAS 3 // quanto + proximo de alunos, mais grupos aparecem em "grupos usando computadores"
#define QTD_COMPUTADORES 2 // quanto mais proximo da qtd de grupos criados, mais perto de zero, fica
#define MAX_POR_GRUPO 2
#define VARIEDADE 10 // não pode ser zero

#define TAXA_ATUALIZACAO 20 //20-entrada grande, 500-entrada pequena
#define TEMPO_USO_PC 5000 // quanto +, permite aumentar a qtd de grupos em "grupos usando computadores"
#define TEMPO_APOS_CONSEGUIR 500 // permite dinamicidade, evitando starvation
#define NOVA_COMBINACAO 1000 //ninguem conseguiu pegar computador, mas ninguem deve ir dar um passeio. Evita starvation
#define NUMERO_COLUNAS 4

//------------------------------------------------------------------------------------------
//-------------------------- FUNÇÃO AUXILIAR -> SLEEP PARA MS E NÃO S ----------------------
//------------------------------------------------------------------------------------------

#ifdef WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>   // for nanosleep
#else
#include <unistd.h> // for usleep
#endif

void sleep_ms(int milliseconds) // cross-platform sleep function
{
#ifdef WIN32
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    usleep(milliseconds * 1000);
#endif
}

//-------------------------------------------------------------------------
//-------------------------- DECLAÇÕES DAS VARIÁVEIS ----------------------
//-------------------------------------------------------------------------

//----> Estruturas de controle de acesso concorrente
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_print = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_pc = PTHREAD_MUTEX_INITIALIZER; // controle de acesso
pthread_mutex_t lock_espera_tempo = PTHREAD_MUTEX_INITIALIZER; // controle de acesso
pthread_mutex_t lock_alguem_n_conseguiu = PTHREAD_MUTEX_INITIALIZER; // controle de acesso
pthread_cond_t linf_cheio = PTHREAD_COND_INITIALIZER; // Se chegar no linf e nao tiver cadeira, vai pro RU (não usada ainda)
sem_t cadeiras; // controla cadeiras disponíveis
pthread_barrier_t *barreira; // uma barreira por grupo
pthread_barrier_t mais_informacoes; // permite adicionar novas informações somente após todos os alunos estiverem separados por grupo
//----> Outras variaveis
//grupo[indice]: indica a qual grupo o Aluno[aluno.id==indice] pertence
//sz_grupo[indice]: indica quantos componentes o Grupo[grupo.numero==indice] possui
//tam_grupo: indica o tamanho de cada grupo (auxiliar) / num_grupo: indica a QTD de grupos existentes / flag: uma thread para infors adicionais
int grupo[QTD_ALUNOS], *sz_grupo, tam_grupo=0, num_grupo=0, thr_infors_adicionais=1, *alguem_nao_conseguiu, *representante_grupo, tem_computador = QTD_COMPUTADORES, tem_cadeiras, *cadeira_por_grupo, deve_pausar=1; 


//-------------------------------------------------------------------------
//---------------------- DECLARAÇÕES DAS FUNÇÕES ----------------------------
//-------------------------------------------------------------------------

void inicializa_sem_barr(); // Chamada pela func. main, inicia semáforos, barreiras, etc.
void * cria_grupos_alunos(void *arg); // Chamada pela func. main, cria aleatoriamente grupos de alunos, considerando os DEFINE'S
void mais_infors(); // Chamada pela func. cria_grupos_alunos, guarda a infor do tamanho de cada grupo em sz_grupo. Faz uma barreira por grupo
void abre_linf(int id_aluno); // Chamada pela func. cria_grupos_alunos, inicia alunos tentando acessar o linf
void pega_computador(int grup, int id_aluno); // conseguiu recurso
void pega_cadeira(int grup); // prestes a conseguir o computador
void sem_cadeiras(int grup, int id_aluno); // vai passear
void grupo_nao_conseguiu(int grup, int id_aluno); // vai passear
void libera_cadeira(int grup); // faz broadcast
void dar_um_passeio(int grup, int id_aluno); // espera broadcast signal
void verifica_configuracao(); // analisa se configuração é valida
//-------------------------------------------------------------------------
//--------------------------- INÍCIO DE FUNÇÕES ---------------------------
//-------------------------------------------------------------------------

//--------------------------- FUNÇÃO PRINCIPAL
int main()
{
	pthread_t a[QTD_ALUNOS];
	int i;

	int *id_aluno;
	inicializa_sem_barr();
	srand(time(NULL));
	printf("\n============================= INICIO =============================\n");

	verifica_configuracao();
	
	for(i=0; i<QTD_ALUNOS; ++i)
	{
		id_aluno = (int *) malloc(sizeof(int));
		*id_aluno = i;
		pthread_create(&a[i], NULL, cria_grupos_alunos, (void *) (id_aluno));
	}

	
	pthread_join(a[0],NULL);

	return 0;
}

void verifica_configuracao()
{
	int status=0;
	if(!QTD_COMPUTADORES)
	{
		printf("Quantidade de computadores deve ser maior que 0!!!\n");
		status=1;
	}
	if(!QTD_ALUNOS)
	{
		printf("O laboratorio deve ser acessado por pelo menos 1 aluno!!!\n");
		status=1;
	}
	if(!QTD_CADEIRAS)
	{
		printf("Quantidade de cadeiras deve ser maior que 0!!!\n");
		status=1;
	}
	if(!MAX_POR_GRUPO)
	{
		printf("Cada grupo deve conter pelo menos 1 membro!!!\n");
		status=1;
	}
	if(status)
		exit(1);
}

//--------------------------- INICIALIZA ESTRUTURAS NECESSÁRIAS PARA O CONTROLE DE ACESSO AO LINF

void inicializa_sem_barr(){
    	sem_init(&cadeiras, 0, QTD_CADEIRAS); // semaforo, pista compartilhada por todos os processos, capacidade C
		pthread_barrier_init(&mais_informacoes, NULL, QTD_ALUNOS);
}

//--------------------------- SEPARA ALUNOS POR GRUPOS

void * cria_grupos_alunos(void *arg)
{
	int id_aluno = *((int*) arg);	

//---- Distribuição de alunos por grupo

	pthread_mutex_lock(&lock); // ~~~ 1 THREAD DE CADA VEZ
	
	//--- sorteia se o componente vai fazer parte do grupo anterior ou não. Um grupo pode ter no máximo QTD_GRUPOS
	if((rand() % VARIEDADE && tam_grupo<MAX_POR_GRUPO) || (!num_grupo && !tam_grupo)) //Segunda condição: apenas para o 1º aluno (força criar novo grupo).
	{
		
		if(!num_grupo && !tam_grupo) // se for o primeiro aluno do primeiro grupo
			printf("~> Aluno[%d] faz parte do Grupo[%d]\n", id_aluno, num_grupo);					
		else
			printf("~~~>Aluno[%d] faz parte do Grupo[%d]\n", id_aluno, num_grupo);

		grupo[id_aluno]=num_grupo;
		tam_grupo++;
	}
	else //criando novo grupo
	{ 
		num_grupo++; 
		grupo[id_aluno]=num_grupo;
		tam_grupo=1;
		printf("\n~> Aluno[%d] faz parte do Grupo[%d]\n", id_aluno, num_grupo);
	}
	pthread_mutex_unlock(&lock); 

//---- Informações adicionais

	pthread_barrier_wait(&mais_informacoes); //para fazer a contagem de membros de grupos, todos os alunos devem ter entrado em um grupo.

	pthread_mutex_lock(&lock); //apenas uma thread é responsável por tratar informações adicionais: qtd_pessoas_por_grupo, uma_barreira_grupo
		if(thr_infors_adicionais)
		{
			num_grupo++;
			mais_infors();

			thr_infors_adicionais=0;
			printf("\n ** FIM DA SEPARAÇÃO DE ALUNOS **\n");
			printf("\n======> TOTAL DE GRUPOS: %d\n", num_grupo);
			for(int j=0;j<num_grupo;j++)
				printf("\nQTD_Grupo[%d]: %d alunos", j, sz_grupo[j]);

			printf("\n\nQUE TAL COLOCAR TODOS ESTES ALUNOS PARA ACESSAR O LINF?\n\n");
			printf("...PRESSIONE <enter> ...\n\n");
			getchar();
			printf("Iniciando simulacao em 3...\n");
			sleep(1);
			printf("Iniciando simulacao em 2...\n");
			sleep(1);
			printf("Iniciando simulacao em 1...\n\n\n");
			sleep(1);
		}
	pthread_mutex_unlock(&lock);

	pthread_barrier_wait(&mais_informacoes); // espera a thread de apresentação acima encerrar, para todas prosseguirem adiante

	abre_linf(id_aluno); //alunos (threads) começam a usar o linf
	
	free(alguem_nao_conseguiu);
	free(representante_grupo);
	free(sz_grupo);
}

//--------------------------- GUARDA INFORMAÇÕES DE QUANTOS ALUNOS CADA GRUPO POSSUI, DEFINE UMA BARREIRA PARA CADA GRUPO

void mais_infors()
{
	int *tam_cada_grupo, *flag_grupo_nao_conseguiu, *representante, *cadeira_grupo, cont = 0, indice = 0;

	tam_cada_grupo = (int*)malloc(num_grupo*sizeof(int));
	flag_grupo_nao_conseguiu = (int*)malloc(num_grupo*sizeof(int));
	representante = (int*)malloc(num_grupo*sizeof(int));
	cadeira_grupo = (int*)malloc(num_grupo*sizeof(int));
	
	//----- Guardando em sz_grupo a informação de quantos componentes tem cada grupo
	for(int i=0; i<num_grupo; i++)
	{
		tam_cada_grupo[i]=0;
		flag_grupo_nao_conseguiu[i]=0;
		cadeira_grupo[i]=0;
		representante[i]=(-1);
		
	}

	alguem_nao_conseguiu = flag_grupo_nao_conseguiu;
	representante_grupo = representante;
	cadeira_por_grupo = cadeira_grupo;
	
	for(int i=0; i<QTD_ALUNOS; i++)
		tam_cada_grupo[grupo[i]]++;		
	sz_grupo = tam_cada_grupo;
	
	//----- Definindo, dinamicamente, uma barreira por grupo
	pthread_barrier_t * barreira_aux;
	barreira_aux = (pthread_barrier_t*)malloc(num_grupo*sizeof(pthread_barrier_t));

	for(int i=0; i<num_grupo; i++)
		pthread_barrier_init(&barreira_aux[i], NULL, sz_grupo[i]);
	barreira = barreira_aux;
}

//--------------------------- FUNÇÃO PRINCIPAL QUE CONTROLA O ACESSO AO LINF

void atualiza_linf(){
	//pthread_mutex_lock(&lock_print);
	system("clear");
	printf("\n================================================== LINF ==================================================\n");
	printf("| PC's disponiveis: %d/%d\n", tem_computador, QTD_COMPUTADORES);
	sem_getvalue(&cadeiras, &tem_cadeiras);
	printf("| Cadeiras disponíveis: %d/%d\n", tem_cadeiras, QTD_CADEIRAS);
	printf("| Grupos usando PC's: ");	
	for(int i=0; i<num_grupo; i++)
		if(representante_grupo[i] != (-1))
			printf("G%d[%d], ", grupo[ representante_grupo[i] ], sz_grupo[i]);
	printf("\n");
	printf("\n==========================================================================================================\n");
	printf("Outras informacoes:\n");
	printf("=> Total de alunos: %d\n", QTD_ALUNOS);
	printf("=> Total de Grupos: %d\n", num_grupo); 
	printf("=> Tempo de uso: %.2fs\n", (float) TEMPO_USO_PC/1000); 
	printf("=> Taxa de atualizacao: %.2fs\n", (float) TAXA_ATUALIZACAO/1000); 
	printf("=> Sobre os grupos: \n\n");
	for(int i=0; i<num_grupo; i++)
	{
		printf("G%d[%d]: ocupando %d cadeiras	", i, sz_grupo[i], cadeira_por_grupo[i]);
		if(i%NUMERO_COLUNAS==0)
			printf("\n");
	}	
	printf("\n");
	if(deve_pausar)
		sleep_ms(TAXA_ATUALIZACAO);

	//pthread_mutex_unlock(&lock_print);
}

//--------------------------- FUNÇÃO QUE AVISA QUE NÃO CONSEGUIU CADEIRAS

void sem_cadeiras(int grup, int id_aluno)
{
	pthread_mutex_lock(&lock_alguem_n_conseguiu); //lock para o caso de 2 ou + alunos do mesmo grupo nao conseguir -> controla variavel
		alguem_nao_conseguiu[ grup ]++;
	pthread_mutex_unlock(&lock_alguem_n_conseguiu);

	pthread_barrier_wait(&barreira[ grup ]); //indica pro grupo que nao conseguiu
	pthread_barrier_wait(&barreira[ grup ]); //garante que o grupo INTEIRO entendeu que nao conseguiu, e volta flag para 0
			
	pthread_mutex_lock(&lock_alguem_n_conseguiu); //lock para o caso de 2 ou + alunos do mesmo grupo nao conseguir -> controla variavel	
		alguem_nao_conseguiu[ grup ]--;
	pthread_mutex_unlock(&lock_alguem_n_conseguiu);
		
	dar_um_passeio(grup, id_aluno);
}

//--------------------------- FUNÇÃO QUE INDICA QUE NÃO TEM MAIS COMPUTADORES DISPONÍVEIS

void sem_computadores(int grup)
{
	pthread_mutex_lock(&lock_alguem_n_conseguiu); //lock para o caso de 2 ou + alunos do mesmo grupo nao conseguir -> controla variavel
		alguem_nao_conseguiu[ grup ]++;
	pthread_mutex_unlock(&lock_alguem_n_conseguiu);

	pthread_mutex_unlock(&lock_pc);
	pthread_barrier_wait(&barreira[ grup ]); //indica pro grupo que nao conseguiu
			
	pthread_mutex_lock(&lock_alguem_n_conseguiu); //lock para o caso de 2 ou + alunos do mesmo grupo nao conseguir -> controla variavel	
		alguem_nao_conseguiu[ grup ]--;
	pthread_mutex_unlock(&lock_alguem_n_conseguiu);

	printf("G%d[¬PC] ", grup);
}

//--------------------------- FUNÇÃO QUE FAZ PASSEAR - ESPERA SIGNAL BROADCAST

void dar_um_passeio(int grup, int id_aluno)
{
	pthread_mutex_lock(&lock_espera_tempo);	//lock serve para impedir que durmam depois do broadcast de outros alunos
		if(tem_computador<QTD_COMPUTADORES) //So vai para o RU (dormir) se tiver pelo menos um grupo usando um computador
		{				
			printf("G%d(Aluno:%d)[PASSEAR], ", grup, id_aluno);
			pthread_cond_wait(&linf_cheio, &lock_espera_tempo); //a verificacao de tem_computador impede que o grupo durma eternamente
		}				
	pthread_mutex_unlock(&lock_espera_tempo);
	if(tem_computador==QTD_COMPUTADORES) // ninguem conseguiu pegar nenhum computador
		sleep_ms(NOVA_COMBINACAO);
}

//--------------------------- FUNÇÃO QUE INDICA QUE ALGUÉM DO GRUPO NÃO CONSEGUIU, PORTANTO VAI PASSEAR

void grupo_nao_conseguiu(int grup, int id_aluno)
{
	libera_cadeira(grup);
	dar_um_passeio(grup, id_aluno); 	
}

//--------------------------- FUNÇÃO DE SUCESSO!! UTILIZA RECURSO

void pega_computador(int grup, int id_aluno)
{
	if(representante_grupo[ grup ]==-1)	//elege representante do grupo pra pegar o computador	
	{					
		pthread_mutex_lock(&lock_print);	
			representante_grupo[ grup ] = id_aluno;
			tem_computador--;
			deve_pausar=1;
			atualiza_linf();
			printf("G%d[SUCESSO] ", grup);
		pthread_mutex_unlock(&lock_print);
	}	

	pthread_mutex_unlock(&lock_pc);
	pthread_barrier_wait(&barreira[ grup ]); // garante que todo o grupo esta pronto para usar o computadorc
	
	sleep_ms(TEMPO_USO_PC); // usa o computador

	libera_cadeira(grup);
	if(representante_grupo[ grup ] == id_aluno) // libera o computador
	{
		pthread_mutex_lock(&lock_print);
			printf("G%d[ENCERRADO] ", grup);
			representante_grupo[ grup ] = -1;
			tem_computador++;
			deve_pausar=1;
			atualiza_linf();
		pthread_mutex_unlock(&lock_print);
	sleep_ms(TEMPO_APOS_CONSEGUIR);
	}
	pthread_mutex_lock(&lock_print);
		deve_pausar=1;
		atualiza_linf();
	pthread_mutex_unlock(&lock_print);
}

//--------------------------- FUNÇÃO DE SUCESSO!! UTILIZA CADEIRA. PRESTES A CONSEGUIR O COMPUTADOR

void pega_cadeira(int grup)
{
//	pthread_mutex_lock(&lock); //serve para print de quantidade de cadeiras que o grupo esta usando
	pthread_mutex_lock(&lock_print);
		if(cadeira_por_grupo[grup]<QTD_CADEIRAS)
			cadeira_por_grupo[grup]++;
		deve_pausar=0;
		atualiza_linf();
	pthread_mutex_unlock(&lock_print);
//	pthread_mutex_unlock(&lock);
	pthread_mutex_lock(&lock_espera_tempo);	//serve para impedir que a galera fique no RU pra sempre, (broad antes de dormirem, etc)
		pthread_cond_broadcast(&linf_cheio); //manda mensagem no grupo do CiC avisando que liberaram as cadeiras
	pthread_mutex_unlock(&lock_espera_tempo);
	
}

//--------------------------- FUNÇÃO QUE LIBERA A CADEIRA. FAZ BROADCAST 

void libera_cadeira(int grup)
{

	//pthread_mutex_lock(&lock); //serve para print de quantidade de cadeiras que o grupo esta usando
	pthread_mutex_lock(&lock_print);
		sem_post(&cadeiras); //libera cadeiras
		if(cadeira_por_grupo[grup]>0)
			cadeira_por_grupo[grup]--;
	//	deve_pausar=1;
//		atualiza_linf();
		sleep_ms(TAXA_ATUALIZACAO);
	pthread_mutex_unlock(&lock_print);
	//pthread_mutex_unlock(&lock);

	pthread_mutex_lock(&lock_espera_tempo);	//serve para impedir que a galera fique no RU pra sempre, (broad antes de dormirem, etc)
		pthread_cond_broadcast(&linf_cheio); //manda mensagem no grupo do CiC avisando que liberaram as cadeiras
	pthread_mutex_unlock(&lock_espera_tempo);	
}

//--------------------------- FUNÇÃO PRINCIPAL QUE DESCREVE O ALGORITMO DO ARTIGO. SIMULA O LINF!!!

void abre_linf(int id_aluno)
{
	int grup = grupo[id_aluno];
	while(1)
	{
	pthread_mutex_lock(&lock_print);
		deve_pausar=0;
		atualiza_linf();
	pthread_mutex_unlock(&lock_print);
		if(sem_trywait(&cadeiras) == 0) //Cada aluno tenta pegar uma cadeira vazia
		{ 		
			pega_cadeira(grup);
			pthread_barrier_wait(&barreira[ grup ]); // grupo espera para ver se todo o grupo consegue pegar cadeiras

			if(alguem_nao_conseguiu[ grup ]) //se alguem do grupo nao tiver conseguido cadeiras
			{
				pthread_barrier_wait(&barreira[ grup ]); // avisa para o que nao conseguiu cadeira, que entendeu que ele nao conseguiu
				grupo_nao_conseguiu(grup, id_aluno);
			}
			else //caso todo o grupo tenha conseguido pegar cadeiras
			{	
				pthread_mutex_lock(&lock_pc);
				if((tem_computador || representante_grupo[ grup ] != -1) && !alguem_nao_conseguiu[ grup ]) //tem computador? obs: se tem representante eh pq pegou um computador
				{	
					pega_computador(grup, id_aluno); //unlock de lock_pc esta dentro desta funcao
				}
				else
				{
					sem_computadores(grup);
					grupo_nao_conseguiu(grup, id_aluno);
				}
				pthread_barrier_wait(&barreira[ grup ]); // faz o grupo todo sair do linf ao mesmo tempo
			}
		}
		else // caso um aluno nao tenha conseguido pegar uma cadeira
		{ 
			sem_cadeiras(grup, id_aluno);
		}
	}	
}
