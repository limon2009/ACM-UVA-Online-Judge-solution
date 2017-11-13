#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXN 25

char input[500];

struct ss {
	char impossible;
	char visit;
}U[MAXN];

struct xx{
	int list[MAXN];
	int ind;
}vertex[MAXN];


int N, OK;
char node[MAXN];
char Link[MAXN][MAXN];
int   A[MAXN];
int Pos[MAXN];

int com(const void *a, const void *b) {
	return *(char*)a - *(char *)b;
}

void Getnode() {									//Ok
	int i;
	N = 0;
	for(i = 0; input[i]; i++) {
		if(isalpha(input[i]))
			node[N++] = input[i];
	}
	node[N] = NULL;
	qsort(node,N,sizeof(node[0]),com);
	for(i = 0; i<N; i++) {
		Pos[node[i] - 'A'] = i;
	}
}


void MakeLink() {									// OK
	char *p, u, v;
	p = strtok(input," ");
	while(p) {
		u = p[0] - 'A';
		v = p[2] - 'A';
		u = Pos[u];
		v = Pos[v];
		U[v].impossible = 1;
		vertex[u].list[vertex[u].ind++] = v;
		p = strtok(NULL, " ");
	}

}

void Mark(int n, int m) {					//OK
	int i, v;
	U[n].visit = 1;
	for(i = 0; i<vertex[n].ind; i++) {
		v = vertex[n].list[i];
		if(U[v].visit == 0){
			Link[v][m] = 1;
			Mark(v, m);
		}
	}
}

void Print() {
	int i, n;
	printf("%c",node[A[1]]);
	for(i = 2; i<= N; i++) {
		n = A[i];
		printf(" %c",node[n]);
	}
	printf("\n");
}

void Recur(int n, int level) {
	int i, j, f, u;
	A[level] = n;
	U[n].visit = 1;
	if(level == N) {
		Print();
		OK = 1;
		U[n].visit = 0;
		return;
	}
	for(i = 0; i<N; i++) {
		if(U[i].visit) continue;
		f = 1;
		for(j = 1; j<=level; j++) {
			u = A[j];
			if(Link[u][i]) { f = 0; break; }
		}
		if(f)
			Recur(i,level+1);
	}
	U[n].visit = 0;
}

void Cal() {
	int i, j;
	OK = 0;
	for(i = 0; i<N; i++) {
		Mark(i, i);
		for(j = 0; j<N; j++) U[j].visit = 0;
	}
	for(i = 0; i<N; i++) {
		if(U[i].impossible) continue;
		Recur(i,1);
	}
	if(!OK) printf("NO\n");
}

void Reset() {
	int i, j;
	for( i = 0; i<=N; i++) {
		U[i].impossible = U[i].visit = 0;
		for(j = 0; j<=N; j++)
			Link[i][j] = 0;
		vertex[i].ind = 0;
	}
}
int main() {
	int kases;
//	freopen("c:\\key.txt","r",stdin);
	gets(input);
	sscanf(input,"%d",&kases);
	gets(input);
	while(kases--) {
		gets(input);
		Getnode();
		gets(input);
		MakeLink();
		Cal();
		if(kases) {
			Reset();
			gets(input);
			printf("\n");
		}
	}
	return 0;

}
