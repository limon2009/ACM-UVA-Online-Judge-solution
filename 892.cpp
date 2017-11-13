#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXN 70

char Str[MAXN], Carry[MAXN];
int Len, Fg;

void Cal() {
	int i, j = 0, k = 0, m = Len;
	char Temp[MAXN];
	if(Fg) {
		for(j = 0; Str[j] == ' '; j++);
		for(j; Str[j] != ' '; j++){
			if(isalpha(Str[j]))
				Temp[k++] = Str[j];
		}
		Temp[k] = NULL;
		strcat(Carry,Temp);
		printf("%s\n",Carry);
		Fg = 0;
	}
	if(Str[Len-1] == '-') {
		k = 0;
		for(i = Len-1; Str[i] !=' '; i--);
		m = i+1;
		for(++i; Str[i]; i++) {
			if(isalpha(Str[i]))
				Carry[k++] = Str[i];
		}
		Carry[k] = NULL;
		Fg = 1;
	}
	for(i = j; i<m; i++) {
		if(!isspace(Str[i]) && !isalpha(Str[i])) continue;
		printf("%c",Str[i]);
	}
	printf("\n");
}
int main() {
	int i;
	while(gets(Str)) {
		for(i = 0; Str[i]; i++) {
			if(Str[i] == '\n'){
				Str[i] = NULL;
				break;
			}
		}
		Len = strlen(Str);
		if(Len == 0) { printf("\n"); continue; }
		if(Len == 1 && Str[0] =='#') break;
		Cal();
	}
	return 0;

}

