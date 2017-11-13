#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 1009
typedef  long long  Big;

char Num[MAXN];
char D[15];
int R, Base;
int A[25];

int DEC(char s[]) {
    int i, j = 0, p = 1, m;
	int l = strlen(D);
	if(Base == 10)
	   return atoi(D);
	for(i = l-1; i>=0; i--) {
		m = D[i] - 48;
	    j += m * p;
		p *= Base;
	}
	return j;
}

void Cal() {
    int i, l, m;
	Big con = Base % R;
	Big rem, pre = 1, total;
	l = strlen(Num);
	rem = (Num[l-1] -48) % R;
	for(i= l -2; i >= 0; i --) {
	   m = Num[i] - 48;
	   pre =( con * pre ) % R;
	   total = (pre * m) % R;
	   rem = (total + rem) % R;
	}
	m = 0;
	if(rem == 0) {
		printf("0\n");
		return;
	}
	 
	while(rem) {
		A[m++] = rem % Base;
		rem /= Base;
	}
	for(i = m-1; i>=0; i--) printf("%d",A[i]);
	printf("\n");
}
int main() {
    while(scanf("%d",&Base) == 1) {
		if(Base == 0) break;
		scanf("%s%s",Num,D);
		R = DEC(D);
		Cal();
	}

	return 0;

}
