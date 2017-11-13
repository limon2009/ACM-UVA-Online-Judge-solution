#include<stdio.h>
#include<ctype.h>

char vo[] = "aAeEiIoOuU";
char ch;

void main(void) {


     char store;
     int a,s,st,ck,c,i;
      a = 1;
     st = 0;
      s = 0;
     ck = 0;

     while( (ch = getc(stdin)) != EOF)  {

       if( ch == '\n') {
	  if(!ck) printf("\n");

	  else {
	    if(st)
	      printf("%c",store);
	      printf("ay");
	      a = 1;
	      printf("\n");
	      s = 0;
	  }
       }

       else if(isalpha(ch) && a) {

	  c = 0;
	  st = 0;
	  for(i = 0; vo[i]; i ++)
	   if(ch == vo[i]) {
	      c = 1;
	      break;
	   }
	 if(c) printf("%c",ch);

	 else {
	     store = ch;
	     st = 1;
	     s = 1;
	 }
	 a = 0;
	 ck = 1;
	 s = 1;
       }

       else if(!isalpha(ch) && s) {

	  if(st) printf("%c",store);
	  printf("ay%c",ch);
	  a = 1;
	  ck = 0;
	  s = 0;
       }
       else
	 printf("%c",ch);

     }
}
