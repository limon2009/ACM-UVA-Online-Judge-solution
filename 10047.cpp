#include<iostream>
#include<queue>
#define maxn 30

using namespace std;

struct  ss {
	int r, c;
	int time;
	char color;
	char dir;
};

char M[maxn][maxn];
char F[maxn][maxn][5];
char D[maxn][maxn][5][5];

queue<ss>Q;

int R, C, sr, sc, tr,tc, mint;

void Change(ss temp) {
	int dir;
	ss dum = temp;
	dir = (temp.dir - 1 + 4)%4;
	if(D[temp.r][temp.c][temp.color][dir] == 0) {
		dum.dir = dir;
		dum.time = temp.time + 1;
		Q.push(dum);
		D[temp.r][temp.c][temp.color][dum.dir] = 1;
	}
	dum.dir = (temp.dir + 1)%4;
	if(D[temp.r][temp.c][temp.color][dum.dir] == 0) {
		dum.time = temp.time + 1;
		Q.push(dum);
		D[temp.r][temp.c][temp.color][dum.dir] = 1;
	}
}

int Forward(ss temp) {
	int nr, nc, co;
	ss dum;
	if(temp.dir == 0) {
		nr = temp.r-1;
		nc = temp.c;
	}
	else if(temp.dir == 1) {
		nr = temp.r;
		nc = temp.c+1;
	}
	if(temp.dir == 2) {
		nr = temp.r+1;
		nc = temp.c;
	}
	else if(temp.dir == 3) {
		nr = temp.r;
		nc = temp.c-1;
	}
	co = (temp.color+1)%5;

	if(nr>=R || nr<0 || nc>=C || nc<0) return 0;
	if(M[nr][nc] == '#') return 0;
	if(F[nr][nc][co] == 1) return 0;
	if(nr == tr && nc == tc && co == 0) return temp.time + 1;
//	F[nr][nc][co] = 1;
	dum.r = nr;
	dum.c = nc;
	dum.color = co;
	dum.dir = temp.dir;
	dum.time = temp.time+1;
	Q.push(dum);
	return 0;
}

int BFS() {
	int  d;
	ss temp;
	temp.r = sr;
	temp.c = sc;
	temp.time = 0;
	temp.color = 0;
	temp.dir = 0;
	Q.push(temp);
	F[sr][sc][0] = 1;
	D[sr][sc][0][0] = 1;
	while(!Q.empty()) {
		temp = Q.front();
		Q.pop();
		d = Forward(temp);
		if(d > 0) return d;
		Change(temp);
	}
	return -1;
}

void Free() {
	int i, j, k, l;
	for(i = 0; i<=R; i++){
		for(k = 0; k<= C; k++) {
			for(j = 0; j<5; j++){
				F[i][k][j] = 0;
				for(l = 0; l<5; l++)
					D[i][k][j][l] = 0;
			}
		}
	}
}

void Cal() {
	int d;
	d = BFS();
	if(d <0) cout<<"destination not reachable\n";
	else cout<<"minimum time = "<<d<<" sec\n";
	Free();
	while(!Q.empty()) Q.pop();
}

int main() {
	int i, j, c, k = 1;
//	freopen("h.txt","r",stdin);
	while(cin>>R>>C) {
		if(!R && !C) break;
		c = 0;
		for(i = 0; i<R; i++){
			cin>>M[i];
			if(c > 1) continue;
			for( j = 0; M[i][j]; j++) {
				if(M[i][j] == 'S') {
					sr = i;
					sc = j;
					c++;
				}
				else if(M[i][j] == 'T') {
					c++;
					tr = i;
					tc = j;
				}
			}
		}
		if(k>1) cout<<endl;
		cout<<"Case #"<<k++<<endl;
		Cal();
	}
	return 0;

}
