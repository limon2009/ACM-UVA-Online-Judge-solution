#include<stdio.h>


main()  {

  int kase,f,size,number,envir,i;
  long long total;
  scanf("%d", &kase);
  while(kase -- )   {
      scanf("%d", &f);
      total = 0;
      for(i = 0; i<f; i ++)  {
	 scanf("%d%d%d", &size, &number, &envir);
	 total += size * envir;
      }
      printf("%lld\n",total);
  }
  return 0;
}
