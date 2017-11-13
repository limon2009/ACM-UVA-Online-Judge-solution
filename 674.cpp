#include <stdio.h>
#define MAXTOTAL 7490

long nway[MAXTOTAL+1];


int coin[5]={ 50,25,10,5,1 };

void Change() {
    int i, j, v,c;
	v=5;
    nway[0]=1;
    for (i=0;i<v;i++) {
      c=coin[i];
      for (j=c;j<=7489; j++)
	 nway[j]+=nway[j-c];
    }
   

}

int main() {
  int n;
  Change();
  while(scanf("%d",&n)== 1) 
         printf("%d\n",nway[n]);
  
	return 0;

}
