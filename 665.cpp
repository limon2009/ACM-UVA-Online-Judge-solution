#include<stdio.h>

struct ss {
	char ok, light, heavy;
}C[102];

int N, A[102];

void Mark(int n, char sg[]) {
	int b[102] = {0}, i;
	if(sg[0] == '<') {
		for(i = 0; i<n; i++){
			C[A[i]].light = 1;
			b[A[i]] = 1;
		}
		for(; i<2*n; i++){
			C[A[i]].heavy = 1;
			b[A[i]] = 1;
		}
	}
	else if(sg[0] == '>') {
		for(i = 0; i<n; i++){
			C[A[i]].heavy = 1;
			b[A[i]] = 1;
		}
		for(; i<2*n; i++){
			C[A[i]].light = 1;
			b[A[i]] = 1;
		}
	}
	else {
		for(i = 0; i<2*n; i++)
			C[A[i]].ok = 1;
	}
	if(sg[0] == '>' || sg[0] == '<') {
		for(i = 1; i<= N; i++) {
			if(b[i] == 0)
				C[i].ok = 1;
		}
	}
}

void Cal(){
	int i, c = 0, rec;
	for(i = 1; i<= N; i++) {
		if(C[i].heavy && C[i].light)
			C[i].ok = 1;
		if(C[i].ok == 0) {
			c++;
			rec = i;
		}
		if(c>1) {
			printf("0\n");
			return;
		}
	}
	printf("%d\n",rec);
}

void Free() {
	int i;
	for(i = 1; i<= N; i++)
		C[i].ok = C[i].heavy = C[i].light = 0;
}

int main() {
	int kases, k = 0, i, n;
	char sg[5];
	//freopen("c:\\h.txt","r",stdin);
	scanf("%d",&kases);
	while(kases--) {
		scanf("%d%d",&N,&k);
		while(k--) {
			scanf("%d",&n);
			for(i = 0; i<n*2; i++)
				scanf("%d",&A[i]);
			scanf("%s",sg);
			Mark(n,sg);
		}
		Cal();
		if(kases) {
			printf("\n");
			Free();
		}
	}
	return 0;

}

