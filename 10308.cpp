#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 10002

int Mnode, Mdis;
int Q[MAXN], QH, QT;

struct node{
  int name;
  int Val;
  node *next;
};

struct Edge {
	int tempVal;
	char colur;
	node *next;
}V[MAXN];


int AddEdge(int n, int m, int v) {
   node *p = (node*)malloc(sizeof(node));
   node *x = (node*)malloc(sizeof(node));
   V[m].tempVal = V[n].tempVal = 0;
   p->name = m;
   p->Val = v;
   p->next = V[n].next;
   V[n].next = p;
   x->name = n;
   x->Val = v;
   x->next = V[m].next;
   V[m].next = x;
   return 0;
}


void Push(int n) {
  Q[QH++] = n;
  QH %= MAXN;
}

int Pop() {
  int n;
  n = Q[QT++];
  QT %= MAXN;
  return n;
}

int IsEmpty() {
  return QH == QT;
}

int  BFS(int st) {
   int i, j, k, v;
   int max = -1, start;
   for(i = 1; i<=Mnode; i++){
	   V[i].colur = 'w';
       V[i].tempVal = 0;
   }
   QH = QT = 0;
   V[st].colur = 'r';
   Push(st);
   while(!IsEmpty()) {
       k = Pop();
	   node *vpt = V[k].next;
	   while(vpt != NULL) {
	      j = vpt->name;
		  v = vpt->Val;
		  if(V[j].colur != 'r') {
		     i = V[k].tempVal + v;
			 if(i>max) { max = i; start = j; Mdis = max; }
			 V[j].tempVal = i;
			 V[j].colur = 'r';
			 Push(j);
		  }
		  vpt = vpt->next;
	   }

   }
   return start;
}

int Cal(int n) {
    int k;
	k = BFS(n);
	if(k == 0){ printf("0\n"); return 0; }
	BFS(k);
	printf("%d\n",Mdis);
	return 0;

}


void Free(node *x) {
   if(x == NULL) return;
   Free(x->next);
   free(x);
}

int FREE() {
	int i;
	for(i = 1; i<= Mnode; i++) {
	   node *p = V[i].next;
	   Free(p);
	}
	return 0;
}

int main() {
    char input[100];
	int m , n, v, i;
  //  freopen("c:\\input.txt","r",stdin);
	while(gets(input)) {
	   Mnode = 0;
	   n = m = v = 0;
	   sscanf(input,"%d%d%d",&n,&m,&v);
	   if(n == 0) { printf("0\n"); gets(input); continue; }
	   AddEdge(n,m,v);
	   if(n > Mnode) Mnode = n;
	   if(m > Mnode) Mnode = m;
	   while(gets(input)) {
	     
		 for(i = 0; input[i]; i++) 
			 if(input[i] == '\n')
				 input[i] = NULL;
			 if(strlen(input)<=0) break;
			 sscanf(input,"%d%d%d",&n,&m,&v);
			 AddEdge(n,m,v);
			 if(n > Mnode) Mnode = n;
			 if(m > Mnode) Mnode = m;
	   }
	   Cal(n);
//	   FREE();
	   for(i = 1; i<=Mnode; i++) V[i].next = NULL;
	}
	return 0;
}
