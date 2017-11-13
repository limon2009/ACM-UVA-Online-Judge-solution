#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXN 10001
	     /* 10001*/
int N;
int Total;
struct Wood {
       char Nam[31];
       double Fre;
}Sp[MAXN],tree;


int com(const void *a, const void *s) {
   Wood *c = (Wood *)a;
   Wood *d = (Wood *)s;
   return  strcmp( c->Nam ,d->Nam );
}

void ReadCase() {
     int i;
     Wood *j;
   
     N = 0;
     while(gets(tree.Nam)) {
	for(i = 0;  tree.Nam[i]; i ++)
	   if(tree.Nam[i] == '\n') tree.Nam[i] = NULL;
	if(strlen(tree.Nam) < 1) break;
	N++;
	j = (Wood *) bsearch(&tree,Sp,Total,sizeof(Sp[0]),com);
	if(j != NULL)
	     j->Fre++;
	else   {
	   strcpy(Sp[Total].Nam,tree.Nam);
	   Sp[Total].Fre++;
	   Total++;
	   qsort(Sp,Total,sizeof(Sp[0]),com);
       }
     }
}

void SolvedCase() {
    int i;
    for(i = 0; i<Total; i ++)
       printf("%s %.4lf\n",Sp[i].Nam,(Sp[i].Fre * 100.0) / (double)N);


}
int main()    {
   int i, j, kase;
   char input[100];
   gets(input);
   sscanf(input,"%d",&kase);
   gets(input);
   while(kase--) {
	 Total = 0.0;
	 ReadCase();
	 SolvedCase();
	 if(kase) {
	   putchar('\n');
	   for(i = 0; i<1001; i ++)
	      Sp[i].Fre = 0;
	 }
   }
	return 0;

}
