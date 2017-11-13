#include<stdio.h> 
#include<math.h>

typedef long long bbig;

struct ss {
	bbig x, y;
}P, Q;

bbig Mid(bbig low, bbig up ) {
	bbig a, diff, c;
	if(low> up) return 0;
	diff = up - low + 1;
	c = low + up;
	a = diff * c;
	return a/2;
}

void Cal() {
	bbig line1, line2, diff, mid, dis;
	line1 = P.x+P.y;
	line2 = Q.x+Q.y;
	if(line1 == line2) {
		printf("%.lf\n",fabs(P.x - Q.x));
		return;
	}
	mid = Mid(line1+2,line2);
	diff = line1 - P.x;
	dis = diff + Q.x + mid;
	printf("%lld\n",dis+1);
}

int main(){
	int kase, f = 1;

	scanf("%d",&kase);
	while(kase--) {
		scanf("%lld%lld%lld%lld",&P.x,&P.y,&Q.x,&Q.y);
		printf("Case %d: ",f++);
		if(P.x == Q.x && P.y == Q.y) {
			printf("0\n");
			continue;
		}
		Cal();
	}
	return 0;

}
