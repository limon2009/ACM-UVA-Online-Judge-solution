#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<map>

using namespace std;

#define MAXN 5002

map<string,bool>M;

char word[MAXN][40];
char str[250];
int tw;

int com(const void *a, const void *b) {
	return (strcmp( (char *)a, (char *)b));
}

void Sep() {
	int i, j, k, v;
	char temp[25];
	for(i = 0; str[i]; ) {
		if(!isalpha(str[i])) {
			i++;
			continue;
		}
		k = 0;
		for(j = i; str[j] && isalpha(str[j]); j++) temp[k++] = tolower(str[j]);
		i = j;
		temp[k] = NULL;
		v = M[temp];
		if(v) continue;
		M[temp] = true;
		strcpy(word[tw++],temp);
	}
}

void Cal() {
	int i;
	qsort((void *)word,tw,sizeof(word[0]),com);
	for(i = 0; i<tw; i++)
		puts(word[i]);
}

int main() {
//	freopen("c:\\h.txt","r",stdin);
//	freopen("c:\\out.txt","w",stdout);
	tw = 0;
	while(gets(str))
		Sep();
	Cal();
	return 0;

}

