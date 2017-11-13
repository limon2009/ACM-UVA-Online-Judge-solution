#include<stdio.h>
#include<string.h>

void Cal(int r, int pro) {
	char rec[300], nam[300], ss[300];
	int max = -100, y;
	double cost,x;
	while(r--) {
		gets(nam);
	}
	while(pro--) {
		gets(nam);
		gets(rec);
		sscanf(rec,"%lf%d",&x,&y);
		if(y>max) {
			max = y;
			cost = x;
			strcpy(ss,nam);
		}
		else if(max == y && x<cost) {
			cost = x;
			strcpy(ss,nam);
		}
		while(y--) {
			gets(nam);
		}
	}
	puts(ss);
}

int main() {
	int n, m, r = 1;
	char ss[300];
//	freopen("h.txt","r",stdin);
	while(gets(ss)){
		sscanf(ss,"%d%d",&n,&m);
		if(!n && !m) break;
		if(r>1) printf("\n");
		printf("RFP #%d\n",r++);
		Cal(n,m);
	}
	return 0;

}

