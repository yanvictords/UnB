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
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0); //UDP
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

	struct sockaddr *cast_remoto = (struct sockaddr *) &remoto;
	int tam_addr_remoto = sizeof(remoto);

	while(1)
	{
		memset(buffer, 0x0, LEN);
		printf("Peca algo ao servidor: ");
		scanf("%s", buffer);
		if(sendto(sockfd, buffer, strlen(buffer), 0, cast_remoto, tam_addr_remoto)) // faz um pedido ao proxy
		{
			if(!strcmp(buffer, "exit"))
				break;
			printf("Aguardando resposta do servidor...\n");
		}
		else
			printf("O servidor nao recebeu a mensagem...\n");
		if((slen = recvfrom(sockfd, buffer, LEN, 0, cast_remoto, &tam_addr_remoto)) > 0) // Na primeira vez, espera a mensagem de bem-vindo do proxy; Recebe pedidos do proxy
		{
			buffer[slen] = '\0';
			printf("\n=> Mensagem Recebida do proxy: %s\n", buffer);
		}
	}
	
	close(sockfd);
	printf("Cliente encerrado!\n");

	printf("\n\nFinalizando o cliente...\n");
	return 0;
}
