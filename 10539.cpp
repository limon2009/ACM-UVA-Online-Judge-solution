#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

#define MAXN 1000000

char P[MAXN+2];
long long  ALM[80071];
int In;
long long  LB, UB;

int com(const void *a, const void *b) {
   long long  *x = (long long  *) a;
   long long  *y = (long long  *)b;
   if(*x > *y) return 1;
   else if( *x < *y) return -1;
   return 0;
}
void Prime_table() {
      int i, j;
	  for(i = 2; i*i<=MAXN; ) {
		  for(j = i+i; j<= MAXN; j += i)
			  P[j] = 1;
		  for(i++; P[i]; i++);
	  }
}

void Gen() {
      int i;
	  double x, y;
	  In = 0;
	  for(i = 2; i<= MAXN; i++) {
	      if(P[i]) continue;
		  y = (double)i;
		  ALM[In++] = y*y;
		  x = y * y;
		  while(1) {
		     x *= i;
			 if(x >1000000000000) break;
			 ALM[In++] = x;
		  }
	  }
}

int LOWER() {
	int LO = 0;
	int UP = In-1;
	int MID= (LO + UP ) / 2;
	while(LO != UP && ALM[MID] != LB) {
		if(ALM[MID] > LB){
			if(ALM[MID-1] < LB)
				return MID;
			UP = MID - 1;
		}
		else
			LO  = MID + 1;
		MID = ( LO + UP ) / 2;
	}
	return MID;
}


int UPPER() {
	int LO = 0;
	int UP = In-1;
	int MID= (LO + UP ) / 2;
	if(UB <=3) return -1;
	while(LO != UP && ALM[MID] != UB) {
		if(ALM[MID] < UB){
			if(ALM[MID+1] > UB)
				return MID;
			LO = MID + 1;
		}
		else
			UP  = MID - 1;
	   MID = (LO + UP ) / 2;
	}
	return MID;
}
int main() {
   int n, l, u;
   Prime_table();
   Gen();
   qsort(ALM,In,sizeof(long long ),com);
   scanf("%d",&n);
   while(n -- ) {
      scanf("%lld%lld",&LB,&UB);
      l = LOWER();
	  u = UPPER();
	  printf("%d\n",u-l+1);
   }
	return 0;

}
