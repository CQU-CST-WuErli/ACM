///////////////////////////////////////////////////////// 
//                           //                        //
//  Created by Îâ¶ûÁ¢ 			                       //
//  Copyright (c) 2015Äê Îâ¶ûÁ¢. All rights reserved.  //
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
#define maxn 2100
int pnt[maxn],nxt[maxn],head[maxn],w[maxn],cnt=0;
int T,S,D;
bool vis[maxn];
int d[maxn];

void addedge(int u,int v,int weight)
{
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;w[cnt]=weight;
	cnt++;
}

int  spfa()
{
	queue<int> q;
	memset(d,0x3f,sizeof(d));
	memset(vis,false,sizeof(vis)); 
	d[0]=0;
	q.push(0);
	vis[0]=true;
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int i=head[x];~i;i=nxt[i])
		{
			int v=pnt[i];
			if (d[x]+w[i]<d[v] || d[v]==0x3f)
			{
				d[v]=d[x]+w[i];
				if (!vis[v])
				{
					q.push(v);
					vis[v]=true;
				}
			}
		}
		vis[x]=false;		
	}
	return d[1001];
}

int main()
{
	while(cin >> T >> S >> D)
	{
		cnt=0;
		memset(nxt,-1,sizeof(nxt));
		memset(head,-1,sizeof(head));
		cir (i,1,T)
		{
			int a,b,time;
			scanf("%d%d%d",&a,&b,&time);
			addedge(a,b,time);
			addedge(b,a,time);
		}
		cir(i,1,S)
		{
			int u;
			scanf("%d",&u);
			addedge(0,u,0);
			addedge(u,0,0);
		}	
		cir(i,1,D)
		{
			int v;
			scanf("%d",&v);
			addedge(1001,v,0);
			addedge(v,1001,0);
		}
		int ans=spfa();
		cout << ans <<endl;
	}
	return 0;
}

