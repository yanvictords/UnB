// UNIVERSIDADE DE BRASÍLIA - 2018/2
// YAN VICTOR DOS SANTOS
// CLIENTE DE TESTE 

#include "refdec.h"

struct sockaddr_in hints;

#define PORTA 7000

#define IP_SERVIDOR "10.42.0.181"
#define LEN 4096
#define _IP_SERVIDOR "127.0.0.1"

int main()
{
	printf("================ CLIENTE - TCP =================\n\n");

	int sockfd;
	int slen;
	char buffer[LEN];

	memset(&hints, 0, sizeof(hints));
	hints.sin_family = AF_INET;
	hints.sin_port = htons(PORTA);
	hints.sin_addr.s_addr = inet_addr(_IP_SERVIDOR);
	
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0); //TCP
	hints.sin_addr.s_addr = inet_addr(_IP_SERVIDOR);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1)
	{
		perror("O socket nao foi criado com sucesso!\n");
		exit(1);	
	}
	else
	{
		printf("O socket foi criado com sucesso!\n");
	}

	if(connect(sockfd, (struct sockaddr *) &hints, sizeof(hints))==-1)
	{
		perror("O servidor final nao conectou!\n");	
		exit(1);
	}
	else
		perror("Conexao com o servidor final feita com sucesso!");

	while(1)
	{
		memset(buffer, 0x0, LEN);
		printf("Ouvindo... ");	
		/*scanf("%s", buffer);
		if(send(sockfd, buffer, sizeof(buffer), 0)) // faz um pedido ao proxy
		{
			if(!strcmp(buffer, "exit"))
				break;

			printf("Aguardando resposta do servidor...\n");
		}
		else
			printf("O servidor nao recebeu a mensagem...\n");*/
		printf("Motor server On...\n");


		if((slen = recv(sockfd, buffer, LEN, 0)) > 0) // Na primeira vez, espera a mensagem de bem-vindo do proxy; Recebe pedidos do proxy
		{
			buffer[slen] = '\0';
			printf("\n=> Comando Recebido: %s\n", buffer);
		}

		//break;

	}
	
	close(sockfd);

	printf("\n\nFinalizando o cliente...\n");
	return 0;
}
