#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


unsigned long rev(unsigned long n)
 {
     int i,k,str_len;
     char str_n[20],rev_str[20];
     unsigned long rev_num;
     k = 0;
     sprintf(str_n,"%lu",n);
     str_len = strlen(str_n);

     for(i = str_len-1; i >= 0; i--)
       rev_str[k++]=str_n[i];

     rev_str[k]=NULL;

     rev_num = atof(rev_str);
     return rev_num;
 }



 main()
 {
    unsigned long num,sum,n,k,m;
    int kase,step;
    scanf("%d",& kase);
    while(kase -- )   {

       scanf("%lu",&num);
       n = rev(num);
       k = n + num;
       step = 1;
       while(1)
       {
	  n = rev(k);
	  if(n == k)  break;
	  m = n + k;
	  k = m;
	  step++;
       }

       printf("%d %lu\n",step,k);
    }
    return 0;
 }
