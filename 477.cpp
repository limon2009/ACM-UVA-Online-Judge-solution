#include<stdio.h>
#include<string.h>
#include<math.h>

char Fig[11][5];
double  Ed[11][5];
double  P,Q;
int I,Kase;

void Read_Rec() {
   char input[100];
   I = 0;
   while(1) {
     gets(input);
     sscanf(input,"%s%lf%lf%lf%lf",Fig[I],&Ed[I][0],&Ed[I][1],&Ed[I][2],&Ed[I][3]);
     if(!strcmp(Fig[I],"*")) break;
     I++;
   }
}

double  Ar_T(double  a, double  b, double  c, double  d,double  e,double  f) {
       double  m , n, ar;
       m = a*d + c*f + e*b;
       n = b*c + d*e + f*a;
       ar = (m - n) / 2;
       if(ar<0) return -ar;
	   return  ar;
}

double  Ar_R(double  a, double  b, double  c, double  d) {
     double  m, n, ar;
     m = Ar_T(a,b,c,b,a,d);
     ar = 2 * m;
	 if(ar<0) return -ar;
     return ar;
}


int Cir(double a, double c, double radius) {
     double x,y,z;
     x = (a-P) * (a-P);
     y = (c-Q) * (c-Q);
     z = sqrt(x + y);
     if(z<radius) return 1;
     return 0;

}

void Solved() {
    int i, j = 0;
    double ArR,ArT1,ArT2,ArT3,ArT4,Tr;
    for(i = 0; i<I; i ++)  {
	   if(!strcmp(Fig[i],"c")) {
	     if(Cir(Ed[i][0],Ed[i][1],Ed[i][2])) {
	       printf("Point %d is contained in figure %d\n",Kase,i+1);
	       j = 1;
	     }
	       continue;
	   }
	   ArR = Ar_R(Ed[i][0],Ed[i][1],Ed[i][2],Ed[i][3]);
	   ArT1 = Ar_T(Ed[i][0],Ed[i][1],P,Q,Ed[i][2],Ed[i][1]);
	   ArT2 = Ar_T(Ed[i][2],Ed[i][1],P,Q,Ed[i][2],Ed[i][3]);
	   ArT3 = Ar_T(Ed[i][2],Ed[i][3],P,Q,Ed[i][0],Ed[i][3]);
	   ArT4 = Ar_T(Ed[i][0],Ed[i][1],P,Q,Ed[i][0],Ed[i][3]);
	   Tr = ArT1+ArT2+ArT3+ArT4;
	   if(fabs(ArR- Tr)<1E-7) {
	      printf("Point %d is contained in figure %d\n",Kase,i+1);
	      j = 1;
	   }
    }
    if(j == 0) printf("Point %d is not contained in any figure\n",Kase);

}


int main() {
      char input[50];
      Kase = 1;
      Read_Rec();
      while(1) {
		gets(input);
		sscanf(input,"%lf%lf",&P,&Q);
		if(P == 9999.9 && Q == 9999.9) break;
		Solved();
		Kase++;
      }

	return 0;

}
