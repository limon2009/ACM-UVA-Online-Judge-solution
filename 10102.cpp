#include<stdio.h>
#include<math.h>
#define MAXN  10000

int O, T;
char Field[10000];
struct ONE {
  int x;
  int y;
}One[MAXN], Two[MAXN];

int Cal()  {
   int i, j, d;
   int MAX = 0, MIN;
   for(i = 0; i<O; i++) {
      MIN = 32767;
      for(j = 0; j<T; j++) {
	 d = abs(One[i].x - Two[j].x) + abs( One[i].y - Two[j].y);
	 if(MIN>d)
	   MIN = d;
      }
      if(MIN>MAX) MAX = MIN;
  }
  printf("%d\n",MAX);
  return 0;
}


int main()  {
   int i, m, j;

   while(scanf("%d",&m) == 1) {
       i = O = T = 0;
       while(m--) {
	   scanf("%s",Field);
	   for(j = 0; Field[j]; j++) {
	      if(Field[j] == '1') {
		One[O].x = i;
		One[O].y = j;
		O++;
	      }
	      else if(Field[j] == '3') {
		  Two[T].x = i;
		  Two[T].y = j;
		  T++;
	      }
	   }
	   i++;
       }
       Cal();
   }
	return 0;

}
