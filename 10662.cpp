#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char tr[21][21], rh[21][21], ht[21][21];
int tp[21], rp[21], hp[21];
int T, R, H, min;

char ss[1000];

void Set() {
	int i, j, max = T;
	if(R>max) max = R;
	if(max<H) max = H;
	for(i = 0; i<= max; i++){
		for(j = 0; j<= max; j++)
			tr[i][j] = rh[i][j] = ht[i][j] = 0;
	}
}

void Readt() {
	int i, j, k;
	char *p;
	for(i = 0; i<T; i++) {
		gets(ss);
		p = strtok(ss," ");
		k = atoi(p);
		tp[i] = k;
		j = 0;
		while(p) {
			p = strtok(NULL, " ");
			if(p) {
				k = atoi(p);
				tr[i][j++] = k;
			}
		}
	}
}

void Readr() {
	int i, j, k;
	char *p;
	for(i = 0; i<R; i++) {
		gets(ss);
		p = strtok(ss," ");
		k = atoi(p);
		rp[i] = k;
		j = 0;
		while(p) {
			p = strtok(NULL, " ");
			if(p) {
				k = atoi(p);
				rh[i][j++] = k;
			}
		}
	}
}

void Readh() {
	int i, j, k;
	char *p;
	for(i = 0; i<H; i++) {
		gets(ss);
		p = strtok(ss," ");
		k = atoi(p);
		hp[i] = k;
		j = 0;
		while(p) {
			p = strtok(NULL, " ");
			if(p) {
				k = atoi(p);
				ht[i][j++] = k;
			}
		}
	}
}

void Cal() {
	int i, j, k;
	int Rt,Rr,Rh;
	min = 2147483646;
	for(i = 0; i<T; i++) {
		for(j = 0; j<R; j++) {
			if(tr[i][j]) continue;
			if(tp[i]+rp[j] >= min) continue;
			for(k = 0; k<H; k++) {
				if(rh[j][k] || ht[k][i]) continue;
				if(tp[i]+rp[j]+hp[k] >= min) continue;
				min = tp[i]+rp[j]+hp[k];
				Rt = i; Rr = j; Rh = k;
			}
		}
	}
	if(min == 2147483646) {
		printf("Don't get married!\n");
		return;
	}
	printf("%d %d %d:%d\n",Rt,Rr,Rh,min);
}

int main() {
	int i;
	
	while(gets(ss)) {
		for(i = 0; ss[i]; i++)
			if(ss[i] == '\n') ss[i] = NULL;
		if(strlen(ss) == 0) break;
		sscanf(ss,"%d%d%d",&T,&R,&H);
		Set();
		Readt();
		Readr();
		Readh();
		Cal();
	}
	return 0;

}

