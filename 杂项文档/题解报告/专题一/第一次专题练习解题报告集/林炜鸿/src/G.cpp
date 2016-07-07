/*
SCU - 4500
求一个最小的 C进制数，使得他满足
由给定的 M的数组成，最大长度不超过 500，并且能被 N整除

依旧是数位DP裸题
从高到低，从小到大枚举每一位
枚举到底的时候判断余数是否为 0

比较麻烦的是判断前导 0：
由于前导 0不算在给定的数字内
所以先单独计算一次此位为前导 0的，然后再进行枚举
最后要记忆化一下，如果当前 i位，余数为 rem搜不到解
就标记一下以后不搜了

有一个 trick是 N==0的情形，特判一下就好了
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

const int maxl=500;
int N,C,M;
bool have[16];
char res[maxl+10];
char str[maxl+10];
bool dp[maxl+10][5010];

int dfs(int,int,bool);
void output(char*);

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		CLR(have);CLR(res);CLR(str);CLR(dp);
		scanf("%d%d%d", &N, &C, &M);
		for(int i=1; i<=M; i++)
		{
			char x;
			scanf(" %c", &x);
			if(x>='A'&&x<='F') x=x-'A'+10;
			else x-='0';
			have[x]=1;
		}
		if(N==0)
		{
			if(have[0]) puts("0");
			else puts("BOMB!!!");
			continue;
		}
		if( dfs(maxl-1,0,0) ) output(res);
		else puts("BOMB!!!");
	}
	return 0;
}

int dfs(int np, int rem, bool lead)
{
	if(np<0)
	{
		if(!rem&&lead)
		{
			for(int i=0; i<maxl; i++) res[i]=str[i];
			return 1;
		}
		else return 0;
	}
	if(dp[np][rem]) return 0;
	if(!lead&&dfs(np-1,rem*C%N,0)) return 1;
	else
	{
		for(int i=0; i<C; i++)
		{
			if((!lead&&!i)||!have[i]) continue;
			str[np]=i;
			if( dfs(np-1, (rem*C+i)%N, 1) ) return 1;
		}
	}
	dp[np][rem]=1;
	return 0;
}

void output(char res[])
{
	int len=maxl-1;
	while(len&&!res[len]) len--;
	for(int i=len; i>=0; i--)
	{
		if(res[i]<10) putchar(res[i]+'0');
		else putchar(res[i]-10+'A');
	}
	puts("");
}
