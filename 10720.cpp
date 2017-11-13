#include<stdio.h>
#include<stdlib.h>

#define MAXN 10002

int Seq[MAXN];
int Sum[MAXN];
int N, Fg;

int com(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

int Bsearch(int lo, int up, int key) {
	int mid = (lo + up)/2;
	while(lo != up) {
		if(Seq[mid] > key) {
			if(Seq[mid+1] < key) return mid;
			lo = mid+1;
		}
		if(Seq[mid] < key) {
			if(Seq[mid-1] >= key) return mid-1;
			up = mid-1;
		}
		if(Seq[mid] == key) {
			lo = mid + 1;
		}
		mid = (lo + up)/2;
	}
	return lo;
}
int Cal() {
	int i, r, sum, k;
	Sum[N+1] = 0;
	if(Sum[N] % 2 || Fg) return 0;
	if(N == 1 && Sum[N] > 0) return 0;
	for(r = 1; r<N; r++) {
		if(r > Seq[r+1]) sum = Sum[N] - Sum[r];
		else if(r <= Seq[N]) sum = (N - r) * r;
		else {
		//	for(i = N; i>r && Seq[i]<r; i--);
			i = Bsearch(r+1,N,r);
			sum = Sum[N] - Sum[i];
			sum += (i - r ) * r;
		}
		sum += r * (r-1);
		if(Sum[r] > sum) return 0;
	}
	return 1;
}

void Set() {
	int i;
	qsort(&Seq[1],N,sizeof(int),com);
	Sum[1] = Seq[1];
	for(i = 2; i<= N; i++) {
		Sum[i] = Sum[i-1] + Seq[i];
	}
}
int main() {
	int i;
	//freopen("c:\\h.txt","r",stdin);
	while(1 == scanf("%d",&N) && N) {
		Fg = 0;
		for(i = 1; i<= N; i++) {
			scanf("%d",&Seq[i]);
			if(Seq[i] < 0)
				Fg = 1;
		}
		if(Fg) {
			printf("Not possible\n");
			continue;
		}
		Set();
		if(Cal()) printf("Possible\n");
		else printf("Not possible\n");
	}
	return 0;

}
