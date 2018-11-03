// UNIVERSIDADE DE BRASÍLIA - 2018/2
// YAN VICTOR DOS SANTOS
// SERVIDOR DE TESTE

#include "refdec.h"
#include "dns_decoder.h"

struct sockaddr_in servidor;
#define PORTA 2000
#define LEN 65536
int main()
{
	int sck_servidor = socket(AF_INET, SOCK_DGRAM, 0); // AF_INET = protocolo usado
	int tam_buff;
	char buffer[LEN];

	printf("================ SERVIDOR - UDP =================\n\n");
//--- tenta criar socket pra linux + UDP
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

	struct sockaddr *cast_addr_serv = (struct sockaddr *) &servidor; // cast do endereço para struct genérica
	int tam_addr_serv = sizeof(servidor); // tamanho da struct

//--- bind() associa o IP do socket criado la em cima à uma porta (literalmente). Aqui sua porta realmente estará aberta para aquele socket
	if(bind(sck_servidor, cast_addr_serv, tam_addr_serv) == -1 )
	{	
		printf("Problemas ao abrir a porta...\n");
		exit(1);
	}
	else
		printf("Portas %d aberta com sucesso!\n", PORTA);

			int cont =0 ;

	while(1) // A PARTIR DAQUI OCORREM AS TROCAS DE MENSAGENS
	{ 
		memset(buffer, 0x0, LEN);
		printf("Esperando por cliente...\n");
		if((tam_buff = recvfrom(sck_servidor, buffer, LEN, 0, (struct sockaddr*)&servidor, &tam_addr_serv)) > 0) // *RECV: FICA TRAVADO AQUI ATÉ RECEBER UMA MENSAGEM DO CLIENTE, salva em "buffer"
		{
		//	pkgAnalyzer(servidor, buffer);
	        //printAllCounters();
			printf("Chegou\n");
			sendto(sck_servidor, "DEU CERTO", sizeof("DEU CERTO"), 0, (struct sockaddr*)&servidor, tam_addr_serv);
		} //AQUI ELE OLTA PARA LOOP INFINITO, E VAI PARA O RECV FICAR TRAVADO ESPERANDO OUTRA MENSAGEM DO CLIENTE.
	}
	close(sck_servidor);

	printf("\n\nFinalizando o servidor...\n");
	return 0;
}
