#include<stdio.h>
#include<ctype.h>
#define MAXN 50


char BOARD[MAXN];
char MARK[10][10];
char PLACE[10][10];
int MOVEY[] = {-2,-2,-1,-1,+1,+1,+2,+2};
int MOVEX[] = {-1,+1,-2,+2,-2,+2,-1,+1};
char P1[] = "PNRBQK";
char P2[] = "pnrbqk";

int islegal(char ch,int r,int c) {
      int i, j;
      if(r>7 || c>7 || r<0 || c<0) return 0;
      for(i = 0; P1[i]; i ++)
	if(ch == P1[i] || ch == P2[i]) return 1;

      return 0;
}


void BISHOP(int r,int c)  {
   int i, j;
   for( i = r-1, j = c-1; i>=0 && j>=0; i--,j--) {
     if(isalpha(PLACE[i][j])) break;
     MARK[i][j] = '1';
   }
   for( i = r-1, j = c+1; i>=0 && j<8; i--,j++) {
     if(isalpha(PLACE[i][j])) break;
     MARK[i][j] = '1';
   }
   i = r+1;
   j = c+1;
   while(1)  {
      if(i>7 || j>7) break;
      if(isalpha(PLACE[i][j])) break;
      MARK[i][j] = '1';
      i ++; j++;
  }
   i = r+1;
   j = c-1;
   while(1)  {
      if(j<0 || i>7) break;
      if(isalpha(PLACE[i][j])) break;
      MARK[i][j] = '1';
      i ++; j--;
  }
}



void ROCK(int r,int c)  {
   int i, j;
   j = c;
   for(j = c+1; j<8; j ++) {
     if(isalpha(PLACE[r][j])) break;
     MARK[r][j] = '1';
   }

   for(j = c-1; j>=0; j --) {
     if(isalpha(PLACE[r][j])) break;
     MARK[r][j] = '1';
   }

   for(j = r-1; j>=0; j --) {
     if(isalpha(PLACE[j][c])) break;
     MARK[j][c] = '1';
   }
   for(j = r+1; j<8; j ++) {
     if(isalpha(PLACE[j][c])) break;
     MARK[j][c] = '1';
   }
}

void KNIGHT(int r, int c)  {
  int i, j, x, y;
  for(i = 0; i<8; i ++)  {
      x = r + MOVEX[i];
      y = c + MOVEY[i];
      if(x<0 || x>7 || y>7 || y<0 ) continue;
      if(!isalpha(PLACE[x][y]))
	   MARK[x][y] = '1';
  }
}

void KING (int r, int c)  {
   int i, j, x, y;
   for(i = -1; i<2; i ++)
     for(j = -1; j<2; j ++)  {
	   if(r == 0 && c == 0) continue;
	   x = r+i;
	   y = c +j;
	   if(x>8 || x<0 || y>8 || y<0) continue;
	   if(!isalpha(PLACE[x][y]))
	     MARK[x][y] = '1';
    }
}

void PON(char ch,int r, int c) {
     int i, j;
    if(islower(ch))  {
	i = r+1;
	j = c-1;
	if(!isalpha(PLACE[i][j]) && i<8 && j>=0)
	  MARK[i][j] = '1';
	j = c+1;
	if(!isalpha(PLACE[i][j]) && i<8 && j<8)
	  MARK[i][j] = '1';
	return ;
     }

	i = r-1;
	j = c-1;
	if(!isalpha(PLACE[i][j]) && i>=0 && j>=0)
	  MARK[i][j] = '1';
	j = c+1;
	if(!isalpha(PLACE[i][j])&& i>=0 && j<8)
	  MARK[i][j] = '1';
}
void COM(char ch, int r, int c)  {

      if(ch == 'r' || ch == 'R')
	 ROCK(r,c);
      else if(ch == 'b'|| ch == 'B')
	 BISHOP(r,c);
      else if(ch =='N' || ch == 'n')
	 KNIGHT(r,c);
      else if(ch == 'Q' || ch == 'q')  {
	 ROCK(r,c);
	 BISHOP(r,c);
      }
      else if(ch == 'k' || ch == 'K')
	KING(r,c);
      else if(ch == 'p' || ch == 'P')
	PON(ch,r,c);
}


void SOLVED()  {
   int i = 0, r, c;
   r = c = 0;
   while(BOARD[i])  {
      if(BOARD[i] =='/') {
	r ++;
	c = 0;
      }
      if(r>7) break;
      else if(isdigit(BOARD[i])) {
	   c+= (BOARD[i] - '0') ;
	   if(c>7) c -= (BOARD[i] - '0') ;
      }
      else if(isalpha(BOARD[i]))
	if(islegal(BOARD[i],r,c)) {
	   PLACE[r][c] = BOARD[i];
	   MARK[r][c] = '1';
	   c++;
	}
       i ++;
   }
   for( i = 0; i<8; i ++)
    for( int j = 0; j<8; j ++)
      if(isalpha(PLACE[i][j]))
	 COM(PLACE[i][j],i,j);

}

int POSITION()  {
  int i, j, k =0;
  for(i = 0; i<8; i ++)
   for(j = 0; j<8; j ++)
     if(MARK[i][j] == '*')
      k++;
  return k;
}


int main()  {
    int i, j;
    while(gets(BOARD)) {
       for(i = 0; i<8;i ++)
	for(j = 0; j<8;j ++) {
	  MARK[i][j] = '*';
	  PLACE[i][j] = '*';
       }
       SOLVED();
       printf("%d\n",POSITION());


    }
	return 0;

}
