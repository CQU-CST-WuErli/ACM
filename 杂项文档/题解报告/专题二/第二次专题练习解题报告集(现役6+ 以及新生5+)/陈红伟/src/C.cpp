//  Created by Chenhongwei on 2016-05-14 Saturday 10:00
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
int t[5];
int dp[41][41][41][41];
int n,m;
int v[400];
int main()
{
	//ios::sync_with_stdio(false);
    // freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(t,0,sizeof t);
		int tmp;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&v[i]);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&tmp);
			t[tmp]++;
		}
		memset(dp,0,sizeof dp);
		dp[0][0][0][0]=v[1];
		for(int i=0;i<=t[1];i++)
			for(int j=0;j<=t[2];j++)
				for(int k=0;k<=t[3];k++)
					for(int z=0;z<=t[4];z++)
					{
						if(i!=0)
							dp[i][j][k][z]=max(dp[i][j][k][z],dp[i-1][j][k][z]+v[i+j*2+k*3+z*4+1]);
						if(j!=0)
							dp[i][j][k][z]=max(dp[i][j][k][z],dp[i][j-1][k][z]+v[i+j*2+k*3+z*4+1]);
						if(k!=0)
							dp[i][j][k][z]=max(dp[i][j][k][z],dp[i][j][k-1][z]+v[i+j*2+k*3+z*4+1]);
						if(z!=0)
							dp[i][j][k][z]=max(dp[i][j][k][z],dp[i][j][k][z-1]+v[i+j*2+k*3+z*4+1]);
					}
		printf("%d\n",dp[t[1]][t[2]][t[3]][t[4]]);
	}
	return 0;
}
