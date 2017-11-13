#include<stdio.h>

#define MAXN 500

int N, K;
char Temp[MAXN];
struct SS {
    int Len;
    char Digit[MAXN];
}V[1002];

void MUL(int n)  {
    int i, j,  carry = 0;
    K = 0;
    for(i = V[n].Len-1; i>=0; i--) {
	j = V[n].Digit[i] * 2 + carry;
	Temp[K++] = j % 10;
	carry = j / 10;
    }
    if( carry) Temp[K++] = carry;

}

void ADD(int n) {
   int i, j, carry = 0, p = K;
   int k = V[n].Len - 1;
   K = 0;
   for(i = 0; i<p; i++) {
	j = V[n].Digit[k--] + Temp[i] + carry;
	Temp[K++] = j % 10;
	carry = j / 10;
	if(k < 0) break;
   }
   for(int q = i+1; q<p; q++) {
	j = Temp[q] + carry;
	Temp[K++] = j % 10;
	carry = j / 10;
   }
   if(carry) Temp[K++] = carry;

}


void Cal()  {
    int i, j, n = 0;
    for(i = 4; i<=1000; i++) {
	n = 0;
	MUL(i-1);
	ADD(i-2);
	ADD(i-3);
	for(j = K-1; j>=0; j--)
	  V[i].Digit[n++] = Temp[j];
	V[i].Len = K;
    }
}

void Print() {
   int i;
   for(i = 0; i<V[N].Len; i++) printf("%d",V[N].Digit[i]);
   putchar('\n');

}

int main() {
    V[1].Len = V[2].Len = 1;
    V[3].Len = 2;
    V[1].Digit[0] = 2;  V[2].Digit[0] = 5;
     V[3].Digit[0] = 1; V[3].Digit[1] = 3;

    Cal();
    while(scanf("%d",&N) == 1) {
	if(N == 1) { printf("2\n");  continue; }
	if(N == 2) { printf("5\n");  continue; }
	if(N == 3) { printf("13\n"); continue; }
	else Print();
    }

	return 0;

}
