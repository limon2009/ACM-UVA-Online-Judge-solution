#include<stdio.h>
#include<string.h>
#define MAXN 200

char B[MAXN], P[MAXN];

int Rem(int n) {
   int i, k, p, g = 0, j = 0;
   for(i = 0; P[i]; i ++) {
	   k = P[i] - '0';
	   p = j * g + k;
	   j = p % n;
	   g = 10;
   }
  return j;
}

void LastDigit(int b,int rem) {
    if(b == 2 ) {
       if(rem == 1) printf("2\n");
       else if(rem == 2) printf("4\n");
       else if(rem == 3) printf("8\n");
       else printf("6\n");
    }

    else if(b == 3 ) {
       if(rem == 1) printf("3\n");
       else if(rem == 2) printf("9\n");
       else if(rem == 3) printf("7\n");
       else printf("1\n");
    }

    else if(b == 4 ) {
       if(rem == 1) printf("4\n");
       else printf("6\n");
    }
    else if(b == 7 ) {
       if(rem == 1) printf("7\n");
       else if(rem == 2) printf("9\n");
       else if(rem == 3) printf("3\n");
       else printf("1\n");
    }

   else if(b == 8 ) {
       if(rem == 1) printf("8\n");
       else if(rem == 2) printf("4\n");
       else if(rem == 3) printf("2\n");
       else printf("6\n");
    }

    else {
       if(rem == 1) printf("9\n");
       else printf("1\n");
    }
}

int main() {
    int r,l;
    while(1)  {
       scanf("%s%s",B,P);
       r = strlen(B) - 1;
       l = r;
       if(B[0] == '0' && P[0] == '0') break;
       if(B[0] == '0') { printf("0\n"); continue; }
       if(P[0] == '0') { printf("1\n"); continue; }
       if(B[r] =='0' || B[r] == '1' || B[r] == '5' || B[r] == '6') {
	 printf("%c\n",B[r]);
	 continue;
       }
       if(B[r] =='4' || B[r] == '9')
	 r = Rem(2);
       else
	 r = Rem(4);

       LastDigit(B[l]-'0',r);
    }
	return 0;

}
