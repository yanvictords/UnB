// UNIVERSIDADE DE BRASÍLIA - 2018/2
// YAN VICTOR DOS SANTOS
// addr_cliente DE TESTE 

#include "refdec.h"

struct sockaddr_in addr_cliente; // usado para o addr_cliente
struct sockaddr_in addr_remoto; // usado em accept para ouvir cliente
struct sockaddr_in addr_serv; // usado para pedir conexão ao addr_servidor final
#define _PORTA 2001
#define _PORTASERV 8080
#define LEN 4096
int main()
{
	int sck_cliente, sck_servidor;
	int cliente;
	int len_cliente = sizeof(addr_remoto), len_servidor = sizeof(addr_serv), slen;
	char buffer[LEN], resposta[LEN]; // mensagem a ser enviada

	printf("================ PROXY =================\n\n");

//=========================================================== CRIAÇÃO DE SOCKET E PORTA PARA OUVIR O CLIENTE

	if((sck_cliente = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
	{
		perror("PROXY: O socket nao foi criado com sucesso!\n");
		exit(1);	
	}
	else // caso tenha conseguido criar o socket
		printf("O socket foi criado com sucesso!\n");
//--- configurações do addr_cliente
	addr_cliente.sin_family =		AF_INET; // para linux
	addr_cliente.sin_port = 		htons(_PORTA); // porta de escuta para bind()
	memset(addr_cliente.sin_zero, 0x0, 8);
//--- fim das configurações do addr_cliente

	if(bind(sck_cliente, (struct sockaddr*) &addr_cliente, sizeof(addr_cliente)) == -1) // tenta associar o socket a uma porta
	{
		printf("Erro ao abrir a porta %d!\n", _PORTA);
		exit(1);
	}
	else
		printf("Porta %d foi aberta com sucesso!\n", _PORTA);

//=========================================================== CRIAÇÃO DE SOCKET E PORTA PARA SE CONECTAR AO addr_servIDOR FINAL

	if((sck_servidor = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
	{
		perror("PROXY: O socket final nao foi criado com sucesso!\n");
		exit(1);	
	}
	else // caso tenha conseguido criar o socket
		printf("O socket final foi criado com sucesso!\n");

//--- configurações do addr_servidor final
	addr_serv.sin_family = 		AF_INET;
	addr_serv.sin_port = 		htons(_PORTASERV);
	addr_serv.sin_addr.s_addr = 		inet_addr("127.0.0.1");
	memset(addr_serv.sin_zero, 0x0, 8);
//--- fim das configurações do addr_servidor final

	if(connect(sck_servidor, (struct sockaddr*)&addr_serv, len_servidor)==-1)
	{
		perror("O addr_servidor final nao conectou!\n");	
		exit(1);
	}
	else
		perror("Conexao com o addr_servidor final feita com sucesso!");

//=========================================================== PROXY ONLINE... ESPERA POR CLIENTE

	listen(sck_cliente, 1); // escuta o cliente

	if((cliente = accept(sck_cliente, (struct sockaddr*)&addr_remoto, &len_cliente))==-1) // tenta conexão com o cliente
	{
		perror("PROXY: Conexao falhou!\n");	
		exit(1);
	}
	else
		perror("PROXY: Conexao feita com sucesso!\n");

//=========================================================== RECEBE DO CLIENTE, ENVIA AO SERVIDOR E REENVIA A RESPOSTA

	strcpy(buffer, "Seja bem-vindo...\n\0");
	if(send(cliente, buffer, strlen(buffer), 0)){
		//printf("Aguardando pedido do cliente...\n");
		perror("Estamos aguardando a requisicao...\n");
	}

//---

	while(1) // espera em loop a mensagem do cliente
	{
		if((slen = recv(cliente, buffer, LEN, 0)) > 0) // caso o tamanho da mensagem recebida em buffer seja maior que zero
		{
			buffer[slen] = '\0';
			printf("\n=> Mensagem recebida do cliente: %s\n", buffer);
			printf("Enviando para o servidor final...\n");

			if(send(sck_servidor, buffer, strlen(buffer), 0)) // repassa o pedido ao servidor
			{
				if(!strcmp(buffer, "exit")) // se a mensagem for exit, fecha a conexão
				{
					close(cliente); // fecha a conexão com o cliente
					close(sck_servidor); // fecha a conexão com o servidor
					break;
				}
				printf("Aguardando resposta do servidor...");
				if((slen = recv(sck_servidor, resposta, LEN, 0)) > 0) // se o servidor responder
				{
					printf("\n=> Mensagem recebida do servidor: %s\n", resposta);
					printf("Enviando novamente para o cliente...\n");
					if(send(cliente, resposta, strlen(resposta), 0)) // repassa a resposta do servidor ao cliente
						printf("Requisicao operada com sucesso!\n");
					else
					{
						//printf("Requisicao problematica!\n");
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

	close(sck_cliente); // fecha o socket que recebe mensagens de cliente

	printf("\n\nFinalizando o proxy...\n");
	return 0;
}
