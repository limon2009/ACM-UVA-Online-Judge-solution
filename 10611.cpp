#include<stdio.h>
#include<math.h>


#define MAXN 50002

int P[MAXN+2];
int  LB, UB, N;


int uPer(int key) {
	int LO = 0;
	int UP = N-1;
	int MID= (LO + UP ) / 2;
	while(LO != UP ) {
		if(P[MID] > key){
			if(P[MID-1] <= key)
				return MID;
			UP = MID - 1;
		}
		else
			LO  = MID + 1;
		MID = ( LO + UP ) / 2;
	}
	//if(P[MID] == key)
	//	return MID+1;
	return MID;
}


int loWer(int key) {
	int LO = 0;
	int UP = N-1;
	int MID= (LO + UP ) / 2;
	while(LO != UP) {
		if(P[MID] < key){
			if(P[MID+1] >= key)
				return MID;
			LO = MID + 1;
		}
		else
			UP  = MID - 1;
	   MID = (LO + UP ) / 2;
	}
	return MID;
}

void Cal() {
	int hi, lo, H , L;
	int query, n;
	H = P[N-1];
	L = P[0];
	scanf("%d",&query);
	while(query--) {
		scanf("%d",&n);
		if(n<=L) printf("X");
		else{
			if(n>H)
				lo = N-1;
			else
				lo = loWer(n);
			printf("%d",P[lo]);
		}
		if(n>=H) printf(" X\n");
		else {
			if(n<L)
				hi = 0;
			else
				hi = uPer(n);
			printf(" %d\n",P[hi]);
		}
	}

}

int main() {
   int l;
  // freopen("c:\\in.txt","r",stdin);
   scanf("%d",&N);
   for(l = 0; l<N; l++)
	   scanf("%d",&P[l]);
   Cal();
	return 0;

}
