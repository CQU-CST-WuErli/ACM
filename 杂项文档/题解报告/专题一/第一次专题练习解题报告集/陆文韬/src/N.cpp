//
//  Created by TaoSama on 2016-05-04
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
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 10007;

int n, m;
struct AcAutomata {
    static const int M = 60 * 100 + 10, S = 26;
    int root, sz;
    int nxt[M][S], fail[M], cnt[M];
    int f[N][M];
    int newNode() {
        cnt[sz] = 0;
        memset(nxt[sz], -1, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = 0;
        root = newNode();
    }
    void insert(char* s) {
        int n = strlen(s);
        int u = root;
        for(int i = 0; i < n; ++i) {
            int& v = nxt[u][s[i] - 'A'];
            if(v == -1) v = newNode();
            u = v;
        }
        cnt[u] = true;
    }
    void build() {
        queue<int> q;
        fail[root] = root;
        for(int i = 0; i < S; ++i) {
            int& v = nxt[root][i];
            if(~v) {
                fail[v] = root;
                q.push(v);
            } else v = root;
        }
        while(q.size()) {
            int u = q.front(); q.pop();
            for(int i = 0; i < S; ++i) {
                int& v = nxt[u][i];
                if(~v) {
                    fail[v] = nxt[fail[u]][i];
                    cnt[v] |= cnt[fail[v]]; //unite
                    q.push(v);
                } else v = nxt[fail[u]][i];
            }
        }
    }
    int dp() {
        memset(f, 0, sizeof f);
        f[0][root] = 1;
        for(int i = 0; i < m; ++i) {
            for(int u = 0; u < sz; ++u) {
                if(!f[i][u]) continue;
                for(int j = 0; j < S; ++j) {
                    int v = nxt[u][j];
                    if(cnt[v]) continue;
                    if((f[i + 1][nxt[u][j]] += f[i][u]) >= MOD)
                        f[i + 1][nxt[u][j]] -= MOD;
                }
            }
        }
        int ret = 0;
        for(int u = 0; u < sz; ++u) if((ret += f[m][u]) >= MOD) ret -= MOD;
        return ret;
    }
    void debug() {
        for(int i = 0; i < sz; ++i) {
            printf("id = %3d, fail = %3d, cnt = %3d, chi = [",
                   i, fail[i], cnt[i]);
            for(int j = 0; j < S; j++)
                printf("%2d", nxt[i][j]);
            printf("]\n");
        }
    }
} ac;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        ac.init();
        for(int i = 1; i <= n; ++i) {
            char buf[110]; scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();

        int ans = 1;
        for(int i = 1; i <= m; ++i) ans = ans * 26 % MOD;
        ans = (ans - ac.dp() + MOD) % MOD;
        printf("%d\n", ans);
    }
    return 0;
}
