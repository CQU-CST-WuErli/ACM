//  Created by Chenhongwei on 2016-05-17 Tuesday 21:33
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
struct matrix 
{
	ll x[3][3];
};
matrix mul(matrix &A,matrix &B)
{
	matrix C;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			C.x[i][j]=0;
			for(int k=0;k<3;k++)
				C.x[i][j]=(C.x[i][j]+A.x[i][k]*B.x[k][j]%mod)%mod;
		}
	return C;
}
matrix fast_pow(ll m)
{
	matrix ans,tmp;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			ans.x[i][j]=(i==j);
	memset(tmp.x,0,sizeof tmp.x);
	tmp.x[0][0]=1,tmp.x[0][1]=1,tmp.x[0][2]=1;
	tmp.x[1][0]=1,tmp.x[2][1]=1;
	while(m)
	{
		if(m&1)
			ans=mul(ans,tmp);
		tmp=mul(tmp,tmp);
		m>>=1;
	}
	return ans;
}
ll a[1001];
ll n;
ll dp[10];
int main()
{
	//ios::sync_with_stdio(false);
    // freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	a[0]=2;
	while(T--)
	{
		int m;
		scanf("%lld%d",&n,&m);
		n+=2;
		for(int i=1;i<=m;i++)
		{
			scanf("%lld",&a[i]);
			a[i]+=2;
		}	
		m++;
		a[m]=n;
		dp[0]=0,dp[1]=0,dp[2]=1;
		for(int i=1;i<=m;i++)
		{
			if(a[i]-a[i-1]==0)
				continue;
			else if(a[i]-a[i-1]==1)
			{
				ll t0=dp[0],t1=dp[1],t2=dp[2];
				dp[2]=(t0+t1+t2)%mod;
				dp[0]=t1;
				dp[1]=t2;
				if(i!=m)
					dp[2]=0;
			}
			else if(a[i]-a[i-1]==2)
			{
				ll t0=dp[0],t1=dp[1],t2=dp[2];
				dp[0]=t2;
				dp[1]=(t0+t1+t2)%mod;
				dp[2]=(dp[0]+dp[1]+t1)%mod;
				if(i!=m)
					dp[2]=0;
			}
			else
			{
				matrix ans=fast_pow(a[i]-a[i-1]);
				ll t0=dp[0],t1=dp[1],t2=dp[2];
				dp[0]=(ans.x[2][0]*t2%mod+ans.x[2][1]*t1%mod+ans.x[2][2]*t0%mod)%mod;
				dp[1]=(ans.x[1][0]*t2%mod+ans.x[1][1]*t1%mod+ans.x[1][2]*t0%mod)%mod;
				if(i!=m)
					dp[2]=0;
				else
					dp[2]=(ans.x[0][0]*t2%mod+ans.x[0][1]*t1%mod+ans.x[0][2]*t0%mod)%mod;
			}
		}
		printf("%lld\n",dp[2]);
	}
	return 0;
}
