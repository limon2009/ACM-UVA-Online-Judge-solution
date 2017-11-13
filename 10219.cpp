#include<stdio.h>
#include<math.h>

double sum;
long long N, K;

void Cal() {
   long long i, d = 1, temp;
   double num, den;
   sum = 0;
   temp = K>(N-K)?K:N-K;
   for(i = temp+1; i<= N; i++) {
       num = (double)i;
	   den = double(d);
	   sum += log10(num/den);
	   d++;
   }
   sum = floor(sum) + 1;
   printf("%.lf\n",sum);
}
int main() {
	while(scanf("%lld%lld",&N,&K) == 2) {
		if(N ==K) { printf("1\n"); continue; }
		Cal();
	}
	return 0;

}
