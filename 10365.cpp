#include<stdio.h>

int N;

void Cal() {
	int i, j, k, m, area;
	int min = 2147483647;
	if(!N) {
		printf("0\n");
		return;
	}
	for(i = 1; i<= N; i++) {
		for(j = i; ; j++) {
			m = i*j;
			if(m > N) break;
			k = N % m;
			if(k == 0)  {
				k = N/m;
				area = 2*i*j + 2*j*k + 2*i*k;
				if(area<min) min = area;
			}
		}
	}
	printf("%d\n",min);
}
int main() {
	int ks;
	scanf("%d",&ks);
	while(ks--) {
		scanf("%d",&N);
		Cal();
	}
	return 0;

}
