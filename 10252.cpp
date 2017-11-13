#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MIN(a,b) (a>b?b:a)
#define MAXN 1001
char A[MAXN], B[MAXN];
int FA[300], FB[MAXN];

int com(const void *a, const void *b) {
	return *(char *)a - *(char *)b;
}

void Cal() {
   int i, m, j;
   qsort(A,strlen(A),sizeof(char),com);
   qsort(B,strlen(B),sizeof(char),com);
   for(i = 0; A[i]; i++){
	   m = A[i];
	   FA[m] ++;
   }
   for(i = 0; B[i]; i++){
	   m = B[i];
	   FB[m] ++;
   }
   for(i = 97; i<=122; i++) {
	   if(FA[i] && FB[i]) {
		   m = MIN(FA[i], FB[i]);
		   for(j = 0; j<m; j++)
			   printf("%c",i);
	   }
   }
   printf("\n");


}

int main() {
	while(gets(A)) {
		gets(B);
        for(int i = 97; i<= 125; i++)
		   FA[i] = FB[i] = 0;
	    Cal();
	}
	return 0;

}
