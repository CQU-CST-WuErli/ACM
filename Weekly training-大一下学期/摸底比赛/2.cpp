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
#define maxn 1010
int t;
int ym,n,d;
struct P
{
	int x,y;
}p[maxn];
bool cmp(const P &a,const P &b)
{
	return a.y<b.y;
}
int g[maxn][maxn];
bool used[maxn];
int ds[maxn];   //´ÎÊý 
int dis(int a,int b)
{
	int d1=(p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y);
	return d1;
}
void bfs()
{
	queue <int> q;
	memset(used,false,sizeof used);
	memset(ds,0x3f,sizeof ds);
	ds[0]=0;
	q.push(0);
	used[0]=true;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=1;i<=n+1;i++)
		{
			if (used[i] || g[x][i]>d) continue;
			ds[i]=ds[x]+1;
			used[i]=true;
			q.push(i);
		}
	}
//	for (int i=0;i<=n+1;i++) cout << ds[i] << endl;
//	cout << endl;
	if (ds[n+1]!=INF)
	{
		printf("YES\n%d\n",ds[n+1]);
	}
	else
	{
		for (int i=1;i<=n;i++)
			if (ds[i]==INF) g[i][n+1]=INF;
		int Min=INF;
		for(int i=1;i<=n;i++)
			if (Min>g[i][n+1])
			Min=g[i][n+1];
		int ans=sqrt(Min);
		printf("NO\n%d\n",ans);
	}
		
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&ym,&n,&d);  d*=d;
		if (n==0) 
		{
			if (ym<=d) printf("YES\n1\n");
			else printf("NO\n%d\n",ym);
			continue;
		}
		for (int i=1;i<=n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		sort(p+1,p+1+n,cmp);
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)	g[i][j]=dis(i,j);
		for (int i=0;i<=n;i++)
		{
			g[0][i]=g[i][0]=p[i].y*p[i].y;
			g[n+1][i]=g[i][n+1]=(ym-p[i].y)*(ym-p[i].y);
		}
		bfs();
	}
	return 0;
}
