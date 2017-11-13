#include<stdio.h>
#include<string.h>

#define MAXN 1001

char F[MAXN][MAXN];
int R, C;

struct ss {
	int r, c;
	int move;
}q[MAXN*MAXN];


int qh, qt;
int mx[] = {0,0,1,-1};
int my[] = {1,-1,0,0};

void Push(int r, int c, int move) {
	q[qh].move = move;
	q[qh].r = r;
	q[qh++].c = c;
	qh %= MAXN*MAXN;
}

ss Pop() {
	ss p;
	p.move = q[qt].move;
	p.r = q[qt].r;
	p.c = q[qt++].c;
	qt %=  MAXN*MAXN;
	return p;
}


void Reset() {
	int i;
	for(i = 0; i<R; i++)
		memset(F[i],0,C);
}

int  ReadCase() {
	int r, n, c, i;
	int nr, j;
	scanf("%d%d",&R,&C);
	if(!R && !C) return 0;
	scanf("%d",&nr);
	for(i = 0; i<nr; i++) {
		scanf("%d%d",&r,&n);
		for(j = 0; j<n; j++) {
			scanf("%d",&c);
			F[r][c] = 1;
		}
	}
	return 1;
}

int Bfs(int sr, int sc, int dr, int dc) {
	int i,  tr, tc;
	ss temp;
	if(sr == dr && sc == dc) return 0;
	F[sr][sc] = 1;
	qh = qt = 0;
	Push(sr,sc,0);
	while(qh != qt) {
		temp = Pop();
		for(i = 0; i<4; i++) {
			tr = temp.r + mx[i];
			tc = temp.c + my[i];
			if(tr>=R || tr<0 || tc>=C || tc<0) continue;
			if(tr == dr && tc == dc) return temp.move+1;
			if(F[tr][tc] == 1) continue;
			F[tr][tc] = 1;
			Push(tr,tc,temp.move+1);
		}
	}
	return -1;
}

void Cal() {
	int sr,sc,dr,dc;
	scanf("%d%d",&sr,&sc);
	scanf("%d%d",&dr,&dc);
	printf("%d\n",Bfs(sr,sc,dr,dc));
}

int main() {
	while(ReadCase()) {
		Cal();
		Reset();
	}
	return 0;

}
