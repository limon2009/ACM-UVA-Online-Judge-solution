#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

#define MAXN 100000
#define INF 10000000
int N;

struct ss {
	int val;
	char color;
};

ss P[MAXN];

int MX[MAXN], MN[MAXN];
int indM, indN;

int com(const void *a, const void *b) {
	ss *x, *y;
	x = (ss *)a;
	y = (ss *)b;
	return y->val - x->val;
}

int Find(int key, int A[], int f) {
	int i, st;
	st = indM;
	if(f == 1) st = indN;
	for(i = st; i>= 1; i--) {
		if(A[i] > key) break;
	}
	return i;
}

int LIS() {
	int i, max = 0, ind;
	indM = indN = 0;
	MX[0] = MN[0] = INF;
	for(i = 0; i<N; i++) {
		if(P[i].color == 0) {
			ind = Find(P[i].val,MN,1) + 1;
			if(ind> max) max = ind ;
			if(ind > indM) indM = ind;
			if(MX[ind] < P[i].val ) MX[ind] = P[i].val;
		}
		else {
			ind = Find(P[i].val,MX,0) + 1;
			if(ind> max) max = ind ;
			if(MN[ind] < P[i].val ) MN[ind] = P[i].val;
			if(ind > indN) indN = ind;
		}
	}
	return max;
}

void Cal() {
	qsort(P,N,sizeof(ss),com);
	cout<<LIS()<<endl;
}

int main() {
	int ks, i, n;
//	freopen("c:\\h.txt","r",stdin);
	cin>>ks;
	while(ks--) {
		cin>>N;
		for(i = 0; i<N; i++) {
			cin>>n;
			if(n < 0) {
				P[i].color  = 1;
				P[i].val = -n;
			}
			else {
				P[i].color = 0;
				P[i].val = n;
			}
			MX[i] = MN[i] = -INF;
		}
		Cal();
	}
	return 0;

}
