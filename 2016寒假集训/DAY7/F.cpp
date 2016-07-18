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

const int N=(2e5+100);
const int M=(2e6+100);

int pnt[M],nxt[M],head[N],cost[M];
int cnt;

void add_edge(int u,int v,int w) {
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;cost[cnt++]=w;
}

int n,m,c;
int lay[N];
int has[N];

int vis[N];
int dis[N];

int spfa() {
	CLR(vis);
	MEM(dis,INF_INT);
	dis[1]=0;
	vis[1]=1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=head[x];~i;i=nxt[i]) {
			int v=pnt[i];
			if (dis[v]>dis[x]+cost[i]) {
				dis[v]=dis[x]+cost[i];
				if (!vis[v]) {
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dis[n];
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
		OFF(head);cnt=0;
		SIII(n,m,c);
		CLR(has);
		rep(i,1,n) {
			SI(lay[i]);
			lay[i]+=n;
			has[lay[i]]=1;
		}
		rep(i,n+1,n+n-1) {
			if (has[i] && has[i+1]) {
				add_edge(i,i+1,c);
				add_edge(i+1,i,c);
			}
		}
		rep(i,1,n) {
			add_edge(lay[i],i,0);
			if (lay[i]>n+1 && has[lay[i]-1]) add_edge(i,lay[i]-1,c);
			if (lay[i]<n+n && has[lay[i]+1]) add_edge(i,lay[i]+1,c);
		}
		while (m--) {
			int u,v,w;
			SIII(u,v,w);
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
		int ans=spfa();
		printf("Case #%d: %d\n",kase,ans>=INF_INT?-1:ans);
	}
	return 0;
}
