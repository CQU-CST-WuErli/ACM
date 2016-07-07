//////////////////////////////////////////////////////// 
//                           //                        //
//  Created by  Team 3 			                       //
//  Copyright (c) 2015Äê Team 3. All rights reserved.  //
/////////////////////////////////////////////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>           
#include <algorithm>
#include <cctype>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <vector>
#define INF 1<<31
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;

const int maxn=220010;
long long  pnt[maxn],pre[maxn],head[maxn],w[maxn],cnt;
long long  vis[maxn],d[maxn],counter[maxn];
int N,ML,MD;

void addedge(long long u,long long  v,long long weight)
{
	pnt[cnt]=v;w[cnt]=weight;pre[cnt]=head[u];head[u]=cnt++;
}

long long spfa()
{
	queue<int> q;
	CLR(vis);
	for (long long i=0;i<maxn;i++) d[i]=0x3f3f3f;
	CLR(counter);
	d[1]=0;
	q.push(1);
	vis[1]=1;
	counter[1]++;
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		if (counter[x]>N) return -1;
		for (int i=head[x];i!=-1;i=pre[i])
		{
			int v=pnt[i];
			if (d[v]>d[x]+w[i])
			{
				d[v]=d[x]+w[i];
				if (vis[v]==0)
				{
					vis[v]=1;
					counter[v]++;
					q.push(v);
				}
			}
		}
	}
	if (d[N]==0x3f3f3f) return -2;
	else return d[N];
}
int main()
{
	while (scanf("%d%d%d",&N,&ML,&MD)!=EOF)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
//		memset(pre,-1,sizeof(pre));
		for (int i=1;i<=ML;i++)
		{
			long long u,v,dis;
			scanf("%lld%lld%lld",&u,&v,&dis); 
			addedge(u,v,dis);
		}
		for (int i=1;i<=MD;i++)
		{
			long long u,v,dis;
			scanf("%lld%lld%lld",&u,&v,&dis);
			addedge(v,u,-dis); 
		}
//		long long ans=spfa();
		cout << spfa() << endl;
	}
	return 0;
}

