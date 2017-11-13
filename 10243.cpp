#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define maxn 1001

char link[maxn][maxn];

vector<int>V[maxn];
vector<int>W;
queue<int>Q;

char Fg[maxn];
char color[maxn];
char Taken[maxn];
char mark[maxn];
int P[maxn];

int N, M, Ind;

void BFS(int n) {
	int u, v, i, c;
	color[n] = 1;
	Q.push(n);
	Fg[n] = 1;
	W.clear();
	W.push_back(n);
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		c = 1;
		if(color[u] == 1) c = 2;
		for(i = 0; i<V[u].size(); i++) {
			v = V[u][i];
			if(Fg[v] == 0) {
				color[v] = c;
				Fg[v] = 1;
				if(c == 1) W.push_back(v);
				Q.push(v);
			}
		}
	}
}


void Setting() {
	int i, u, v;
	for(i = 0; i<W.size(); i++) {
		u = W[i];
		for(int j = 0; j<V[u].size(); j++) {
			v = V[u][j];
			link[v][u] = 0;
		}
	}
}

void Mark(int v) {
	int u;
	u = P[v];
	if(u < 0) return;
	link[u][v] --;
	link[v][u]++;
	Mark(P[v]);
}

int Match(int u) {
	int i, v;
	mark[u] = 1;
	for(i = 0; i<V[u].size(); i++) {
		v = V[u][i];
		if(mark[v] == 1) continue;
		if(link[u][v] == 0) continue;
		P[v] = u;
		if(color[v] == 2 && Taken[v] == 0) {
			Taken[v] = 1;
			Mark(v);
			return 1;
		}
		if(Match(v)) return 1;
	}
	return 0;
}

int MAXI() {
	int i, d = 0;
	Setting();
	for(i = 0; i<W.size(); i++) {
		P[W[i]] = -1;
		if(Match(W[i])) d++;
		for(int j = 1; j<= N; j++)
			mark[j] = 0;
	}
	return d;
}

void Cal() {
	int i, j = 0;
	if(N == 1) {
		cout<<"1\n";
		return;
	}
	for(i = 1; i<= N; i++) {
		if(Fg[i] == 1) continue;
		BFS(i);
		if(W.size() == 1) j ++;
		else
			j += MAXI();
	}
	cout<<j<<endl;
}

void Free() {
	int i, j, v;
	for(i = 1; i<= N; i++) {
		mark[i] = color[i] = 0;
		Taken[i] = Fg[i] = 0;
		for(j = 0; j<V[i].size(); j++) {
			v = V[i][j];
			link[i][v] = link[v][i] = 0;
		}
		V[i].clear();
	}
}


int main() {
	int i, j, n,  v;
//	freopen("c:\\h.txt","r",stdin);
	while(cin>>N && N) {
		for(i = 1; i<= N; i++) {
			cin>>n;
			for(j = 1; j<= n; j++) {
				cin>>v;
				link[i][v] = 1;
				link[v][i] = 1;
				V[i].push_back(v);
			}
		}
		Cal();
		Free();
	}
	return 0;

}
