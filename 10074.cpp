#include<stdio.h>
#define Dif(i,j,k) (Table[i+k][j] - Table[i][j])
#define MAXN 105

int N,M,MAX;
int Table[MAXN][MAXN];


void ReadCase() {
   int i, j;
   for(i = 1; i<=N; i++)
	   for(j  = 0; j<M; j++){
		   scanf("%d",&Table[i][j]);
	       if(Table[i][j] ==1)
			   Table[i][j] = -1001;
		   else Table[i][j] = 1;
	   }
	   
}

void Cal() {
   int i, j, k, t;
   for(i = 1; i<=N; i++){
	   for(j = 0; j<M; j++)
		  Table[i][j] =  Table[i][j] + Table[i-1][j];
   }
   MAX = Table[1][0];
   for(k = 1; k<=N; k++) {
	   for(i = 0; i<=N-k; i++){
		   for(t = 0, j = 0; j<M; j++) {
		      if(t>=0) t+= Dif(i,j,k);
			  else t = Dif(i,j,k);
			  if(t>MAX) MAX = t;
		   }
	   }
   }
		 
   MAX<0?printf("0\n"):printf("%d\n",MAX);
   
}


void FREE() {
   int i, j;
   for(i = 0; i<=N; i++)
	   for(j = 0; j<=M; j++)
		   Table[i][j] = 0;
}

int main() {
    int f = 0;	
  	while(scanf("%d%d",&N,&M) == 2) {
		if(!N && !M) break;
	   if(f++) FREE();
	   ReadCase();
	   Cal();
	   
	}
	return 0;

}
