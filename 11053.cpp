#include<stdio.h>
#define MAXBITS 10000000
#define USIZE (8 * sizeof(unsigned))

unsigned bitarry[MAXBITS/USIZE];
#define SETBIT(X) (bitarry[X/USIZE] != 1 << ( X % USIZE))
#define RESETBIT(X) (itarry[X/USIZE] &= ~(1 << ( X % USIZE))
#define GETBIT(X) ((bitarry[X/U] & ( 1<<(X%USIZE))) ? 1 : 0)


//typedef __int64 ss;
typedef long long ss;



struct xx {
	int a, b;
};

xx H[1000][1000];
int Ind[1000];

ss N, A, B;

int Find(int h, int key) {
	int i;
	for(i = 0; i<Ind[h]; i++) {
		if(H[h][i].a == key) return H[h][i].b;
	}
	return -1;
}

int Cal() {
	ss next = 0, len = 1, d, t;
	xx temp;
	temp.a = 0;
	temp.b = 1;
	H[0][0] =  temp;
	Ind[0] = 1;
	while(1) {
		t = next % N;
		t *= t;		t %= N;
		t *= A;		t %= N;
		next = (t + B) % N;
		d = Find(next % 1000, next);
		if(d >= 0){
			if(d == 1) return len - d + 2;
			return len - d + 1;
		}
		
		d = next % 1000;
		temp.a = next;
		temp.b = len ++;
		H[d][Ind[d]++] = temp;
	}
	return 0;
}

int main() {
//	freopen("c:\\11053.in","r",stdin);
//	freopen("c:\\out.ans","w",stdout);
	while(scanf("%lld",&N) && N) {
		scanf("%lld%lld",&A,&B);
		printf("%d\n",N - Cal() + 1);
		for(int i = 0; i<1000; i++) {
			Ind[i] = 0;
		}
	}
	return 0;

}
