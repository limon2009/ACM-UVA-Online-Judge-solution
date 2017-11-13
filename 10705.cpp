#include<stdio.h>
#include<math.h>
#include<string.h>

typedef long long ss;

ss V[65], max, min, N, K;
ss MX[65], MN[65];

char Sg[70];

void Ini() {
	int i;
	ss d = 1, x = 0;
	for(i = 1; i<64; i++) {
		V[i] = d;
		d *= 2;
	}
}
int A[70];

void Print(int n) {
	int i, j;
	for(i = 0; i<= n; i++)
		printf("%d",A[i]);
	for(j = i+1; j<=K; j++) printf("0");
	printf("\n");
}

int recur(int level, ss n, ss sum, ss limit, int ind, int sg) {
	A[level] = sg;
	if(sum == N) {
		Print(level);
		return 1;
	}
	if(n == limit) {
		return 0;
	}
	if(sum > N) if(MN[n-1] + sum > N) return 0;
	if(sum < N) if(MX[n-1] + sum < N) return 0;
	if(Sg[ind] == 'n'){
		if(recur(level+1,n-1,sum-V[n-1],limit,ind+1,1)) return 1;
	}
	else if(Sg[ind] == 'p')
		if(recur(level+1,n-1,sum+V[n-1],limit,ind+1,1)) return 1;
	if(recur(level+1,n-1,sum,limit,ind+1,0)) return 1;
	return 0;
}

void GetmaxMin(ss t) {
	max = min = 0;
	ss st = K-1, i;
	if(t == 2) st --;
	for(i = t; i<=  K; i++) {
		if(Sg[st--] =='n') 
			min -= V[i];
		else
			max += V[i];
		MX[i] = max;
		MN[i] = min;
	}
}

void Cal() {
	ss t = 1, k = V[K];
	if(N%2 == 0)
		t = 2;
	GetmaxMin(t);
	if(Sg[0] == 'n') k = -V[K];
	if(N > max || N<min) {
		printf("Impossible\n");
		return;
	}
	if(recur(0,K,k,t,1,1)) return;
	if(recur(0,K,0,t,1,0)) return;
	printf("Impossible\n");
}
int main() {
	Ini();
	int k;
	//freopen("c:\\key.txt","r",stdin);
	scanf("%d",&k);
	while(k--) {
		scanf("%lld",&K);
		scanf("%s",Sg);
		scanf("%lld",&N);
		Cal();
	}
	return 0;

}
