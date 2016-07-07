//
//  Created by TaoSama on 2016-05-01
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

int n, m;
struct Trie {
    static const int M = 5e6 + 10, S = 2;
    int nxt[M][S];
    int root, sz;
    int newNode() {
        memset(nxt[sz], 0, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = 0; newNode();
        root = newNode();
    }
    void insert(int x) {
        int u = root;
        for(int i = 31; ~i; --i) {
            int c = x >> i & 1, &v = nxt[u][c];
            if(!v) v = newNode();
            u = v;
        }
    }
    int query(int x) {
        int ret = 0, u = root;
        for(int i = 31; ~i; --i) {
            int c = x >> i & 1;
            if(nxt[u][c ^ 1]) {
                ret |= 1 << i;
                u = nxt[u][c ^ 1];
            } else u = nxt[u][c];
            if(!u) break;
        }
        return ret;
    }
} trie;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        trie.init();
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            trie.insert(x);
        }

        int ans = 0;
        for(int i = 1; i <= m; ++i) {
            int x; scanf("%d", &x);
            ans = max(ans, trie.query(x));
        }
        printf("%d\n", ans);
    }
    return 0;
}
