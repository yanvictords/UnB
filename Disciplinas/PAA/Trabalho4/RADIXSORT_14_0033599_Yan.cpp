
#include <bits/stdc++.h>
using namespace std;

vector <int> A;
int tamanho; 

void radixsort();

int main(){
    int c;
    scanf("%d", &tamanho);
    for(int i=0; i<tamanho; i++){
        scanf("%d", &c);
        A.push_back(c);
    }
    
    radixsort();
    
    for(int i=0; i <tamanho;i++)
        printf("%d\n", A[i]);
return 0;
}

void radixsort(){
    int i, *b, max = A[0], exp=1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++)
        if (A[i] > max)
    	    max = A[i];
    
    while (max/exp > 0) {
        int bk[10] = { 0 };

    	for (i = 0; i < tamanho; i++)
    	    bk[(A[i] / exp) % 10]++;

    	for (i = 1; i < 10; i++)
    	    bk[i] += bk[i - 1];

    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bk[(A[i] / exp) % 10]] = A[i];

    	for (i = 0; i < tamanho; i++)
    	    A[i] = b[i];
    	exp *= 10;
    }

    free(b);
}
