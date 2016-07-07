///////////////////////////////////////////////////////// 
//                                                     //
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
const int maxn=2005;
int n,ans=0; 
int pnt[maxn],pre[maxn],head[maxn],cnt=0;
int f[maxn];

void addedge(int u,int v)
{
	pnt[cnt]=v;pre[cnt]=head[u];head[u]=cnt++;
} 

void dfs(int p,int step)
{
	ans=max(ans,step);
	for (int i=head[p];i!=-1;i=pre[i])
		dfs(pnt[i],step+1);
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(head,-1,sizeof(head));
		CLR(pre);
		CLR(pnt);
		CLR(f);
		cir(i,1,n)
		{
			int u;
			scanf("%d",&u);
			if (u==-1)
				f[i]=-1;
			else addedge(u,i);
		} 
		cir (i,1,n)
			if (f[i]==-1)
				dfs(i,1);
		printf("%d\n",ans);
	}
	return 0;
} 
