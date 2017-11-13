#include<stdio.h>
#define MAXN 46345

typedef long long  ss;

ss A[MAXN];

void GEN() {
  ss sum;
  ss  i;
  A[0] = 0;
  for(i = 1; i<=46341; i++) {
      sum = (i * (i+1));
	  A[i] = sum;
	  
  }
}

int Search(int key) {
   int lo = 0, up = 46341, mid;
   int dif;
   mid = (lo + up) / 2;
   dif = key - A[mid];
   while(lo <= up && dif != mid) {
       if(dif>0){
	       if((key - A[mid+1])<=0) return mid; 
		   lo = mid+1;
	   }
	   else  up = mid-1;
	   mid= (lo + up) / 2;
	   dif = key - A[mid];
	   	   
   }
  // if( dif == mid) return mid-1;
   return mid;
}

/*
int Search(int key) {
   int i;
   ss dif;
   for(i = 0; 1; i++) {
      if((key - A[i])<=0) break;
   }
   return i-1;
}
*/
void Cal(int n, int m ) {
   int diff, p;
   p = Search(m-n);
   diff = m - n - A[p];
   if(p+1>=diff) printf("%d\n",p*2+1);
   else printf("%d\n",p*2+2);
}

int main() {
	int kase, n, m;
              GEN();
	scanf("%d",&kase);
	while(kase--) {
		scanf("%d%d",&n,&m);
		if(m == n) { printf("0\n"); continue; }
		Cal(n,m);
	}
	return 0;

}
