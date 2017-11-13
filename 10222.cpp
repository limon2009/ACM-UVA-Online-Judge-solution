#include<stdio.h>

 main()
 {
    char *ch= "`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./qwertyuiopasdfghjklzxcvbnm<>?|(){}~!@#$%^&*()_+";
    char *ch2="`1`1234567890qwqwertyuiopasasdfghjklxxzxcvbnm,qwqwertyuiasasdfghjzxzxcvbnm<>&*op~!~!@#$%^&*()";
    char s[100];
    int i,j,k;
    gets(s);

       for(i=0;s[i];i++)
       {
	  k=1;
	  for(j=0;ch[j];j++)
	   if(s[i]==ch[j])
	   {
	      printf("%c",ch2[j]);
	      k=0;
	      break;
	   }
	    if(k)
	    printf("%c",s[i]);
       }
       printf("\n");
    return 0;
 }

