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
#define maxn 200
int  g[maxn];
int par[maxn],vis[maxn];
int np,nl;
void init(int n)
{
	for (int i=0;i<=n;i++)
	{
		par[i]=i;
	}
}

int find(int x)
{
	if (par[x]==x)  return x;
	else return par[x]=find(par[x]);
}


int main()
{
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	int t;
	cin >> t;
	while (t--)
	{
		int ans=0;
		init(200);
		CLR(vis);
		scanf("%d%d",&np,&nl);
		for (int i=1;i<=np;i++)
		{
			int n;
			cin >> n;
			if (n==0)
			{
				ans++;
			}
			for (int j=1;j<=n;j++)
			{
				scanf("%d",&g[j]);
				vis[g[j]]=1;
			}
			for (int j=1;j<n;j++)
				par[find(g[j])]=find(g[j+1]);
		}	
		if (ans==np)
		{
			ans++;
		}
		else
		{
			for (int i=1;i<=nl;i++)
				if (vis[i]==1 && par[i]==i)
					ans++;
		}
		cout << ans-1 << endl;
	}
	return 0;
}
