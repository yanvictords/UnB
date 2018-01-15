//******UNIVERSIDADE DE BRASÍLIA*****************
//******TAG: 2017/01
//******ALUNOS: GUILHERME ANDREÚCE - 
//******ALUNOS: RODRIGO VILAÇA - 14/0031111
//******ALUNOS: YAN VICTOR - 14/0033599
//***********************************************
//=====================================================================================================
#include <bits/stdc++.h>
#include "Eigen/Dense" //INSIRA A PASTA "Eigen" NO MESMO LOCAL DO ARQUIVO t.cpp
#include "kmeans.h"
using namespace Eigen;
//------------------------------Como compilar e executar
//Compile: g++ -o t trab.cpp kmeans.cpp
//Execute: ./t < entradaKmeans.in
//--------------------------------------------------------------//DEFINES
#define size_att 17 //numero total de atributos de cada instancia: usada para FOR'S, DECLARAÇÕES, ETC.
#define size_inst 101 //numero total de instancias: usada para FOR'S, DECLARAÇÕES, ETC.
#define sigma 10 //para comparar distância entre duas instâncias: compare()
#define col_normaliza 2 //para pegar somente as duas primeiras colunas da matrizX e matrizY
//--------------------------------------------------------------//DECLARAÇÃO DE VARIÁVEIS
char name[size_inst][100]; //matriz de atributos
int data[size_inst][size_att]; //nome dos animaizinhos lalala
double matrizA[size_inst][size_inst]; //Matriz A de afinidade
double matrizD[size_inst][size_inst]; //Matriz D diagonal para guardar a soma das linhas de MATRIZA
double matrizI[size_inst][size_inst]; //Matriz 'I'nversa de D
double matrizL[size_inst][size_inst]; //Matriz Laplaciana L = D^(-1/2) * A * D^(-1/2)
double matrizX[size_inst][col_normaliza]; //Matriz de autovetores da Matriz L
double matrizY[size_inst][col_normaliza]; //Matriz para normalizar
int total_points, total_values, K, max_iterations, has_name; //Usada para classe KMeans, Cluster e Point
vector<Point> points; //vector de objetos: Point
string point_name; //Caso a instancia tenha nome
//--------------------------------------------------------------//DECLARAÇÃO DE FUNÇÕES 
void read_file(); //Para leitura de dados e construção de tabela
void compare(); //Cria matriz de afinidade: MATRIZA
double distance_e(int a, int b); //Usada para distancia euclidiana
void zera_diagonal(); //Zera diagonal da matriz: MATRIZA
void matriz_diagonal(); //Preenche a diagonal da MATRIZD com as soma das linhas da MATRIZA
void matriz_raiz_inversa(); //Calcla MATRIZ^(-1/2) PARA MATRIZD: MATRIZI
void multiplica_matrizes_ML(); //Cria a matriz laplaciana: MATRIZL
void autovetores(); //Cria a matriz de autovetores: MATRIZX
void normaliza(); //Normaliza a matriz: MATRIZY
//=====================================================================================================
//------------------------------
//--------FUNÇÃO PRINCIPAL------
//------------------------------
int main(){
//----------------------- ***FAÇA O TESTE EXEMPLO DOS SLIDES: MATRIZY NORMALIZADA - STEP4 *** --------------------------
//PASSO 1: Troque "#define size_inst 101" por "#define size_inst 6".
//PASSO 2: Torne em comentários as linhas que chamam as funções "read_file();" e "compare();" dentro da função "main(){}".
//PASSO 3: Descomente todas as linhas abaixo que contém: "matrizA[][] = ...".
//PASSO 4: Lembre-se (caso necessário) de descomentar o código de PRINT matrizY abaixo, dentro da própria "main(){}".
//PASSO 5: Ao finalizar o teste, lembre-se de trocar "#define size_inst 6" para "#define size_inst 101" novamente.
/*
matrizA[0][3] = matrizA[0][5] = matrizA[1][3] = matrizA[1][4] = matrizA[1][5] = matrizA[2][4] = matrizA[2][5] = 0;
matrizA[3][0] = matrizA[3][1] = matrizA[4][1] = matrizA[4][2] = matrizA[5][0] = matrizA[5][1] = matrizA[5][2] = matrizA[5][5] = 0;
matrizA[0][4] = matrizA[4][0] = 0.1;
matrizA[2][0] = matrizA[0][2] = 0.6;
matrizA[2][3] = matrizA[3][2] = 0.2;
matrizA[5][3] = matrizA[3][5] = 0.7;
matrizA[5][4] = matrizA[4][5] = matrizA[4][3] = matrizA[3][4] = matrizA[2][1] = matrizA[1][2] = matrizA[1][0] = matrizA[0][1] = 0.8;
*/
//---------------
read_file();
compare();//FIM DO PASSO1: MATRIZA
matriz_diagonal(); 
matriz_raiz_inversa(); 
multiplica_matrizes_ML();//FIM DO PASSO2: MATRIZL
autovetores();//FIM DO PASSO3: MATRIZX
normaliza();//FIM DO PASSO4: MATRIZY

//Descomente o pedaço de código abaixo que está entre "INICIO" e "FIM" para printar a Saída da matrizY.
//INICIO: PRINT matrizY
/*for (int i=0; i<size_inst; ++i){
    for(int j=0; j<col_normaliza; ++j)
        cout << "|" <<matrizY[i][j] << "| ";
    cout << endl;
}*/
//FIM: PRINT matrizY

//------- PRINTAR MATRIZY PARA USAR NA CLASSE KMEANS. COLOCAR EM ARQUIVO A SAIDA GERADA
cout << "101 2 2 100 1\n";
for (int i=0;i<size_inst;i++){
    for (int j = 0; j<col_normaliza;j++){
        cout << matrizY[i][j] << " ";
    }
    cout << name[i] <<endl;
}
//--------------- FIM PRINTAR MATRIZY

//---------INICIO DOS PASSOS 5 E 6
    srand (time(NULL));
    cin >> total_points >> total_values >> K >> max_iterations >> has_name;
    for(int i=0; i<total_points; ++i){
        vector<double> values;
        for(int j=0; j<total_values; ++j){
            double value;
            cin >> value;
            values.push_back(value);
        }
        if(has_name){ //SE A INSTÂNCIA TIVER NOME, O CONSTRUTOR SERÁ DIFERENTE
            cin >> point_name;
            Point p = Point(i, values, point_name);
            points.push_back(p);
        }else{
            Point p = Point(i, values);
            points.push_back(p);
        }
    }
    KMeans kmeans = KMeans(K, total_points, total_values, max_iterations); // OBJETO DA CLASSE KMEANS
    kmeans.run(points); //EFETIVAMENTE PRINTA OS DADOS FINAIS
//---------FIM DOS PASSOS 5 E 6
  return 0;
}
//=====================================================================================================

//--------------------------
//----FUNÇÃO LÊ ARQUIVO----- //chamada pela main()
//--------------------------
void read_file(){
    FILE *teto;
    int k=0;
    teto = fopen("lista_de_animais.in" ,"r+");
    while(fscanf(teto, "%s", name[k])!=EOF){
        for(int j=0; j<17; ++j){
            fscanf(teto, "%d ", &data[k][j]); //LÊ BOOLEANS COMO INTEIROS. ESSA TIPAGEM NÃO AFETA A VERIFICAÇÃO
        }
       	++k;
    }
    fclose(teto);
}

//------------------------------------------
//---FUNÇÃO PREENCHE MATRIZA AFINIDADE------ //chamada pela main()
//------------------------------------------
void compare(){ 
    double temp;
    for(int i=0; i<size_inst; ++i)
        for(int j=0; j<size_inst; ++j)
            matrizA[i][j] = exp(distance_e(i,j)/(2*pow(sigma,2))); //---CHAMADA DE FUNCAO() -> 'disância Euclidiana'
   zera_diagonal(); //---CHAMADA DE FUNCAO() -> 'zera diagonal da matrizA'
}

//-----------------------------------------------
//-----FUNÇÃO CALCULA DISTÂNCIA EUCLIDIANA------- //chamada por compare()
//-----------------------------------------------
double distance_e(int a, int b){
    double soma = 0;
    for (int i=0; i<size_att; ++i)
        soma = soma + pow(data[a][i] - data[b][i],2); //FEITA USANDO A FÓRMULA
    return sqrt(soma);
}

//------------------------------------------------------------------
//--------FUNÇÃO ZERA A DIAGONAL PRINCIPAL DE MATRIZA AFINIDADE----- //chamada por compare()
//------------------------------------------------------------------
void zera_diagonal(){
    for(int i=0; i<size_inst; ++i){
        matrizA[i][i] = 0;
    }
} 

//--------------------------------------------------------
//--------FUNÇÃO CRIA E PREENCHE MATRIZD DIAGONAL--------- //chamada pela main()
//--------------------------------------------------------
void matriz_diagonal(){
    double somaLinha = 0;
    for(int i=0; i<size_inst; ++i) //PREENCHE MATRIZD DE ZEROS, MENOS A DIAGONAL
        for(int j=0; j<size_inst; ++j)
            if (i!=j) matrizD[i][j] = 0;
            
    for(int i=0; i<size_inst; ++i){ //PREENCHE A DIAGONAL DE MATRIZD COM A SOMA DAS LINHAS DE MATRIZA: AFINIDADE
        somaLinha = 0;
        for(int j=0; j<size_inst; ++j)
            somaLinha += matrizA[i][j];
        matrizD[i][i] = somaLinha;
    }
}

//--------------------------------------------------------
//--------FUNÇÃO CALCULA A RAIZINVERSA EM MATRIZI--------- //chamada pela main()
//--------------------------------------------------------
void matriz_raiz_inversa(){
  MatrixXf A(size_inst,size_inst); //MatrixXf: TIPAGEM TÍPICA PARA CALCULAR A INVERSA DE UMA MATRIZ
  for(int i=0; i<size_inst; ++i) //DADOS DA MATRIZD PASSAM PARA MATRIZ A() PARA SER INVERTIDA
    for(int j=0; j<size_inst; ++j)
        A(i,j) = matrizD[i][j]; 
  A = A.inverse(); //A TORNA-SE EFETIVAMENTE A INVERSA DE MATRIZD
  for(int i=0; i<size_inst; ++i)
    for(int j=0; j<size_inst; ++j)
        matrizI[i][j] = A(i,j); //MATRIZI RECEBE A INVERSA DE MATRIZD QUE ESTAVA EM A()
  for(int i=0; i<size_inst; ++i) 
  	matrizI[i][i] = sqrt(matrizI[i][i]); //RAIZ DA DIAGONAL PASSA A SER SUA RAIZ QUADRADA (^(-1/2))
 }
 
//-------------------------------------------------
//--------FUNÇÃO CALCULA MATRIZL LAPLACIANA-------- //chamada pela main()
//-------------------------------------------------
void multiplica_matrizes_ML(){
    double temp_sum; 
    double matrizR[size_inst][size_inst]; //MATRIZ QUE GUARDA O RESULTADO DE UMA MULTIPLICAÇÃO
    
//--------CALCULO MATRIZR = D(^(-1/2))*MATRIZA
    for(int i=0; i<size_inst; ++i)  //PARA CADA CASO DA POSIÇÃO R[I][J]
        for(int j=0; j<size_inst; ++j){ 
            temp_sum=0; 
            for(int k=0; k<size_inst;++k){ //MULTIPLICA-SE A LINHA DE M1[I]['K'] PELA COLUNA DE M2['K'][J]
                temp_sum+=matrizI[i][k]*matrizA[k][j];
            }
            matrizR[i][j]=temp_sum; //EFETIVAMENTE GUARDA-SE O RESULTADO DA MULTIPLICAÇÃO
        }
        
//---------CALCULO MATRIZL = MATRIZR*D(^(-1/2)) {A MULTIPLICAÇÃO É EXATAMENTE IGUAL}
    for(int i=0; i<size_inst; ++i) 
        for(int j=0; j<size_inst; ++j){ 
            temp_sum=0; 
            for(int k=0; k<size_inst;++k){ 
                temp_sum+=matrizR[i][k]*matrizI[k][j];
            }
            matrizL[i][j]=temp_sum; //MATRIZL ENCONTRADA
        }
}

//-------------------------------------------------
//---FUNÇÃO ENCONTRA OS AUTOVETORES PARA MATRIZX--- //chamada pela main()
//-------------------------------------------------
void autovetores(){
	MatrixXf A(size_inst,size_inst); //TIPAGEM TÍPICA PARA CALCULAR AUTOVETORES
	for(int i=0; i<size_inst; ++i) 
    	for(int j=0; j<size_inst; ++j)
        	A(i,j) = matrizL[i][j]; //MATRIZ A() RECEBE LAPLACIANA PARA CALCULAR AUTOVETORES
	EigenSolver<MatrixXf> es(A); //TIPAGEM DO MÉTODO
	MatrixXf X = es.pseudoEigenvectors(); //EFETIVAMENTE CALCULA-SE OS AUTOVETORES
  	for(int i=0; i<size_inst; ++i)
	    for(int j=0; j<col_normaliza; ++j)
        	matrizX[i][j] = X(i,j); //GUARDA-SE EM MATRIZX APENAS AS 2 PRIMEIRAS COLUNAS DE MATRIZL
}

//------------------------------------
//---FUNÇÃO NORMALIZA PARA MATRIZY---- //chamada pela main()
//------------------------------------
void normaliza(){
	double soma = 0;
	for(int i=0; i<size_inst; ++i){
		soma = 0;
		for(int j=0; j<col_normaliza; ++j)
	  		soma += pow(matrizX[i][j],2); //CALCULA RAIZ(SOMATORIOj DE Xij²) DA FÓRMULA PARA DENOMINADOR DA FÓRMULA
	    soma = sqrt(soma); //RAIZ DO DENOMINADOR
	    for(int j=0; j<col_normaliza; ++j)
	    	matrizY[i][j] = matrizX[i][j]/soma; //MATRIZY SENDO PREENCHIDA, APENAS AS 2 PRIMEIRAS COLUNAS
	}
}
//=====================================================================================================
