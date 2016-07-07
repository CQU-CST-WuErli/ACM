/*
SCU - 4503

板子题，依题意描述分为三个步骤 
1. 求每个位置为中心的回文串，以及最大回文串 
2. 求每个回文串的长度的异或前缀和 
3. 求两个异或前缀和异或的最大值 （xor-Trie） 

然后用快速幂算出 JD，再和 FJD比大小即可

注意一下 Trie上要先插入一个 0
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

const int maxl=1e5+10;
struct Manacher
{
	char *str;
	int *mana,len,res;
	Manacher(char *,int);
	~Manacher(){delete []str;delete []mana;}
	int query(int);
};
struct Trie
{
	struct node
	{
		char chr;
		int val,nxt[2];
	} *trie;
	int siz;
	Trie(int size){trie=new node[size];memset(trie,0,sizeof(node)*size);siz=0;}
	~Trie(){delete []trie;}
	int chnum(char x){return x-'0';}
	void addstr(char*);
	int query(char *str);
};


char inpt[maxl];
int mana[maxl];
char str01[50];

int spr_pow(int,LL,int);
char* nts(int,char*);

int main()
{
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		scanf(" %s", inpt);
		int len=strlen(inpt);
		Manacher mana(inpt,len);
		int JD=(LL)spr_pow(mana.res,(LL)len*len*len,mana.res/3*5+1)+mana.res*4/5;
		Trie trie(3e5);
		int pxor=0,FJD=pxor;
		trie.addstr(nts(0,str01));
		
		#ifdef LOCAL
		for(int i=1; i<2*len+2; i++) printf("%c ", mana.str[i]);puts("");
		for(int i=1; i<2*len+1; i++) printf("%d ", mana.mana[i]);puts("");
		#endif
		
		for(int i=0; i<len; i++)
		{
			pxor^=mana.query(i);
//			printf("i_len: %d\n", mana.query(i));
			nts(pxor,str01);
			FJD=max(FJD, trie.query(str01));
			trie.addstr(str01);
		}
		if(JD>FJD) puts("liujc");
		else puts("luoxinchen");
	}
	return 0;
}

int spr_pow(int num,LL mi,int MOD)
{
	int res=1;
	while(mi)
	{
		if(mi&1) res=((LL)res*num)%MOD;
		num=((LL)num*num)%MOD;
		mi>>=1;
	}
	return res;
}

Manacher::Manacher(char *tstr,int tlen):len(tlen)
{
	str=new char[2*len+10];
	mana=new int[2*len+10];
	res=0;
	str[0]='!';
	for(int i=0; i<len; i++)
	{
		str[2*i+1]='#';
		str[2*i+2]=tstr[i];
	}
	str[2*len+1]='#';
	str[2*len+2]=0;
	mana[1]=1;
	int p=1,rm=1;
	for(int i=2; i<2*len+1; i++)
	{
		if(rm>i)
			mana[i] = min(rm-i+1, mana[2*p-i]);
		else
			mana[i]=1;
		while(str[i-mana[i]] == str[i+mana[i]])
			mana[i]++;
		if(i+mana[i]-1>rm)
		{
			rm=i+mana[i]-1;
			p=i;
		}
		if(res<mana[i]) res=mana[i];
	}
	res--;
}

int Manacher::query(int np)
{
	return mana[2*np+2]-1;
}

void Trie::addstr(char *str)
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

char* nts(int num, char str[])
{
	for(int i=30; i>=0; i--){str[i]=(num&1)+'0';num>>=1;}
	str[31]=0;
	return str;
}
