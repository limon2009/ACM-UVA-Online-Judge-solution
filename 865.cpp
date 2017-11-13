#include<stdio.h>
#include<string.h>
#define MAXN 75

char plain[MAXN], line[MAXN];
char sub[MAXN];
char M[300];

void Ini() {
	int i;
	for(i = 0; i<300; i++) M[i] = 0;
	for(i = 0; plain[i]; i++) {
		M[plain[i]] = sub[i];
	}
}

int Empty() {
	int i;
	for(i = 0; line[i]; i++) 
		if(line[i] == '\n') {
			line[i] = NULL;
			break;
		}
	if(strlen(line) == 0) return 1;
	return 0;
}

void Cal() {
	int i, u;
	for(i = 0; line[i]; i++) {
		u = line[i];
		if(M[u]) printf("%c",M[u]);
		else printf("%c",line[i]);
	}
	printf("\n");
}
int main() {
	int kases;
//	freopen("c:\\h.txt","r",stdin);
//	freopen("c:\\out.txt","w",stdout);
	gets(line);
	sscanf(line,"%d",&kases);
	gets(line);
	while(kases--) {
		gets(plain);
		gets(sub);
		puts(sub);
		puts(plain);
		Ini();
		while(gets(line)) {
			if(Empty()) break;
			Cal();
		}
		if(kases) printf("\n");
	}
	return 0;

}
