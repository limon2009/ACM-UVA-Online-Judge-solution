#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;


int main() {
    char s[100];
	int f;
	while(scanf("%s",s) && strcmp(s,"#")){
		f = 1;
		while(next_permutation(s, s+strlen(s))){
			printf("%s\n",s);
			f = 0;
			break;
		}
		if(f) printf("No Successor\n");
	}
	return 0;
}

