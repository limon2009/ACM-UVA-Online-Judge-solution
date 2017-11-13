#include<stdio.h>

int fre[130];
int store[60];
char text[20000];

main() {

   int i,max,k,p;
   while(gets(text)) {

       for(i = 0; i<130; i++) fre[i] = 0;
       for(i = 0; text[i]; i ++) {
	 p = text[i];
	 fre[p] ++;
       }

	 k = 0;
       max = fre[65];
       store[k++] = 65;
       for(i = 66; i<=122; i ++) {
	  if(max == fre[i])
	    store[k++] = i;

	  else if( max<fre[i]) {
	    k = 0;
	    store[k++] = i;
	    max = fre[i];
	  }
      }
      for(i = 0; i<k; i ++)
	printf("%c", store[i]);
      printf(" %d\n",max);
   }
   return 0;
}

