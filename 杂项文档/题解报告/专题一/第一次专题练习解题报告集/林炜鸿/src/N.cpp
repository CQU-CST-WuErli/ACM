/*
SCU - 4507
求给定长度的文本串，使得每个模式串至少出现过一次
求这样的模式串的个数

AC自动机禁止模式串的裸题
这题求的是一个串至少出现过一次
只要求一次都没出现过的方案总数
再拿所有方案总数相减即可得到答案

然后就拿所有模式串构造 Trie树，然后在上面跑 AC自动机
跑到单词结尾的时候不转移，这样就能求出答案
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

const int MOD=10007,nxt_siz=26,noden=60*100+10;
struct AC_Auto
{
	struct node
	{
		char chr;
		int val,fail,nxt[nxt_siz];
	} *trie;
	int siz;

	AC_Auto(int size){siz=0;trie=new node[size];memset(trie,0,sizeof(node)*size);}
	~AC_Auto(){delete []trie;}

	int chnum(char x){return x-'A';}
	void addstr(char*);
	void init();
	int solve();
};
int N,M;
int dp[110][noden];

int main()
{
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		AC_Auto ac(noden);
		scanf("%d%d", &N, &M);
		for(int i=0; i<N; i++)
		{
			char patn[110];
			scanf(" %s", patn);
			ac.addstr(patn);
		}
		ac.init();
		printf("%d\n", ac.solve());
	}
	return 0;
}

void AC_Auto::addstr(char *str)
{
	int len=strlen(str),np=0;
	for(int i=0; i<len; i++)
	{
		int ch=chnum(str[i]);
		if(trie[np].nxt[ch]) np=trie[np].nxt[ch];
		else
		{
			trie[np].nxt[ch]=++siz;
			np=siz;
			trie[np].chr=str[i];
		}
		if(i==len-1) trie[np].val=1;
	}
}

void AC_Auto::init()
{
	trie[0].fail = 0;
	queue<int> que;
	for(int i=0; i<nxt_siz; i++)
	{
		int np = trie[0].nxt[i];
		if(np)
		{
			que.push(np);
			trie[np].fail = 0;
		}
	}

	while(!que.empty())
	{
		int np = que.front();
		for(int i=0; i<nxt_siz; i++)
		{
			int nxp = trie[np].nxt[i];
			int fap = trie[np].fail;
			if(!nxp)
			{
				trie[np].nxt[i] = trie[fap].nxt[i];
				continue;
			}
			que.push(nxp);
			trie[nxp].fail = trie[fap].nxt[i];
			fap = trie[nxp].fail;
			if(trie[fap].val) trie[nxp].val = 1;
		}
		que.pop();
	}
}

int AC_Auto::solve()
{
	CLR(dp);
	dp[0][0]=1;
	int res=0,tot=1;
	for(int i=0; i<M; i++)
	{
		tot=tot*26%MOD;
		for(int j=0; j<=siz; j++)
		{
			if(!dp[i][j]) continue;
			for(int k=0; k<26; k++)
			{
				int nxp=trie[j].nxt[k];
				if(trie[nxp].val) continue;
				dp[i+1][nxp]=(dp[i+1][nxp]+dp[i][j])%MOD;
			}
		}
	}
	for(int i=0; i<=siz; i++) res=(res+dp[M][i])%MOD;
	return ((tot-res)%MOD+MOD)%MOD;
}
