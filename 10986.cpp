#include<iostream>
#include<queue>
#include<list>

using namespace std;

#define maxn 20002
#define INF 900000000 
            
int Cost[maxn];

struct xx {
	int n, cost;
};

list<xx>link[maxn];

struct ss {
	int node;
	int cost;
};

class comp {
public:
	bool operator()(const ss &a, const ss &b) {
		return a.cost > b.cost;
	}
};

priority_queue<ss,vector<ss>, comp > Q;

int N, M, S, T;

void Ini() {
	int i;
	for(i = 0; i<N; i++)
		Cost[i] = INF;
	Cost[S] = 0;
}


int BFS() {
	ss t, d;
	int v, c;
	list<xx>::iterator p;
	t.cost = 0;
	t.node = S;
	Q.push(t);
	while(!Q.empty()) {
		t = Q.top();
		if(t.node == T) return t.cost;
		Q.pop();
		for(p = link[t.node].begin(); p != link[t.node].end(); p++) {
			v = p->n;
			c = p->cost + t.cost;
			if(c < Cost[v]) {
				Cost[v] = c;
				d.node = v;
				d.cost = c;
				Q.push(d);
			}
		}
	}
	return -1;
}

void Cal() {
	int d;
	if(M == 0) {
		cout<<"unreachable\n";
		return;
	}
	Ini();
	d = BFS();
	if(d == -1) cout<<"unreachable\n";
	else cout<<d<<endl;
}

void Free() {
	int i;
	while(!Q.empty()) Q.pop();
	for(i = 0; i<N; i++)
		link[i].clear();
}

int main() {
	int ks, u, v, c, k = 1;
	cin>>ks;
	xx t;
	while(ks--) {
		cin>>N>>M>>S>>T;
		while(M--) {
			cin>>u>>v>>c;
			t.n = v;
			t.cost = c;
			link[u].push_back(t);
			t.n = u;
			link[v].push_back(t);
		}
		cout<<"Case #"<<k++<<": ";
		Cal();
		Free();
	}
	return 0;

}
