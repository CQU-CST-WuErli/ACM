//
//  Created by TaoSama on 2016-05-27
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
struct Edge {
    int v, c, d;
};
vector<Edge> G[N];

int f[N], in[N];
bool spfa(int limit) {
    queue<int> q; q.push(1);
    memset(f, 0x3f, sizeof f);
    memset(in, 0, sizeof in);
    f[1] = 0; in[1] = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = 0; i < G[u].size(); ++i) {
            Edge& e = G[u][i];
            int v = e.v, c = e.c, d = e.d;
            if(c < limit) continue;
            if(f[v] > f[u] + d) {
                f[v] = f[u] + d;
                if(f[v] > k) f[v] = INF;
                if(!in[v]) q.push(v), in[v] = true;
            }
        }
    }
//    pr(limit); prln(f[n]);
    return f[n] <= k;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; ++i) G[i].clear();

        vector<int> val;
        for(int i = 1; i <= m; ++i) {
            int u, v, c, d;
            scanf("%d%d%d%d", &u, &v, &c, &d);
            val.push_back(c);
            G[u].push_back((Edge) {v, c, d});
            G[v].push_back((Edge) {u, c, d});
        }

        sort(val.begin(), val.end());
        int l = 0, r = val.size(), res = -1;
        while(l < r) {
            int m = l + r >> 1;
            int limit = val[m];
            if(spfa(limit)) res = m, l = m + 1;
            else r = m;
        }
        if(~res) printf("%d\n", val[res]);
        else puts("Poor RunningPhoton!");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
