#include<stdio.h>
#include<math.h>


#define MAXN  1000000

char pp[MAXN+2];
int PD[MAXN];

void Prime_table() {
	int i, j;
	for(i = 2; i<= MAXN; i++) pp[i] = 1;
	for(i = 2; i<=sqrt(MAXN); ) {
		for(j = i+i; j<=MAXN; j+=i) 
			pp[j] = 0;
		for(i++; !pp[i]; i++);
	}
}


int Digit(int n) {
	int sum= 0;
	while(n) {
		sum+= n % 10;
		n /= 10;
	}
	return sum;
}

void Gen() {
	int k = 0;
	int i,n;
	for(i = 2; i<= MAXN; i++ ) {
		if(pp[i]) {
			n = Digit(i);
			if(pp[n])
				k++;
		}
	    PD[i] = k;
	}
}


int main() {
	int n ,kase, m;
	Prime_table();
	Gen();
	scanf("%d",&kase);
	while(kase --)  {
          scanf("%d%d",&n,&m);
		  printf("%d\n",PD[m] - PD[n-1]);
	}	
	return 0;

}
