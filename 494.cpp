#include<stdio.h>
#include<string.h>

int main()
{

   int i,j,c,p=0,d,l;
   char a[1000];
   while(a, sizeof(a), stdin)
   {
      c=0;
      l=strlen(a);
      p=0;
      for(i = 0; i<l; i++)
      {
	 d=0;
	 if(((a[i] >=97 && a[i] <= 122 )||(a[i] >=65 && a[i] <= 90)) && i != l-1)
	   continue;
	 else
	 {
	   for(j=i;j>=p;j--)
	     if((a[j] >= 97&& a[j] <= 122)||(a[j] >= 65 && a[j] <= 90))
	     {
		d=1;
		break;
	     }
	   if(d) c++;
	   p=i;
	 }

      }
      printf("%d\n",c);
   }
       return 0;
}
