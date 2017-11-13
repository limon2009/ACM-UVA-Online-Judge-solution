#include<iostream>

using namespace std;

#define mx 110

int N;
int Sq[mx][mx];

void Swap(int r1, int c1, int r2, int c2) {
	int n = Sq[r1][c1];
	Sq[r1][c1] = Sq[r2][c2];
	Sq[r2][c2] = n;
}


void Inverse(int pos, int size) {
	int p, q, sz = pos+size-1;
	if(size == 1) return;
	p = sz;
	q = pos;
	while(p>=pos) {
		Swap(p,pos,sz,q);
		p--;
		q++;
	}
	p = sz;
	q = pos;
	while(p>pos) {
		Swap(pos,p,q,sz);
		p--;
		q++;
	}
}


void Diagonal(int pos, int size) {
	int p, s = pos+size - 1;
	p = pos;
	if(size == 1) return;
	while(p <= s) {
		Swap(p,pos,pos,p);
		p++;
	}
	p = s; 
	while(p > pos) {
		Swap(s,p,p,s);
		p--;
	}
}

void Left_Right(int pos, int size) {
	if(size == 1) return;
	int p, q, s = size+pos - 1;
	p = pos+1;
	q = s-1;
	while(p < q) {
		Swap(pos,p,pos,q);
		Swap(s,p,s,q);
		p++;
		q--;
	}
	for(int i = pos; i<=s; i++)
		Swap(i,pos,i,s);
}

void Up_Down(int pos, int size) {
	int i, p, q, s = pos +size - 1;
	if(size == 1) return;
	for(i = pos; i<=s; i++)
		Swap(pos,i,s,i);
	p = pos+1;
	q = s-1;
	while(p<q) {
		Swap(p,pos,q,pos);
		Swap(p,s,q,s);
		p++;
		q--;
	}
}


void Cal(){ 
	int i, size = N, t, n, d, k = 1;
	n = (N+1)/2;
	for(i = 1; i<= n; i++) {
		cin>>t;
		while(t--) {
			cin>>d;
			switch(d) {
			case 1:Up_Down(k,size); break;
			case 2:Left_Right(k,size); break;
			case 3:Diagonal(k,size); break;
			case 4:Inverse(k,size); break;
			}
		}
		size -= 2;
		k++;
	}
	for(i = 1; i<= N; i++) {
		cout<<Sq[i][1];
		for(t = 2; t<=  N; t++)
			cout<<" "<<Sq[i][t];
		cout<<endl;
	}
//	cout<<endl;
}


#include<stdio.h>

int main() {
	int ks, i, j;
//	freopen("h.txt","r",stdin);
	cin>>ks;
	while(ks--) {
		cin>>N;
		for(i = 1; i<= N; i++) {
			for(j = 1; j<= N; j++)
				cin>>Sq[i][j];
		}
		Cal();
	}
	return 0;

}
