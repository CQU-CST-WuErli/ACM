//  Created by Chenhongwei on 2016-05-20 Friday 22:51
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
double exc[maxn]={0},sum[maxn]={0},rev[maxn]={0},t[maxn];
double dp[maxn][55];
int q[maxn],tail,top;
double ss(int x,int y)
{
	return dp[x][y]-exc[x]+sum[x]*rev[x];
}
double slope(int x,int y,int z)
{
	return (ss(x,z)-ss(y,z))/(sum[x]-sum[y]);
}
double cal(int l,int r)
{
	return exc[r]-exc[l]-sum[l]*(rev[r]-rev[l]);
}
void add(int x,int y)
{
	while(top<tail-1&&slope(x,q[tail-1],y)<slope(q[tail-1],q[tail-2],y))
		tail--;
	q[tail++]=x;
}
int getmax(int x,int y)
{
	while(top<tail-1&&slope(q[top+1],q[top],y)<rev[x])
		top++;
	return q[top];
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
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%lf",&t[i]);
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+t[i];
			rev[i]=rev[i-1]+1.0/t[i];
			exc[i]=exc[i-1]+sum[i]/t[i];	
		}
		for(int i=1;i<=n;i++)
			dp[i][1]=exc[i];
		for(int i=2;i<=k;i++)
		{
			top=tail=0;
			q[tail++]=0;
			for(int j=1;j<=n;j++)
				add(j,i-1);
			for(int j=1;j<=n;j++)
				if(j>=i)
				{
					int l=getmax(j,i-1);
					dp[j][i]=dp[l][i-1]+cal(l,j);
				}
				else dp[j][i]=1e40;
		}
		printf("%.4lf\n",dp[n][k]);
	}
	
	return 0;
}
