#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char dis[101][7];
int k;

int sort_function( const void *a, const void *b)
{
   return( strcmp((char *)a,(char *)b) );
}




int find(char word[])
{
    char store[7];
    char list[100][7];
    int i,m,ck,j,p;
    m = 0;
    for(i = 0; i<k; i++)
    {
	if(strlen(word) != strlen(dis[i]))  continue;
	strcpy(store,dis[i]);

	for(j = 0; word[j]; j++)
	{
	   ck = 0;

	   for(p = 0; store[p]; p++)
	   {
	      if(word[j] == store[p])
	      {
		 store[p] = '*';
		 ck = 1;
		 break;
	      }
	   }
	   if(!ck) break;
	}

	if(ck)
	{
	    strcpy(list[m++],dis[i]);

	}
    }

    if(m)
    {
       qsort((void *)list, m, 7, sort_function);
       for(i = 0; i<m; i++)
	 printf("%s\n",list[i]);
    }
    else
      printf("NOT A VALID WORD\n");

    printf("******\n");

   return 0;
}

int main()
{
     int h,i;
     char s_word[100][10];
     k = 0;
     h = 0;
     while(scanf("%s", dis[k]) && strcmp(dis[k],"XXXXXX"))
      k++;

     while(1)
     {
	scanf("%s",s_word[h]);
	if(!strcmp(s_word[h],"XXXXXX")) break;
	h++;
     }
     for(i = 0; i<h; i++)
      find(s_word[i]);

     return 0;
}
