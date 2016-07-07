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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int s[N], c[N], t[2][N];
int sa[N], rk[N], height[N];
void build(int n, int m) {
    int i, k, *x = t[0], *y = t[1];
    for(i = 0; i < m; i++) c[i] = 0;
    for(i = 0; i < n; i++) c[x[i] = s[i]]++;
    for(i = 1; i < m; i++) c[i] += c[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for(k = 1; k <= n; k <<= 1) {
        int p = 0;
        for(i = n - k; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i] - k;
        for(i = 0; i < m; i++) c[i] = 0;
        for(i = 0; i < n; i++) c[x[y[i]]]++;
        for(i = 1; i < m; i++) c[i] += c[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1; x[sa[0]] = 0;
        for(i = 1; i < n; i++)
            x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] &&
                        y[sa[i - 1] + k] == y[sa[i] + k]) ? p - 1 : p++;
        if(p >= n) break;
        m = p;
    }
    for(i = 0; i < n; i++) rk[sa[i]] = i;
    for(i = 0, k = 0; i < n; i++) {
        if(k) k--;
        int j = sa[rk[i] - 1];
        while(s[i + k] == s[j + k]) k++;
        height[rk[i]] = k;
    }
}

char str[N];
int l[N], r[N];
int stk[N], top;

void see(int n){
    for(int i = 0; i < n; ++i) printf("%d: %s\n", i, str + sa[i]);
    printf("sa: "); for(int i = 0; i < n; ++i) printf("%d ", sa[i]); puts("");
    printf("rk: "); for(int i = 0; i < n; ++i) printf("%d ", rk[i]); puts("");
    printf("ht: "); for(int i = 0; i < n; ++i) printf("%d ", height[i]); puts("");
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

	pair<int, int> p = {1, 2};
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", str);
        int n = strlen(str);
        for(int i = 0; i < n; ++i) s[i] = str[i] - 'a' + 1;
        s[n] = 0;

        build(n + 1, 27);
//      see(n + 1);
        /*
        0:
        1: acao
        2: ao
        3: cacao
        4: cao
        5: o
        sa: 5 1 3 0 2 4
        rk: 3 1 4 2 5 0
        ht: 0 0 1 0 2 0
        */
        long long ans = 0;
        for(int i = 2; i <= n; ++i)
            ans += 1LL * i * (i - 1) + 1LL * i * (i - 1) / 2;
//      prln(ans);

        top = 0;
        for(int i = 2; i <= n; ++i) {
            while(top && height[stk[top]] >= height[i]) --top;
            l[i] = top ? stk[top] : 1;
            stk[++top] = i;
        }
        top = 0;
        for(int i = n; i >= 2; --i) {
            while(top && height[stk[top]] > height[i]) --top;
            r[i] = top ? stk[top] : n + 1;
            stk[++top] = i;
        }

        for(int i = 2; i <= n; ++i) {
            if(!height[i]) continue;
            long long e = 1LL * (i - l[i]) * (r[i] - i);
            ans -= 2 * e * height[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
