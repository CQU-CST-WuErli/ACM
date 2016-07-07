//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
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

int n, m;
vector<int> id[100010];

struct Chain {
	int u, v, w;
	Chain(int u, int v, int w):u(u), v(v), w(w) {}
	Chain() {}
};
vector<Chain> chain;

struct SegmentTree {
	const static int N = 100020;
	int sum[N << 2], dp[N << 2];

	void push_up(int rt) {
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
		dp[rt] = dp[rt << 1] + dp[rt << 1 | 1];
	}
	void build(int l, int r, int rt) {
		sum[rt] = dp[rt] = 0;
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(l, mid, rt << 1);
		build(mid + 1, r, rt << 1 | 1);
		push_up(rt);
	}
	void change(int o, int v1, int v2, int l, int r, int rt) {
		if (l == r) {
			sum[rt] = v1;
			dp[rt] = v2;
			return;
		}
		int mid = (l + r) >> 1;
		if (o <= mid) change(o, v1, v2, l, mid, rt << 1);
		else change(o, v1, v2, mid + 1, r, rt << 1 | 1);
		push_up(rt);
		return;
	}
	int querySum(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return sum[rt];
		}
		int ret = 0;
		int mid = (l + r) >> 1;
		if (L <= mid) ret += querySum(L, R, l, mid, rt << 1);
		if (R > mid) ret += querySum(L, R, mid + 1, r, rt << 1 | 1);
		push_up(rt);
		return ret;
	}
	int queryDp(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return dp[rt];
		}
		int ret = 0;
		int mid = (l + r) >> 1;
		if (L <= mid) ret += queryDp(L, R, l, mid, rt << 1);
		if (R > mid) ret += queryDp(L, R, mid + 1, r, rt << 1 | 1);
		push_up(rt);
		return ret;
	}
}T;

struct HLD {
	const static int N = 100010;
	const static int M = 200020;
	int pnt[M], nxt[M], head[N], cnt;
	int sz[N], fa[N], son[N], dep[N], pre[N], top[N], dfs_clock;

	void init() {
		dfs_clock = cnt = 0;
		CLR(son);
		OFF(head);
	}
	void add_edge(int u, int v) {
		pnt[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
	}
	void dfs1(int f, int u, int d) {
		sz[u] = 1; fa[u] = f; dep[u] = d;
		for (int i = head[u]; i != -1; i = nxt[i]) {
			int v = pnt[i];
			if (v == f) continue;
			dfs1(u, v, d + 1);
			if (son[u] == 0 || sz[son[u]] < sz[v]) son[u] = v;
			sz[u] += sz[v];
		}
	}
	void dfs2(int tp, int u) {
		pre[u] = ++dfs_clock;
		top[u] = tp;
		if (son[u]) dfs2(tp, son[u]);
		for (int i = head[u]; ~i; i = nxt[i]) {
			int v = pnt[i];
			if (v == fa[u] || v == son[u]) continue;
			dfs2(v, v);
		}
	}
	void build() {
		dfs1(-1, 1, 0);
		dfs2(1, 1);
	}
	int LCA(int u, int v) {
		int fu = top[u], fv = top[v];
		while (fu != fv) {
			if (dep[fu] < dep[fv]) {
				swap(fu, fv);
				swap(u, v);
			}
			u = fa[fu]; fu = top[u];
		}
		return dep[u] <= dep[v] ? u : v;
	}
	int getSum(int u, int v) {
		int ret = 0;
		int fu = top[u], fv = top[v];
		while (fu != fv) {
			if (dep[fu] < dep[fv]) {
				swap(fu, fv);
				swap(u, v);
			}
			ret += T.querySum(pre[fu], pre[u], 1, dfs_clock, 1);
			u = fa[fu]; fu = top[u];
		}
		if (dep[u] > dep[v]) swap(u, v);
		ret += T.querySum(pre[u], pre[v], 1, dfs_clock, 1);
		return ret;
	}
	int getDp(int u, int v) {
		int ret = 0;
		int fu = top[u], fv = top[v];
		while (fu != fv) {
			if (dep[fu] < dep[fv]) {
				swap(fu, fv);
				swap(u, v);
			}
			ret += T.queryDp(pre[fu], pre[u], 1, dfs_clock, 1);
			u = fa[fu]; fu = top[u];
		}
		if (dep[u] > dep[v]) swap(u, v);
		ret += T.queryDp(pre[u], pre[v], 1, dfs_clock, 1);
		return ret;
	}
	void DP(int u) {
		int sum = 0;
		int ans = 0;
		for (int i = head[u]; ~i; i = nxt[i]) {
			int v = pnt[i];
			if (v == fa[u]) continue;
			DP(v);
			sum += getDp(v, v);
		}
		ans = max(ans, sum);
		for (int i = 0; i < id[u].size(); i++) {
			int index = id[u][i];
			int tu = chain[index].u, tv = chain[index].v;
			int tmp = chain[index].w + sum + getSum(tu, tv) - getDp(tu, tv);
			ans = max(ans, tmp);
		}
		T.change(pre[u], sum, ans, 1, dfs_clock, 1);
	}
}hld;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	SII(n, m);
    	hld.init();
    	for (int i = 1; i <= n; i++) id[i].clear();
    	chain.clear();
    	for (int i = 1; i < n; i++) {
    		int u, v;
    		SII(u, v);
    		hld.add_edge(u, v);
    		hld.add_edge(v, u);
    	}
    	hld.build();
    	for (int i = 1; i <= m; i++) {
    		int u, v, w;
    		SIII(u, v, w);
    		chain.push_back(Chain(u, v, w));
    	}
    	for (int i = 0; i < chain.size(); i++) {
    		int lca = hld.LCA(chain[i].u, chain[i].v);
    		id[lca].push_back(i);
    	}
    	T.build(1, hld.dfs_clock, 1);
    	hld.DP(1);
    	cout << T.queryDp(1, 1, 1, hld.dfs_clock, 1) << endl;
    }
	return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \|     |//  `.
            /  \|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			佛祖保佑		永无BUG
*/