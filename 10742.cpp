#include<stdio.h>
#define maxn 1000000
#define mx 80000

typedef long long INT;

char ss[maxn+3];
int p[mx], tp, k;

void table() {
	int i, j;
	ss[0] = 1;
	for(i = 2; i*i<maxn; ) {
		for(j = i+i; j<maxn; j+=i)
			ss[j] = 1;
		for(++i; ss[i]; i++);
	}
	k = 2;
	p[1] = 2;
	for(i = 3; i<maxn; i+=2) if( !ss[i]) p[k++] = i;
}



void Cal(int key) {
	INT f = 1, r = k-1, c = 0;
	if(key<=4) {
		printf("0\n");
		return;
	}
	while(f<r) {
		if(p[f] + p[r] >key) {
			r--;
		}
		else {
			c += r - f;
			f ++;
		}
	}
	printf("%lld\n",c);
}

int main() {
	int n, cs = 1;
	table();
	while(scanf("%d",&n) && n) {
		printf("Case %d: ",cs++);
		Cal(n);
	}
	return 0;

}
