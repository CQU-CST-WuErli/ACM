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
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int g[N][N];
vector<int> G[N];
int col[N]; // a=-1,b=0,c=1

bool dfs(int u, int c) {
    col[u] = c;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(col[v] == c) return false;
        if(!col[v] && !dfs(v, -c)) return false;
    }
    return true;
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
        scanf("%d%d", &n, &m);
        memset(g, 0, sizeof g);
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            g[u][v] = g[v][u] = true;
        }

        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            for(int j = 1; j <= n; ++j)
                if(i != j && !g[i][j]) G[i].push_back(j);
        }

        bool ok = true;
        memset(col, 0, sizeof col);
        for(int i = 1; i <= n; ++i) {
            if(!col[i] && G[i].size() && !dfs(i, 1)) {
                ok = false;
                break;
            }
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i == j) continue;
                if(g[i][j] && col[i] * col[j] < 0) ok = false;
                if(!g[i][j] && col[i] * col[j] >= 0) ok = false;
            }
        }
        puts(ok ? "Yes" : "No");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
