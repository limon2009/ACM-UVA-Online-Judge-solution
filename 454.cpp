#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 10000
  /* 10000 */

char STR[102][MAXN];
int N;

int sort_function(const void *a, const void *s)  {
    return ( strcmp( (char *) a, (char *)s));
}

int s_function(const void *a,const void *s) {
  return *(char *)a - *(char *)s;
}

int ANAG(char A[] ,char B[])  {

       int i,j;
       int k = 0;
       for(i = 0; A[i]; i ++)
	 if(A[i] != ' ')
	   A[k++] = A[i];
       A[k] = NULL;
       k = 0;
       for(i = 0; B[i]; i ++)
	 if(B[i] != ' ')
	   B[k++] = B[i];
       B[k] = NULL;
       if(strlen(A) != strlen(B) ) return 0;
       qsort((void *)A,strlen(A),sizeof(char),s_function);
       qsort((void *)B,strlen(B),sizeof(char),s_function);
       if(!strcmp(A,B)) return 1;

       return 0;
}

void PRINT(char A[],char B[]) {
    printf("%s = %s\n",A,B);
}



void COMPUTE()  {

     int i,j;
     char TEMP1[MAXN],TEMP[MAXN];
     for(i = 0; i<N-1; i ++) {
	 if(i && !strcmp(STR[i],STR[i-1]))continue;
	for(j = i + 1; j<N; j ++)  {
	     if(!strcmp(STR[j],STR[j-1])) continue;
	     strcpy(TEMP1,STR[i]);
	     strcpy(TEMP,STR[j]);
	     if(ANAG(TEMP1,TEMP)) {
		PRINT(STR[i],STR[j]);

	     }
	}
     }
}


int main()  {

      char input[50];
      int i,kase;
      gets(input);
      sscanf(input,"%d",&kase);
      gets(input);
      while(kase--) {
	 i = 0;
	 while(1) {

	    gets(STR[i]);
	    if(STR[i][0] == NULL||STR[i][0] == '\n')  break;
	    i ++;
	 }
	 N = i;
	 qsort((void *)STR,N,sizeof(STR[0]),sort_function);
	 COMPUTE();
	 if(kase)
	     printf("\n");

      }
	return 0;

}
