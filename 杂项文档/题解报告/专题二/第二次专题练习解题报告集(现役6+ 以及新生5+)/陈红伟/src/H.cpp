//  Created by Chenhongwei on 2016-05-14 Saturday 08:41
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
int n,m;
ll a[maxn],num[maxn];
bool f[maxn],q[maxn];
int main()
{
	//ios::sync_with_stdio(false);
    // freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%lld",&num[i]);
		memset(f,0,sizeof f);
		f[0]=1;
		memset(q,0,sizeof q);
		for(int i=1;i<=n;i++)
		{
			if(num[i]==1)
			{
				for(int j=m;j>=a[i];j--)
					if(f[j]||f[j-a[i]])
						f[j]=1;
			}
			else if(a[i]*num[i]>=m)
			{
				for(int j=a[i];j<=m;j++)
					if(f[j]||f[j-a[i]])
						f[j]=1;
			}
			else
			{
				ll h,t;
				for(int i=0;i<a[i];i++)
				{
					ll sum=0;
					h=t=q[0]=0;
					for(int j=i;j<=m;j+=a[i])
					{
						if(t-h==num[i]+1)
							sum-=q[++h];
						sum+=(q[++t]==f[j]);
						if(sum)
							f[j]=1;
					}
				}
			}
		}
		if(f[m])
			puts("yes");
		else
			puts("no");
	}
	return 0;
}