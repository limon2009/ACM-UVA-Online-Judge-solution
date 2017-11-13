#include<stdio.h>

using namespace std;
typedef long long ss;

ss D[] = {0,1,10,100,1000,10000,100000,1000000,10000000};
ss Digit[15], td;

void Set(ss n) {
	td = 0;
	while(n) {
		Digit[td++] = n%10;
		n /= 10;
	}
}

ss Sum(ss n) {
	ss set = 0, m, count = 0, i, j;
	if(n < 0) return 0;
	if(n <= 1) return n;
	m = n % 10;
	for( i = 1; i<= m; i++)
		count += i;
	m = n/10;
	set += m;
	Set(n);
	for(i = td - 1; i >= 1; i--) {
		for(j = i-1; j>= 1; j--)
			set += Digit[i]*D[j];
		for(j = 1; j<= Digit[i]; j++)
			count += j;
	}
	set = set * 45 + count;
	return set;
}


int main() {
	ss p, q, x, y;
	while(scanf("%lld%lld",&p,&q) == 2) {
		if(p < 0 && q < 0) break;
		printf("%lld\n",Sum(q) - Sum(p-1));
	}
	return 0;

}
