#include<stdio.h>

#define MAXN 30002

struct Friends {
	int parent;
	int rank;
	int count;
}F[MAXN];

int N, M, MAX;

int Find(int n) {
	if(n != F[n].parent)
		F[n].parent = Find(F[n].parent);
	return F[n].parent;
}

void Link(int x, int y) {
	if(F[x].rank>F[y].rank){
		F[y].parent = x;
		F[x].count += F[y].count;
		if(MAX<F[x].count)
			MAX = F[x].count;
	}
	else {
	   F[x].parent = y;
	   F[y].count += F[x].count;
	   if(MAX<F[y].count)
			MAX = F[y].count;
	   if(F[x].rank == F[y].rank)
		   F[y].rank++;
	}
}

void Cal() {
	int i, a, b, x, y;
	MAX = 0;
	for(i = 1; i<= N; i++){
		F[i].parent = i;
		F[i].rank = 0 ;
		F[i].count = 1;
	}
	for(i = 1; i<= M; i++) {
		scanf("%d%d",&a, &b);
		x = Find(a);
		y = Find(b);
		if(x != y) 
			Link(x,y);
	}
	printf("%d\n",MAX);
}

int main() {
	int n;
	scanf("%d",&n);
	while(n--) {
		scanf("%d%d",&N,&M);
		Cal();
	}
	return 0;

}
