#include<stdio.h>

#define MAXN 4

char Tic[MAXN][MAXN];
int N,T,O;

void Readcase() {
   int i;
   for(i = 0; i<3; i++)
	   gets(Tic[i]);

}


int Islegal() {
   int i, j;
   T = O = 0;
   for(i = 0; i<3; i++)
	   for(j = 0; j<3; j++)
		   if(Tic[i][j] == 'X') T++;
		   else if(Tic[i][j] == 'O') O ++;
   
   if(T == O || T == O+1) return 1;
   return 0;
}


int Win(char c) {
	int i, j;
	int f = 1;
    for(i = 1; i<3; i++){
		if((Tic[i][i] != Tic[i-1][i-1] ) || Tic[i][i] != c){
			f = 0;
			break;
		}
	}
	if(f) return 1;
	for(i = 0; i<3; i++) {
		f = 1;
		for(j = 1; j<3; j++) {
			if((Tic[i][j-1] != Tic[i][j]) || Tic[i][j] != c) {
				f = 0;		
				break;
			}
	
		}
		if(f) return 1;
//		if(f && Tic[i][0] == 'O') return 2;
	}
	for(i = 0; i<3; i++) {
		f = 1;
		for(j = 1; j<3; j++) {
			if((Tic[j-1][i] != Tic[j][i] )|| Tic[j][i] != c) {
				f = 0;
				break;
			}
	
		}
		if(f) return 1;
	//	if(f && Tic[0][i] == 'O') return 2;
	}
    
    return 0;
}

void Solvedcase() {
   int  k;
   k = Islegal();
   if(k ==0) {
	   printf("no\n");
	   return;
   }
  // k = Win();
   if(Win('X')) {
       if(!Win('O') && T == O+1)
	     printf("yes\n");
	   else printf("no\n");
       return;
   }
   else if(Win('O')) {
	   if(!Win('X') && T == O)
	   printf("yes\n");
	   else printf("no\n");
	   return;
   }
   printf("yes\n");

}
int main() {
	char input[10];
    gets(input);
	sscanf(input,"%d",&N);
	while(N --) {
		Readcase();
		Solvedcase();
	    if(N) gets(input);
	}
	return 0;

}
