//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
const int maxn=100010*3;
int pnt[maxn],head[maxn],next[maxn],count[maxn],vis[maxn],d[maxn];
int n,m,k;
int cnt;

void addedge(int u,int v){
	pnt[cnt]=v;next[cnt]=head[u];head[u]=cnt++;
}

void spfa();

int main()
{
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (scanf("%d%d%d",&n,&m,&k)==3){
		cnt=0;
		memset(head,-1,sizeof(head));
		for (int i=1;i<=m;i++){
			int u,int v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		
	}
	return 0;
}


