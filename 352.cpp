#include<stdio.h>
#define MAXN 26

char PIXEL[MAXN][MAXN];
int COUNT,R;

void IMAGE(int r,int c)  {
     if(r>=R||r<0 ||c>=R||c<0) return;
     if(PIXEL[r][c] != '1') return;
     PIXEL[r][c] = '0';
     for(int i = -1; i<=1; i ++) {
      for(int j = -1; j<= 1; j ++) {
	if(i!= 0 || j!= 0)
	  IMAGE(r+i,c+j);
      }
    }
}

void WAR(int n)   {
  int i,j;
  COUNT = 0;
  for(i = 0; i<R; i ++)
   for(j = 0; j<R; j++)
     if(PIXEL[i][j] == '1') {
       COUNT ++;
       IMAGE(i,j);
     }
  printf("Image number %d contains %d war eagles.\n",n,COUNT);
}


int main() {
	 int i,kase,p;
	 char input[10];
	 kase = 0;
	 while(gets(input)) {
	   p = sscanf(input,"%d",&R);
	   if(p == 0) break;
	   for(i = 0;i<R; i ++)
	     gets(PIXEL[i]);
	   kase ++;
	   if(kase == 12) break;
	   WAR(kase);
	}
	return 0;

}
