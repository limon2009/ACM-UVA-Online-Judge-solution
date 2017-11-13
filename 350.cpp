#include<stdio.h>
#include<math.h>


long old[200000];
int n;

int round()
{
   int i;
   long k;
   k = old[n];
   for(i = 0; i<n; i++)
     if(k == old[i])
       return n-i;
  return 0;
}




int  main()
{
    long z,i,m,l;
    int c = 0;
    while(scanf("%ld %ld %ld %ld",&z,&i,&m,&l) == 4)
    {
	 
		if(!z && !i && !m && !l) break;
		n = -1;
	    c ++;
	    while(!round())
		{
	      old[++n] = l;
	      l = (z * l + i) % m;

		}
	    printf("Case %d: %d\n",c,round());
    }
    return 0;
}
