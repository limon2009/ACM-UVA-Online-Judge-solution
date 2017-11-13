#include<stdio.h>


   main()
   {
       long n,m,i,cary,d;
       while(1)
       {
	  scanf("%ld %ld",&n,&m);
	  if(!n)
	   if(!m) break;
	  d=0;cary=0;
	  for(i=1;i<=10;i++)
	  {
	    if((n%10+m%10+d)>9)
	    {
	       cary++;
	       d=1;
	    }
	    else
	     d=0;
	   n=n/10;m=m/10;
	   }
	   if(cary==0)
	    printf("No carry operation.\n");
	   else if(cary==1)
	    printf("%ld carry operation.\n",cary);
	   else
	    printf("%ld carry operations.\n",cary);
       }
       return 0;
    }
