//  Created by Chenhongwei on 2016-06-04 Saturday 09:10
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
const int maxn=1e4+100;
typedef long long ll;
typedef unsigned long long ull;
struct edge
{
	int v,lim,cost;
};
struct  node
{
	int p;
	ll cost;
	bool operator < (const node & rhs) const
	{
		return cost>rhs.cost;
	}
};
vector<edge> g[maxn];
ll d[maxn];
bool f[maxn];
int n,m,k;
bool judge(int x)
{
	memset(d,0x3f,sizeof d);
	memset(f,0,sizeof f);
	d[1]=0;
	priority_queue<node> q;
	q.push((node){1,0});
	while(!q.empty())
	{
		node np=q.top();
		q.pop();
		int u=np.p;
		if(f[u]) continue;
		f[u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			if(g[u][i].lim<x)
				continue;
			int v=g[u][i].v;
			ll cost=g[u][i].cost;
			if(d[v]>d[u]+cost)
			{
				d[v]=d[u]+cost;
				q.push((node){v,d[v]});
			}
		}
	}
	return d[n]<=k;
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
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<=n;i++)
			g[i].clear();
		int u,v,lim;
		ll cost;
		int l=inf,r=-1;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d%lld",&u,&v,&lim,&cost);
			g[u].push_back((edge){v,lim,cost});
			g[v].push_back((edge){u,lim,cost});
			r=max(r,lim);
			l=min(l,lim);
		}
		int ans=-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(judge(mid))
			{
				l=mid+1;
				ans=mid;
			}
			else
				r=mid-1;
		}
		if(ans==-1)
			puts("Poor RunningPhoton!");
		else
			printf("%d\n",ans);
	}
	return 0;
}