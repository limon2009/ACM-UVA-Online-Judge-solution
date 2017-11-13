#include<stdio.h>
#define maxn 103

typedef long long bg;

bg Table[maxn][maxn];
bg Seq[maxn];
bool Flag[maxn][maxn];
bg N;

bg Sum(int l, int r) {
	int i, sum = 0;
	for(i = l; i<= r; i++)
		sum += Seq[i];
	return sum;
}


bg Recur(int L, int R) {
	bg max, i, d, k;
	if(L == R) return Seq[L];
	if(Flag[L][R]) return Table[L][R];
	max = Sum(L,R);
	d = Seq[L];
	for(i = L+1; i<= R; i++) {
		k = Recur(i,R);
		if((d - k) > max)
			max = d - k;
		d += Seq[i];
	}
	d = Seq[R];
	for(i = R-1; i>= L; i--) {
		k = Recur(L,i);
		if((d - k) > max)
			max = d - k;
		d += Seq[i];
	}
	Flag[L][R] = true;
	Table[L][R] = max;
	return max;
}

void Cal() {
	bg max, i, d, k;
	max = Sum(1,N);
	d = Seq[1];
	for(i = 2; i<= N; i++) {
		k = Recur(i,N);
		if((d - k) > max)
			max = d - k;
		d += Seq[i];
	}
	d = Seq[N];
	for(i = N-1; i>= 1; i--) {
		k = Recur(1,i);
		if((d - k) > max)
			max = d - k;
		d += Seq[i];
	}
	printf("%lld\n",max);
}

void Reset() {
	for(int i = 1; i<= 100; i++) {
		for(int j = 1; j<= 100; j++)
			Flag[i][j] = false;
	}
}
int main() {
	int i;
	while(scanf("%lld",&N)  && N) {
		for(i = 1; i<= N; i++) 
			scanf("%lld",&Seq[i]);
		Cal();
		Reset();
	}
	return 0;

}
