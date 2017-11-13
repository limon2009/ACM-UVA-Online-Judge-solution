#include<stdio.h>

char a[1050],b[1050],d[1050];
char fibs[5001][1052];
int k,digit[5000];

 int fbs()
{
     int sum,c,ck,l,i,count;
     for(i = 0; i <1050; i ++)  a[i] = b[i] = d[i] = 0;
     b[0]  = 1;
       ck  = 0;
     count = 0;
	 k = 0;

     for(i = 0;i <5000; i ++)
     {
	      sum = 0;
	        k = 0;
	        c = 0;
	   while(1)
	   {
	      sum =a[k] + b[k] + c;
	      if(!sum && ck <= k) break;
	      d[k] = sum % 10;
	      c = sum / 10;
	      k ++;
	   }
 
	   digit[i] = k;
	   for(l = 0;l<k; l ++)
	   {
	      b[l]=a[l];
	      a[l]=d[l];
	      fibs[i][l] = d[l];
	   }
	   ck = k;

     }
    
	 return 0;

}



int main()
{
       int fib,l,k;

       fbs();

       while(scanf("%d", &fib) == 1)
       {
	  if(fib<1)
	  {
	     printf("0\n",fib);
	     continue;
	  }

	  k = digit[fib-1];
	  for(l = k-1; l>=0; l --) printf("%d",fibs[fib-1][l]);

	  printf("\n");

       }
 return 0;
}
