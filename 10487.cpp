#include<stdio.h>
#include<stdlib.h>
#define MAXN 1005
#define MAX 499509
  /* 499500 */
int DATA[MAXN];
int STORE[MAX];
int N,Q,SUM,ST;
int DIFF,M;

int sort_function(const void *a, const  void *b) {

  return *(int *)a - *(int *)b;

}



void  COM() {

     int i,j;
     M = 0;

     for(i = 0; i<N-1; i ++)
	  for(j = i+1; j<N; j ++) {
	       if(DATA[i] == DATA[j] ) continue;
	       STORE[M++] = DATA[i] + DATA[j];
	  }
     qsort((void *)STORE,M,sizeof(int),sort_function);
}
void CAL() {

     int i,diff1,diff2;
     for(i = 0; SUM>STORE[i] && i<M; i++);
     if(i == 0)
       ST = STORE[i];
     else if(i == M)  ST = STORE[i-1];
     else {
	diff1  = abs(SUM - STORE[i]);
	diff2  = abs(SUM - STORE[i-1]);
	if(diff1>diff2)
	  ST = STORE[i-1];
	else
	  ST = STORE[i];
     }
}

int main()  {

      int i,kase = 1;
      while(scanf("%d",&N) && N)  {

	     for(i = 0;i <N; i ++)
		scanf("%d",&DATA[i]);
	     COM();
	     scanf("%d",&Q);
	     printf("Case %d:\n",kase++);
	     while(Q --)  {
		scanf("%d", & SUM);
		CAL();
		printf("Closest sum to %d is %d.\n",SUM,ST);

	     }
      }
	return 0;

}
