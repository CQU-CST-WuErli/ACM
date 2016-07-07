//  Created by Chenhongwei on 2016-06-04 Saturday 08:33
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
const int maxn=5e5+100;
typedef long long ll;
typedef unsigned long long ull;
struct node
{
	int u,v,w;
	bool operator < (const node & rhs) const
	{
		return w<rhs.w;
	}
};
int f[maxn];
node a[maxn*4];
int n,m;
int find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
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
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
			f[i]=i;
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		sort(a+1,a+m+1);
		int ans=-1;
		for(int i=1;i<=m;i++)
		{
			int x=find(a[i].u);
			int y=find(a[i].v);
			if(x!=y)
				f[x]=y;
			else if(ans==-1)
				ans=a[i].w;
		}
		if(ans==-1)
			puts("No solution!");
		else
			printf("%d\n",ans);
	}
	return 0;
}
