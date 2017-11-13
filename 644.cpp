#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char bit[100][100];
int p;

int sort_function( const void *a, const void *b)
{
   return( strcmp((char *)a,(char *)b) );
}


int result()  {
   int i,j;
   for(i = 0; i<p-1; i ++)
    for(j = i+1; j<p; j ++)
	if(!strncmp(bit[i],bit[j],strlen(bit[i])))
	  return 0;

    return 1;
}




int main()  {
     int set =0;
     p = 0;
     while(scanf("%s",bit[p]) != EOF) {
	 p ++;
	 set ++;
	 while(1)  {

	   scanf("%s",bit[p]);
	   if(!strcmp(bit[p],"9")) break;
	   p ++;
	 }
	 qsort((void *)bit,p,sizeof(bit[0]),sort_function);
	 if(result())
	  printf("Set %d is immediately decodable\n",set);
	 else
	  printf("Set %d is not immediately decodable\n",set);
	  p = 0;
     }
     return 0;
}
