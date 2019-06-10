// UNIVERSIDADE DE BRASÍLIA - 2018/2
// YAN VICTOR DOS SANTOS
// CLIENTE DE TESTE 

#include "refdec.h"
struct sockaddr_in remoto;
struct sockaddr_in source;

#define PORTA 3000
#define PORTA_ORIGEM 4000
#define _IP "127.0.0.1"
// #define _IP "192.168.25.18"
#define LEN 65536
#define IPARRAYLEN 20
#define QUERYMAXLEN 4096


void printHost(struct sockaddr_in * host)
{
	char node_addr[4096];
	inet_ntop(AF_INET, &(host->sin_addr), node_addr, INET_ADDRSTRLEN);

	printf("\nPrint Host: [%s:%d]\n", node_addr, htons(host->sin_port));
}
int main()
{

	FILE *arq;
	arq=fopen("entrada", "r+");
	printf("================ CLIENTE - UDP =================\n\n");

	int sockfd = socket(AF_INET, SOCK_DGRAM, 0); //UDP

	int len = sizeof(remoto);
	int slen;
	unsigned char* buffer;
	buffer = (unsigned char*)malloc((QUERYMAXLEN) * sizeof(unsigned char));
	if(sockfd == -1)
	{
		perror("O socket nao foi criado com sucesso!\n");
		exit(1);	
	}
	else
	{
		printf("O socket foi criado com sucesso!\n");
	}

	source.sin_family = AF_INET;
	source.sin_port = htons(PORTA_ORIGEM);
	memset(source.sin_zero, 0x0, 8);

   if (bind(sockfd, (struct sockaddr *) &source, sizeof(source)) < 0) {
        perror("bind");
        exit(1);
    }

	remoto.sin_family = AF_INET;
	remoto.sin_port = htons(PORTA);
	remoto.sin_addr.s_addr = inet_addr(_IP);
	memset(remoto.sin_zero, 0x0, 8);

	struct sockaddr *cast_remoto = (struct sockaddr *) &remoto;
	int tam_addr_remoto = sizeof(remoto);
    unsigned char* ip;
	while(1)
	{
//		printf("Lendo arquivo\n");
//		fread(buffer, (QUERYMAXLEN) * sizeof(char_type), 1, arq);

		printf("Enviando a palavra teste\n");

		if(sendto(sockfd, "teste", sizeof("teste"), 0, cast_remoto, tam_addr_remoto)) // faz um pedido ao proxy
		{
			printf("\nAguardando resposta do servidor...\n");
		}
		else
			printf("O servidor nao recebeu a mensagem...\n");
		if((slen = recvfrom(sockfd, buffer, LEN, 0, cast_remoto, &tam_addr_remoto)) > 0) // Na primeira vez, espera a mensagem de bem-vindo do proxy; Recebe pedidos do proxy
		{
			buffer[slen] = '\0';
			printf("buffer: %s\n", buffer);
			printHost((struct sockaddr_in *) cast_remoto);
		}
		// break;
		getchar();
	}


	
	close(sockfd);

	printf("\n\nFinalizando o cliente...\n");
	return 0;
}
