#include<stdio.h>

#define MAXN 102

int N, M, Black, St[MAXN];
int MAX, A[MAXN];

struct ss {
	int adj[MAXN];
	int index;
	int c;
}V[MAXN];

void Copy( int n) {
	int i;
	for(i = 0; i<=n; i++) 
		A[i] = St[i];
}

void Free(int n) {
	int i, j;
	for(i = 0; i<V[n].index; i++) {
		j = V[n].adj[i];
		V[j].c  --;
		if(V[j].c == 0)
			Black--;
	}
	V[n].c = 0;

}
void Recur(int level, int n) {
	int i, j, k;
	St[level] = n;
	V[n].c = 1;
	for(j = 0; j<V[n].index; j++){
		k = V[n].adj[j];
		if(V[k].c == 0)
			Black++;
		V[k].c++;
	}
	if(level > MAX) {
		Copy(level);
		MAX = level;
	}
	k = Black+level;
	if((N-k+level)<=MAX) {
		Free(n);
		return;
	}
	for(i = n+1; i<= N; i++) {
		if(V[i].c == 0) 
			Recur(level+1,i);
	}
	Free(n);
}

void Cal() {
	int i;
	MAX = 0;
	for(i = 1; N-i>=MAX; i++){
		Black = 0;
		Recur(1,i);
	}
	printf("%d\n",MAX);
	printf("%d",A[1]);
	for(i = 2; i<=MAX; i++) 
		printf(" %d",A[i]);
	printf("\n");
}


void Set() {
	int i;
	for(i = 1; i<= N; i++) {
		V[i].index = 0;
		V[i].c = 0;
	}
}

int main() {
	int kase, i, n, m;
//	freopen("c:\\h.txt","r",stdin);
	scanf("%d",&kase);
	while(kase--) {
		scanf("%d%d",&N,&M);
		for(i = 0; i<M; i++) {
			scanf("%d%d",&n,&m);
			V[n].adj[V[n].index++] = m;
			V[m].adj[V[m].index++] = n;
		}
		Cal();
		if(kase)
			Set();
	}
	return 0;
}
