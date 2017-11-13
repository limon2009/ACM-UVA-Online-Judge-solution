#include<stdio.h>
#include<assert.h>


	    int  main()
	    {

	      int i,j,k,l,n,m,kase,p;
	      scanf("%d",&kase);
	      for(p=1;p<=kase;p++)
	      {
		scanf("%d",&m);
		scanf("%d",&n);
		for(l=1;l<=n;l++)
		{
		   for(i=1;i<=m+1;i++)
		   {
		    if(i<=m)
		     {
		      for(j=1;j<=i;j++)
		       {
			printf("%d",i);
		       }
		       printf("\n");
		     }
		    else
		    {
		      for(k=m-1;k>=1;k--)
		      {
			for(j=1;j<=k;j++)
			 printf("%d",k);
			printf("\n");
		      }
		    }
		   }
		  if(l<n)
		  printf("\n");
		}
		if(p!=kase)
		printf("\n");
	      }
	   
	return 0;
 }
