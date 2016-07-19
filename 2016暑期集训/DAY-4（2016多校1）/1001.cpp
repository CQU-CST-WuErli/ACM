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
#include <bitset>
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

const int N = 1000100;

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

void add_edge(int u, int v, int ww) {
    pnt[cnt] = v; nxt[cnt] = head[u]; w[cnt] = ww;
    head[u] = cnt++;
}

int find(int x) {
    if (x == par[x]) return par[x];
    else return par[x] = find(par[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    par[x] = y;
}

ll MST() {
    for (int i = 1; i <= n; i++) {
        par[i] = i, rnk[i] = 0;
    }
    OFF(head); cnt = 0;
    sort(es.begin(), es.end());
    ll ret = 0;
    for (int i = 0; i < es.size(); i++) {
        Edge& e = es[i];
        if (!same(e.u, e.v)) {
            ret += e.w;
            unite(e.u, e.v);
            add_edge(e.u, e.v, e.w);
            add_edge(e.v, e.u, e.w);
        }
    }
    return ret;
}

double sum;
int sz[100010];

void dfs(int fa, int u) {
    sz[u] = 1;
    for (int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if (v == fa) continue;
        dfs(u, v);
        sz[u] += sz[v];
        sum += (double)sz[v] * (n - sz[v]) * w[i];
    }
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
        es.clear();
        SII(n, m);
        for (int i = 1; i <= m; i++) {
            int u, v, cost;
            SIII(u, v, cost);
            es.push_back(Edge(u, v, cost));
        }
        ll ans = MST();
        sum = 0;
        CLR(sz);
        dfs(-1, 1);
        sum = sum * 2.0 / ((double)n * (n - 1));
        printf("%lld %.2f\n", ans, sum);
    }
    return 0;
}