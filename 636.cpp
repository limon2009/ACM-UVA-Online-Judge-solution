#include<stdio.h>
#include<math.h>


int COM(int N,int b) {
       int sum = 0;
       int p = 0;
       int  a;
       while(N)  {
	  sum += (N % 10 ) * ( pow(b,p));
	  N = N / 10;
	  p ++;
       }

      a = sqrt((double)sum);
      if( a*a == sum) return 1;

      return 0;
}


int big(int n)   {
    int max = 0;
    int k;
    while(n) {
      k = n % 10;
      if(k>max) max = k;
      n /= 10;
    }
    return max;
}


void CAL(int n)  {
  int i,j,k;
  k = big(n);
  for(i = k+1; i<=99; i ++)
    if(COM(n,i))
      break;
  printf("%d\n",i);
}

int main() {
  int n;
  while(scanf("%d",&n) && n)
    CAL(n);
	return 0;

}
