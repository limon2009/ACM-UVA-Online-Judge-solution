#include<stdio.h>
#include<map>

using namespace std;

typedef long long ss;

map<ss, int>A;

ss recur(ss n) {
	ss x, p;
	if(n == 1) return 1;
	x = A[n];
	if(x) return x;
	if(n%2)
		p = recur(3*n+1);
	else p = recur(n/2);
	A[n] = p+1;
	return A[n];
}

void Cal(int n, int m) {
	int sm = n, bg = m, temp, max = 0;
	if(sm>bg) {
		temp = bg;
		bg = sm;
		sm = temp;
	}
	for(int i = sm; i<= bg; i++) {
		n = recur(i);
		if(n>max)
			max = n;
	}
	printf("%d\n",max);
}

void main() {
	int n, m;
	while(scanf("%d%d",&n,&m) == 2) {
		printf("%d %d ",n,m);
		Cal(n,m);
	}
}
