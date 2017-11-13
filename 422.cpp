#include<stdio.h>
#define MAXN 101

int N,R,C;
char MAP[MAXN][MAXN];
char W[101];

int HF(int r,int c) {
  int i,j;

  for(i = 0; W[i]; i ++)
    if(W[i] != MAP[r][c++]) return 0;
  R = r;
  C = c-1;
  return 1;
}

int HB(int r,int c) {
  int i,j;

  for(i = 0; W[i]; i ++) {
   if(c<0) return 0;
     if(W[i] != MAP[r][c--]) return 0;
  }
  R = r;
  C = c+1;
  return 1;
}

int VF(int r,int c) {
  int i,j;

  for(i = 0; W[i]; i ++)  {
    if(r>=N) return 0;
    if(W[i] != MAP[r++][c]) return 0;
  }
  R = r-1;
  C = c;
  return 1;
}

int VB(int r,int c) {
  int i,j;

  for(i = 0; W[i]; i ++) {
    if(r<0) return 0;
    if(W[i] != MAP[r--][c]) return 0;
  }
  R = r+1;
  C = c;
  return 1;
}

int DWN(int r,int c) {
  int i,j;

  for(i = 0; W[i]; i ++) {
    if(r<0 ||c<0) return 0;
    if(W[i] != MAP[r--][c--]) return 0;
  }
  R = r+1;
  C = c+1;
  return 1;
}

int DNE(int r,int c) {
  int i,j;

  for(i = 0; W[i]; i ++) {
    if(r<0 || c>=N) return 0;
    if(W[i] != MAP[r--][c++]) return 0;
  }
  R = r+1;
  C = r-1;
  return 1;
}

int DES(int r,int c) {
  int i,j;

  for(i = 0; W[i]; i ++) {
    if(r>=N ||c>=N) return 0;
    if(W[i] != MAP[r++][c++]) return 0;
  }
  R = r-1;
  C = c-1;
  return 1;
}

int DSW(int r,int c) {
  int i,j;

  for(i = 0; W[i]; i ++) {
    if(r>=N ||c<0) return 0;
    if(W[i] != MAP[r++][c--]) return 0;
 }
  R = r-1;
  C = c+1;
  return 1;
}


int FIND(int r,int c) {

   if(HF(r,c))
     return 1;
   else if(HB(r,c))
     return 1;
   else if(VF(r,c))
     return 1;
   else if(VB(r,c))
     return 1;
   else if(DWN(r,c))
     return 1;
   else if(DNE(r,c))
     return 1;
   else if(DES(r,c))
     return 1;
   else if(DSW(r,c))
     return 1;
   return 0;
}




void COM()  {

	int i,j,k;
	for(i = 0; i<N; i ++) {
	  for(j = 0; j<N; j++) {
	    if(MAP[i][j] == W[0]) {
		 if(FIND(i,j)){
		   printf("%d,%d %d,%d\n",i+1,j+1,R+1,C+1);
		   return;
		 }
	    }
	  }
	}
       printf("Not found\n");
}



int main() {

      int k,i,c = 0;
      char input[50];

      while(1)  {

	  if(c == 0) {
	    gets(input);
	    sscanf(input,"%d",&N);
	  }

	  if(!N) break;
	  for(i =0 ; i<N; i ++)
	    gets(MAP[i]);
	  while(1)  {
	    gets(W);
	    k = sscanf(W,"%d",&N);
	    if(k != 0) break;
	    COM();
	  }
	  c ++;
      }
	return 0;

}
