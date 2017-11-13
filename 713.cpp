#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX(a, b)  (a>b?a:b)

#define MAXN 202

char Num1[MAXN], Num2[MAXN];

void Cal() {
	int i,l1, l2, max;
	int a, b, carry = 0, sum, f = 0;
	l1 = strlen(Num1);
	l2 = strlen(Num2);
	max = MAX(l1,l2);
	for(i = l1; i<max; i++)
		Num1[i] = '0';
	for(i = l2; i<max; i++)
		Num2[i] = '0';
	for(i = 0; i<max; i++) {
		a = Num1[i] - '0';
		b = Num2[i] - '0';
		sum = (a+b+carry);
		carry = sum / 10;
		if(!(sum%10) && f) printf("%d",sum%10);
		if(sum%10){
			printf("%d",sum%10);
			f = 1;
		}
	}
	if(carry) printf("%d",carry);
}

int main() {
	int kase;
	scanf("%d",&kase);
	while(kase--) {
		scanf("%s%s",Num1,Num2);
		Cal();
		putchar('\n');
	}
	return 0;

}


