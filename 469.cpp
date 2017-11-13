#include<stdio.h>
#include<string.h>
#define MAXR 105
#define MAXN 105

char FLORIDA[MAXR][MAXN];
char HELP[MAXR][MAXN];
int  count,R,C;


void FLOOD(int r,int c)  {

  if( r<0 || r >= R || c<0 || c >= C) return ;
  if(HELP[r][c] != 'W') return;
  HELP[r][c] = '1';
  count ++;
  for(int i = -1; i<= 1; i ++) {
    for(int j = -1; j <= 1; j ++)
      if( i!= 0 || j!= 0) {
	FLOOD(r+i,c+j);

     }
  }
}


int main()  {

     int r,c,n,kase,i;
     char input[20],fal[30];
     gets(input);
     sscanf(input,"%d",&kase);
     gets(fal);
     while(kase--)  {

	R = 0;
	while(1) {

	    gets(FLORIDA[R]);
	    n = sscanf(FLORIDA[R], "%d%d",&r,&c);
	    if(n == 2) break;
	    R ++;
	}

       C = strlen(FLORIDA[0]);

       for(i = 0; i < R; i ++)
	 strcpy(HELP[i],FLORIDA[i]);

       count = 0;
       FLOOD(r-1,c-1);
       printf("%d\n",count);

       while(gets(input))  {

	  int k = sscanf(input,"%d%d",&r,&c);
	  if(k<=1) break;
	  for(i = 0; i <R; i ++)
	    strcpy(HELP[i],FLORIDA[i]);
	  count = 0;
	  FLOOD(r-1,c-1);
	  printf("%d\n",count);
       }
      if(kase>0)
	printf("\n");
   }
	return 0;

}
