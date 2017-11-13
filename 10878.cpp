#include<string.h>
#include<stdio.h>

char str[100];

int F() {
	int i, d = 1, sum = 0;
	for(i = 9; i>1; i--) {
			if(str[i] != ' ' && str[i] != 'o') continue;
			if(str[i] == 'o')
				sum += d;
			d *= 2;
		
	}
	return sum;
}
void Cal() {
	int  d;
	gets(str);
	while(strcmp(str,"___________")) {
		d = F();
		printf("%c",d);
		gets(str);
	}
}

int main() {
//	freopen("h.txt","r",stdin);
	gets(str);
	Cal();
	return 0;

}
