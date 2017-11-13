#include<stdio.h>
#include<math.h>

int k;


int  COM(double a,double n)  {
  double x, y, p, q, r1, r2;
  double ang_1,ang_2,th,AR_1,AR_2;
  ang_1 = sin((360 * 2 * acos(0) ) / ( n * 180));
  x = 2 * a;
  y = n * ang_1;
  r1 = x/y;
  th = (2 * acos(0))/n;
  ang_2 =  tan(th);
  y = n * ang_2;
  r2 = a/y;
  AR_1 = 2 *  acos(0) * r1;
  AR_2 = 2 * acos(0) * r2;
  printf("Case %d: %.5lf %.5lf\n",k++,AR_1-a,a-AR_2);
  return 0;
}

int  main()
{
  int n;
  k=1;
  double a;
  while(1)
 {
     scanf("%d",&n);
     if(n<3)break;
     scanf("%lf",&a);
     COM(a,n);

 }
	return 0;

}
