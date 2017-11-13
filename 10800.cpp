#include<stdio.h>
#include<string.h>

#define maxn 110

int len[maxn], Up, Lo, X, Y, maxi;
char G[maxn][55];
char Ins[55];

void Right(int pre) {
	if(Ins[pre] =='R') {
		G[X-1][Y+1] = '/';
		if((X-1)< Lo) Lo = X-1;
		if(len[X-1]<(Y+1)) len[X-1] = Y+1;
		X = X-1;
		Y += 1;
	}
	else {
		G[X][Y+1] = '/';
		if(len[X]<(Y+1)) len[X] = Y+1;
		Y += 1;
	}
}
	
void F(int pre) {
	if(Ins[pre] =='R')  {
		G[X][Y+1] = 92;
		if(len[X]<(Y+1)) len[X] = Y+1;
		Y += 1;
	}
	else {
		G[X+1][Y+1] = 92;
		if(len[X+1]<(Y+1)) len[X+1] = Y+1;
		if(Up < (X+1)) Up = X+1;
		Y += 1;
		X += 1;
	}
}
void U(int pre) {
	if(Ins[pre] =='C' || Ins[pre] == 'F') {
		G[X][Y+1] = '_';
		if(len[X]<(Y+1)) len[X] = Y+1;
		Y += 1;
	}
	else {
		G[X-1][Y+1] = '_';
		if(len[X-1]<(Y+1)) len[X-1] = Y+1;
		if(X-1<Lo) Lo = X-1;
		Y += 1;
		X -= 1;
	}

}

void Cal() {
	X = 55;
	Y = 2;
	maxi = strlen(Ins) + 2;
	int i;
	for(i = 1; Ins[i]; i++) {
		switch(Ins[i]) {
		case 'R':Right(i-1);	break;
		case 'F':F(i-1);		break;
		case 'C':U(i-1);		break;
		}
	}
	for(i = Lo; i<= Up; i++) {
		printf("| ");
		for(int j = 2; j<=len[i]; j++)
			printf("%c",G[i][j]);
		printf("\n");
	}
	printf("+");
	for(i = 1; i<= maxi; i++)
		printf("-");
	printf("\n");


}

int main() {
	int ks, k = 1;
	scanf("%d",&ks);
	while(ks--) {
		scanf("%s",Ins);
		Up = Lo = 55;
		memset(len,0,sizeof(int)*maxn);
		len[55] = 2;
		memset(G,32,maxn*55);
		if(Ins[0] == 'R') G[55][2] = '/';
		else if(Ins[0] == 'F') G[55][2] = 92;
		else G[55][2] = '_';
		printf("Case #%d:\n",k++);
		Cal();
		printf("\n");
	}
	return 0;

}

