#include<stdio.h>
#include<math.h>
#define MAXN 3000000
	     /* 5000000 */
double  V[MAXN];

double  recur(double  n)  {

  double  t;
  if(n ==1) return 0;
  if(n<MAXN && V[(int)n]) return  V[(int)n];
  if(fmod(n , 2))
    t = recur(3*n+1) + 1;
  else
    t = recur(n / 2) +1;
  if(n<MAXN)
    V[(int)n] =  t;
  return t;
}

void AK(double  n,double  m)  {
  double  i,temp, MAX = 0;
  double  d, p = 1.;
  if(n>m) {
     temp = n;
     n = m;
     m = temp;
  }
  for(i = n; i<=m; i ++)  {
      if(i == 0 || i == 1) d = V[(int)i];
	  else d = recur(i);
       if(MAX<d)  {
	   MAX = d;
	   p = i;
      }
  }
  printf("Between %.0lf and %.0lf, %.0lf generates the longest sequence of %.0lf values.\n",n,m,p,MAX);
}



int main() {
    double  m,n;
    V[0] = 0.0;
	V[1] = 3.0;
	while(1)  {
       scanf("%lf%lf",&m,&n);
       if(!n && !m) break;
       AK(n,m);
    }
	return 0;

}
