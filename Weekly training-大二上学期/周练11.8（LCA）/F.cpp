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
struct Edge{
	int v,flag;
	Edge(int _,int __) {
		v=_;
		flag=__;
	}
};
vector<Edge> g[N];
int n,q;

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
		dfs(u,v,d+1,ds+g[u][i].flag);
		vis[++dfs_clock]=u;
		dep[dfs_clock]=d;
	}
}

int DIS[N<<1];
void DFS(int fa,int u,int d) {
	DIS[u]=d;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i].v;
		if (v==fa) continue;
		DFS(u,v,d+1);
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

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n) {
		for (int i=1;i<=n;i++) g[i].clear(); 
		for (int i=1;i<n;i++) {
			int u,v;
			SII(u,v);
			g[u].push_back(Edge(v,1));
			g[v].push_back(Edge(u,-1));
		}
		dfs_clock=0;
		dfs(-1,1,0,0);	
		st.init(2*n+1);
		DFS(-1,1,0);
		cin >> q;
		while (q--) {
			int u,v;
			SII(u,v);
			int Lca=lca(u,v);
			int DIS1=DIS[u]-DIS[Lca];
			int DIS2=DIS[v]-DIS[Lca];
			int dis1=dis[u]-dis[Lca];
			int dis2=dis[v]-dis[Lca];
			if (DIS1==-dis1 && DIS2==dis2) puts("Yes");
			else puts("No");
		}	
	}	
	return 0;
}

