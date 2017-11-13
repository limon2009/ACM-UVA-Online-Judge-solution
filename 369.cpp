#include <stdio.h>

long n,k;

int gcd (int a, int b) { return b?gcd(b,a%b):a; }

int read_case()
{
  scanf("%ld %ld",&n,&k);
  if (n==0 && k==0) return 0;
  return 1;
}

void solve_case()
{
  int a[20];
  long i,j,d,g,res,f;
  f=k;
  if (k>n/2) k=n-k;
  for (i=0; i<k; i++)
    a[i] = n-i;
  for (j=2; j<=k; j++)
    for (i=0, d=j; d>1; i++)
      {
	g = gcd(a[i],d);
	a[i] /= g;
	d /= g;
      }
  for (i=0, res=1; i<k; res*=a[i++]);
  printf("%ld things taken %ld at a time is %ld exactly.\n",n,f,res);
}

int main()
{

  while (read_case()) solve_case();
  return 0;
}
