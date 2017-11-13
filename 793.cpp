#include<stdio.h>
#include<string.h>

#define MAXN 100000

int P[MAXN], rank[MAXN];
int C;

void Ini() {
	int i;
	for(i = 1; i<=C; i++){
		P[i] = i;
		rank[i] = 0;
	}
}

int Find(int x) {
	if(P[x] != x)
		P[x] = Find(P[x]);
	return P[x];
}

void Link(int x, int y) {
	if(rank[x]>rank[y])
		P[y] = x;
	else {
		P[x] = y;
		if(rank[x] == rank[y])
			rank[y]++;
	}
}


void Cal() {
	char input[100], tt[10];
	int i, a, b, x, y, n1 = 0, n2 = 0;
	while(gets(input)) {
		for(i = 0; input[i]; i++) 
			if(input[i] == '\n') 
				input[i] = NULL;
		if(strlen(input) == 0) break;
		sscanf(input,"%s%d%d",tt,&a,&b);
		x = Find(a); y = Find(b);
		if(!strcmp(tt,"q")) {
			if(x != y) n2++;
			else n1++;
		}
		else {
			if(x != y) Link(x,y);
		}
	}
	printf("%d,%d\n",n1,n2);
}


int main() {
	int kase;
	char input[100];
	gets(input);
	sscanf(input,"%d",&kase);
	gets(input);
	while(kase--) {
		gets(input);
		sscanf(input,"%d",&C);
		Ini();
		Cal();
		if(kase) putchar('\n');		
	}
	return 0;

}
