#include <bits/stdc++.h>
using namespace std;
#define root 4   //escolha uma raiz
#define destiny 1 //escolha um destino
#define infinite 100
//-----------------------
//-----------------------
FILE *arq = fopen("g1.in", "r+");
int num_v, origem=root-1, dest=destiny-1;
//GRAFO
std::map<int,std::vector< std::pair<int,float> > > g; //grafo em lista de adj v-><u,peso_aresta>
std::vector<bool> color; //parametros de cor de v para bfs
std::vector<int> pv; //pai de v
std::vector< std::pair<float,int> > dv_v; //d[v] para dijkstra
//Filas
std::queue<int> q; //fila para bfs
std::vector<int> q_aux; //para auxiliar a forma que preenchemos a queue q em dijkstra
//-----------------------
void cria_grafo();
void inicia_cores();
void inicia_valores();
bool bellman_ford();
bool compare(float a, float b);
void relaxacao(int v, int u);
void organiza_queue();
void print();
void print_arvore_minima();
//-----------------------
//-----------------------
int main(){
    cria_grafo();
    cout << "******Algoritmo de Bellman-Ford******\n";
    cout << "#Nota: O grafo criado para a simulacao do algoritmo esta no arquivo 'g1.in' .\n\n";
    cout << "#Nota: A leitura e feita a partir de uma matriz de adjacencia. A primeira linha contem o numero n de vertices, e as proximas n linhas descrevem a matriz.\n\n";
    cout << "Pressione <Enter> para simular...";
    getchar();
    if(bellman_ford()){
    	std::cout << "\nArvore gerada...";
    	print_arvore_minima();
	}else{
    	std::cout << "\nLoop Infinito...\n";
	}    
    return 0;
}
//-----------------------

void cria_grafo(){
    float p;
    fscanf(arq, "%d", &num_v);

    for(int i=0;i<num_v;++i){
        for(int j=0;j<num_v;++j){
            fscanf(arq, "%f", &p);
            if(p!=0){
                g[i].push_back(std::make_pair(j,p));
            }
        }
    }
    fclose(arq);
}
//-----------------------

void inicia_cores(){
	color.erase(color.begin(), color.end());
    for(int i=0;i<num_v;++i)
        color.push_back(false);
    color[origem]= true;
}
//-----------------------

void inicia_valores(){
    std::cout << "=> Rodando Bellman Ford...\n\n";
    while(!q.empty())
        q.pop();
    for(int i=0;i<num_v;++i){
        pv.push_back(-1);
        dv_v.push_back(std::make_pair(infinite,i));
    }
    inicia_cores();
    dv_v[origem].first=0;
}
//-----------------------

bool bellman_ford(){
    int p, u, a,b,fim=dest;
    inicia_valores();
    for(int k=0;k<g.size()-1;  ++k){
    	q.push(origem);
    	while(!q.empty()){
        	print();
        	u = q.front();
        	for(int i=0;i<g[u].size();++i){
	            relaxacao(g[u][i].first,u);
	            if(!color[g[u][i].first]){
	                color[g[u][i].first]=true;
	                q_aux.push_back(g[u][i].first);
	            }
	        }
	        organiza_queue();
	        q.pop();
	    }
	    for(int i=0;i<num_v;++i)
	        if(dv_v[i].second==dest)
	    		fim=i;
	  	inicia_cores();
	}

	for(int u=0;u<g.size();++u){
		for(int i=0;i<g[u].size();++i){
	   	 	for(int k=0;k<num_v;++k){
	   	    	if(g[u][i].first==dv_v[k].second)
	   	        	a=k;
	   	     	if(u==dv_v[k].second)
	   	        	b=k;
	   	 	}
	   	 	if(compare(dv_v[a].first,dv_v[b].first+g[u][i].second))
				return false;	
		}
	}

	std::cout << "\nPeso do caminho minimo de " << root << " ate " << destiny << ": " << dv_v[fim].first << std::endl;
	return true;
}
//-----------------------

bool compare(float a, float b){
	if(a-b>0)
		if(a-b<0.1)
			return false;
		else
			return true;
	return false;
}
//-----------------------

void relaxacao(int v, int u){
    float p;
    int a,b;
    for(int i=0;i<g[u].size();++i)
        if(g[u][i].first==v)
            p=g[u][i].second;

    for(int i=0;i<num_v;++i){
        if(v==dv_v[i].second)
            a=i;
        if(u==dv_v[i].second)
            b=i;
    }

    if(dv_v[a].first>(dv_v[b].first+p)){
        dv_v[a].first=dv_v[b].first+p;
        pv[v]=u;
    }
}
//-----------------------

void organiza_queue(){
    std::sort(dv_v.begin(), dv_v.end());
    for(int i=0;i<num_v;++i)
        for(int j=0;j<q_aux.size();++j)
            if(dv_v[i].second==q_aux[j]){
                q.push(dv_v[i].second); }
    q_aux.erase(q_aux.begin(), q_aux.end());
}
//-----------------------

void print(){
    std::queue<int> qa = q;
    int  temp,a=qa.size();
    std::cout << "q={ ";
    for (int i=0;i<a;++i){
        std::cout<< qa.front()+1 <<"[";
        for(int j=0;j<num_v;++j)
            if(dv_v[j].second==qa.front())
                std::cout << dv_v[j].first << "]"<< " ";
        if(i==0)
            temp=qa.front()+1;
        qa.pop();
    }
    std::cout<<"}     - Relaxacao feita em Adjs["<<temp<<"]\n";
}

//-----------------------
void print_arvore_minima(){
        std::cout<<"\n\n=> Arvore Geradora Minima...\n\n";
    for(int i=0;i<num_v;++i){
        if(pv[i]+1==0)
            std::cout<<"Vertice: "<< i+1 << "| Pai: Raiz" << "\n";
        else
            std::cout<<"Vertice: "<< i+1 << "| Pai: " << pv[i]+1 << "\n";
    }
}
