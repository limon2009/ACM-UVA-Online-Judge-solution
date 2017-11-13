#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define MAXN 1000000

struct ss {
	int fre;
	int ascii;
}In[130],En[130];

char Input[MAXN];
char Encode[MAXN];
int  Dummy[130];

int comin(const void *a ,const void *b) {
   ss *x = (ss *)a;
   ss *y = (ss *)b;
   if(x->fre > y->fre) return -1;
   else if(x->fre < y->fre) return 1;
   return 0;
}

 
void Count1() {
   int i, j;
   for(i = 0; Input[i]; i++) {
      if(!isalpha(Input[i])) continue;
	  j = Input[i];
      In[j].fre ++;
   }
}
void Count2(){ 
   int i, j;
   for(i = 0; Encode[i]; i++) {
      if(!isalpha(Encode[i])) continue;
	  j = Encode[i];
      En[j].fre ++;
   }
}


void Cal() {
   int i, j, k;
   for(i = 0; i<130; i++)
	   In[i].ascii = En[i].ascii = i;
   qsort(In,130,sizeof(In[0]),comin);
   qsort(En,130,sizeof(En[0]),comin);
   for(i = 0; i<130; i++) {
       j = In[i].ascii;
	   k = En[i].ascii;
	   Dummy[k] = j;
   }
   for(i = 0; Encode[i]; i++ ){
       if(!isalpha(Encode[i])) {
	      printf("%c",Encode[i]);
		  continue;
	   }
       j = Encode[i];
	   printf("%c",Dummy[j]);
	  
   }
   printf("\n");
}


int main() {
	char Blank[100];
    int kase;
	gets(Blank);
	sscanf(Blank,"%d",&kase);
	gets(Blank);
	while(kase -- ){
		gets(Input);
		assert(strlen(Input) < MAXN);
		gets(Encode);
		assert(strlen(Encode) < MAXN);
		Count1();
		Count2();
		Cal();
		if(kase) {
		   gets(Blank);
		   printf("\n");
		   for(int i = 0; i<130; i++)
			   In[i].fre = En[i].fre = 0;
		}
	}
	return 0;

}
