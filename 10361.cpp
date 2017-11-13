#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s1[100],s2[100],s3[100],s4[100];

int re(char a[])
{
   int i,j,k,l;
   l = 1;

    for(i = 0; a[i]; i++)
      if(a[i] !='<' && a[i] != '>' )
	 printf("%c",a[i]);

    else if(l)
    {
	k = 0;
	j = i+1;
	while(a[j] != '>')
	{
	   s1[k++] = a[j];
	   j++;
	}

	s1[k] = NULL;
	k = 0;
	j = j+1;

	while(a[j] != '<')
	{
	   s2[k++] = a[j];
	   j++;
	}
	s2[k] = NULL;
	k = 0;
	j = j+1;

	while(a[j] != '>')
	{
	  s3[k++] = a[j];
	  j++;
	}
	s3[k] = NULL;
	k = 0;
	j = j+1;

	while(a[j] != ' ' && a[j])
	{
	  s4[k++] = a[j];
	  j++;
	}
	s4[k] = NULL;
	l = 0;
    }
   printf("\n");
   return 0;
}


int replace(char a[])
{
   int i,j;
   for(i = 0; a[i]; i++)
     if(a[i] != '.')
       printf("%c", a[i]);
     else
     {
	  printf("%s",s3);
	  printf("%s",s2);
	  printf("%s",s1);
	  printf("%s",s4);
	 printf("\n");
	 return 0;
     }
     return 1;
}


int main()
{
   int kase,i,k;
   char line[105][105],ks[12];

    gets(ks);
    kase = atoi(ks);
   for(i = 0; i< kase*2; i ++)
      gets(line[i]);
   for(i = 0; i < kase*2; i += 2) {
     re(line[i]);
     replace(line[i+1]);
   }
   return 0;
}
