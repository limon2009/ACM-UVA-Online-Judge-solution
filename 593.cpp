#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<string.h>
#include<queue>
#include<math.h>

using namespace std;
#define maxn 15

map<string,int>M;
map<string,int>MM;
map<string,int>G;

vector<int>Link[maxn];
vector<int>Host[maxn];
vector<string>HName;
int IsLand[52];

char GR[52][22];
int TH[12][12];
int N, total;

struct SS {
	int n;
	int ttl;
};

struct XX {
	string h;
	string pack;
	int ttl;
}R[1000];

int TTL[maxn];
queue<SS>Q;

int com( const void *a, const void *b) {
	int p, q;
	XX *x = ( XX *)a;
	XX *y = ( XX *)b;
	if(x->h.compare(y->h) != 0) {
		p = atof(x->h.c_str());
		q = atof(y->h.c_str());
		return p - q;
	}
	if(x->pack.compare(y->h) != 0) {
		p = atof(x->pack.c_str());
		q = atof(y->pack.c_str());
		return p - q;
	}
	return 0;
}

int ReadCase() {
	int i, j, island, n, d, u, v, host;
	string ss, tt;
	island = host = 1;
	HName.push_back(" ");
	cin>>N;
	if(!N) return 0;
	for(i = 0; i<N; i++) {
		cin>>ss>>n;
		u = MM[ss];
		if(u == 0) {
			MM[ss] = island;
			u = island;
			island ++;
		}
		while(n--) {
			cin>>tt;
			if(tt.compare("T") == 0) {
				cin>>d>>ss;
				v = MM[ss];
				if(!v) {
					MM[ss] = island;
					v = island;
					island++;
				}
				TH[u][v] = d;
				Link[u].push_back(v);
			}
			else {
				cin>>ss;
				v = M[ss];
				if(v == 0) {
					M[ss] = host;
					v = host;
					host ++;
					HName.push_back(ss);
				}
				Host[u].push_back(v);
				IsLand[v] = u;
			}
		}
	}
	return 1;
}

void BFS(int h, int ttl, string pack) {
	int i, v, tl, u;
	u = IsLand[h];
	SS t, d;
	t.n =  u;
	t.ttl = ttl;
	for(i = 1; i<maxn; i++) 
		TTL[i] = -1;
	TTL[u] = ttl;
	Q.push(t);
	while(!Q.empty()) {
		t = Q.front();
		Q.pop();
		u = t.n;
		for(i = 0; i<Link[u].size(); i++) {
			v = Link[u][i];
			tl = t.ttl - TH[u][v];
			if(tl < 0 ) continue;
			if(tl < TTL[v]) continue;
			TTL[v] = tl;
			d.n = v;
			d.ttl = tl;
			Q.push(d);
		}
	}
}


void Cal() {
	int q, h, ind = 1, g, tl, i, j, k;
	string cc, hh, gg, pk;
	total = 0;
	XX x;
	cin>>q;
	while(q--) {
		cin>>cc;
		if(cc.compare("J") == 0 || cc.compare("L") == 0) {
			cin>>hh>>gg;
			h = M[hh];
			g = G[gg];
			if(g == 0) {
				g = ind;
				G[gg] = ind;
				ind ++;
			}
			if(cc.compare("J") == 0)
				GR[h][g] = 1;
			else GR[h][g] = 0;
		}
		else {
			cin>>hh>>gg>>pk>>tl;
			h = M[hh];
			g = G[gg];
			BFS(h,tl,pk);
			for(i = 1; i<= N; i++)  {
				if(TTL[i] < 0 ) continue;
				for(j = 0; j<Host[i].size(); j++) {
					k = Host[i][j];
					if(GR[k][g] == 1) {
						x.h = HName[k];
						x.pack = pk;
						x.ttl = TTL[i];
						R[total++] = x;
					}
				}
			}
		}
	}
}

void Free() {
	int i;
	M.clear();
	G.clear();
	MM.clear();
	for(i = 1; i<=N; i++) {
		Link[i].clear();
		Host[i].clear();
	}
	HName.clear();
	for(i = 1; i<51; i++) {
		for(int j = 1; j<22; j++)
			GR[i][j] = 0;
	}
}

int main() {
	int NT = 1, i;
	//freopen("c:\\h.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);
	while(ReadCase()) {
		Cal();
		qsort(R,total,sizeof(XX),com);
		cout<<"Network #"<<NT++<<endl;
		for(i = 0; i<total; i++) {
			cout<<R[i].h<<" "<<R[i].pack<<" "<<R[i].ttl<<endl;
		}
		Free();
		cout<<endl;
	}
	return 0;

}
