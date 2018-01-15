#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define PP 5

typedef struct sistema Sistem;
struct sistema{
    int cod[11];
    char descricao[11][50];
    int unidades[11];
    float periodo[11][6];
};
/* Funcao Menu Busca*/
int menu(int x){
printf("\n*-------- Controle de Estoque - BUSCA ONLINE --------*\n");
printf("1 - Consultar produtos\n2 - Gerar relatorio\n3 - Exit\n");
printf("*----------------------------------------------------*\n~>ACAO:");
scanf("%d", &x);

while(x>3||x<1){
printf("\n*-------- Controle de Estoque - BUSCA ONLINE --------*\n");
printf("1 - Consultar produtos\n2 - Gerar relatorio\n3 - Exit\n");
printf("*----------------------------------------------------*\n~>");
printf("Opcao invalida! Tente outra opcao:");
 scanf("%d", &x);
}
return x;
}
/* Fim Funcao Menu */



/*Calcula total para media*/
float calcula_media(int total[], Sistem *estoque, int i){
	int j;
	for(j=0;j<5;j++)	
		total[i] = total[i]+estoque->periodo[i][j];


return (float) total[i]/5;
}
/*Fim Calcula total para media*/

void main_media(float media[], int total[], Sistem *estoque){
	int i;
	for(i=0;i<10;i++){
		total[i]=0;
		media[i] = calcula_media(total, estoque, i); /*calcula a media*/	
	}
}


/*Calcula desvio padrao*/
float desvio_padrao(Sistem *estoque, float temp, float media[], int i, int n){
	float temp2;
	int j;
	for(j=0;j<5;j++){
		temp2 = estoque->periodo[i][j]-media[i];  /*(Xn - Xmed)*/
		temp2 = temp2*temp2; 	/*(Xn - Xmed)²*/
		temp = temp + temp2;   /* Somatorio de 1 até n de (Xn - Xmed)²*/
	}

return (float) sqrt(temp/n);
}
/*Fim calcula desvio padrao*/


void main_desvio_padrao(Sistem *estoque, float temp, float media[], int n, float dp[]){
	int i;
	for(i=0;i<10;i++){
		temp=0;
		dp[i] = desvio_padrao(estoque, temp, media, i, n);/*Raiz do Somatorio de 1 até n de (Xn - Xmed)² sobre (N-1) */
	}
}


/*Calcula Estoque minimo*/
float estoque_minimo(float FS, float dp[], int i, int LT){
	float temp, temp2;
	temp = FS*dp[i]; /* (FS x Desvio padrao)*/
	temp2 =  (float) sqrt(LT)/PP; /* (Raiz de LT, dividido por PP)  */

return temp*temp2;
}
/*Fim calcula Estoque minimo*/

void main_estoque_minimo(float Em[], float FS, float dp[], float LT){
	int i;
	for(i=0;i<10;i++)
		Em[i]= estoque_minimo(FS, dp, i, LT);
}



/*Ver Produtos*/
int ver_produtos(Sistem *estoque, int y, int total[], float media[], float dp[], float Em[], float temp, int n, float FS, float LT){
int i, per, flag=0, t;
float demanda;
int k=0;



while(k!=6){
	if(flag==0){
	printf("\n");
	printf("\n*----- ALL PRODUCTS -----*\n");
	for(i=0;i<10;i++){
		if(estoque->cod[i]<10){
			printf("|CODE|: %d   |Product|: %s\n", estoque->cod[i], estoque->descricao[i]);
		}else{
			printf("|CODE|: %d  |Product|: %s\n", estoque->cod[i], estoque->descricao[i]);
		}
	}
	printf("\n~>CODIGO DO PRODUTO:");
	scanf("%d", &y);
	while(y<1||y>10){
		printf("Codigo nao encontrado. Tente outro:");
		scanf("%d", &y);
	}
	}
	printf("\n*----- %s -----*\n", estoque->descricao[y-1]);
	printf("|1 - Unidades e Demanda\n|2 - Total e Media\n|3 - Estoque minimo e Desvio Padrao\n|4 - Alterar demanda\n|5 - Consultar outro produto\n|6 - Voltar ao menu principal\n");
	printf("*------------------------*\n~>ACAO:");
	scanf("%d", &k);
	while(k<1||k>6){
		printf("\n*----- %s -----*\n", estoque->descricao[y-1]);
		printf("|1 - Unidades e Demanda\n|2 - Total e Media\n|3 - Estoque minimo e Desvio Padrao\n|4 - Alterar demanda\n|5 - Consultar outro produto\n|6 - Voltar ao menu principal\n");
		printf("*------------------------*\n~>");
		printf("Opcao invalida, digite outra opcao:");
		scanf("%d", &k);
	}



	if(k==1){
		printf("\n...Buscando Unidades... Pressione <Enter>\n");
		getchar();getchar();
		printf("\n...Buscando Demanda... Pressione <Enter>\n");getchar();
		printf("\n*----- %s -----*", estoque->descricao[y-1]);
		printf("\nUnidades: %d\n", estoque->unidades[y-1]);
		for(i=0;i<5;i++){
			printf("%do Periodo: %.3f\n", i+1, estoque->periodo[y-1][i]);		
		}
		printf("\nDemanda e Unidades encontradas com sucesso! Pressione <Enter>");
		getchar();
		printf("\n||1 - Consultar outro produto\n||2 - Continuar a consultar %s\n||3 - Voltar ao menu principal\n", estoque->descricao[y-1]);
		scanf("%d", &t);
		while(t<1||t>3){
			printf("Opcao invalida! Tente outra opcao:");
			scanf("%d", &t);
		}
		if(t==1)
			flag=0;
		if(t==2)
			flag=1;
		if(t==3)
			k=6;
	}


	if(k==2){
		printf("\n...Calculando o Total... Pressione <Enter>\n");
		getchar(); getchar();	
		printf("\n...Calculando a Media... Pressione <Enter>\n");
		getchar();
		printf("\n*----- %s -----*\n", estoque->descricao[y-1]);
		printf("Total: %d\nMedia: %.3f\n", total[y-1], media[y-1]);
		printf("\nCalculado com sucesso! <Enter>");	
		getchar();	
		printf("\n||1 - Consultar outro produto\n||2 - Continuar a consultar %s\n||3 - Voltar ao menu principal\n", estoque->descricao[y-1]);
		scanf("%d", &t);
		while(t<1||t>3){
			printf("Opcao invalida! Tente outra opcao:");
			scanf("%d", &t);
		}
		if(t==1)
			flag=0;
		if(t==2)
			flag=1;
		if(t==3)
			k=6;
	}


	if(k==3){
		printf("\n...Calculando o Desvio Padrao... Pressione <Enter>\n");
		getchar();getchar();
		printf("\n...Calculando o Estoque Minimo... Pressione <Enter>\n"); 
		getchar();
		printf("\n*----- %s -----*\n", estoque->descricao[y-1]);
		printf("Estoque minimo: %.3f\nDesvio Padrao: %.3f\n", Em[y-1], dp[y-1]);

		printf("\nCalculado com sucesso! <Enter>");	
		getchar();	


		printf("\n||1 - Consultar outro produto\n||2 - Continuar a consultar %s\n||3 - Voltar ao menu principal\n", estoque->descricao[y-1]);
		scanf("%d", &t);
		while(t<1||t>3){
			printf("Opcao invalida! Tente outra opcao:");
			scanf("%d", &t);
		}
		if(t==1)
			flag=0;
		if(t==2)
			flag=1;
		if(t==3)
			k=6;
	}
	if(k==4){
		printf("Digite o periodo que deseja alterar:");
		scanf("%d", &per);
		while(per>5||per<1){
			printf("Periodo nao existe. Tente outro:");
			scanf("%d", &per);
		}
		printf("Digite a nova demanda:");
		scanf("%f", &demanda);
		estoque->periodo[y-1][per-1] = demanda;
		printf("\nNova demanda: %.3f\n", estoque->periodo[y-1][per-1]);
		main_media(media, total, estoque); /*Calcula media*/
main_desvio_padrao(estoque, temp, media, n, dp); /*Calcula o desvio padrao*/
main_estoque_minimo(Em, FS, dp, LT); /* Calculo do Estoque minimo */

		printf("\n||1 - Consultar outro produto\n||2 - Continuar a consultar %s\n||3 - Voltar ao menu principal\n", estoque->descricao[y-1]);
		scanf("%d", &t);
		while(t<1||t>3){
			printf("Opcao invalida! Tente outra opcao:");
			scanf("%d", &t);
		}
		if(t==1)
			flag=0;
		if(t==2)
			flag=1;
		if(t==3)
			k=6;
	}		
	if(k==5)
		flag=0;
	
	}
return k;
}
/*Fim ver Produtos*/


void arquivo_relatorio(FILE *gerar, Sistem estoque, int total[], float media[], float Em[], char firstline[100]){
	int i;
	struct tm *local;
time_t t= time(NULL);
local = localtime(&t);

	fprintf(gerar,"Relatorio gerado em: %s as %d:%d:%d\n\n", __DATE__,local->tm_hour,local->tm_min,local->tm_sec );
	fprintf(gerar, "%s	\n", firstline);
	for(i=0;i<10;i++){
		if(strlen(estoque.descricao[i])>7){
		fprintf(gerar, "%d		%s		%d		%.1f		%.1f		%.1f		%.1f		%.1f", estoque.cod[i], estoque.descricao[i], estoque.unidades[i], estoque.periodo[i][0], estoque.periodo[i][1], estoque.periodo[i][2], estoque.periodo[i][3], estoque.periodo[i][4]);
	fprintf(gerar, "\n");

		}else{
		fprintf(gerar, "%d		%s			%d		%.1f		%.1f		%.1f		%.1f		%.1f", estoque.cod[i], estoque.descricao[i], estoque.unidades[i], estoque.periodo[i][0], estoque.periodo[i][1], estoque.periodo[i][2], estoque.periodo[i][3], estoque.periodo[i][4]);
	fprintf(gerar, "\n");
		}
	}
		fprintf(gerar, "\nCODIGO	DESCRICAO	TOTAL	MEDIA	ESTOQUE MINIMO");
	for(i=0;i<10;i++){
		if(strlen(estoque.descricao[i])>7){
			if(total[i]>999){
		fprintf(gerar, "\n%d		%s	%d	%.1f		%.3f",estoque.cod[i], estoque.descricao[i], total[i], media[i], Em[i]);
			}else{
				fprintf(gerar, "\n%d		%s	%d		%.1f		%.3f",estoque.cod[i], estoque.descricao[i], total[i], media[i], Em[i]);
			}

		}else{
		if(total[i]>999){
			fprintf(gerar, "\n%d		%s		%d	%.1f		%.3f",estoque.cod[i], estoque.descricao[i], total[i], media[i], Em[i]);
		}else{
			fprintf(gerar, "\n%d		%s		%d		%.1f		%.3f",estoque.cod[i], estoque.descricao[i], total[i], media[i], Em[i]);
		}
		}
	}
	}

/* ---------------------------------------------------- */
int main(){
int i, total[10], x=0, y=0;
float dp[10], media[10], temp=0, n, FS = 1.6450, Em[10], LT=2;
char firstline[100]; /* lixo da primeira linha */
FILE *arq = fopen("estoque.txt", "r+");
FILE *gerar = fopen("Relatorio.txt", "w+");
Sistem estoque; /* Criando a estrutura */

fscanf(arq, "%[^\n]s", firstline); /*Pula a primeira linha do arquivo*/

	for(i=0;i<10;i++){
	 fscanf(arq, "%d	%s		%d		%f		%f		%f		%f		%f", &estoque.cod[i], estoque.descricao[i], &estoque.unidades[i], &estoque.periodo[i][0], &estoque.periodo[i][1], &estoque.periodo[i][2], &estoque.periodo[i][3], &estoque.periodo[i][4]);
	}
/*Fim do progresso de armazenamento na estrutura de dados*/


n = 5-1; /*total de periodos -1*/
main_media(media, total, &estoque); /*Calcula media*/
main_desvio_padrao(&estoque, temp, media, n, dp); /*Calcula o desvio padrao*/
main_estoque_minimo(Em, FS, dp, LT); /* Calculo do Estoque minimo */


printf("\n");

/* ----------------------BUSCA ONLINE---------------------- */
while(x!=3){
	x = menu(x); /* Funcao Menu Busca */


/*Printa produtos*/

if(x==1)
	ver_produtos(&estoque, y, total, media, dp, Em, temp, n, FS, LT);
/*Fim Printa produtos*/



struct tm *local;
time_t t= time(NULL);
local = localtime(&t);

if(x==2){
		printf("\n\n... Calculando dados e Gerando Relatorio... Pressione <Enter>\n");
		getchar();
		getchar();
		printf("Relatorio gerado com sucesso... %s as %d:%d:%d\n", __DATE__,local->tm_hour,local->tm_min,local->tm_sec );
		printf("\n<Enter> para mostrar...\n");
		getchar();
	
	for(i=0;i<10;i++)
	printf("|Code|: %d |Descricao|: %s	|Estoque Min.|: %.3f\n|Unid.|: %d |Demandas|: |1|: %.1f |2|: %.1f |3|: %.1f |4|: %.1f |5|: %.1f\n|Total|: %d	|Media|: %.1f\n\n", estoque.cod[i], estoque.descricao[i], Em[i], estoque.unidades[i], estoque.periodo[i][0],  estoque.periodo[i][1], estoque.periodo[i][2], estoque.periodo[i][3], estoque.periodo[i][4], total[i], media[i]);
	
	printf("Pressione <Enter> para voltar ao Menu Principal...\n\n");
	getchar();
}
}
	arquivo_relatorio(gerar, estoque, total, media, Em, firstline);

fclose(arq);
fclose(gerar);
printf("\n\n...Um relatorio em formato de arquivo texto 'Relatorio.txt' foi criado com sucesso!...\n\n");
printf("Feito por: Yan Victor.\n\n");
 return 0;


}
