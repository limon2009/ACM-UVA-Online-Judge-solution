#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXN 27

int Day[MAXN], Tday[MAXN], link[MAXN][MAXN], maxlen;
char color[MAXN], flag[MAXN];

struct node {
	int n;
	node *next;
};
node *list;

void ReadCase(char str[]) {
	int u, v, i;
	char *p;
	p = strtok(str," ");
	v = p[0] - 'A';
	if(v>maxlen) maxlen = v;
	flag[v] = 1;
	p = strtok(NULL," ");
	Tday[v] = Day[v] = atoi(p);
	p = strtok(NULL, " ");
	if(p == NULL) return;
	for(i = 0; p[i] != NULL; i++) {
		u = p[i] - 'A';
		if(u>maxlen) maxlen = u;
		link[u][v] = 1;
		flag[u] = 1;
	}
}

void topo(int n) {
	int i;
	color[n] = 1;
	for(i = 0; i<26; i++) {
		if(link[n][i] && !color[i])
			topo(i);
	}
	node *p;
	p = new node;
	p->next = list;
	list = p;
	p->n = n;
}

void Dfs() {
	int i;
	for(i = 0; i<26; i++) {
		if(flag[i] && !color[i])
			topo(i);
	}
}

void Count() {
	node *x = list;
	int i, u;
	while(x!= NULL) {
		u = x->n;
		for(i = 0; i<26; i++) {
			if(link[u][i]) {
				if(Tday[u] + Day[i] > Tday[i])
					Tday[i] = Tday[u] + Day[i];
			}
		}
		x = x->next;
	}
}

void Cal() {
	int i, max = 0;
	if(maxlen == -1) {
		printf("\n");
		return;
	}
	Dfs();
	Count();
	for(i = 0; i<26; i++){
		if(max<Tday[i])
			max = Tday[i];
	}
	printf("%d\n",max);
}

void Reset() {
	int i, j;
	for(i = 0; i<26; i++) {
		for(j = 0; j<26; j++)
			link[i][j] = 0;
		Tday[i] = Day[i] = 0;
		color[i] = flag[i]  = 0;
	}
}

int main() {
	char str[100];
	int kases, i;
	
	gets(str);
	sscanf(str,"%d",&kases);
	gets(str);
	while(kases--) {
		list = NULL;
		maxlen = -1;
		while(gets(str)) {
			for(i = 0; str[i]; i++) {
				if(str[i] == '\n') {
					str[i] = NULL;
					break;
				}
			}
			if(strlen(str) == 0) break;
			ReadCase(str);
		}
		Cal();
		if(kases) {	putchar('\n');	Reset();}
	}
	return 0;

}

