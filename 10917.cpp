#include<iostream>
#include<list>
#include<queue>

using namespace std;

#define maxn 1002
#define INF 2147483640

struct ss {
	int node;
	int cost;
};

int Path[maxn], C[maxn];
char Fg[maxn];

list<ss>L[maxn];

class comp {
public :
	bool operator() (const ss &a, const ss &b) {
		return a.cost > b.cost;
	}
};

priority_queue<ss,vector<ss>, comp> Q;

int N, E;

void Ini() {
	int i;
	for(i = 1; i<= N; i++) {
		Path[i] = Fg[i] = 0;
		C[i] = INF;
	}
}


void DIJ() {
	ss t, dmp, x;
	int c, fg = 0;
	list<ss>::iterator p;
	t.node = 2;
	t.cost = 0;
	C[2] = 0;
	Q.push(t);
	while(!Q.empty()) {
		t = Q.top();
		Q.pop();
		for(p = L[t.node].begin();  p != L[t.node].end(); p++) {
			dmp = *p;
			c = dmp.cost + t.cost;
			if(C[dmp.node] < c) continue;
			else if(C[dmp.node] > c) {
				C[dmp.node] = c;
				x.cost = c;
				x.node = dmp.node;
				Q.push(x);
			}
		}
	}
}

int Recur(int n) {
	ss t;
	if(n == 1) return 1;
	if(Fg[n]) return Path[n];
	list<ss>::iterator p;
	for(p = L[n].begin();  p != L[n].end(); p++) {
		t = *p;
		if(C[n] >=  C[t.node] ) continue;
		Path[n] += Recur(t.node);
	}
	Fg[n] = 1;
	return Path[n];
}

void ReadCase() {
	ss temp;
	int i, u , v, c;
	for( i = 0; i<E; i++) {
		cin>>u>>v>>c;
		temp.node = v;
		temp.cost = c;
		L[u].push_back(temp);
		temp.node = u;
		L[v].push_back(temp);
	}
}

int main() {
//	freopen("h.txt","r",stdin);
	while(cin>>N && N) {
		cin>>E;
		Ini();
		ReadCase();
		DIJ();
		cout<<Recur(2)<<endl;
		for(int i = 1; i<= N; i++) 
			L[i].clear();
	}
	return 0;

}
