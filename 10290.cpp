#include<stdio.h>
#include<math.h>

#define MAXN 30000000

typedef long long qq;

char ss[MAXN+2];
qq N;

int Prime_table() {
	qq i, j;
	for(i = 2; i*i<=MAXN;) {
		for(j = i+i; j<= MAXN; j+= i)
			ss[j] = 1;
		for(++i;ss[i] & i<= MAXN; i++);
	}
	return 0;
}


int Count(qq p) {
    int c = 0;
	while(N % p == 0) {
	   c++;
	   N /= p;
	}
	return c+1;
}

int Cal() {
	qq i;
	qq d, s = 1;
	qq temp = N;
	while(N % 2==0) 
		N /= 2;
	if(N == 1) { printf("0\n"); return 0; }
	for(i = 3; i*i<= temp; i+=2) {
		if(ss[i] == 1) continue;
	    d = Count(i);  
		s *= d;
		if(N == 1) break;
	}
	if(N != 1) s *= 2;
	printf("%lld\n",s);
	return 0;
}

int main() {
	Prime_table();
	while(scanf("%lld",&N)== 1) {
		Cal();
	}
	return 0;
}
