#include<stdio.h>

int N, M;

void Cal() {
	int a, b, c;
	if(!M) {
		printf("0\n");
		return;
	}
	a = (N/2)+1;
	b = (M+1)/2;
	b *= b;
	c = (a-1)*(a-1);
	printf("%d\n",b-c);
}
int main() {
	int ks, k = 1;
	scanf("%d",&ks);
	while(ks--) {
		scanf("%d%d",&N,&M);
		printf("Case %d: ",k++);
		Cal();
	}
	return 0;

}

