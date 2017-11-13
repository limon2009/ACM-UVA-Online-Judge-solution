#include <stdio.h>
#include <stdlib.h>

#define MAXN 102

struct store{
	int I;
	store *af;
};

store *list;

struct node {
	int nodeNum;
	node *next;
};
struct vertex {
	char color;

	node *next;
};

vertex V[MAXN];

void addEdge(int u, int v) {
	node *p = (node*)malloc(sizeof(node));
	p->nodeNum = v;
	p->next = V[u].next;
	V[u].next = p;
}

int time;

void DFSVisit(int u) {
	time ++;	
	node *vptr = V[u].next;
	while (vptr!=NULL) {
		int v = vptr->nodeNum;
		if (V[v].color=='W') {
			DFSVisit(v);
		}
		vptr = vptr->next;
	}
	store *p = (store *)malloc(sizeof(store));
	p ->I = u;
	p->af = list;
	list = p;
	V[u].color = 'B';
	
}


void make_null(int N) {
	int u;
	for(u = 1; u<= N; u++)
     V[u].next = NULL;
}


void DFS(int N) {
	int u;
	for (u=1; u<=N; u++) {
		V[u].color = 'W';
	}
	
	time = 0;
    
	for (u=1; u<=N; u++) {
		if (V[u].color == 'W')
			DFSVisit(u);
	}
}


void topology() {
	store *k = list;
	while(k != NULL) {
		printf("%d ",k->I);
		k = k->af;
	}
	putchar('\n');
}


int main() {
	int N, E, u, v;
	list = NULL;
	while(1) {
	  scanf("%d %d",&N,&E);
	  list = NULL;
	  if( N==0 && E ==0) break;
	  while (E--) {
		scanf("%d %d",&u,&v);
		addEdge(u,v);
	  }
		
		DFS(N);
		topology();
	    make_null(N);
	}
	return 0;
}
