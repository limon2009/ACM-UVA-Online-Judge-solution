#include<stdio.h>

main()
{
   int  b,p,m,i,r,cary;
   int  x,d;
   char a[46344];
   while(scanf("%d",&b)==1)
   {
       scanf("%d",&p);
       scanf("%d",&m);
           
       if(b == 0){ printf("0\n"); continue; }
	   else if(p == 0) { printf("%d\n",1%m); continue; }
	   if(b%m == 0) { printf("0\n"); continue; }
	   for(i =1; i<=m+1; i++) a[i] = 0;
       cary = 1;
       i = 0;
       
	   while(1)
       {
	     d = b%m;
	     x = d*cary;
	     cary = x%m;
	     if(a[cary]) break;
	     a[cary] = 1;
	     i++;
       }
       
	   r = p%i;
	   cary = 1;
	   d = b%m;
	   for(i = 1; i<=r; i++)
	   {
         
	     x = d*cary;
	     cary = x%m;
	     
       }
	   printf("%d\n",cary);
   }
   return 0;
}
