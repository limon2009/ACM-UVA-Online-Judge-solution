#include<stdio.h>



int T,N,B,K,R;

int main()  {

     int i,SUM,a,r;
     scanf("%d",&T);
     while(T --)  {
	scanf("%d%d",&N,&B);
	SUM = 0;
	while(B --)  {
	   scanf("%d",&K);
	   R = 1;
	   for(i = 1; i<=K; i ++)  {
	      scanf("%d",&a);
	      r = a % N;
	      R *= r;
	      R = R % N;
	  }

	  SUM += R;
	  SUM = SUM % N;
	}
	printf("%d\n",SUM);
     }
	return 0;

}
