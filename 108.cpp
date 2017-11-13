#include<stdio.h>
#define Dif(i,j,k) (Table[i+k][j] - Table[i][j])
#define MAXN 110

int N, MAX;
int Table[MAXN][MAXN];


void ReadCase() {
   int i, j;
   for(i = 1; i<=N; i++)
	   for(j  = 0; j<N; j++)
		   scanf("%d",&Table[i][j]);
	   
}

void Cal() {
   int i, j, k, t;
   for(i = 1; i<=N; i++){
	   for(j = 0; j<N; j++)
		  Table[i][j] =  Table[i][j] + Table[i-1][j];
   }
   MAX = Table[1][0];
   for(k = 1; k<=N; k++) {
	   for(i = 0; i<=N-k; i++){
		   for(t = 0, j = 0; j<N; j++) {
		      if(t>=0) t+= Dif(i,j,k);
			  else t = Dif(i,j,k);
			  if(t>MAX) MAX = t;
		   }
	   }
   }
		 
   printf("%d\n",MAX);
   
}


void FREE() {
   int i, j;
   for(i = 0; i<=N; i++)
	   for(j = 0; j<=N; j++)
		   Table[i][j] = 0;
}

int main() {
    int f = 0;	

	while(scanf("%d",&N) == 1) {
	   if(f++) FREE();
	   ReadCase();
	   Cal();
	   
	}
	return 0;
}
