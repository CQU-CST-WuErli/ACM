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

int n, V, q[N];
int w[105], c[105];
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
        for(int i = 1; i <= n; ++i) scanf("%d", w + i);
        for(int i = 1; i <= n; ++i) scanf("%d", c + i);

        int p = 0;
        memset(f[p], 0, sizeof f[p]);
        f[p][0] = 1;
        for(int i = 1; i <= n; ++i) {
            memset(f[!p], 0, sizeof f[!p]);
            for(int mod = 0; mod < w[i]; ++mod) {
                int L = 0, R = 0;
                for(int j = 0; mod + j * w[i] <= V; ++j) {
                    while(L < R && !f[p][q[R - 1] * w[i] + mod]) --R;
                    q[R++] = j;
                    while(L < R && j - q[L] > c[i]) ++L;
                    int k = q[L];
                    f[!p][j * w[i] + mod] |= f[p][k * w[i] + mod];
                }
            }
            p = !p;
        }
        puts(f[p][V] ? "yes" : "no");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
