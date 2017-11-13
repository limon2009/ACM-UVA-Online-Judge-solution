#include<stdio.h>
#define MX(a, b) (a>b?a:b)
#define MIN(a, b) (a>b?b:a)
#define MAX 85
#define INF 1000000

struct ss {
	int max;
	int cost;
}link[MAX][MAX];

int N, E, Q;
int F[MAX];

void Ini() {
	int i, j;
	for(i = 1; i<=N; i++) {
		for(j = i+1; j<=N; j++)
			link[i][j].cost = link[j][i].cost = INF;
		link[i][i].cost = 0;
	}
}

void Floyd() {
	int i, j, k, x, y, z;
	for(k = 1; k<= N; k++) {
		for(i = 1; i <= N; i ++) {
			for(j = 1; j <= N; j++) {
				x = link[i][j].cost + link[i][j].max;
				y = link[i][k].cost + link[k][j].cost;
				z =	 MX(link[i][k].max,link[k][j].max);
				if(x>(y+z)) {
					link[i][j].cost = y;
					link[i][j].max = z;
				}
			}
		}
	}
}


void Cal() {
	int u, v, x;
	Floyd();
	Floyd();
	while(Q--) {
		scanf("%d%d",&u,&v);
		x = link[u][v].cost + link[u][v].max; 
		if( x>= INF) printf("-1\n");
		else printf("%d\n",x);
	}
}

int main() {
	int i, u, v, c, ks = 1;
	//freopen("c:\\h.txt","r",stdin);
	while(scanf("%d%d%d",&N,&E,&Q) == 3) {
		if(!N && !E && !Q) break;
		Ini();
		for(i = 1; i <= N; i++) {
			scanf("%d",&F[i]);
			link[i][i].max = F[i];
		}
		for(i = 0; i<E; i++) {
			scanf("%d%d%d",&u,&v,&c);
			if(link[u][v].cost > c) {
				link[u][v].cost = link[v][u].cost = c;
				link[u][v].max = link[v][u].max = MX(F[u],F[v]);
			}
		}
		if(ks>1) printf("\n");
		printf("Case #%d\n",ks++);
		Cal();
	}
	return 0;

}
