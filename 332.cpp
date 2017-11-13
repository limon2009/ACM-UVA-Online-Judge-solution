#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>



char Num[100];
int J, K, Kase;
double X;

int GCD(int a, int b) { return b? GCD(b, a%b):a;}
void Cal() {
    int gcd, num, den;
	double M, N;
	K = strlen(Num) - 2- J;
    X = atof(Num);
    M = X * pow(10, J+K) - X * pow(10,K);
    N = pow(10, J+K) - pow(10,K);
    num = (int)(ceil(M));
	den = (int)(ceil(N));
	gcd = GCD(num, den);
	num /= gcd; den /= gcd;
	printf("Case %d: %d/%d\n",Kase++,num,den);
}


void SP() {
   int i, j, k = 0, m = 1;
   char ss[50];
   for(i = 2; Num[i]; i++)
        ss[k++] = Num[i];
   ss[k] = NULL;
   for(i = 1; i<= strlen(Num) -2; i++)
	   m *= 10;
   k = atoi(ss);
   j = GCD(k,m);
   printf("Case %d: %d/%d\n",Kase++,k/j,m/j);
}
int main() {
	Kase = 1;

	while(scanf("%d",&J) == 1) {
	    if(J == -1) break;
		scanf("%s",Num);
        if(J == 0 && atof(Num) == 0.0){
			printf("Case %d: 0/1\n",Kase++);
			continue;
		}
		if(J == 0)
			SP();
		else
		Cal();
	}
	return 0;

}
