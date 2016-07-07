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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;

struct DSU {
    int n, p[N];
    void init(int _n) {
        n = _n;
        for(int i = 1; i <= n; ++i) p[i] = i;
    }
    int find(int x) {
        return p[x] = p[x] == x ? x : find(p[x]);
    }
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        p[x] = y;
    }
    bool isConnected() {
        int cnt = 0;
        for(int i = 1; i <= n; ++i) if(p[i] == i) ++cnt;
        return cnt == 1;
    }
} dsu;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);

        dsu.init(n);
        vector<int> in(n + 1, 0), out(n + 1, 0), deg(n + 1, 0);
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            dsu.unite(u, v);
            ++out[u]; ++in[v];
            ++deg[u]; ++deg[v];
        }

        if(n == 1 && m == 0) {puts("Yes Yes"); continue; }
        if(!dsu.isConnected()) {puts("No No"); continue; }

        //无向图 0或2个奇度点
        int oddDeg = 0, mark = 0;
        for(int i = 1; i <= n; ++i) {
            if(deg[i] & 1) ++oddDeg;
            if(in[i] == out[i]) continue;
            else if(~mark && abs(in[i] - out[i]) == 1) ++mark;
            else mark = -1;
        }
        bool undirectedEuler = oddDeg <= 2; //奇度点只有偶数个
        //有向图 入度之和 = 出度之和
        bool directedEuler = mark == 0 || mark == 2;
        printf("%s %s\n", undirectedEuler ? "Yes" : "No",
               directedEuler ? "Yes" : "No");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
