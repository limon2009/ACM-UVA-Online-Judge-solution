#include<stdio.h>
#include<string.h>
#include<ctype.h>

char word[645000][31]; /* arry size are to increase [645151] */
int fre[40],f;

calculat(char a[]) {
   int i;
   for(i = 0; a[i]; i++) {
     if(isalpha(a[i]))
      f++;
     else if(a[i] == '.' || a[i] == ',' || a[i] == '!' || a[i] == '?') {
       fre[f] ++;
       f = 0;
     }
   }
   if(a[i-1] != '-') {
     fre[f] ++;
     f = 0;
   }

   return 0;
}

main() {

      int i,j,n,k = 0;
      while(scanf("%s",word[k++])!= EOF) {

	 while(scanf("%s",word[k]) && strcmp(word[k],"#"))
	  k ++;
	  f = 0;
	 for(i = 0; i<35; i++) fre[i] = 0;

	 for(i = 0; i<k; i++)
	   calculat(word[i]);
	 for(i = 1; i<30; i++)
	  if(fre[i])
	    printf("%d %d\n",i,fre[i]);

	printf("\n");
	k = 0;
      }
      return 0;
}
