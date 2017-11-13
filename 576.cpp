#include<stdio.h>
#include<string.h>

#define MAXN 201

char V[] = "aeiouy";
char HAIK[MAXN];

int ISVO(int n)  {
  int i;
  for(i = 0; V[i]; i ++)
   if(V[i] == HAIK[n])
      return 1;

  return 0;
}



void COMPUTE() {
      int i,j;
      j = 0;
      if(ISVO(0)) j = 1;
      for(i = 1; HAIK[i] != '/'; i ++)
	  if(ISVO(i) && !ISVO(i-1))
	    j++;
      if(j != 5) {
	printf("1\n");
	return;
      }

      j = 0;
      if(ISVO(i+1)) j = 1;
      for(i = i+2; HAIK[i] != '/'; i ++)
	  if(ISVO(i) && !ISVO(i-1))
	    j++;
      if(j != 7) {
	printf("2\n");
	return;
      }
      j = 0;
      if(ISVO(i+1)) j = 1;
      for(i = i+2; HAIK[i]; i ++)
	 if(ISVO(i) && !ISVO(i-1))
	    j++;
      if(j != 5) {
	printf("3\n");
	return;
      }
      printf("Y\n");
}




int main()  {

       while(gets(HAIK)) {
	  if(!strcmp(HAIK,"e/o/i")) break;

	  COMPUTE();
       }


	return 0;

}
