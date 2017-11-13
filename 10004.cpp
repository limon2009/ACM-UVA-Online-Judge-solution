#include<stdio.h>
#include<string.h>

#define MAXN 202

char Link[MAXN][MAXN];
int N, E;

struct SS {
   char color;
}V[MAXN];

int Q[MAXN], QH, QT;

void Push(int n) {
   Q[QH++] = n;
   QH %= MAXN;
}

int  Pop() {
  int n = Q[QT++];
  QT %= MAXN;
  return n;
}

int IsEmpty() {
  return QH == QT;
}


int BFS(int s) {
    int i, j, u;
    char co;
    V[s].color = 'w';
    QH = QT = 0;
    Push(s);
    while(!IsEmpty()) {
	u = Pop();
	co = 'w';
	if(V[u].color == 'w')
	   co = 'b';
	for(i = 0; i<N; i++) {
	   if(Link[i][u] ==1) {
	       if(V[i].color == 'g') {
		  V[i].color = co;
		  Link[i][u] = Link[u][i] = 0;
		  Push(i);

	       }
	       else if(V[i].color == V[u].color) return 0;
	   }
       }
    }
    return 1;
}

void Cal(int s)  {
    int i, j;
    for(i = 0; i<=N; i++)
      V[i].color = 'g';
    if(BFS(s))  printf("BICOLORABLE.\n");
    else printf("NOT BICOLORABLE.\n");

}



int main() {
   int i, a, b, s;
   while(1) {
       scanf("%d",&N);
       if(!N) break;
       scanf("%d",&E);
       for(i = 0; i<E; i++) {
	  scanf("%d%d",&a, &b);
	  Link[a][b] = Link[b][a] = 1;
	  s = a;
       }
       Cal(s);
       for(i = 0; i<MAXN; i++)
	 memset(Link[i],0,sizeof(char) * 201);
   }
	return 0;

}
