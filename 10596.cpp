#include<stdio.h>

#define MAXN 10002
#define MAX 202

int N, R;
char Adj[MAX][MAX], fl[MAX];

int Q[MAX], QH, QT;

struct ss {
	int income;

}dg[MAX];


void Push(int n) {
	Q[QH++] = n;
	QH %= MAX;
}

int Pop() {
	int n;
	n = Q[QT++];
	QT %= MAX;
	return n;
}

int IsEmpty() {
	return QH == QT;
}

int IsConnected () {
	int i, p, c = 1;
    QH = QT = 0;
	Push(0);
	fl[0] = 1;
	while(!IsEmpty()) {
		p = Pop();
		for(i = 0; i<N; i++){
			if(fl[i] == 0 && Adj[p][i] == 1){
				c++;
				if(c == N) return 1;
				fl[i] = 1;
				Push(i);
			}
		}

	}
	return 0;
}

int Cal() {
	int i;
	if(!IsConnected()) return 0;
	for(i = 0; i<N; i++) 
		if(dg[i].income % 2!= 0) return 0;
	return 1;
}

void Reset() {
	int i, j;
	for(i = 0; i<N; i++) {
		fl[i] = 0;
		dg[i].income = 0;
		for(j = 0; j<N; j++) {
			Adj[i][j] = Adj[j][i] = 0;
		}
	}
}

int main() {
	int i, u, v;
	while(scanf("%d%d",&N,&R) == 2) {
		for(i = 0; i<R; i++) {
			scanf("%d%d",&u,&v);
			Adj[u][v] = 1;
			dg[u].income++;
			dg[v].income++;
		}
		if(Cal()) printf("Possible\n");
		else printf("Not Possible\n");
		Reset();
	}
	return 0;
}
