#include<stdio.h>
#include<math.h>

	     int main()
	     {
		 int kase,count,n,k=0,M,digit;
		 long i,sum;

		 scanf("%d", & kase);

		 while(k!=kase)
		 {
		    count = 0;
		    scanf("%d", & M);
		    for(i=M;i;i=i/2)
		     if(i%2)
		       count++;

		    printf("%d ",count);
		    count = 0;
			n = 0;
		      sum = 0;

		    while(M)
		    {
		       digit = M%10;
		       sum+=digit*pow(16,n);
		       M=M/10;
		       n++;
		    }

		    for(i=sum;i;i=i/2)
		     if(i%2)
		      count++;

		    printf("%d\n",count);
		    k++;
		 }
	    
	return 0;
 }
