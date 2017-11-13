#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char f[1002];
int N[22], k, sum;
char str[1000];

void Sep() {
	char *p;
	k = sum = 0;
	p = strtok(str," ");
	N[k++] = atoi(p);
	sum += N[k-1];
	while(1) {
		p = strtok(NULL, " ");
		if(p)
			N[k++] = atoi(p);
		else break;
		sum += N[k-1];
	}
}


int Dynamic() {
	int i, j, half = sum/2;
	int m, p;
	if(sum % 2) {
		return 0;
	}
	m = 0;
	for(i = 0; i<k; i++) {
		if(N[i] > half) continue;
		for(j = m; j>=0; j--){
			if(f[j]) {
				p = j+N[i];
				if(p<= half && !f[p]){
					f[p] = 1;
					if(p>m) m = p;
				}
			}
		}
		if(f[N[i]] == 0) {
			f[N[i]] = 1;
			if(m<N[i])
				m = N[i];
		}
		if(f[half] == 1) return 1;
	}
	return 0;
}

void Cal() {
	if(Dynamic()) printf("YES\n");
	else printf("NO\n");
}

void Free() {
	int half, i;
	half = sum/2;
	for(i = 0; i<= half; i++)
		f[i] = 0;
}

int main() {
	int kase;
	char input[100];
	gets(input);
	sscanf(input,"%d",&kase);
	while(kase--) {
		gets(str);
		Sep();
		Cal();
		Free();
	}
	return 0;

}
