#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

char V[] = "0023456789TJQKA";
char S[] = "CDHS";

int Val[300];
int Suit[130];


struct ss {
	int s;
	int v;
};

ss P1[5], P2[5];

void Ini() {
	int i, d;
	for(i = 0; V[i]; i++ ) {
		d = V[i];
		Val[d] = i;
	}
	for(i = 0; S[i]; i++) {
		d = S[i];
		Suit[d] = i;
	}
}
int com(const void *a, const void *b) {
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	return x->v - y->v;
}

int isStraight(ss t[]) {
	int i, h = t[4].v;
	for(i = 1; i<5; i++) {
		if(t[i].s != t[i-1].s) return 0;
		if(t[i].v != t[i-1].v + 1) return 0;
	}
	return h;
}

int FourAKind(ss t[]) {
	int i, c = 1;
	for(i = 1; i<5; i++) {
		if(t[i].v != t[i-1].v) 
			c = 1;
		else c++;
		if(c == 4) return t[i].v;
	}
	return 0;
}

int FullHouse(ss t[] ) {
	int i, c = 1, h = t[0].v;
	for(i = 1; i<5; i++) {
		if(t[i].v == t[i-1].v) c++;
		else break;
	}
	if(c > 3 || c<2) return 0;
	c = 1;
	if(c < 3) h = t[2].v;
	i += 1;
	for(; i<5; i++) {
		if(t[i].v != t[i-1].v) return 0;
	}
	return h;
}

int Flash(ss t[]) {
	int i;
	for(i = 1; i<5; i++) {
		if(t[i].s != t[i-1].s) return 0;
	}
	return 1;
}

int Straight(ss t[]) {
	int i;
	for(i = 1; i<5; i++) {
		if(t[i].v != t[i-1].v +1) return 0;
	}
	return t[4].v;
}

int ThreeAKind(ss t[]) {
	int i, c = 1;
	for(i = 1; i<5; i++) {
		if(t[i].v != t[i-1].v) 
			c = 1;
		else c++;
		if(c == 3) return t[i].v;
	}
	return 0;
}

int TwoPair(ss t[]) {
	int i, p = 0;
	int a[17] = {0};
	for(i = 0; i<5; i++) {
		a[t[i].v] ++;			
	}
	for(i = 2; i<= 16; i++) {
		if(a[i] == 2) p++;
	}
	if(p == 2) return 1;
	return 0;
}

int Pair(ss t[]) {
	int i , c = 1;
	for(i = 1; i<5; i++) {
		if(t[i].v == t[i-1].v) c++;
		else c = 1;
		if(c == 2) return 1;
	}
	return 0;
}


void HighCard() {
	int i;
	for(i = 4; i>=0; i--) {
		if(P1[i].v == P2[i].v) continue;
		if(P1[i].v > P2[i].v){ cout<<"Black wins.\n";  return;}
		else { cout<<"White wins.\n"; return;}
	}
	cout<<"Tie.\n";
}

ss FindRank(ss t[]) {
	ss x;
	x.v = isStraight(t);
	x.s = 1;
	if(x.v) return x;
	x.s = 2;
	x.v = FourAKind(t);
	if(x.v) return x;
	x.s = 3;
	x.v = FullHouse(t);
	if(x.v) return x;
	x.s = 4;
	x.v = Flash(t);
	if(x.v) return x;
	x.s = 5;
	x.v = Straight(t);
	if(x.v) return x;
	x.s = 6;
	x.v = ThreeAKind(t);
	if(x.v) return x;
	x.s = 7;
	x.v = TwoPair(t);
	if(x.v) return x;
	x.s = 8;
	x.v = Pair(t);
	if(x.v) return x;
	x.s = 9;
	//HighCard();
	return x;

}

void Print(int x, int y) {
	if(x == y) {
		cout<<"Tie.\n";
		return;
	}
	if(x > y)
		cout<<"Black wins.\n";
	else 
		cout<<"White wins.\n";
}


void Print2P() {
	int i;
	int a[20] = {0};
	int b[20] = {0};
	int c[4], d[4], ic, id;
	ic = id = 0;
	for(i = 0; i<5; i++) {
		a[P1[i].v] ++;
		b[P2[i].v] ++;
	}
	for(i = 14; i>= 2; i--) {
		if(a[i] == 2) c[ic++] = i;
		if(b[i] == 2) d[id++] = i;
		if(a[i] == 1) c[2] = i;
		if(b[i] == 1) d[2] = i;
	}
	for(i = 0; i<3; i++) {
		if(c[i] == d[i]) continue;
		if(c[i] > d[i]) {
			cout<<"Black wins.\n"; 
			return;
		}
		else {
			cout<<"White wins.\n";
			return; 
		}
	}
	cout<<"Tie.\n";
}

void PrintP() {
	int i;
	int a[20] = {0};
	int b[20] = {0};
	int c[4], d[4], ic, id;
	ic = id = 1;
	for(i = 0; i<5; i++) {
		a[P1[i].v] ++;
		b[P2[i].v] ++;
	}
	for(i = 14; i>= 2; i--) {
		if(a[i] == 2) c[0] = i;
		if(b[i] == 2) d[0] = i;
		if(a[i] == 1) c[ic++] = i;
		if(b[i] == 1) d[id++] = i;
	}
	for(i = 0; i<4; i++) {
		if(c[i] == d[i]) continue;
		if(c[i] > d[i]) {
			cout<<"Black wins.\n"; 
			return;
		}
		else {
			cout<<"White wins.\n";
			return; 
		}
	}
	cout<<"Tie.\n";
}

void Cal() {
	ss t1, t2;
	qsort(P1,5,sizeof(ss),com);
	qsort(P2,5,sizeof(ss),com);
	t1 = FindRank(P1);
	t2=  FindRank(P2);
	if(t1.s < t2.s){
		cout<<"Black wins.\n";
		return;
	}
	else if(t1.s > t2.s){
		cout<<"White wins.\n";
		return;
	}

	if(t1.s ==	9) HighCard();
	else if(t1.s == 1 || t1.s == 2 || t1.s == 3 || t1.s == 5) Print(t1.v,t2.v);
	else if(t1.s == 4) HighCard();
	else if(t1.s == 6) Print(t1.v,t2.v);
	else if(t1.s == 7) Print2P();
	else if(t1.s == 8) PrintP();
}


int main() {
	char cd[10];
	int i, s, v;
	Ini();
//	freopen("c:\\h.txt","r",stdin);
//	freopen("c:\\out.txt","w",stdout);
	while(cin>>cd) {
		v = cd[0];
		s = cd[1];
		s = Suit[s];
		v = Val[v];
		P1[0].v = v;
		P1[0].s = s;
		for(i = 1;i<5; i++) {
			cin>>cd;
			v = cd[0];
			s = cd[1];
			s = Suit[s];
			v = Val[v];
			P1[i].v = v;
			P1[i].s = s;
		}
		for(i = 0; i<5; i++) {
			cin>>cd;
			v = cd[0];
			s = cd[1];
			s = Suit[s];
			v = Val[v];
			P2[i].v = v;
			P2[i].s = s;
		}
		Cal();
	}
	return 0;

}
