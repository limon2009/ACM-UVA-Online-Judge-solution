#include<stdio.h>
#include<map>
#include<string.h>
#define MAXN 30
using namespace std;

char S[MAXN][30];
char flg[MAXN];
char link[MAXN][MAXN];
int N, E;

map<string,int>M;

void Set() {
	int i, j;
	for(i = 1; i<= N; i++) {
		for(j = i+1; j<= N; j++)
			link[i][j] = link[j][i] = 0;
		link[i][i] = 0;
	}
}


void Dfs(int n, int k) {
	int i;
	flg[n] = 1;
	link[k][n] = 1;
	for(i = 1; i<= N; i++){
		if(flg[i] == 0 && link[n][i])
			Dfs(i,k);
	}
}

void Circle(int n) {
	int i;
	for(i = 1; i<= N; i++) {
		if(flg[i] || i == n ) continue;
		if(link[i][n] && link[n][i]) {
			printf(", %s",S[i]);
			flg[i] = 1;
		}
	}
}

void Cal() {
	int i, j, k;
	for(i = 1; i<= N; i++) {
		Dfs(i,i);
		memset(flg,0,MAXN);
	}
	for(i = 1; i<= N; i++) {
		if(flg[i] == 1) continue;
		printf("%s",S[i]);
		flg[i] = 1;
		Circle(i);
		printf("\n");
	}
	memset(flg,0,MAXN);
}

int main() {
	char ss[30], xx[30];
	int ind, u, v, st = 1;
	while(scanf("%d%d",&N,&E) == 2) {
		ind = 1;
		if(!N && !E) break;
		Set();
		for(int i = 0; i<E; i++) {
			scanf("%s%s",ss,xx);
			u = M[ss];
			if(!u){ M[ss] = ind++; u = ind-1; strcpy(S[ind-1],ss); }
			v= M[xx];
			if(!v){ M[xx] = ind++; v = ind-1; strcpy(S[ind-1],xx);}
			link[u][v] = 1;
		}
		if(st>1) printf("\n");
		printf("Calling circles for data set %d:\n",st++);
		Cal();
		M.clear();
	}
	return 0;

}
