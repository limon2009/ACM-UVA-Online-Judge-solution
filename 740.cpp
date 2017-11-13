#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXN 35

char UD[2][MAXN];

char Code[85];

int Decimal(char Temp[]) {
     int i, k, p = 1;
	 double Sum = Temp[4] - '0';
	 for(i = 3; i>= 0; i--){ 
		 k = Temp[i] - '0';
	     Sum += k * pow(2.0,(double)p);
		 p ++;
	 }
	 return (int)Sum;
}
void SolvedCase() {
     int F = 0;
	 int i, j, k,D;
	 char Temp[10];
	 for(i = 0; Code[i];i+= 5 ) {
		 k = 0;
		 for(j = i; j <i+5;j++)
            Temp[k++] = Code[j];
         Temp[k] = NULL;      
		 D = Decimal(Temp);
			if(D == 27)
				F = 0;
			else if(D == 31)
				F = 1;
			else printf("%c",UD[F][D]);
	 }

}

int main() {

	  gets(UD[0]);
	  gets(UD[1]);
	  while(gets(Code)) {
		  SolvedCase();
	      printf("\n");
	  }
	return 0;

}
