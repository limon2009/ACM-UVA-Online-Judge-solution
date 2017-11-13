#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 30

char STR[MAXN];



int sort_function(const void *a, const void *b) {
	return ( *(char *)a - *(char *) b);
}



void INTERCHANGE(int m,int n) {
   char c;
   c = STR[m];
   STR[m] = STR[n];
   STR[n] = c;

}





int main() {

	int i,n ,c,m,p,N,M,kase;
	scanf("%d",&kase);
	while(kase--)  {
           scanf("%s",STR);
		   n = strlen(STR) - 1;
		   qsort((void *)STR,n+1,1,sort_function);
           printf("%s\n",STR);
		   while(1) {
		      c = 0;
              for(i = n; i>=1; i --) {
				  if(STR[i] >STR[i-1]) {
					  c = 1;
					  break;
				  }
			  }
			  if(c ==0) break;
			  m = i - 1;
			  for(i = n; STR[i] <=STR[m]; i--);
			  p = i;
			  INTERCHANGE(m,p);
			  N = n;
			  M = m+1;
			  while(N > M) {
				  INTERCHANGE(N,M);
				  N--;
				  M++;
			  }
		     for(int j = 0; STR[j];j ++) printf("%c",STR[j]);
			 printf("\n");
		   }
     	
	     printf("\n");
	} 

	return 0;

}
