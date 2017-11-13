#include<stdio.h>

#define MAX  7
char V[MAX][MAX];
char B[10];

void MAKELINK()  {
      V[1][2] = 1;  V[2][1] = 1;
      V[2][3] = 1;  V[3][2] = 1;
      V[5][2] = 1;  V[2][5] = 1;
      V[3][5] = 1;  V[5][3] = 1;
      V[1][5] = 1;  V[5][1] = 1;
      V[1][3] = 1;  V[3][1] = 1;
      V[5][4] = 1;  V[4][5] = 1;
      V[3][4] = 1;  V[4][3] = 1;
}

void PRINT()  {
  int i;
  printf("1");
  for(i = 0; i<8; i ++)
    printf("%d",B[i]);
  putchar('\n');
}

void CAL(int r,int level)  {

    int j,k;
    if(level == 8)  {
      PRINT();
      return;
    }
    for(int i = 1;i<=5; i ++)
      if(V[r][i] && V[i][r]) {
	B[level] = i;
	V[i][r] = V[r][i] = 0;
	CAL(i,level+1);
	j = level;
	k = B[j];
	V[k][r] = 1;
	V[r][k] = 1;
      }
       j = level - 2;
       if(j>=0) {
	 k = B[j];
	 V[k][r] = 1;
	 V[r][k] = 1;
       }
}

int main()  {

     MAKELINK();
     CAL(1,0);
	return 0;

}
