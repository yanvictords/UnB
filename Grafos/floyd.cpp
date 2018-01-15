#include <bits/stdc++.h>
using namespace std;
#define infinito 10000

int matriz[100][100];
int pred[100][100];

int main(){
	int n,m,a,b;
	int p;
	cout << "*******Algoritmo de Floyd-Warshall******\n";	
	cout << "#Nota: Para encerrar a simulacao, insira um inteiro negativo para a quantidade de vertices.\n";
	cout << "#Nota: Peso 10.000 e considerado infinito neste algoritmo." << endl << endl;
	cout << "Insira a quantidade de vertices: ";
	scanf("%d", &n);
	cout << "\n#Os seguintes vertices foram inseridos: ";	
	for(int i=1;i<n;++i)
		cout << i << ", ";
	cout << n << ".\n\n";
	while(n > 0){
		cout << "Insira a quantidade de arestas: ";
		scanf("%d", &m);
//inicializa matriz
		for(int i=0; i<n;++i)	
			for(int j=0;j<n;++j){
				matriz[i][j]=infinito;	
				if(i==j)
					matriz[i][j]=0;	
				pred[i][j]=-1;
			}
//preenche matriz
		for(int i=0;i<m;++i){
			cout << "--> Digite 'a b p', onde 'a' e 'b'(ints) são vertices e 'p' o peso da aresta: \n";
			scanf("%d %d %d", &a, &b, &p);
			a--;b--;
			matriz[a][b]=p;
			pred[a][b]=a+1;
		}	
		cout << endl;
		cout << "=> Matriz de probabilidades antes de floyd Warshall...\n\n";
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cout << matriz[i][j] << " " ;
			}
			cout << endl;
		}
		cout << endl;

		cout << "=> Matriz predecessor antes de floyd Warshall...\n\n";
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cout << pred[i][j] << " " ;
			}
			cout << endl;
		}
		cout << endl;
//floyd warshall
		for(int k=0; k<n; ++k)
			for(int i=0; i<n; ++i)
				for(int j=0; j<n; ++j){
					if(matriz[i][j] > matriz[i][k] + matriz[k][j]){
						matriz[i][j]=matriz[i][k]+matriz[k][j];
						pred[i][j]=pred[k][j];
					}	
				}
//fim floyd warshall
//print matriz de probabilidades atualizada 
		cout << endl;
		cout << "=> Matriz de probabilidades após floyd Warshall...\n\n";
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cout << matriz[i][j] << " " ;
			}
			cout << endl;
		}
		cout << endl;
//print matriz predecessor
		cout << "=> Matriz predecessor após floyd Warshall...\n\n";
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cout << pred[i][j] << " " ;
			}
			cout << endl;
		}
		cout << endl;
		cout << "Insira a quantidade de vertices: ";
		scanf("%d", &n);
}
	return 0;
}
