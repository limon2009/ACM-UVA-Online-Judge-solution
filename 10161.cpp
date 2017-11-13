#include<stdio.h>
#include<math.h>

int main()
{
    long b,grid,mid,end,k,i;
    long time;
    while(scanf("%ld",&time) && time)
    {
	 for(i=1;i;i++)
	 {

	   if(i*i>=time) break;
	 }
	 b=i;
	 grid=i*i;
	 mid=grid+1-b;
	 if(time==mid)
	 {
	     printf("%ld %ld\n",b,b);
	     goto x;
	 }

	 if(b%2==0)
	 {
	    if(time==grid) { printf("%ld 1\n",b); goto x;}
	    end=mid+1-b;
	    if(time==end)
	       printf("1 %ld\n",b);

	    else if(time<mid && time>=end)
	    {
	      k=mid-time;
	      printf("%ld %ld\n",b-k,b);

	     }
	    else
	    {
	       k=grid-time;
	       printf("%ld %ld\n",b,k+1);

	    }
	 }
	 else
	 {
	    if(time==grid) { printf("1 %ld\n",b); goto x;}
	    end=mid+1-b;
	    if(time==end)
	       printf("%ld 1\n",b);

	    else if(time>mid && time<=grid)
	    {
	      k=grid-time;
	      printf("%ld %ld\n",k+1,b);

	     }
	    else
	    {
	       k=mid-time;
	       printf("%ld %ld\n",b,b-k);

	    }
	 }
      x:
    }
    return 0;
}
