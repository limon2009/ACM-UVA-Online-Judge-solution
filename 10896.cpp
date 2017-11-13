#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define maxn 100

char ss[maxn];
char key[maxn];
char Words[maxn][20];
int tw;

void Sep() {
	tw = 0;
	char *p = strtok(ss," ");
	while(p) {
		strcpy(Words[tw++], p);
		p = strtok(NULL, " ");
	}
}

bool Match(int ind, int k) {
	char temp[maxn];
	int i;
	for(i = 0; Words[ind][i]; i++) {
		temp[i] = (((Words[ind][i] - 'a') - k + 26) % 26) +'a';
	}
	temp[i] = NULL;
	if(!strcmp(temp,key)) return true;
	return false;
}

bool F(int k) {
	int i;
	for(i = 0; i<tw; i++) {
		if(Match(i,k)) return true;
	}
	return false;
}
void Cal() {
	int i;
	for(i = 0; i<26; i++) {
		if(F(i)) printf("%c",i+'a');
	}
	printf("\n");
}

int main() {
	int tc;
//	freopen("h.txt","r",stdin);
	gets(ss);
	tc = atoi(ss);
	while(tc--) {
		gets(ss);
		Sep();
		gets(key);
		Cal();
	}
	return 0;

}
