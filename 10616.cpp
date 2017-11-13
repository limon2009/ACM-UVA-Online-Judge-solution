#include<stdio.h>
#include<stdlib.h>

//typedef __int64 SS;
typedef long long SS;

struct ss {
	int A[202];
	int ind;
};

ss B[25];
int N, Q;

int Num[201];
char F[22];

int Fg[20][205][42];
SS C[12][205][42], Res;

int com(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

void Setting(int d) {
	int i, r;
	for(i = 0; i<N; i++) {
		r = Num[i] % d;
		r += (d-1);
		B[d].A[B[d].ind++] = r;
	}
}

SS Recur(int ind, int level, int sum, int dev, int m) {
	SS i, k = 0, d, p;
	if(level == m) {
		if(sum == 0)
			return 1;
		return 0;
	}
	p = sum + dev - 1;
	if(Fg[level][ind][p] ) return C[level][ind][p];
	for(i = ind + 1; i<N; i++) {
		d = Num[i] % dev;
		d = ( d + sum) % dev;
		k += Recur(i,level+1,d,dev,m);
	}
	Fg[level][ind][p] = 1;
	C[level][ind][p] = k;
	return k;
}

SS Count(int d, int m) {
	SS c = 0, i, k, j;
	Res = 0;
	if(d == 1 && m == 1) return N;
	for(i = 0; i<N; i++) {
		k = Num[i] % d;
		Res += Recur(i,1,k,d,m);
	}
	return Res;
}

void Free(SS d, SS m) {
	SS i, j, k, l = d*2;
	for(i = 1; i<= m; i++) {
		for(j = 0; j<= N; j++) {
			for(k = 0; k<=l; k++)
				Fg[i][j][k] = 0;
		}
	}

}

void Cal() {
	SS d, m, c, st = 1;
	while(Q--) {
		scanf("%lld%lld",&d,&m);
		c = Count(d, m);
		printf("QUERY %lld: %lld\n",st++,c);
		Free(d,m);
	}
}

int main() {
	int st = 1;
//	freopen("c:\\h.txt","r",stdin);
//	freopen("c:\\out.txt","w",stdout);
	while(scanf("%d%d",&N,&Q) == 2) {
		if(!N && !Q) break;
		for(int i = 0; i<N; i++) {
			scanf("%d",&Num[i]);
		}
		printf("SET %d:\n",st++);
		Cal();
	}
	return 0;

}
