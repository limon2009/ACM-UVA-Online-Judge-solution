#include<stdio.h>
#include<stdlib.h>
#define MAXN 1002

struct job {
	int ind;
	int day;
	int fine;
}J[MAXN];

int N;

int com(const void *a, const void *b) {
	int m, n;
	job *x = (job *)a;
	job *y = (job *)b;
	m = x->fine * y->day;
	n = x->day * y->fine;
	if(m != n) {
		return n - m;
	}
	return x->ind - y->ind;
}
void Print() {
	int i;
	printf("%d",J[0].ind);
	for(i = 1; i<N; i++)
		printf(" %d",J[i].ind);
	printf("\n");
}
int main() {
	int ks;
	scanf("%d",&ks);
	while(ks--) {
		scanf("%d",&N);
		for(int i = 0; i<N; i++) {
			scanf("%d%d",&J[i].day,&J[i].fine);
			J[i].ind = i+1;
		}
		qsort(J,N,sizeof(job),com);
		Print();
		if(ks) printf("\n");
	}
	return 0;

}


