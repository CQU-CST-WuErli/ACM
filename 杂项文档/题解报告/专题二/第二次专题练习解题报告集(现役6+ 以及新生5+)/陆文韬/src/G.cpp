//
//  Created by TaoSama on 2016-05-25
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
const int N = 24 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int use[N], vis[N];

bool dfs(int u, int s) {
    if(u == n) return use[n - 1] == n - 1;
    if(use[u] == a[u] - 1) return dfs(u + 1, u);
    for(int v = s; ~v; --v) { //connect sons
        if(vis[v] || !use[u] && a[u] - a[v] == 1) continue; //omit single edge
        if(use[u] >= a[u]) break;
        use[u] += a[v]; vis[v] = true;
        if(dfs(u, v - 1)) return true;
        use[u] -= a[v]; vis[v] = false;
    }
    return false;
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
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        sort(a, a + n);
        memset(vis, 0, sizeof vis);
        memset(use, 0, sizeof use);
        puts(dfs(0, -1) ? "YES" : "NO");
//        for(int i = 0; i < n; ++i){
//          printf("%d: %d\n", i, a[i]);
//          for(int j = 0; j < n; ++j)
//              if(use[i] >> j & 1) printf("%d ", j);
//          if(use[i]) puts("");
//        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
