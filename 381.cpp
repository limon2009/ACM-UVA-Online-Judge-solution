#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

using namespace std;

typedef double dd;

int S, T;
dd Mean, Sd;

struct ss {
	int CT[11];
	int bns,abs;
	dd Avg,adAvg;
	int Gra,AdjGra;
}stu[32];

int com(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

void ReadCase() {
	int i, j;
	cin>>S>>T;
	for(i = 0; i<S; i++) {
		for(j = 0; j<T; j++)
			cin>>stu[i].CT[j];
		cin>>stu[i].bns>>stu[i].abs;
	}
}

dd Near(dd x) {
	char ss[30];
	sprintf(ss,"%.1lf",x);
	return atof(ss);
}

void SetAvg() {
	int i, j,t;
	dd avg, sum, p, ovsum = 0;
	p = 1;
	if(T>=2) {
		for(i = 0; i<S; i++)
			qsort(stu[i].CT,T,sizeof(int),com);
		
	}
	t = T;
	if(T>2) t = T-1;
	for(i = 0; i<S; i++) {
		sum = 0;
		for(j = 0;  j<t; j++)
			sum += stu[i].CT[j];
		sum = Near(sum);
		avg = sum/(dd)t;
		stu[i].Avg = avg;
		ovsum += stu[i].Avg;
	}
	Mean = ovsum/(dd)S;
}

void SetAdjAvg() {
	int i,  p;
	for(i = 0; i<S; i++) {
		p = stu[i].bns/2;
		p *= 3;
		stu[i].adAvg = (dd)p+stu[i].Avg;
	}
}

void SetSd() {
	int i;
	dd sum = 0, p;
	for(i = 0; i<S; i++) {
		p = stu[i].Avg-Mean;
		p *= p;
		sum += p;
	}
	p = sum/(dd)S;
	Sd = sqrt(p);
}

int Result(double avg) {
	dd a, b;
	a = Sd + Mean;
	b = Mean - Sd;
	if(avg>=a) return 4;
	else if(avg>=Mean && avg<a) return 3;
	else if(avg>=b && avg<Mean) return 2;
	return 1;
}

int SetAdjGra(int n) {
	int p, t;
	if(stu[n].abs == 0) p = 1;
	else 
		p = -(stu[n].abs/4);
	t = stu[n].Gra + p;
	if(t>=4) return 4;
	if(t<=0) return 0;
	return t;
}

void SetGra() {
	int i, sum = 0;
	dd  t;
	for(i = 0; i<S; i++) {
		stu[i].Gra = Result(stu[i].adAvg);
		stu[i].AdjGra = SetAdjGra(i);
		sum += stu[i].AdjGra;
	}
	t = (dd)sum/(dd)S;
	printf("%.1lf\n",t);
}

void Cal() {
	SetAvg();
	SetAdjAvg();
	SetSd();
	SetGra();
}

int main() {
	int kase;
	cin>>kase;
	cout<<"MAKING THE GRADE OUTPUT\n";
	while(kase--) {
		ReadCase();
		Cal();
	}
	cout<<"END OF OUTPUT\n";
	return 0;
}
