//  Created by Chenhongwei on 2016-05-18 Wednesday 09:32
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
ll gcd(ll x,ll y)
{
	if(y==0)
		return x;
	else
		return gcd(y,x%y);
}
ll a[maxn],n;
int main()
{
	//ios::sync_with_stdio(false);
    // freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ll maxv=0,t,cnt=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]==0) cnt++;
			if(i==1)
				t=a[i];
			else
				t=gcd(t,a[i]);
			maxv=max(maxv,a[i]);
		}
		ll m=maxv/t+cnt;
		double ans=0;
		for(int i=1;i<=m;i++)
			ans+=(double)m/(double)i;
		ans+=m-n;
		printf("%lld\n",(ll)ans);
	}
	return 0;
}