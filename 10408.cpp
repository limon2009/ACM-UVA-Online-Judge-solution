#include<stdio.h>
#include<stdlib.h>

#define MAXN 999005

int N, K, P;
struct ss {
    int num, den;
	double frac;
}V[MAXN];

int com(const void *x, const void *y){
    ss *m = (ss *)x;
	ss *n = (ss *)y;
	if(m->frac > n->frac) return 1;
	else if(m->frac < n->frac) return -1;
	return 0;
}

int gcd(int a, int b) { return b? gcd(b,a%b):a;}

void Gen() {
   int i, j;
   double temp;
   P = 0;
   for(i = 1; i<N; i++){
	   for(j = i+1; j<=N; j++){
	       if(gcd(i,j) != 1) continue;
		   V[P].num = i;
		   V[P].den = j;
		   temp = (double)i / (double)j;
		   V[P].frac = temp;
		   P++;

	   }
   }
   V[P].num = V[P].den = 1;
   V[P].frac = 1;
   P++;
}

void Cal() {
   qsort(V,P,sizeof(V[0]),com);
   printf("%d/%d\n",V[K-1].num,V[K-1].den);
}

int main() {
	int pre = -1;
	while(scanf("%d%d",&N,&K) == 2){
	    if(N != pre) 
		 Gen();
		Cal();
		pre = N;
	}
	return 0;

}
