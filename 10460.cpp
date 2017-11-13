#include<stdio.h>
#include<string.h>

char str[30];
int In;

void Insert(int p, char c, char *ss) {
	int i, l;
	l = strlen(ss);
	if(p == l) {
		ss[p] = c;
		ss[p+1] = NULL; 
		return;
	}
	for(i = l; i>p; i--)
		ss[i] = ss[i-1];
	ss[p] = c;
	ss[l+1] = NULL;
}

void Cal() {
	int i, l, k = 0;
	int a[30];
	char dummy[30];
	l = strlen(str);
	if(l == 1) {
		printf("%s\n",str);
		return;
	}
	a[k++] = In%l;
	In /= l;
	for(i = l-1; i>=2; i--) {
		a[k++] = In%i;
		In /= i;
	}
	l = 1;
	dummy[0] = str[0]; dummy[1] = NULL;
	for(i = k-1; i>=0; i--) {
		Insert(a[i],str[l++],dummy);
	}
	printf("%s\n",dummy);
}

int main() {
	int kase ;
	scanf("%d",&kase);
	while(kase--) {
		scanf("%s",str);
		scanf("%d",&In);
		In--;
		Cal();
	}
	return 0;
}
