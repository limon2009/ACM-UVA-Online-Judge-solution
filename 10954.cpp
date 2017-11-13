#include<queue>
#include<vector>
#include<iostream>

using namespace std;

priority_queue<int, vector<int> , greater<int> > P;

void Cal() {
	int ov, c;
	c = ov = 0;
	while(P.size() > 1) {
		c = P.top();
		P.pop();
		c += P.top();
		P.pop();
		ov += c;
		P.push(c);
	}
	P.pop();
	cout<<ov<<endl;
}

int main() {
	int temp, t;
	
	while(cin>>t && t) {
		while(t--) {
			cin>>temp;
			P.push(temp);
		}
		Cal();
	}
	
	return 0;
}
