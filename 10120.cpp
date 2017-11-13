#include<stdio.h>
#include<math.h>

#define MAXN 1000002

int Jump[2][MAXN];
int N, T;

int Dynamic() {
	int i,  nth = 2, a1 = 1, a2 = 0, j;
	int inda =1, indb, forword, backword;
	Jump[a1][0] = 1;
	j = nth*2-1;
	while(inda) {
		indb = 0;
		for(i = 0; i<inda; i++) {
			forword = Jump[a1][i] + j;
			if(forword <= N ){
				Jump[a2][indb++] = forword;
			}
			backword = Jump[a1][i] - j;
			if(backword>0 ){
				Jump[a2][indb++] = backword;
			
			}
			if(forword == T || backword == T) return 1;
		}
		inda = indb;
		a1++; 
		a2++; 
		nth ++;
		a1%= 2; 
		a2%= 2;
		j = nth*2-1;
	}
	return 0;
}
int main() {
	int g;
	while(scanf("%d%d",&N,&T) && N && T) {
		if(N>48) {
			printf("Let me try!\n");
			continue;
		}
		g = int(sqrt(T));
		if(g*g == T) {
			printf("Let me try!\n");
			continue;
		}
		if(Dynamic())
			printf("Let me try!\n");
		else
			printf("Don't make fun of me!\n");
	}
	return 0;

}
