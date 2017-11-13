#include<stdio.h>
#include<math.h>

int n,m;

int cal() {
  int k,d,temp;
  k = n/m;
  d = n - m * k;
  while(1) {
     temp = m;
     m = d;
     d = temp;
     printf("%d",d/m);
     if(m == 1) break;
     k = d/m;
     d = d - k * m;

     printf(",");
  }
  printf("]\n");
  return 0;
}

int main()  {
      int k;
      while(scanf("%d%d",&n,&m) == 2)  {
	   printf("[%d;",n/m);
	   cal();

      }
      return 0;
}
