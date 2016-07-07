//  Created by Chenhongwei on 2016-05-09 Monday 18:10
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
const int maxn=1e5+100;
typedef long long ll;
typedef unsigned long long ull;
int n,m,ans;
char s[10][10];
char D[4]={'A','C','G','T'};
int len[10];
void dfs(int *p,int d,int dep)
{
	if(d>dep||ans!=-1)
		return ;
	int maxv=0;
	for(int i=1;i<=n;i++)
	{
		int t=len[i]-p[i];
		maxv=max(maxv,t);
	}
	if(maxv==0)
	{
		ans=d;
		return ;
	}
	if(d+maxv>dep)
		return ;
	for(int i=0;i<4;i++)
	{
		int q[10];
		bool flag=0;
		for(int j=1;j<=n;j++)
			if(s[j][p[j]]==D[i])
			{
				flag=1;
				q[j]=p[j]+1;
			}
			else
				q[j]=p[j];
		if(flag)
			dfs(q,d+1,dep);
		if(ans!=-1)
			break;
	}
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
		scanf("%d",&n);
		int maxlen=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]);
			len[i]=strlen(s[i]);
			maxlen=max(maxlen,len[i]);
		}
		int dep=maxlen;
		ans=-1;
		int p[20];
		memset(p,0,sizeof p);
		while(true)
		{
			dfs(p,0,dep);
			if(ans!=-1)
				break;
			dep++;
		}	
		printf("%d\n",ans);
	}
	return 0;
}
