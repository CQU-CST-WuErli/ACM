//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N = 40010;
int n, m;
struct Edge
{
	int v, w;
	Edge(int v, int w):v(v), w(w){}
};
vector<Edge> g[N];

int vis[N << 1 | 1], dep[N << 1 | 1];
int first[N];
int dis[N];
int dfs_clock;

void dfs(int fa, int u, int d, int cnt) {
	first[u] = ++ dfs_clock;
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

struct SpareTable
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

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
        SII(n, m);
        for (int i = 0; i <= n; i++) g[i].clear();
        for (int i = 1; i < n; i++) {
        	int u, v, w;
        	SIII(u, v, w);
        	g[u].push_back(Edge(v, w));
        	g[v].push_back(Edge(u, w));
        }
        CLR(vis); CLR(vis); CLR(dep); CLR(first); CLR(dis);
        dfs_clock = 0;
        dfs(-1, 1, 0, 0);
        st.init(2 * n);
        for (int i = 1; i <= m; i++) {
        	int u, v;
        	SII(u, v);
        	int LCA = lca(u, v);
        	printf("%d\n", dis[u] + dis[v] - 2 * dis[LCA]);
        }
    }
	return 0;
}