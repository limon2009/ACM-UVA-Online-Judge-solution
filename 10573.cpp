#include<stdio.h>
#include<math.h>

int N, R1, R2;
char Data[100];

void Cal_One() {
	double x,pi;
pi = 2 * acos(0);

	x = (double)R1;
	x *= x;
	if(R1 <=0) {
		printf("Impossible.\n");
		return;
	}
	printf("%.4lf\n",pi*x/8);
}

void Cal_Two() {
	double x, y, z, pi;
	double Barea, Sarea;
	pi = 2 * acos(0);
	x = pi*(double)R1*(double)R1;
	y = pi*(double)R2*(double)R2;
	Sarea = x + y;
	z = R1+R2;
	Barea = pi * z * z;
	printf("%.4lf\n",Barea-Sarea);

}

int main() {
    char input[100];
	int d;
	gets(input);
	sscanf(input,"%d",&N);
	while(N--) {
		gets(Data);
        d =  sscanf(Data,"%d%d",&R1,&R2);
		if(d == 1)
			Cal_One();
		else 
			Cal_Two();
	}
	return 0;

}
