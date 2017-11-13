#include<stdio.h>


int  N;

int Uniq(int a, int b) {
	int i, j;
    int f[12] = {0};
	char ss[10], aa[10];
   sprintf(aa,"%05d",a);
   sprintf(ss,"%05d",b);
   for(i = 0; aa[i]; i++) {
	   j = aa[i] - '0';
	   if(f[j] == 1) return 0;
	   f[j] = 1;
   }
   for(i = 0; ss[i]; i++) {
	   j = ss[i] - '0';
	   if(f[j] == 1) return 0;
	   f[j] = 1;
   }
   return 1;
}

void FIND() {
   int i, j, k = 1;
   for(i = 1234; i<=99999; i++) {
       j = N*i;
	   if(j >98765) break;
	   if(Uniq(i, j)) { printf("%05d / %05d = %d\n",j,i,N); k = 0;}
	   
   }
   if(k) printf("There are no solutions for %d.\n",N);
}

int main() {
	int f = 0;
    while(scanf("%d",&N) && N) {
		if(f++) putchar('\n');
		FIND();
	}
	return 0;
}
