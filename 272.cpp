#include<stdio.h>
#include<string.h>

char text[1000000];

main()
{
   int i,j = 0;

   while(gets(text))   {
      for( i = 0; text[i]; i ++) {
	if(text[i] =='"') {
	  j ++;
	  if(j % 2 != 0)
	     printf("``");
	  else
	    printf("''");
	}
	else
	 printf("%c",text[i]);
      }
      printf("\n");
   }
   return 0;
}
