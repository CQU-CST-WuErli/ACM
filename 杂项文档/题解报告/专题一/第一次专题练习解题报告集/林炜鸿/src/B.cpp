/*
SCU - 4495
给定一个字符串，把其中出现的 A串替换为 B串

KMP入门题，对原串匹配 A串，跑一遍 KMP
然后匹配到终点的时候替换就好了
最后再输出替换的结果
时间复杂度 O(N)
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

const int maxn=5e6+10;
struct KMP
{
	char *patn;
	int plen,*fail;
	KMP(char*,int);
	~KMP(){delete[] fail;}
	int match(char*,int,char*,int,char*);
};

char inpt[maxn];
char patn[maxn];
char conv[maxn];
char ans[maxn];

int main()
{
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		scanf(" %s %s %s", inpt, patn, conv);
		KMP kmp(patn,strlen(patn));
		CLR(ans);
		kmp.match(inpt,strlen(inpt),conv,strlen(conv),ans);
		puts(ans);
	}
	return 0;
}

KMP::KMP(char tpatn[],int len):patn(tpatn),plen(len)
{
	fail=new int[plen+1];
	fail[0]=fail[1]=0;
	for(int i=1; i<plen; i++)
	{
		int fp = fail[i];
		while(fp && patn[fp] != patn[i])  fp=fail[fp];
		if(patn[fp]==patn[i]) fail[i+1] = fp+1;
		else fail[i+1] = 0;
	}
}

int KMP::match(char str[], int len, char conv[], int clen, char res[])
{
	int np=0,end=0;
	for(int i=0; i<len; i++)
	{
		res[end++]=inpt[i];
		while( np && patn[np] != str[i])  np = fail[np];
		if( patn[np] == str[i] ) np++;
		if( np == plen )
		{
			np=0;
			for(int j=end-plen; j<end-plen+clen; j++) res[j]=conv[j-(end-plen)];
			end=end-plen+clen;
		}
	}
	res[end]=0;
	return end;
}

