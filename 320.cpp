#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

#define MAXN 1030

char Move[MAXN];
char B[33][33];

void Set() {
	int i;
	for(i = 0; i<33; i++)
		memset(B[i],'.',32);
}

void Cal(int r, int c) {
	int i;
	for(i = 0; Move[i]; i++) {
		if(Move[i] == '.') break;
		switch(Move[i]) {
		case 'E':B[r+1][c]	= 'X'; c++;	break;
		case 'N':B[r][c]	= 'X'; r--;	break;
		case 'W':B[r][c-1]	= 'X'; c--;	break;
		case 'S':B[r+1][c-1]= 'X'; r++;	break;
		}
	}
}

void Print() {
	int i;
	for(i = 0; i<32; i++){
		B[i][32] = NULL;
		cout<<B[i]<<endl;
	}
}

int main() {
	int kase, r, c, g = 1;
	cin>>kase;
	while(kase--) {
		cin>>c>>r;
		cin>>Move;
		Set();
		Cal(31-r,c);
		cout<<"Bitmap #"<<g++<<endl;
		Print();
		cout<<endl;
	}
	return 0;
}


