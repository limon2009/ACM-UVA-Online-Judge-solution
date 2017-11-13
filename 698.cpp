#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<vector>
#include<string.h>

#define maxn 10000

using namespace std;

char INDEX[maxn][22];
char text[100000];
char sep[maxn][22];


int total, ts;
vector<int>V[maxn];

int com(const void *a, const void *b) {
	return strcmp((char *)a,(char *)b);
}

int Empty(char ss[]) {
	int i;
	for(i = 0; ss[i]; i++) {
		if(ss[i] == '\n'){
			ss[i] = NULL;
			break;
		}
	}
	if(strlen(ss) == 0) return 1;
	return 0;
}

void Sep() {
	int i, j, k;
	ts = 0;
	char temp[112];
	for(i = 0; text[i]; ) {
		if(!isalpha(text[i]) && !isdigit(text[i])) {i++; continue; }
		k = 0;
		for(j = i; text[j] && (isalpha(text[j]) || isdigit(text[j])); j++) 
			temp[k++] = toupper(text[j]);
		temp[k] = NULL;
		strcpy(sep[ts++],temp);
		i = j;
	}

}

void Cal(int line) {
	int i, *j;
	Sep();
	qsort(sep,ts,sizeof(sep[0]),com);
	for(i = 0; i<total; i++) {
		j = (int *)bsearch(&INDEX[i],sep,ts,sizeof(INDEX[0]),com);

		if(j) V[i].push_back(line);
	}
}


void Print() {
	int i, j, k, pre, f;
	for(i = 0; i<total; i++) {
		f = 1;
		if(V[i].size() == 0) continue;
		for(j = 0; INDEX[i][j]; j++) {
			if(!isdigit(INDEX[i][j]) && !isalpha(INDEX[i][j])) {
				f =0;
				break;
			}
		}
		//if(!f) continue;
		printf("%s",INDEX[i]);
		if(V[i].size() == 0){
			printf("\n");
			continue;
		}
		pre = V[i][0];
		printf(" %d",V[i][0]);
		for(j = 1; j<V[i].size(); j++) {
			if(V[i][j] != pre+1) {
				printf(", %d",V[i][j]);
				pre = V[i][j];
			}
			else {
				printf("-");
				while(j<V[i].size() && V[i][j] == pre+1){
					pre = V[i][j];
					j++;
				}
				j--;
				printf("%d",pre);
			}
		}
		printf("\n");
	}
}

void Free() {
	int i;
	for(i = 0; i<total; i++)
		V[i].clear();
}

int main() {
	int line, i, ks = 1;
	total = 0;
	//freopen("h.txt","r",stdin);
	//freopen("ans.txt","w",stdout);
	while(gets(INDEX[total++])) {
		if(Empty(INDEX[total-1])) break;
		for(i = 0; INDEX[total-1][i]; i++)
			INDEX[total-1][i] = toupper(INDEX[total-1][i]);
		while(gets(INDEX[total])) {
			if(Empty(INDEX[total])) break;
			for( i = 0; INDEX[total][i]; i++)
				INDEX[total][i] = toupper(INDEX[total][i]);
			total++;
		}
		qsort(INDEX,total,sizeof(INDEX[0]),com);
		line = 1;
		while(1) {
			gets(text);
			if(Empty(text)) break;
			Cal(line);
			line++;
		}
		printf("Case %d\n",ks++);
		Print();
		Free();
		total = 0;
		printf("\n");
	}
	return 0;

}
