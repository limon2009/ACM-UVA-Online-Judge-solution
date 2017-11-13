#include<stdio.h>
#include<string.h>
#include<math.h>


 char hex[]="0123456789ABCDEF";

 long hx(char n[])
 {
    int l,i,j,k=0;
    long sum=0;
    l=strlen(n);
    for(i=l-1;i>=0;i--)
    {
       for(j=0;hex[j];j++)
	if(n[i]==hex[j]) break;
	sum+=j*pow(16,k);
	k++;
    }
    return sum;
 }

 main()
 {
    int kase,k,i;
    long d1,d2,td;
    char h1[10],op[3],h2[10];
    scanf("%d",& kase);
    for(k=1;k<=kase;k++)
    {
       scanf("%s %s %s",h1,op,h2);
       d1=hx(h1);
       d2=hx(h2);

       if(op[0]=='+')
	td=d1+d2;
       else td=d1-d2;

       for(i=4096;i>0;i=i/2)
	if(d1 & i) printf("1");
	else printf("0");

	printf(" %s ",op);

	for(i=4096;i>0;i=i/2)
	 if(d2 & i) printf("1");
	 else printf("0");

	printf(" = %ld\n", td);
    }
   return 0;
 }

