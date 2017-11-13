#include <stdio.h>
#define MAXN 10

int MOVEY[] = {-2,-2,-1,-1,+1,+1,+2,+2};
int MOVEX[] = {-1,+1,-2,+2,-2,+2,-1,+1};
int MARK[MAXN][MAXN];
int VALUE[200];
int MIN;
int R, C;

void generate()  {
    char i,c = 0;
    for(i = 'a'; i <= 'h'; i ++) {
      c ++;
      int d = i;
      VALUE[d] = c;
    }
}

int recur(int r, int c, int level) {

	if (r <= 0 || c <= 0 || r> 8 || c>8) return 0;
	if (MARK[r][c]==1) return 0;

	if(level >= MIN) return 0;
	MARK[r][c] = 1;

	if(r == R && c == C) {
	  MARK[r][c] = 0;
	  return 1;
	}
	if (level == 64) {
		MARK[r][c] = 0;
		return 0;
	}

	for (int i=0; i<8; i++) {
		int newr = r+MOVEY[i];
		int newc = c+MOVEX[i];
		if (recur(newr,newc,level+1)) {
			MARK[r][c] = 0;
			if(level == 1) { MIN = 1; return 1;}
			if(level < MIN)
			  MIN = level;
		}
	}

	MARK[r][c] = 0;
	return 0;
}





int  main() {

	int r, c;
	int i, j;
	char P[5],Q[5];
	generate();
	while(scanf("%s%s",P,Q) != EOF) {

	  MIN = 100;
	  r = P[1] - '0';
	  c = VALUE[P[0]];
	  R = Q[1] - '0';
	  C = VALUE[Q[0]];
	  if(r == R && c == C)
	    MIN = 0;
	  else
	    recur(r,c,1);
	  printf("To get from %s to %s takes %d knight moves.\n",P,Q,MIN);

	}
	return 0;

}
