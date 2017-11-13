#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1001

struct Dic {
	char st[11];
	int ind;
}dic[MAX], ss, A;

int Fre[MAX], wd, Count;


char f[10];

int com(const void *a ,const void *b) {
	Dic *x,*y;
	x = (Dic  *)a;
	y = (Dic  *)b;
	return strcmp(x->st,y->st);	
}

void Recur(int n, int level, int limit) {
	int i,  ind, ck = 0;
	Dic *p;
	if(level == limit) return;
	A.st[level] = ss.st[n];
	A.st[level+1] = NULL;
	if(level > 0){
		p = (Dic *)bsearch(&A,dic,wd,sizeof(dic[0]),com);
		if(p) {
			ind = p->ind;
			Count += Fre[ind];
		}
	}
	f[n] = 1;
	for(i = 0; i<limit; i++) {
		if(f[i]) continue;
		if(i && f[i-1] == 0 && ss.st[i] == ss.st[i-1]) continue;
		Recur(i,level+1, limit);
	}
	f[n] = 0;
}


void ReadDic() {
	Dic *p;
	int ind;
	wd = 0;
	while(1) {
		gets(dic[wd].st);
		if(!strcmp(dic[wd].st,"#")) break;
		p = (Dic *)bsearch(&dic[wd].st,dic,wd,sizeof(dic[0]),com);
		if(p) {
			ind = p->ind;
			Fre[ind]++;
		}
		else {
			dic[wd].ind = wd;
			Fre[wd]++;
			wd++;
		}
	}
}

int com1(const void *a, const void *b ){
	return *(char *)a - *(char *)b;
}

void Cal() {
	int qq[30] = {0};
	int i, j, limit, ind;
	char tmp[10];
	Dic *p;
	limit = strlen(ss.st);
	Count = 0;
	qsort(ss.st,limit,sizeof(char),com1);
	for(i = 0; i<limit; i++) {
		j = ss.st[i] - 'a';
		if(qq[j]) continue;
		tmp[0] = ss.st[i];
		tmp[1] = NULL;
		p = (Dic *)bsearch(&tmp,dic,wd,sizeof(dic[0]),com);
		if(p) {
			ind = p->ind;
			Count += Fre[ind];
		}
		qq[j] = 1;
		for(j = 0; j<limit; j++) f[i] = 0;
		Recur(i,0,limit);
	}
	printf("%d\n",Count);
}

void ReadPuzzel() {
	char temp[500];
	int i, j;
	while(1) {
		gets(temp);
		if(!strcmp(temp,"#")) break;
		j = 0;
		for(i = 0; temp[i]; i++)
			if(temp[i] != ' ')
				ss.st[j++] = temp[i];
		ss.st[j] = NULL;
		Cal();
	}
}

int main() {
	
	ReadDic();
	ReadPuzzel();
	return 0;

}
