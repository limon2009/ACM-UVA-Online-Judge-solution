#include<iostream>

using namespace std;

#define mx 100

int P[mx+1], R[mx+1], N, E;

void Ini() {
	int i;
	for(i = 0; i<mx; i++) {
		P[i] = i;
		R[i] = 1;
	}
}

int Find(int n) {
	if(P[n] == n)
		return n;
	else P[n] = Find(P[n]);
	return P[n];
}

void MakeLink(int u, int v) {
	if(R[u] > R[v]) {
		P[v] = u;
	}
	else {
		P[u] = v;
		if(R[u] == R[v])
			R[v] ++;
	}
}

void Cal() {
	int face = 1, u, v;
	char a, b;
	while(E--) {
		cin>>a>>b;
		u = a - 'A';
		v = b - 'A';
		u = Find(u);
		v = Find(v);
		if(u != v) {
			MakeLink(u,v);
		}
		else face++;
	}
	cout<<face<<endl;
}


int main() {

	while(cin>>N>>E) {
		Ini();
		Cal();
	}
	return 0;

}
