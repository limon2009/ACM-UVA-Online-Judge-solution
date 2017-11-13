#include<math.h>
#include<stdio.h>

double m1, m2, m3;

void Cal() {
	double s, area, x, y;
	s = 0.5 * ( m1 + m2 + m3 );
	x = s * ( s - m1 ) * (s - m2) * ( s - m3 );
	area = (4 * sqrt(x))/3;
	if(x>0) 
		printf("%.3lf\n",area);
	else printf("-1.000\n");
}

int main() {
	while(scanf("%lf%lf%lf",&m1,&m2,&m3) == 3) {
		Cal();
	}
	return 0;

}
