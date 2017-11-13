#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char text[300];
char word[15][85];
int s,e;


int rep(char word1[],char word2[]) {

    int k,d,a,i,j;
    k = strlen(text);
    if( strlen(word1)<strlen(word2) ){
       d = strlen(word2) - strlen(word1);
       a = k + d - 1;
       for(i = a; i >= e+d; i --)
	  text[i] = text[i-d];
       for(i = 0; word2[i]; i ++)
	  text[s+i] = word2[i];

       text[a+1] = NULL;
    }

    else if(strlen(word1) > strlen(word2)) {
	d= strlen(word1) - strlen(word2);

	for(i = 0; word2[i]; i ++)
	 text[s+i] = word2[i];
	a = s + strlen(word2);
	for(j = a; text[j]; j ++)
	  text[j] = text[j+d];
       text[j] = NULL;
    }
    else {
      for(i = 0; word2[i]; i++)
	 text[s+i] = word2[i];
    }

    return 0;
}

int p_match(char key[])  {

	int i,j,max,c;
	max = strlen(text) - strlen(key);
	for(i = 0;i<=max; i++) {
	   c = 1;
	   for(j = 0; key[j]; j++) {
	     if(text[i+j] != key[j]) {
	       c = 0;
	       break;
	     }
	   }
	   if(c) {
	     s = i;
	     e = i + strlen(key) - 1;
	     return 1;
	   }
	}
	return 0;
}

int main() {
   int i,j,k;
    char n[5];

   while(gets(n) && atoi(n)) {
      k  = atoi(n);
      for(i = 0; i<k*2; i++)
	 gets(word[i]);

      gets(text);

      for(i = 0; i<k*2-1; i +=2) {
	 while(p_match(word[i]))
	      rep(word[i],word[i+1]);
      }

      for(i = 0; text[i]; i++)
	printf("%c", text[i]);
      printf("\n");
   }
     return 0;
}










