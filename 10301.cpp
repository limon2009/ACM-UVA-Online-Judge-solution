#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAXN 102

int N, MAX;
char Link[MAXN][MAXN];

struct SS {
   double x;
   double y;
   double r;
} Ring[MAXN];

struct DD {
   char co;
}V[MAXN];

int Inside(int  m, int n, double dis) {
    double x;
    x = Ring[m].r - dis;
    if(x <= Ring[n].r) return 1;
    return 0;
}

int OverLap(int m, int n) {
    double dis, R;
    dis = sqrt(pow((Ring[m].x - Ring[n].x),2) + pow((Ring[m].y - Ring[n].y),2));
    if(dis<= Ring[m].r|| dis <= Ring[n].r)  {
	if(Ring[m].r> Ring[n].r) {
	   if(Inside(m,n,dis)) return 1;
	   else return 0;
	}
	else {
	  if(Inside(n,m,dis)) return 1;
	  else return 0;
	}
    }
    R = Ring[m].r + Ring[n].r;
    if(dis < R)  return 1;
    return 0;
}


void MakeLink() {
     int i, j;
     for(i = 0; i<N-1; i++)
	for(j = i+1; j<N; j++)
	    if(OverLap(i,j))
	       Link[i][j] = Link[j][i] = 1;
}



void DFS(int n) {
   V[n].co = 'b';
   MAX ++;
   for(int i = 0; i<N; i++) {
      if(Link[n][i] == 1 && V[i].co == 'w')
	  DFS(i);
   }
}


void Cal() {
      int i, max = 0, p;
      for(i = 0; i<N; i++)
	 V[i].co = 'w';
      for(i = 0; i<N; i++) {
	 if(V[i].co == 'w') {
	    MAX = 0;
	    DFS(i);
	    if(max<MAX) max = MAX;
	   
	 }
     }
      if(max ==1 )
     printf("The largest component contains %d ring.\n",max);
	  else printf("The largest component contains %d rings.\n",max);


}


int main() {
      int i;

      while(scanf("%d",&N) == 1) {
	 if(N==-1 ) break;
	 for(i = 0; i<N; i++)
	   scanf("%lf%lf%lf",&Ring[i].x,&Ring[i].y,&Ring[i].r);
	 MakeLink();
	 Cal();
	 for(i = 0; i<MAXN;i++) memset(Link[i],0,sizeof(char) * 100);
      }
	return 0;

}
