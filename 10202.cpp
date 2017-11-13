#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>V;
vector<int>A, T;
int N, K;

int Search(int key) {
	int lo = 0, up = V.size()-1;
	int mid = (lo + up) / 2;
	while(V[mid] != key && lo < up) {
		if(V[mid] > key )
			up = mid-1;
		else lo = mid+1;
		mid = (lo + up)/2;
	}
	if(V[mid] != key)
		return -1;
	return mid;
}


int Find(int smallV) {
	int i, j, nextsum, nextV, sum;
	A.push_back(smallV);
	while(V.size() > 0) {
		nextsum = V[0];
		nextV = V[0] - smallV;
		for(i = 0; i<A.size(); i++) {
			sum = nextV+A[i];
			j = Search(sum);
			if(j>=0) {
				V.erase(find(V.begin(),V.end(),V[j]));
			}
			else return 0;
		}
		A.push_back(nextV);

	}
	return 1;
}

void Print() {
	int i;
	cout<<A[0];
	for(i = 1; i<A.size(); i++)
		cout<<" "<<A[i];
	cout<<endl;
}

void Cal() {
	int i, j, k;
	for(i = 2; i<N; i++) {
		k = T[0] + T[1] - T[i];
		if(k%2 == 0) {
			V = T;
			if(Find(k/2)) {
				Print();
				return;
			}
			A.clear();
		}
	}
	cout<<"Impossible\n";
}

int main() {
	int i, n;
//	freopen("h.txt","r",stdin);
	while(cin>>K) {
		N = (K * (K-1))/2;
		for(i = 0; i<N; i++) {
			cin>>n;
			T.push_back(n);
		}
		sort(T.begin(),T.end());
		Cal();
		T.clear();
		A.clear();
	}
	return 0;
}

