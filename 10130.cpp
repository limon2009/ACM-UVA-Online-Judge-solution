#include<stdio.h>
#include<stdlib.h>
#define MAXI(a,b) (a>b?a:b)

#define MAXN 1000
#define MAX 270

int Val[MAXN], P, N;
int W[MAXN],C[MAXN][MAX];

int  MCarry()  {
    int i, j;
    for(i = 1; i<=N; i++)
      for(j = 1; j<=P; j++) {
	if(W[i] > j)
	  C[i][j] = C[i-1][j];
	else C[i][j] = MAXI(C[i-1][j], C[i-1][j - W[i]] + Val[i]);
      }
    return C[N][P];
}


int main() {
     int Kase, i, tP;
     int Sum;
	 scanf("%d",&Kase);
     while(Kase --) {
	  Sum = 0;
	  scanf("%d",&N);
	  for(i = 1; i<= N; i++)
	       scanf("%d%d",&Val[i],&W[i]);
	  scanf("%d",&tP);
	  while(tP--) {
	     scanf("%d",&P);
	     Sum += MCarry();
	  }
	  printf("%d\n",Sum);
     }


	return 0;

}
