#include<stdio.h>
#include<string.h>

int LO, UP;

int TOOH(int n) {
   if(n<= LO) return 0;
   if(n < UP) UP = n;
   return 1;
}	

int TOOL(int n) {
    if(n >= UP) return 0;
	if(n> LO) LO = n;
	return 1;
}
void Cal(int n) {
	LO = 0; UP = 11;
	char com[15];
	char num[100];
	int p = 1, j;
	while(1) {
	   gets(com);
	   if(!strcmp(com,"too high")) {
		   j = TOOH(n);
		   if(j == 0 && p){ 
			   printf("Stan is dishonest\n");
			   p = 0;
		   }
	   }
	   else if(!strcmp(com,"too low")) {
		   j = TOOL(n);
		   if(j == 0 && p) {
			   printf("Stan is dishonest\n");
			   p = 0;
		   }
	   }
	   else {
		   if((n <= LO || n >= UP) && p){
			   printf("Stan is dishonest\n");
		       return;
		   }
		   break;
	   }
        gets(num);
		sscanf(num,"%d",&n);
	}
	if(p) printf("Stan may be honest\n");
}

int main() {
   int n;
   char input[100];

   while(gets(input)) {
	   sscanf(input,"%d",&n);
	   if(n == 0) break;
	   Cal(n);
   }
	return 0;

}
