#include<stdio.h>
#include<math.h>

double gx, gy, dx, dy;

double dis(double x, double y, double p, double q) {
	double dis, a, b;
	a = (x - p) * (x - p);
	b = (y - q) * (y - q);
	dis = sqrt(a+b);
	return dis;
}

int main() {
	int n, f;
//	freopen("c:\\h.txt","r",stdin);
	double rx, ry, x, y, disg, disd;
	while(scanf("%d",&n) == 1) {
		f = 0;
		scanf("%lf%lf%lf%lf",&gx,&gy,&dx,&dy);
		while(n--) {
			scanf("%lf%lf",&x,&y);
			if(f) continue;
			disg = dis(gx,gy,x,y);
			disd = dis(dx,dy,x,y);
			disd /= 2;
			if(disg<=disd) {
				rx = x;
				ry = y;
				f = 1;
			}
		}
		if(!f) printf("The gopher cannot escape.\n");
		else {
			printf("The gopher can escape ");
			printf("through the hole at (%.3lf,%.3lf).\n",rx,ry);
		}
	}
	return 0;

}
