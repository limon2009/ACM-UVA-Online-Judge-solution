#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 65005
	
char pp[MAXN];


int prime_table()   {

       int i,j;
       for(i = 2; i<MAXN; i ++) pp[i] = 1;

       for(i = 2; i<=sqrt(MAXN); ) {
	 for(j = i+i; j<MAXN; j +=i)
	   pp[j] = 0;
	 for(i ++; !pp[i]; i ++);
       }

      return 0;
}



int prime(unsigned long n)
{
     unsigned long q,m,z;
     unsigned long i,y,a;
     q=n;
     for(i=0;i<8;i++)
     {
	 m = q;
	 y = 1;
	 a = (rand()%(q-1));
	 z = a;
	 while(m>0)
	 {
	      while(!(m%2))
	      {
		  z=(z*z)%n;
		  m=m/2;
	      }
	      m-=1;
	      y=(y*z)%n;
	 }
	 if(y!=a) return 0;
     }
     return 1;
}




int main()
{

       unsigned long n;

       prime_table();

       while(1)
       {
	     scanf("%ld",&n);

	     if(n == 0) break;

	     if( !pp[n] && prime(n))
	       printf("The number %u is a Carmichael number.\n",n);
	     else
	       printf("%u is normal.\n",n);
       }
       return 0;
}
