#include<stdio.h>
#define MAXN 10002
#define MAX(a, b) (a>b?a:b)

int Bed[MAXN], N;

void Cal() {
	int i,  max,k;
	scanf("%d",&Bed[0]);
	max = Bed[0];
	for(i = 1; i<N; i++) {
			scanf("%d",&Bed[i]);
			k = Bed[i] + Bed[i-1];
			Bed[i] = MAX(Bed[i],k);
			max = MAX(max,Bed[i]);
	}
	if(max<=0)
		printf("Losing streak.\n");
	else
		printf("The maximum winning streak is %d.\n",max);
}


int main() {
//	int i;
	while(scanf("%d",&N) == 1) {
		if(!N) break;
//		for(i = 0; i<N; i++)
//			scanf("%d",&Bed[i]);
		Cal();
	}
	return 0;

}
