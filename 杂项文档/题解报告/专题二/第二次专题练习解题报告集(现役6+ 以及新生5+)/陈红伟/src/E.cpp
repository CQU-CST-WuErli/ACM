//  Created by Chenhongwei on 2016-05-18 Wednesday 00:38
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
int dp[2][maxn];
int w[100];
int main()
{
	//ios::sync_with_stdio(false);
    // freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,sum=0;
		scanf("%d",&n);
		memset(dp,0xc0,sizeof dp);
		dp[0][0]=0;
		int p=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&w[i]);
			sum+=w[i];
		}
		for(int i=1;i<=n;i++)
		{
			p=1-p;
			for(int j=0;j<=sum;j++)
			{
				dp[p][j]=dp[1-p][j+w[i]]+w[i];
				if(j>=w[i])
					dp[p][j]=max(dp[p][j],dp[1-p][j-w[i]]);
				else
					dp[p][j]=max(dp[p][j],dp[1-p][w[i]-j]+w[i]-j);
				dp[p][j]=max(dp[p][j],dp[1-p][j]);
			}
		}
		if(dp[p][0]<=0)
			puts("GG");
		else
			printf("%d\n",dp[p][0]);	
	}
	return 0;
}
