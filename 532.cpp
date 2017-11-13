#include<stdio.h>
#include<string.h>

#define MAXN 27002

int X[] = {0,0,1,-1};
int Y[] = {1,-1,0,0};
 
int QH, QT, R, C, D;
int SR, SC, SD;
char V[31][31][31];

struct ss{
	int r, c, d, l;
}Q[MAXN];

void Push(int r, int c, int d, int l){
	   Q[QH].r = r;
	   Q[QH].c = c;
	   Q[QH].d = d;
	   Q[QH++].l = l;
	   QH %= MAXN;
}

ss Pop() {
  ss x;
  x.r = Q[QT].r;
  x.c = Q[QT].c;
  x.d = Q[QT].d;
  x.l = Q[QT].l;
  QT++;
  QT %= MAXN;
  return x;
}

int IsEmpty() {
  return QH == QT;
}


int BFS() {
	int i;
	int r, c, d;
	ss p;
	QH = QT = 0;
	V[SD][SR][SC] = 'v';
	Push(SR,SC,SD,0);

	while(!IsEmpty()) {
		p = Pop();
		r = p.r; c = p.c; d = p.d;
        for(i = 0; i<4; i++) {
		   r = p.r+X[i];
		   c = p.c+Y[i];
           if(r<R && r>=0 && c<C && c>=0){
			    if(V[d][r][c] == 'E') {
					   return p.l+1;
				}
			   if(V[d][r][c] == '.') {
				  
				  V[d][r][c] = 'v';
				  Push(r,c,d,p.l+1);
			   }
		   }
		}
		d = p.d+1;
		if(d<D) {
		   if(V[d][p.r][p.c] == 'E') return p.l+1;
		   if(V[d][p.r][p.c] == '.') {
				V[d][p.r][p.c] = 'v';
				Push(p.r,p.c,p.d+1,p.l+1);
		   }
		}
		d = p.d-1;
		if(d>=0) {
		   if(V[d][p.r][p.c] == 'E') return p.l+1;
		   if(V[d][p.r][p.c] == '.') {
			   V[d][p.r][p.c] = 'v';
			   Push(p.r,p.c,p.d-1,p.l+1);
		   }
		}
	}
  return 0;
}

void SolvedCase() {
   int time;
   time = BFS();
   if(time) printf("Escaped in %d minute(s).\n",time);
   else printf("Trapped!\n");
  
}

void ReadCase() {
   int i, j, k, f = 1;
   for(i = 0; i<D; i++) {
	   for(j = 0; j<R; j++){ 
		   scanf("%s",V[i][j]);
			if(!f) continue;
			for(k = 0; V[i][j][k]; k++){
				if(V[i][j][k] == 'S') {
					SR = j;
					SD = i;
					SC = k;
					f = 0;
					break;
				}
			}
		}
   }
}

int main() {
    while(scanf("%d%d%d",&D,&R,&C) == 3) {
	  if(!R&&!C&&!D) break;
	  ReadCase();
	  SolvedCase();
	}
	return 0;

}
