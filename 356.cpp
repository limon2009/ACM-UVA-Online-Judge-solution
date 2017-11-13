#include<stdio.h>
#include<math.h>

int N, seg;
double  part;

double Val(double k) {
	double xx, r;
	r = double(N) - .5;
	xx = 4*floor(sqrt(r*r - k*k));
	return xx;
}

int Cal() {
    int i;
	part = 0;
	for(i = 1; i<N; i++) {
		part += Val((double)i);
	}
    printf("In the case n = %d, %d cells contain segments of the circle.\n",N,seg);
	printf("There are %.lf cells completely contained in the circle.\n",part);


	return 0;
}

int main() {
	int f= 0;
	while(scanf("%d",&N) == 1) {
		if(f++) putchar('\n');
		seg = 8*N - 4;
		Cal();
		
	}
	return 0;
    
}
