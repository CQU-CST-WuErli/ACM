//
//  Created by TaoSama on 2016-05-13
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, w, q[N];
typedef long long LL;
LL x[N], f[N];
//f[i] = min { f[j] + w + (x[i] - x[j+1])^ 2 }
//slope(k, j) = {(f[j] + x[j+1]^2)-()} / {2(x[j+1]-x[k+1])} < x[i]

LL up(int k, int j) {
    return (f[j] + x[j + 1] * x[j + 1]) - (f[k] + x[k + 1] * x[k + 1]);
}

LL dw(int k, int j) {
    return 2 * (x[j + 1] - x[k + 1]);
}

bool check(int k, int j, int i) {
    return up(k, j) * dw(j, i) >= up(j, i) * dw(k, j);
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
        scanf("%d%d", &n, &w);
        for(int i = 1; i <= n; ++i) scanf("%lld", x + i);

        int L = 0, R = 0;
        q[R++] = 0;
        for(int i = 1; i <= n; ++i) {
            while(L + 1 < R && up(q[L], q[L + 1]) <= x[i] * dw(q[L], q[L + 1])) ++L;
            int j = q[L];
            f[i] = f[j] + w + (x[i] - x[j + 1]) * (x[i] - x[j + 1]);
//          printf("f[%d] = %lld f[%d] = %lld\n", j, f[j], i, f[i]);
            while(L + 1 < R && check(q[R - 2], q[R - 1], i)) --R;
            q[R++] = i;
        }
        printf("%lld\n", f[n]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
