#include<stdio.h>

#define MAXN 27
#define MAX  100
char city1[100000],city2[100000];
char FL[MAXN][MAXN];
struct Vertex{
   int  pr;
   char cl;
}  V[MAXN];

int QH,QT,Q[MAX];

int IsEmpty() {
 return QH == QT;
}

int pop() {
   int x = Q[QT++];
   QT %= MAX;
   return x;
}

void push(int n)  {
  Q[QH++] = n;
  QH %= MAX;
}

void BFS(int st , int ter)  {
   int i,j,u;
   for(i = 0; i<MAXN; i++)
     V[i].cl = 'W';
   V[st].cl = 'G';
   QH = QT = 0;
   push(st);
   while(!IsEmpty()) {
      u = pop();
      for(i = 0; i<MAXN;i ++)  {
	 if(FL[u][i] && V[i].cl == 'W')  {
	    V[i].pr = u;
	    V[i].cl = 'G';
	    if(ter == i) return;
	    push(i);
	 }
      }
   }
}

void PrintPath(int s,int t) {
   if(s == t) {
     printf("%c",s+'A');
     return;
   }
   else PrintPath(s,V[t].pr);
      printf("%c",t+'A');
}


int main()  {
     int i, j, kase, nt, q;
     int a, b;
     scanf("%d",&kase);
     while(kase --)  {
	 scanf("%d%d",&nt,&q);
	 for(i = 0; i<nt; i ++) {
	   scanf("%s%s",city1,city2);
	   a = city1[0] - 'A';
	   b = city2[0] - 'A';
	   FL[b][a] = FL[a][b] = 1;
	 }
	 while(q--)  {
	   scanf("%s%s",city1,city2);
	   a = city1[0] - 'A';
	   b = city2[0] - 'A';
	   if(a == b) continue;
	   BFS(a,b);
	   PrintPath(a,b);
	   printf("\n");
	 }
	 if(kase) printf("\n");
	 for(i = 0; i<MAXN;i ++)
	   for( j= 0; j<MAXN; j++)
	    FL[i][j] = 0;
     }
	return 0;

}
