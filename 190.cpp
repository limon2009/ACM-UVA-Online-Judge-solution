#include<stdio.h>
#include<math.h>

double g,f,c,A,B,C,R,E,F,G,K,M;
double X1,Y1,X2,Y2,X3,Y3;

void CENTER()  {
   A = 2*(X1-X2);
   B = 2*(Y1-Y2);
   C = (X2*X2) + ( Y2*Y2) -  (X1 * X1)  - (Y1*Y1);
   E = 2*(X2-X3);
   F = 2*(Y2-Y3);
   G = (X3*X3) + ( Y3*Y3) -  (X2 * X2)  - (Y2*Y2);
   g = (C * F - G * B) / (A*F - E*B);
   f = (C * E - G * A) / ( B * E -  F * A);
   c = -(X2 * X2 + Y2 * Y2 + 2 * g * X2 + 2 * f * Y2);
   K = 2 * g;
   M = 2 * f;
}

void RADIUS()  {

     char p,q,r,s;
     R = sqrt(((X1 - (-g)) * (X1 - (-g))) +  ((Y1 - (-f)) * (Y1 - (-f))));
      if(g<0) p = '-';
      else p = '+';
      if(f<0) q = '-';
      else q = '+';
      g = fabs(g);
      f = fabs(f);
      printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",p,g,q,f,R);
      if(c<0) p ='-';
      else  p = '+';
      c = fabs(c);
      if(K<0) r ='-';
      else r = '+';
      K = fabs(K);
      if(M<0) s ='-';
      else s = '+';
      M = fabs(M);
      printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n",r,K,s,M,p,c);
}

int main()  {


	 while(scanf("%lf%lf%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2,&X3,&Y3) == 6) {

	    CENTER();
	    RADIUS();
	    printf("\n");
	 }
	return 0;

}
