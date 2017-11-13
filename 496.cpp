#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000000
	  /*1000000*/
#define MAXN 10000
	     /*10000*/
char Line1[MAX];
char Line2[MAX];
char Set1[MAXN][20];
char Set2[MAXN][20];
int K,M,C;

int com(const void *a, const void *s)  {
      return strcmp( (char *)a, (char *)s );
}


void Sep1() {
  int i, j = 0, p;
  K = 0;
  p = 0;
  for(i = 0; Line1[i]; )  {
    if(Line1[i] !=' ') {
       Set1[K][j++] = Line1[i++];
       p = 1;
    }
    else if(p)  {
      Set1[K][j] = NULL;
      j = 0;
      K++;
      for(i++;Line1[i] ==' ' && Line1[i]; i++);
      p = 0;
   }
   else i++;
  }
 if(p) Set1[K++][j] = NULL;
}

void Sep2() {
  int i, j = 0, p;
  M = 0;
  p = 0;
  for(i = 0; Line2[i]; )  {
    if(Line2[i] !=' ') {
       Set2[M][j++] = Line2[i++];
       p = 1;
    }
    else if(p)  {
      Set2[M][j] = NULL;
      j = 0;
      M++;
      for(i++;Line2[i] ==' ' && Line2[i]; i++);
      p = 0;
    }
    else i++;
  }
 if(p) Set2[M++][j] = NULL;
}

int IsEuqal()  {
   int i, *j;
   for(i = 0; i<M; i ++) {
      j = (int *)  bsearch(&Set2[i],Set1,K,sizeof(Set1[0]),com);
      if(j == 0)
	 return 0;
  }
  return 1;
}

int Subset1() {
	  int i, *j;
	  for(i = 0; i<M; i ++) {
	     j = (int *)  bsearch(&Set2[i],Set1,K,sizeof(Set1[0]),com);
	     if(j == 0)
	       return 0;
	  }
  return 1;
}


int Subset2() {
	  int i, *j;
	  for(i = 0; i<K; i ++) {
	     j = (int *)  bsearch(&Set1[i],Set2,M,sizeof(Set2[0]),com);
	     if(j == 0)
	       return 0;
	  }
  return 1;
}

int Disjoint()  {
  int i, *j;
  for(i = 0; i<K; i ++) {
       j = (int *)  bsearch(&Set1[i],Set2,M,sizeof(Set2[0]),com);
       if(j != 0)
	 return 1;
  }
  return 0;
}

void COM()  {

    qsort(Set1,K,sizeof(Set1[0]),com);
    qsort(Set2,M,sizeof(Set2[0]),com);
    if(K==M && IsEuqal()) printf("A equals B\n");
    else if(K>M && Subset1()) printf("B is a proper subset of A\n");
    else if(M>K && Subset2()) printf("A is a proper subset of B\n");
    else if(!Disjoint()) printf("A and B are disjoint\n");
    else printf("I'm confused!\n");
}
int main()  {
       while(gets(Line1))  {
	 gets(Line2);
	 Sep1();
	 Sep2();
	 COM();
       }
	return 0;

}
