#include<stdio.h>
#define MAXN 10000

int A[MAXN], B[MAXN];
int inda, indb;

int Largest(int i, int n) {
	int l, r, largest;
	l = i*2;
	r = l+1;
	if(l<=n && A[l] > A[i])
		largest = l;
	else
		largest = i;
	if(r<= n && A[r] > A[largest])
		largest = r;
	return largest;
}

int Smallest(int i, int n) {
	int l, r, smallest;
	l = i*2;
	r = l+1;
	if(l<=n && B[l] < B[i])
		smallest = l;
	else
		smallest = i;
	if(r<= n && B[r] < B[smallest])
		smallest = r;
	return smallest;
}

void MAX_HEAP(int n, int i) {
	int larg, temp;
	larg = Largest(i, n);
	while(larg != i) {
		temp = A[i];
		A[i] = A[larg];
		A[larg] = temp;
		i = larg;
		larg = Largest(i,n);
	}
}

void MIN_HEAP(int n, int i) {
	int Small, temp;
	Small = Smallest(i, n);
	while(Small != i) {
		temp = B[i];
		B[i] = B[Small];
		B[Small] = temp;
		i = Small;
		Small = Smallest(i,n);
	}
}

void InsertA(int key, int i) {
	int par = i/2, temp;
	A[i] = key;
	while(i>1 && A[par]<A[i]) {
		temp = A[par];
		A[par] = A[i];
		A[i] = temp;
		i = par;
		par = i/2;
	}
}

void InsertB(int key, int i) {
	int par = i/2, temp;
	B[i] = key;
	while(i>1 && B[par]>B[i]) {
		temp = B[par];
		B[par] = B[i];
		B[i] = temp;
		i = par;
		par = i/2;
	}
}

void Cal(int n) {
	//long
	long long p;
	if(inda == indb) {
		if(A[1]>n) {
			InsertB(A[1],indb+1);
			A[1] = n;
			MAX_HEAP(inda,1);
			
		}
		else
			InsertB(n,indb+1);
		indb++;
	}
	else {
		if(B[1]<n) {
			InsertA(B[1],inda+1);
			B[1] = n;
			MIN_HEAP(indb,1);
			
		}
		else
			InsertA(n,inda+1);
		inda++;
	}
	p = A[1] + B[1];
	if(inda != indb) printf("%d\n",B[1]);
	else
		printf("%lld\n",p/2);
}

int main() {
	int n;
	inda = indb = 0;
	while(scanf("%d",&n) == 1) {
		Cal(n);
	}
	return 0;

}
