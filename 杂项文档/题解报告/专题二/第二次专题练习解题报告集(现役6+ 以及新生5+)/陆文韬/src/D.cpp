//
//  Created by TaoSama on 2016-05-17
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
const int N = 2e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int OFF = 3000;

int n, a[N], b[N];
int f[2][OFF * 2 + 5]; //前i个任务 且A比B多用时j 的最小时间花费

void getMin(int& x, int y) {
    if(x > y) x = y;
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
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d%d", a + i, b + i);
        int z = 0;
        memset(f[z], 0x3f, sizeof f[z]);
        f[z][OFF] = 0;
        for(int i = 1; i <= n; ++i) {
            memset(f[!z], 0x3f, sizeof f[!z]);
            for(int j = -OFF; j <= OFF; ++j) {
                if(j > 0) {
                    getMin(f[!z][a[i] + OFF], f[z][j + OFF] + a[i]); //给A B只能等
                    getMin(f[!z][j + OFF - b[i]], f[z][j + OFF] + max(0, b[i] - j));
                } else {
                    getMin(f[!z][-b[i] + OFF], f[z][j + OFF] + b[i]); //给B A只能等
                    getMin(f[!z][j + OFF + a[i]], f[z][j + OFF] + max(0, a[i] + j));
                }
            }
            z = !z;
        }
        int ans = *min_element(f[z], f[z] + 2 * OFF + 1);
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
