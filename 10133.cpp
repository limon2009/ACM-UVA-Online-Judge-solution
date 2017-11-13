#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXN 100

char Line[1000];
int Level, word;

char List[200][20];
char F[200][200];
int A[200];
int Path[200];

struct str {
	char nam[20];
	int link, sl;
};

struct ss {
	str pum[MAXN];
	int ind;
}Auto[MAXN];


void Set(char temp[], int l) {
	char  dummy[100], num[10];
	int lev, i, j = 0;
	for(i = 0; temp[i] != ':'; i++)
		dummy[i] = temp[i];
	dummy[i] = NULL;
	for(++i; temp[i]; i++)
		num[j++] = temp[i];
	num[j] = NULL;
	strcpy(List[word],dummy);
	strcpy(Auto[l].pum[Auto[l].ind].nam, dummy);
	Auto[l].pum[Auto[l].ind].sl = word;
	if(!strcmp(num,"$")) lev = -1;
	else lev = atoi(num);
	Auto[l].pum[Auto[l].ind].link = lev;
	Auto[l].ind++;
	word++;

}

void Sep(int l) {
	char *p;
	p = strtok(Line, " ");
	while(p) {
		Set(p, l);
		p = strtok(NULL, " ");
	}
}


int ReadCase() {

	int i, l, len, f, pre;
	word = 1;
	Level = 0;
	gets(Line);
	while(1) {
		sscanf(Line,"%d",&l);
		if(pre != l)
			Auto[l].ind = 0;
		if(l>Level) Level = l;
		while(1) {
			f = 1;
			gets(Line);
			len = strlen(Line);
			for(i = 0; Line[i] && Line[i] != ':'; i++){
				if(isalpha(Line[i])){
					f = 0;
					break;
				}
			}
			if(Line[i] == ':' && f) break;
			else if(f && Line[i] != ':')
				return atoi(Line);
			Sep(l);
			pre = l;
		}
	
	}
}
	

void MakeLink() {
	int i, j, k, v, link, u;
	for(i = 0; i<Level; i++) {
		for(k = 0; k<Auto[i].ind; k++) {
			link = Auto[i].pum[k].link;
			u =   Auto[i].pum[k].sl;
			if(link <0) continue;
			for(j = 0; j<Auto[link].ind; j++) {
				v = Auto[link].pum[j].sl;
				F[u][v] = 1;
			}
		}
	}
	for(i = 0; i<Auto[0].ind; i++) {
		u = Auto[0].pum[i].sl;
		F[0][u] = 1;
	}
}

void Print(int level) {
	int i, n;
	n = A[1];
	printf("%s",List[n]);
	for(i = 2; i<= level; i++){
		n = A[i];
		printf("-%s",List[n]);
	}
	printf("\n");
}
int Find(int key, int sum, int n, int level) {
	int i, j = 1;
	A[level] = n;
	for(i = 0; i<word; i++) {
		if(F[n][i]) {
			j = 0;
			if(sum + Path[i]>= key)
				if(Find(key,sum,i, level+1)) return 1;
			sum += Path[i];
		}
	}
	Print(level);
	return 1;
}

int  Mark(int n) {
	int i, j = 1;
	if(Path[n]) return Path[n];
	for(i = 0; i<word; i++) {
		if(F[n][i]){
			j = 0;
			Path[n] += Mark(i);
		}
	}
	if(j) Path[n] = 1; 
	return Path[n];
}

void Cal() {
	int n, i;
	char dummy[100];
	n = ReadCase();
	MakeLink();
	Mark(0);
	Find(n,0,0,0);
	while(gets(dummy)) {
		for(i = 0; dummy[i]; i++) {
			if(dummy[i] == '\n') 
				dummy[i] = NULL;
		}
		if(strlen(dummy) == 0) break;
		n = atoi(dummy);
		Find(n,0,0,0);
	}
}

void GetFree() {
	int i, j;
	for(i = 0; i<word; i++) {
		Path[i] = 0;
		for(j = 0; j<word; j++) {
			F[i][j] = 0;
		}
	}
}

int main() {
	char dd[100];
	int kase;
	gets(dd);
	kase = atoi(dd);
	gets(dd);
	while(kase--) {
		Cal();
		if(kase){
			GetFree();
			printf("\n");
		}
	}
	return 0;

}
