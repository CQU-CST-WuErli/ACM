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
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1e5+100; 
int n,m;
struct Edge {
	int v,dis;
	Edge(int _v,int _dis) {
		v=_v,dis=_dis;
	}
};
vector<Edge> g[N];

int tu,tv,td;
int vis[N<<1],dep[N<<1],fst[N<<1],dfs_clock,dis[N<<1];
int dp[20][N<<1];

void dfs(int fa,int u,int d,int ds) {
	vis[++dfs_clock]=u;
	dep[dfs_clock]=d;
	fst[u]=dfs_clock;
	dis[u]=ds;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i].v;
		if (v==fa) continue;
		dfs(u,v,d+1,ds+g[u][i].dis);
		vis[++dfs_clock]=u;
		dep[dfs_clock]=d;
	}
}

int getMin(int x,int y) {
	return dep[x]<dep[y]?x:y;
}

struct SparseTable {
	void init(int n) {
		for (int i=1;i<=n;i++) dp[0][i]=i;
		for (int i=1;(1<<i)<=n;i++) {
			for (int j=1;j+(1<<i)-1<=n;j++) {
				dp[i][j]=getMin(dp[i-1][j],dp[i-1][j+(1<<i-1)]);
			}
		}
	}
	int RMQ(int l,int r) {
		int k=31-__builtin_clz(r-l+1);
		return getMin(dp[k][l],dp[k][r-(1<<k)+1]);
	}
}st;

int lca(int u,int v) {
	if (fst[u]>fst[v]) swap(u,v);
	int id=st.RMQ(fst[u],fst[v]);
	return vis[id];
}

int gao(int u,int v) {
	return dis[u]+dis[v]-2*dis[lca(u,v)];
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	for (int kase=scanf("%d",&T_T);kase<=T_T;kase++) {
		cin >> n >> m;
		for (int i=0;i<=n;i++) g[i].clear();
		int root=0;
		for (int i=1;i<n;i++) {
			int u,v,d;
			SIII(u,v,d);
			if (!root) root=u;
			g[u].push_back(Edge(v,d));
			g[v].push_back(Edge(u,d));
		}
		SIII(tu,tv,td);
		dfs_clock=0;
		dfs(-1,root,0,0);
		st.init(2*n+1);
		printf("Case #%d:\n",kase);
		for (int i=1;i<=m;i++) {
			int u,v;
			SII(u,v);
			int tmp=gao(u,v);
			int t1=gao(u,tu)+td+gao(v,tv);
			int t2=gao(u,tv)+td+gao(v,tu);
			int ans=tmp-min(t1,t2);
			if (ans<=0) ans=0;
			printf("%d\n",ans);
		}
	}
	return 0;
}

