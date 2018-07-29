#include <bits/stdc++.h>
using namespace std;

vector <int> A;
int tamanho; 

int hoare_partition(int p, int r);
void quicksort(int p, int r);

int main(){
    int c;
    scanf("%d", &tamanho);
    for(int i=0; i<tamanho; i++){
        scanf("%d", &c);
        A.push_back(c);
    }
    
    quicksort(0, tamanho-1);
    
    for(int i=0; i <tamanho;i++)
        printf("%d\n", A[i]);
return 0;
}

int hoare_partition(int p, int r){
    int x = A[p];
    int i = p-1;
    int j = r+1;
    int aux;
    
    while(true){
        do{
            j--;
        }while(A[j] > x);
        do{
            i++;
        }while(A[i] < x);
        if(i<j){
            aux=A[i];
            A[i]=A[j];
            A[j]=aux;
        }else{
            return j;
        }
    }
}

void quicksort(int p, int r){
    if(p<r){
    int q=hoare_partition(p,r);;
        quicksort(p, q);
        quicksort(q+1, r);
    }
}
