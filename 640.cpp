#include<stdio.h>
#include<math.h>
#define MAXN 1000001

char a[MAXN+3];

int digit(int n)
{
	int sum=0;
	while(n)
	 {
		 sum+=n%10;
		 n=n/10;
	 }
	 return sum;
}


 int main()
 {

	 int i,d,k,c=0;
	 for(i=1;i<=MAXN;i++) a[i]=1;
	 for(i=1;i<=MAXN;)
	   {
		  k=i;
		  while(1)
		   {
		      d = digit(k)+k;
		      if(d>=MAXN || !a[d]) break;
			   a[d]=0;
			  k=d;
		  }
	           for (i++; !a[i] && i<MAXN; i++);  
                                 
	 }


	   for(i=1;i<MAXN;i++)
	     if(a[i]) 
	      printf("%d\n",i);
	 	
			 
	   return 0;
 }
