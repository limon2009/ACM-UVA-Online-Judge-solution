#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXN 1002
int V[MAXN];
int N, MAX;


int com(const void *a, const void *b){
   return *(int *)a - *(int *)b;
}

int Search(int key, int low) {
  int mid, hi = N-1;
  mid = (low+hi) / 2;
  while(hi>low && V[mid] != key) {
       if(V[mid] > key)
		   hi = mid-1;
	   else low = mid+1;
	   mid = (low + hi) / 2;
  }
  if(V[mid] == key)
	  return mid;
  return -1;
}


void Cal() {
   int i, j, k, sum;
   int F = 0, x = 0;
   int m, n ;
   m = n = N-1;
   int p;
   MAX = -536870922 ;
   for(i = 0; i<N-2; i++) {
	   if(V[i]+V[i+1] >= V[N-1]) break;
	   for(j = i+1; j<N-1;j++){
		   if(V[i]+V[j]+V[j+1]>V[N-1]) break;
		   if(V[N-1] <0 && (V[i] + V[j] + V[j+1] <= MAX)) break;
		   for(k = j+1; k<N; k++) {
			   sum = V[i] + V[j] + V[k];
			   if(sum <0 && sum < V[0] && V[N-1] <0) break;
			   if(sum <0 && sum <= MAX && V[N-1] <0) break;
			   if(sum > V[N-1]) break;
			   if(sum <= MAX) continue;
			   p = Search(sum,0);
			   if(p != -1){
				   if(sum > MAX && V[i] != sum && V[j] != sum && V[k] != sum){
					  MAX = sum;
				      F = 1;
				      if(MAX == V[N-1]) goto done;

				   }
			   }
		   }
	   }
   }
done:;
	 if(F) printf("%d\n",MAX);
   else printf("no solution\n");

}

int main() {
	int i;
	while(scanf("%d",&N) ==1 ) {
		if(!N) break;
		for(i =  0; i<N; i++){
		   scanf("%d",&V[i]);
		}
	   qsort(V,N,sizeof(int),com);
	   Cal();
	}
	return 0;

}
