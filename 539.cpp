#include<stdio.h>
#include<string.h>
#define MAXN 26

int N,E;
char Link[MAXN][MAXN];
char A[MAXN],F[MAXN][MAXN];
int MAXL;


void DFS(int v,int level) {

	if(level > MAXL)
	   MAXL = level;

	for(int i = 0; i<MAXN;i ++) {
	  if(Link[v][i] && F[v][i] == 0 && F[i][v] == 0) {
	     F[v][i] = F[i][v] = 1;
	     DFS(i,level+1);
	     F[v][i] = F[i][v] = 0;
	  }
	}
}

void Cal() {
   int i, j;
   MAXL = 0;
   for(i = 0; i<MAXN;i ++)
     if(A[i] == 1)
       DFS(i,0);
   printf("%d\n",MAXL);
}


int main() {
    int i, j, a, b;
    while(1) {
       scanf("%d%d",&N,&E);
       if(N == 0 && E == 0) break;
	for(i = 0; i<E; i ++) {
	   scanf("%d%d",&a,&b);
	   Link[a][b] = Link[b][a] = 1;
	   A[a] = A[b] = 1;
	}
	Cal();
	for(i = 0; i<MAXN; i ++)   {
	  A[i] = 0;
	  memset(F[i],0,MAXN * sizeof(char));
	  memset(Link[i],0,MAXN * sizeof(char));
	}
    }
	return 0;

}
