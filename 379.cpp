#include<iostream>
#include<stdio.h>

using namespace std;

int bb[7][7] = {{0,0,1,2,3,0,0},
				{0,0,4,5,6,0,0},
				{7,8,9,10,11,12,13},
				{14,15,16,17,18,19,20},
				{21,22,23,24,25,26,27},
				{0,0,28,29,30,0,0},
				{0,0,31,32,33,0,0}};

int E[35], P, F, MAX;

struct ss {
	int r, c;
	int empty;
}hole[35];

struct value {
	int val;
}v[7][7];

struct nExt {
	int st, mid, ter;
}nt;

void Ini() {
	int i, j, k;
	for(i = 0; i<7; i++) {
		for(j = 0; j<7; j++) {
			if(!bb[i][j]) continue;
			k = bb[i][j];
			hole[k].r = i;
			hole[k].c = j;
			hole[k].empty = 1;
			v[i][j].val = k;
		}
	}
}

void ReadCase() {
	P = 0;
	int n;
	while(1) {
		cin>>n;
		if(!n) break;
		hole[n].empty = 0;
		E[P++] = n;
	}
}

void Up(int n) {
	int r1, r2, c, m, t;
	r1 = hole[n].r - 1;
	r2 = hole[n].r - 2;
	c = hole[n].c;
	if(r1<0 || r2<0 ) return;
	if(v[r1][c].val == 0 || v[r2][c].val == 0) return;
	m = v[r1][c].val;
	t = v[r2][c].val;
	if(hole[m].empty) return;
	if(hole[t].empty == 0) return;
	if(t>MAX) {
		MAX = t;
		F = 1;
		nt.st = n;
		nt.mid = m;
		nt.ter = t;
	}
}

void Down(int n) {
	int r1, r2, c, m, t;
	r1 = hole[n].r + 1;
	r2 = hole[n].r + 2;
	c = hole[n].c;
	if(r1 >=7 || r2>=7 ) return;
	if(v[r1][c].val == 0 || v[r2][c].val == 0) return;
	m = v[r1][c].val;
	t = v[r2][c].val;
	if(hole[m].empty) return;
	if(hole[t].empty == 0) return;
	if(t>MAX) {
		MAX = t;
		F = 1;
		nt.st = n;
		nt.mid = m;
		nt.ter = t;
	}
}


void Left(int n) {
	int c1, c2, r, m, t;
	c1 = hole[n].c - 1;
	c2 = hole[n].c - 2;
	r = hole[n].r;
	if(c1<0 || c2<0 ) return;
	if(v[r][c1].val == 0 || v[r][c2].val == 0) return;
	m = v[r][c1].val;
	t = v[r][c2].val;
	if(hole[m].empty) return;
	if(hole[t].empty == 0) return;
	if(t>MAX) {
		MAX = t;
		F = 1;
		nt.st = n;
		nt.mid = m;
		nt.ter = t;
	}
}

void Right(int n) {
	int c1, c2, r, m, t;
	c1 = hole[n].c + 1;
	c2 = hole[n].c + 2;
	r = hole[n].r;
	if(c1 >=7 || c2>=7 ) return;
	if(v[r][c1].val == 0 || v[r][c2].val == 0) return;
	m = v[r][c1].val;
	t = v[r][c2].val;
	if(hole[m].empty) return;
	if(hole[t].empty == 0) return;
	if(t>MAX) {
		MAX = t;
		F = 1;
		nt.st = n;
		nt.mid = m;
		nt.ter = t;
	}
}


void IsMove() {
	int i,  n;
	MAX = F = 0;
	for(i = 33; i>=1; i--) {
		n = i;
		if(hole[n].empty) continue;
		Down(n);
		Right(n);
		Left(n);
		Up(n);
	}
}

void Move() {
	int st, mid, ter;
	int r, c;
	st = nt.st;
	mid =nt.mid;
	ter =nt.ter;
	hole[ter].empty = 0;
	hole[mid].empty = 1;
	hole[st].empty = 1;
	r = hole[ter].r;
	c = hole[ter].c;
	v[r][c].val = ter;
}

void Count() {
	int sum = 0, i;
	for(i = 1; i<=33; i++) {
		if(hole[i].empty) continue;
		sum += i;
	}
	cout<<sum<<endl;
}

void Cal() {
	while(1) {
		IsMove();
		if(!F) break;
		Move();
	}
	Count();
}


int main() {
	int kase;
	Ini();
	cout<<"HI Q OUTPUT\n";
	cin>>kase;
	while(kase--) {
		ReadCase();
		Cal();
		if(kase) Ini();
	}
	cout<<"END OF OUTPUT\n";
	return 0;
}

