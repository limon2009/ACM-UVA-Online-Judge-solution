#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXN 22

char link[MAXN][MAXN];
char str1[75];
char str2[1000];
char color[150];
int  mark[150];


int com(const void *a, const void *b) {
	return *(char *)a - *(char *)b;
}


void Recur(int level, int n, int l, char dummy[30]) {
	int i, j, k, m;
	for(j = 0; j<level-1; j++) {
		k = dummy[j];
		m = mark[k];
		if(link[m][n] == 1) return;
	}
	
	dummy[level-1] = str1[n];
	if(level == l) {
		dummy[level] = NULL;
		puts(dummy);
		return;
	}
	color[n] = 1;
	for(i = 0; i<l; i++) {
		if(link[n][i] == 0 && color[i] == 0)
			Recur(level+1,i,l,dummy);
	}
	color[n] = 0;
}


void Set() {
	int i, j, k = 0;
	for(i = 0; str1[i]; i ++) {
		if(str1[i] != ' ')
			str1[k++] = str1[i];
	}
	str1[k] = NULL;
	qsort(str1,k,sizeof(char),com);
	for(i = 0; str1[i]; i++) {
		j = str1[i];
		mark[j] = i;
	}
}

void Mark() {
	int i, j, l, k = 0, u, v;
	char temp[100];
	l = strlen(str2);
	for(i = 0; i<l; i++){
		if(str2[i] != ' ') 
			temp[k++] = str2[i];
	}
	temp[k] = NULL;
	for(i = 0; temp[i]; i+= 2) {
		j  = temp[i];
		k = temp[i+1];
		u = mark[j];
		v = mark[k];
		link[v][u] = 1;
	}
}


void Cal() {
	char dummy[50];
	int i, l, j;
	l = strlen(str1);
	for(i = 0; i<l; i++) 
		Recur(1,i,l,dummy);
	for(i = 0; i<l; i++)
		for(j = 0; j<l; j++) link[i][j] = 0;
}


int main() {
	int kase = 0;
	while(gets(str1)) {
		if(kase++) printf("\n");
		Set();
		gets(str2);
		Mark();
		Cal();
	}
	return 0;
}
