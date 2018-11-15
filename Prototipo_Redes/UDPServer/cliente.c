// UNIVERSIDADE DE BRASÍLIA - 2018/2
// YAN VICTOR DOS SANTOS
// CLIENTE DE TESTE 

#include "refdec.h"

struct sockaddr_in remoto;

#define PORTA 8000
#define _IP "187.58.203.68"
#define LEN 1000000
#define IPARRAYLEN 20
#define QUERYMAXLEN 4096
typedef unsigned char char_type;
char_type* parse_result(char_type* result, int query_len, char_type* ip) {
    /*int offset = -1;

    //offset = query_len + 32;
    int count = 0;
    while(count < 3) {
        offset++;
        if(result[offset] == 0x00C0) {
            count++;
        }
    }

    offset += 32;*/

    int offset = -1;
    int found = 0;
    while(found == 0) {
        offset++;
        if(result[offset] == 0x00C0) {
	printf("ok\n");
            if(result[offset + 3] == 0x0001 && result[offset + 2] == 0x0000) {
                offset = offset + 12;
                found = 1;
            }
        }
    }

    sprintf(ip, "%d.%d.%d.%d\n", 
    result[offset], result[offset + 1], 
    result[offset + 2], result[offset + 3]);

    return ip;
}


int main()
{

	FILE *arq;
	arq=fopen("entrada", "r+");
	printf("================ CLIENTE - UDP =================\n\n");

	int sockfd = socket(AF_INET, SOCK_DGRAM, 0); //UDP
	int len = sizeof(remoto);
	int slen;
	char_type* buffer;
	buffer = (char_type*)malloc((QUERYMAXLEN) * sizeof(char_type));
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
	remoto.sin_addr.s_addr = inet_addr(_IP);
	memset(remoto.sin_zero, 0x0, 8);

	struct sockaddr *cast_remoto = (struct sockaddr *) &remoto;
	int tam_addr_remoto = sizeof(remoto);
    char_type* ip;
	while(1)
	{
		printf("Lendo arquivo\n");
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
		    //ip = (char_type*)malloc(IPARRAYLEN * sizeof(char_type));
			printf("Resposta do servidor: \n%s\n", buffer);
			
		}
		break;
	}


	
	close(sockfd);

	printf("\n\nFinalizando o cliente...\n");
	return 0;
}
