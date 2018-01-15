#include "MuMaterial.h"

#define TAMANHO_ESCALA 40    //Tamanho do vetor com a escala que você deseja ter.
#define INICIO 60           //A partir de qual valor esse vetor deve ser criado.
#define NUMERO_DE_VOZES 16 //Ńúmero de vozes máxima usadas em um único CaMaterial. 





class CaMaterial : public MuMaterial
{	
	private:
		int* Graus[NUMERO_DE_VOZES];
	
	
	public:

		int getEscalaNat(void); /* Retorna 0 para atonal, 1 a 12 para Dó 
                                        a Si Maior e 13 a 24 para Dó a Si Menor. */

		int* getVetorGraus(int tom);          /*Recebe o tom e retorna a escala começada por esse  
                                         tom a partir de um dado início. Lembrar de desalocar
                                         o endereço retornado pela função ao fim do programa*/

		void GeraTriade(int notaref, int posicao, MuMaterial* paux); //posicao 0 :  C E G posicao 1: Am C E posicao 2: F Am C
		//int nota = referencia para as 3 notas possiveis 

		int ProximaAltura(int notaref, int salto);//Retorna a próxima altura baseado no intervalo a ser saltado
												  //e na nota de origem. Precisa usar a setGraus antes.
		int* getCompassos(int tempos, int *numero_compassos);

		void setGraus(int voz);//Armazena o grau da voz escolhida em graus[0];

		void setGraus(void);//Armazena o grau da voz escolhida em graus[0];

		int* getGraus(int voz); //Retorna o vetor com os graus da voz escolhida.

		int* getGraus(void);//Retorna o vetor com os graus da voz zero.

		void ShowGraus(int voz);//Imprime na tela os graus da voz escolhida do material.

		void ShowGraus(void);//Imprime na tela os graus da voz zero do material.

		CaMaterial & operator=(const CaMaterial & MuMaterial);

		CaMaterial & operator=(const MuMaterial & inMaterial);

};
