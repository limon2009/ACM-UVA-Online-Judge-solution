#include<stdio.h>


unsigned long long S,N,K;

void CAL() {
   int b = 0, q;
   S = 0;
   while(N >= K) {
     S += N;
     b += N % K;
     N /= K;
     N += b / K;
     b = b % K;
   }
   b += N % K;
   N += b / K;
   printf("%llu\n",S+N);
}



int main()  {

	while(scanf("%llu%llu",&N,&K) == 2)  {
	   if(N == 0) { printf("0\n"); continue; }
	   if(K == 0) { printf("%llu\n",N); continue; }
	   CAL();
	}
	return 0;

}
