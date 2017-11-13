#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

#define maxn 18

struct ss {
	int x;
	int y;
}P[maxn];

struct xx {
	double dis;
	int x, y;
};

xx D[maxn*maxn];

int N, totalp;
char Fg[maxn*maxn];
double Rec, MIN;

int com(const void *a, const void *b) {
	xx *m = (xx *)a;
	xx *n = (xx *)b;
	if(m->dis > n->dis) return 1;
	return -1;
}

double Distence(int x1, int y1, int x2, int y2) {
	int a, b;
	a = (x1 - x2) * (x1 - x2);
	b = (y1 - y2) * (y1 - y2);
	a += b;
	return sqrt((double)a);
}

void Set() {
	int i, j;
	double d;
	totalp = 0;
	for( i = 0; i<2*N; i++) {
		for(j = i+1; j<2*N; j++) {
		   d = Distence(P[i].x,P[i].y,P[j].x,P[j].y);
		   D[totalp].x = i;
		   D[totalp].y = j;
		   D[totalp++].dis = d;
		}
	}
}


int A[20];


void Recur(int n, int level, double cost ) {
	int i, rem, c = 0;
	double b = 0,guess = 0;
	if(cost >= MIN) return;
	if(level == N) {
		MIN = cost;
		return;
	}
	Fg[D[n].x] = 1;
	Fg[D[n].y] = 1;
	rem = N - level;
	for(i = n+1; i < totalp; i++){
		if(Fg[D[i].x] || Fg[D[i].y]) continue;
		guess += D[i].dis;
		c++;
		if(c == rem) break;
	}

	if(cost + guess >= MIN || c < rem) {
		Fg[D[n].x] = 0;
		Fg[D[n].y] = 0;
		return;
	}
	for(i = n+1; i<totalp; i++) {
		if(Fg[D[i].x] || Fg[D[i].y])continue;
		Recur(i,level+1,cost + D[i].dis);
	}
	Fg[D[n].x] = 0;
	Fg[D[n].y] = 0;
}

void Cal() {
	int i;
	Set();
	qsort(D,totalp,sizeof(xx),com);
	MIN = 2147483646;
	for(i = 0; i<totalp; i++) {
		Recur(i,1,D[i].dis);
	}
	printf("%.2lf\n",MIN);
}

int main() {
	int i, k = 1;
	char nam[100];
	//freopen("h.txt","r",stdin);
	while(cin>> N && N) {
		for(i = 0; i<2*N; i++ ) {
			cin>>nam>>P[i].x>>P[i].y;
		}
		printf("Case %d: ",k++);
		Cal();
	}
	return 0;

}
