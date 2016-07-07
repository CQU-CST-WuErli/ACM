//
//  Created by Running Photon on 2016-03-21
//  Copyright (c) 2015 Running Photon. All rights reserved.
//
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
#include <sstream>
#include <set>
#include <vector>
#include <stack>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x,begin())
#define ll long long
#define CLR(x) memset(x, 0, sizeof x)
using namespace std;
const int MOD = 941266248;
const ll inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxv = 3;
const double eps = 1e-9;

ll mod;
struct Matrix {
    ll mat[maxv][maxv];
    Matrix() {CLR(mat);}
    void clear() {
        CLR(mat);
    }
    void print(int maxx) {
        for(int i = 0; i < maxx; i++) {
            for(int j = 0; j < maxx; j++) {
                printf("%lld ", mat[i][j]);
            }
            puts("");
        }
        puts("");
    }
    Matrix operator* (Matrix& rhs) {
        Matrix ret;
        ret.clear();
        for(int i = 0; i < maxv; i++) {
            for(int j = 0; j < maxv; j++) {
                for(int k = 0; k < maxv; k++) {
                    ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * rhs.mat[k][j] % mod + mod) % mod;
                }
            }
        }
        return ret;
    }
    Matrix operator^ (ll n) {
        Matrix ret;
        Matrix a = *this;
        ret.clear();
        for(int i = 0; i < maxv; i++) {
            ret.mat[i][i] = 1;
        }
        while(n) {
            if(n & 1) ret = ret * a;
            a = a * a;
            n >>= 1;
        }
        return ret;
    }
};

// d[i] = 3 * d[i-1] - d[i-2] - 2 check oka
ll getT(ll m) {
    if(m == 0) return 1;
    if(m == 1) return 3;
    if(m == 2) return 7;
    Matrix res;
    res.mat[0][0] = 3;
    res.mat[0][1] = 1;
    res.mat[1][0] = -1;
    res.mat[2][0] = 2;
    res.mat[2][2] = 1;
    mod = 84472584;
    res = res ^ (m - 2);
    ll ans = (5LL * res.mat[0][0] + res.mat[1][0] + res.mat[2][0] + mod) % mod;
    return ans + 2;
}
ll solve(ll n) {
    if(n <= 1) return 1;
    if(n == 2) return 2;
    Matrix res;
    res.mat[0][0] = 1;
    res.mat[0][1] = 1;
    res.mat[1][0] = 1;
    res.mat[1][1] = 0;
    mod = MOD;
    res = res ^ (n - 2);
    ll ans = (res.mat[0][0] + res.mat[1][0] + mod) % mod;
    return ans;
}
int main() {
#ifdef LOCAL
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);
    ll k = 1;
    ll a = 0, b = 1, c;
    for(k = 2;;k++) {
        c = (a + b) % MOD;
        a = b;
        b = c;
        if(a == 0 && b == 1) {
            printf("%d\n", k);
            break;
        }
    }
//    ll n;
//    while(scanf("%lld", &n) != EOF) {
//        printf("%lld\n", solve(getT(n)));
//    }
	return 0;
}
