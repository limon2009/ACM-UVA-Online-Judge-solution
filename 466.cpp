#include<stdio.h>
#include<string.h>

#define MAXN 12

char Org[MAXN][MAXN], New[MAXN][MAXN];
char Ref[MAXN][MAXN];
int N, Kase;

int Rot_90() {
	char temp[MAXN];
	int i, j, c, f = 1;
	for(i = 0; i<N; i++) {
		c = 0;
		for(j = N-1; j>=0; j--) 
		  temp[c++] = Org[j][i] ;
		temp[c] = NULL;
		if(strcmp(New[i],temp)){
			f = 0;
			break;
		}
	}
	return f;
}

int Rot_180() {
	char temp[MAXN];
	int i, j, c, f = 1, m = 0;
	for(i = N-1; i>=0; i--) {
		c = 0;
		for(j = N-1; j>=0; j--) 
			temp[c++] = Org[i][j];
		temp[c] = NULL;
		if(strcmp(New[m++],temp)){
			f = 0;
			break;
		}
	}
	return f;
}

int Rot_270() {
	char temp[MAXN];
	int i, j, c, f = 1, m = 0;
	for(i = N-1; i>=0; i--) {
		c = 0;
		for(j = 0; j<N; j++) 
			temp[c++] = Org[j][i];
		temp[c] = NULL;
		if(strcmp(New[m++],temp)){
			f = 0;
			break;
		}
	}
	return f;
}

int ReF() {
	int i, f = 1, c = 0;
	for(i = N-1; i>=0; i--) {
		strcpy(Ref[c++],Org[i]);
		if(strcmp(Ref[c-1],New[c-1]))
			f = 0;
	}
	return f;
}


int Match(int f) {
	if(Rot_90()) {
		if(f) printf("reflected vertically and ");
		printf("rotated 90 degrees."); 
		return 1;
	}
	else if(Rot_180()) {
		if(f) printf("reflected vertically and ");
		printf("rotated 180 degrees."); 
		return 1;
	}
	else if(Rot_270()) {
		if(f) printf("reflected vertically and ");
		printf("rotated 270 degrees."); 
		return 1;
	}
	return 0;
	
}

void Cal() {
	int i;
	printf("Pattern %d was ",Kase++);
	if(Match(0)) return;
	else if(ReF()) {
		printf("reflected vertically.");
		return;
	}
	for(i = 0; i<N; i++) strcpy(Org[i],Ref[i]);
	if(Match(1)) return;
    printf("improperly transformed.");	
}

int main() {
	 Kase = 1;
	int i, f;
	while(scanf("%d",&N) == 1) {
		f = 0;
		for(i = 0; i<N; i++){
			scanf("%s%s",Org[i],New[i]);
			if(strcmp(Org[i],New[i]))
				f = 1;
		}
		if(!f) printf("Pattern %d was preserved.",Kase++);
		else Cal();
		printf("\n");
	}
	return 0;
}
