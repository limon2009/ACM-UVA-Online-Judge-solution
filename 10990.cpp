#include<stdio.h>
#define maxn 2000001

char sv[maxn];
int Fact[maxn];
char fgE[maxn], fgD[maxn];
int Eu[maxn], D[maxn];


void Table() {
	int i, j;
	for(i = 2; i*i<maxn; ) {
		for(j = i+i; j<maxn; j+= i){
			sv[j] = 1;
			Fact[j] = i;
		}
		for(++i; sv[i]; i++);
	}
}


int Euler(int n) {
	int k, f, m;
	if(!sv[n]) return n-1;
	if(fgE[n]) return Eu[n];
	fgE[n] = 1;
	f = Fact[n];
	m = n/f;
	if(m % f == 0)
		k = f * Euler(m);
	else
		k = (f - 1) * Euler(m);
	Eu[n] = k;
	return k;
}

int Depth(int n, int level) {
	if(n == 1) return level - 1;
	if(fgD[n]) return D[n] + level - 1;
	fgD[n] = 1;
	D[n] = Depth(Eu[n],level+1);
	return D[n];
}

void Cal() {
	int i;
	Eu[1] = 0;
	for( i = 2; i<maxn; i++)
		Eu[i] = Euler(i);
	for(i = 2; i<maxn; i++) {
		D[i] = Depth(i, 1);
	}
	for(i = 3; i<maxn; i++)
		D[i] += D[i-1];
}
int main() {
	int k, n, m;
	Table();
	Cal();
	scanf("%d",&k);
	while(k--) {
		scanf("%d%d",&n,&m);
		printf("%d\n",D[m] - D[n-1]);
	}
	return 0;

}
