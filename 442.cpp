#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXN 10000

char Stack[MAXN];
char Exp[MAXN];
int Top, N, G;
long long SS;
struct Mat {
  int R;
  int C;
}M[27];

struct Temp {
  int R;
  int C;
}mm[27];

void Push(char c) {
  Stack[Top++] = c;
}


int Count() {
   int i, j, p, q ;
   char c;
   long long Pro;
   p = Stack[Top-1] - 'A';
   q = Stack[Top-2] - 'A';
   c = Stack[Top-2];
   if(mm[q].C != mm[p].R) return 0;
   Pro = mm[q].R * mm[q].C * mm[p].C;
   mm[q].R = mm[q].R;
   mm[q].C = mm[p].C;
   SS+= Pro;
   Top -= 3;
   Push(c);
   return 1;
}

void Cal() {
   int i, j;
   for(i = 0; Exp[i]; i++) {
      if(Exp[i] == '(') Push(Exp[i]);
      else if(isalpha(Exp[i])) Push(Exp[i]);
      else if(Exp[i] == ')') {
	 j = Count();
	 if(!j)  { printf("error\n"); return; }
      }
   }
  printf("%lld\n",SS);
}



int main() {
   int a, b, d, i;
   char C[10], ss[150];
    gets(ss);
   sscanf(ss,"%d",&N);
   for(i = 0; i<N; i++)  {
      gets(ss);
      sscanf(ss,"%s%d%d",C,&a, &b);
	d = C[0] - 'A';
	M[d].R = a;
	M[d].C = b;
   }
   while(gets(Exp)) {
      if(strlen(Exp) <= 1) {
	   printf("0\n");
	   continue;
      }
      Top = G = SS = 0;
      for(i = 0; i<27; i++)  {
	 mm[i].R = M[i].R;
	 mm[i].C = M[i].C;
      }
      Cal();
  }
	return 0;

}
