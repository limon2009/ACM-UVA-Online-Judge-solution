#include<stdio.h>
#include<string.h>

#define MAXN 1000000

char Ones[MAXN+1];
int Record[MAXN];

void Set() {
	int i, j= 0;
	for(i = 0; Ones[i]; ) {
		if(Ones[i] == '1') {
			j++;
			for(;Ones[i]== '1' && Ones[i]; i++)
				Record[i] = j;
			/*while(Ones[i] == '1'&& Ones[i]) {
				Record[i] = j;
				i++;
			}*/
		}
		if(Ones[i] == '0') {
			j++;
			for(;Ones[i]== '0' && Ones[i]; i++)
				Record[i] = j;
			
			/*while(Ones[i] == '0' && Ones[i]) {
				Record[i] = ;
				i++;
			}*/
		}
	}
}

int main() {
	int q, i, s, t,kase=1;
	char input[100];
	while(gets(Ones)) {
		for(i = 0; Ones[i]; i++) 
			if(Ones[i] == '\n')
				Ones[i] = NULL;
			
        if(strlen(Ones) <1) break;
		Set();
	    gets(input);
		sscanf(input,"%d",&q);
		printf("Case %d:\n",kase++);
		while(q--) {
			gets(input);
			sscanf(input,"%d%d",&s,&t);
			if(s == t) { printf("Yes\n"); continue; }
			if(Record[s] == Record[t])
				printf("Yes\n");
			else printf("No\n");
		}
	}
    
	return 0;

}
