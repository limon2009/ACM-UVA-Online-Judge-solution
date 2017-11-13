#include<iostream>
#include<string.h>

using namespace std;

char ss[102];
int fre[30], count, len;

int F() {
	int i, j;
	len = strlen(ss);
	for(i = 0; ss[i]; i++) {
		j = ss[i] - 'a';
		fre[j]++;
	}
	j = 0;
	for(i = 0; i<26; i++) {
		if(fre[i]%2) j++;
	}
	if(j>1) return 1;
	if(j>0 && len%2 == 0) return 1;
	return 0;
}

int FindB(int n, int m, char ch) {
	int i;
	for(i = m; i>n; i--) 
		if(ss[i] == ch) break;
	return i;
}

int FindF(int n, int m, char ch){
	int i;
	for(i = n; i<m; i++)
		if(ss[i] == ch) break;
	return i;
}
void MoveB(int n, int m, char ch) {
	int i;
	for( i = n; i<m; i++)
		ss[i] = ss[i+1];
	ss[m] = ch;
}

void MoveF(int n, int m, char ch) {
	int i;
	for(i = m; i>n; i--)
		ss[i] = ss[i-1];
	ss[n] = ch;
}

void Recur(int lo, int up) {
	int  k, l, ind1, d1, d2, ind2;
	if(lo >= up) return;
	k = ss[lo] - 'a';
	l = ss[up] - 'a';
	if(ss[lo] == ss[up]) Recur(lo+1,up-1);
	else {
		d1 = d2 = 1000;
		if(fre[k] > 1) {
			ind1 = FindB(lo,up,ss[lo]);
			d1 = up - ind1;
		}
		if(fre[l] > 1){
			ind2 = FindF(lo,up,ss[up]);
			d2 = ind2 - lo;
		}
		if(d1<= d2) {
			count += d1;
			MoveB(ind1,up,ss[lo]);
			fre[k] -= 2;
			Recur(lo+1,up-1);
		}
		else {
			count += d2;
			MoveF(lo,ind2,ss[up]);
			fre[l] -= 2;
			Recur(lo+1,up-1);
		}
	}
}

void Cal() {
	if(F()) {
		cout<<"Impossible\n";
		return;
	}
	count = 0;
	Recur(0,strlen(ss)-1);
	cout<<count<<endl;
}
int main() {
	int k;
	cin>>k;
	while(k--) {
		cin>>ss;
		Cal();
		for(int i = 0; i<26; i++) fre[i] = 0;
	}
	return 0;

}
