#include<iostream>
#include<string.h>

using namespace std;

int B,S;

char BS[1000][1000];
char SS[1000][1000];

int Zero(int r, int c) {
	int i, j, d;
	d = B - c + 1;
	if(S > d)
		return 0;
	d = B - r + 1;
	if( S > d)
		return 0;

	for(i = r; i < r + S ; i++) {
		for(j = c; j<c+S; j++) {
			if(SS[i - r][j - c] != BS[i][j]) return 0;
		}
	}
	return 1;
}

int Nine(int r, int c) {
	int i, j, d, k;
	d = B - c + 1;
	if(S > d)
		return 0;
	d = B - r + 1;
	if( S > d)
		return 0;

	for(i = 0; i <S; i++) {
		k = c;
		for(j = S-1; j>=0; j--) {
			if(SS[j][i] != BS[r][k++]) return 0;
		}
		r ++;
	}
	return 1;
}

int One(int r, int c) {
	int i, j, d, k;
	d = B - c + 1;
	if(S > d)
		return 0;
	d = B - r + 1;
	if( S > d)
		return 0;

	for(i = S-1; i >=0 ; i--) {
		k = c;
		for(j = S-1; j>=0; j--) {
			if(SS[i][j] != BS[r][k++]) return 0;
		}
		r ++;
	}
	return 1;
}


int Three(int r, int c) {
	int i, j, d, k;
	d = B - c + 1;
	if(S > d)
		return 0;
	d = B - r + 1;
	if( S > d)
		return 0;

	for(i = S-1; i >= 0; i--) {
		k = c;
		for(j = 0; j<S; j++) {
			if(SS[j][i] != BS[r][k++]) return 0;
		}
		r ++;
	}
	return 1;
}

void Cal() {
	int i, j, z, n, o, t;
	z = n = o = t = 0;
	for(i = 0; i<S; i++)
		cin>>SS[i];
	for( i = 0; i+S<=B; i++) {
		for(j = 0; j+S<=B; j++) {
			if(Nine(i,j)) n ++;
			if(Zero(i,j)) z ++;
			if(One(i,j))  o ++;
			if(Three(i,j)) t ++;
		}
	}
	cout<<z<<" "<<n<<" "<<o<<" "<<t<<endl;
}

//#include<stdio.h>
int main() {
	int i;
//	freopen("c:\\h.txt","r",stdin);
	while(cin>>B>>S) {
		if(!B && !S) break;
		for(i = 0; i<B; i++)
			cin>>BS[i];
		Cal();
	}
	return 0;

}
