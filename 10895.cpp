#include<stdio.h>
#include<vector>

using namespace std;


struct ss {
	int ind;
	vector< pair<int,int> >C;
};

ss *R;

int row, col;
int index[10002];

void Cal() {
	int i, j, nonz, v;
	for(i = 1; i<= row; i++) {
		scanf("%d",&nonz);
		for(j = 1; j<= nonz; j++)
			scanf("%d",&index[j]);
		for(j = 1; j<= nonz; j++) {
			scanf("%d",&v);
			R[index[j]].ind++;
			R[index[j]].C.push_back(make_pair(v,i));
		}
	}
}

void Print() {
	int i, j;
	printf("%d %d\n",col,row);
	for(i = 1; i<= col; i++) {
		printf("%d",R[i].ind);
		if(R[i].ind == 0)
			printf("\n");
		else {
			for(j = 0; j<R[i].C.size(); j++)
				printf(" %d",R[i].C[j].second);
			printf("\n%d",R[i].C[0].first);
			for(j = 1; j<R[i].C.size(); j++)
				printf(" %d",R[i].C[j].first);
		}
		printf("\n");

	}

}
void Set() {
	int i;
	for(i = 0; i<= col; i++) {
		R[i].ind = 0;
		R[i].C.clear();
	}
}
int main() {
	//freopen("h.txt","r",stdin);
	while(scanf("%d%d",&row,&col) == 2 ) {
		R = new ss[col+2];
		Set();
		Cal();
		Print();
	}
	return 0;

}
