#include<stdio.h>
#include<string.h>


#define MAXN 101

char Link[MAXN][MAXN];

struct SS{
	char cl;
}V[MAXN];

int N , C;

void DFSVisit(int u) {
     
	for(int i = 1; i<= N; i++){
		if(Link[u][i] == 1 && V[i].cl == 'w') {
			V[i].cl = 'r';
			C++;
			DFSVisit(i);
		}
	}


}

void DFS(int st) {
     int i;
	 for(i = 1; i<= N; i++)
		 V[i].cl = 'w';
	 C = 0;
	 DFSVisit(st);
	 printf("%d",N - C);
	 for(i = 1; i<= N; i++)
		 if(V[i].cl == 'w') printf(" %d",i);
     printf("\n");

}


int main() {
	int st, u, q;
	while(1) {
		scanf("%d",&N);
		if(N == 0) break;
		while(1) {
			scanf("%d",&st);
			if(st == 0) break;
            while(1) {
				scanf("%d",&u);
				if(u == 0) break;
				Link[st][u] = 1;
			}
		}
        scanf("%d",&q);
		while(q--) {
			scanf("%d",&st);
			DFS(st);
		}
	
	    for(int i = 0; i<MAXN; i++)
			memset(Link[i],0,sizeof(char)*MAXN);
	}
	return 0;

}
