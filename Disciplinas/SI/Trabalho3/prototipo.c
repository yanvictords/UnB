#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*-------- Funcao de informacoes sobre o restaurante------*/
void sobre(){
	system("clear||cls");
	FILE *seta1;
	seta1 = fopen("mesas.txt", "r+");
	char dados[100][3];

	printf("\n------------------- Sobre nos -------------------\n");
	fscanf(seta1, "\n%[^\n]s", dados[0]);
	printf("\n|%s", dados[0]);
	fscanf(seta1, "\n%[^\n]s", dados[1]);
	printf("\n|Fone: %s\n", dados[1]);
	fscanf(seta1, "\n%[^\n]s", dados[2]);
	printf("|Endereco: %s\n", dados[2]);
	fclose(seta1);
	printf("\n-------------------------------------------------\n");
	printf("\nPara voltar pressione uma <enter>...");
	getchar();
	getchar();
}
/*------- FIM OPCAO SOBRE ------*/


/*-------- INTERFACE DO CLIENTE---------*/
void menu(char restaurante[]){
system("clear||cls");
printf("------- Restaurante %s --------\n", restaurante);
printf("|1. Reservar uma mesa              |\n");
	printf("|2. Sobre nos                      |          \n");
	printf("|3. Sair                           |\n");
	printf("------------------------------------\n");
	printf("Opcao:");
}

/*-------- FIM DA INTERFACE DO CLIENTE---------*/




int main(){
char restaurante[100], lixo[100], nome[100], login[100]="admin", senha[100]="admin", endereco[100];
int interface, x=0, id, dia, mes, mesa, count=0, month, day, qtd, i, nmesa, rg, k;
system("clear||cls");

/*-------- ESCOLHA DO TIPO DE USUARIO---------*/

printf("|-------- INTERFACE DO USUARIO -------|\n|1. Cliente                           |\n|2. Setor de Atendimento ao Cliente   |\n|-------------------------------------|\nOpcao:");
scanf("%d", &interface);
while((interface>2)||(interface<1)){
	printf("Opcao invalida. Por favor, digite novamente:");
	scanf("%d", &interface);
}

/*-------- FIM DA ESCOLHA DO TIPO DE USUARIO---------*/

/*-------- OPCAO DA INTERFACE DO CLIENTE --------*/

if(interface==1){
while(x!=3){
	FILE *seta;
	seta = fopen("mesas.txt", "r+");
	fscanf(seta, "%[^\n]\n", restaurante);
	count=0;
	menu(restaurante); /*menu principal*/

	scanf("%d", &x);
	while((x>3)||(x<1)){
		printf("Opcao invalida. Por favor, digite novamente:");
		scanf("%d", &x);
	}

	if(x==1){ /*RESERVAR UMA MESA*/
		system("clear||cls");
		printf("*** SGRO | %s***\n\n", restaurante);
		printf("Pesquisar por mesas disponiveis:\n");
		printf("|Dia:");
		scanf("%d", &day);
		while((day>31)||(day<1)){
			printf("Dia invalido. Por favor, digite novamente:");
			scanf("%d", &day);
		}
		printf("|Mes:");
		scanf("%d", &month);
		while((month>12)||(month<1)){
			printf("Mes invalido. Por favor, digite novamente:");
			scanf("%d", &month);
		}		

		system("clear||cls");
		printf("*** SGRO | %s***\n\n", restaurante);
		fscanf(seta, "%[^\n]\n", lixo);
		fscanf(seta, "%[^\n]\n", lixo);
		fscanf(seta, "%s %s %d %[^\n]\n", lixo, lixo, &qtd, lixo); /* Pega a quantidade de mesas */
		fscanf(seta, "%[^\n]\n", lixo);
		printf("Mesas disponiveis:\n");
		int disp[qtd];
		for(k=0;k<qtd;k++)
			disp[k]=0;
		while(!feof(seta)){
			fscanf(seta, "%d	%d	%d	%d	%[^\n]\n", &id, &dia, &mes, &mesa, lixo); 

			if((month==mes)&&(day==dia)){ /*Mesa reservada nesta dada */
				count++;
				disp[mesa-1]=1;
			}
		}

		
		if(count==qtd){ printf("0\n");
			printf("...Mesas indisponiveis para esta data...\n\n");
			printf("\nPara voltar pressione uma <enter>...");
			getchar(); getchar();
		}else{
			for(k=0;k<qtd;k++){
				if(disp[k]==0)
					printf("|Mesa |%d|\n", k+1);
			}
			
			printf("\nReservar uma mesa?\n");
			printf("|1. Sim\n");
			printf("|2. Nao\n");
			printf("Opcao:");
			scanf("%d", &i);
			while((i>2)||(i<1)){
				printf("Opcao invalida. Tente novamente:");
				scanf("%d", &i);
			}
			if(i==1){ /*RESERVANDO UMA MESA*/

				printf("\n|------------- Reserve uma mesa ---------------|\n");
				setbuf(stdin,NULL);
				printf("|Digite seu primeiro nome: ");
				scanf("%[A-Z a-z 0-9]s", nome);
				printf("|RG(id): ");
				scanf("%d", &rg);
				printf("|Numero da mesa: ");
				scanf("%d", &nmesa);
				while((disp[nmesa-1]==1)||(nmesa>qtd)||(nmesa<1)){
					printf("Mesa indisponivel. Por favor, digite uma mesa disponivel:");
					scanf("%d", &nmesa);
				}
				printf("|----------------------------------------------|\n");
				FILE *seta1;
				seta1=fopen("mesas.txt", "a");
				fprintf(seta1, "%d	%d	%d	%d	%s\n", rg, day, month, nmesa, nome);
				printf("\n..........Reserva efetuada com sucesso!.........\n\n");
				printf("...Pressione <Enter> para gerar o comprovante...");
				getchar();
				getchar();
				system("clear||cls");
				
				FILE* seta5 = fopen("mesas.txt", "r+");
				fscanf(seta5, "\n%[^\n]s", lixo);
				fscanf(seta5, "\n%[^\n]s", lixo);
				fscanf(seta5, "\n%[^\n]s", endereco);
				fclose(seta5);				

				printf("-------------------------------------------------\n");
				printf("|**COMPROVANTE DE RESERVA**\n|\n");
				printf("|Nome: %s\n|RG: %d\n|Mesa: |%d|\n|Data: %d/%d\n|Restaurante %s\n|Endereco: %s\n", nome, rg, nmesa, day, month, restaurante, endereco);
				printf("-------------------------------------------------\n");
				/*GERANDO O COMPROVANTE.TXT*/
				seta1=fopen("comprovante.txt", "w+");
				fprintf(seta1,"-------------------------------------------------\n");
				fprintf(seta1,"|**COMPROVANTE DE RESERVA**\n|\n");
				fprintf(seta1, "|Nome: %s\n|RG: %d\n|Mesa: |%d|\n|Data: %d/%d\n|Restaurante %s\n|Endereco: %s\n", nome, rg, nmesa, day, month, restaurante, endereco);
				fprintf(seta1,"-------------------------------------------------\n");
				printf("\nUm comprovante.txt foi gerado com sucesso!\n");
				printf("\nPara voltar pressione <Enter>...\n");
				getchar(); 
				
			}
			
		}

	}
	if(x==2)	/*MOSRAR INFORMAÇÕES DO RESTAURANTE*/
		sobre();
}


/*-------- FIM DA ESCOLHA DA INTERFACE DO CLIENTE---------*/



/*-------- ESCOLHA DA INTERFACE DOS FUNCIONARIOS DO RESTAURANTE ---------*/
}else{
	char nomec[100], forma[20], login2[100], senha2[100];
	int rgc, flag=0, valor, q=1, l, diac, mesc, mesac;

	/*TELA DE LOGIN*/
	
	system("clear||cls");
	printf("------------------- SETOR DE ATENDIMENTO -------------------\n\n");
	printf("Login:");
	scanf("%s", login2);
	printf("Senha:");
	scanf("%s", senha2);
	l=1;
	while(((strcmp(senha2,senha))||(strcmp(login2,login)))&&(l!=2)){
		printf("\nLogin ou senha errada\nTentar mais uma vez?\n\n|1. Sim\n|2. Nao\nOpcao:");
		scanf("%d", &l);
		while((l<1)||(l>2)){
			printf("Opcao invalida. Tente novamente:");
			scanf("%d", &l);
		}
		if(l==1){
			system("clear||cls");
	printf("------------------- SETOR DE ATENDIMENTO -------------------\n\n");
			printf("Login:");
			scanf("%s", login2);
			printf("Senha:");
			scanf("%s", senha2);		
		}
	}

	if((!strcmp(senha2,senha))&&(!strcmp(login2,login))){
	while(q!=3){
	flag=0;
	
	/* FIM DA TELA DE LOGIN */

	/* INTERFACE DO FUNCIONARIO DO RESTAURANTE */
	system("clear||cls");
	printf("------------------- Bem-vindo ao SGRO -------------------\n\n");
	printf("|1. Ver todas as reservas\n|2. Verificar Comprovante do cliente\n|3. Sair\nOpcao:");
	scanf("%d", &q);
	while((q<1)||(q>3)){
		printf("Opcao invalida. Por favor, digite novamente:");
		scanf("%d", &q);	
	}

	if(q==1){  /*VER TODAS AS RESERVAS REGISTRADAS*/
		system("clear||cls");
		FILE *seta2;
		seta2 = fopen("mesas.txt", "r+");
		fscanf(seta2, "%[^\n]\n", lixo);
		fscanf(seta2, "%[^\n]\n", lixo);
		fscanf(seta2, "%[^\n]\n", lixo);
		fscanf(seta2, "%[^\n]\n", lixo);
		fscanf(seta2, "%[^\n]\n", lixo);
		printf("*** RESERVAS REGISTRADAS ***\n");
		while(!feof(seta2)){
			fscanf(seta2, "%d	%d	%d	%d	%[^\n]\n", &id, &dia, &mes, &mesa, lixo);  
			printf("\n|Nome do Cliente: %s\n", lixo);
			printf("|RG: %d\n", id);
			printf("|Mesa: |%d|\n", mesa);
			printf("|Data: %d/%d\n", dia, mes);
		}
		printf("\nPressione <Enter> para voltar...");
		getchar();getchar();
	}
	
	if(q==2){	/*VERIFICAR O COMPROVANTE DO CLIENTE*/
	system("clear||cls");
	printf("-------------- Verificar reserva do Cliente ------------\n");
	printf("Pressione <Enter> para verificar o Comprovante do cliente...\n");
	getchar();
	getchar();
	printf("Conferindo dados...\n");
	getchar();
	FILE *seta1;
	seta1=fopen("comprovante.txt", "r+");
	if(seta1==NULL){
	printf("\nO cliente nao possui comprovante!\n\n");	
	exit(1);	
	}
	fscanf(seta1, "%[^\n]\n", lixo);
	fscanf(seta1, "%[^\n]\n", lixo);
	fscanf(seta1, "%[^\n]\n", lixo);
	fscanf(seta1, "%s %[^\n]\n", lixo, nomec);
	fscanf(seta1, "%s %d", lixo, &rgc);
	fscanf(seta1, "\n%s |%d|\n", lixo, &mesac);
	fscanf(seta1, "%s %d/%d", lixo, &diac, &mesc);


	FILE *seta;
	seta = fopen("mesas.txt", "r+");
	fscanf(seta, "%[^\n]\n", lixo);
	fscanf(seta, "%[^\n]\n", lixo);
	fscanf(seta, "%[^\n]\n", lixo);
	fscanf(seta, "%[^\n]\n", lixo);
	fscanf(seta, "%[^\n]\n", lixo);
	while(!feof(seta)){
		fscanf(seta, "%d	%d	%d	%d	%[^\n]\n", &id, &dia, &mes, &mesa, lixo); 
		if((rgc==id)&&(!strcmp(nomec,lixo))&&(diac==dia)&&(mesc==mes)&&(mesa==mesac)){  
			printf("\n**Reserva encontrada**\n");
			printf("-----------------------------------");
			printf("\n|Nome do Cliente: %s\n", lixo);
			printf("|RG: %d\n", id);
			printf("|Mesa: |%d|\n", mesa);
			printf("|Data: %d/%d\n", dia, mes);
			printf("-----------------------------------\n");
			flag=1;


			if(flag!=0){ /*REGISTRANDO O PAGAMENTO DO CLIENTE E GERANDO O RELATORIO*/
		printf("\n...Pressione <Enter>...\n");
		getchar();
		system("clear||cls");
		printf("Desejar registrar o pagamento do cliente?\n");
		printf("|1. Sim\n|2. Nao\nOpcao:");
		int y;
		setbuf(stdin,NULL);
		scanf("%d",&y);
		while((y<1)||(y>2)){
			printf("Opcao invalida. Tente novamente:");
			scanf("%d", &y);
		}
		if(y==1){
		system("clear||cls");
		printf("...Registrando o Pagamento do(a) Cliente %s...\n", lixo);
		getchar();
		getchar();
		printf("Forma de pagamento:");
		scanf("%[A-Z a-z 0-9]s", forma);
		printf("Valor do pagamento(Reais):");
		scanf("%d", &valor);
		FILE *seta3=fopen("Relatorio.txt", "r+");
		if(seta3==NULL){
			char lixo2[100];
			FILE* seta5 = fopen("mesas.txt", "r+");
				fscanf(seta5, "\n%[^\n]s", lixo2);
				fscanf(seta5, "\n%[^\n]s", lixo2);
				fscanf(seta5, "\n%[^\n]s", endereco);
				fclose(seta5);
			seta3 = fopen("mesas.txt", "r+");
			fscanf(seta3, "%s", restaurante); 
			seta3=fopen("Relatorio.txt", "w+");
			fprintf(seta3, "Relatorio geral criado pelo Sistema GRO\nCriado em: %d/%d as %s\nDescricao: Pagamentos de clientes com reserva\nRestaurante %s\n%s\n\n",dia, mes,__TIME__,restaurante, endereco);
			fprintf(seta3, "---------------------------------\n");
			fprintf(seta3, "|RG Cliente: %d\n", id);
			fprintf(seta3, "|Nome Cliente: %s\n", lixo);
			fprintf(seta3, "|Mesa reservada: |%d|\n", mesa);
			fprintf(seta3, "|Forma de pagamento: %s\n", forma);
			fprintf(seta3, "|Valor do pagamento(Reais): %d\n", valor);
			fprintf(seta3, "|DATA : %d/%d HORA: %s\n",dia, mes,__TIME__);
			fprintf(seta3, "---------------------------------\n");
			fprintf(seta3,"\n");
			printf("\nRelatorio.txt foi criado com sucesso!\n");
			printf("\nPressione <Enter> para voltar...\n");
			getchar();getchar();		
		}else{
			seta1=fopen("Relatorio.txt", "a");
			fprintf(seta1, "---------------------------------\n");
			fprintf(seta1, "|RG Cliente: %d\n", id);
			fprintf(seta1, "|Nome Cliente: %s\n", lixo);
			fprintf(seta1, "|Mesa reservada: |%d|\n", mesa);
			fprintf(seta1, "|Forma de pagamento: %s\n", forma);
			fprintf(seta1, "|Valor do pagamento(Reais): %d\n", valor);
			fprintf(seta1, "|DATA : %d/%d HORA: %s\n",dia, mes,__TIME__);
			fprintf(seta1, "---------------------------------\n");
			fprintf(seta1,"\n");
			printf("\nRelatorio.txt foi criado com sucesso!\n");
			printf("\nPressione <Enter> para voltar...\n");
			getchar();getchar();
		}
		}
		
	}

		/* FIM DO REGISTRANDO O PAGAMENTO DO CLIENTE E GERANDO O RELATORIO.TXT*/

		}
	}
	if(flag==0){ /*CASO O COMPROVANTE NAO SEJA VALIDO*/
		printf("------------------------------------\n");
		printf("| **A reserva NAO foi encontrada** |\n");
		printf("------------------------------------\n\n");
		printf("Pressione <Enter>...");
		getchar();
	}
	}
}

}
}

/*-------- FIM DA ESCOLHA DA INTERFACE DOS FUNCIONARIOS DO RESTAURANTE ---------*/

printf("\n...Fim de processo...\n");
return 0;
}
