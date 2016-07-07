/*
SCU - 4500
��һ����С�� C��������ʹ��������
�ɸ����� M������ɣ���󳤶Ȳ����� 500�������ܱ� N����

��������λDP����
�Ӹߵ��ͣ���С����ö��ÿһλ
ö�ٵ��׵�ʱ���ж������Ƿ�Ϊ 0

�Ƚ��鷳�����ж�ǰ�� 0��
����ǰ�� 0�����ڸ�����������
�����ȵ�������һ�δ�λΪǰ�� 0�ģ�Ȼ���ٽ���ö��
���Ҫ���仯һ�£������ǰ iλ������Ϊ rem�Ѳ�����
�ͱ��һ���Ժ�����

��һ�� trick�� N==0�����Σ�����һ�¾ͺ���
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
