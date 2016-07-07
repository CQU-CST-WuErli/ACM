/*
SCU - 4496
����һ����������С�Ľ���0��1���ɵ��ܱ���������������

���� dfs���Ӹߵ��ͣ���С����ö�ٵ�ǰλ��Ȼ��һֱ�ѵ���
����ж�һ�������Ƿ���� 0�����Ϊ 0���򷵻�
Ҫע��ǰ�� 0����������ų�ȫΪ 0�Ľ�
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

const int maxl=20;
int N;
bool zero;
int res[100];
int str[100];

int dfs(int,int);
void out(int*);

int main()
{
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		scanf("%d", &N);
		CLR(res);
		CLR(str);
		zero=0;
		bool ok=dfs(maxl,0);
		out(res);
	}
	return 0;
}

int dfs(int np, int rem)
{
	if(np<0)
	{
		if(!rem&&zero)
		{
			for(int i=0; i<=maxl; i++) res[i]=str[i];
			return 1;
		}
		else
		{
			zero=1;
			return 0;
		}
	}
	for(int i=0; i<2; i++)
	{
		str[np]=i;
		int nrem=(rem*10+i)%N;
		if(dfs(np-1,nrem)) return 1;
	}
	return 0;
}

void out(int str[])
{
	int len=maxl+1;
	while(!str[len]&&len) len--;
	while(len>=0) printf("%d", str[len--]);
	puts("");
}
