#include<stdio.h>

#define MAXN 1000000

char ss[MAXN+3];
int P[78499], K;

void Prime_table() {
	int i, j;
	for(i = 2; i*i<MAXN; ) {
		for(j = i+i; j<= MAXN; j+= i)
			ss[j] = 1;
		for(i++; ss[i]; i++);
	}
	P[0] = 2;
	K = 1;
	for(i = 3; i<MAXN; i+=2) if( !ss[i]) P[K++] = i;
}

void Cal(int n) {
	int i, j = 0;
	for(i = 0; P[i]*P[i] <= n && i<K; i++) {
		if(n%P[i] == 0) {
			j++;
			while(n%P[i] == 0) {
				n /= P[i];
			}
		}
		if(n == 1) break;
	}
	if(n != 1)		j++;
	printf(": %d\n",j);
}

int main() {
	Prime_table();
	int n;
	while(scanf("%d",&n) && n) {
		printf("%d ",n);
		Cal(n);
	}
	return 0;

}
