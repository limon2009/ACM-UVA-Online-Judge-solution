#include<stdio.h>
#include<math.h>

double a, b, c, s, r;

int main() {

	while(scanf("%lf%lf%lf",&a,&b,&c) == 3) {
		if(a == 0 || b == 0 || c == 0) {
			printf("The radius of the round table is: 0.000\n");
			continue;
		}
		s = (a+b+c)/2;
		r = ((s-a)*(s-b)*(s-c)/s);
		printf("The radius of the round table is: %.3lf\n",sqrt(r));
	}
	return 0;

}
