//  Created by Chenhongwei on 2016-05-20 Friday 08:47
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
const int maxn=2e5+100;
typedef long long ll;
typedef unsigned long long ull;
ll dp[2][maxn];
int a[maxn],b[maxn],t[maxn];
int q[maxn];
int main()
{
	//ios::sync_with_stdio(false);
    // freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,s;
		scanf("%d%d%d",&n,&m,&s);
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&a[i],&b[i],&t[i]);
		memset(dp,0,sizeof dp);
		int u=0;
		for(int i=1;i<=m;i++)
		{
			u=1-u;
			int d=min((ll)(t[i]-t[i-1])*s,(ll)n);
			int h=0,t=0;
			for(int j=1;j<=d;j++)
			{
				while(t>0&&dp[1-u][q[t-1]]<=dp[1-u][j])
					t--;
				q[t++]=j;
			}
			for(int j=1;j<=n;j++)
			{
				if(j+d<=n)
				{
					while(t>0&&dp[1-u][q[t-1]]<=dp[1-u][j+d])
						t--;
					q[t++]=j+d;
				}
				dp[u][j]=dp[1-u][j];
				while(h<t&&q[h]+d<j)
					h++;
				if(h<t)
					dp[u][j]=max(dp[u][j],dp[1-u][q[h]]);
				dp[u][j]+=b[i]-abs(a[i]-j);
			}
		}
		ll ans=dp[u][1];
		for(int i=2;i<=n;i++)
			ans=max(ans,dp[u][i]);
		cout<<ans<<endl;
	}
	return 0;
}
