#include<stdio.h>
#include<math.h>
#include<string.h>

#define MAXN 1005


typedef long long bg;

bg limit, thole;
bg Dis[MAXN][MAXN];

struct node {
	bg dis;
	char color;
}V[MAXN];

bg Q[MAXN];
bg qh, qt;

struct pt {
	double x, y;
}P[MAXN];


double ds(double x1, double y1, double x2, double y2) {
	double x, y, z;
	x = (x1-x2); x *= x;
	y = (y1-y2); y *= y;
	z = sqrt(x+y);
	return z;
}

void GetDis() {
	int i, j, s;
	double d;
	for(i = 0; i<thole; i++) {
		for(j = i+1; j<thole; j++) {
			d = ds(P[i].x,P[i].y,P[j].x,P[j].y);
			s = (bg)(d*1000);
			Dis[i+1][j+1] = Dis[j+1][i+1] = s;
		}
	}
}

int isBlank(char str[]) {
	int i;
	for(i = 0; str[i]; i++) {
		if(str[i] == '\n') {
			str[i] = NULL;
			break;
		}
	}
	if(strlen(str) == 0) return 1;
	return 0;
}

void Ini() {
	int i;
	for(i = 1; i<=thole; i++) {
		V[i].color = 0;
		V[i].dis = 0;
	}
}

void Push(bg n) {
	Q[qh++] = n;
	qh %= MAXN;
}

bg Pop() {
	bg n;
	n = Q[qt++];
	qt %= MAXN;
	return n;
}

bg BFS() {
	bg i, p;
	qh = qt = 0;
	Push(1);
	V[1].color = 1;
	while(qh != qt) {
		p = Pop();
		for(i = 1; i<=thole; i++) {
			if(V[i].color || Dis[p][i] > limit) continue;
			if(i == 2) return V[p].dis;
			V[i].color = 1;
			V[i].dis = V[p].dis + 1;
			Push(i);
		}
	}
	return -1;
}

void Cal() {
	bg n;
	Ini();
	n = BFS();
	if(n>=0) printf("Yes, visiting %lld other holes.\n",n);
	else printf("No.\n");
}
int main() {
	char str[200];
	bg n, m;
	while(gets(str)) {
		sscanf(str,"%lld%I64d",&n,&m);
		if(!n && !m) break;
		limit = n*m*1000*60;
		thole = 0;
		gets(str);
		while(!isBlank(str)) {
			sscanf(str,"%lf%lf",&P[thole].x,&P[thole].y);
			thole++;
			gets(str);
		}
		GetDis();
		Cal();
	}
	return 0;

}
