#include<iostream>
#include<vector>

using namespace std;

struct ss {
	vector<int>S;
	int rem;
};
ss N[52];

void Gen() {
	int i, j, d;
	N[1].rem = 1;
	N[2].S.push_back(1);
	N[2].rem = 2;
	for(i = 3; i<= 50; i++) {
		d = N[i-1].rem + 2;
		if(d > i) d = 2;
		N[i].rem = d;
		N[i].S.push_back(1);
		for(j = 0; j<N[i-1].S.size(); j++) {
			d = N[i-1].S[j] + 2;
			if( d> i ) d = 2;
			N[i].S.push_back(d);
		}
	}
}

void Print(int n) {
	int i;
	cout<<"Discarded cards:";
	if(N[n].S.size()) cout<<" "<<N[n].S[0];
	for(i = 1; i<N[n].S.size(); i++)
		cout<<", "<<N[n].S[i];
	cout<<endl;
	cout<<"Remaining card: "<<N[n].rem<<endl;
}
int main() {
	Gen();
	int n;
	while(cin>>n && n) {
		Print(n);
	}
	return 0;

}
