#include<stdio.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<assert.h>

using namespace std;

char Ig[52][17];
int  tk, ti, ts;
char tt[10000], cont[17][20];
char W[2000][400];
int  tc;



int com(const void *a, const void *b) {
	return strcmp((char *)a,(char *)b);
}


struct ss {
	char key[25];
	int ind;
}K[2000];

struct node {
	char str[20];
	int ind;
	node *par, *left, *right;
};

node *root;

int com1(const void *a, const void *b) {
	ss *p = (ss *)a;
	ss *q = (ss *)b;
	if(!strcmp(p->key,q->key)) 
		return p->ind - q->ind;
	return strcmp(p->key,q->key);
}

void ReadIg() {
	ti = 0;
	while(gets(Ig[ti])) {
		if(!strcmp(Ig[ti],"::")) break;
		ti++;
	}
}


void Process(int p) {
	char temp[50];
	int i, j, k = 0;
	for(i = 0; cont[p][i]; i++)
		temp[i] = toupper(cont[p][i]);
	temp[i] = NULL;
	for(i = 0; i<p; i++) {
		for(j = 0; cont[i][j]; j++)
			W[ts][k++] = cont[i][j];
		W[ts][k++] = ' ';
	}
	for(i = 0; temp[i]; i++) W[ts][k++] = temp[i];
	if(p == tc-1) {
		W[ts++][k] = NULL;
		return;
	}
	for(i = p+1; i<tc; i++) {
		W[ts][k++] = ' ';
		for(j = 0; cont[i][j]; j++)
			W[ts][k++] = cont[i][j];
	}
	W[ts++][k] = NULL;
}

void Sep() {
	char *p;
	int i;
	tc = 0;
	p = strtok(tt," ");
	while(p) {
		for(i = 0; p[i]; i++) 
			p[i] = tolower(p[i]);
		strcpy(cont[tc++],p);
		p = strtok(NULL , " ");
	}
}

void Insert(char str[], int ind) {
	node *p = new node;
	p->left = p->right = NULL;
	strcpy(p->str,str);
	p->ind = ind;
	if(root == NULL) {
		root = p;
		p->par = NULL;
		return;
	}
	node *x = root;
	while(1) {
		if(strcmp(x->str,str)>0) {
			if(x->right == NULL) {
				x ->right = p;
				p->par = x;
				break;
			}else x = x->right;
		}else {
			if(x->left == NULL) {
				x ->left = p;
				p->par = x;
				break;
			}else x = x->left;
		}
	}

}
node *Sr(node *r, char str[]) {
	node *x = r;
	while(x != NULL) {
		if(!strcmp(x->str,str)) return x;
		if(strcmp(x->str,str) > 0) 
			x = x->right;
		else x = x->left;
	}
	return x;
}

void ReadTitle() {
	int i, *q, l, m;
	node *g;
	tk = ts = 1;
	while(gets(tt)) {
		Sep();
		l = strlen(tt);
		for(i = 0; i<tc; i++) {
			q = (int *)bsearch(&cont[i],Ig,ti,sizeof(Ig[0]),com);
			if(q == NULL) {
				g = Sr(root,cont[i]);
				if(g == NULL) {
					Insert(cont[i],tk);
					tk++;
				}
				strcpy(K[ts].key,cont[i]);
				K[ts].ind = ts;
				Process(i);
			}
		}
	}
}

void Cal() {
	int i, j;
	ReadTitle();
	qsort(&K[1],ts-1,sizeof(ss),com1);
	for(i = 1; i<ts; i++){
			j = K[i].ind;
			puts(W[j]);
	}
}

int main() {
	//freopen("c:\\123.in","r",stdin);
	//freopen("c:\\out.txt","w",stdout);
	root = NULL;
	ReadIg();
	qsort(Ig,ti,sizeof(Ig[0]),com);
	Cal();
	return 0;

}


