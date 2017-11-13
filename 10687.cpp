#include<iostream>
#include<math.h>
#include<vector>
#define maxn 1001
using namespace std;

vector<int>link[maxn];

struct ss {
	int x, y;
}P[maxn];

int N;
char Fg[maxn];

int Dis(int p, int q) {
	int d, n;
	d = P[p].x - P[q].x;
	d *= d;
	n = P[p].y - P[q].y;
	n *= n;
	return d + n;
}

int Swap(int a, int b) {
	if(P[a].x > P[b].x) return 1;
	if(P[a].x == P[b].x && P[a].y > P[b].y) return 1;
	return 0;
}

void MakeLink() {
	int min1, min2;
	int i, j, dis, p1, p2;
	
	for(i = 0; i<N; i++) {
		
		min1 = min2 = 1000000000;

		for(j = 0; j<N; j++) {
			if(i == j) continue;
			dis = Dis(i, j);
			
			if(dis < min1 ) {
				p2 = p1;
				p1 = j;
				min1 = dis;
			}
			else if( dis < min2) {
				p2 = j;
				min2 = dis;
			}

			else if(dis == min1) {
				if(Swap(p1,j)){
					if( min1 == min2 && Swap(p1, p2)) 
						p2 = p1;
					p1 = j;
				}
			}
			else if(dis == min2 && Swap(p2,j)) 
				p2 = j;
		}
		link[i].push_back(p1);
		link[i].push_back(p2);
	}
}


void Recur(int u) {
	int i, v;
	Fg[u] = 1;
	for(i = 0; i<link[u].size(); i++) {
		v = link[u][i];
		if(Fg[v]) continue;
		Recur(v);
	}
}

void Cal() {
	int i;
	if(N <= 3) {
		cout<<"All stations are reachable.\n";
		return;
	}
	Recur(0);
	for(i = 0; i<N; i++) {
		if(!Fg[i]) {
			cout<<"There are stations that are unreachable.\n";
			return;
		}
	}
	cout<<"All stations are reachable.\n";
}


void Free() {
	int i;
	for(i = 0; i<N; i++) {
		Fg[i] = 0;
		link[i].clear();
	}
}

int main() {
	int i;
//	freopen("c:\\h.txt","r",stdin);
	while(cin>>N && N) {
		for(i = 0; i<N; i++) {
			cin>>P[i].x>>P[i].y;
		}
		MakeLink();
		Cal();
		Free();
	}
	return 0;

}
