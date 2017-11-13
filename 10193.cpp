#include<stdio.h>
#include<string.h>

char str1[35];
char str2[35];

int gcd(int a , int b) { return b?gcd(b,a%b):a;}

int Binary(char ss[]) {
	int i, j, sum = 0, k = 1;
	for(i = strlen(ss)-1; i>=0; i--) {
		j = ss[i] - '0';
		sum += j*k;
		k *= 2;
	}
	return sum;
}

int Cal() {
	int a, b;
	if(!strcmp(str1,str2)) {
		printf("All you need is love!\n");
		return 0;
	}

	a = Binary(str1);
	b = Binary(str2);
	if(gcd(a,b)>1) printf("All you need is love!\n");
	else printf("Love is not all you need!\n");
	return 0;
}

int main() {
	int kase, m = 1;
	scanf("%d",&kase);
	while(kase--) {
		scanf("%s",str1);
		scanf("%s",str2);
		printf("Pair #%d: ",m++);
		Cal();
	}
	return 0;
}

