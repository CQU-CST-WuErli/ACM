/*
SCU - 4506
求由于硬盘容量进制不同造成的容量损失率

按题意模拟就好，其实这题跟前面的数字无关
*/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;
typedef unsigned long long ULL;
typedef double DBL;
typedef long double LDBL;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) (a*a)

const char *Tmp[9]={"B","KB","MB","GB","TB","PB","EB","ZB","YB"};
char inpt[200];
const DBL rate=Sqr(5.0)*5.0/(Sqr(2.0)*Sqr(2.0)*Sqr(2.0)*2.0);

int main()
{
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		scanf(" %s", inpt);
		int len=0,np=0;
		while(inpt[np++]!='[');
		while(inpt[np++]!=']') inpt[len++]=inpt[np-1];
		inpt[len]=0;
		int flr=0;
		while(strcmp(Tmp[flr++],inpt));
		DBL ans=1.0;
		while(--flr) ans*=rate;
		printf("Case #%d: %.2f%%\n", ck, (1-ans)*100.0);
	}
	return 0;
}

