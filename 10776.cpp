#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ss[100], temp[100], fg[100];
int R, len;

int com(const void *a, const void *b) {
	return *(char *)a - *(char *)b;
}

void Recur(int n, int level) {
	temp[level] = ss[n];
	fg[n] = 1;
	if(level == R-1) {
		temp[level+1] = NULL;
		puts(temp);
		fg[n] = 0;
		return;
	}
	if(level == len-1) {
		fg[n] = 0;
		return;
	}
	for(int i = n+1; i<len; i++) {
		if(fg[i-1] == 0 && ss[i] == ss[i-1]) continue;
		Recur(i,level+1);
	}
	fg[n] = 0;
}

void Cal() {
	int i;
	len = strlen(ss);
	qsort(ss,len,sizeof(char),com);
	for(i = 0; i<=len-R; i++) {
		if(i && ss[i] == ss[i-1]) continue; 
		Recur(i,0);
	}
}

int main() {
	char input[100];
	while(gets(input)) {
		sscanf(input,"%s%d",ss,&R);
		Cal();
	}
	return 0;

}
