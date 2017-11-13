#include<stdio.h>
#include<queue>
#define MAXN 1002

using namespace std;

struct ss {
	int schedule[31];
	int ind;
}city[11][11];

struct xx {
	int node;
	int level;
};

queue<xx>Q;
int Cost[11][MAXN];
int N, K, Min;

void ReadCase() {
	int i, j, k, sc;
	for(i = 1; i<= N; i++) {
		for(j = 1; j<= N; j++) {
			if(i == j) continue;
			scanf("%d",&sc);
			for(k = 0; k<sc; k++)
				scanf("%d",&city[i][j].schedule[k]);
			city[i][j].ind = k;
		}
	}
}

void BFS() {
	xx s, t;
	int i, d, k,cost,u;
	s.level = -1;
	s.node = 1;
	Q.push(s);
	Min = 2147483647;
	Cost[1][0] = 0;
	while(!Q.empty()) {
		t = Q.front();
		Q.pop();
		u = t.node;
		d = t.level + 1;
		if(t.level <0 ) t.level = 0;
		for(i = 1; i<= N; i++) {
			if(i == u) continue;
			if(d == K-1 && i != N) continue;
			k = city[u][i].schedule[d%city[u][i].ind];
			if(!k) continue;
			cost = Cost[u][t.level] + k;
			if(d == K-1) {
				if(cost < Min) Min = cost;
				continue;
			}
			if(Cost[i][d] <= cost) continue;
			if(Cost[i][d] != 2147483647) {
				if(Cost[i][d] > cost) {
					Cost[i][d] = cost;
					continue;
				}
			}
			Cost[i][d] = cost;
			s.level = d;
			s.node = i;
			Q.push(s);
		}
	}
}

void Cal() {
	BFS();
	if(Min == 2147483647) printf("No flight possible.\n");
	else printf("The best flight costs %d.\n",Min);
}

int main() {
//	freopen("c:\\h.txt","r",stdin);
	int i, j, s = 1;
	while(scanf("%d%d",&N,&K) ==2 ) {
		if(!N && !K) break;
		for(i = 1; i<= N; i++) for(j = 0; j<= K; j++) Cost[i][j] = 2147483647;
		ReadCase();
		printf("Scenario #%d\n",s++);
		Cal();
		printf("\n");
	}
	return 0;

}
