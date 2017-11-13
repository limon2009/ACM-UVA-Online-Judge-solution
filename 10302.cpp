#include<stdio.h>
#include<math.h>

main()  {
   long long n,r;
   while(scanf("%lld",&n) == 1) {
	r = n * n * (n+1) * (n+1) / 4;
	printf("%lld\n",r);
   }
	return 0;

}
