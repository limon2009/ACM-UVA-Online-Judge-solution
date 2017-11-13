#include<stdio.h>
#include<math.h>

#define MAX(a, b) (a>b?a:b)

typedef long long ss;

ss A[40], B[40];

ss ind1, ind2, N, L, U, all;

void Binary(ss n, ss a[], ss &ind) {		// OK
	ind = 0;
	all = 1;
	while(n) {
		a[ind++] = n%2;
		if(a[ind-1] == 0) all = 0;
		n /= 2;
	}
}

void Rev(ss a[], ss n) {		// OK
	ss temp[40], i, j = 0;
	for(i = n-1; i>=0; i--)
		temp[j++] = a[i];
	for(i = 0; i<n; i++)
		a[i+1]  = temp[i];
}

int Recur(ss limit, ss level, ss sum) {
	ss x, y, z;
	x = limit - level + 1;
	y = (ss)pow(2,(double)x) - 1;
	if(sum > U) return 0;
	if(sum + y < L) return 0;
	if(level == limit+1 && sum <= U) {
		printf("%lld\n",sum);
		return 1;
	}
	if(A[level] == 0) {
		z = sum + (ss)pow(2,double(limit-level));
		if(Recur(limit,level+1,z)) return 1;
		if(Recur(limit,level+1,sum)) return 1;
	}
	if(A[level] == 1) {
		if(Recur(limit,level+1,sum)) return 1;
		z = sum + (ss)(pow(2,(double)(limit-level)));
		if(Recur(limit,level+1,z)) return 1;

	}
	return 0;
}

void Cal() {
	ss max;
	if(U == L) {	// OK
		printf("%lld\n",L);
		return;
	}
	for(max = 0; max<35; max++) A[max] = 0;
	Binary(N,A,ind1);
	if(all && N>= U) {	// OK
		printf("%lld\n",L);
		return;
	}
	Binary(U,B,ind2);
	max = MAX(ind1, ind2);
	Rev(A,max);
	Recur(max,1,0);
}

int main() {
//	freopen("c:\\h.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);
	while(scanf("%lld%lld%lld",&N,&L,&U) == 3) 
		Cal();
	return 0;

}
