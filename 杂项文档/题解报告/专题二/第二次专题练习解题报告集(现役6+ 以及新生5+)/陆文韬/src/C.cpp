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
const int N = 350 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int c[5], v[N];
int f[41][41][41][41];

void getMax(int& x, int y) {
    if(x < y) x = y;
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
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) scanf("%d", v + i);
        memset(c, 0, sizeof c);
        for(int i = 1; i <= m; ++i) {
            int x; scanf("%d", &x);
            ++c[x];
        }
        memset(f, 0, sizeof f);
        f[0][0][0][0] = v[1];
        for(int i = 0; i <= c[1]; ++i) {
            for(int j = 0; j <= c[2]; ++j) {
                for(int k = 0; k <= c[3]; ++k) {
                    for(int l = 0; l <= c[4]; ++l) {
                        if(i + j + k + l == 0) continue;
                        if(i) getMax(f[i][j][k][l], f[i - 1][j][k][l]);
                        if(j) getMax(f[i][j][k][l], f[i][j - 1][k][l]);
                        if(k) getMax(f[i][j][k][l], f[i][j][k - 1][l]);
                        if(l) getMax(f[i][j][k][l], f[i][j][k][l - 1]);
                        int x = 1 + i + 2 * j + 3 * k + 4 * l;
                        f[i][j][k][l] += v[x];
                    }
                }
            }
        }
        printf("%d\n", f[c[1]][c[2]][c[3]][c[4]]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}

