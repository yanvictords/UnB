#include <bits/stdc++.h>
using namespace std;

map <int, int> h;
int main() {
    int n, q, a;
    scanf("%d %d", &n, &q);
    for(int i=0; i<n; ++i){
        scanf("%d", &a);
        h.insert(make_pair(a,i));
    }
    while(q--){
        scanf("%d", &a);
        if(h.find(a) != h.end())
            printf("%d\n", h[a]);
        else
            printf("-1\n");
    }
	return 0;
}
