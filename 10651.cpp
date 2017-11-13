#include<stdio.h>
#include<string.h>

#define MAXN 1500


char ini[15];

struct ss {
	char str[15];
	int len;
}Q[MAXN];

int qh, qt, min;

void Push(char temp[], int len) {
	strcpy(Q[qh].str,temp);
	Q[qh++].len = len;
	qh %= MAXN;
}

void BFS(int t) {
	int i, j, pre;
	char xx[15], yy[15];
	qh = qt = 0;
	min = t;
	Push(ini,t);
	while(qh != qt) {
		strcpy(xx,Q[qt].str);
		pre = Q[qt++].len;
		if(pre < min) min = pre;
		for(i = 0; i<12; i++) {
			if(xx[i] == 'o') continue;
			if(i<=9 && xx[i+1] == 'o' && xx[i+2] == 'o') {
				for(j = 0; j<i; j++)
					yy[j] = xx[j];
				yy[j] = 'o';
				yy[i+1] = yy[i+2] = '-';
				for(j = i+3; j<12; j++)
					yy[j] = xx[j];
				yy[12] = NULL;
				Push(yy,pre-1);
			}
			if(i>=2 && xx[i-1] == 'o' && xx[i-2] == 'o') {
				for(j = 11; j>i; j--) 
					yy[j] = xx[j];
				yy[j] = 'o';
				yy[i-1] = yy[i-2] = '-';
				for(j = 0; j<i-2; j++)
					yy[j] = xx[j];
				yy[12] = NULL;
				Push(yy,pre-1);
			}
		}
	}
}

void Cal() {
	int i, t = 0;
	for(i = 0; ini[i]; i++) {
		if(ini[i] == 'o')
			t++;
	}
	if(t == 12 || t == 0 || t == 1 ) {
		printf("%d\n",t);
		return;
	}
	BFS(t);
	printf("%d\n",min);
}

int main() {
	int kase;
	scanf("%d",&kase);
	while(kase--) {
		scanf("%s",ini);
		Cal();
	}
	return 0;

}

