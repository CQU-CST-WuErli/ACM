//  Created by Chenhongwei on 2016-05-17 Tuesday 20:03
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
const int maxn=1e6+100;
typedef long long ll;
typedef unsigned long long ull;
ll n,c;
ll a[maxn],dp[maxn];
int que[maxn];
double Slope(int x,int y)
{
	return double(dp[y]-dp[x]+a[y+1]*a[y+1]-a[x+1]*a[x+1])/(double)(2.0*(a[y+1]-a[x+1]));
}
int main()
{
	//ios::sync_with_stdio(false);
    // freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%lld%lld",&n,&c);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		dp[0]=0,dp[1]=c;
		int l=0,r=1;
		que[0]=0,que[r]=1;
		for(int i=2;i<=n;i++)
		{
			while(l<r&&Slope(que[l],que[l+1])<=(double)a[i])
				++l;
			dp[i]=dp[que[l]]+c+(a[i]-a[que[l]+1])*(a[i]-a[que[l]+1]);
			while(l<r&&Slope(que[r],i)<=Slope(que[r-1],que[r]))
				--r;
			que[++r]=i;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}