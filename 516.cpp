#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000100


long c,N[1000];
long long sum;
long STORE[1000],TOTAL[1000];
int P[7000];
char A[MAX+5];
char data[100010];

void PRIME_TABLE()  {

   int i,j,c = 0;
   for(i = 2; i<MAX; i ++) A[i] = 1;
   for(i = 2; i<= sqrt(MAX); )  {
     for(j = i + i; j <= MAX; j += i)
       A[j] = 0;
     for(i++; !A[i] & i<= MAX; i++);
   }
   for(i = 2; i <= MAX; i ++  )
    if(A[i])
      P[c++] = i;

}


void GEN()  {

   int i,c,k = 0;
   sum -= 1;
   for(i = 0; P[i] <= sqrt(sum); i ++)   {

     if(sum % P[i] == 0)  {
       c = 0;
       STORE[k] = P[i];
       while(sum % P[i] == 0) {
	 sum /= P[i];
	 c ++;
	 if(sum == 1) break;
       }
       TOTAL[k] = c;
       k++;
     }

   }
   if(sum != 1)  {
     STORE[k] = sum;
     TOTAL[k++] = 1;
   }
   i = k-1;
   while(STORE[i] && i >=0) {
     printf("%ld %ld",STORE[i],TOTAL[i]);
     if(i!=0)
     printf(" ");
       i --;
   }
   putchar('\n');

}

void GETNUM()  {

   char MID[20];
   int i,k = 0;
   c = 0;
   for(i = 0; i<strlen(data); i ++) {
      if(data[i] == ' ' ) {
	MID[k] = NULL;
	N[c ++] = atoi(MID);
	k = 0;
      }
      else MID[k++] = data[i];
  }
  MID[k] = NULL;
  N[c++] = atoi(MID);
}

void calculate()  {

 int i,j;
 sum = 1;
 for(i = 0 ; i<c; i += 2)
    sum  *= pow(N[i],N[i+1]);
 GEN();

}

int main()  {

     PRIME_TABLE();
     while(1)  {

	gets(data);
	if(!atoi(data)) break;
	GETNUM();
	calculate();
     }
	return 0;

}
