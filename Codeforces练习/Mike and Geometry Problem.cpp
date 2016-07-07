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

const int N = 200010;

ll n, k;
ll fac[N], inv[N];

ll ksm(ll a, ll x, ll mod) {
	if (x == 0) return 1;
	ll ret = ksm(a, x / 2, mod);
	ret = ret * ret % mod;
	if (x & 1) ret = ret * a % mod;
	return ret;
}

void init() {
	fac[0] = 1; inv[0] = 1;
	for (ll i = 1; i < N; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = ksm(fac[i], MOD - 2, MOD);
	}
}

map<int, int> mp;

ll C(ll n, ll k) {
	ll ret = fac[n] * inv[k] % MOD;
	// lookln(fac[n]); lookln(inv[k]);
	ret = ret * inv[n - k] % MOD;
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    init();
    while (cin >> n >> k) {
    	mp.clear();
    	for (int i = 1; i <= n; i++) {
    		int l, r; SII(l, r);
    		mp[l]++; mp[r + 1]--;
    	}
    	int last = mp.begin()->first;
    	int tmp = 0;
    	ll ans = 0;
    	for (auto it = mp.begin(); it != mp.end(); it++) {
    		ll num = it->first - last;
    		if (tmp >= k) ans += C(tmp, k) * num % MOD;
    		// lookln(ans);
    		ans %= MOD;
    		tmp += it->second;
    		last = it->first;
    	}
    	cout << ans << endl;
    }
	return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \|     |//  `.
            /  \|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			佛祖保佑		永无BUG
*/