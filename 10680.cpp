#include<stdio.h>
#include<math.h>

#define MAXN 1000000
#define MIN(a, b) (a>b?b:a)

char seiv[MAXN+2];
int P[80000];
int tp;

struct ss {
	int three;
	int nine,  seven;
}L[MAXN];

int indL;
int Two[] = {6,2,4,8};
int Three[] = {1,3,9,7};
int Seven[] = {1,7,9,3};
int Nine[] = {1,9};
int Dig[] = {0,1,2,6,2,6,6,7,4,2,2};

int LastDigit(int n, int m) {
	int t = m%2;
	int f = m%4;
	if(m == 0) return 1;
	switch(n) {
	case 1:return 1;
	case 2:return Two[f];
	case 3:return Three[f];
	case 5:return 5;
	case 7:return Seven[f];
	case 9:return Nine[t];
	}
	return 0;
}


void Prime_table() {
	int i, j, k;
	int A[10] = {0};
	for(i = 2; i*i<=MAXN; ) {
		for(j = i+i; j<= MAXN; j+= i)
			seiv[j] = 1;
		for(i ++; seiv[i]; i++);
	}
	tp = 3;
	P[0] = 2;
	L[3].three = 1;
	L[3].nine = 0;
	L[3].seven = 0;
	L[5].three = 1;
	L[5].nine = 0;
	L[5].seven = 0;
	A[3] = 1;
	P[1] = 3;
	P[2] = 5;
	for(i = 7; i<= MAXN; i += 2){ 
		if(seiv[i]) continue;
		P[tp ++] = i;
		k = i%10;
		A[k]++;
		L[i].three = A[3];
		L[i].seven = A[7];
		L[i].nine = A[9];

	}
}


int Time(int num, int prime) {
	int times = 0, m = prime;
	while(m <= num) {
		times ++;
		m *= prime;
	}
	return times;
}


int Binary(int key) {
	int lo = 0, up = tp - 1, mid;
	mid = up / 2;
	if(key> P[tp-1]) return tp-1;
	while(P[mid] != key ) {
		if(P[mid] > key) {
			if(P[mid-1] <key) return mid-1;
			up = mid-1;
		}
		else if(P[mid]<key) {
			if(P[mid+1]>key) return mid;
			lo = mid+1;
		}
		mid = (lo + up)/2;
	}
	return mid;
}

void Gen(int n) {
	int i,  k;
	int aa[13] = {0};
	if(n<=10) {
		printf("%d\n",Dig[n]);
		return;
	}
	aa[5] += Time(n,5);
	aa[3] += Time(n,3);
	aa[2] += Time(n,2);
	k = MIN(aa[5],aa[2]);
	aa[5] -= k;
	aa[2] -= k;
	for(i = 3; P[i]*P[i] <= n; i++) {
		k = P[i] % 10;
		if(k == 1) continue;
		aa[k] += Time(n,P[i]);
	}
	while(P[i]*P[i] >n) i--;

	k = Binary(n);
	aa[9] += L[P[k]].nine - L[P[i]].nine;
	aa[3] += L[P[k]].three - L[P[i]].three;
	aa[7] += L[P[k]].seven - L[P[i]].seven;
	k = LastDigit(2,aa[2]);
	k *= LastDigit(3,aa[3]);
	k %= 10;
	k *= LastDigit(5,aa[5]);
	k*= LastDigit(7,aa[7]);
	k %= 10;
	k *= LastDigit(9,aa[9]);
	k %= 10;
	printf("%d\n",k);
}

void Cal(int n) {
	 
}

int main() {
	int n;
	Prime_table();
	while(scanf("%d",&n) && n) {
		Gen(n);
	}
	return 0;

}

