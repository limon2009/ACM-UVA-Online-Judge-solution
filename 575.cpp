#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
    char sk[100];
    int i,c,l;
    long dec;
    while(scanf("%s",sk) && strcmp(sk,"0"))
    {
	 l = strlen(sk);
	 c = 1;
	 dec = 0;
	 for(i = l-1; i>=0; i--)
	 {
	     if(sk[i] =='0')
	     {
		c++;
		continue;
	     }
	     else if(sk[i] == '1')
	     {
		dec += (pow(2,c)-1);
		c++;
	     }
	     else
	     {
		dec += 2*(pow(2,c)-1);
		c++;
	     }
	 }
	 printf("%ld\n",dec);
    }
    return 0;
}
