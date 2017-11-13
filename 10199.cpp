#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXN 102

char city[MAXN][31];

struct ss {
	char city[32];
	int index;
}pp[MAXN], key1, key2;

struct edg {
	int a, b;
}Ed[MAXN*MAXN];

int p[MAXN], rank[MAXN];
int M, N, E, Or;

int com(const void *a, const void *b) {
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	return strcmp(x->city,y->city);
}

void Ini() {
	int i;
	for(i = 1; i<= N; i++) {
		p[i] = i;
		rank[i] = 0;
	}
}

int Find(int s) {
	if( s != p[s]) 
		p[s] =  Find(p[s]);
	return p[s];
}

void Link(int x, int y) {
	if(rank[x] > rank[y]) 
		p[y] = x;
	else {
		p[x] = y;
		if(rank[x] == rank[y])
			rank[y]++;
	}
}

void ReadCase() {
	int i, p, q;
	ss *in1, *in2;
	scanf("%d",&M);
	Ini();
	qsort(pp,N,sizeof(pp[0]),com);
	for(i = 0; i<M; i++) {
		scanf("%s%s",key1.city,key2.city);
		in1 = (ss *) bsearch(&key1,pp,N,sizeof(pp[0]),com);
		in2 = (ss *) bsearch(&key2,pp,N,sizeof(pp[0]),com);
		Ed[E].a = in1->index;
		Ed[E++].b = in2->index;
		p = Find(in1->index);
		q = Find(in2->index);
		if(p != q) {
			Link(p, q);
			Or--;
		}
	}
}

void SolvedCase(int Kase) {
	int i, j, temp, indx;
	int x, y, k = 0;
	for(i = 0; i<N; i++) {
		indx = pp[i].index;
		Ini();
		temp = N;
		for(j = 0; j<E; j++) {
			if(Ed[j].a == indx ||Ed[j].b == indx) continue;
			x = Find(Ed[j].a);
			y = Find(Ed[j].b);
			if(x != y) {
				temp --;
				Link(x, y);
			}
		}
		if(temp-1 >Or) 
			strcpy(city[k++],pp[i].city);
	}
	printf("City map #%d: %d camera(s) found\n",Kase, k);
	if(!k) return;
	for(i = 0; i<k; i++) printf("%s\n",city[i]);
	
}

int main() {
	int i, Kase = 1;
	while(scanf("%d",&N) && N) {
		E = 0;
		Or = N;
		for(i = 0; i<N; i++) {
			scanf("%s",pp[i].city);
			pp[i].index = i+1;
		}
		ReadCase();
		if(Kase>1) printf("\n");
		SolvedCase(Kase);
		Kase++;
	}
	return 0;
}

