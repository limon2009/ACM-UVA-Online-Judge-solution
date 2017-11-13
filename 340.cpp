#include<stdio.h>
#include<stdlib.h>

#define MAXN 1001

int Code[MAXN];
int Temp[MAXN];
int Temp1[MAXN];
int Guess[MAXN];

int N, ST, W;


int Cal() {
	int i, j;
	char *c = "(";
	ST = W = 0;
	for(i = 0; i<N; i++) {
	   Temp[i]  = Code[i];
	   if(Guess[i] == Temp[i]){
		   ST ++;
		   Guess[i] = -1;
		   Temp[i] = -2;
	   }
	}
    printf("%5s",c);        
    printf("%d,",ST);
    for(i = 0; i<N; i++) {
		if(Guess[i] == -1) continue;
		for(j = 0; j<N; j++) {
			if(Guess[i] == Temp[j]) {
				W++;
				Guess[i] = Temp[j] = -1;
				break;
			}
		}
	}

    printf("%d)\n",W);
	return 0;

}


int main() {
	int i, kase = 1;
    int f;
	
	while(1) {
		scanf("%d",&N);
		if( N == 0) break;
		printf("Game %d:\n",kase++);
		for(i = 0; i<N; i++) 
			scanf("%d",&Code[i]);
        
		while(1) {
			for(i = 0; i<N; i++) {
				scanf("%d",&Guess[i]);
				if(Guess[i] != 0)
					f = 0;
			}
			if(f) break;
			Cal();
			f = 1;
		
		}
	}
	return 0;

}
