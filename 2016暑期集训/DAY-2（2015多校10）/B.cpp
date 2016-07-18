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

int n;
ll ksm(ll x, ll a) {
	if (a == 0) return 1 % MOD;
	ll ret = ksm(x, a /  2);
	ret = ret * ret % MOD;
	if (a & 1) ret = ret * x % MOD;
	return ret;
}
int maxp[1000010];
void init() {
    for (int i = 1; i <= 1000001; i++)
        maxp[i] = i;
    for (int i = 2; i <= 1000001; i++) if (maxp[i] == i) {
        for (int j = i + i; j <= 1000001; j += i) maxp[j] = i;
    }
}
ll ans[1000010];

bool ok(int x) {
    int tmp = maxp[x];
    while (x % tmp == 0)
        x /= tmp;
    return x == 1;
}

void solve() {
    ans[1] = 1;
    for (int i = 2; i <= 1000001; i++) {
        if (ok(i)) ans[i] = ans[i - 1] * maxp[i]  % MOD;
        else ans[i] = ans[i - 1];
    }
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    init();
    solve();
    while (t--) {
    	SI(n);
        cout << ans[n + 1] * ksm((n + 1), MOD - 2) % MOD << endl;
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