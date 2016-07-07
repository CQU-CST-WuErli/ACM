///////////////////////////////////////////////////////// 
//                           //                        //
//  Created by 吴尔立 			                       //
//  Copyright (c) 2015年 吴尔立. All rights reserved.  //
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
#define ll long long;
#define INF 1<<31
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
using namespace std;
#define maxn 10000
int F,N,M,W;//F样例数，N   节点数，  M  边数   W  虫洞数
int pnt[maxn],pre[maxn],head[maxn],w[maxn],cnt;
int d[maxn],vis[maxn],counter[maxn];

void addedge(int u, int v, int weight)
{
	pnt[cnt]=v;pre[cnt]=head[u];w[cnt]=weight;head[u]=cnt++;
}

bool spfa()
{
	deque<int>q;
	CLR(vis);
	memset(d,0x3f,sizeof(d));
	CLR(counter);
	d[1]=0;
	vis[1]=1;
	q.push_front(1);
	counter[1]=1;
	while (!q.empty())
	{
		int x=q.front();
		q.pop_front(); 
		counter[x]++;
		vis[x]=0;
		if (counter[x]>N) return true;
		for (int i=head[x];i!=-1;i=pre[i])
		{
			int v=pnt[i];
			if (d[v]>d[x]+w[i] || d[v]==0x3f)
			{
				d[v]=d[x]+w[i];
				if (!vis[v])
				{
					if (d[v]<q.front())	q.push_front(v);
					else q.push_back(v);
					vis[v]=1;
				}
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d",&F);
	cir(f,1,F)
	{
		int s,e,t;
		cnt=0;
		scanf("%d%d%d",&N,&M,&W);
		memset(pre,-1,sizeof(pre));
		memset(head,-1,sizeof(head));
		cir (i,1,M)
		{
			scanf("%d%d%d",&s,&e,&t);
			addedge(s,e,t);
			addedge(e,s,t);
		}
		cir(i,1,W)
		{
			scanf("%d%d%d",&s,&e,&t);
			addedge(s,e,-t);
		}
		bool ans=spfa();
		if (ans)  printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;
}
