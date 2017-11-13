#include<stdio.h>
#include<string.h>

char wo[] = "AEHIJLMOSTUVWXYZ12358";
char rw[] = "A3HILJMO2TUVWXY51SEZ8";

int pallin(char w[])
{
       int i,len,k=0;
       char a[10000];
       len=strlen(w)-1;
       for(i=len;i>=0;i--)
	 a[k++] = w[i];
       a[k] = NULL;
       if(!strcmp(a,w))
	 return 1;

       return 0;
}



int  mirror(char w[])
{
       int i,k,ck,len,d,j,p;
       d = strlen(w);
       k = d - 1;
       if(d % 2 != 0)
	  len  = d / 2;
       else
	  len = d / 2 - 1;

       for(i = 0; i <= len; i ++) {
	 ck = 1;
	 for(j = 0; wo[j]; j ++) {
	    if(w[i] == wo[j])
	       if(w[k] == rw[j])  {
		 ck = 0;
		 break;
	       }
	 }
	 k --;
	 if(ck) return 0;
       }
       return 1;
}

int main()
{
    char word[1000];
    int pal;
    int mirr;
    while(scanf("%s",word)!=EOF)
    {
	    pal = 0;
	   mirr = 0;
	   if(pallin(word))
	     pal = 1;
	   if(mirror(word))
	     mirr = 1;

	   if(pal && mirr)
	     printf("%s -- is a mirrored palindrome.\n",word);

	   else if(pal)
	     printf("%s -- is a regular palindrome.\n",word);

	   else if(mirr)
	     printf("%s -- is a mirrored string.\n",word);

	   else
	     printf("%s -- is not a palindrome.\n",word);

	   printf("\n");
     }
	return 0;

}
