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

ll n, k;
ll c[500050];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (scanf("%I64d%I64d", &n, &k) == 2) {
    	ll sum = 0;
    	for (int i = 1; i <= n; i++) {
    		scanf("%I64d", c + i);
    		sum += c[i];
    	}
    	ll L = 0, R = sum / n;
    	ll ans1 = 0;
    	while (L <= R) {
    		ll mid = L + R >> 1;
    		ll tmp = 0;
    		for (int i = 1; i <= n; i++)
    			if (c[i] < mid) tmp += mid - c[i];
    		if (tmp <= k) ans1 = mid, L = mid + 1;
    		else R = mid - 1;
    	}

    	L = (sum + n - 1) / n, R = 1000000000;
    	ll ans2 = 0;
    	while (L <= R) {
    		ll mid = L + R >> 1;
    		ll tmp = 0;
    		for (int i = 1; i <= n; i++)
    			if (c[i] > mid) tmp += c[i] - mid;
    		if (tmp <= k) ans2 = mid, R = mid - 1;
    		else L = mid + 1;
    	}
    	cout << ans2 - ans1 << endl;
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