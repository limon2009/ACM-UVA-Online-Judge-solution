#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>

using namespace std;

#define MAXN 102
#define INF 1000000000

struct ss {
	int list[MAXN];
	int ind;
	int time;
};


struct node {
	int r, c;
};

ss Lift[7];
queue<node>Q;
char F[7][MAXN];
char H[7][MAXN];
char Str[1000];
int C[7][MAXN];
int Ad[7][MAXN];
int L, T, R;

void ReadCase() {
	int i = 1, k, min = 10000;
	char *p;
	p = strtok(Str, " ");
	while(p) {
		Lift[i++].time = atoi(p);
		p = strtok(NULL," ");
		if(Lift[i-1].time < min) {
			min = Lift[i-1].time;
			R = i-1;
		}
	}
	for(i = 1; i<= L; i++) {
		Lift[i].ind = 0;
		gets(Str);
		p = strtok(Str," ");
		while(p) {
			k = atoi(p);
			Lift[i].list[Lift[i].ind++] = k;
			H[i][k] = 1;
			C[i][k] = INF;
			Ad[i][k] = Lift[i].ind-1;
			p = strtok(NULL, " ");
		}
	}
}

void Back(int r, int c) {
	int d, m, n, k;
	node x;
	if(c <= 0) return;
	d = abs(Lift[r].list[c-1] - Lift[r].list[c]);
	n = Lift[r].list[c];
	m = Lift[r].list[c-1];
	k = d * Lift[r].time + C[r][n];
	if(C[r][m] > k) {
			C[r][m] = k;
			x.r = r;
			x.c = c-1;
			if(F[r][m] == 0) {
				Q.push(x);
				F[r][m] = 1;
			}
			Q.push(x);
	}
}

void Front(int r, int c) {
	int d, m, n, k;
	node x;
	if(c >= Lift[r].ind-1) return;
	d = abs(Lift[r].list[c+1] - Lift[r].list[c]);
	n = Lift[r].list[c];
	m = Lift[r].list[c+1];
	k = d * Lift[r].time + C[r][n];
	if(C[r][m] > k) {
			C[r][m] = k;
			x.r = r;
			x.c = c+1;
			if(F[r][m] == 0) {
				Q.push(x);
				F[r][m] = 1;
			}
	}
}

void BFS() {
	node temp;
	int i, j, k, min = INF, r, c, m;
	for(i = 1; i<= L; i++) {
		if(H[i][0] == 1) {
			temp.r = i;
			temp.c = 0;
			C[i][0] = 0;
			Q.push(temp);
			F[i][0] = 1;
		}
	}
	while(!Q.empty()) {
		temp = Q.front();
		Q.pop();
		r = temp.r;
		c = temp.c;
		m = Lift[r].list[c];
		F[r][m] = 0;
		Back(r,c);
		Front(r,c);
		for(j = 1; j <= L; j++) {
			if(H[j][m] == 0) continue;
			k = C[r][m] + 60;
			if(C[j][m] > k) {
				C[j][m] = k;
				k = Ad[j][m];
				if(F[j][m] == 0) {
					F[j][m] = 1;
					temp.r = j;
					temp.c = k;
					Q.push(temp);
				}
			}
		}
	}
}

int BestCase() {
	if(H[R][0] == 1 && H[R][T] == 1) return 1;
	return 0;
}

int Impossible() {
	int i;
	if(R == INF) return 1;
	for(i = 1; i<= L; i++){
		if(H[i][T] == 1) return 0;
	}
	return 1;
}

void Cal() {
	int i, min = INF;
	if(Impossible()) {
		printf("IMPOSSIBLE\n");
		return;
	}
	if(BestCase()) {
		printf("%d\n",Lift[R].time * T);
		return;
	}
	BFS();
	for(i = 1; i<= L; i++) {
		if(H[i][T] == 0) continue;
		if(C[i][T] < min)
			min = C[i][T];
	}
	if(min == INF) puts("IMPOSSIBLE");
	else printf("%d\n",min);
}

void Free() {
	int i, j, k;
	for(i = 1; i<= L; i++) {
		for(j = 0; j<Lift[i].ind; j++) {
			k = Lift[i].list[j];
			H[i][k] = 0;
			F[i][k] = 0;
		}
	}
}

int Emt() {
	int i;
	for(i = 0; Str[i]; i++) {
		if(Str[i] == '\n') {
			Str[i] = NULL;
			break;
		}
	}
	if(strlen(Str) == 0) return 1;
	return 0;
}

int main() {
	
	while(gets(Str)) {
		if(Emt()) continue;
		sscanf(Str,"%d%d",&L,&T);
		gets(Str);
		R = INF;
		ReadCase();
		Cal();
		Free();
	}
	return 0;

}
