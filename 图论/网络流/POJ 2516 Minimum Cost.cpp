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
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T gcd(const T& a,const T& b) {return b==0?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1e5+100;
const int M=200;

int n,m,k;
int havekind[M],have[M][M];
int needkind[M],need[M][M];	

int pnt[N],head[M],nxt[N],cap[N],cost[N],pre[N];
int cnt;

void add_edge(int u,int v,int f,int w) {
	pnt[cnt]=v;pre[cnt]=u;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt]=f;cost[cnt++]=w;
}

int a[M],p[M],vis[M];
ll d[M];

bool spfa(int s,int t,int &Flow,ll& Cost) {
	CLR(a);CLR(vis);
	rep(i,s,t) d[i]=INF_INT;
	queue<int> q;
	vis[s]=1;
	a[s]=INF_INT;
	d[s]=0;
	q.push(s);
	while (q.size()) {
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=head[x];~i;i=nxt[i]) {
			int v=pnt[i];
			if (d[v]>d[x]+cost[i] && cap[i]) {
				d[v]=d[x]+cost[i];
				p[v]=i;
				a[v]=min(a[x],cap[i]);
				if (!vis[v]) {
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	if (d[t]>=INF_INT) return false;
	Flow+=a[t];
	Cost+=a[t]*d[t];
	for (int u=t;u!=s;u=pre[p[u]]) {
		cap[p[u]]-=a[t];
		cap[p[u]^1]+=a[t];
	}
	return true;
}

ll MCMF(int s,int t) {
	int Flow=0;
	ll Cost=0;
	while (spfa(s,t,Flow,Cost));
	return Cost;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SIII(n,m,k)==3 && !(!n && !m && !k)) {
		CLR(havekind);CLR(needkind);
		rep(i,1,n) rep(j,1,k) {
			SI(need[i][j]);
			needkind[j]+=need[i][j];			
		}
		rep(i,1,m) rep(j,1,k) {
			SI(have[i][j]);
			havekind[j]+=have[i][j];
		}
		int flag=1;
		rep(i,1,k) if (needkind[i]>havekind[i]) flag=0;
		int source=0,sink=m+n+1;
		ll ans=0;
		rep(z,1,k) {
			OFF(head);cnt=0;
			rep(i,1,n) rep(j,1,m) {
				int x;SI(x);
				add_edge(j,i+m,INF_INT,x);
				add_edge(i+m,j,0,-x);
			}
			if (!flag) continue;
			rep(i,1,m) {
				add_edge(source,i,have[i][z],0);
				add_edge(i,source,0,0);
			}
			rep(i,1,n) {
				add_edge(i+m,sink,need[i][z],0);
				add_edge(sink,i+m,0,0);
			}
			ans+=MCMF(source,sink);
		}
		if (!flag) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}

