#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAXN 1000000
 /* MAXN = 1000000 */

char pri[1000010];   /* array size are to increase 1000010*/


int prime_table() {
  int i,j;
  for(i = 2; i <= MAXN; i ++)  pri[i] = 1;
  for( i = 2; i<=sqrt(MAXN); ) {
    for(j = i+i; j<=MAXN; j += i)
      pri[j] = 0;
    for(i++; !pri[i]; i++);
  }
  return 0;
}

 int rev(int n) {
     char num[20],rnum[20];
     int i,l,k = 0;
     sprintf(num,"%d",n);
     l = strlen(num);
     for(i = l-1; i >=0; i--)
	rnum[k++] = num[i];
     rnum[k] = NULL;
     return atoi(rnum);
 }

  int main()
  {
      int n,e,x,p,i;
      prime_table();
      while(scanf("%d",&n) == 1) {

	p = e = 0;

	if(pri[n]) {
	  p = 1;
	  x = rev(n);
	  if((x != n) && pri[x])  e = 1;
	}

	if(p && e) printf("%d is emirp.\n",n);
	else if(p) printf("%d is prime.\n",n);
	else printf("%d is not prime.\n",n);
      }
      return 0;
  }



