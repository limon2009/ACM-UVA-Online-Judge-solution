#include<stdio.h>
#include<math.h>
#define MAXN 32000

char p[32000+5];
int p2[6000];
int k;

int prime_table()
{
	int i,j;
	k=2;
	for(i=2;i<=MAXN;p[i]=1,i++);
	for(i=2;i<sqrt(MAXN);)
	{
		 for(j=i+i;j<=MAXN;j+=i)
	p[j]=0;
		 for(i++;!p[i];i++);
	}
	for(i=2;i<=MAXN;i++)
	  if(p[i])
		 p2[k++]=i;

	 return 0;
}

 int digit(long n)
 {
	int d=0;
	 while(n)
	 {
		d+=n%10;
		n=n/10;
	 }
	return d;
 }





int main() {

	 int i,j,k,n,sd,d,kase;

	 prime_table();
	 scanf("%d",&kase);
	while(kase) {
	 scanf("%d", &n);
	n = n+1;
	d = digit(n);
	k = sqrt(n);
	sd = 0;
	j = n;
	while(1) {
	  n = j;
	  for(i = 2; p2[i]<=k; i++) {
		 while(n%p2[i] == 0) {
			sd += digit(p2[i]);
			n /= p2[i];
			if(n==1) break;
		 }
		if(sd > d || n == 1 )  break;
	  }

	  if(n == j) goto done;
	  if(n == 1 && sd == d) break;
	  if(n != 1)
		 sd += digit(n);
	  if(sd == d) break;
		done:;
	  j ++;
	  k = sqrt(j);
	  d = digit(j);
	  sd = 0;
	}

	printf("%d\n",j);
	 kase --;
	}
	 return 0;
}



