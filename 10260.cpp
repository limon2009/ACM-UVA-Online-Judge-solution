#include<stdio.h>

char ch[7][10] = {"AEIOUYHW ","BFPV","CGJKQSXZ","DT","L","MN","R"};
char word[30];
int cal()  {
  int i,j,k,c,pre;
  pre = -1;
  for(i = 0; word[i]; i ++) {
     c = 0;
     for(j = 0; j <7; j ++) {
	for(k = 0; ch[j][k]; k ++) {
	   if(word[i] == ch[j][k]) {
	     c = 1;
	     break;
	   }
	}
	 if(c)  break;
     }
     if(j && j != pre)
       printf("%d",j);
     pre = j;
  }
  printf("\n");
  return 0;
}

int main()   {

    while(gets(word))
      cal();
    return 0;
}
