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

int n,q;
struct Edge
{
	int v, w;
	Edge(int v, int w):v(v), w(w) {}
	Edge() {}
};
vector<Edge> g[N];
int vis[N << 1],dep[N << 1],first[N];
int dis[N];
int dfs_clock;

void dfs(int fa, int u, int d, int cnt) {
	first[u] = ++dfs_clock;
	dis[u] = cnt;
	vis[dfs_clock] = u;
	dep[dfs_clock] = d;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].v;
		int w = g[u][i].w;
		if (v == fa) continue;
		dfs(u, v, d + 1, cnt + w);
		vis[++dfs_clock] = u;
		dep[dfs_clock] = d;
	}
}

struct SparseTable
{
	int dp[20][N << 1 | 1];
	int getMin(int x, int y) {
		return dep[x] < dep[y] ? x : y;
	}
	void init(int n) {
		for (int i = 1; i <= n; i++) dp[0][i] = i;
		for (int i = 1; (1 << i) <= n; i++) {
			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
				dp[i][j] = getMin(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	int query(int l, int r) {
		int k = 31 - __builtin_clz(r - l + 1);
		return getMin(dp[k][l], dp[k][r - (1 << k) + 1]);
	}
}st;

int lca(int u, int v) {
	if (first[u] > first[v]) swap(u, v);
	int id = st.query(first[u], first[v]);
	return vis[id];
}

int tu, tv, tw;

int gao(int u, int v) {
	return dis[u] + dis[v] - 2 * dis[lca(u, v)];
}

int cal(int u, int v) {
	int dis1 = gao(u, v);
	int dis2 = gao(u, tu) + tw + gao(v, tv);
	int dis3 = gao(u, tv) + tw + gao(v, tu);
	return max(0, max(dis1 - dis2, dis1 - dis3));
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	for (int kase=scanf("%d",&T_T);kase<=T_T;kase++) {
		cin >> n >> q;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v, w;
			SIII(u, v, w);
			g[u].push_back(Edge(v, w));
			g[v].push_back(Edge(u, w));
		}
		SIII(tu, tv, tw);
		CLR(vis); CLR(dep); CLR(dis); CLR(first);
		dfs_clock = 0;
		dfs(-1, 1, 0, 0);
		st.init(n << 1);
		// BUG;
		printf("Case #%d:\n", kase);
		for (int i = 1; i <= q; i++) {
			int u, v;
			SII(u, v);
			printf("%d\n", cal(u, v));
		}
	}
	return 0;
}

