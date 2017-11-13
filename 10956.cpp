#include<stdio.h>
#define maxn 3000000

//typedef unsigned __int64 ss;

typedef unsigned  long long ss;

char sv[maxn+2];
ss P[6545], tp;
char Fg[100002];
ss Fail[100000];
ss N, M, B;

void Prime_table() {
	int i, j;
	for( i = 2; i*i <= maxn; ) {
		for(j =i+i; j<maxn; j+=i)
			sv[j] = 1;
		for(++i; sv[i]; i++);
	}
	tp = 1;
	P[0] = 2;
	for(i = 3; i <=65535; i += 2)
		if(sv[i] == 0) P[tp++] = i;
}


ss Mod(ss a, ss b, ss n) {
	ss t;
	if(b == 0) return 1;
	if(b == 1) return a % n;
	if( b % 2) 
		return ((a%n) * Mod(a,b-1,n)) % n;
	else {
		t = Mod(a,b/2,n) % n;
		t *= t;
		return t % n;
	}
}

int isPrime(ss key) {
	ss x, t = 0, d = key-1, i, tx;
	ss res = 2, h;
	while(d % 2 == 0) {
		t ++;
		d /= 2;
	}
	x = Mod(B,d,key);
	for(i = 0; i<t; i++) {
		tx = (x * x) % key;
		if(tx == 1 && x != 1 && x!= key-1) {
			return 0;
		}
		if(tx <= 1) break;
		x = tx;
	}
	if(tx != 1) 
		return 0;
	return 1;
}


void Cal() {
	ss i, p1, p2, st = N, non = 0, f = 0;
	if( N % 2 == 0) st++;
	for(i = st; i<= M; i += 2) {
		p1 = p2 = 0;
		if(i <= maxn) {
			if(sv[i] == 0) 
				p1 = 1;
		}
		else if(Fg[i-N] == 0) p1 = 1;
		
		if(p1 == 0){
			non ++;
			p2 = isPrime(i);
			if(p2)
				Fail[f++] = i;
		}
	}
	printf("There are %llu odd non-prime numbers between %llu and %llu.\n",non,N,M);
	if(f > 0)
		printf("%llu suspects fail in base %llu:\n",f,B);
	else printf("There are no failures in base %llu.\n",B);
	for(i = 0; i<f; i++)
		printf("%llu\n",Fail[i]);
}


int Primes(int key) {
	ss i, j;
	for(i = 2; i*i <= key; i++)
		if(key % i == 0) return 0;
	return 1;
}

void Ini() {
	ss i, j, k;
	if(maxn >= M) return;
	for(i = 1; P[i]*P[i] <= M && i<tp; i++) {
		k = N % P[i];
		if(k == 0)
			k = N;
		else
			k = N-k + P[i];
		for(j = k; j<= M; j+= P[i]) {
			Fg[j - N] = 1;
		}
	}
}

void Free() {
	ss i;
	if( maxn >= M) return;
	for(i = 0; i<= M-N; i++)
		Fg[i] = 0;
}
int main() {
	//freopen("c:\\h.txt","r",stdin);
	int k = 0;
	Prime_table();
	while(scanf("%llu%llu%llu",&B,&N,&M) == 3) {
		Ini();
		if(!B && !N && !M) break;
		if(k++) printf("\n");
		Cal();
		Free();
	}
	return 0;

}
