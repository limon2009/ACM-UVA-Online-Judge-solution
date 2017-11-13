#include<stdio.h>
#define max 30000
//typedef __int64 ss;	// vc++
typedef long long ss;

int D[] = { 10000, 5000, 2000, 1000, 500 ,200, 100, 50, 20,10,5 };
ss T[max+2];

void Dynamic() {
	int i, j;
	T[0] = 1;
	for(i = 0; i<11; i++) {
		for(j = D[i]; j<= max; j++) {
			T[j] += T[j-D[i]];
		}
	}
}
int main() {
	double x;
	int d;
	Dynamic();
	while(scanf("%lf",&x) == 1) {
		d = (int)(x*100 + 1E-5);
		if(d == 0) break;
		//printf("%6.2lf%17I64d\n",x,T[d]); // visual c++
		printf("%6.2lf%17lld\n",x,T[d]);	
	}
	return 0;

}


