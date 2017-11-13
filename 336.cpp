#include<stdio.h>
#include<stdlib.h>

int ST[950];
int Store[100];
long PAIR1[440];
int PAIR2[440];
char FL[310][31];
int TTL, K;

struct Vertex {
	char cl;
	int d;
} V[320];
int Q[320], QH, QT;


int com(const void *a, const void * s) {

  return *(int *)a - *(int *)s;

}

int B_search(int key)  {
   int up = K-1,low = 0,mid;
   mid = (up + low) / 2;
   while(low<=up && Store[mid] != key)  {
      if(key > Store[mid])
	low = mid +1;
      else if(key<Store[mid])
	 up = mid - 1;
      mid = (up + low) / 2;
   }
   if(Store[mid] == key) return mid;
   return -1;
}



void PUSH(int n)  {
   Q[QH++] = n;
   QH %= 32;
}

int POP() {
  int n = Q[QT++];
  QT = QT % 32;
  return n;
}

int IsEmpty()  {
  return QH == QT;
}

void BFS(int j)  {
   int st, i, n, u;
   for(i = 0; i<K; i ++)
      V[i].cl = 'W';
   st = B_search(j);
   if(st == -1) return;
   V[st].cl = 'G';
   V[st].d = 0;
   QH = QT = 0;
   PUSH(st);
   while(!IsEmpty())  {
     u = POP();
     if(V[u].d == TTL) return;
     for(i = 0;i <K; i ++)
	if(V[i].cl == 'W' && FL[u][i])  {
	  V[i].cl = 'G';
	  V[i].d = V[u].d + 1;
	  PUSH(i);
	}
   }
}

void MAKELINK(int k,int N)  {
   int i, j, n, m;
   K = 0;
   qsort(ST,k,sizeof(int ),com);
   for(i = 1; i<k; i ++)
     if(ST[i] == ST[i-1])
	ST[i-1] = -1;
   qsort(ST,k,sizeof(int),com);
   for(i = 0; i<k; i ++)
     if(ST[i] != -1)
       Store[K++] = ST[i];

   for(i = 0;i<N; i ++)  {
     m = B_search(PAIR1[i]);
     n = B_search(PAIR2[i]);
     FL[n][m] = FL[m][n] = 1;
   }

}

int Unreachable()  {
 int i, g = 0;
 for(i = 0; i<K; i ++)
   if(V[i].cl == 'W')
     g ++;

 return g;
}

int main()  {

	int i, m, n, k, N, j, Kase = 1;
	while(scanf("%d",&N) && N)  {
	    k = 0;
	    for(i = 0; i<N; i ++)  {
	       scanf("%d%d",&m,&n);
	       ST[k] = m;
	       PAIR1[i] = ST[k];
	       k++;
	       ST[k] = n;
	       PAIR2[i] = ST[k];
	       k++;
	   }
	    MAKELINK(k,N);
	    while(scanf("%d%d",&j,&TTL) ==2)  {
	       if(j == 0 && TTL == 0) break;
	       BFS(j);
	       printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",Kase++,Unreachable(),j,TTL);
	    }
	    for(i = 0; i<32; i ++)
	      for(j = 0; j<32; j ++)
		FL[i][j] = 0;

	}
	return 0;

}
