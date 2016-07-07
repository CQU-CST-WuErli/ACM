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

struct Manacher {
    char s[N << 1];
    int n, p[N << 1];

    void init(char* a) {
        s[0] = '@'; s[1] = '#'; n = 2;
        for(int i = 1; a[i]; ++i)
            s[n++] = a[i], s[n++] = '#';
        s[n] = 0;
    }

    int gao() {
        int mx = 0, id, ret = 0;
        for(int i = 1; i < n; ++i) {
            p[i] = mx > i ? min(mx - i, p[2 * id - i]) : 1;
            while(s[i - p[i]] == s[i + p[i]]) ++p[i];
            if(mx < i + p[i]) mx = i + p[i], id = i;
            ret = max(ret, p[i] - 1);
        }
        return ret;
    }

    bool ok(int l, int r) {
        l <<= 1; r <<= 1;
        int k = l + r >> 1;
        return k + p[k] - 1 >= r;
    }
} ma;

struct Trie {
    static const int M = 1e5 * 16 + 10, S = 2;
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
        for(int i = 16; ~i; --i) {
            int c = x >> i & 1, &v = nxt[u][c];
            if(!v) v = newNode();
            u = v;
        }
    }
    int query(int x) {
        int ret = 0, u = root;
        for(int i = 16; ~i; --i) {
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

int n;
char s[N];

typedef long long LL;

LL ksm(LL x, LL n, LL m) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % m;
        x = x * x % m;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s + 1);
        n = strlen(s + 1);

        ma.init(s);
        int mz = ma.gao();
        int jd = ksm(mz, 1LL * n * n * n, mz / 3 * 5 + 1) + mz * 4 / 5;

        int sum = 0, fjd = 0;
        trie.init(); trie.insert(0);
        for(int i = 1; i <= n; ++i) {
            sum ^= ma.p[i << 1] - 1;
            fjd = max(fjd, trie.query(sum));
            trie.insert(sum);
        }

        puts(jd > fjd ? "liujc" : "luoxinchen");
    }
    return 0;
}
