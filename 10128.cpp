#include<iostream>
#include<stdio.h>

using namespace std;

#define maxn 15

typedef long long ss;

ss F[maxn][maxn];
ss B[maxn][maxn];
ss Com[maxn][maxn][maxn];

void First(ss n) {
	ss i, j, lim;
	lim = n;
	for(i = 1; i<n; i++) {
		for(j = 1; j<n; j++) {
			if(i + j > lim) break;
			Com[n][i+1][1] += Com[n-1][i][j];
			Com[n][1][i+1] += Com[n-1][i][j];
		}
	}
}

ss Combination(ss n, ss r) {
	ss temp = 1, dump, i;
	dump = 1;
	for(i = r+1; i<= n; i++)
		temp *= i;
	for(i = 2; i<= n-r; i++)
		dump *= i;
	return temp/dump;
}

void Gen(ss n, ss m, ss key) {
	ss i, j, k, l, b, c, x;
	b = n+2;
	c = m+2;
	x = Combination(key-1,n);
	for(i = 1; i<=n+1; i++) {
		if(i + 1 > b) break;
		k = Com[n+1][i][1];
		if(k == 0) continue;
		for(j = 1; j <= m+1; j++) {
			if(j + 1 > c) break;
			l = Com[m+1][1][j];
			Com[key][i][j] += k * l * x;
		//	Com[key][j][i] += k * l * x;
		}
	}
}

void Cal() {
	ss i, j, k;
	Com[1][1][1] = 1;
	Com[2][1][2] = Com[2][2][1] = 1;
	for(i = 3; i<14; i++) {
		First(i);
		k = i - 1;
		for(j = 1; j<k; j++)
			Gen(j, k-j, i);
	}
}

int main() {
	ss n, f, b, c;
	Cal();
	scanf("%lld",&n);
	while(n--) {
		scanf("%lld%lld%lld",&f,&b,&c);
		printf("%lld\n",Com[f][b][c]);
	}
	return 0;

}
