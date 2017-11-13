#include<iostream>

using namespace std;

int Cost[37];


int CCost(int n, int bs) {
	int cost = 0;
	if(n == 0) return Cost[0];
	while(n) {
		cost += Cost[n%bs];
		n /= bs;
	}
	return cost;
}

void Cal() {
	int i, n, q, min, ind, c;
	int A[100];
	cin>>q;
	while(q--) {
		cin>>n;
		min = 9999999;
		ind = 0;
		for(i = 2; i<37; i++) {
			c = CCost(n,i);
			if(c < min) {
				A[0] = i;
				ind = 1;
				min = c;
			}
			else if(c == min) {
				A[ind++] = i;
			}
		}
		cout<<"Cheapest base(s) for number "<<n<<":";
		for(i = 0; i<ind; i++)
			cout<<" "<<A[i];
		cout<<endl;
	}
}

//#include<stdio.h>

int main() {
	int ks, i, k = 1;
//	freopen("c:\\h.txt","r",stdin);
	cin>>ks;
	while(ks--) {
		for(i = 0; i<36; i++)
			cin>>Cost[i];
		cout<<"Case "<<k++<<":\n";
		Cal();
		if(ks) cout<<"\n";
	} 
	return 0;

}
