#include<stdio.h>
#include<math.h>
#include<string.h>

int puzzle[6][6];
char CM[] = "#LRUD";
char instra[70];

int fg[] = {0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0};

struct ss {
	int r, c;
}pos[20];

void Ini() {
	int i, j, d = 1;
	for(i = 1; i<5; i++) {
		for(j = 1; j<5; j++) {
			pos[d].r = i;
			pos[d++].c = j;
		}
	}
}

int Estiminate() {
	int i, j, d = 0, v;
	for(i = 1; i<5; i++) {
		for(j = 1; j<5; j++) {
			v = puzzle[i][j];
			if(!v) continue;
			d += abs(i - pos[v].r) + abs(j - pos[v].c);
		}
	}
	return d;
}

int inversion(int a[]) {
	int i, j, d = 0, x, p, q;
	for(i = 1; i<= 16; i++) {
		x = a[i];
		if(!x) {x = 16; p = i; /*continue;*/}
		for(j = i+1; j<=16;  j++){
			q = a[j];
			if(a[j] == 0) q = 16;
			if(x>q)
				d++;
		}
	}
	d += fg[p];
	return d;
}

int recur(int level, int limit, int r, int c, int est, int com) {
	int NE[6], cm[6];
	int ind = 0, u, x, y, k, m, i;
	if(est == 0) {
		instra[level] = NULL;
		puts(instra);
		return 1;
	}
	if(com != 2 && c<=3) { // left
		u = puzzle[r][c+1];
		x = abs(r - pos[u].r) + abs(c - pos[u].c);
		y = abs(r - pos[u].r) + abs(c+1 - pos[u].c);
		k = x - y;
		k += est;
		if(level+k <= limit ){
			NE[0] = k;
			cm[0] = 1;
			ind++;
		}
	}
	if(com != 1 && c>1) { // right
		u = puzzle[r][c-1];
		x = abs(r - pos[u].r) + abs(c - pos[u].c);
		y = abs(r - pos[u].r) + abs(c-1 - pos[u].c);
		k = x - y;
		k += est;
		if(level+k <= limit ){
			NE[ind] = k;
			cm[ind++] = 2;
			m = ind-1;
			while(m>1) {
				if(NE[m]<NE[m-1]) {
					k = NE[m];
					x = cm[m];
					NE[m] = NE[m-1];
					cm[m] = cm[m-1];
					NE[m-1] = k;
					cm[m-1] = x;
				}
				m--;
			}
		}
	}
	if(com != 4 && r<4) { // up
		u = puzzle[r+1][c];
		x = abs(r - pos[u].r) + abs(c - pos[u].c);
		y = abs(r + 1 - pos[u].r) + abs(c - pos[u].c);
		k = x - y;
		k += est;
		if(level+k <= limit ){
			NE[ind] = k;
			cm[ind++] = 3;
			m = ind-1;
			while(m>1) {
				if(NE[m]<NE[m-1]) {
					k = NE[m];
					x = cm[m];
					NE[m] = NE[m-1];
					cm[m] = cm[m-1];
					NE[m-1] = k;
					cm[m-1] = x;
				}
				m--;
			}
		}
	}
	if(com != 3 && r>1) { //down
		u = puzzle[r-1][c];
		x = abs(r - pos[u].r) + abs(c - pos[u].c);
		y = abs(r - 1 - pos[u].r) + abs(c - pos[u].c);
		k = x - y;
		k += est;
		if(level+k <= limit ){
			NE[ind] = k;
			cm[ind++] = 4;
			m = ind-1;
			while(m>1) {
				if(NE[m]<NE[m-1]) {
					k = NE[m];
					x = cm[m];
					NE[m] = NE[m-1];
					cm[m] = cm[m-1];
					NE[m-1] = k;
					cm[m-1] = x;
				}
				m--;
			}
		}
	}
	for(i = 0; i<ind; i++) {
		if(cm[i] == 1) {
			instra[level] = CM[2];
			puzzle[r][c] = puzzle[r][c+1];
			puzzle[r][c+1] = 0;
			if(recur(level+1,limit,r,c+1,NE[i],1))
				return 1;
			puzzle[r][c+1] = puzzle[r][c];
			puzzle[r][c] = 0;
		}
		else if(cm[i] == 2) {
			instra[level] = CM[1];
			puzzle[r][c] = puzzle[r][c-1];
			puzzle[r][c-1] = 0;
			if(recur(level+1,limit,r,c-1,NE[i],2))
				return 1;
			puzzle[r][c-1] = puzzle[r][c];
			puzzle[r][c] = 0;
		}
		else if(cm[i] == 3) {
			instra[level] = CM[4];
			puzzle[r][c] = puzzle[r+1][c];
			puzzle[r+1][c] = 0;
			if(recur(level+1,limit,r+1,c,NE[i],3))
				return 1;
			puzzle[r+1][c] = puzzle[r][c];
			puzzle[r][c] = 0;
		}
		else {
			instra[level] = CM[3];
			puzzle[r][c] = puzzle[r-1][c];
			puzzle[r-1][c] = 0;
			if(recur(level+1,limit,r-1,c,NE[i],4))
				return 1;
			puzzle[r-1][c] = puzzle[r][c];
			puzzle[r][c] = 0;
		}
		
	}
	return 0;
}

void Cal(int r, int c, int a[]) {
	int d, i, in;
	d = Estiminate();
	in = inversion(a);
	if(in%2) {
		printf("This puzzle is not solvable.\n");
		return;
	}
	for(i = d; i<51; i++) {
		if(recur(0,i,r,c,d,-1)) break;
	}
}
int main () {
	int kases, i, j, r, c;
	int a[20], p;
	Ini();
	scanf("%d",&kases);
	while(kases--) {
		p = 1;
		for(i = 1; i<5; i++) {
			for(j = 1; j<5; j++) {
				scanf("%d",&puzzle[i][j]);
				a[p++] = puzzle[i][j];
				if(puzzle[i][j] == 0) {
					r = i;
					c = j;
				}
			}
		}
		Cal(r,c,a);
	}
	return 0;
}
