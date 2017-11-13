#include<stdio.h>
#include<string.h>

int a[7];

int south()
{
    int k,i;
    k = a[3];
    for(i = 2; i>=0; i --)
      a[i+1] = a[i];
    a[0] = k;
    return 0;
}

int north()
{
   int i,k;
   k = a[0];
   for(i = 0; i<=2; i ++)
     a[i] = a[i+1];
   a[3] = k;
   return 0;
}

int east() {
    int k;
    k = a[5];
    a[5] = a[0];
    a[0] = a[4];
    a[4] = a[2];
    a[2] = k;
    return 0;
}

int west()
{
   int k;
   k = a[4];
   a[4] = a[0];
   a[0] = a[5];
   a[5] = a[2];
   a[2] = k;
   return 0;
}

int main() {

    char side[1030][7];
    int n,i;

    while(scanf("%d", &n) &&n)
    {
	for(i = 0; i<n; i++)
	  scanf("%s", side[i]);

	a[0] = 1;
	a[1] = 5;
	a[2] = 6;
	a[3] = 2;
	a[4] = 3;
	a[5] = 4;
	for(i = 0; i<n; i++) {
	 if(!strcmp(side[i],"north"))
	   north();
	 else if(!strcmp(side[i],"south"))
	   south();
	 else if(!strcmp(side[i],"east"))
	   east();
	 else
	   west();

       }
       printf("%d\n" ,a[0]);

    }
    return 0;
}
