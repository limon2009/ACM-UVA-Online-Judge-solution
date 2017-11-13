#include<iostream>

using namespace std;

#define maxn 1000000


char sv[maxn+2];
int P[78500], tp;

void Table() {
	int i, j;
	for(i = 2; i*i<=maxn; ) {
		for(j = i+i; j<maxn; j+=i)
			sv[j] = 1;
		for(++i; sv[i]; i++);
	}
	P[0] = 2;
	tp = 1;
	for(i = 3; i<maxn; i+=2)
		if(!sv[i]) P[tp++] = i;
}


void Cal(int n) {
	int i = 0, j = tp - 1;
	while(i <= j) {
		if(P[i] + P[j] > n)
			j--;
		else if(P[i] + P[j] < n)
			i++;
		else {
			cout<<P[i]<<"+"<<P[j]<<endl;
			return;
		}
	}
	cout<<"NO WAY!\n";
}

int main() {
	int n;
	Table();
	while(cin>>n && n) {
		cout<<n<<":\n";
		Cal(n);
	}
	return 0;

}
