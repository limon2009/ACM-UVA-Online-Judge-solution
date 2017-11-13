#include<iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

using namespace std;

char ss[100];

char sv[2002];

void Prime_table() {
	int i, j;
	for(i = 2; i*i < 2000; ) {
		for(j = i+i; j<2000; j += i) {
			sv[j] = 1;
		}
		for(++i; sv[i]; i++);
	}
}

int Cal() {
	int i, c = 0;
	for(i = 0; ss[i]; i++) {
		if(isupper(ss[i])) 
			c += ss[i] - 'A' + 27;
		else 
		        c += ss[i] - 'a' + 1;
	}
	return  c; 
		
}

int  main() {
	int i;
	Prime_table();
	while(gets(ss)) {
		i = Cal();
		if(sv[i] == 0) cout<<"It is a prime word.\n";
		else cout<<"It is not a prime word.\n";
	}
	return 0;
}
