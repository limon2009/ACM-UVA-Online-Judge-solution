#include<stdio.h>
#include<math.h>
#define MAXN 46400

char p[MAXN+1];
int a[6000];

int prime()
{
      int k=0,j;
      int i;
      for(i=1;i<MAXN;i++)
       p[i]=1;
      for(i=2;i<=sqrt(MAXN);)
	  {
	      for(j=i+i;j<=MAXN;j+=i)
	         p[j]=0;
	      for(i++;!p[i];i++);
	  }
      for(i=1;i<=MAXN;i++)
	  {
		  if(p[i]) a[k++]=i;
	  }
   
    return 0;

 }


int print(int n)
{

    int i;
    int s=sqrt(n);
    for(i=1;a[i]<=s;i++)
    {
       while(n%a[i]==0)
       {
	  n=n/a[i];
	  if(n!=1) { printf("%d ",a[i]);printf("x ");}
	  else printf("%d",a[i]);
       }
       if(n==1) { printf("\n");return 0;}
    }
	if(n!=1) printf("%d",n);
	printf("\n");

     return 0;
}


int main()
 {
     int n,s,i;
	 prime();
	 while(scanf("%d",&n) && n)
	{
	   printf("%d = ",n);
	   if(n==1) { printf("1\n"); continue;}
	   if(n==-1){ printf("-1 x 1\n"); continue;}
	   if(n<0)
	   {
	      printf("-1 x ");
	      n=n/-1;
	   }
	   print(n);
	}
    return 0;
}
