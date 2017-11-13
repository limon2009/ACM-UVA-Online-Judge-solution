#include<stdio.h>
int main()
{
	long int v,t,s=0;
	while(scanf("%ld%ld",&v,&t)!=EOF)
	{
		s=2*v*t;
		printf("%ld\n",s);
	}
	return 0;

}
