#include <bits/stdc++.h>

using namespace std;
#define MODULO 1000000007

int x;
vector<vector<long long> > A;

void multiplica_m(vector<vector<long long> > matriz1, vector<vector<long long> > matriz2, vector<vector<long long> > & matriz3, int a, int b, int c);
void cp_matriz(vector<vector<long long> > & matriz1, vector<vector<long long> > matriz2);
long long fibonacci(long long u);

int main(){

  int cont; 
  long long u, v, r;   
  x = 2;
  A.resize(x);
  for(int i = 0; i < x; i++)
    A[i].resize(1);
  
  A[0][0] = 1;
  A[1][0] = 1;

  scanf("%d",&cont);
  
  while(cont--){
    scanf("%lld %lld",&u,&v);
    r = (fibonacci(v+2)-1-(fibonacci(u+1)-1)) % MODULO;
    if(r < 0)
      r += MODULO;
    printf("%lld\n",r);
  }
  return 0;
}

long long fibonacci(long long u){
	
  if(u == 0) return 0;
  else if(u == 1) return A[0][0] % MODULO;
  else if(u == 2) return A[1][0] % MODULO;
  
  vector<vector<long long> > a, b, c;
  a.resize(x);
  b.resize(x);
  c.resize(x);
  
  for(int i = 0; i < x; i++){
    a[i].resize(x);
    b[i].resize(x);
    c[i].resize(x);
  }
  a[0][0] = a[0][1] = a[1][0] = 1;
  a[1][1] = 0;
  for(int i = 0; i < x; i++){ 
    for(int j = 0; j < x; j++){
      c[i][j] = 0;
	}
  }
  c[0][0] = c[1][1] = 1;
  u = u-2;
  while(u){
    if(u%2==1){
		multiplica_m(c, a, b, x, x, x);
		cp_matriz(c,b);
    }
    multiplica_m(a, a, b, x, x, x);
    cp_matriz(a,b);
    u>>=1;
  }

  multiplica_m(c, A, b, x, x, 1);
  if(b[0][0]<0)
    b[0][0]+=MODULO;
  return b[0][0];
}

void multiplica_m(vector<vector<long long> > matriz1, vector<vector<long long> > matriz2, vector<vector<long long> > & matriz3, int a, int b, int c){
	for(int i = 0; i < a; i++)
		for (int j = 0; j < c; j++){
			matriz3[i][j] = 0;
			for (int k = 0; k < b; k++)
				matriz3[i][j] = (matriz3[i][j] + (matriz1[i][k]*matriz2[k][j]) % MODULO) % MODULO;
		}
}

void cp_matriz(vector<vector<long long> > & matriz1, vector<vector<long long> > matriz2){
	for (int i = 0; i < matriz1.size(); i++)
		for(int j = 0; j < matriz1[0].size();j++)
			matriz1[i][j] = matriz2[i][j];	
}

