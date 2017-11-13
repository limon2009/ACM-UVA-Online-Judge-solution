#include<iostream>
#include<stdio.h>
#include<list>

using namespace std;

#define maxn 3002


using namespace std;

list<int>link[maxn];
char C[maxn];
char Ad[maxn][maxn];

int N, M, count;

void Recur(int n, int level, int k) {
	int v;
	list<int>::iterator p;
	if(level == 3) {
		if(Ad[n][k]) 
			count ++;
		return;
	}
	C[n] = 1;
	for(p = link[n].begin(); p != link[n].end(); p++) {
		v = *p;
		if(C[v]) continue;
		Recur(v, level+1, k);
	}
	C[n] = 0;
}

void Cal() {
	int i, d = N - 3 + 1;
	count = 0;
	for(i = 1; i<= d; i++) {
		Recur(i, 1, i);
	}
	printf("%d\n",count);
}

int main() {
	int t, u, v;
	scanf("%d",&t);
	list<int>::iterator p;
	while(t--) {
		scanf("%d%d",&N,&M);
		while(M--) {
			scanf("%d%d",&u,&v);
			if(u<v)
				link[u].push_back(v);
			else link[v].push_back(u);
			Ad[u][v] = Ad[v][u] = 1;
		}
		Cal();
		for(u = 1; u <= N; u++) {
			for(p = link[u].begin(); p != link[u].end(); p++) {
				v = *p;
				Ad[u][v] = Ad[v][u] = 0;
			}
			link[u].clear();
		}
	}
	return 0;

}
