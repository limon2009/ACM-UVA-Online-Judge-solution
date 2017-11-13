#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MIN(a, b)  (a>b?b:a)

#define MAXN 200

char Tname[110], Dis[200];
int  T, N, Pld;


struct Game {
     int index;
	 char name[40];
	 int pt;
	 int goal;
	 int agoal;
	 int win;
	 int played;
	 int loss;
	 int ties;
}V[31], temp;

int com1(const void *x, const void *y) {
   Game *p = (Game *)x;
   Game *q = (Game *)y;
   return strcmp(p->name, q->name);
}


int StrCmp(char temp[], char dummy[]) {
	int i, l;
	l = MIN(strlen(temp),strlen(dummy));
	for(i = 0; i<l; i++) {
		if(tolower(temp[i]) > tolower(dummy[i])) return 1;
		else if(tolower(temp[i]) < tolower(dummy[i])) return -1;
	}
	if(strlen(temp)>strlen(dummy)) return 1;
	else if(strlen(temp)<strlen(dummy)) return -1;
	return 0;
}
int com2(const void *x, const void *y) {
   Game *p = (Game *)x;
   Game *q = (Game *)y;
   if(p->pt>q->pt) return -1;
   else if(p->pt<q->pt) return 1;
   else if(p->win > q->win) return -1;
   else if(p->win <q->win) return 1;
   else if( (p->goal - p->agoal) > (q->goal - q->agoal) )
	   return -1;
   else if( (p->goal - p->agoal) < (q->goal - q->agoal) )
	   return 1;
   else if(p->goal > q->goal) return -1;
   else if(p->goal < q->goal) return 1;
   else if(p->played > q->played) return 1;
   else if(p->played <q->played ) return -1;
   else return StrCmp(p->name,q->name);
   //return 0;

}

void Result(int in1, int t1, int in2, int t2) {
    
	if( t1 > t2) {
		V[in1].pt += 3;
		V[in1].win ++;
		V[in2].loss ++;
	}
	else if(t1<t2){
		V[in2].pt += 3;
		V[in2].win ++;
		V[in1].loss ++;
	}
	else{
		V[in1].pt += 1;
		V[in2].pt += 1;
		V[in1].ties ++;
		V[in2].ties ++;
	}

    V[in1].played ++;
	V[in2].played ++;
	V[in1].goal += t1;
	V[in2].goal += t2;
	V[in1].agoal += t2;
	V[in2].agoal += t1;
}

void Sep() {
	int i, j,t1, t2, m = 0;
	int in1, in2;
	Game *p;
	char g1[5];
	for(i = 0;Dis[i] != '#'; i++)
      temp.name[m++] = Dis[i];
    temp.name[m] = NULL;
	m = 0;
	for(j = i+1; Dis[j] != '@'; j++)
		g1[m++] = Dis[j];
	g1[m] = NULL;
	t1 = atoi(g1);
	p = (Game *)bsearch(&temp,V,T,sizeof(V[0]),com1);
 	in1 = p->index;
	m = 0;
	for(i = j+1; Dis[i] != '#'; i++)
       g1[m++] = Dis[i];
	g1[m] = NULL;
	t2 =atoi(g1);
	m = 0;
	for(j = i+1; Dis[j]; j++)
       temp.name[m++] = Dis[j];
	temp.name[m] = NULL;
	p = (Game *)bsearch(&temp,V,T,sizeof(V[0]),com1);
	in2 = p->index;
	Result(in1,t1,in2,t2);
}


void Cal() {
   int i;
   for(i = 0; i<Pld; i++) {
      gets(Dis);
	  Sep();
   }
   qsort(V,T,sizeof(V[0]),com2);
   for(i = 0; i<T; i++){
	   printf("%d) %s %dp, %dg",i+1,V[i].name,V[i].pt,V[i].played);
	   printf(" (%d-%d-%d), ",V[i].win,V[i].ties,V[i].loss);
       printf("%dgd (%d-%d)\n",V[i].goal-V[i].agoal,V[i].goal,V[i].agoal);
   }
}


int main() {
   int i, n;
   char input[100];
   gets(input);
   sscanf(input,"%d",&n);
   while(n -- ) {
      gets(Tname);
	  printf("%s\n",Tname);
	  gets(input);
	  sscanf(input,"%d",&T);
	  for(i = 0; i<T; i++) {
	     gets(V[i].name);
		 V[i].agoal = V[i].goal = 0;
		 V[i].win = V[i].played = V[i].pt = 0;
		 V[i].loss = V[i].ties = 0;
	  }
	  qsort(V,T,sizeof(V[0]),com1);
	  for(i = 0; i<T; i++)
		  V[i].index = i;
	  gets(input);
	  sscanf(input,"%d",&Pld);
	  Cal();
	  if(n) printf("\n");
   }
	return 0;

}
