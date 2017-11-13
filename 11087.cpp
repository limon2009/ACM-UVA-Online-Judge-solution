#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define maxn 1002

typedef int SS;
int K;
int A[maxn];
int N[100002];

SS count;

int Com(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}


SS NCR(int n) {
	int m = n-1;
	if(m % 2)
		return (n/2)*m;
	return n*(m/2);
}


void Pos(int n) {
	int d;
	d = K - n + K;
	n += K;
	if(d != n) 
		count += A[d] * A[n];
	else 
		count += NCR(A[d]);
}

void Neg(int n) {
	int negn, d;
	negn = -n;
	d = -(K - n) + K;
	negn += K;
	if(negn != d)
		count += A[negn] * A[d];
	else 
		count += NCR(A[negn]);
}

void Cal() {
	int i;
	for(i = 1; i<=K/2; i++) {
		Pos(i);
		Neg(i);
	}
	count += NCR(A[K]);
	printf("%d\n",count);
}

void Setting(int n) {
	int i, c = 0, d;
	qsort(N,n,sizeof(int),Com);
	count = 0;
	d = N[0] % K;
	d += K;
	A[d]++;
	for(i = 1; i<n; i++) {
		if(N[i] == N[i-1]) {
			c++;
			if( c == 1) {
				if(2*N[i] % K == 0)
					count++;
			}
		}
		else {
			c = 0;
			d = N[i] % K;
			d += K;
			A[d]++;
			if(N[i] > 0 && d!= K) {
				d -= K;
				d = K- d;
				count += A[d];
			}
		}
	}
}

void Free() {
	int i;
	for(i = 0; i<2*K; i++)
		A[i] = 0;
}


int main() {
	int k = 1, kase, n,i;
//	freopen("c:\\h.txt","r",stdin);
//	freopen("c:\\out.txt","w",stdout);
	scanf("%d",&kase);
	while(kase--) {
		scanf("%d%d",&n,&K);
		for(i = 0; i<n; i++) {
			scanf("%d",&N[i]);
		}
		Setting(n);
		printf("Case %d: ",k++);
		Cal();
		Free();
	}
	return 0;

}
