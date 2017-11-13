#include<iostream.h>
#include<string>
#include<queue>
#include<stdio.h>

using namespace std;

string Path[25][25];

int X[] = {0, 0,1,-1};
int Y[] = {1,-1,0, 0};

char D[] = "EWSN";

int Label[25][25];
int Dis[25][25];
int Rec[25];

int Carry[25];

int R,C, tt, move, energy;
int Min;

char Mz[22][22];
char Fg[22][22];

struct ss {
	string path;
	int dis, r, c;
};

queue<ss>Q;

void ReadCase() {
	int i, j;
	tt = 2;
	for(i = 0; i<R; i++) {
		cin>>Mz[i];
		for(j = 0; j<C; j++) {
			if(Mz[i][j] == '*')
				Label[i][j] = ++tt;
			else if(Mz[i][j] =='S') {
				Label[i][j] = 1;
			}
			else if(Mz[i][j] == 'T'){
				Label[i][j] = 2;
			}
		}
	}
	
	cin>>move;
	energy = 0;

	for(i = 2; i<tt; i++) {
		cin>>j>>Carry[i+1];
		energy += j;
	}
}


int BFS(int r, int c, int lab) {
	ss t, d;
	int i, nr, nc, found = 0, num;
	t.r = r;
	t.c = c;
	t.dis = 0;
	t.path = "";
	Q.push(t);
	Fg[r][c] = 1;

	while(!Q.empty()) {
		t = Q.front();
		Q.pop();

		for(i = 0; i<4; i++) {
			nr = t.r + X[i];
			nc = t.c + Y[i];
			if(nr >= R || nr < 0 || nc >= C || nc < 0) continue;
			if(Mz[nr][nc] == '#') continue;
			if(Fg[nr][nc] == 1) continue;

			if(Mz[nr][nc] == '*' || Mz[nr][nc] == 'S' || Mz[nr][nc] =='T') {
				num = Label[nr][nc];
				Path[lab][num] = t.path + D[i];
				Dis[lab][num] = t.dis + 1;
				found ++;
			}
			d.r = nr;
			d.c = nc;
			d.dis = t.dis + 1;
			d.path = t.path + D[i];
			Q.push(d);
			Fg[nr][nc] = 1;
		}
	}
	if(found != tt - 1) return 1;
	return 0;
}

void Reset() {
	int i, j;
	for(i = 0; i<R; i++) for(j = 0; j<C; j++) Fg[i][j] = 0;
}

int A[25];
char F[25];


int Guess(int n, int w) {
	int i, c = 0, min = 10000, d = 0;
	c = Dis[n][2] * w;
	for(i = 1; i <= tt; i++) {
		if(i == n) continue;
		if(i != 2 && F[i] == 0) {
			c += Carry[i]*Dis[i][2] ;
		}
	}
	return c;
}

void Record() {
	int i;
	for(i = 1; i<tt; i++)
		Rec[i] = A[i];
}




void Recur(int n, int w, int cost, int level) {
	int i, c;
	if(cost >= Min) return;
	A[level] = n;
	if(level == tt-1) {
		c = w * Dis[n][2];
		if(cost + c >= Min) return;
		Record();
		Min = cost + c;
		return;
	}
	if( (cost + Guess(n,w)) >= Min) return;
	F[n] = 1;
	for(i = 1; i<= tt; i++) {
		if(F[i] == 0 && i != 2) {
			c = w * Dis[n][i];
			Recur(i,w+Carry[i],cost+c,level+1);
		}
	}
	F[n] = 0;
}


void PrintPath() {
	int u, v, f = 0;
	Rec[tt] = 2;
	for(int i = 1; i<tt; i++) {
		if(f++) cout<<"P";
		u = Rec[i];
		v = Rec[i+1];
		cout<<Path[u][v].c_str();
	}
	cout<<endl;
}

void Cal() {
	int i, j, d = 0;
	for(i = 0; i<R; i++) {
		for(j = 0; j<C; j++) {
			if(Mz[i][j] == '*' || Mz[i][j] == 'S' || Mz[i][j] == 'T'){
				d = BFS(i,j,Label[i][j]);
				Reset();
				if(d) break;
			}
		}
		if(d) break;
	}
	if(d){
		cout<<"The hunt is impossible.\n";
		return;
	}
	Min = 999999999;
	Recur(1,move,0,1);
	cout<<"Minimum energy required = "<<Min+energy<<" cal\n";
	PrintPath();
}

int main() {
//	freopen("c:\\h.txt","r",stdin);
	int hunt = 1;
	while(1) {
		cin>>R>>C;
		if(!R && !C) break;
		ReadCase();
		cout<<"Hunt #"<<hunt++<<endl;
		Cal();
		cout<<endl;
	}
	return 0;

}
