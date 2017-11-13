#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int Num[1002], Dem[1002];
int N;

#include <stdio.h>
#include<string.h>
#include<math.h>

#define	MAXDIGITS	1000		/* maximum length bignum */ 

#define PLUS		1		/* positive sign bit */
#define MINUS		-1		/* negative sign bit */

#define max(a,b) ((a>b)?a:b)

typedef struct {
        char digits[MAXDIGITS]; /* represent the number */
		int signbit;			/* 1 if positive, -1 if negative */ 
        int lastdigit;			/* index of high-order digit */
} bignum;

void int_to_bignum(int s, bignum *n);
void initialize_bignum(bignum *n);
int add_bignum(bignum *a, bignum *b, bignum *c);
int subtract_bignum(bignum *a, bignum *b, bignum *c);

void int_to_bignum(int s, bignum *n)
{

	if (s >= 0) n->signbit = PLUS;
	else n->signbit = MINUS;
	int t = abs(s);
	sprintf(n->digits,"%d",t);
	n->lastdigit=strlen(n->digits);
}

void int_to_bignum(char *s, bignum *n)
{
	int i;
	if (s[0] != -1) 
	{	
		n->signbit = PLUS;
		i = 0;
	}
	else 
	{	i = 1;
		n->signbit = MINUS;
	}
	
	strcpy(n->digits,&s[i]);
	n->lastdigit = strlen(n->digits);
}


void initialize_bignum(bignum *n)
{	int_to_bignum(0,n);		}	


void multiply_bignum(bignum *a, bignum *b, bignum *c)
{
	long int n_d;
	register long int i,j,k;
	short int num1[MAXDIGITS],num2[MAXDIGITS],of=0,res[MAXDIGITS]={0};
	
	n_d=(a->lastdigit<b->lastdigit)?b->lastdigit:a->lastdigit;
	n_d++         ;
	

	for(i=0,j= a->lastdigit-1;i< a->lastdigit ;i++,j--)
		num1[i]=a->digits[j]-48;

	for(i=0,j= b->lastdigit-1;i< b->lastdigit ;j--,i++)
		num2[i]=b->digits[j]-48;
	res[0]=0;
	
	for(j=0;j< b ->lastdigit;j++)
	{	for(i=0,k=j;i< a->lastdigit || of;k++,i++)
		{	if(i<a->lastdigit)
				res[k] += num1[i] * num2[j] + of;
			else	res[k] += of;
			of=res[k]/10;
			res[k]=res[k]%10;
		}
	}
	
	for(i=k-1,j=0;i>=0;i--,j++)
		c->digits[j]=res[i]+48;
	c->digits[j]='\0';
	c->lastdigit=k;	
	c->signbit = a->signbit*b->signbit;
}



char temp[2000], dummy[2000];

void Cal() {
	bignum n1, n2, n3;
	int_to_bignum(1,&n2);
	int i;
	for(i = 0; i<N-1; i++) {
		if(Num[i] == 1) continue;
		int_to_bignum(Num[i], &n1);
		multiply_bignum(&n1,&n2,&n3);
		strcpy(temp,n3.digits);
		int_to_bignum(temp,&n2);
	}
	printf("%s\n",temp);
}

int gcd(int a, int b) { return b?gcd(b,a%b):a;}

int Comb() {
	int i, j, k, d, g;
	int  lim = N - 1;
	for(i = 0; i<lim; i++) {
		Num[i] = N + i+2;
		Dem[i] = i+2;
	}
	for(i = 0; i<lim; i++) {
		k = Dem[i];
		for(j = 0; j<lim && k>1; j++) {
			d = Num[j];
			g = gcd(k,d);
			k /= g;
			Num[j] /= g; 
		}
	}
	Cal();
	return 0;
}

int main() {
	while(scanf("%d",&N) == 1) {
		if(N == 1) {
			printf("1\n");
			continue;
		}
		Comb();
	}
	return 0;
}
