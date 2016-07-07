//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

ll x, m, mod, c;
struct Matrix {
	ll mat[3][3];
	void init() {
		CLR(mat);
	}
	Matrix operator * (Matrix rhs) {
		Matrix ret;
		ret.init();
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= 2; j++) {
				for (int k = 1; k <= 2; k++) {
					ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * rhs.mat[k][j] % mod) % mod;
				}
			}
		}
		return ret;
	}
};


ll cal(ll n) {
	if (n == 1) return x % mod;
	n--;
	Matrix ret;
	ret.init();
	ret.mat[1][1] = 10LL; ret.mat[1][2] = 1LL; ret.mat[2][2] = 1LL;
	Matrix tmp;
	tmp.init();
	tmp.mat[1][1] = tmp.mat[2][2] = 1;
	while(n) {
		if (n & 1) tmp = tmp * ret;
		ret = ret * ret;
		n >>= 1;
	}
	ll ans = (x * tmp.mat[1][1] % mod + tmp.mat[1][2] * x % mod) % mod;
	return ans % mod;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    int kase = 1;
    while(t--) {
        cin >> x >> m >> mod >> c;
        ll ans = cal(m);
        cout << "Case #" << kase++ << ":" << endl;
        // lookln(ans);
        if (ans == c) puts("Yes");
        else puts("No");
    }
	return 0;
}