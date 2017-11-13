#include<stdio.h>
#include<math.h>
#include<string.h>

#define MAXN 20

int N, Kase;
double P, Q;

struct SS {
   char T[10];
   double a, b;
   double c, d;
   double e, f;
}V[MAXN];



void ReadCase() {
   char C[100];
   N = 0;
   while(1) {
      gets(C);
      sscanf(C,"%s%lf%lf%lf%lf%lf%lf",V[N].T,&V[N].a,&V[N].b,
		  &V[N].c,&V[N].d,&V[N].e,&V[N].f);
      if(!strcmp(V[N].T,"*")) break;
      N++;
  }
}

int Rec(int i) {
    if(P>V[i].a && P<V[i].c)
      if(Q>V[i].d && Q<V[i].b)
	return 1;
    return 0;
}


int Cir(int n) {
   double dis;
   dis = sqrt( pow((V[n].a - P),2) + pow((V[n].b - Q),2));
   if(dis < V[n].c) return 1;
   return 0;
}


double  TT(double  a, double  b, double  c, double  d,double  e,double  f) {
       double  m , n, ar;
       m = a*d + c*f + e*b;
       n = b*c + d*e + f*a;
       ar = (m - n) / 2;
       if(ar<0) return -ar;
	   return  ar;
}

int Tri(int n)   {
   double T1, T2, T3, tt;
   T1 = TT(V[n].a, V[n].b, V[n].c, V[n].d, P, Q);
   T2 = TT(V[n].c, V[n].d, V[n].e, V[n].f, P, Q);
   T3 = TT(V[n].e, V[n].f, V[n].a, V[n].b, P, Q);
   tt = TT(V[n].a, V[n].b, V[n].c, V[n].d, V[n].e, V[n].f);
   if(fabs((T1+T2+T3) - tt)<=.000001) return 1;
  return 0;
}

void Cal() {
      int i, j = 0;
      for(i = 0; i<N; i++) {
	  if(!strcmp(V[i].T,"r") && Rec(i)) {
	     printf("Point %d is contained in figure %d\n",Kase,i+1);
	     j = 1;
	  }
	  else if(!strcmp(V[i].T,"c") && Cir(i)) {
	     printf("Point %d is contained in figure %d\n",Kase,i+1);
	     j = 1;
	  }
	  else if(!strcmp(V[i].T,"t") && Tri(i)) {
	     printf("Point %d is contained in figure %d\n",Kase,i+1);
	     j = 1;
	  }
      }
      if(!j) printf("Point %d is not contained in any figure\n",Kase);
}

int main() {
   char S[100];
   Kase = 1;
   ReadCase();
   while(1) {
      gets(S);
      sscanf(S,"%lf%lf",&P,&Q);
      if(P == 9999.9 && Q == 9999.9) break;
      Cal();
      Kase++;
   }
	return 0;

}
