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
#define INF 1<<31
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
#define maxn 200010

int pnt[maxn],pre[maxn],head[maxn],w[maxn];
long long cnt;
long long R;
int N;
bool vis[maxn];
long long d[maxn],cd[maxn];

void addedge(int u,int v,int weight)
{
	pnt[cnt]=v;w[cnt]=weight;
	pre[cnt]=head[u];head[u]=cnt++;
}

void spfa(int s,long long *dt)
{ 
	queue<int> q;
	memset(vis,false,sizeof(vis));
//	memset(dt,0x3f,sizeof(dt));
	dt[s]=0;
	vis[s]=true;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=false;
		for (long long i=head[x];i!=-1;i=pre[i])
		{
			int v=pnt[i];
			if (dt[v]>dt[x]+w[i])
			{
				dt[v]=dt[x]+w[i];
				if (!vis[v])
				{
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	while (scanf("%d%lld",&N,&R)!=EOF)
	{
		memset(d,0x3f,sizeof(d));
		memset(cd,0x3f,sizeof(cd));
		cnt=0;
		memset(head,-1,sizeof(head));
		memset(pre,-1,sizeof(pre));
		for (long long i=1;i<=R;i++)
		{
			int u,v,dis;
			scanf("%d%d%d",&u,&v,&dis);
			addedge(u,v,dis);
			addedge(v,u,dis);
		} 
		spfa(1,d);
		spfa(N,cd);
//		cout << d[N] << endl;
//		cout << cd[N]<< endl;
		long long ans=0x3f3f,temp;
		for (int i=1;i<=N;i++)
		{
			for (long long j=head[i];j!=-1;j=pre[j])
			{
				int v=pnt[j];
				temp=d[i]+cd[v]+w[j];
				if (temp>d[N] && ans>temp)
					ans=temp;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

