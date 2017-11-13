#include<stdio.h>
#include<stdlib.h>

#define MAXN  33

int B[MAXN][1][12];
int St[MAXN], V[MAXN];
int P[MAXN], N, D;

int com(const void *a, const  void *s) {
   return *(int *)a - *(int *)s;
}


int Biger(int n, int m){
       int i;
       for(i = 0; i<D; i++)
	 if(B[n][0][i] <= B[m][0][i])
	   return 0;
       return 1;
}

void Sort() {
  int i, j, Temp;
  for(i = 0; i<N-1; i++) {
    for(j = i+1; j<N; j++) {
       if(Biger(St[i], St[j])) {
	  Temp = St[i];
	  St[i] = St[j];
	  St[j] = Temp;
       }
    }
  }
}

void Print(int n){
   if(P[n] == -1) {
     printf("%d",St[n]+1);
     return;
   }
    Print(P[n]);
    printf(" %d",St[n]+1);
}

void SolvedCase() {
     int i, j, max, largest= 0, last;
     int par;
     Sort();
     for(i = 0; i<N; i++) {
       max = 0;  par = -1;
       for(j = i-1; j>=0 ; j--)   {
	     if(Biger(St[i], St[j])) {
	       if(V[j]>max){
		 max = V[j];
		 par = j;
	       }
	     }
       }
       P[i] = par;
       V[i] = max+1;
       if(V[i] >largest ){
	 largest = V[i];
	 last = i;
       }
     }
     printf("%d\n",largest);
     Print(last);
     putchar('\n');
}


void ReadCase(){
    int i, j;
    for(i = 0; i<N; i++) {
      St[i] = i;
      for(j = 0; j<D; j++)
	scanf("%d",&B[i][0][j]);
      qsort(B[i][0],D,sizeof(int),com);
   }
}


void main() {
      while(scanf("%d%d",&N,&D) == 2) {
	ReadCase();
	SolvedCase();
      }
}
