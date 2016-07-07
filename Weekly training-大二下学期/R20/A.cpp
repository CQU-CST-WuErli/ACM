//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

ll a,b,n,m;
ll mod;

struct Matrix {
    ll mat[3][3];
    Matrix() {
        CLR(mat);
    }
    Matrix operator* (Matrix rhs) {
        Matrix ret;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    ret.mat[i][j] = ( ret.mat[i][j] + mat[i][k] * rhs.mat[k][j] % mod + mod) % mod;
                }
            }
        }
        return ret;
    }
    Matrix operator^ (ll n) {
        Matrix res;
        Matrix a = (*this);
        for(int i = 0; i < 2; i++) res.mat[i][i] = 1;
        while(n) {
            if(n & 1) res = res * a;
            n >>= 1;
            a = a * a;
        }
        return res;
    }
    void print() {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                printf("%d ", mat[i][j]);
            }
            puts("");
        }
    }
};

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(cin >> a >> b >> n >> m) {
		if (n == 1) {
			cout << 2 * a % m << endl;
			continue;
		}
		mod = m;
		ll r1 = a + (ll)sqrt(b) + 1;
		ll r2 = (ll)powl((long double)a + sqrtl((long double)b), (long double)2.0) + 1;
		r1 %= m;
		r2 %= m;
		Matrix init;
		CLR(init.mat);
		init.mat[0][0] = a * 2LL % m;
		init.mat[0][1] = 1;
		init.mat[1][0] = (b - a * a) % m;
		init.mat[1][1] = 0;
		ll ans = 0;
		init = init ^ (n - 2);
		ans = (r2 * init.mat[0][0] % mod + r1 * init.mat[1][0] % mod + mod) % mod;
		cout << ans << endl;
	}
	return 0;
}