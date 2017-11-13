#include<iostream>
#include<math.h>

using namespace std;

int nosol(int r1, int c1, int r2, int c2) {
	if(r1 % 2 == r2%2) {	
		if(c1 % 2 != c2 % 2) return 1;
	}
	else if(c1 % 2== c2 % 2) return 1;
	return 0;
}


void Cal(int r1, int c1, int r2, int c2) {
	int x, y;
	if(nosol(r1,c1,r2,c2)) {
		cout<<"no move\n";
		return;
	}
	if(r1 == r2 and c1 == c2) {
		cout<<"0\n";
		return;
	}
	x = abs(r1-r2);
	y = abs(c1-c2);
	if(x == y) cout<<"1\n";
	else cout<<"2\n";
}

int main() {
	int ks, t, r1, r2, c1, c2, N;
	cin>>ks;
	while(ks--) {
		cin>>t;
		cin>>N;
		while(t--) {
			cin>>r1>>c1>>r2>>c2;
			Cal(r1,c1,r2,c2);
		}
	}	
	return 0;

}
