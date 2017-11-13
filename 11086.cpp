#include<iostream>

using namespace std;
#define maxn 1048579

char sv[maxn];
int Com[maxn];

void Table() {
	int i, j;
	for(i = 2; i*i<maxn; ) {
		for(j = i+i; j<maxn; j+= i)
			sv[j] = 1;
		for(++i; sv[i]; i++);
	}
	for(i = 4; i<maxn;) {
		for(j = i+i; j<maxn; j += i)
			sv[j] = 0;
		for(++i; !sv[i] && i<maxn; i++);
	}
}
int main() {
	int n, k, c;
	Table();
	sv[1] = 0;
	while(cin>>n) {
		c = 0;
		while(n--) {
			cin>>k;
			if(sv[k]) c++;
		}
		cout<<c<<endl;
	}
	return 0;

}
