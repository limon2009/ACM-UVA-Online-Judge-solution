#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 30

char G[MAXN][MAXN];
char Fl[50];
char LARGEST;

struct Vertex {
    char color;

} V[MAXN];
int Q[MAXN], QH, QT;

int isEmpty() {
	return QH==QT;
}
int pop() {
	int x = Q[QH++];
	QH %= MAXN;
	return x;
}
void push(int x) {
	Q[QT++] = x;
	QT %= MAXN;
}

void BFS(int s) {

	V[s].color = 'G';
	QH = QT = 0;

	push(s);
	while (!isEmpty()) {
		int u = pop();
		for (char v='A'; v<=LARGEST; v++) {
			int m = v-'A';
			if (V[m].color=='W' && G[u][m]==1) {
				V[m].color = 'G';
				push(m);
			}
		}
		V[u].color = 'B';
	}
}

void COMPUTE()  {
     char c;
     int i,count = 0,m;

     for (c='A'; c<=LARGEST; c++) {
	m = c - 'A';
	V[m].color = 'W';
	Fl[m] = 1;
     }
     for(c = 'A'; c<=LARGEST; c ++)  {
	i = c-'A';
	if(V[i].color == 'W')  {
	  count ++;
	  BFS(i);
	}
     }
     printf("%d\n",count);
}

int main() {

       char input[20];
       int kase,i,j,n;
       gets(input);
       sscanf(input,"%d",&kase);
       gets(input);
       while(kase --) {
	    gets(input);
	    LARGEST = input[0];
	    n = LARGEST - 'A';
	    Fl[n] = 1;
	    while(gets(input))  {
		for(i = 0;input[i]; i ++)
		  if(input[i] == '\n') input[i] = NULL;

		if(!strlen(input)) break;
		i = input[0] - 'A';
		j = input[1] - 'A';
		G[i][j] = 1;
		G[j][i] = 1;

	   }
	   COMPUTE();
	   for(i = 0; i<30; i ++)  {
	     Fl[i] = 0;
	     memset(G[i],0,30*sizeof(char));
	   }
	   if(kase>0) {
	      printf("\n");

	   }
       }
	return 0;

}
