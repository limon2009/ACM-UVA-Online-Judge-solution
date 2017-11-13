#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAXN 25149
int  N, qh, qt, rec;

char  F[MAXN+2], St[MAXN+2][17];
int Rec[MAXN+10], P[MAXN+2];
int Q[MAXN+4];

struct link {
	int D[100];
	int ind;
}list[MAXN+2];

struct ss {
	char str[17];
	int ind;
}A[MAXN],dum, aa, bb;

int com(const void *a, const void *b) {
	ss *x, *y;
	x = (ss *)a;
	y = (ss *)b;
	return strcmp(x->str,y->str);
}

void Push(int n) {
	Q[qh++] = n;
	Rec[rec++] = n;
	qh %= MAXN;
}

int Pop() {
	int n;
	n = Q[qt++];
	qt %= MAXN;
	return n;
}

void Print(int n) {
	if(P[n] == -1) {
		printf("%s\n",St[n]);
		return;
	}
	Print(P[n]);
	printf("%s\n",St[n]);
}


int BFSVisit( int st ,int des) {
	int i,  k, lim, p;
	qh = qt = rec = 0;
	P[st] = -1;
	F[st] = 1;
	Push(st);
	while(qh != qt) {
		k = Pop();
		lim = list[k].ind;
		for(i = 0; i<lim; i++) {
			p = list[k].D[i];
			if(p == des) {
				P[p] = k;
				Print(p);
				return 1;
			}
			if(F[p]) continue;
			P[p] = k;
			F[p] = 1;
			Push(p);
		}
		
	}
	return 0;
}

void Sp(int st) {
	int i, d, f = 0;
	printf("%s\n",St[st]);
	for(i = 0; i<list[st].ind && i<1; i++){
		d = list[st].D[i];
		printf("%s\n",St[d]);
		f = 1;
	}
	if(f)
		printf("%s\n",St[st]);
}

void BFS() {

	int u,   f = 0;
	int i;
	char str[100];
	
	ss *c, *v;
	while(gets(str)) {
		for(i =  0; str[i]; i++) {
			if(str[i] == '\n')
				str[i] = NULL;
			if(strlen(str) == 0) break;
		}
		if(f++) printf("\n");
		sscanf(str,"%s%s",aa.str,bb.str);
		if(strlen(aa.str) != strlen(bb.str)) {
			printf("No solution.\n");
			continue;
		}
		c = (ss *) bsearch(&aa,A,N,sizeof(A[0]),com);
		v = (ss *) bsearch(&bb,A,N,sizeof(A[0]),com);
		if(!c || !v) {
			printf("No solution.\n");
			continue;
		}
		if(!strcmp(aa.str,bb.str)) {
			Sp(c->ind);
			continue;
		}
		for(i = 0; i<rec; i++) {
			u = Rec[i];
			F[u] = 0;
		}
		if(!BFSVisit(c->ind,v->ind)){
			printf("No solution.\n");
		}
	}
}

void Link() {
	int i,  p, k , mx = 0;
	int s, t, d;
	ss *c;
	for(k = 0; k< N; k++){
		d = A[k].ind;
		for(i = 0; A[k].str[i]; i++){
			strcpy(dum.str,A[k].str);
			for(p = A[k].str[i]+1; p<97+26; p++) {
				if(p != A[k].str[i]){
					dum.str[i] = p;
					c = (ss *) bsearch(&dum,A,N,sizeof(A[0]),com);
					if(c){
						s = list[d].ind;
						t = list[c->ind].ind;
						list[d].D[s] = c->ind;
						list[c->ind].D[t] = d;
						list[d].ind++;
						list[c->ind].ind++;
					}
				}
			}
		}
	}
	
}

void ReadCase() {
	int i;
	char temp[20];
	N = 0;
	while(gets(temp)) {
		for(i = 0; temp[i]; i++)
			if(temp[i] == '\n')
				temp[i] = NULL;
			if(strlen(temp) == 0) break;
		strcpy(A[N++].str ,temp);
		strcpy(St[N-1],temp);
		A[N-1].ind = N-1;
		
	}
}


int main() {
	
	ReadCase();
	qsort(A,N,sizeof(A[0]),com);
	Link();
	BFS();
	return 0;
}

