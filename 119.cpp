#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char name[50][50],nam_1[50][50],nam[105],person[105],taka[105];
int main() {

     
     int tk,pe,aca[150],n,p,q,i,j,av;
     int FLGG = 0;
       for(p = 0; p <= 50; p ++) aca[p] = 0;

       while(scanf("%d", &n) == 1)  {
		if(FLGG == 1) {
			printf("\n");
		}
		FLGG = 1;
       for(i = 0; i<n; i ++)
	  scanf("%s", name[i]);
       for(i = 0; i<n; i ++) {
	  scanf("%s%s%s",nam,taka,person);

	  pe = atoi(person);
	  for(j = 0; j<pe; j ++)
	     scanf("%s",nam_1[j]);

	  tk = atoi(taka);


	  for(p = 0;p<n; p ++)
	    if(!strcmp(nam,name[p]))
	      break;


	  if(!tk || !pe) av = 0;
	  else
	  av = tk / pe;


	  aca[p] -= (tk-(tk-av * pe));

	  for(p = 0; p<pe; p ++) {
	    for(q = 0; q<n; q ++) {
	      if(!strcmp(nam_1[p],name[q]))
		break;
	    }
	    aca[q] += av;
	  }
       }
       for(i = 0; i<n; i ++)
	 printf("%s %d\n",name[i],aca[i]);

       for(p = 0; p<=50; p ++) aca[p] = 0;
     }
     return 0;
}
