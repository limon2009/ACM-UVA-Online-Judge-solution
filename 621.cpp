#include<stdio.h>
#include<string.h>

#define MAXN 10000

char S[MAXN];

int Pos() {
   if(!strcmp(S,"1")) return 1;
   else if(!strcmp(S,"4")) return 1;
   else if(!strcmp(S,"78")) return 1;
   return 0;
}

int Neg() {
      int l = strlen(S);
      if(l<3) return 0;
      if(S[l-1] == '5' && S[l-2] == '3') return 1;
      return 0;
}

int Fail() {
       int l = strlen(S);
       if(l<3) return 0;
       if(S[0] == '9' && S[l-1] == '4') return 1;
       return 0;
}

int Incom() {
       int l = strlen(S);
       if(l<4) return 0;
       if(S[0] == '1' && S[1] == '9' && S[2] == '0') return 1;
       return 0;
}

void Cal() {
   if(Pos()) { printf("+\n"); return; }
   else if(Neg()) { printf("-\n"); return; }
   else if(Fail()) { printf("*\n"); return; }
   else if(Incom()) { printf("?\n"); return; }

}
int main() {
    int n;
    scanf("%d",&n);
    while(n -- ) {
	scanf("%s",S);
	Cal();
    }
	return 0;

}
