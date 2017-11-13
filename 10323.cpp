#include<stdio.h>

#define UP 6227020800
#define LO 10000

void Call(long long n) {
    if(n % 2) printf("Overflow!\n");
    else printf("Underflow!\n");
}

int main() {
      long long n, sum;
      while(scanf("%lld",&n) == 1) {
	   if(n<0) { Call(n); continue; }
	   sum = 1;
	   for(int i = 1; i<= n; i++) {
		       sum *= i;
		       if(sum > UP) break;
	   }
	   if(sum > UP) printf("Overflow!\n");
	   else if(sum<=UP && sum>= LO) printf("%lld\n",sum);
	   else printf("Underflow!\n");
      }
	return 0;

}
