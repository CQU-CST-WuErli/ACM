//  Created by Chenhongwei on 2016-05-05 Thursday 23:20
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
const int maxn=1e5+100;
typedef long long ll;
typedef unsigned long long ull;
int n,num,ans,dp[1010];
bool dfs(int cur,int d)
{
	if(d>=ans)
	{
		if(cur==n)
			return true;
		return false;
	}
	int maxn=0;
	for(int j=0;j<num;j++)
		maxn=max(dp[j],maxn);
	if( (cur+maxn) << (ans-d-1) < n)
		return false;
	for(int i=num-1;i>=0;i--)
	{
		dp[num++]=cur+dp[i];
		if(dfs(cur+dp[i],d+1))
			return true;
		num--;
		dp[num++]=cur-dp[i];
		if(dfs(cur-dp[i],d+1))
			return true;
		num--;
	}
	return false;
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
		scanf("%d",&n);
		int tmp=1;
		ans=0;
		while(n>tmp)
		{
			tmp*=2;
			ans++;
		}
		while(1)
		{
			memset(dp,0,sizeof dp);
			dp[0]=num=1;
			if(dfs(1,0))break;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
