#include<stdio.h>
#include<stdlib.h>

#define MAXN 1001

int P[MAXN], M[MAXN], N;


struct ele {
   int wa;
   int iq;
   int index;
}SS[MAXN];

int com( const  void *a, const void *s) {
   ele *c = (ele *)a;
   ele *d = (ele *)s;
   return c->wa - d->wa;
}

void PrintPath(int n) {
       if(P[n] == -1) { printf("%d\n",SS[n].index); return; }
       PrintPath(P[n]);
       printf("%d\n",SS[n].index);
}

void LIS() {
    int i, j, par, start;
    int max, largest = 0;
    for(i = 1; i<N; i++) {
	par = -1;
	max = 0;
	for(j = i-1; j>=0; j--)  {
	   if(SS[i].wa>SS[j].wa && SS[i].iq<SS[j].iq) {
		if(M[j]>max) {
		   max = M[j];
		   par = j;
		}
	   }
       }
       P[i] = par;
       M[i] = max+1;
       if(M[i]>largest)  {
	  largest = M[i];
	  start = i;
       }
    }
    printf("%d\n",largest);
    PrintPath(start);
}

int main() {
   N = 1;

   SS[0].wa = SS[0].iq = 0;
   while(scanf("%d%d",&SS[N].wa,&SS[N].iq) == 2)
     N++;
   for(int i = 0; i<N; i++) SS[i].index = i;
   qsort(SS,N,sizeof(SS[0]),com);
   LIS();
	return 0;

}
