#include<stdio.h>
#include<string.h>

typedef long long ss;
ss B[17][17], P[100];
ss R[17][17][17];
ss k;
char com[100];
char pos[] = "123456789ABCDEF";
ss F[17][17];

void Ini() {
	int i;
	for(i = 0; pos[i]; i++)
		P[pos[i]] = i+1;
}

/*
ss Recur(ss r, ss c, ss level, ss g) {
	ss i, j;
	if(R[g][r][c]) return R[g][r][c];
	if(level == g) {
		return 1;
	}
	for(i = 1; i<=g; i++) {
			if(i == c-1 || i == c || i == c+1) continue;
			R[g][r][c] += Recur(r+1,i, level+1,g);
	}
	return R[g][r][c];
}
*/
ss recur(ss r, ss c, ss level, ss limit) {
	ss i, fg = 1;
	if(F[r][c] == 1) return B[r][c];
	/*if(limit >=3) {
		for(i = level; com[i]; i++)
			if(com[i] != '?') 
				break;
		if(i == limit) {
			return R[limit][r][c];
		}
	}*/
	if(level == limit) {
		return 1;
	}
	F[r][c] = 1;
	if(com[r] == '?') {
		for(i = 1; i<=limit; i++) {
			if(i == c-1 || i == c || i == c+1) continue;
			B[r][c] += recur(r+1,i, level+1,limit);
		}
	}
	else {
		if(c == P[com[r]] -1 || c == P[com[r]] || c == P[com[r]] + 1) return 0;
		else B[r][c] = recur(r+1,P[com[r]],level+1,limit);
	}
	return B[r][c];
}

void Free() {
	int i, j;
	for(i = 1; i<=15; i++) {
		for(j = 1; j<=15; j++)
			B[i][j] = F[i][j] = 0;
	}
}

void Cal() {
	ss i, j;
	k = 0;
	j = strlen(com);
	if(com[0] == '?'){
		for(i = 1; i<= j; i++) 
			k += recur(1,i,1,j);
	}
	else 
		k = recur(1,P[com[0]],1,j);

	printf("%lld\n",k);
}
/*
void Set() {
	ss i, j, x = 0;
	for(j = 3; j<=15; j++) {
		for(i = 1; i<=j; i++){
			R[j][1][i] = Recur(1,i,1,j);
		}
	}
}
*/
int main() {
	//freopen("c:\\h.in","r",stdin);
	Ini();
	//Set();
	while(scanf("%s",com) != EOF) {
		Cal();
		Free();
	}
	return 0;
}

