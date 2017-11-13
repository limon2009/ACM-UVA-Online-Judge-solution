#include<iostream>

using namespace std;

#define MAXN(a, b) (a > b? a:b)

int T, N, MAXN;

void F() {
	int i, n, diff;
	while(T--) {
		cin>>N;
		diff = -160000;
		cin>>MAXN;
		for(i = 1; i<N; i++) {
			cin>>n;
			diff = MAXN(diff, MAXN - n);
			MAXN = MAXN(MAXN, n);
		}
		cout<<diff<<endl;
	}
}

int main() {
	cin>>T;
	F();
	return 0;

}
