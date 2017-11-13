#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 83683

struct ss {
   int index;
   char str[6];
}V[MAXN], W;



int com1(const void *t, const void *u) {
   ss *x = (ss *)t;
   ss *y = (ss *)u;
   if(strcmp(x->str,y->str)>0) return 1;
   if(strcmp(x->str,y->str)<0) return -1;
   return 0;
}

int x;

void Gen() {
  x = 0;
  char a, b, c, d, e;
  for(a = 'a'; a<='z'; a++) {
	  V[x].str[0] = a;
	  V[x].index = x+1;
	  V[x++].str[1] = NULL;
  }
  for(a= 'a'; a<'z'; a++){
	  for(b = a+1; b<='z'; b++){
		  V[x].str[0] = a;
		  V[x].str[1] = b;
		  V[x].str[2] = NULL;
		  V[x].index = x+1;
		  x++;
	  }
  }


  for(a= 'a'; a<'z'-1; a++){
	  
	  for(b = a+1; b<'z'; b++){
		  
		  for(c = b+1; c<='z'; c++){
			  V[x].str[1] = b;
			  V[x].str[0] = a;
			  V[x].str[2] = c;
			  V[x].str[3] = NULL;
			  V[x].index = x+1;
			  x++;
		  }
	  }
  }

  for(a= 'a'; a<'z'-2; a++){
	   for(b = a+1; b<'z'-1; b++){
		  for(c =b+1; c<'z'; c++){
	    	  for(d = c+1; d<='z'; d++){
				  V[x].str[1] = b;
				  V[x].str[2] = c;
				  V[x].str[0] = a;
				  V[x].str[3] = d;
				  V[x].str[4] = NULL;
				  V[x].index = x+1;
				  x++;
			  }
		  }
	  }
  }

  for(a= 'a'; a<'z'-3; a++){
	  
	  for(b = a+1; b<'z'-2; b++){ 
			V[x].str[1] = b;
		  for(c =b+1; c<'z'-1; c++){
			  V[x].str[2] = c;
			  for(d = c+1; d<'z'; d++){
				  V[x].str[3] = d;
				  for(e = d+1; e<='z'; e++){
					  V[x].str[0] = a;
					  V[x].str[1] = b;
					  V[x].str[2] = c;
					  V[x].str[3] = d;
					  V[x].str[4] = e;
					  V[x].str[5] = NULL;
					  V[x].index = x+1;
					  x++;
				  }
			  }
		  }
	  }
  }
 
}


void Cal() {
  
  int i, j;
  qsort(V,83681,sizeof(V[0]),com1);
  ss *p;
  while(gets(W.str)) {
	  if(strlen(W.str)>5) { printf("0\n"); continue; }
	  j = 0;
	  for(i = 1; W.str[i]; i++) {
		  if(W.str[i] < W.str[i-1]) {
			  j = 1; 
			  break;
		  }
	  }
	  if(j) {  printf("0\n"); continue; }
	  p = (ss *)bsearch(&W,V,83681,sizeof(V[0]),com1);
	  if(p) {
		  j = p->index;
		  printf("%d\n",j);
	  }
	  else printf("0\n");
  }
}

int main() {
 Gen();
 Cal();
	return 0;

}
