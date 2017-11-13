#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 1001
	     /**1001*/

int N,M;
long long VAL;
char W[100];

typedef struct node{

    char P[100];
    long DOLLAR;

}SS;

SS HAY[MAXN],TEX;

int sf(const void *a,  const void *b ) {
     return  ( strcmp( ((SS *)a)->P,((SS *)b)->P ) );
}


void COM()  {

    SS  *i;

    while(M--)     {
	VAL = 0;
	while(1)  {
	 scanf("%s",TEX.P);
	 if(!strcmp(TEX.P,".")) break;
	 i =  (SS *)  bsearch(&TEX,HAY,N,sizeof(HAY[0]),sf);

	 if(i)
	    VAL += i->DOLLAR;
      }
     printf("%lld\n",VAL);
   }
}



int main()  {

   char input[20];
   int i;
   gets(input);
   sscanf(input,"%d%d",&N,&M);
   for(i = 0; i<N; i ++)
     scanf("%s%ld",HAY[i].P,&HAY[i].DOLLAR);
   qsort(HAY,N,sizeof(HAY[0]),sf);
   COM();
	return 0;

}
