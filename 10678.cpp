#include<stdio.h>
#include<math.h>

double D, L;

int main() {
	int kase;
	double a, b, pi = 3.1415926535897932384626433832795;
	scanf("%d",&kase);
	while(kase--) {
		scanf("%lf%lf",&D,&L);
		a = L/2;
		b = sqrt((L/2)*(L/2) - (D/2)*(D/2));
		printf("%.3lf\n",a*b*pi);
	}
	return 0;

}
