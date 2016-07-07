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
#define INF 1<<31
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
#define maxn 55000 
int N,M; //N girls M boys
long long R;  //R个关系;
int x[maxn],y[maxn],d[maxn]; 
int par[maxn],rank[maxn];
struct Edge
{
	int u,v,cost;
}e[maxn];
void init(int n)                  //初始化 
{
	for (int i=0;i<=n;i++)
	{
		par[i]=i;
		rank[i]=0;
	}
} 

int find(int x)             //寻找父亲节点 
{
	if (par[x]==x) return x;
	else return par[x]=find(par[x]);
}

bool same(int x,int y)          //比较父亲节点 
{
	return find(x)==find(y);
}

bool cmp(const Edge &a,const Edge &b)            //比较函数，用于sort排序 
{
	return a.cost <b.cost;
}

void unite(int x,int y)
{
	x=find(x);y=find(y);
	if (x==y)  return ;
	if (rank[x]<rank[y]) par[x]=y;
	else
	{
		par[y]=x;
		if (rank[x]==rank[y])
			rank[x]++;
	}
}
int kruskal()
{
	sort(e+1,e+1+R,cmp);
	init(N+M);
	int res=0;
	for (long long i=1;i<=R;i++)
	{
		Edge es=e[i];
		if (!same(es.u,es.v))
		{
			unite(es.u,es.v);
			res+=es.cost;
		}
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%lld",&N,&M,&R);
		for (long long i=1;i<=R;i++)
		{
			scanf("%d%d%d",&x[i],&y[i],&d[i]);
			e[i]=(Edge){x[i],N+y[i],-d[i]}; 
		}
		cout << 10000*(M+N)+kruskal() << endl;
	}
	return 0;
}

