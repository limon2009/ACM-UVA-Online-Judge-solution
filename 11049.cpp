#include<iostream>
#include<queue>
#include<string.h>

using namespace std;



#define maxn 8

char Fg[maxn][maxn];
char ud[maxn][maxn][maxn];
char lr[maxn][maxn][maxn];

int Sr, Sc, Er, Ec;

struct ss {
	char path[40];
	int r, c, ind;
};

queue<ss>Q;

void ReadCase() {
	int i, d, x1, y1, x2, y2, j;
	for(j = 0; j<3; j++) {
		cin>>x1>>y1>>x2>>y2;
		if(y1 == y2) {
			if(y1 == 0 || y1 == 6) continue;
			d = y1 + 1;
			for(i = x1 + 1; i<= x2; i++) {
				ud[i][d][y1] = 1;
				ud[i][y1][d] = 1;
			}
		}
		else if(x1 == x2 ) {
			if(x1 == 0 || x1 == 6) continue;
			d = x1 + 1;
			for(i = y1+1; i<= y2; i++) {
				lr[i][d][x1] = 1;
				lr[i][x1][d] = 1;
			}
		}
	}
}


int Left(ss d) {
	if(d.c == 1) return 0;
	if(lr[d.r][d.c][d.c-1] == 1) return 0;
	d.c = d.c - 1;
	if(Fg[d.r][d.c] == 1) return 0;
	d.path[d.ind++] = 'W';
	if(Er == d.r && Ec == d.c) {
		d.path[d.ind] = NULL;
		cout<<d.path<<endl;
		return 1;
	}
	Q.push(d);
	Fg[d.r][d.c] = 1;
	return 0;
}

int Right(ss d) {
	if(d.c == 6) return 0;
	if(lr[d.r][d.c][d.c+1] == 1) return 0;
	d.c = d.c + 1;
	if(Fg[d.r][d.c] == 1) return 0;
	d.path[d.ind++] = 'E';
	if(Er == d.r && Ec == d.c) {
		d.path[d.ind] = NULL;
		cout<<d.path<<endl;
		return 1;
	}
	Q.push(d);
	Fg[d.r][d.c] = 1;
	return 0;
}

int Up(ss d) {
	if(d.r == 1) return 0;
	if(ud[d.c][d.r][d.r-1] == 1) return 0;
	d.r = d.r - 1;
	if(Fg[d.r][d.c] == 1) return 0;
	d.path[d.ind++] = 'N';
	if(Er == d.r && Ec == d.c) {
		d.path[d.ind] = NULL;
		cout<<d.path<<endl;
		return 1;
	}
	Q.push(d);
	Fg[d.r][d.c] = 1;
	return 0;
}

int Down(ss d) {
	if(d.r == 6) return 0;
	if(ud[d.c][d.r][d.r+1] == 1) return 0;
	d.r = d.r + 1;
	if(Fg[d.r][d.c] == 1) return 0;
	d.path[d.ind++] = 'S';
	if(Er == d.r && Ec == d.c) {
		d.path[d.ind] = NULL;
		cout<<d.path<<endl;
		return 1;
	}
	Q.push(d);
	Fg[d.r][d.c] = 1;
	return 0;
}

void BFS() {
	ss d;
	d.r = Sr;
	d.c = Sc;
	strcpy(d.path,"");
	d.ind = 0;
	Q.push(d);
	Fg[Sr][Sc] = 1;
	while(!Q.empty()) {
		d = Q.front();
		Q.pop();
		if(Left(d)) return;
		if(Right(d)) return;
		if(Up(d)) return;
		if(Down(d)) return;
	}
}

void Free() {
	int i, j, k;
	for(i = 0; i<7; i++) {
		for(j = 0; j<7; j++) {
			for(k = 0; k<7; k++) {
				lr[i][j][k] = 0;
				ud[i][j][k] = 0;
				Fg[j][k] = 0;
			}
		}
	}
	while(!Q.empty()) Q.pop();
}
#include<stdio.h>

int main() {
//	freopen("c:\\11049.in","r",stdin);
	//freopen("c:\\out.ans","w",stdout);
	while(cin>>Sc>>Sr) {
		if(!Sr && !Sc) break;
		cin>>Ec>>Er;
		ReadCase();
		BFS();
		Free();
	}
	return 0;

}
