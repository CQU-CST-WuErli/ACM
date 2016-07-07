//  Created by Chenhongwei on 2016-05-07 Saturday 16:30
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
char s[610][610];
bool f[610][610];
int d[610][610];
int dp[610];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m,k,cnt,ss,t;
bool check(int x,int y)
{
	if(x>=1&&x<=n&&m>=1&&y<=m&&s[x][y]!='W')
		return true;
	return false;
}
struct node
{
	int x,y;
	bool operator < (const node & rhs) const
	{
		if(x!=rhs.x)
			return x<rhs.x;
		return y<rhs.y;
	}
}point[160];
vector<node> g[160];
void bfs(int x,int y)
{
	queue<node> q;
	node tmp,np;
	tmp.x=x,tmp.y=y;
	q.push(tmp);
	memset(f,0,sizeof f);
	memset(d,0x3f,sizeof d);
	d[x][y]=0;
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			np.x=tmp.x+dir[i][0];
			np.y=tmp.y+dir[i][1];
			if(check(np.x,np.y)&&d[np.x][np.y]>d[tmp.x][tmp.y]+1)
			{
				d[np.x][np.y]=d[tmp.x][tmp.y]+1;
				if(!f[np.x][np.y])
				{
					f[np.x][np.y]=1;
					q.push(np);
				}
			}
		}
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
		cnt=0;
		node tmp;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
				if(s[i][j]!='W'&&s[i][j]!='.')
				{
					point[++cnt].x=i;
					point[cnt].y=j;
					if(s[i][j]=='S')
						ss=cnt;
					else if(s[i][j]=='E')
						t=cnt;
				}
		}
		for(int i=0;i<=cnt;i++)
			g[i].clear();
		for(int i=1;i<=cnt;i++)
		{
			bfs(point[i].x,point[i].y);
			for(int j=1;j<=cnt;j++)
				if(i!=j)
				{
					int xx=point[j].x,yy=point[j].y;
					if(d[xx][yy]<k)
					{
						g[i].push_back((node){j,d[xx][yy]});
						g[j].push_back((node){i,d[xx][yy]});
					}
				}
		}
		memset(dp,0x3f,sizeof dp);
		
		dp[ss]=0;
		queue<int> q;
		bool flag[660];
		memset(flag,0,sizeof flag);
		flag[ss]=1;
		q.push(ss);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=0;i<g[u].size();i++)
			{
				int v=g[u][i].x;
				if(dp[v]>dp[u]+g[u][i].y)
				{
					dp[v]=dp[u]+g[u][i].y;
					if(!flag[v])
					{
						q.push(v);
						flag[v]=1;
					}	
				}
			}
		}
		if(dp[t]>inf)
			puts("Poor RunningPhoton!");
		else
			printf("%d\n",dp[t]);
	}
	return 0;
}