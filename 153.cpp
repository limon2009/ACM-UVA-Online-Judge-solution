#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

#define maxn 31

int P[] = {2,3,5,7,11,13,17,19,23,29};
int F[maxn][maxn];
int N[maxn], D[maxn];
int Len;

char ss[maxn];

void Pre() {
	int i, j, k;
	for(i = 2; i<maxn; i++) {
		for(j = 0; j<10; j++) {
			for(k = P[j]; k<= i; k*= P[j])
				F[i][j] += i/k;
		}
	}
}


int SS(int a[], int ind, int n) {
	int i, j, d;
	if(n == 1) return 1;

	for(i = 0; i<10; i++) N[i] = 0;
	
	for(i = 0; i<10; i++) {
		if(P[i] > n) break;
		N[i] = F[n][i];
	}
	for(i = 0; i<ind; i++) {
		for(j = 0; j<10; j++) {
			if(a[i] < P[j]) break;
			d = a[i];
			N[j] -= F[d][j];
		}
	}
	d = 1;
	for(i = 0; i<10; i++) {
		if(N[i])
			d *= pow(P[i] , N[i]);
	}
	return d;
}


int Count(int ind) {
	int i, j, k, d = 0, l, m = 0;
	int count = 0;

	int a[maxn] = {0};
	int b[maxn], c[maxn];
	l = ss[ind] - 'a';
	for(i = ind; i<Len; i++) {
		k = ss[i] - 'a';
		a[k]++;
		m++;
	}
	for(i = 0; i<26; i++){
		if(a[i]) 
			b[d++] = i;
	}

	for(i = 0; i<d; i++) {
		k = b[i];
		if(k >= l) break;
		for(j = 0; j<d; j++){
			if(i == j)
				c[j] = a[b[j]] - 1;
			else c[j] = a[b[j]];
		}
		count += SS(c,d,m-1);
	}
	return count;
}
void Cal() {
	int c = 1, i;
	Len = strlen(ss);
	if(Len == 1) {
		printf("%10d\n",1);
		return;
	}
	for(i = 0; i+1<Len; i++)
		c += Count(i);
	printf("%10d\n",c);
}

void main() {
	Pre();
	while(cin>>ss) {
		if(ss[0] =='#') break;
		Cal();
	}
}
