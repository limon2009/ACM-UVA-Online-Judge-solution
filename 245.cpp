#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXN 300000

struct ss {
	char str[52];
};
ss *p;


char input[100000];
int ta;


void Set(int n) {
	int i;
	char dum[52];
	strcpy(dum,p[n].str);
	for(i = n; i<=ta-2; i++) {
		strcpy(p[i].str,p[i+1].str);
	}
	strcpy(p[ta-1].str,dum);
}

void Gen() {
	int i, j;
	char temp[52];

	for(i = 0; input[i]; ) {
		if(isalpha(input[i])) {
			j = 0;
			for(i; input[i] && isalpha(input[i]); i++){
				temp[j++] = input[i];
				printf("%c",input[i]);
			}
			temp[j] = NULL;
			strcpy(p[ta++].str,temp);
		
		}
		else if(isdigit(input[i])) {
			j = 0;
			for(i; input[i] && isdigit(input[i]); i++) {
				temp[j++] = input[i];
			}
			temp[j] = NULL;
			j = atoi(temp);
			printf("%s",p[ta - j].str);
			Set(ta - j);
		}
		else {
			putchar(input[i]);
			i++;
		}
	}
	printf("\n");
}

int main() {
	//freopen("c:\\h.in","r",stdin);
	//freopen("c:\\out.txt","w",stdout);
	p = new ss[MAXN];
	ta = 0;	
	while(gets(input)) {
		if(!strcmp(input,"0")) break;
		Gen();
	}
	delete []p;
	return 0;

}

