#include<iostream>
#define maxn 100

using namespace std;

typedef long ss;
ss T[maxn+2][maxn+2];

void Gen() {
	ss i, j;
	for(i = 0; i<= maxn; i++)
		T[1][i] = 1;
	for(i = 2; i<= 100; i++) {
		T[i][0] = 1;
		for(j = 1; j <= 100; j++) 
			T[i][j] = (T[i][j-1] + T[i-1][j]) % 1000000;
	}
}

int main() {
	ss n, m;
	Gen();
	while(cin>>n>>m) {
		if(!n && !m) break;
		cout<<T[m][n]<<endl;
	}
	return 0;

}
