#include<stdio.h>

long N,st,end,d;
int c;



int compute()
{
    long i,a[10],g,k,m,h;
     k = N-d;
     h = k/c;
     m = k%c;
     i = st+h-1;
     if(m) i = i+1;
     if(m) h = h+1;
     d = h*c+d;
	g = 0;

    while(i)
    {
	a[g++] = i%10;
	i /= 10;
    }

    for(i = 0; i<g; i++)
    {

	if(d-i == N) break;
    }
    printf("%ld\n",a[i]);
    return 0;
}


int main()
{


      while(scanf("%ld",&N) == 1)
      {
	  if(N<= 9)
	  {
	      printf("%ld\n",N);
	      continue;
	  }

	  if(N>=10 && N<= 189)
	  {
	      st = 10; end = 99;
	      c = 2; d = 9;
	  }

	  else if(N>=190 && N<= 2889)
	  {
	      st = 100; end =999;
	      c = 3; d = 189;
	  }

	  else if(N>=2890 && N<= 38889)
	  {
	      st = 1000; end = 9999;
	      c = 4; d = 2889;
	  }
	  else if(N>=38890 && N<= 488889)
	  {
	      st = 10000; end = 99999;
	      c = 5; d = 38889;
	  }
	  else if(N>=488890 && N<= 5888889)
	  {
	      st = 100000; end = 999999;
	      c = 6; d = 488889;
	  }
	  else if(N>=5888890 && N<= 68888889)
	  {
	      st = 1000000; end = 9999999;
	      c = 7; d = 5888889;
	  }
	  else
	  {
	      st = 10000000; end = 99999999;
	      c = 8; d = 68888889;
	  }

	  compute();
      }
      return 0;
}

