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

const int N = 50050;
int n, m;
struct Edge {
	int u, v, w;
	Edge(int u, int v, int w):u(u), v(v), w(w) {}
	Edge() {}
	bool operator < (const Edge& rhs) const {
		return w < rhs.w;
	}
};
vector<Edge> es;
int par[N], rnk[N];

int pnt[N << 1], nxt[N << 1], head[N], w[N << 1];
int cnt;
void add_edge(int u, int v, int c) {
	pnt[cnt] = v; nxt[cnt] = head[u]; w[cnt] = c; head[u] = cnt++;
}

void init() {
	for (int i = 1; i <= n; i++) par[i] = i, rnk[i] = 0;
}

int find(int x) {
	if (par[x] == x) return par[x];
	else return par[x] = find(par[x]);
}

bool same(int x, int y) {
	return find(x) == find(y);
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) par[x] = y;
	else {
		par[y] = x;
		if (rnk[x] == rnk[y]) rnk[x]++;
	}
}

void kruskal() {
	init();
	sort(es.begin(), es.end());
	for (int i = 0; i < es.size(); i++) {
		Edge& e = es[i];
		if (!same(e.u, e.v)) {
			unite(e.u, e.v);
			add_edge(e.u, e.v, e.w);
			add_edge(e.v, e.u, e.w);
		}
	}
}

int ans[20][N], p[20][N];
int dep[N];
void dfs(int fa, int u, int d, int c) {
	p[0][u] = fa;
	ans[0][u] = c;
	dep[u] = d;
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = pnt[i];
		if (v == fa) continue;
		dfs(u, v, d + 1, w[i]);
	}
}

void process() {
	OFF(p); OFF(dep); OFF(ans);
	dfs(-1, 1, 0, 0);
	for (int i = 0; i + 1 < 20; i++) {
		for (int v = 1; v <= n; v++) {
			if (p[i][v] == -1) p[i + 1][v] = -1;
			else p[i + 1][v] = p[i][p[i][v]];
			ans[i + 1][v] = max(ans[i][v], ans[i][p[i][v]]);
		}
	}
}

int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = 0; i < 20; i++) {
		if (dep[v] - dep[u] >> i & 1) v = p[i][v];
	}
	if (v == u) return u;
	for (int i = 19; i >= 0; i--) {
		if (p[i][u] != p[i][v]){
			v = p[i][v];
			u = p[i][u];
		}
	}
	return p[0][u];
}

int query(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	int ret = -1;
	for (int i = 19; i >= 0; i--) {
		if (dep[v] - dep[u] >> i & 1) {
			ret = max(ret, ans[i][v]);
			v = p[i][v];
		}
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int kase = 0;
    while(SII(n, m) == 2) {
    	if (kase) cout << endl; kase++;
    	es.clear();
    	for (int i = 1; i <= m; i++) {
    		int u, v, w;
    		SIII(u, v, w);
    		es.push_back(Edge(u, v, w));
    	}
    	OFF(head); cnt = 0;
    	kruskal();
    	process();
    	int q; SI(q);
    	while(q--) {
    	   int u, v;
    	   SII(u, v);
    	   int LCA = lca(u, v);
    	   cout << max(query(u, LCA), query(v, LCA)) << endl;
    	}
    }
	return 0;
}