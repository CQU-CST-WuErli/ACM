//
//  Created by TaoSama on 2016-05-28
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 2e5 + 10;

int n, m;
struct Edge {
    int v, c;
};
vector<Edge> G[N];
int f[N], in[N];

void spfa(int src, int des) {
    queue<int> q; q.push(src);
    memset(f, 0x3f, sizeof f);
    memset(in, 0, sizeof in);
    f[src] = 0; in[src] = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = 0; i < G[u].size(); ++i) {
            Edge& e = G[u][i];
            int v = e.v, c = e.c;
            if(f[v] > f[u] + c) {
                f[v] = f[u] + c;
                if(!in[v]) q.push(v), in[v] = true;
            }
        }
    }
}

struct Dinic {
    struct Edge {
        int v, nxt, cap;
    } edge[M];
    int head[N], cnt;

    void init() {
        cnt = 0; memset(head, -1, sizeof head);
    }

    void addEdge(int u, int v, int c1, int c2 = 0) {
        edge[cnt] = {v, head[u], c1};
        head[u] = cnt++;
        edge[cnt] = {u, head[v], c2};
        head[v] = cnt++;
    }

    int lev[N], cur[N];
    bool bfs(int s, int t) {
        queue<int> q;
        memset(lev, 0, sizeof lev);
        q.push(s);  lev[s] = 1;
        while(q.size() && !lev[t]) {
            int u = q.front(); q.pop();
            for(int i = head[u]; ~i; i = edge[i].nxt) {
                int v = edge[i].v;
                if(edge[i].cap > 0 && !lev[v]) {
                    lev[v] = lev[u] + 1;
                    q.push(v);
                }
            }
        }
        return lev[t];
    }

    int dfs(int u, int t, int delta) {
        if(u == t || !delta) return delta;
        int ret = 0;
        for(int i = cur[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if(edge[i].cap > 0 && lev[v] == lev[u] + 1) {
                int d = dfs(v, t, min(delta, edge[i].cap));
                cur[u] = i;
                ret += d; delta -= d;
                edge[i].cap -= d;
                edge[i ^ 1].cap += d;

                if(delta == 0) return ret;
            }
        }
        lev[u] = 0;
        return ret;
    }

    int dinic(int s, int t) {
        int ret = 0;
        while(bfs(s, t)) {
            for(int i = s; i <= t; ++i) cur[i] = head[i];
            ret += dfs(s, t, INF);
        }
        return ret;
    }
} solver;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G[u].push_back((Edge) {v, c});
        }

        int x, y; scanf("%d%d", &x, &y);
        spfa(x, y);
        if(f[y] == INF) {puts("0"); continue;}

        solver.init();
        int src = 0, des = n + 1;
        solver.addEdge(src, x, INF);
        solver.addEdge(y, des, INF);

        for(int u = 1; u <= n; ++u) {
            for(int i = 0; i < G[u].size(); ++i) {
                Edge& e = G[u][i];
                int v = e.v, c = e.c;
                if(f[v] == f[u] + c) solver.addEdge(u, v, 1);
            }
        }

        printf("%d\n", solver.dinic(src, des));
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
