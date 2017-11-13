#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAXN 1000000

char St[MAXN];
char input[MAXN];

int sth, rh, N, td;

struct ss {
	int val;
}data[MAXN];

void SetStack() {
	int i, j, k, f ;
	char temp[20];
	for(i = rh; input[i]; i++) {
		if(input[i] == ' ') continue;
		if(input[i] == '(') {
			St[sth++] = '(';
			data[td++].val = -214748364;
		}
		else if(input[i] == ')') {
			sth--;
			data[td++].val = -214748364;
		}
		else if(isdigit(input[i]) || input[i] == '-') {
			f = 1;
			if(input[i] == '-'){
				f = -1;
				i++;
			}
			for(j = i, k = 0; isdigit(input[j]) && input[j]; j++)
				temp[k++] = input[j];
			temp[k] = NULL;
			data[td++].val = f * atoi(temp);
			i = j-1;
		}
	}
}

int Recur(int val) {
	if(data[rh+3].val == -214748364 && data[rh+5].val == -214748364) {
		rh += 6;
		if(val == N) return 1;
		return 0;
	}
	if(data[rh+3].val != -214748364) {
		rh += 2;
		if(Recur(val+data[rh+1].val)) return 1;
		rh++;
		if(data[rh+1].val != -214748364) {
			if(Recur(val+data[rh+1].val)) return 1;
			rh++;
		}else {
			rh += 2;
			return 0;
		}
	}else {
		rh += 4;
		if(Recur(val+data[rh+1].val)) return 1;
		rh++;
	}
	return 0;
}
void Cal() {
	if(td <= 2) {
		printf("no\n");
		return;
	}
	rh = 0;
	if(Recur(data[1].val)) printf("yes\n");
	else printf("no\n");
}

int Blank() {
	int i;
	for(i = 0; input[i]; i++) {
		if(isdigit(input[i]) || input[i] == '(' || input[i] == ')')
			return 0;
		if(input[i] == '-') return 0;
	}
	return 1;
}
void Set() {
	int i, k = 0, f;
	char temp[50];
	for(i = 0; input[i] && input[i] == ' '; i++);
	f = 1;
	if(input[i] == '-') {
		f = -1;
		i++;
	}
	for(i; isdigit(input[i]); i++) temp[k++] = input[i];
	temp[k] = NULL;
	N = f * atoi(temp);
	rh = i;
	f = 0;
	while(1) {
		for(i =rh; input[i]; i++) {
			if(input[i] == '(') {
				f = 1;
				break;
			}
		}
		if(f)break;
		else {
			gets(input);
			rh = 0;
		}
	}
	sth = td = 0;
	SetStack();
	while(sth) {
		rh = 0;
		gets(input);
		SetStack();
	}
}

int main() {
	int i;
//	freopen("c:\\h.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);
	while(gets(input)) {
		if(Blank()) continue;
		Set();
		Cal();
	}
	return 0;

}
