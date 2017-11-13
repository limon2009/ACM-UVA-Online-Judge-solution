#include<stdio.h>
int N,a[100];

int swap()  {
  int  i,j;
  int sw = 0;
  for(i = 0; i<N-1; i ++)
   for(j = i+1; j<N; j ++)
    if(a[i] >a[j]) sw ++;
  printf("Optimal train swapping takes %d swaps.\n",sw);
  return 0;
}



int main() {
   int i,j,kase;
   scanf("%d",&kase);
   while(kase --)  {
      scanf("%d",&N);
      for(i = 0; i<N; i ++)
	scanf("%d",&a[i]);
      swap();
   }
   return 0;
}
