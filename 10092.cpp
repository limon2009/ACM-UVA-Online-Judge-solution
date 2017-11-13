#include<iostream>
#include<list>
#include<queue>

using namespace std;

#define maxn 1024

list<int>link[maxn];
list<int>Cat[22];

int Cost[maxn][maxn];
int parent[maxn];
char Match[maxn][maxn];
int Block[maxn];
int Req[22], A[22];
char Fg[maxn];
queue<int>Q;

int P, CT, Des, Ter, ind;

int SetAll() {
	int i, d, r;
	Des = P+CT+1;
	Ter = 0;
	for(i = 1; i <= CT; i++) {
		d = P+i;
		link[d].push_back(Des);
		Cost[d][Des] = Req[i];
		Ter += Req[i];
	}
	return 0;
}

void Print() {
	int c, i, j;

	list<int>::iterator p;
	cout<<"1\n";
	for(i = 1; i<= CT; i++) {
		c = 0;
		for(p = Cat[i].begin(); p != Cat[i].end(); p++) {
			j = *p;
			if(c++) cout<<" ";
			cout<<j;
		}
		cout<<endl;
	}
}

void Recur(int n) {
	if(n < 0) return;
	Recur(parent[n]);
	A[ind++] = n;
}

void Mark(int n) {
	int i, u , v;
	ind = 0;
	Recur(Des);
	for(i = 1; i<ind; i++) {
		u = A[i-1];
		v = A[i];
		Match[u][v] = 1;
		Match[v][u] = 0;
		Cost[u][v]  -= 1;
		Cost[v][u]  += 1;
	}
	Ter --;
}

void BFS(int n) {
	int u, v;
	for(u = 1; u <= Des; u++)
		Fg[u] = 0;
	list<int>::iterator p;
	parent[n] = -1;
	Q.push(n);
	Fg[n] = 1;
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		for(p = link[u].begin(); p != link[u].end(); p++) {
			v = *p;
			if(Cost[u][v] == 0 || Block[v] || Fg[v]) continue;
			parent[v] = u;
			if(v == Des) {
				Mark(n);
				return;
			}
			Fg[v] = 1;
			Q.push(v);
		}
	}
}

int Impossible() {
	int i, d;
	for(i = 1; i<= CT; i++) {
		d = i + P;
		if(Req[i] > link[d].size()) return 1;
	}
	return 0;
}
void Cal() {
	int i;
/*	if(Impossible()) {
		cout<<"0\n";
		return;
	}*/
	if(SetAll()) {
		Print();
		return;
	}
	for(i = 1; i<= P && Ter; i++) {
		BFS(i);
		while(!Q.empty()) Q.pop();
	}
	if(Ter) cout<<"0\n";
	else {
		for(i = 1; i<= P; i++) {
			if(Block[i]) continue;
			for(int j = 1; j<= CT ; j ++) {
				if(Match[i][j+P]) {
					Cat[j].push_back(i);
					break;
				}
			}
		}
		Print();
	}
}

void Free() {
	int i, c;
	list<int>::iterator p;
	for(i = 1; i<= CT; i++)
		Cat[i].clear();
	for(i = 1; i<= P; i++) {
		for(p = link[i].begin(); p != link[i].end(); p++) {
			c = *p;
			Match[i][c] = Match[c][i] = 0;
			Cost[c][i] = Cost[i][c] = 0;
		}
		link[i].clear();
	}
	for(i = P+1; i<= P+CT; i++) {
		link[i].clear();
		Cost[i][Des] = Cost[Des][i] = 0;
	}
}

int main() {
	int i, c, j, nc;
	//freopen("h.txt","r",stdin);
	while(cin>>CT>>P) {
		if(!P && !CT) break;
		for(i = 1; i<= CT; i++)
			cin>>Req[i];
		
		for(i = 1; i<= P; i++) {
			cin>>nc;
			for( j = 0; j<nc; j++) {
				cin>>c;
				link[i].push_back(c+P);
				link[c+P].push_back(i);
				Cost[i][c+P] = 1;
			}
		}
		Cal();
		Free();
	}
	return 0;

}
