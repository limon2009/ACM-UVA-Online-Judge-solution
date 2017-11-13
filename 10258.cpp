#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int MAXT;

struct ss {
	int pelt;
	int I;
	int cr;
	int temp[12];
	int f[13];
}V[102];


int com(const void *x, const void *y) {
     ss *a = (ss *)x;
	 ss *b = (ss *)y;
     if(a->I == 0 && b->I == 0) return 0;
	 if(a->cr > b->cr) return -1;
	 else if(a->cr < b->cr) return 1;
	 else if(a->cr == b->cr) {
	     if(a->pelt < b->pelt) return -1;
		 else if(a->pelt >b->pelt) return 1;
	 }
	 else if(a->I > b->I) return 1;
	 else if(a->I < b->I) return -1;
	 return 0;
	 
}

void  Readcase() {
    char fal[200];
	int i, k;
	int team, p, time;
	char res[9];
	for(i = 0; i<= 100; i++) {
		for(k = 1; k<=11; k++){
		  V[i].temp[k] = 0;
		  V[i].f[k] = 0;
		}
		V[i].cr = 0;
		V[i].pelt = 0;
		V[i].I = -1;
	}
	while(gets(fal)){
	      for(i = 0; fal[i]; i++)
			  if(fal[i] == '\n')
				  fal[i] = NULL;
           if(strlen(fal) <= 0) break;
		   k = sscanf(fal,"%d%d%d%s",&team,&p,&time,res);
           if(k<4) break;

		   if(team > MAXT)
			   MAXT = team;
		   team -= 1;
		   V[team].I = team;
		   if(res[0] == 'I')
			   V[team].temp[p] += 20;
		   else if(res[0] == 'C' && V[team].f[p] == 0) {
			   V[team].pelt += V[team].temp[p] + time;
			   V[team].temp[p] = 0;
			   V[team].cr ++;
			   V[team].f[p] = 1;
		   }

   }
}


void Sort() {
   int i;
   qsort(V,MAXT+1,sizeof(V[0]),com);
   for(i = 0; i<MAXT; i++){
	   if(V[i].I != -1) 
		  //break;
	   printf("%d %d %d\n",V[i].I+1,V[i].cr,V[i].pelt);
   }
	   

}

int main() {
   char fal[100];
   int kase;
   //freopen("c:\\h.txt","r",stdin);
    gets(fal);
   kase = atoi(fal);
   gets(fal);
   while(kase--) {
	   MAXT = 0;
	   Readcase();
	   Sort();
	   if(kase) {
		   printf("\n");
		  // gets(fal);
	   }
   }
      
	return 0;

}
