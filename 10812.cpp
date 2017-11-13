#include<stdio.h>

typedef int ss;

void Cal(ss n, ss m, ss sum) {
	if(n <= m) {
		printf("impossible\n");
		return;
	}
	if(sum % 2) {
		printf("impossible\n");
		return;
	}
	printf("%d %d\n",sum/2, n - sum/2);
}

int main() {
	ss n, m, k;
	scanf("%d",&k);
	while(k--) {
		scanf("%d%d",&n,&m);
		if(!n && !m) {
			printf("0 0\n");
			continue;
		}
		Cal(n,m,n+m);
	}
	return 0;

}

