#include<stdio.h>

typedef unsigned long long ss;

ss A[65][65];

ss Recur(int n, int m) {
	ss sum = 0;
	int i;
	if(n<= 1) return 1;
	if(A[n][m]) return A[n][m];
	for(i = 1; i<= m; i++)
		sum  += Recur(n-i,m);	
	A[n][m] = sum+1;
	return A[n][m];
}

int main(){
	int n, m, kases = 1;
	while(scanf("%d%d",&n,&m) == 2) {
		if(n>60) break;
		printf("Case %d: %llu\n",kases++,Recur(n,m));
	}
	return 0;

}
