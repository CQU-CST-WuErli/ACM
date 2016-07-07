//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for (int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1e5+100;
const ll Maxf=1000000000;

set<ll> st;

ll fib[N];
int n,m;
ll val[N];
int in[N];

void init() {
	fib[1]=1,fib[2]=1;
	st.insert(1);
	int cnt=3;
	while (1) {
		fib[cnt]=fib[cnt-1]+fib[cnt-2];
		st.insert(fib[cnt]);
		if (fib[cnt]>Maxf) break;
		cnt++;
	}
}

int par[N],rnk[N],sum[N];

void initset() {
	rep(i,1,n) {
		par[i]=i;
		rnk[i]=0;
		sum[i]=in[i];
	}
}

int find(int x) {
	if (par[x]==x) return x;
	else {
		int fa=x;
		while (par[fa]!=fa) fa=par[fa];
		while (x!=fa) {
			int tmp=par[x];
			par[x]=fa;
			x=tmp;
		}
	}
	return x;
}

bool same(int x,int y) {
	return find(x)==find(y);
}

void unite(int x,int y) {
	x=find(x);y=find(y);
	if (rnk[x]<rnk[y]) {
		par[x]=y;sum[y]+=sum[x];sum[x]=0;
	}	
	else {
		par[y]=x;
		sum[x]+=sum[y];
		sum[y]=0;
		if (rnk[x]==rnk[y]) rnk[x]++;
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
//	rep(i,1,10) cout << fib[i] << endl;
	while (SII(n,m)==2) {
		rep(i,1,n) {
			scanf("%I64d",val+i);
			if (st.count(val[i])) in[i]=1;
			else in[i]=0;
		}
		initset();
		rep(i,1,m) {
			int u,v;
			SII(u,v);
			if (!same(u,v)) unite(u,v);
		}
		int ans=0;
		rep(i,1,n) ans=max(ans,sum[find(i)]);
		cout << ans << endl; 
	}
	return 0;
}

