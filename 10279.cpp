#include<ctype.h>
#include<stdio.h>
#include<string.h>
#define MAXN 20

int N;
int COUNT ;
char MAP[MAXN][MAXN];
char PLAY[MAXN][MAXN];

void GAME(int r,int c)  {
	int i,j,x,y;
	 for(i = -1; i<= 1; i ++){
	   for(j = -1; j<=1; j++) {
			if(j != 0 || i != 0){
			    x = i+r;
				y = j+c;
				if(x>=N ||x<0 ||y>=N ||y<0) continue;
				  if(MAP[x][y] =='*')
					COUNT ++;
			}
				
		}
	}
	
}



void print_bord() {
	int i,j;
	for(i = 0; i<N; i++){
	  for(j = 0; j<N; j++)
	    if(isdigit(PLAY[i][j]))
	      printf("%c",PLAY[i][j]);
	    else  {
	      if(MAP[i][j] == '*') printf("*");
	      else printf(".");
	    }

	    printf("\n");
	}
}




void COM()  {

	int i,j,c = 0;
	for(i = 0; i<N; i ++){
	   for(j = 0; j<N; j++){
	      if(PLAY[i][j] =='x'){
		 if(MAP[i][j] == '*'){
		     c = 1;
		  }
		  else {
		   COUNT = 0;
		   GAME(i,j);
		   PLAY[i][j] = COUNT +'0';
		 }
	      }
	   }
	}
	if(c) { print_bord();return;}
	for( i = 0;i<N; i++){
	  for(j = 0; j<N; j++)
	    printf("%c",PLAY[i][j]);
	  printf("\n");
	}
}



int main()  {

      int i,kase;
      char input[20];
      gets(input);
      sscanf(input,"%d",&kase);
      gets(input);
      while(kase--) {
	gets(input);
	sscanf(input,"%d",&N);
	for(i = 0; i<N; i ++)
	   gets(MAP[i]);
	for(i = 0; i<N; i ++)
	   gets(PLAY[i]);
	COM();
	if(kase) {
	   gets(input);
	   printf("\n");
	}
      }
	return 0;

}
