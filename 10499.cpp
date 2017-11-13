#include<stdio.h>
 
long long N;
char P[123] = "%";
int main() {
	while(1) {
		scanf("%lld",&N);
		if(N <0) break;
		if(N == 1) printf("0%s\n",P);
		else {
			printf("%lld%s\n",N * 25,P);
		
		}
	}
	return 0;

}
