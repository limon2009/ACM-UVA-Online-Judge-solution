#include <stdio.h>

main()
{

  int number[15],k,i,j,p,l,m,n,c=0;

  while (1)
    {
      scanf("%d",& k);
      if  (k==0) break;
      for (i=0; i<k; i++)
	 scanf("%d",&number[i]);
      if (c++>0) printf("\n");
      for (i=0; i<k-5; i++)
	for (j=i+1; j<k-4; j++)
	  for (p=j+1; p<k-3; p++)
	    for (l=p+1; l<k-2; l++)
	      for (m=l+1; m<k-1; m++)
		for (n=m+1; n<k; n++)
		  printf("%d %d %d %d %d %d\n",number[i],number[j],
			 number[p],number[l],number[m],number[n]);
    }

  return 0;
}

