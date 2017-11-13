#include<stdio.h>
#include<math.h>
int p[32772];
void compute_prime_table() 
{
  long i,j;

  p[0] = p[1] = 0;
  for (i=2; i<=32768; i++) p[i]=1;
  for (i=2; i<=181;) 
    {
      for (j=i+i; j<=32768; j+=i) p[j]=0;  
      for (i++; !p[i]; i++);  
    }
}

main()
{
  long n,i,j,count;
  compute_prime_table();
  while(scanf("%ld",&n)&&n)
	{
		if(n==4) { printf("1\n"); continue;}
		count=0;
		for(i=3;i<=16384;i+=2)
		{
			if(p[i])
			{
			   for(j=n-3;j>=i;j-=2)
			   {
				  if(p[j])
				  {
					  if(i+j==n)
					  {		  
						  count++;
					      if((i+j)<n)
						  break;
					  }
				  }
			   }
			}
		}
         printf("%ld\n",count);
	}
	return 0;
}
