#include <stdio.h>
#include <string.h>
#define MAX 120
/*  10000  */

int X[MAX],Y[MAX];
int i,j,m,n,c[MAX][MAX],b[MAX][MAX];

int LCSlength() {


  for (i=1;i<=m;i++) c[i][0]=0;
  for (j=0;j<=n;j++) c[0][j]=0;

  for (i=1;i<=m;i++)
    for (j=1;j<=n;j++) {
      if (X[i-1]==Y[j-1]) {
	c[i][j]=c[i-1][j-1]+1;
	b[i][j]=1;
      }
      else if (c[i-1][j]>=c[i][j-1]) {
	c[i][j]=c[i-1][j];
	b[i][j]=2;
      }
      else {
	c[i][j]=c[i][j-1];
	b[i][j]=3;
      }
    }

  return c[m][n];
}


int main() {

   int pp,kase = 0;;
  while (1) {
    scanf("%d%d",&m,&n);
    if(!m)
     if(!n) break;
    for(pp = 0; pp<m; pp ++) scanf("%d",&X[pp]);
    for(pp = 0; pp<n; pp ++) scanf("%d",&Y[pp]);
    printf("Twin Towers #%d\n",++kase);
    printf("Number of Tiles : %d\n",LCSlength());
    printf("\n");
  }
	return 0;

}
