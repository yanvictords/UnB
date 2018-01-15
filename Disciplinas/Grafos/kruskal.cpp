#include <bits/stdc++.h>
using namespace std;

int num_v, num_a, a, b, peso;
vector< pair<int, pair<int,int> > > g;
vector< pair<int, pair<int,int> > > agm;
vector <int> p;

void grafo();
int find(int a); //encontra a raiz da componente que o vertice 'a' esta
void Union(int a, int b); //junta duas componentes diferentes
void init(); //no inicio todo mundo eh pai de si mesmo
void kruskal();
void print();
int main(){
	grafo();
	kruskal();
}

void grafo(){
	cout << "*********Algoritmo de Kruskal**********\n";
	printf("Numero de vertices: ");
	scanf("%d", &num_v);
	printf("Numero de arestas: ");
	scanf("%d", &num_a);
	printf("\n#Nota: %d vertice(s) indicam o seguinte conjunto de vertices: [", num_v);
	for(int i=0;i<num_v-1;++i)
		printf("%d,", i);
	printf("%d].", num_v-1);
	printf("\n\n-> Insira %d aresta(s) no seguinte formato: 'v1' 'v2' 'w' (SEM ASPAS), onde w eh o peso.\n", num_a);
	for(int i=0;i<num_a;++i){
		scanf("%d %d %d", &a, &b, &peso);
		g.push_back(make_pair(peso, make_pair(a,b)));
	}
}

void kruskal(){
	int a;
	int b;
	init();
	sort(g.begin(), g.end());
	for(int i=0;i<num_a;++i){
		a = find(g[i].second.first);
		b = find(g[i].second.second);
		if(a!=b){
			Union(a,b);
			agm.push_back(make_pair(g[i].first, make_pair(g[i].second.first, g[i].second.second)));
		}
	}
	print();
}

int find(int a){
	if(a==p[a])
		return a;
	return find(p[a]);
}

void Union(int a, int b){
	p[find(b)]=find(a);
}

void init(){
	for(int i=0;i<num_v;++i)
		p.push_back(i);
}

void print(){
	printf("\n\n=> A Arvore Geradora Minima contem as seguintes arestas: ");
	for(int i=0; i<agm.size();++i)
		printf("\n- Aresta %d: [%d]-[%d] com Peso: %d", i+1, agm[i].second.first, agm[i].second.second, agm[i].first);
	printf("\n");
}
