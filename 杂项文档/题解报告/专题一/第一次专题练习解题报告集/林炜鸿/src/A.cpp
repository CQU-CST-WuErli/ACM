/*

给定两个序列，问从两个序列中各取一个值的异或和最大为多少
把 A序列中的数字看成一个二进制的 01串，然后存到 Trie树里
然后将 B序列的数字同样看成一个 01串，然后在 Trie树上从高位到低位贪心地查找
如果B序列中查找的 01串当前位为 0，则找 Trie树上为 1的子儿子
否则就只能走为 0的右儿子，反之亦然，然后往下走
时间复杂度 O(N)
*/
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
#define Pow2(a) (a*a)

const int maxn=1e6+10,nxt_siz=2;
struct Trie
{
	struct node
	{
		int chr,nxt[nxt_siz];
	} *trie;
	int siz;
	Trie(int size){trie=new node[size];memset(trie,0,sizeof(node)*size);siz=0;}
	~Trie(){delete []trie;}
	void addstr(char*);
	int query(char*);
};
int N,M;
int inpt[2][maxn];
int pow2[32];
char _str[50];

void nts(int,char*);

int main()
{
	pow2[0]=1;
	for(int i=1; i<32; i++) pow2[i]=pow2[i-1]<<1;
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		scanf("%d%d", &N, &M);
		Trie data(3*maxn);
		for(int i=0; i<N; i++)
		{
			scanf("%d", &inpt[0][i]);
			nts(inpt[0][i], _str);
			data.addstr(_str);
		}
		int ans=0;
		for(int i=0; i<M; i++)
		{
			scanf("%d", &inpt[1][i]);
			nts(inpt[1][i], _str);
			ans=max(ans, data.query(_str));
		}
		printf("%d\n", ans);
	}
	return 0;
}

void Trie::addstr(char *str)
{
	int len=strlen(str),np=0;
	for(int i=0; i<len; i++)
	{
		int ch=str[i]-'0';
		if(trie[np].nxt[ch]) np=trie[np].nxt[ch];
		else
		{
			trie[np].nxt[ch]=++siz;
			np=siz;
			trie[np].chr=str[i];
		}
	}
}

int Trie::query(char *str)
{
	int res=0,np=0;
	for(int i=0; i<31; i++)
	{
		int now=str[i]-'0';
		if(trie[np].nxt[now^1])
		{
			np=trie[np].nxt[now^1];
			res^=1<<(30-i);
		}
		else if(trie[np].nxt[now])
		{
			np=trie[np].nxt[now];
		}
	}
	return res;
}

void nts(int num, char *str)
{
	for(int i=30; i>=0; i--){str[i]=(num&1)+'0';num>>=1;}
}
