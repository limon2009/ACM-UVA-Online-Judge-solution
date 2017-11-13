#include<stdio.h>
#define maxn 2000000

int div[maxn];
int ind, N;

typedef long long Bg;

Bg gcd(Bg a, Bg b) {return b ? gcd(b,a%b):a; }

void GetDiv() {
	int i;
	ind = 0;
	for(i = 1; i*i<= N; i++) {
		if(N % i == 0) {
			div[ind++] = i;
			if(N/i != i)
				div[ind++] = N/i;
		}
	}
}

Bg Lcm(Bg a, Bg b) {
	Bg gc = gcd(a,b);
	Bg lc = (a*b)/gc;
	return lc;
}

void Cal() {
	int i, j, total = 0;
	Bg lcm;
	if(N == 1) {
		printf("1\n");
		return;
	}
	for(i = 0; i+1<ind; i++) {
		for(j = i+1; j<ind; j++) {
			lcm = Lcm(div[i],div[j]);
			if(lcm == N)
				total++;
		}
	}
	printf("%d\n",total+1);
}

int main() {
	//freopen("h.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d",&N) && N) {
		GetDiv();
		printf("%d ",N);
		Cal();
	}
	return 0;

}
