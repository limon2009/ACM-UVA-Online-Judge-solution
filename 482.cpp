#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 100000
char input1[MAXN+MAXN];
char input2[MAXN+MAXN];
int I,J;
struct per {
	int val;
	char x[20];
}V[MAXN];

int com(const void *a, const void *s){
	 per *c = (per *)a;
	 per *d = (per *)s;
	 return c->val - d->val;
}

void Sep1() {
   int i, c = 0, k, m = 0;
   char value[100];
   for(i = 0; input1[i]; ) {
	   if(input1[i] != ' ') {
              value[m++] = input1[i++];
			  c = 1;
			  k  = 1;
	   }
       else if(c && input1[i] == ' '){
		   value[m] = NULL;
		   V[I++].val = atoi(value);
       for(i++; input1[i] && input1[i] == ' '; i++);
		   m = 0;
		   k = 0;
	   }
	   else i++;
   }
   if(k) value[m] = NULL;
   V[I++].val = atoi(value);
}


void Sep2() {
   int i, c = 0, k, m = 0;
   char value[100];
   for(i = 0; input2[i]; ) {
	   if(input2[i] != ' ') {
              value[m++] = input2[i++];
			  c = 1;
			  k  = 1;
	   }
       else if(c && input2[i] == ' '){
		   value[m] = NULL;
		   strcpy(V[J++].x,value);
       for(i++; input2[i] && input2[i] == ' '; i++);
		   m = 0;
		   k = 0;
	   }
	   else i++;
   }
   if(k) value[m] = NULL;
    strcpy(V[J++].x,value);
}


void sort() {
qsort(V,I,sizeof(V[0]),com);
for(int i = 0; i<I;i++)
 printf("%s\n",V[i].x);

}

int main() {
	char set[10];
	int kase,j = 0;
  gets(set);
	sscanf(set,"%d",&kase);
	gets(set);
	while(kase--) {
	  I = J = 0;
	  gets(input1);
	  gets(input2);
	  Sep1();
	  Sep2();
	  sort();
    if(kase){ putchar('\n');gets(input1);}
	}
	return 0;

}
