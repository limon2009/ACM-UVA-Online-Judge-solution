#include<stdio.h>
#define max  100

		      int main()
		      {

			 long sum=0,a[max];
			 int i=0,j,k,n;
			 while(1)
			 {
			    scanf("%ld",&a[i]);
			    if(!a[i]) break;
			    i++;
			 }

			 printf("PERFECTION OUTPUT\n");

			 for(j=0;j<i;j++)
			 {
			    sum=0;
			    for(k=1;k<=a[j]/2;k++)
			    {
			       if(!(a[j]%k))
				 sum+=k;
			    }

			    if(sum==a[j])
			     printf("%5ld  PERFECT\n",a[j]);

			    else if(sum>a[j])
			     printf("%5ld  ABUNDANT\n",a[j]);

			    else
			     printf("%5ld  DEFICIENT\n",a[j]);

			 }
			 printf("END OF OUTPUT\n");
		     
	return 0;
 }
