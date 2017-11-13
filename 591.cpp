#include<stdio.h>

main()
{
     int n,i,move,k,s[102],total_briks;
     int kase = 0;
     while(scanf("%d", &n) && n)
     {
	 total_briks = 0;
		move = 0;
	 kase ++;
	 for(i = 0; i<n; i++)
	 {
	    scanf("%d", &s[i]);
	    total_briks += s[i];
	 }

	 k = total_briks/n;
	 for(i = 0; i<n; i++)
	  if(s[i]>k)
	    move += s[i] - k;
	 printf("Set #%d\n",kase);
	 printf("The minimum number of moves is %d.\n", move);
	 printf("\n");
     }
     return 0;
}
