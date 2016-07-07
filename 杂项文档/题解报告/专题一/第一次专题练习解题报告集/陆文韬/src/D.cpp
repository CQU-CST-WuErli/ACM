//
//  Created by TaoSama on 2016-05-02
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

struct Squre {
    int u, r, d, l;
    void read() {
        scanf("%d%d%d%d", &u, &r, &d, &l);
    }
    void see() {
        printf("(%d, %d, %d, %d)\n", u, r, d, l);
    }
    bool operator==(const Squre& sq) const {
        return u == sq.u && r == sq.r && d == sq.d && l == sq.l;
    }
} sq[30];

int n, m, cnt[30];
int path[10][10];

bool dfs(int x, int y) {
    if(y == n + 1) ++x, y = 1;
    if(x == n + 1) return true;
    for(int i = 1; i <= m; ++i) {
        if(!cnt[i]) continue;

        bool ok = true;
        if(y > 1 && sq[i].l != sq[path[x][y - 1]].r) ok = false;
        if(x > 1 && sq[i].u != sq[path[x - 1][y]].d) ok = false;
        if(!ok) continue;

        --cnt[i];
        path[x][y] = i;
        if(dfs(x, y + 1)) return true;
        ++cnt[i];
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        m = 0;
        for(int i = 1; i <= n * n; ++i) {
            sq[i].read();
            bool same = false;
            for(int j = 1; j <= m; ++j) {
                if(sq[i] == sq[j]) {
                    same = true;
                    ++cnt[j];
                    break;
                }
            }
            if(!same) {
                sq[++m] = sq[i];
                cnt[m] = 1;
            }
        }
//      for(int i = 1; i <= m; ++i) sq[i].see();
        puts(dfs(1, 1) ? "Possible" : "Impossible");
    }
    return 0;
}
