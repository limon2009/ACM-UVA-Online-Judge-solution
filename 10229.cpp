#include<stdio.h>
#include<math.h>
main()
{
    long i;
    long n,m,remainder,rem_1,rem_2,b,length;

    while(scanf("%ld %ld", &n, &m) == 2)
    {
	if(!n) {   printf("0\n"); continue;  }
	if(!m) {   printf("0\n"); continue;  }

	b = 3;
	for(i = 1; i<m; i ++) b *= 2;

	length = n%b;
	if(length == 0 )
	   length = b;

	m = pow(2,m);

	rem_1 = 0;
	rem_2 = 1;
	for(i = 1; i<= length; i ++)
	{
	   remainder = ( rem_1 + rem_2 ) % m;
	   rem_2 = rem_1;
	   rem_1 = remainder;
	}
	printf("%ld\n",remainder);
    }
    return 0;
}
