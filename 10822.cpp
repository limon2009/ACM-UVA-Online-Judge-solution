#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<stdio.h>
using namespace std;

#define max 50002

struct node {
	int nam;
	int tp;
	node *next;
};

struct edge {
	char visit;
	char val;
	node *next;
};

edge E[max];
int Ind, Enc;
char conf[3][3];
queue<int>Q;


void Set() {
	conf[0][1] = conf[1][2] = conf[2][0] = 1;
}

void ReadCase() {
	int u, v, d = 0;
	node *x;
	char ss[1000], *tt;
	while(d<Enc) {
		cin>>ss;
		tt = strtok(ss,"(>)");
		while(tt) {
			u = atoi(tt);
			tt = strtok(NULL,"(>)");
			v = atoi(tt);
			x = new node;
			x->nam = v;
			x->tp = 0;
			x->next = E[u].next;
			E[u].next = x;
			x = new node;
			x->nam = u;
			x->tp = 1;
			x->next = E[v].next;
			E[v].next = x;
			tt = strtok(NULL,"(>");
			d ++;
		}
	}
}

int BFS(int st) {
	int u, v, t, v1, v2, f = 0;
	E[st].val = 0;
	node *x;
	E[st].visit = 1;
	Q.push(st);
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		if(f) continue;
		x = E[u].next;
		v1 = E[u].val;
		while(x) {
			v = x->nam;
			t = x->tp;
			v2 = E[v].val;
			if(!t) {
				if(E[v].visit == 1) {
					if(!conf[v1][v2]) f = 1;
				}else {
					E[v].val = (v1+1) % 3;
					E[v].visit = 1;
					Q.push(v);
				}
			}else {
				if(E[v].visit == 1) {
					if(!conf[v2][v1]) f =  1;
				}else {
					E[v].val = (v1 - 1 + 3) % 3;
					E[v].visit = 1;
					Q.push(v);
				}
			}
			x = x->next;
		}
	}
	return f;
}

void Cal() {
	int i, dis = 0, d;
	for(i = 1; i<= Ind; i++){
		E[i].visit = 0;
	}
	for(i = 1; i<= Ind; i++) {
		if(E[i].visit == 0) {
			dis ++;
			d = BFS(i);
			if(d) {
				puts("Conflicting Records");
				return;
			}
		}
	}
	if(dis > 1) puts("Not Enough Data");
	else puts("Observation Complete");
}

void Reset() {
	int i;
	for(i = 1; i<= Ind; i++)
		E[i].next = NULL;
}

int main() {
	int ks, k = 1;
//	freopen("h.txt","r",stdin);
	Set();
	cin>>ks;
	cout<<"Community "<<k++<<": ";
	while(ks--) {
		cin>>Ind>>Enc;
		ReadCase();
		Cal();
		if(ks) {
			Reset();
			cout<<"Community "<<k++<<": ";
		}
	}
	return 0;

}

