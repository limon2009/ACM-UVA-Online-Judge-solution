#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979

int main()  {

     double ang,AB,BC,aria,ANG;
     double RADIUS,SIDE;
     while(scanf("%lf%lf",&RADIUS,&SIDE) == 2)   {

	   ANG = 360.0 / SIDE;
	   ang = ( 180.0 - ANG ) / 2.0;
	   BC = sin((ang * PI) / 180) * RADIUS;
	   AB = cos((ang * PI) / 180) *  RADIUS;
	   aria = .5 * BC * AB * 2;
	   printf("%.3lf\n",aria * SIDE);
     }
	return 0;

}
