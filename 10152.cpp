#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXN 201

struct ss {
   int index;
   char Word[81];
}V[MAXN],Temp;

char W[MAXN][81];
int Pos[MAXN];
int N;

int com(const void *a, const void *b) {
       ss *x = (ss *)a;
	   ss *y = (ss *)b;
	   return strcmp(x->Word,y->Word);
}

void Sort() {
   int i;
   for(i = 0; i<N; i++)
	   V[i].index = i;
   qsort(V,N,sizeof(V[0]),com);

}

void Cal() {
  int i,x, min = 300, f = 0;
  int max = -10000;
  char First[100];
  strcpy(First,V[0].Word);
  Sort();
  ss *p;
  for(i = N-1; i>=0; i--) {
      strcpy(Temp.Word,W[i]); 
	  p = (ss *) bsearch(&Temp,V,N,sizeof(V[0]),com);
      x = p->index;
	  if(i == N-1)  { min = x; continue; }
	  if(x > min) {  
		  printf("%s\n",W[i]);
		  f = 1;
		  if(max<x)
		    max = x;
	  }
	  else if(x<max && f) { printf("%s\n",W[i]); }
	  else if(x < min )   min = x;

  }
  //if(!strcmp(W[0],First) && f)  printf("%s\n",First);
}


int main() {
   int i, kase;
   char dummy[100];
   gets(dummy);
   sscanf(dummy,"%d",&kase);
   while(kase--) {
       gets(dummy);
	   sscanf(dummy,"%d",&N);
	   for(i = 0; i<N; i++)
		   gets(V[i].Word);
	   for(i = 0; i<N; i++) 
			gets(W[i]);
  
	   Cal();
	   printf("\n");
   }
	return 0;

}
