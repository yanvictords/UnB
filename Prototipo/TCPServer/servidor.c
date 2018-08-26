// UNIVERSIDADE DE BRASÍLIA - 2018/2
// YAN VICTOR DOS SANTOS
// SERVIDOR DE TESTE

#include "refdec.h"

struct sockaddr_in servidor;
struct sockaddr_in cli_proxy;
#define PORTA 80
#define LEN 4096
int main()
{
	int proxy, len_proxy = sizeof(cli_proxy);
	int sck_servidor = socket(AF_INET, SOCK_STREAM, 0); // AF_INET = protocolo usado
	int tam_buff;
	char buffer[LEN];

	printf("================ SERVIDOR - TCP =================\n\n");
//--- tenta criar socket pra linux + tcp
	if(sck_servidor == -1)
	{
		printf("Houve problema ao criar socket\n");
		exit(1);
	}
	else
		printf("Socket criado com sucesso!\n");
//--- socket criado acima

//--- preenche struct com informações do seu endereço (servidor que vc esta desenvolvendo)
	servidor.sin_family = AF_INET; // *seu servidor roda em linux
	servidor.sin_port = htons(PORTA); // *seu servidor escutara nesta porte
	memset(servidor.sin_zero, 0x0, 8);

//--- bind() associa o IP do socket criado la em cima à uma porta (literalmente). Aqui sua porta realmente estará aberta para aquele socket
	if(bind(sck_servidor, (struct sockaddr *) &servidor, sizeof(servidor)) == -1 )
	{	
		printf("Problemas ao abrir a porta...\n");
		exit(1);
	}
	else
		printf("Porta %d aberta com sucesso!\n", PORTA);
	
	printf("\nEsperando por conexões: TCP...\n");

	listen(sck_servidor,1); // *fica travado aqui até que um cliente queira falar na porta criada

	printf("\nEscutando na porta %d...\n", PORTA);

	while(1) // A PARTIR DAQUI OCORREM AS TROCAS DE MENSAGENS
	{ 
	if((proxy = accept(sck_servidor, (struct sockaddr*) &cli_proxy, &len_proxy)) == -1) // apos falar, o cliente tenta conexao com o servidor
	{ // *proxy é o cliente do nosso servidor
		//printf("A conexao nao foi efetuada com sucesso!\n");
		perror("A conexao nao foi efetuada com sucesso!\n");
	}
	else
		printf("A conexao foi efetuada com sucesso!\n");

// --- SOCKET -> PORTA -> SERVER ONLINE ESCUTANDO -> CLIENTE FALA -> CLIENTE SE CONECTA VIA TCP -> TROCAM MENSAGENS ABAIXO

		memset(buffer, 0x0, LEN);
		printf("Esperando novo cliente...\n");
		if((tam_buff = recv(proxy, buffer, LEN, 0)) > 0) // *RECV: FICA TRAVADO AQUI ATÉ RECEBER UMA MENSAGEM DO CLIENTE (proxy), salva em "buffer"
		{
			printf("=> Mensagem recebida do proxy: %s\n\n", buffer);
			buffer[tam_buff] = '\0';

			if(!strcmp(buffer, "kill")) // se a mensagem do cliente for exit, fecha a conexão			
				break;
			if(!strcmp(buffer, "exit")) // se a mensagem do cliente for exit, fecha a conexão
			{
				if((proxy = accept(sck_servidor, (struct sockaddr*) &cli_proxy, &len_proxy)) == -1)
					perror("A conexao nao foi efetuada com sucesso!\n");
				else
					printf("A conexao foi efetuada com sucesso!\n");	
			}
			else
			{
				char resposta[LEN];
				printf("Digite algo para o cliente: ");
				fgets(resposta, sizeof(resposta), stdin);
				resposta[sizeof(resposta)]='\0';
				if(send(proxy, resposta, strlen(resposta), 0)) // *AQUI ELE RESPONDE ALGUMA COISA PARA O CLIENTE, DE VOLTA (proxy). Não fica travado
				{
					//printf("A requisicao foi respondida com sucesso!\n");
					perror("\nSERVIDOR: A requisicao foi respondida com sucesso!\n");
					printf("Mensagem enviada: %s\n\n", resposta);
					close(proxy);

				}
				else
				{
					//printf("Problemas ao responder a requisicao!\n");
					perror("SERVIDOR: Problemas ao responder a requisicao!\n");
				}
			}
		} //AQUI ELE VOLTA PARA LOOP INFINITO, E VAI PARA O RECV FICAR TRAVADO ESPERANDO OUTRA MENSAGEM DO CLIENTE.
	}

//	close(proxy);
	close(sck_servidor);

	printf("\n\nFinalizando o servidor...\n");
	return 0;
}
