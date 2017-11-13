#include<stdio.h>
#include<string.h>
#include<math.h>

char Fig[11];
double  Ed[11][5];
double  P,Q;
int I,Kase;

struct point {
   double x1;
   double y1;
   double x2;
   double y2;
}V[15];

void Read_Rec() {
   char input[100];
   I = 0;
   while(1) {
     gets(input);
     sscanf(input,"%s%lf%lf%lf%lf",Fig,&V[I].x1,&V[I].y1,&V[I].x2,&V[I].y2);
     if(!strcmp(Fig,"*")) break;
     I++;
   }
}



int IsIn(int n) {
   if(P<V[n].x2 && P>V[n].x1)
     if(Q<V[n].y1 && Q>V[n].y2)
       return 1;
   return 0;
}
void Solved() {
    int i, j = 0;
    double ArR,ArT1,ArT2,ArT3,ArT4,Tr;
    for(i = 0; i<I; i ++)  {
	   if(IsIn(i)) {
	      printf("Point %d is contained in figure %d\n",Kase,i+1);
	      j = 1;
	   }
    }
    if(j == 0) printf("Point %d is not contained in any figure\n",Kase);

}


int main() {
      char input[100];
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
