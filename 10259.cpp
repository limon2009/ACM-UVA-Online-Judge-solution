#include<iostream>

using namespace std;

#define MAXNn 103



#define MX(a,b) (a>b?a:b)



int N, B[MAXNn][MAXNn], MAXN, K, large;

int Or[MAXNn][MAXNn];



void BFS() {

	int i, nx, ny, pos, j, k;

	B[1][1] = Or[1][1];

	MAXN = B[1][1];

	for(k = B[1][1]; k<=100; k++) {

		for(i = 1; i<=N; i++) {

			for(j = 1; j<=N; j++) {

				if(Or[i][j] != k) continue;

				for(pos = -K; pos<= K; pos++) {

					ny = j + pos;

					if(ny>0 && ny<=N) {

						if(Or[i][j] < Or[i][ny]){

							B[i][ny] = MX(B[i][ny], B[i][j] + Or[i][ny]);

							MAXN = MX(B[i][ny],MAXN);

						}

					}

					nx = i+ pos;

					if(nx<1 || nx>N) continue;

					if(Or[i][j] < Or[nx][j]){

						B[nx][j] = MX(B[nx][j], B[i][j] + Or[nx][j]);

						MAXN = MX(B[nx][j],MAXN);

					}

				}

			}

		}

	}

}





void Cal(){

	BFS();

	cout<<MAXN<<endl;

}



int main() {

	int ks, i, j;

//	freopen("h.txt","r",stdin);

	cin>>ks;

	while(ks--) {

		cin>>N>>K;

		large = -1;

		for(i = 1; i <= N; i++) {

			for(j = 1; j <= N; j++){

				cin>>Or[i][j];

				large = MX(large,Or[i][j]);

				B[i][j] = -1000000;

			}

		}

		Cal();

		if(ks) cout<<"\n";

	}

	return 0;

}
