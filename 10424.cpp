#include<stdio.h>

char name1[27],name2[27];
int score1,score2;

int compute()
{
    int i,j;
    score1=0;
    score2=0;
    for(i=0; name1[i]; i++)
    {
	if(name1[i]>=97 && name1[i]<=122)
	  score1+=name1[i]-96;
	else if(name1[i] >=65 && name1[i] <= 90)
	  score1+=name1[i]-64;
     }

    for(i=0; name2[i]; i++)
    {
	if(name2[i]>=97 && name2[i]<=122)
	  score2+=name2[i]-96;
	else if(name2[i] >=65 && name2[i] <= 90)
	  score2+=name2[i]-64;

    }
    return 0;

}

float digit(int dig)
{
   int sum;
   while(dig>=10)
   {
      sum = 0;
      while(dig)
      {
	 sum+=dig%10;
	 dig=dig/10;
      }
      dig=sum;
   }
  return dig;
}

int result( float s1,float s2)
{
    float res;
    char per[3] = "%";
    if(s1>=s2)
      res=(s2*100)/s1;
    else
      res=(s1*100)/s2;
    printf("%.2f %s\n",res,per);
    return 0;
}


int main()
{
    float s1,s2;
    while(gets(name1))
    {
       gets(name2);
       compute();
       s1=digit(score1);
       s2=digit(score2);
       result(s1,s2);
    }

    return 0;
}

