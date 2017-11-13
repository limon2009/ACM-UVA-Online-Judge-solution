#include<stdio.h>
#include<math.h>

double a, b, c;
void main() {
while(scanf("%lf%lf",&a,&b) == 2) {
   printf("%.0lf\n",pow(b,1/a));
}
}
