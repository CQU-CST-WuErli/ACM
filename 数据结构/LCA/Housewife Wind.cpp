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

const int N = 100010;

struct Edge
{
	int v, w, id;
	Edge(int v, int w, int id):v(v), w(w), id(id) {}
	Edge() {}
};
vector<Edge> g[N];
int n, q, s;
int cost[N];
int first[N], dep[N << 1];
int dis[N], vis[N << 1];
int dfs_clock;
int lpos[N], rpos[N];

struct BIT
{
	int a[N << 1];
	int n;
	void init(int _) {
		n = _;
		memset(a, 0, sizeof a);
	}
	int lowbit(int x) {
		return x & -x;
	}
	void update(int pos, int v) {
		while(pos <= n) {
		    a[pos] += v;
		    pos += lowbit(pos);
		}
	}
	int query(int pos) {
		int ret = 0;
		while(pos) {
		    ret += a[pos];
		    pos -= lowbit(pos);
		}
		return ret;
	}
}bit;

void dfs(int fa, int u, int d, int cnt) {
	// lookln(u);
	first[u] = ++dfs_clock;
	dis[u] = cnt;
	vis[dfs_clock] = u;
	dep[dfs_clock] = d;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].v;
		int w = g[u][i].w;
		int id = g[u][i].id;
		if (v == fa) continue;
		lpos[id] = dfs_clock;
		bit.update(dfs_clock, w);
		dfs(u, v, d + 1, cnt + w);
		vis[++dfs_clock] = u;
		dep[dfs_clock] = d;
		rpos[id] = dfs_clock;
		bit.update(dfs_clock, -w);
	}
}

struct SparseTable
{
	int dp[20][N << 1];
	int getMin(int x, int y) {
		return dep[x] < dep[y] ? x : y;
	}
	void init(int n) {
		for (int i = 1; i<= n; i++) dp[0][i] = i;
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
    while(SIII(n, q, s) == 3) {
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i < n; i++) {
        	int u, v, w;
        	SIII(u, v, w);
        	g[u].push_back(Edge(v, w, i));
        	g[v].push_back(Edge(u, w, i));
        	cost[i] = w;
        }
        // CLR(first); CLR(vis); CLR(dis); CLR(dep);
        dfs_clock = 0;
        // CLR(lpos); CLR(rpos);
        bit.init(n << 1 | 1);
        dfs(-1, 1, 0, 0);
        st.init(n << 1 | 1);
        for (int i = 1; i <= q; i++) {
        	int op; SI(op);
        	if (op == 0) {
        		int u; SI(u);
        		int LCA = lca(u, s);
        		int ans = bit.query(first[u] - 1) + bit.query(first[s] - 1) - 2 * bit.query(first[LCA] - 1);
        		printf("%d\n", ans);
        		s = u;
        	}
        	else if (op == 1) {
        		int id, x;
        		SII(id, x);
        		bit.update(lpos[id], x - cost[id]);
        		bit.update(rpos[id], cost[id] - x);
        		cost[id] = x;
        	}
        }
    }
	return 0;
}