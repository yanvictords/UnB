#include "MuMaterial.h"

#define TAMANHO_ESCALA 26    //Tamanho do vetor com a escala que você deseja ter.
#define INICIO 48           //A partir de qual valor esse vetor deve ser criado.




int getEscalaNat(MuMaterial* pmat); /* Retorna 0 para atonal, 1 a 12 para Dó 
                                        a Si Maior e 13 a 24 para Dó a Si Menor. */


int* getVetorEscala(int tom);          /*Recebe o tom e retorna a escala começada por esse  
                                         tom a partir de um dado início. Lembrar de desalocar
                                         o endereço retornado pela função ao fim do programa*/

void GeraTriade(int notaref, int posicao, MuMaterial* pmat, MuMaterial* paux); //posicao 0 :  C E G posicao 1: Am C E posicao 2: F Am C
//int nota = referencia para as 3 notas possiveis 

int* getCompassos(int tempos, MuMaterial* pmat, int *numero_compassos);



