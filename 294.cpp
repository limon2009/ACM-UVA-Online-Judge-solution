#include<stdio.h>
#include<math.h>
#define max1 31700
#define max2 31630

char a[max1];
int p[10000];

int prime_table()  {

   int i,j,k;
   for(i = 2; i <= max2; i ++) a[i] = 1;
   for(i = 2; i <= sqrt(max2); )  {
     for(j = i+i; j <= max2; j += i)
       a[j] = 0;
     for(i++ ; !a[i]; i ++);
   }

   k = 0;
   for(i = 2; i <= max2; i ++)
     if(a[i])
       p[k ++] = i;

  return 0;
}


long divisor(long n)  {

     long i,j,k;
     long div,c;
     div = 1;
     for(i = 0; p[i] <= sqrt(n); i ++)  {

	  c = 0;
	  while( n % p[i] == 0)  {
	     n = n / p[i];
	     c ++;

	  }

	  div *= (c+1);
	  if( n == 1 ) break;
     }

     if( n != 1)
       div *= 2;

     return div;
}



int main()   {

       long i,k,j,U,L,kase;
       long max = 0,record;

       prime_table();

       scanf("%ld", &kase);
       while(kase -- )  {

	   scanf("%ld%ld",&L,&U);

	      max = 0;
	      for(i = L; i <= U; i ++)    {
		 k = divisor(i);
		 if(k > max)  {
		    record = i;
		    max = k;
		 }
	      }
	    printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n",L,U,record,max);

       }
       return 0;
}
