#include<stdio.h>

char  mat[105][105];
int N;

int row()  {

    int i,j,sum,c,save;
    sum = 0;
      c = 0;
    for(i = 0; i<N; i ++)  {
      sum = 0;
      for(j = 0; j<N; j ++)
	   sum += mat[i][j];
      if( sum % 2 != 0) {
	c ++;
	save = i;
      }
      if( c>1) return -2;
    }
    if( c == 1) return save;

    return -1;
}

int column()  {

  int i,j,sum,c,save;
  sum = c = 0;
  for(i = 0; i<N; i ++)  {
    sum = 0;
    for(j = 0; j<N; j ++)
       sum += mat[j][i];
    if(sum % 2 != 0) {
      c ++;
      save = i;
    }
    if(c > 1) return -2;
  }
  if( c == 1) return save;
  return -1;
}

int main()  {

    int i,j,k,m;
    while(scanf("%d",&N) && N) {

      for(i = 0; i<N; i ++)
	for(j = 0; j<N; j ++)
	  scanf("%d", & mat[i][j]);

      k = row();
      m = column();
      if(k == -1 && m == -1) printf("OK\n");
      else if( k == -2 || m == -2) printf("Corrupt\n");
      else printf("Change bit (%d,%d)\n",k+1,m+1);
    }
      return 0;

}
