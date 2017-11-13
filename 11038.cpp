#include<stdio.h>
#include<string.h>
#include<math.h>

#define maxn 20

//typedef __int64 ss;
typedef long long ss;

ss Zero[maxn];
ss All[maxn], X, Y;

void ForAll() {
	ss i, d = 10;
	All[1] = 1;
	for(i = 2; i<15; i++) {
		All[i] = i*d;
		d *= 10;
	}
	Zero[0] = 0;
	Zero[1] = 1;
	for(i = 2; i<15; i++) {
		Zero[i] = 9*All[i-1];
		Zero[i] += Zero[i-1];
	}
}

ss Rest(ss ind, char ch[], ss len) {
	ss i, d = 1, m, v = 0;
	for(i = len - 1; i>= ind; i--) {
		m = ch[i] - '0';
		v += m*d;
		d *= 10;
	}

	return v ? v+1:1;
}

ss F(ss n) {
	char ch[100];
	ss i, len, res = 0, res1 = 0, d, m;
	if(n <= 9) 	return n>=0 ? 1 : 0;
	sprintf(ch,"%lld",n);
	len = strlen(ch);
	if(len == 2) {
		return n/10 + 1;
	}
	res += Zero[len-1];
	for(i = 0; i+2<len; i++) {
		d = ch[i] - '0';
		if(!d) {
			res1 += Rest(i+1,ch, len);
			continue;
		}
		m = d - 1;
		if(i == 0) {
			if(!m) continue;
			res1 += m*All[len-i-1];
		}else {
			res1 += (ss)pow(10,(double)(len-i-1));
			res1 += (m+1)*All[len-i-1];
		}
	}
	d= ch[i] - '0';
	if(!d) res1 += Rest(i+1,ch,len);
	else
		res1 += 10;
	m =  (ss) pow(10,(double)(len-1));
	//d = n/m;
	//d = (n - d*m)/10 + 1;
	d = n%100;
	d  = d/10 + 1;
	return res1 + res + d;
}

void Cal() {
	ss x, y;
	x = F(X - 1);
	y = F(Y);
	printf("%lld\n",y-x);

}

int main() {
	ForAll();
//	freopen("c:\\h.txt","r",stdin);
	while(scanf("%lld%lld",&X,&Y) == 2) {
		if(X < 0 && Y < 0) break;
		Cal();
	}
	return 0;

}
