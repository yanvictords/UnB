#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector <int> A;
void merge(int p, int q, int r){
vector <int> L;
vector <int> R;
    int n1 = q-p+1;
    int n2 = r-q;
    int i, j, k;
    for(i=0; i<n1; ++i){
        L.push_back(A[p+i]);
    }
    for(j=0; j<n2; ++j){
        R.push_back(A[q+j+1]);
    }

    i=0; j=0, k=p;
    while(i<n1 && j<n2){ // se uma das duas metades chegar ao fim, encerra
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
            k++;
        }else{
            A[k] = R[j];
            j++;
            k++;
        }
    }
    while(i<n1){  // Caso ainda haja elementos na primeira metade
        A[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){ // Caso ainda haja elementos na segunda metade
        A[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int p, int r){
    int q;
    if(p < r){
        q = ((p+r)/2);
        mergeSort(p, q);
        mergeSort(q+1, r);
        merge(p, q, r);
    }
}


int main() {
	int args; // n quantidade de elementos, args argumentos do vetor
    while(scanf("%d", &args) != EOF)
        A.push_back(args); // preenche vetor de entrada

    mergeSort(0, A.size()-1);

    for(int i=0; i<A.size(); ++i)
        cout << A[i] << ' ';
    cout << endl;
	return 0;
}
