#include<stdio.h>
#include<math.h>


#define MAXN 5002

int V[102], N, M;
int Sum1;
char fg[51][MAXN];

struct ss {
	int ind;
	int A[MAXN];
}C[52];

void Gen() {
	int i, j, k, ind, n, m, val, p;
	int g = N+M, half = Sum1/2, max = 1;
	C[1].A[0] = V[0];
	C[1].ind++;
	N = N>M?M:N;
	m = N-1;
	for(i = 1; i<g; i++) {
		n = V[i];
		for(j = max; j>=1; j--) {
			if(m-j>g-i-1) break; // may have to off
			ind = C[j].ind;
			p = j+1;
			if(p>N) continue;;
			for(k = 0; k<ind; k++) {
				val = C[j].A[k] + n;
				if(fg[p][val+100]) continue;
				fg[p][val+100] = 1;
				C[p].A[C[p].ind++] = val;
				if(p>max) max = p;
			}
		}
		if(fg[1][n+50] == 0) {
			fg[1][n+50] = 1;
			C[1].A[C[1].ind++] = n;
		}
	}
}

void Cal() {
	int i, half = Sum1/2, max = -100, min = 1000000000;
	int dis, a, m1, m2;
	Gen();
	for(i = 0; i<C[N].ind; i++) {
		a = Sum1-C[N].A[i];
		dis = abs(a - C[N].A[i]);
		if(dis>max){ max =dis; m2 = a; }
		if(dis<min){ min = dis; m1 = a; }
	}
	printf("%d %d\n",m1*(Sum1-m1),m2*(Sum1-m2));

}

void Free() {
	int i, j, k, l;
	for(i = N; i>=1; i--) {
		for(j = 0; j<C[i].ind; j++) {
			k = C[i].A[j]+100;
			l = C[i].A[j]+50;
			if(k<MAXN)
				fg[i][k] = 0;
			fg[i][l] = 0;
		}
		C[i].ind = 0;
	}
}

int main() {
	int i, n;

	while(scanf("%d%d",&N,&M) == 2) {
		Sum1 = 0;
		for(i = 0; i<N+M; i++) {
			scanf("%d",&n);
			Sum1 += n;
			V[i] = n;
		}
		Cal();
		Free();
	}
	return 0;

}

