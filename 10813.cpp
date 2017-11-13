#include<iostream>
#include<vector>

using namespace std;

#define maxn 6

vector<int>B[maxn];
vector<int>ans;

struct ss {
	int r, c;
};

ss SS(int key) {
	int r, c, f = 0;
	ss temp;
	for(r = 1; r<6; r++) {

		for(c = 0; c<B[r].size(); c++) {
			if(B[r][c] == key){
				f = 1;
				break;
			}
		}
		if(f) break;
	}
	if(!f) {
		temp.r = -1;
		return temp;
	}
	temp.r = r;
	temp.c = c+1;
	if(r == 3) {
		temp.c = c+1;
		if(c>1) temp.c = c+2;
	}
	return temp;
}

int Cal() {
	int i, x;
	ss d;
	int r[6] = {0};
	int c[6] = {0};
	int dig1 = 1;
	int dig2 = 1;
	r[3] = 1;
	c[3] = 1;
	for(i = 0; i<ans.size(); i++) {
		d = SS(ans[i]);
		x = ans[i];
		if(d.r == -1) continue;
		r[d.r]++;
		c[d.c]++;
		if(d.r == d.c) dig1++;
		else if(d.r + d.c == 6) dig2++;
		if(r[d.r] == 5 || c[d.c] == 5 || dig1 == 5 || dig2 == 5) break;
	}
	return i+1;
}

void Free() {
	int i;
	for(i = 0; i<= 5; i++)
		B[i].clear();
	ans.clear();
}

#include<stdio.h>

int main() {
	int ks, i, j, n, k;
//	freopen("h.txt","r",stdin);
	cin>>ks;
	while(ks--) {
		for(i = 1; i<6; i++){
			k = 6;
			if(i == 3) k = 5;
			for(j = 1; j<k; j++){
				cin>>n;
				B[i].push_back(n);
			}
		}
		for(i = 1; i<= 75; i++) {
			cin>>n;
			ans.push_back(n);
		}
		cout<<"BINGO after "<<Cal()<<" numbers announced"<<endl;
		Free();
	}
	return 0;

}
