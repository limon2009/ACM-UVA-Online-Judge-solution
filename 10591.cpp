#include<stdio.h>
#include<string.h>


char ss[100];
char F[700];


int RECUR(char temp[]) {
	int k = 0, i;
	for(i = 0; temp[i]; i++)
		k += (temp[i]-'0')*(temp[i]-'0');
    if(k == 1) return 1;
	if(F[k]) return 0;
	F[k] = 1;
	sprintf(temp,"%d",k);
	return(RECUR(temp));
	
}

void INI() {
    int i;
	for(i = 0; i<=650; i++) F[i] = 0;
}
int main() {
   int kase = 1, f = 0, t;
   char dummy[100];
   int d;
   scanf("%d",&t);
   while( t--) {
	   scanf("%s",ss);
	   if(f++)  INI();
       strcpy(dummy,ss);
	   d = RECUR(dummy);
	  if(d) printf("Case #%d: %s is a Happy number.\n",kase++,ss);
	  else printf("Case #%d: %s is an Unhappy number.\n",kase++,ss);

   }
	return 0;

}
