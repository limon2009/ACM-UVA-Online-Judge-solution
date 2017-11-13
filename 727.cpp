#include<stdio.h>
#include<stack>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

stack<char>S;
char Sym[] = "()[]{}";

void Cal(char ch) {
	int i;
	if(isdigit(ch)) {
		printf("%c",ch);
		return;
	}
	if(ch == '(' || ch == '[' || ch == '{'){
		S.push(ch);
		return;
	}
	if(ch == ')' || ch == ']' || ch == '}') {
		for(i = 1; Sym[i] !=ch; i+=2);
		while(S.top() != Sym[i-1]) {
			printf("%c",S.top());
			S.pop();
		}
		S.pop();
		return;
	}
	if(ch == '+' || ch == '-') {
		while(S.top() =='+'||S.top() =='-'||S.top() =='*'||S.top() =='/'){
			printf("%c",S.top());
			S.pop();
		}
		S.push(ch);
	}
	if(ch == '*' || ch == '/') {
		while(S.top() =='*'||S.top() =='/'){
			printf("%c",S.top());
			S.pop();
		}
		S.push(ch);
	}
}

int main() {
	char temp[100];
	int kase, i;
//	freopen("c:\\h.txt","r",stdin);
	gets(temp);
	kase = atoi(temp);
	gets(temp);
	while(kase--) {
		S.push('(');
		while(gets(temp)) {
			for(i = 0; temp[i]; i++){
				if(temp[i] == '\n') {
					temp[i] = NULL;
					break;
				}
			}
			if(strlen(temp) == 0) {
				break;
			}
			Cal(temp[0]);
		}
		Cal(')');
		printf("\n");
		if(kase) printf("\n");
	}
	return 0;

}
