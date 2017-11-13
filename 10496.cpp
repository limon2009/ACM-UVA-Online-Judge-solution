#include<stdio.h>
#include<math.h>

int R, C;
int N;
int Link[31][31];
int MIN, A[15];
char F[100];

struct pp {
	int r;
	int c;
}pt[12];

void Dis() {
	int i, j, dis;
	for(i = 0; i< N; i++) {
		for(j = i+1; j<=N; j++) {
			dis = abs(pt[i].r - pt[j].r) + abs(pt[i].c - pt[j].c);
			Link[i][j] = Link[j][i] = dis;
		}
	}
}

void Recur(int n, int dis, int level) {
	if(dis >= MIN) return;
	A[level] = n;
	if(level == N) {
		dis = dis + Link[n][0];
		if(dis < MIN)
			MIN = dis;
		return;
	}
	F[n] = 1;
	for(int i = 0; i<=N; i++) {
		if(F[i] == 0) {
			Recur(i,dis+Link[n][i],level+1);
		}
	}
	F[n] = 0;
}


void Cal() {
	MIN = 1000000;
	Recur(0,0,0);
	printf("The shortest path has length %d\n",MIN);
}

void Free() {
	int i;
	for(i = 0; i<= N; i++)
		F[i] = 0;
}

int main() {
	int kase, i;
	//freopen("z:\\h.txt","r",stdin);
	scanf("%d",&kase);
	while(kase--) {
		scanf("%d%d",&R,&C);
		scanf("%d%d",&pt[0].r,&pt[0].c);
		scanf("%d",&N);
		for(i = 0; i<N; i++)
			scanf("%d%d",&pt[i+1].r,&pt[i+1].c);
		Dis();
		Cal();
		if(kase) Free();
	}

	return 0;

}
