//  Created by Chenhongwei on 2016-05-03 Tuesday 21:51
//  Copyright (c) 2016 Chenhongwei. All rights reserved.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int inf=1e9;
const int mod=1e9+7;
const int maxn=1e6+100;
typedef long long ll;
typedef unsigned long long ull;
int n,m,pos;
int nxt[maxn*4][2];
int num[maxn*4];
void insert(ll x)
{
	int cur=0;
	for(int i=0;i<=31;i++)
	{
		int flag=(x&(1<<(31-i)))?1:0;
		if(nxt[cur][flag]==-1)
		{
			memset(nxt[pos],-1,sizeof nxt[pos]);
			nxt[cur][flag]=pos++;
		}
		cur=nxt[cur][flag];
	}
	num[cur]=x;
}
int find(int x)
{
	int cur=0;
	for(int i=0;i<=31;i++)
	{
		int flag=(x&(1<<(31-i)))?1:0;
		if(nxt[cur][1-flag]!=-1)
			cur=nxt[cur][1-flag];
		else
			cur=nxt[cur][flag];
	}
	return x^num[cur];
}
int main()
{
	//ios::sync_with_stdio(false);
    // freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(num,0,sizeof num);
		scanf("%d%d",&n,&m);
		int maxv=0,tmp;
		pos=1;
		memset(nxt[0],-1,sizeof nxt[0]);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&tmp);
			insert(tmp);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&tmp);
			maxv=max(maxv,find(tmp));
		}
		printf("%d\n",maxv);
	}
	return 0;
}