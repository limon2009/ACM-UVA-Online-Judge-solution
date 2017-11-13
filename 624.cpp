#include<stdio.h>

#define MAXT 21
int TRACK[MAXT];
int STORE[MAXT],B[MAXT];
int N,Q,L,MAXIMUM;
int TOTAL;


void CALCULATE(int index,int level) {

	 if(TOTAL > N)  return;
	 if(level == Q) return;
	 for(int i = index; i<=Q; i ++) {

	     TOTAL += TRACK[i-1];
	     B[level] = i;
	     if(MAXIMUM < TOTAL  && TOTAL <= N) {
		for(int j = 0 ; j<= level; j ++){
		  int k = B[j];
		  STORE[j] = TRACK[k - 1];
		}
		MAXIMUM = TOTAL;
		L = level;
	     }
	     CALCULATE(i+1,level+1);
	     TOTAL -= TRACK[i-1];

	 }

}

void PRINT() {
 int i;
 for(i = 0; i<=L; i ++)
   printf("%d ",STORE[i]);
 printf("sum:%d\n",MAXIMUM);
}


int main()   {

       int i;
	while(scanf("%d",&N) == 1) {
	   scanf("%d",&Q);
	   for(i = 0; i<Q; i ++)
	     scanf("%d",&TRACK[i]);
	   TOTAL = 0;
	   MAXIMUM = 0;
	   CALCULATE(1,0);
	   PRINT();
       }
	return 0;

}
