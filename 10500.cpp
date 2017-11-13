#include<stdio.h>
#include<string.h>

int R, C;
char INI[11][11];
char MAP[11][11];
char TEMP[11][11];
char Sym[] = "|---";

void MARK(int r, int c) {
   int nr, nc;
   MAP[r][c] = '0';
   TEMP[r][c] = 1;
   nr = r-1;
   if(nr>=0) MAP[nr][c] = INI[nr][c];
   nc = c+1;
   if(nc<C)  MAP[r][nc] = INI[r][nc];
   nr = r+1;
   if(nr<R)  MAP[nr][c] = INI[nr][c];
   nc = c-1;
   if(nc>=0) MAP[r][nc] = INI[r][nc];

}

int MOVE(int r, int c) {
   int nr, nc, side;
   nr = r-1;
   if(nr>=0 && INI[nr][c] != 'X' && TEMP[nr][c] !=1 ) {side = nr*C+c; return side; }
   nc = c+1;
   if(nc<C && INI[r][nc] != 'X' && TEMP[r][nc] !=1)  {side = r*C+nc; return side; }
   nr = r+1;
   if(nr<R && INI[nr][c] != 'X' && TEMP[nr][c] !=1)  {side = nr*C+c; return side; }
   nc = c-1;
   if(nc>=0 && INI[r][nc] != 'X' && TEMP[r][nc] !=1) {side = r*C+nc; return side; }

	return -1;
}
int SolvedCase(int sr, int sc) {
	int c = 0, side;
	while(1) {
	   MARK(sr, sc);
       side = MOVE(sr,sc);
	   if(side <0) break;
	   sr = side/C;
	   sc = side%C;
	   c++;
	}
	return c;
		
}

void ReadCase() {
	int i, j, m;  
	char dummy[100];
	for(i = 0; i<R; i++) {
	   gets(dummy);
	   m = 0;
	   for(j = 0; dummy[j]; j++)
		   if(dummy[j] != ' ' )
			   INI[i][m++] = dummy[j];
	}
}


void SET() {
  int i, j;
  for(i = 0; i<R; i++){
	  for(j = 0; j<C; j++){
          MAP[i][j] = '?';
		  TEMP[i][j] = 0;
	  }
  }
}


void Print(int c) {
  int i, j, k;
  for(i = 0; i<R; i++) {
    for(k = 0; k<C; k++) printf("%s",Sym);
	printf("|\n");
    for(j = 0; j<C; j++)
		printf("| %c ",MAP[i][j]);
	printf("|\n");
  }
  for(k = 0; k<C; k++) printf("%s",Sym);
	printf("|\n\n");
	printf("NUMBER OF MOVEMENTS: %d\n",c);


}

int main() {
  
  char input[100];
  int sr, sc, c;
 
   while(gets(input)) {
       sscanf(input,"%d%d",&R,&C);
	   if(!C && !R) break;
       printf("\n");
	   gets(input);
	   sscanf(input,"%d%d",&sr,&sc);
	   ReadCase();
	   SET();
	   c = SolvedCase(sr-1, sc-1);
	   Print(c);
	   
  }
	return 0;

}
