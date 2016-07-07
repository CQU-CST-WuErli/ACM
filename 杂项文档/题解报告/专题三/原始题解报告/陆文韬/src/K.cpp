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
const int N = 5e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
vector<int> G[N], T[N], B[N];

int scc, dfsNum;
int dfn[N], low[N], in[N], id[N];
int stk[N], top;

void tarjan(int u) {
    dfn[u] = low[u] = ++dfsNum;
    stk[++top] = u;
    in[u] = true;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        B[++scc].clear();
        while(true) {
            int v = stk[top--];
            in[v] = false;
            id[v] = scc;
            B[scc].push_back(v);
            if(v == u) break;
        }
    }
}

int vis[N];
int dfs(int u, int mark) {
    vis[u] = mark;
    int ret = B[u].size();
    for(int i = 0; i < T[u].size(); ++i) {
        int v = T[u][i];
        if(vis[v] == mark) continue;
        ret += dfs(v, mark);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\input.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) G[i].clear(), T[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            ++u, ++v;
            G[u].push_back(v);
        }

        scc = dfsNum = 0;
        memset(dfn, 0, sizeof dfn);
        for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);

        vector<int> in(scc + 1, 0);
        for(int i = 1; i <= n; ++i) {
            int u = id[i];
            for(int j = 0; j < G[i].size(); ++j) {
                int v = id[G[i][j]];
                if(u == v) continue;
                T[v].push_back(u); //存逆图
                ++in[u];
            }
        }

        memset(vis, 0, sizeof vis);
        vector<int> sz(n + 1, -INF);
        for(int i = 1; i <= scc; ++i) {
            if(in[i]) continue;
            int ret = dfs(i, i) - 1;
            for(int j = 0; j < B[i].size(); ++j) sz[B[i][j]] = ret;
        }

        int ans = *max_element(sz.begin(), sz.end());
        vector<int> v;
        for(int i = 1; i <= n; ++i)
            if(sz[i] == ans) v.push_back(i - 1);

        static int kase = 0;
        printf("Case %d: %d\n", ++kase, ans);
        for(int i = 0; i < v.size(); ++i)
            printf("%d%c", v[i], " \n"[i == v.size() - 1]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
