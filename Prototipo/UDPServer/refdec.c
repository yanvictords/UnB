// UNIVERSIDADE DE BRASÍLIA - 2018/2
// YAN VICTOR DOS SANTOS
// PROXY DE TESTE 

//=============
//==INCLUDE'S==
//=============
#include "refdec.h"

//============
//==DEFINE'S==
//============
#define _PORTA_CLIENTE 2000
#define _PORTA_SERV 8080
#define _IP_SERVIDOR "127.0.0.1"
#define LEN 4096

//=============
//==VARIÁVEIS==
//=============
struct sockaddr_in addr_cliente; // usado para o addr_cliente
struct sockaddr_in addr_serv; // usado para pedir conexão ao servidor finals

//===========
//==FUNÇÕES==
//===========
int main()
{
	int sck_cliente, sck_servidor; // soquetes
	int tam_msg; // tamanho da mensagem recebida
	char buffer[LEN], resposta[LEN]; // mensagem a ser enviada/recebida

	printf("================ PROXY - UDP =================\n\n");

//===================================================================
// CRIAÇÃO DE SOCKET E PORTA PARA SE CONECTAR AO SERVIDOR FINAL: UDP
//===================================================================
	sck_servidor = socket(AF_INET, SOCK_DGRAM, 0); //UDP

	if(sck_servidor == -1) 
	{
		perror("PROXY: O socket final nao foi criado com sucesso!\n");
		exit(1);	
	}
	else
		printf("O socket final foi criado com sucesso!\n");

//=== configurações do servidor final
	addr_serv.sin_family = 		AF_INET;
	addr_serv.sin_port = 		htons(_PORTA_SERV);
	addr_serv.sin_addr.s_addr = 		inet_addr(_IP_SERVIDOR);
	memset(addr_serv.sin_zero, 0x0, 8);
//=== fim das configurações do servidor final

	struct sockaddr *cast_addr_serv = (struct sockaddr *) &addr_serv; // cast do endereço para struct genérica
	int tam_addr_servidor = sizeof(addr_serv); // tamanho da struct

//=====================================================
// CRIAÇÃO DE SOCKET E PORTA PARA OUVIR O CLIENTE: UDP
//===================================================== 
	sck_cliente = socket(AF_INET, SOCK_DGRAM, 0); //UDP

	if(sck_cliente == -1) 
	{
		perror("PROXY: O socket nao foi criado com sucesso!\n");
		exit(1);	
	}
	else
		printf("O socket com o cliente foi criado com sucesso!\n");

//=== configurações do addr_cliente
	addr_cliente.sin_family =		AF_INET; // para linux
	addr_cliente.sin_port = 		htons(_PORTA_CLIENTE); // porta de escuta para bind()
	memset(addr_cliente.sin_zero, 0x0, 8);
//=== fim das configurações do addr_cliente

	struct sockaddr *cast_addr_cliente = (struct sockaddr *) &addr_cliente; // cast do endereço para struct genérica
	int tam_addr_cliente = sizeof(addr_cliente); // tamanho da struct

	if(bind(sck_cliente, cast_addr_cliente, tam_addr_cliente) == -1) // tenta associar o socket a uma porta
	{
		printf("Erro ao abrir a porta %d!\n", _PORTA_CLIENTE);
		exit(1);
	}
	else
		printf("Porta %d foi aberta com sucesso!\n", _PORTA_CLIENTE);

//====================================
// PROXY ONLINE... ESPERA POR CLIENTE
//====================================
	printf("\nEsperando por mensagens: UDP...\n");

//===========================================================
// RECEBE DO CLIENTE, ENVIA AO SERVIDOR E REENVIA A RESPOSTA
//===========================================================

	while(1)
	{
		memset(buffer, 0x0, LEN);
		if((tam_msg = recvfrom(sck_cliente, buffer, LEN, 0, cast_addr_cliente, &tam_addr_cliente)) > 0) // mensagem recebida > 0
		{
			buffer[tam_msg] = '\0';
			printf("\n=> Mensagem recebida do cliente: %s\n", buffer);
			printf("Enviando para o servidor final...\n");
			//char ip = inet_ntoa(addr_cliente.sin_addr);
			//printf("Cliente: %s\n\n", ip);
			//if(verifica_tabela() == OK) {

			if(sendto(sck_servidor, buffer, strlen(buffer), 0, cast_addr_serv, tam_addr_servidor))
			{
				if(!strcmp(buffer, "exit")) // se a mensagem for exit, fecha a conexão
					break;

				printf("Aguardando resposta do servidor...");
				if((tam_msg = recvfrom(sck_servidor, resposta, LEN, 0, cast_addr_serv, &tam_addr_servidor)) > 0)
				{
					printf("\n=> Mensagem recebida do servidor: %s\n", resposta);
					printf("Enviando novamente para o cliente...\n");
					if(sendto(sck_cliente, resposta, strlen(resposta), 0, cast_addr_cliente, tam_addr_cliente)) // repassa do servidor ao cliente
						printf("Requisicao operada com sucesso!\n");
					else
					{
						perror("PROXY: Requisicao problematica!\n");
					}				
				}
			}
			else
			{
				printf("Mensagem nao foi enviada ao servidor com sucesso...\n");
				perror("PROXY: O servidor nao estava online. Desculpe o transtorno!\n");
				exit(0);
			}
		}
	}

//==========================
// ENCERRAMENTO DO PROGRAMA
//==========================

	close(sck_cliente); // fecha o socket que recebe mensagens de cliente
	close(sck_servidor); // fecha o socket da conexão com o servidor

	printf("\n\nFinalizando o proxy...\n");
	return 0;
}
