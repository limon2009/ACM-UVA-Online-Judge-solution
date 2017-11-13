#include<iostream>
#include<string.h>

using namespace std;

char ST[101];

struct ss {
	int P[101];
	int ind;
};

ss A[30];

void SetUp() {
	int i, j;
	for(i = 0; ST[i]; i++) {
		j = ST[i] - 'a';
		A[j].P[A[j].ind++] = i;
	}
}

void Cal() {
	int i, j, n, p, d;
	char ch1, ch2;
	cin>>n;
	while(n--) {
		cin>>p>>ch1>>ch2;
		j = ch1 - 'a';
		for(i = 0; i<A[j].ind; i++) {
			if(A[j].P[i] >= p) {
				d = A[j].P[i];
				ST[d] = ch2;
			}
		}
	}
	cout<<ST<<"."<<endl;
}

//#include<stdio.h>

int main() {
	int k = 1, i, j, p;
	char ch;
//	freopen("c:\\h.txt","r",stdin);
	while(cin>>ST) {
		SetUp();
		for(i = 0; i<26; i++) {
			cin>>ch;
			for(j = 0; j<A[i].ind; j++) {
				p = A[i].P[j];
				ST[p] = ch;
			}
		}
		cout<<"Case "<<"#"<<k++<<": "<<"The encoding string is ";
		Cal();
		cout<<endl;
		for(i = 0; i<26; i++) A[i].ind = 0;
	}
	return 0;

}
