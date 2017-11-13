#include<iostream>
#include<vector>

using namespace std;

vector<int>C;
char Fg[10000];

void Cal(int cat) {
	int i, sub, req, ok = 1, n, c;
	while(cat --) {
		cin>>sub>>req;
		c = 0;
		while(sub--) {
			cin>>n;
			if(Fg[n] )
				c++;
		}
		if(c < req) ok = 0;
	}
	if(ok) cout<<"yes\n";
	else cout<<"no\n";
	for(i = 0; i<C.size(); i++)
		Fg[C[i]] = 0;

	C.clear();
}

int main() {
	int taken, cat, n;
	while(cin>>taken && taken) {
		cin>>cat;
		for(int i = 0; i<taken; i++) {
			cin>>n;
			Fg[n] = 1;
			C.push_back(n);
		}
		Cal(cat);
	}
	return 0;

}
