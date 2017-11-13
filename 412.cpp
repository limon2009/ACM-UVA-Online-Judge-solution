#include<stdio.h>
#include<math.h>


int a[60],N,k;

int gcd(int a,int b)  { return b ? gcd(b,a%b) : a;  }



int count()  {

   int i,j;
   k = 0;
   for(i = 0; i<N-1;  i ++)
     for(j = i+1; j<N;  j ++)
	if(gcd(a[i],a[j]) == 1)
	   k ++;
   return 0;
}

int calculate()  {

    int pair;
    double pi,x,y;
    if( !k )  { printf("No estimate for this data set.\n");  return 0; }
    pair = (N * (N-1)) / 2;
     x = pair;
     y = k;
    pi = sqrt(( x * 6) / y);
    printf("%.6lf\n",pi);
    return 0;
}


int main()  {

    int i;
    while(scanf("%d", &N) && N) {

      for(i = 0; i<N; i ++)
	 scanf("%d", &a[i]);

      count();
      calculate();
    }
    return 0;
}
