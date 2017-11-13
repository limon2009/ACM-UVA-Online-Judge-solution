#include<iostream>

using namespace std;

int sum(int n) {
   int sum = 0;
   int A[35], ind = 0;
   while(n) {
       sum += n%2;
       A[ind++] = n%2;
       n/=2;
    }
    cout<<" ";
    for(int i = ind-1; i>=0; i --) {
       cout<<A[i];
    }
    cout<<" is "<<sum<<" (mod 2).\n";
    return 0;
}

int main() {
   int n;
   while(cin>>n && n) {
     cout<<"The parity of";
     sum(n);
   }
   return 0;
}
