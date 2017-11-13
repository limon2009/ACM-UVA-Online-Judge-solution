#include<stdio.h>

char ch[3] = "->";

long  lnjd(long n)
{
   long k,c=0,d=1,sum=0;
   while(n)
   {
	k=n%10;
	n=n/10;
	if(k!=0||c!=0)
	{
	   sum+=k*d;
	   d=d*10;
	   c++;
	   if(c==5)  break;

	}
   }
   return sum;
}



int main()
{
    long n,m,i,k,sum;
    long i2;

    while(scanf("%ld",&n)!=EOF)
    {
	 printf("%5ld",n);
	 printf(" %s",ch);
	 sum = 1;
	    i= 1;
	 while(i<=n)
	 {
	     i2=lnjd(i);
	     sum*=i2;
	     sum=lnjd(sum);
	     i++;
	 }
	 printf("% ld\n",sum%10);
    }
    return 0;
}








