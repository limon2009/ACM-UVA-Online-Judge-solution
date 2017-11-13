#include<stdio.h>
#define MAX 15000000000000000
#define CON 547213610

typedef long long ss;

ss N;

ss Search(ss key) {
	ss lo = 3, up = CON, x, y, z;
	ss mid = (lo + up)/2;
	x = (mid*(mid+1))/2 - 1;
	while(x != key) {
		if(x>key) {
			y = mid - 1;
			z = (y*(y+1))/2 - 1;
			if(z<key) return mid+2;
			if(z== key) return y+2;
			up = mid-1;
		}
		if(x < key) {
			y = mid+1;
			z = (y*(y+1))/2 - 1;
			if(z>=key) return y+2;
			lo = mid+1;
		}
		mid = (lo+up)/2;
		x = (mid*(mid+1))/2 - 1;
	}
	return mid+2;
}

int main() {
	ss k = 1;
	while(scanf("%lld",&N) && N) {
		printf("Case %lld: ",k++);
		if(N<=2) {
			printf("4\n");
			continue;
		}
		printf("%lld\n",Search(N));
	}
	return 0;

}
