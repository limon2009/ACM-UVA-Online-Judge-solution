#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>


char line[20000][1000];    /* arry size are to increase line[20000][1000] */
int fre[300];
int store[300];

int sort_function( const void *a, const void *b)
{
   return *(int *)b - *(int *)a ;
}




main() {

    int i,j,k,c,pre,n;
    char y[10];
    gets(y);
    n = atoi(y);
       for(i = 0; i<n; i++)
	 gets(line[i]);
      for(i = 0; i<300; i++) fre[i] = 0;
       for(i = 0; i<n; i++) {
	 for(j = 0; line[i][j]; j ++) {
	   if(isalpha(line[i][j])) {
	     k = toupper(line[i][j]);
	     fre[k] ++;
	   }
	 }
       }

       c = 0;
       for(i = 65; i<= 90; i ++)
	     if( fre[i] )
	     store[c++] = fre[i];
       qsort((void *)store, c, 4, sort_function);

       pre = 0;
       for( i = 0; i<c; i ++) {
	  if(store[i] == pre)
	     continue;
	  for( j = 65; j<=90; j ++)
	    if(fre[j] == store[i])
	      printf("%c %d\n",j,fre[j]);
	  pre = store[i];
     
	   }

    return 0;
}



