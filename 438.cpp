#include<stdio.h>
#include<math.h>

#define PI 3.141592653589793

double g,f,A,B,C,R,E,F,G;
double x1,Y1,x2,y2,x3,y3;

void CENTER()  {
   A = 2*(x1-x2);
   B = 2*(Y1-y2);
   C = (x2*x2) + ( y2*y2) -  (x1 * x1)  - (Y1*Y1);
   E = 2*(x2-x3);
   F = 2*(y2-y3);
   G = (x3*x3) + ( y3*y3) -  (x2 * x2)  - (y2*y2);
   g = (C * F - G * B) / (A*F - E*B);
   f = (C * E - G * A) / ( B * E -  F * A);

}

void RADIUS()  {

     R = sqrt(((x1 - (-g)) * (x1 - (-g))) +  ((Y1 - (-f)) * (Y1 - (-f))));
}

void CIRCUMFERENCE()  {
       printf("%.2lf\n",2 * PI *  R);

}

int main()  {

	 while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&Y1,&x2,&y2,&x3,&y3) == 6) {

	    CENTER();
	    RADIUS();
	    CIRCUMFERENCE();
	}
	return 0;

}
