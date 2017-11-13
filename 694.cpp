#include<stdio.h>

long long start,limit,n;

int cycle()   {

    long long p = start;
	n = 0;
	while(p <= limit && p != 1)  {
		if(p % 2 == 0)
			p = p / 2;
		else
			p = 3 * p + 1;
      n ++;	
	}
	if(p == 1) n ++;
	return 0;
}


int main()  {

	long long  kase = 0;
	while(1)   {
		scanf("%lld%lld",&start,&limit);
		if( start <0 && limit < 0) break;
		cycle();
		printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",++kase,start,limit,n);
 
	}
	return 0;
}
