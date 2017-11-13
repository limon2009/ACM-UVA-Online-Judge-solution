#include<stdio.h>

main()
{
       char a[400],b[400],d[400];
       int sum,k=0,c,l,v,ck,m,i;
       while(scanf("%d",&v)==1)
       {
	  v = v+2;
	  for(m = 0;m <= 400; m ++) a[m]=b[m]=d[m]=0;
	  b[0] = 1;  ck = 0;
	  for(i = 0; i<v; i ++)
	  {
	     sum = 0; k = 0;c = 0;
	     while(1)
	     {
		sum = a[k]+b[k]+c;
		if(!sum && ck<=k) break;
		d[k] = sum % 10;
		c = sum / 10;
		k ++;
	     }
	     for(l = 0;l <= k;l ++)
	     {
		 b[l]=a[l];
		 a[l]=d[l];
	     }
	     ck=k;
	  }

	  for(l = k-1;l >= 0;l--) printf("%d", d[l]);
	  printf("\n");
       }
 return 0;
}


