#include<stdio.h>

#define MAXN 55

int S[MAXN][MAXN];
int A[MAXN];
int N, L;

void Ini() {
	int i;
	for(i = 0; i<= N; i++) {
		S[i][i]		= 0;
		S[i][i+1]	= 0; 
	}
}

void Cal() {
	int i, j, k, l;
	int inf = 1000000;
	int n = N+1, q;
	for(l = 2; l<= n; l++) {
		for(i = 0; i<=n-l; i++) {
			j = i+l;
			S[i][j] = inf;
			for(k = i+1; k<j; k++) {
				q = S[i][k] + S[k][j] + A[j] - A[i];
				if(S[i][j] > q)
					S[i][j] = q;
			}
		}
	}
	printf("The minimum cutting is %d.\n",S[0][n]);
}

int main() {
	int f = 0, i;
	while(scanf("%d",&L)==1) {
		if(!L) return 0;
		scanf("%d",&N);
		if(f++)	Ini();
		for(i = 1; i<=N; i++)
			scanf("%d",&A[i]);
		A[i] = L;
		Cal();
	}
	return 0;
}
