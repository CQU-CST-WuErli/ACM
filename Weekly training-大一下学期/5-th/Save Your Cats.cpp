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
#define maxn 10010
struct Edge
{
	int u,v;
	double cost;
}es[maxn*maxn];

int N,M;
int par[maxn*maxn],rank[maxn*maxn];
int x[maxn*maxn],y[maxn*maxn];

void init(int n)
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
	else return par[x]=find(par[x]);
}

bool cmp(const Edge &a,const Edge &b)
{
	return a.cost>b.cost;
}

bool same(int x,int y)
{
	return find(x)==find(y);
}

void unite(int x,int y)
{
	x=find(x);y=find(y);
	if (x==y)  return ;
	if (rank[x]<rank[y]) par[x]=y;
	else
	{
		par[y]=x;
		if (rank[x]==rank[y]) rank[x]++;
	}
}

double kruskal()
{
	init(M);
	sort(es+1,es+1+M,cmp);
	double res=0.00;
	for (int i=1;i<=M;i++)
	{
		Edge &e=es[i];
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
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		double sum=0.00;
		for (int i=1;i<=N;i++)
			scanf("%d%d",&x[i],&y[i]);
		for (int i=1;i<=M;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			es[i].u=u;
			es[i].v=v;
			es[i].cost=sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
			sum+=es[i].cost;
		}
//		cout << sum << endl;
		double ans=kruskal();
		printf("%.3lf\n",sum-ans);
	}
	return 0;
}

