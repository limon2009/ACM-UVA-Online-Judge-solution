#include<stdio.h>
#define MX(a,b) (a>b?a:b)
#define MN(a,b) (a<b?a:b)
#define MAXN 342
#define MAX MAXN*MAXN

char F[MAXN][MAXN];
int  V[MAXN], min;

struct ss {
	int a, b;
}Table[MAX];

int ind, N, s1, s2, xxx;

void Gen(int n, int half, int sum) {
	int p, q, i, s, r, a, b;
	if(n>half) return;
	for(i = ind-1; i>=0; i--) {
		a = Table[i].a ;
		b = Table[i].b;
		p = a+n;
		q = b+n;
		if(p<= half) {
			if(!F[p][b]){
				F[p][b] = 1;
				F[b][p] = 1;
				Table[ind].a = p;
				Table[ind++].b = b;
				s = p + b;
				r = sum - s;
				s = MX(MX(p,b),r);
				r = MN(MN(p,b),r);
				if((s-r)<min){
					min = s-r;
				}
				if(min == xxx) return;
			}
		}
		if(q<= half) {
			if(!F[q][a]){
				F[q][a] = 1;
				F[Table[i].a][q] = 1;
				Table[ind].b = q;
				Table[ind++].a = a;
				s = q + a;
				r = sum - s;
				s = MX(MX(q,a),r);
				r = MN(MN(q,a),r);
				if((s-r)<min)
					min = s-r;
				if(min == xxx) return;
			}
		}
	}

}


void Cal(int sum) {
	int i, half;
	if(N == 1) {
		printf("%d\n",V[0]);
		return;
	}
	ind = 1;
	min = 1000;
	half = sum/2;
	xxx = 0;
	if(sum%3)
		xxx = 1;
	for(i = 0; i<N; i++){
		Gen(V[i], half, sum);
		if(min == xxx) break;
	}
	printf("%d\n",min);
	
}

void Free() {
	int i;
	for(i = 0; i<ind; i++) {
		F[Table[i].a][Table[i].b] = F[Table[i].b][Table[i].a] = 0;
	}
}

int main() {
	int kases, i, sum, c = 1;
	scanf("%d",&kases);
	while(kases--) {
		scanf("%d",&N);
		sum = 0;
		for(i = 0; i<N; i++){
			scanf("%d",&V[i]);
			sum += V[i];
		}
		printf("Case %d: ",c++);
		if(N == 2) {
			printf("%d\n",MX(V[0],V[1]));
			continue;
		}
		if(N == 3) {
			printf("%d\n",MX(V[0],MX(V[1],V[2]))-MN(V[0],MN(V[1],V[2])));
			continue;
		}
		Cal(sum);
		if(kases) Free();
	}
	return 0;

}
