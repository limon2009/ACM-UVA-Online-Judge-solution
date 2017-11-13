#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

int  person;
char P[22][100];

map<string,int>M;

struct ss {
	int am;
	char  name[100];
}Act[22];

int com(const void *a, const void *b) {
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	return y->am - x->am;
}

int ReadCase() {
	int n, m, am, v;
	char name[100], per[100];
	scanf("%d%d",&person,&m);
	if(!person && !m) return 0;
	for(n = 1; n <= person; n++) {
		scanf("%s",P[n]);
		M[P[n]] = n;
		strcpy(Act[n].name,P[n]);
	}
	while(m--) {
		scanf("%s%s%d",name,per,&am);
		n = M[name];
		v = M[per];
		Act[n].am += am;
		Act[v].am -= am;
	}
	return 1;
}

void Cal() {
	int i, j, n, d;
	qsort(&Act[1],person,sizeof(ss),com);
	for(i = 1; i<person; i++) {
		if(Act[i].am == 0) continue;
		for(j = person; j>i && Act[i].am > 0; j--) {
			if(Act[j].am == 0) continue;
			n = abs(Act[j].am);
			if(Act[i].am>=n) { 
				printf("%s %s %d\n",Act[j].name,Act[i].name,n);
				Act[i].am -= n; Act[j].am = 0;
			}
			else {
				printf("%s %s %d\n",Act[j].name,Act[i].name,Act[i].am);
				Act[j].am += Act[i].am;
				Act[i].am = 0;
			}
		}
	}
}

int main() {
//	freopen("c:\\h.txt","r",stdin);
	int k = 1;
	while(ReadCase()){
		printf("Case #%d\n",k++);
		Cal();
		M.clear();
		memset(Act,0,sizeof(int)*21);
		printf("\n");
	}
	return 0;

}

