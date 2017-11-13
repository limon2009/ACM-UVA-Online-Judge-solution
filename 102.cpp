#include<stdio.h>

int Bin[4][4];
int MIN;
char gla[] = "BCG";
char G[5];


void Cal(int a, int b, int c) {
    int x = 0;
	x += Bin[1][a] + Bin[2][a];
	x += Bin[0][b] + Bin[2][b];
	x += Bin[0][c] + Bin[1][c];
	if(x < MIN){
		 MIN = x;
	     G[0] = gla[a];	 
		 G[1] = gla[b];
		 G[2] = gla[c];
	     G[3] = NULL;
	}

}

int main() {
    int a,b,c,d,e,f,g,h,i;
	while(scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i) == 9) {
	   Bin[0][0] = a; Bin[0][2] = b; Bin[0][1] = c;
       Bin[1][0] = d; Bin[1][2] = e; Bin[1][1] = f;
	   Bin[2][0] = g; Bin[2][2] = h; Bin[2][1] = i;
	   MIN = 2147483647;
	   Cal(0,1,2);
	   Cal(0,2,1);
	   Cal(1,0,2);
	   Cal(1,2,0);
	   Cal(2,0,1);
	   Cal(2,1,0);
	   printf("%s %d\n",G,MIN);
	}
	return 0;
}
