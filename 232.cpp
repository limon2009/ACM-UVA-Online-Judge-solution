#include<stdio.h>
#include<string.h>

#define MAXN 100

char B[MAXN][MAXN];
int N[MAXN][MAXN];

int R, C;

int Count(int r, int c) {
	if(B[r][c] == '*') return 0;
	if(r == 0 || c == 0) return 1;
	if(c>0 && B[r][c-1] == '*') return 1;
	if(r>0 && B[r-1][c] =='*') return 1;
	return 0;
}

void Numbered() {
	int i, j, c = 1;
	for(i = 0; i<R; i++) {
		for(j = 0; j<C; j++) {
			N[i][j] = 0;
			if(Count(i,j))
				N[i][j] = c++;
		}
	}
}

void Across() {
	int i, j;
	for(i = 0; i<R; i++) {
		for(j = 0; j<C; ){
			if(B[i][j] != '*'){
				printf("%3d.",N[i][j]);
				for(;B[i][j] && B[i][j] != '*'; j++)
					printf("%c",B[i][j]);
				printf("\n");
			}
			else j++;
		}
	}
}

void Down() {
	int c, r, k;
	for(r = 0; r<R; r++) {
		for(c = 0; c<C; c++ ){
			if(B[r][c] != '*'){
				printf("%3d.",N[r][c]);
				for(k = r; k<R && B[k][c] != '*'; k++) {
					printf("%c",B[k][c]);
					B[k][c] = '*';
				}
				printf("\n");
			}
			
		}
	}
}


int main() {
	int i, k = 0;
//	freopen("c:\\h.txt","r",stdin);
//	freopen("c:\\out.txt","w",stdout);
	while(scanf("%d",&R) == 1) {
		if(!R) break;
		scanf("%d",&C);
		for(i = 0; i<R; i++)
			scanf("%s",B[i]);
		if(k++) printf("\n");
		printf("puzzle #%d:\n",k);
		Numbered();
		printf("Across\n");
		Across();
		printf("Down\n");
		Down();
	}
	return 0;
}
