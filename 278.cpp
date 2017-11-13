#include<stdio.h>
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)

int M, N;
char P[5];

void Rock() {
   printf("%d\n",MIN(M,N));
}
void Knight() {
   int d, x;
   d = M*N;
   x = d/2;
   if(d%2) x += 1;
   printf("%d\n",x);
}
void Queen() {
     printf("%d\n",MIN(M,N));
}
void  King() {
   int max, d, k, x;
   d = MAX(M,N);
   k = MIN(M,N);
   x = (d / 2);
   if( d % 2) x += 1;
   k -= k / 2;
   max = k * x;
   printf("%d\n",max);
}



int main() {

   int kase;
   scanf("%d",&kase);
   while(kase--) {
	 scanf("%s%d%d",P,&M,&N);
	 switch(P[0]) {
	    case 'r':Rock();   break;
	    case 'k':Knight(); break;
	    case 'K':King();   break;
	    case 'Q':Queen();  break;
	}
   }
	return 0;

}
