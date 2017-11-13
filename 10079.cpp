#include<stdio.h>
#include<math.h>

long long N;
int main() {
	long long  x;
	while(scanf("%lld",&N) == 1) {
		if(N<0) break;
        x = N * N + N;
		x = x/2 + 1;
		printf("%lld\n",x);
	}
	return 0;

}
