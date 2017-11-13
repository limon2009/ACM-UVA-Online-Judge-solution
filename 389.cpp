#include<stdio.h>
#include<math.h>
#include<string.h>

char Digit[] = "0123456789ABCDEF";
char Er[] = "ERROR",Z[] = "0";
char Base[15];
int Value[200], From, To, F;
long long Sum;

int Ini() {
  int i, j;
  for(i = 0; Digit[i]; i ++) {
     j = Digit[i];
     Value[j] = i;
  }
  return 0;
}

int  Decimal() {
      int i, p, q = 0, r = 0;
      int l = strlen(Base);
      Sum = 0;
      if(Base[0] == '-') {
	 F = 1;
	 r = 1;
      }
      for(i = l-1; i>=r; i --)  {
	  p = Base[i];
	  if(Value[p] >= From) return 0;
	  Sum += Value[p] * pow(From,q);
	  q ++;
      }
      return 1;
}

void Convert()  {
	int i, p = 0, k, d = 0;
	char C[50],S[50];

	if(F)  {   S[0] = '-'; d = 1; }
	if(Sum == 0) {  printf("%7s\n",Z); return; }
	while(Sum)  {
	    k = Sum % To;
	    C[p++] = Digit[k];
	    Sum /= To;
	}
	for(i = p-1; i>=0; i --)
	  S[d++] = C[i];
	S[d] = NULL;
	if(d > 7) printf("%7s\n",Er);
	else printf("%7s\n",S);
}

int main()  {

      Ini();
      while(scanf("%s%d%d",Base,&From,&To) != EOF) {
	      F = 0;
	      Decimal();
	      Convert();

      }
	return 0;

}
