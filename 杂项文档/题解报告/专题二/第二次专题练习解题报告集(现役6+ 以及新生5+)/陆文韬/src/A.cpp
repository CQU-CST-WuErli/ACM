//
//  Created by TaoSama on 2016-05-14
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
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL n;
int m;

//remember to call "init" first
struct Matrix {
    int row, col;
    static const int N = 3;
    LL mat[N][N];
    void init(int r, int c, bool one = false) {
        row = r; col = c;
        memset(mat, 0, sizeof mat);
        if(!one) return;
        for(int i = 0; i < row; ++i) mat[i][i] = 1;
    }
    Matrix operator* (const Matrix& rhs) {
        Matrix ret; ret.init(row, rhs.col);
        for(int k = 0; k < col; ++k) {
            for(int i = 0; i < row; ++i) {
                if(mat[i][k] == 0) continue;
                for(int j = 0; j < rhs.col; ++j) {
                    if(rhs.mat[k][j] == 0) continue;
                    ret.mat[i][j] += mat[i][k] * rhs.mat[k][j] % MOD;
                    ret.mat[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
    Matrix operator^ (LL n) {
        Matrix ret, x = *this;
        ret.init(row, col, 1);
        for(; n; n >>= 1) {
            if(n & 1) ret = ret * x;
            x = x * x;
        }
        return ret;
    }
};


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%lld%d", &n, &m);
        vector<LL> v(1, 0);
        bool never = false;
        for(int i = 1; i <= m; ++i) {
            LL x; scanf("%lld", &x);
            if(x == 0 || x == n) never = true;
            else if(x < 0 || x > n) continue;
            else v.push_back(x);
        }
        v.push_back(n);

        if(never) {puts("0"); continue;}

        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());

        Matrix A; A.init(3, 3);
        /* 0 0 1
           1 0 1
        0 1 1  */
        A.mat[0][2] = 1;
        A.mat[1][0] = 1;
        A.mat[1][2] = 1;
        A.mat[2][1] = 1;
        A.mat[2][2] = 1;

        Matrix ans; ans.init(1, 3);
        ans.mat[0][2] = 1; /* 0 0 1 */

        for(int i = 1; i < v.size(); ++i) {
            ans = ans * (A ^ (v[i] - v[i - 1]));
            if(i < v.size() - 1) ans.mat[0][2] = 0; //mine
        }
        printf("%lld\n", ans.mat[0][2]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
