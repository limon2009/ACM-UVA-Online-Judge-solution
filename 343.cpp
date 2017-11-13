#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 38

char BASE[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int VALUE[200];
char X[MAXN],Y[MAXN];
char temp[250],temp1[250];
int I,J;

struct ST {
      long long STORE;
      int BS;

} V[MAXN],W[MAXN];


void GETVALUE()  {
   int i,j;
   for(i = 0; BASE[i]; i ++) {
     j = BASE[i];
     VALUE[j] = i;
   }
}


int  MAX(char x[])  {
   int i,mx = 0,j;
   for(i = 0;x[i]; i++) {
     j = x[i];
     if(mx<VALUE[j])
       mx = VALUE[j];
   }
   if(mx == 0) mx = mx+1;
   return mx;

}

long long POW(int b, int p) {
   int i, j;
   long long k = 1;
   for(i = 1; i<=p; i ++)
     k *= b;
   return k;
}
long long NUMBER(char x[],int base) {

     int i,j,L,m,p = 0;
     long long sum = 0,f;
     L = strlen(x) - 1;
     for(i = L; i>=0; i --)  {
       j = x[i];
       m = VALUE[j];
       f = POW(base,p) * m;
       sum += f;
       p++;
    }
    return sum;
}


void CONVERT1(char x[])  {

	 int i,max;
	 I = 0;
	 max = MAX(x);
	 for(i = max+1; i<= 36; i ++) {
	    V[I].STORE = NUMBER(x,i);
	    V[I].BS = i;
	    I ++;
	 }
}

void CONVERT2(char x[])  {
	 int i,max;
	 J = 0;
	 max = MAX(x);
	 for(i = max+1; i<= 36; i ++) {
	   W[J].STORE  = NUMBER(x,i);
	   W[J].BS = i;
	   J ++;
	}

}

int COMPARE()  {

      int i,j;
      for(i = 0; i<I; i ++) {
	for(j = 0; j<J; j ++) {
	  if(V[i].STORE == W[j].STORE) {
	    printf("%s (base %d) = %s (base %d)\n",temp,V[i].BS,temp1,W[j].BS);
	    return 1;
	  }
	 if(V[i].STORE<W[J].STORE) break;
       }
     }
     return 0;

}

int main()  {

      int i,j;
      GETVALUE();
      while(scanf("%s%s",X,Y) != EOF) {
	    strcpy(temp,X);
	    strcpy(temp1,Y);
	    CONVERT1(X);
	    CONVERT2(Y);
	    j = COMPARE();
	    if(j == 0)
	     printf("%s is not equal to %s in any base 2..36\n",temp,temp1);

	    for(i = 0; i<=36; i ++) {
	      V[i].STORE = 0;
	      V[i].BS = 0;
	      W[i].STORE = 0;
	      W[i].BS = 0;
	    }
      }
	return 0;

}
