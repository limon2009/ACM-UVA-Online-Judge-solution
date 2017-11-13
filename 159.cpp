#include<string.h>
#include<stdio.h>
#define MAX(a, b) (a>b?a:b)

char W1[12], W2[12], W3[12], W4[12];
char L[15], R[15];
int h1, v1, h2, v2;

int Set(char ss[], char xx[], int &x, int &y) {
	int i, j;
	for(i = 0; ss[i]; i++) {
		for(j = 0; xx[j]; j++) {
			if(ss[i] == xx[j]) {
				x = i;
				y = j;
				return 1;
			}
		}
	}
	return 0;
}

void Get(int mx, int d1, int d2) {
	int i, p = 0, q = 0, r = 0, s = 0;
	for(i = 1; i<= mx; i++) {
		if(i > d1)
			L[r++] = W2[p++];
		else 
			L[r++] = 0;
		if(i > d2)
			R[s++] = W4[q++];
		else
			R[s++] = 0;
	}
}

void PrintUp(int mx) {
	int i, j, l, d;
	l = strlen(W1);
	d = l - h1 - 1 + 3 + h2;
	for(i = 0; i<mx; i++) {
		for(j = 0; j<h1; j++) printf(" ");
		if(L[i] && !R[i])
			printf("%c\n",L[i]);
		else if(!L[i] && R[i]) {
			for(j = 0; j<d+1; j++) printf(" ");
			printf("%c\n",R[i]);
		}
		else if(L[i] && R[i]) {
			printf("%c",L[i]);
			for(j = 0; j<d; j++) printf(" ");
			printf("%c\n",R[i]);
		}
	}
}

void GetDown(int mx, int x, int y) {
	int i, l1, l2, p = 0, q = 0;
	l1 = strlen(W2);
	l2 = strlen(W4);
	for(i = 1; i<= mx; i++) {
		if(x < l1) L[p++] = W2[x++];
		else L[p++] = 0;
		if(y < l2) R[q++] = W4[y++];
		else R[q++] = 0;
	}
}

void Print_down(int mx) {
	int i, j, l, d;
	l = strlen(W1);
	d = l - h1 - 1 + 3 + h2;
	for(i = 0; i<mx; i++) {
		for(j = 0; j<h1; j++) printf(" ");
		if(L[i] && !R[i])
			printf("%c\n",L[i]);
		else if(!L[i] && R[i]) {
			for(j = 0; j<d+1; j++) printf(" ");
			printf("%c\n",R[i]);
		}
		else if(L[i] && R[i]) {
			printf("%c",L[i]);
			for(j = 0; j<d; j++) printf(" ");
			printf("%c\n",R[i]);
		}
	}
}
void Cal() {
	int  j, mx, u1, u2;
	mx = MAX(v1,v2);
	Get(mx,mx-v1,mx-v2);
	PrintUp(mx);
	printf("%s",W1);
	for(j = 0; j<3; j++) printf(" ");
	printf("%s\n",W3);
	u1 = strlen(W2) - v1 - 1;
	u2 = strlen(W4) - v2 - 1;
	mx = MAX(u1, u2);
	GetDown(mx,v1+1,v2+1);
	Print_down(mx);
	memset(L,0,15);
	memset(R,0,15);
}

int main() {
	int f = 0;
	//freopen("c:\\h.txt","r",stdin);
	while(scanf("%s",W1) != EOF) {
		if(!strcmp(W1,"#")) break;
		scanf("%s%s%s",W2,W3,W4);
		if(f++) putchar('\n');
		if(!Set(W1,W2,h1,v1) || !Set(W3,W4,h2,v2)) {
			printf("Unable to make two crosses\n");
			continue;
		}
		Cal();
	}
	return 0;

}
