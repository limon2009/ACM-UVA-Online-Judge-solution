#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

char D[] = " .xW";
vector<int>v;


void Cal() {
	int A[2][50], i, ind1 = 0, ind2 = 1, times = 50, k;
	memset(A[0],0,sizeof(int)*50);
	memset(A[1],0,sizeof(int)*50);
	A[0][19] = 1;
	while(times--) {
		for(i = 0; i<40; i++) cout<<D[A[ind1][i]];
		cout<<endl;
		for(i = 1; i+1<40; i++) {
			k = A[ind1][i-1] + A[ind1][i] + A[ind1][i+1];
			A[ind2][i] = v[k];
		}
		A[ind2][0] = v[A[ind1][0] + A[ind1][1]];
		A[ind2][39] = v[A[ind1][39] + A[ind1][38]];
		ind1++;
		ind2++;
		ind1 %= 2;
		ind2 %= 2;
	}
}
int main() {
	int ks, n = 0, m;
	cin>>ks;
	while(ks--) {
		n = 0;
		while(n++<10){
			cin>>m;
			v.push_back(m);
		}
		Cal();
		if(ks) cout<<endl;
		v.clear();
	}
	return 0;

}
