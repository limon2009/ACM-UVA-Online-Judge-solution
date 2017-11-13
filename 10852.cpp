#include<iostream>
#define maxn 10000

using namespace std;

int P[maxn], tp;
char sv[maxn+2];

void PrimeTable() {
	int i, j;
	for(i = 2; i*i<maxn; ) {
		for(j = i+i; j<maxn; j+=i) 
			sv[j] = 1;
		for(++i; sv[i]; i++);
	}
	tp = 1;
	P[0] = 2;
	for(i = 3; i<maxn; i+=2) 
		if(sv[i] == 0)
			P[tp++] = i;
}

void Cal(int n) {
	int i, res, d, min = -1, x;
	for(i = 0; P[i]<= n && i<tp; i++) {
		x = n/P[i];
		d = n - x*P[i];
		if(d>min) {
			res = P[i];
			min = d;
		}
	}
	cout<<res<<endl;
}

int main() {
	PrimeTable();
	int n, k;
	cin>>k;
	while(k--) {
		cin>>n;
		Cal(n);
	}
	return 0;

}
