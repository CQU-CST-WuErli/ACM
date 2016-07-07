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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
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
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        int p = 0;
        memset(f[p], 0xc0, sizeof f[p]);
        f[p][0] = 0;
        for(int i = 1; i <= n; ++i) {
            memset(f[!p], 0xc0, sizeof f[!p]);
            for(int j = 0; j <= 500000; ++j) {
                f[!p][j] = max(f[!p][j], f[p][j]);
                if(j + a[i] <= 500000)
                    f[!p][j + a[i]] = max(f[!p][j + a[i]], f[p][j] + a[i]);
                if(j - a[i] >= 0)
                    f[!p][j - a[i]] = max(f[!p][j - a[i]], f[p][j] + a[i]);
                else f[!p][a[i] - j] = max(f[!p][a[i] - j], f[p][j] + a[i]);
            }
            p = !p;
        }
        if(f[p][0] <= 0) puts("GG");
        else printf("%d\n", f[p][0] / 2);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
