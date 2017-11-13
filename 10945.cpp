#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

string A, R;

char ss[1000000];


int Cal() {
	int i = 0, d;
	d = A.size() - 1;
	while(i <= d) {
		if(A[d] != A[i]) return 0;
		i++;
		d--;
	}
	return 1;
}

int main() {
	int i;
	while(1) {
		gets(ss);
		if(!strcmp(ss,"DONE")) break;
		A = "";
		R = "";
		for(i = 0; ss[i]; i++){
			if(isalpha(ss[i]))
				A += tolower(ss[i]);
		}
		if(Cal()) cout<<"You won't be eaten!\n";
		else cout<<"Uh oh..\n";
	}
	return 0;

}
