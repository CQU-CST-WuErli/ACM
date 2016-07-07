///////////////////////////////////////////////////////// 
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
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
#define maxn 100010 
int N,X;
long long M;
int pnt[maxn],pre[maxn],head[maxn];
int vis[maxn],d1[maxn],d2[maxn],w[maxn],cnt;

void addedge(int u,int v,int weight)
{
	pnt[cnt]=v;pre[cnt]=head[u];w[cnt]=weight;head[u]=cnt++;
}

void spfa(int s,int *md)
{
	queue<int> q;
	CLR(vis);
	memset(md,0x3f,sizeof(md));
	q.push(s);
	md[s]=0;
	vis[s]=1;
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for (long long i=head[x];i!=-1;i=pre[i])
		{
			int v=pnt[i];
			if (md[v]>md[x]+w[i])
			{
				md[v]=md[x]+w[i];
				if (!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
}

int main()
{
	while (scanf("%d%lld%d",&N,&M,&X)!=EOF)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		memset(pre,-1,sizeof(pre));
		for (long long i=1;i<=M;i++)
		{
			int u,v,cost;
			scanf("%d%d%d",&u,&v,&cost);
			addedge(v,u,cost);
		}
	}
	return 0;
}

