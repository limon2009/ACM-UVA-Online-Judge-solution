#include<iostream>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

using namespace std;

#define maxn 55

char map[maxn][maxn];

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
int R, C;

struct ss {
	char ch;
	int count;
};

ss H[100000];
int count;

int com(const void *a, const void *b) {
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	if(x->count != y->count) return y->count - x->count;
	return x->ch - y->ch;
}	

void Recur(int r, int c, char ch) {
	int i, nx, ny;
	map[r][c] = 0;
	count++;
	for(i = 0; i<4; i++) {
		nx = X[i] + r;
		ny = Y[i] + c;
		if(nx >= R || nx<0 || ny < 0 || ny >= C) continue;
		if(map[nx][ny] != ch) continue;
		Recur(nx,ny,ch);
	}
}



void Cal() {
	int th = 0, i, d;
	for(i = 0; i<R; i++) {
		for(int j = 0; j < C; j++) {
			if(isalpha(map[i][j])) {
				count = 0;
				H[th].ch = map[i][j];
				Recur(i, j, map[i][j]);
				H[th++].count = count;
			}
		}
	}
	qsort(H,th,sizeof(ss),com);
	for(i = 0; i<th; i++)
		cout<<H[i].ch<<" "<<H[i].count<<endl;
}

int main() {
	int i, d = 1;
	while(cin>>R>>C) {
		if(!R && !C) break;
		for(i = 0; i<R; i++)
			cin>>map[i];
		cout<<"Problem "<<d++<<":\n";
		
		Cal();
	}
	return 0;

}
