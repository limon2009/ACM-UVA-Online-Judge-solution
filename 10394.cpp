#include<stdio.h>
#include<math.h>
#define max 19000000
char p[max];
int  a[121105];
void prime_table()
{
	long i,j,c=0;
	for(i=2;i<max;i++) p[i]=1;
	for(i=2;i<=sqrt(max);  )
	{
		
		for(j=i+i;j<=max;j+=i)
			p[j]=0;
           	i++;
		for( ;!p[i];i++);
	}	

	 
    
}

main()
{
    long n,d=3,c,i,e=1;
	prime_table();
     
	for(i=3;i<=max;i+=2)
	{   
		if(p[i]&&p[i+2])
		{
			a[e++]=i;
	      
		}	 
	} 
		
	while(scanf("%ld",&n)==1)
	 {
		 	
		 printf("(%d, %d)\n",a[n],a[n]+2);
	 }
	 return 0;
}
