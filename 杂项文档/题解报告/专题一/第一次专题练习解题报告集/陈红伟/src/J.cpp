//  Created by Chenhongwei on 2016-05-09 Monday 17:08
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
const int maxn=1e5+100;
typedef long long ll;
typedef unsigned long long ull;
char s[maxn],t[maxn*2];
ll p[maxn*2],pp[maxn*2];
ll n,m,cnt;
ll mz,mod;
ll a[maxn],v[maxn*34];
ll nxt[maxn*34][2];
void init()
{
	t[0]='$',t[1]='#';
	for(ll i=0;i<n;i++)
	{
		t[i*2+2]=s[i];
		t[i*2+3]='#';
	}
	n=n*2+2;
	t[n]=0;
}
void manacher()
{
	ll maxv=0,pos;
	for(ll i=1;i<n;i++)
	{
		if(maxv>i)
			p[i]=min(p[2*pos-i],maxv-i);
		else
			p[i]=1;
		while(t[i-p[i]]==t[i+p[i]]&&i+p[i]<n)
			p[i]++;
		if(p[i]+i>maxv)
		{
			maxv=p[i]+i;
			pos=i;
		}
	}
}
void insert(int x)
{
	ll u=0;
	for(ll i=31;i>=0;i--)
	{
		ll k=(x>>i)&1;
		if(!nxt[u][k])
		{
			memset(nxt[cnt],0,sizeof nxt[cnt]);
			v[cnt]=0;
			nxt[u][k]=cnt++;
		}
		u=nxt[u][k];
		v[u]++;
	}
}
ll query(int x)
{
	ll u=0;
	ll ret=0;
	for(ll i=31;i>=0;i--)
	{
		ll k=((x>>i)&1)^1;
		if(nxt[u][k])
			ret|=(1<<i);
		else
			k^=1;
		u=nxt[u][k];
	}
	return ret;
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
		scanf("%s",s);
		m=n=strlen(s);
		init();
		manacher();
		mz=1;
		ll tt=0;
		for(ll i=0;i<n;i++)
			if(t[i]!='#'&&t[i]!='$')
			{
				mz=max(mz,p[i]-1);
				pp[++tt]=p[i]-1;
			}
		ll num=m*m*m;
		ll mod=mz/3*5+1;
		ll JD=1,tmp=mz;
		while(num)
		{
			if(num&1)
				JD=JD*tmp%mod;
			tmp=(tmp*tmp)%mod;
			num>>=1;
		}
		JD+=(mz*4/5);
		cnt=1,v[0]=0;
		memset(nxt[0],0,sizeof nxt[0]);
		for(ll i=1;i<=tt;i++)
		{
			a[i]=a[i-1]^pp[i];
			insert(a[i]);
		}
		ll FJD=-1;
		for(ll i=0;i<=tt;i++)
			FJD=max(FJD,query(a[i]));
		if(JD>FJD)
			puts("liujc");
		else
			puts("luoxinchen");
	}
	return 0;
}