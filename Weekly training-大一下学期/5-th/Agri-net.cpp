///////////////////////////////////////////////////////// 
//                           //                        //
//  Created by  Team 3 			                       //
//  Copyright (c) 2015年 Team 3. All rights reserved.  //
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
#define maxn 150
struct Edge
{
	int u,v,cost;
}es[maxn*maxn];
int par[maxn*maxn],rank[maxn*maxn];
int n;

void init(int n)                  //初始化 
{
	for (int i=0;i<=n;i++)
	{
		par[i]=i;
		rank[i]=0;
	}
} 

int find(int x)
{
	if (par[x]==x) return x;
	else  return par[x]=find(par[x]);
}

bool cmp(const Edge &a,const Edge &b)
{
	return a.cost < b.cost;
}

bool same(int x,int y)
{
	return find(x)==find(y);
}

void unite(int x,int y)
{
	x=find(x);y=find(y);
	if (x==y) return ;    //是同一个集合
	if (rank[x]<rank[y]) par[x]=y;
	else
	{
		par[y]=x;
		if (rank[x]==rank[y])
			rank[x]++;                //同样的深度则在增减一个父节点 
	}  	
}

int kruskal()
{
	int res=0;
	init(n*n+1);
	sort(es+1,es+1+n*n,cmp);
	for (int i=1;i<=n*n;i++)
	{
		Edge e=es[i];
		if (!same(e.u,e.v))
		{
			unite(e.u,e.v);
			res+=e.cost;
		}
	}
	return res;
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		int tot=1;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			{
				int w;
				scanf("%d",&w);
				es[tot++]=(Edge){i,j,w};
			}
		cout << kruskal() << endl;
	}
	return 0;
}

