#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 100
   /* 1000*/

char STR[85],MID[85];
char STORE[MAXN][81];
int K,M;


int com(const void *a , const void *b) {
   return strcmp( (char *)a, (char *)b );
}


int ISPAL(int s, int f)  {
  int i,j,n,m;
  n = (s + f)/ 2;
  m = n;
  if(strlen(STR) % 2 == 0)
   m = n+1;
  for(i = s,j = f;i<=n,j>=m;i++,j--)
    if(STR[i] != STR[j]) return 0;

  return 1;
}


int UNLETTER(char str[])  {
  int i, j, k = 0;
  char c;
  for(i = 0; str[i]; i ++) {
    if(str[i] == '#') continue;
    k ++;
    for(j = i +1; str[j]; j ++)
      if(str[i] == str[j])
	 str[j] = '#';
  }
  return k;
}


int ISUNIQUE() {
    int i,j,k;
    int *p;
    p =  (int *)bsearch(&MID, STORE,M,sizeof(STORE[0]),com);
    if(p == 0)  {
      strcpy(STORE[M++],MID);
      qsort(STORE,M,sizeof(STORE[0]),com);
      return 1;
    }
    return 0;
}

int PALLIN()  {
   int i, j, k;
   for(i = 0; STR[i]; i ++) {
     for(j = i+1; STR[j]; j ++) {
       if(STR[i] == STR[j])
	   if(ISPAL(i,j)){
	      k = 0;
	      for(int m = i; m<=j; m ++)
		 MID[k++] = STR[m];
	      MID[k] = NULL;
	      if(ISUNIQUE())
		 K ++;
	   }
     }
   }
   char x[81];
   strcpy(x,STR);
   k = UNLETTER(x);
   printf("The string '%s' contains %d palindromes.\n",STR,K+k);
   return 0;
}

int main() {
  while(scanf("%s",STR) != EOF)  {
     K = 0;
     M = 0;
     PALLIN();

  }
 return 0;
}
