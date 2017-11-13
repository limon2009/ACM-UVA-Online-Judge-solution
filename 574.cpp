#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int SUM, TOTAL, K;
int N, NUM[14], B[15], C;
int  F[100][15];


int com(const void *a, const void *s) {
     return ( strcmp( (char *)a, (char *)s));

}
int sf(const void *a, const void *s) {
     return   *(int  *)s -  *(int *)a;

}

void prt(int k) {
   int i,j;
   for(i = 0; i<k; i ++) {
     j = B[i];
     printf("%d",NUM[j-1]);
     if(i<k-1) printf("+");
   }
   printf("\n");
   C = 1;
}


void ADD(int k) {
  int i;
  for(i = 0; i<k; i++) {
    int j = B[i];
    F[K][i]  = NUM[j-1];
 }
}


int  SAME(int a[],int k)  {
   int i;
   for(i = 0;i<k; i ++)  {
     int j = B[i];
     if(a[i] !=  NUM[j-1]) return 0;
  }
  return 1;
}



void PRINT(int k)  {
     int i;
     for(i = 0; i<K; i ++) {
       if(SAME(F[i],k))
	return;
    }
    prt(k);
    ADD(k);
    K ++;
}


void Recur(int index,int level)  {

   if(level) {
     int m = B[level - 1];
     TOTAL += NUM[m-1];
   }
   if(TOTAL == SUM)  {
     PRINT(level);
     return;
   }
   if(TOTAL>SUM) return;
   if(level == N) return;
   for(int i = index; i<= N; i ++) {
      B[level] = i;
      Recur(i+1,level+1);
      int j = B[level];
      TOTAL -= NUM[j-1];
   }
}


int main()  {
     int i, j;
      while(scanf("%d%d",&SUM,&N) && SUM && N) {
       TOTAL = 0;
       K = 0;
       C = 0;
       for(i = 0; i<N; i ++)
	 scanf("%d",&NUM[i]);
       qsort(NUM,N,sizeof(int),sf);
	 for(j = 0; j<100; j ++) {
	    B[j] = 0;
	    for(i = 0; i<14; i ++)
	     F[j][i] = 0;
	 }
	printf("Sums of %d:\n",SUM);
	Recur(1,0);
	if(C == 0) printf("NONE\n");
     }
	return 0;

}
