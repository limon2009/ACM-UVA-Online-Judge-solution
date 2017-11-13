#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char word[1000][22];
char store[1000][22];


int sort_function( const void *a, const void *b)
{
   return( strcmp((char *)a,(char *)b) );
}



cheack(char a[],char s[])
{
    char x[22],y[22];
    int i,j,c;
    if(strlen(a)!= strlen(s))
      return 0;

    strcpy(x,a);
    strcpy(y,s);

    for(i = 0; x[i]; i++)
    {
       c = 0;
      for(j = 0; y[j]; j++)
      {
	 if(tolower(x[i]) == tolower(y[j]))
	 {
	    c = 1;
	    y[j] = '%';
	    break;
	 }
      }
      if(!c) return 0;
    }
    return 1;
}


main()
{
   int i,j,k,n,ck;

   k = 0;
   n = 0;

   while(scanf("%s",word[k]) && strcmp(word[k],"#"))
     k++;

   for(i = 0; i<k; i++)
   {
      if(!strcmp(word[i],"#"))  continue ;
      ck = 1;
      for(j = i+1; j<k; j++)
      {
	 if(cheack(word[i],word[j]) != 0)
	 {
	       ck = 0;
	       strcpy(word[j],"#");
	  }
      }
      if(ck)
	strcpy(store[n++],word[i]);
   }
   qsort((void *)store, n, 22, sort_function);

   for(i = 0; i<n; i++) printf("%s\n",store[i]);
   return 0;
}
