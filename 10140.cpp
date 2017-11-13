#include<stdio.h>
#include<math.h>

#define MAX 1000000
#define MAXN 46350
    /*46350*/

char PR[MAXN+5];
int TEMP[MAX+5];
int P[10000];
int K,D;

void Prime_table()  {
  int i, j;
  K = 0;
  for(i = 2; i<= MAXN; i ++)  PR[i] = 1;
  for(i = 2; i<= sqrt(MAXN);)  {
    for(j = i*2; j<= MAXN; j += i)
	PR[j] = 0;
    for(++i; !PR[i]; i ++);
  }
  for(i = 0; i<= MAXN; i ++)
   if(PR[i])
     P[K++] = i;
}

void COM(int ST,int EN)  {
   unsigned i, j, k, n;
   if(ST == 1) ST = 2;
   D = ST - 1;
   for(i = ST;i<=EN; i ++)
     TEMP[i-D] = 1;
   for(i = 0; i<= sqrt(EN) && i<K; i ++)  {
	 if(P[i] >= ST)
	    k = P[i]*2;

	  else {
	    n = (ST /P[i]) * P[i];
	    if(n>=ST)
	      k = n;
	    else
	      k = ((ST/ P[i])  + 1) * P[i];
	  }

	 for(j = k; j<= EN; j+=P[i])
	   TEMP[j-D] = 0;
   }

}

int  CLOSET(int m,int n)  {

	unsigned i, MIN = 10000;
	int f, F, S, C = 0, d;
	if(m<=2 && n>=3) {
	   printf("2,3 are closest,");
	   return 1;
	}
	if(m<=1 && n<= 1) return 0;
	if(m<=1) m = 2;
	for(i = m; i<=n; i ++)
	  if(TEMP[i-D]) {
	    f = i;
	    break;
	  }
	for(i = f+1;i<=n; i ++) {
	  if(TEMP[i-D]) {
	    d = i - f;
	    C = 1;
	    if(d<MIN)  {
	      F = f;
	      S = i;
	      MIN = d;
	    }
	    f = i;
	  }
	}
	if(C ==0) return 0;
	printf("%d,%d are closest,",F,S);
	return 1;

}
int  DISTANT(int m,int n)  {

	unsigned i, MIN = 0;
	int f, F, S, C = 0, d;
	if(m<=1 && n<= 1) return 0;
	if(m<=1) m = 2;
	for(i = m; i<=n; i ++)
	  if(TEMP[i-D]) {
	    f = i;
	    break;
	  }
	for(i = f+1;i<=n; i ++) {
	  if(TEMP[i-D]) {
	    d = i - f;
	    C = 1;
	    if(d>MIN)  {
	      F = f;
	      S = i;
	      MIN = d;
	    }
	    f = i;
	  }
	}
	if(C == 0) return 0;
	printf(" %d,%d are most distant.\n",F,S);
	return 1;

}


int main() {
  int n, m, p ,q;
  Prime_table();
  while(scanf("%d%d",&n,&m) == 2)  {
    COM(n, m);
    p = CLOSET(n,m);
    q = DISTANT(n,m);
    if(! p && !q) printf("There are no adjacent primes.\n");
  }
	return 0;

}
