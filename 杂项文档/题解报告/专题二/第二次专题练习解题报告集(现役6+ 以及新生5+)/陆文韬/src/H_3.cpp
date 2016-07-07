//
//  Created by TaoSama on 2016-05-18
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

int n, V, Q[N];
int w[105], c[105], v[105];
int f[2][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &V);
        for(int i = 1; i <= n; ++i) scanf("%d", w + i), v[i] = w[i];
        for(int i = 1; i <= n; ++i) scanf("%d", c + i);

        int z = 0;
        memset(f[z], 0, sizeof f[z]);
        f[z][0] = 0;
        for(int i = 1; i <= n; ++i) {
            memset(f[!z], 0, sizeof f[!z]);
            for(int r = 0; r < w[i]; ++r) {
                int L = 0, R = 0;
                for(int p = 0; p * w[i] + r <= V; ++p) {
                    while(L < R && f[z][Q[R - 1] * w[i] + r] - Q[R - 1] * v[i]
                            <= f[z][p * w[i] + r] - p * v[i]) --R;
                    Q[R++] = p;
                    while(L < R && p - Q[L] > c[i]) ++L;
                    int q = Q[L];
                    f[!z][p * w[i] + r] = (f[z][q * w[i] + r] - q * v[i]) + p * v[i];
                }
            }
            z = !z;
        }
        puts(f[z][V] == V ? "yes" : "no");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
