//
//  Created by TaoSama on 2016-05-16
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
const int N = 300 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1.5e5 + 10;

int n, m, d;
int a[N], b[N], t[N];
typedef long long LL;
LL f[2][M];

struct SparseTable {
    LL dp[20][M];
    void init(LL* a) {
        for(int i = 1; i <= n; ++i) dp[0][i] = a[i];
        for(int i = 1; (1 << i) <= n; ++i)
            for(int j = 1; j + (1 << i) - 1 <= n; ++j)
                dp[i][j] = max(dp[i - 1][j],
                               dp[i - 1][j + (1 << i - 1)]);
    }
    LL RMQ(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return max(dp[k][l], dp[k][r - (1 << k) + 1]);
    }
} st;


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &d);
        for(int i = 1; i <= m; ++i) scanf("%d%d%d", a + i, b + i, t + i);
        int p = 0;
        for(int i = 1; i <= n; ++i) f[p][i] = b[1] - abs(a[1] - i);
        for(int i = 2; i <= m; ++i) {
            st.init(f[p]);
            LL c = t[i] - t[i - 1];
            for(int j = 1; j <= n; ++j) {
                int l = max(1LL, j - c * d), r = min(1LL * n, j + c * d);
                int v = b[i] - abs(a[i] - j);
                f[!p][j] = st.RMQ(l, r) + v;
            }
            p = !p;
        }
        LL ans = -1e18;
        for(int i = 1; i <= n; ++i) ans = max(ans, f[p][i]);
        printf("%lld\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}

