#include<stdio.h>

int main()
{
     char ch;
     int d;
     while((ch=getc(stdin))!=EOF)
     {
	d=ch;
       if(d==10)
	{
	  printf("\n");
	  continue;
	}
	printf("%c",d-7);

     }

	return 0;
 }
