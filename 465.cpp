#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 2147483647

 long n1,n2;
 char number_1[10000],number_2[10000],op[2];

   int frist_n(char a[])
   {
       int len,i;
       long val=0;
       len=strlen(a);
       i=0;
       while(a[i]=='0'&&i<len)
       {
	 i++;
	 val++;
       }
       if(i==len&&a[i-1]=='0') { n1= 0; return 0; }
       if((len-val)>10) { printf("first number too big\n"); n1=-1;  return 0; }
       else if(atof(a)>MAXN) { printf("first number too big\n"); n1=-1; return 0; }
       else n1=atof(a);
       return 0;
   }



   int scend_n(char b[])
   {
       int len,i,val=0;
       len=strlen(b);
       i=0;
       while(b[i]=='0' && i<len)
       {
	 i++;
	 val++;
       }
       if(i==len && b[i-1]=='0') {  n2=0; return 0; }
       if((len-val)>10) { printf("second number too big\n"); n2=-1; return 0;}
       else if(atof(b)>MAXN) { printf("second number too big\n");  n2=-1; return 0;}
       else n2=atof(b);
       return 0;
   }


   int result(char b[],char a[],char op[])
   {

	long i,k;
	if(!n2||!n1) return 0;
	else if(n1==-1||n2==-1) printf("result too big\n");
	else
	{
	   if(op[0]=='+')
	     if(atof(a)+atof(b)>MAXN) printf("result too big\n");

	   if(op[0]=='*')
	     if(atof(a)*atof(b)>MAXN) printf("result too big\n");
	}
	return 0;
   }

   int main()
   {

       while(scanf("%s %s %s",number_1,op,number_2)==3)
       {
	    n1=1;n2=2;
	    printf("%s %s %s\n",number_1,op,number_2);
	    frist_n(number_1);
	    scend_n(number_2);
	    result(number_1,number_2,op);

       }

       return 0;
   }
