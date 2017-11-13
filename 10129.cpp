#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXN 100002

struct node {
	int rank;
	int parent;
}X[MAXN];

struct xx {
	int st, en;
	int first, last;
}tt[30];

int Dg[30], In, N, E;

void Set() {
	int i;
	for(i = 0; i<= N; i++) {
		Dg[i] = 0;
		X[i].rank = 0;
		X[i].parent = i;
	}
	for(i = 0; i<= 29; i++){
		tt[i].st = tt[i].en = 0;
		tt[i].first = tt[i].last = 0;
	}
}

int Find(int n) {
	if(X[n].parent != n)
		X[n].parent = Find(X[n].parent);
	return X[n].parent;
}

void Link(int x, int y) {
	if(X[x].rank > X[y].rank)
		X[y].parent = x;
	else {
		X[x].parent = y;
		if(X[y].rank > X[x].rank)
			X[y].rank++;
	}
}

char str[1002];


void Union(int p , int q, int k) {
	int x, y;
	if(tt[p].en != 0) {
		x = Find(k);
		y = Find(tt[p].en);
		if(x != y){
			Link(x,y);
			E++;
		}
	}
	if(tt[q].st != 0)  {
		x = Find(k);
		y = Find(tt[q].st);
		if(x != y){
			Link(x,y);
			E++;
		}
	}
	if(tt[p].st == 0) tt[p].st = k;
	if(tt[q].en == 0) tt[q].en = k;
}


void Cal() {
	int i, j = 0;
		if(E< N-1){
		printf("The door cannot be opened.\n");
		return;
	}
	for(i = 1; i<= N; i++) {
		if(tt[i].last != tt[i].first){ 
			j++;
			if(abs(tt[i].last - tt[i].first)>1) {
				printf("The door cannot be opened.\n");
				return;
			}
		}
		if(j > 2) {
			printf("The door cannot be opened.\n");
			return;
		}
	}
	printf("Ordering is possible.\n");
}

int main() {
	int kase, i, u, v;
	scanf("%d",&kase);
	while(kase--) {
		scanf("%d",&N);
		Set();
		E = 0;
		for(i = 1; i<=N; i++) {
			scanf("%s",str);
			u = str[0] - 'a'+1;
			v = str[strlen(str)-1] - 'a'+1;
			Union(u,v, i);
			tt[u].first ++;
			tt[v].last++;
		}
		Cal();
	}
	return 0;
}
