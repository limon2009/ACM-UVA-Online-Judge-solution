#include<iostream>
#include<list>
#include<string.h>
#include<set>

#define maxn 100000
using namespace std;

char Dic[maxn][15];
char Word[15];

int N, Maxx, D, maxLen;
int Sum[20];
char X[20];

set<string>S;

struct ss {
	char ch;
	int val;
}L[12];

int com(const void *a, const void *b) {
	ss *x, *y;
	x = (ss *)a;
	y = (ss *)b;
	return y->val - x->val;
}

int com1(const void *a, const void *b) {
	return *(char *)a - *(char *)b;
}

void Add() {
	int i;
	Sum[0] = L[0].val;
	for(i = 1; i<D; i++) 
		Sum[i] = Sum[i-1] + L[i].val;
}

void Recur(int n, int level, int limit, int cost) {
		int i, j, *p, d;
		Word[level-1] = L[n].ch;
		if(level == limit) {
			Word[level] = NULL;
			strcpy(X,Word);
			qsort(X,limit,1,com1);
			if( S.find(X) != S.end() && cost > Maxx){
				Maxx = cost;
				//cout<<Word<<endl;
			}
			return;
		}
		
		d = level + (D - n) - 1;
		if(d < limit) return;
		
		d = limit - level;
		d += n;
		j = Sum[d] - Sum[n];
		if(cost + j <= Maxx) return;

		for(i = n+1; i<D; i++) {
			Recur(i,level+1,limit,cost+L[i].val);
		}
}

void NCR(int limit) {
	int i;
	for(i = 0; i<D; i++) 
		Recur(i,1,limit,L[i].val);
}

void Find() {
	int i;
	for(i = D; i>=1; i --) {
		if(Sum[i-1] <= Maxx) continue;
		NCR(i);
	}
}

void Cal() {
	int n;
	int  i;
	cin>>n;
	while(n--) {
		cin>>D;
		Maxx = 0;
		for(i = 0; i<D; i++)
			cin>>L[i].ch>>L[i].val;
		qsort(L,D,sizeof(ss),com);
		Add();
		Find();
		cout<<Maxx<<endl;
	}
}

int main() {
	int n, j, f, k = 0;
	char ss[100];
//	freopen("c:\\h.txt","r",stdin);
//	freopen("c:\\out.ans","w",stdout);
	maxLen = 0;
	cin>>f;
	N = 0;
	for(int i = 0; i<f; i++){
		cin>>ss;
		n = strlen(ss);
		if(n > maxLen) maxLen = n;
		qsort(ss,n,sizeof(char),com1);
		if(S.find(ss) == S.end()) {
			S.insert(ss);
			strcpy(Dic[N++],ss);
		}
	}
	Cal();
	return 0;

}
