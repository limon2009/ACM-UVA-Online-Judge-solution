#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

string J, nJ;
string O, nO;

int N;

void AddJ(string ss) {
	int i;
	ss += "\n";
	J += ss;
	for(i = 0; i<ss.length(); i++) {
		if(isdigit(ss[i]))
			nJ += ss[i];
	}
}

void AddO(string ss) {
	int i;
	ss += "\n";
	O += ss;
	for(i = 0; i<ss.length(); i++) {
		if(isdigit(ss[i]))
			nO += ss[i];
	}
}

void Cal() {
	if(J.compare(O) == 0) {
		cout<<"Accepted\n";
		return;
	}
	if(nJ.compare(nO) == 0) {
		cout<<"Presentation Error\n";
		return;
	}
	cout<<"Wrong Answer\n";
}

int main() {
	char ss[200];
	int r = 1;
	//freopen("c:\\h.txt","r",stdin);
	while(1) {
		gets(ss);
		N = atoi(ss);
		if(!N) break;
		J = O = "";
		nJ = nO = "";
		while(N--) {
			gets(ss);
			AddJ(ss);
		}
		gets(ss);
		N = atoi(ss);
		while(N--) {
			gets(ss);
			AddO(ss);
		}
		cout<<"Run #"<<r++<<": ";
		Cal();
	}
	return 0;

}
