#include<stdio.h>
#include<string.h>
#include<ctype.h>

char str[1200];
char ss[] = "0123456789ABCDEFGH";

int C;

int Rem() {
	int i, d = 1, g = 34943, v, rem = 0, p;
	int l = strlen(str);
	if(!l) return l;
	for(i = l-1; i>=0; i--) {
	//	if(!isalpha(str[i])) continue;
		v = str[i];
		p = d * v;
		p %= g;
		rem += p;
		rem %= g;
		d *= 256;
		d %= g;
	}
	p = ( 256 * 256) % g;
	p *= rem;

	return p % g;
}


void Cal() {
	int d, ind = 0, i;
	char xx[12];
	d = Rem();
	if(!d) {
		printf("00 00\n");
		return;
	}
	d = 34943 - d;
	while(d) {
		xx[ind++] = ss[d % 16];
		d /= 16;
	}
	for(i = ind; i<4; i++) {
		xx[ind++] = '0';
	}
	printf("%c%c",xx[3],xx[2]);
	printf(" %c%c\n",xx[1],xx[0]);
	
}

void main () {
	//freopen("c:\\h.txt","r",stdin);
	while(1) {
		gets(str);
		if(!strcmp(str,"#")) break;
		Cal();
	}
}
