/*YAN VICTOR DOS SANTOS - 140033599 || Professora Carla Koike - Computação básica
PROGRAMA: JOGO DA FORCA. PALAVRA: "otorrinolaringologista"  */
#include <stdio.h>
/*-------------------------------------------------------------------------------------------------*/
    /*PRIMEIRA FUNÇÃO: Imprime a quantidade de '_'s na mesma quantidade de letras que a palavra possui.*/
    void string_decifrada(char palavra_alvo1[], char palavra_decifrada1[]){
        int i;
/*Essa estrutura "for" nos dá a possibilidade de aparecer '_'s na mesma quantidade de letras em
qualquer palavra que quisermos colocar. Eu usei traços ao invés de underlines para a melhor visualização.*/
        for(i=0;palavra_alvo1[i]!='\0';i++){
            palavra_decifrada1[i]='-';
        }
    }
    /*TÉRMINO DA PRIMEIRA FUNÇÃO*/
/*-------------------------------------------------------------------------------------------------*/
/*SEGUNDA FUNÇÃO: Observa se a letra que o usuário inseriu já foi utilizada alguma vez*/
    void letra_alfabeto(char letra2[], char alfabeto2[], int i){
        int j;
        /* Enquando o contador i for menor que o contador j, ele irá mostrar na tela a letra usada*/
        for(j=0; j<=i; j++){
            if(letra2[i]==alfabeto2[j-1]){
                printf("\n");
                printf("A letra '%c' jah foi usada. Tente outra.", letra2[i]);
            }else{
                alfabeto2[i] = letra2[i];
                printf("|%c|", alfabeto2[j]);
            }
        }
        printf("\n");
    }
    /*TÉRMINO DA SEGUNDA FUNÇÃO*/
/*-------------------------------------------------------------------------------------------------*/
/*TERCEIRA FUNÇÃO: Verifica se a letra inserida existe na palavra e substitui o "underline" pela letra inserida*/
    void letra_palavra(char palavra_alvo3[], char palavra_decifrada3[], char letras3[], int i){
        int j;
        for(j=0;palavra_alvo3[j]!='\0';j++){
            if(letras3[i]==palavra_alvo3[j]){
                palavra_decifrada3[j]=letras3[i];
            }
            printf("%c", palavra_decifrada3[j]);
        }
        printf("\n");
    }
    /*TÉRMINO DA TERCEIRA FUNÇÃO*/
/*-------------------------------------------------------------------------------------------------*/
/*QUARTA FUNÇÃO: Testa a palavra encontrada com a palavra escolhida.*/
    int parabens(char palavra_decifrada4[], char palavra_alvo4[]){
        int i;
        for(i=0;palavra_alvo4[i]!='\0';i++){
            if(palavra_alvo4[i]!=palavra_decifrada4[i]){
            return(0);
            }
        }
        return(1);
    }

/*TÉRMINO DA QUARTA FUNÇÃO*/
/*-------------------------------------------------------------------------------------------------*/
/*FUNÇÃO ADICIONAL OU FUNÇÃO BONECO: calcula os erros e mostra as partes do corpo*/
    void palito(int quanterros){
        if(quanterros==1){
           printf("\n");
           printf(" |\n");
           printf(" O\n\n\n");
            }
        if(quanterros==2){
            printf("\n");
            printf(" |");
            printf("\n");
            printf(" O");
            printf("\n");
            printf(" |");
            printf("\n\n");
            }
        if(quanterros==3){
            printf("\n");
            printf("  |");
            printf("\n");
            printf("  O");
            printf("\n");
            printf(" /|");
            printf("\n\n");
        }
        if(quanterros==4){
            printf("\n");
            printf("  |");
            printf("\n");
            printf("  O");
            printf("\n");
            printf(" /|\\ ");
            printf("\n\n");
        }
        if(quanterros==5){
            printf("\n");
            printf("  |");
            printf("\n");
            printf("  O");
            printf("\n");
            printf(" /|\\ ");
            printf("\n");
            printf(" / ");
            printf("\n\n");
        }
        if(quanterros==6){
            printf("\n");
            printf("  |");
            printf("\n");
            printf("  O");
            printf("\n");
            printf(" /|\\ ");
            printf("\n");
            printf(" / \\ ");
            printf("\n");
            printf("***GAME OVER***");
        }
    }


/*FIM DA FUNÇÃO ADICIONAL*/
/*-------------------------------------------------------------------------------------------------*/
/*Função principal*/
    int main(){
        char letra[30], palavra_alvo[]="otorrinolaringologista", palavra_decifrada[30], alfabeto[30];
        int i, j, f, quanterros=0, v=0;
        printf("***BEM VINDO AO JOGO DA FORCA***\n");
/*Essa estrutura "for" serve somente para indicar a quantidade de letras que a palavra tem, nada mais.*/
        for(j=0;palavra_alvo[j]!='\0';j++){
        }
        printf("A palavra possui %d letra(s).\n", j);
/*Chamando a PRIMEIRA FUNÇÃO*/
        string_decifrada(palavra_alvo, palavra_decifrada);
        for(j=0;palavra_alvo[j]!='\0';j++){
        printf("%c", palavra_decifrada[j]);
        }
        printf("\n");
/*Término do chamado da primeira Função*/
        printf("Veja, uma corda!: |\n");
/*--------------Inicio do comando de entrada da letra pelo jogador-------------*/
        for(i=0;((f!=1)&&(quanterros<=5));i++){
            printf("Digite uma letra:");
            scanf("%c", &letra[i]);
            getchar();
            while((letra[i]=='\n')||(letra[i]==' ')){
                printf("Erro! Digite novamente outra letra:");
                scanf("%c", &letra[i]);
                getchar();
            }
            /*Somente para aparecer as letras que ja foram usadas, de forma fixa*/
            printf("Letras usadas:");
/*Chamando a SEGUNDA FUNÇÃO*/
            letra_alfabeto(letra, alfabeto, i);
/*Chamando a TERCEIRA FUNÇÃO*/;
            letra_palavra(palavra_alvo, palavra_decifrada, letra, i);
/*Chamando a FUNÇÃO BONECO PALITO*/
   v=0;
   for(j=0;palavra_alvo[j]!='\0';j++){
            if(letra[i]==palavra_alvo[j]){
              v=1;
            }
   }
if(v!=1){
quanterros++;
            palito(quanterros);
}
/*Chamando a QUARTA FUNÇÃO*/
            parabens(palavra_decifrada, palavra_alvo);
            f = parabens(palavra_decifrada, palavra_alvo);
            /*se ele me retornar 1, significa que o usuario acertou*/
            if(f==1){
                printf("CONGRATULATIONS! A palavra era '%s'!\n", palavra_alvo);
            }
        }
    return(0);
    }
