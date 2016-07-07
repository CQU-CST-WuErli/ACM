//  Created by  CQUWEL			                       
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.  

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
int n,m;
int ans,temp;
char g[1010][1010];
int vis[1010][1010];
int dir[4][2]={1,0,0,1,-1,0,0,-1}; 
int mmax(int a, int b)
{
    return a > b ? a : b;
}
void dfs(int dx,int dy,int px,int py)
{
	for (int i=1;;++i)
	{
		int tx=px+i*dx,ty=py+i*dy;
		if (tx<1 || tx>n || ty < 1 || ty > m || g[tx][ty]=='*')
			break;
		if (g[tx][ty]=='E' && !vis[tx][ty])
		{
			temp++;
			vis[tx][ty]=1;
//			printf("g[%d][%d]=%c,%d\n",tx,ty,g[tx][ty],temp);
			continue;
		}
		if (g[tx][ty]=='/' && dx==1)
		{
			dfs(0,-1,tx,ty);break;
		}
		if (g[tx][ty]=='/' && dx==-1)
		{
			dfs(0,1,tx,ty);break;
		}
		if (g[tx][ty]=='/' && dy==1)
		{
			dfs(-1,0,tx,ty);break;
		}
		if (g[tx][ty]=='/' && dy==-1)
		{
			dfs(1,0,tx,ty);break;
		}
		if (g[tx][ty]=='\\' && dx==1)
		{
			dfs(0,1,tx,ty);break;
		}
		if (g[tx][ty]=='\\' && dx==-1)
		{
			dfs(0,-1,tx,ty);break;
		}
		if (g[tx][ty]=='\\' && dy==1)
		{
			dfs(1,0,tx,ty);break;
		}
		if (g[tx][ty]=='\\' && dy==-1)
		{
			dfs(-1,0,tx,ty);break;
		}
	}
	ans=mmax(ans,temp);
}
int main()
{
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
		cin >> n >> m;
		ans=0;
		int sx,sy;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				cin >> g[i][j];
				if (g[i][j]=='T')
				{
					sx=i;sy=j;
				}
			}
//			getchar();
		}
		for (int i=0;i<4;i++)
		{
			CLR(vis);
			temp=0;
			dfs(dir[i][0],dir[i][1],sx,sy);
		}
		cout << ans << endl;
	return 0;
}

