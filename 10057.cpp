#include<iostream>
#include<vector>
#include<algorithm>

#define maxn 65536

using namespace std;

int F[maxn+2], N;
vector<int>V;

void Cal() {
	int n, m, c;
	sort(V.begin(),V.end());
	if(N%2) {
		cout<<V[N/2];
		cout<<" "<<F[V[N/2]]<<" "<<"1\n";
	}
	else {
		n = V[N/2];
		m = V[N/2 - 1];
		c = F[n];
		if(n != m)
			c = F[n] + F[m];
		cout<<m<<" ";
		cout<<c<<" ";
		cout<<n-m+1<<endl;
	}
}

void ReSet() {
	int i;
	for(i = 0; i<N; i++) {
		F[V[i]] = 0;
	}
	V.clear();
}

int main() {
	int n, m;
//	freopen("h.txt","r",stdin);
	while(cin>>N && N) {
		m = N;
		while(m--) {
			cin>>n;
			F[n]++;
			V.push_back(n);
		}
		Cal();
		ReSet();
	}
	return 0;

}
