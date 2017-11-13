#include<stdio.h>

#define MAXN 50002

struct Friends {
	int parent;
	int rank;
}F[MAXN];

int N, M, MAX;

int Find(int n) {
	if(n != F[n].parent)
		F[n].parent = Find(F[n].parent);
	return F[n].parent;
}

void Link(int x, int y) {
	if(F[x].rank>F[y].rank)
		F[y].parent = x;

	else {
	   F[x].parent = y;
	   if(F[x].rank == F[y].rank)
		   F[y].rank++;
	   }
}

void Cal() {
	int i, a, b, x, y;
	MAX = N;
	for(i = 1; i<= N; i++){
		F[i].parent = i;
		F[i].rank = 0 ;
	}
	for(i = 1; i<= M; i++) {
		scanf("%d%d",&a, &b);
		x = Find(a);
		y = Find(b);
		if(x != y){ 
			Link(x,y);
			MAX --;
		}
	}
	printf("%d\n",MAX);
}

int main() {
	int kase = 1;
	while(1) {
		scanf("%d%d",&N,&M);
		if(!N && !M) break;
		printf("Case %d: ",kase++);
		Cal();
	}
	return 0;

}
