// UNIVERSIDADE DE BRASÍLIA - 2018/2
// YAN VICTOR DOS SANTOS
// CLIENTE DE TESTE 

#include "refdec.h"

struct sockaddr_in remoto;

#define PORTA 2001
#define LEN 4096
int main()
{

	printf("================ CLIENTE =================\n\n");

	printf("Sou um cliente\n");
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	int len = sizeof(remoto);
	int slen;
	char buffer[LEN];
	if(sockfd == -1)
	{
		perror("O socket nao foi criado com sucesso!\n");
		exit(1);	
	}
	else
	{
		printf("O socket foi criado com sucesso!\n");
	}
	
	remoto.sin_family = AF_INET;
	remoto.sin_port = htons(PORTA);
	remoto.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(remoto.sin_zero, 0x0, 8);

	if(connect(sockfd, (struct sockaddr*)&remoto, len)==-1)
	{
		perror("O servidor nao conectou!\n");	
		exit(1);
	}
	else
	{
		perror("Conexao feita com sucesso!");
	}

	while(1)
	{
		if((slen = recv(sockfd, buffer, LEN, 0)) > 0)
		{
			buffer[slen] = '\0';
			printf("\n=> Mensagem Recebida do proxy: %s\n", buffer);
		}
		memset(buffer, 0x0, LEN);
		printf("Peca algo ao servidor: ");
		scanf("%s", buffer);
		if(send(sockfd, buffer, strlen(buffer), 0))
		{
			if(!strcmp(buffer, "exit"))
				break;
			printf("Aguardando resposta do servidor...\n");
		}
		else
			printf("O servidor nao recebeu a mensagem...\n");
		
	}
	
	close(sockfd);
	printf("Cliente encerrado!\n");

	printf("\n\nFinalizando o cliente...\n");
	return 0;
}
