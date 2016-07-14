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

int q;
ll logs[100];
map<ll, ll> sum;

void init() {
	logs[0] = 1LL;
	for (int i = 1; i <= 62;i++) {
		logs[i] = logs[i - 1] * 2 + 1;
	}
}

int get(ll x) {
	if (x == 1) return 0;
	else {
		for (int i = 1; i <= 62; i++) {
			if (x >= logs[i - 1] + 1 && x <= logs[i]) return i;
		}
	}
}

void change(ll u, ll v, ll w) {
	int du = get(u), dv = get(v);
	if (du > dv) {
		swap(du, dv);
		swap(u, v);
	}
	// v big
	for (int i = dv; i > du; i--) {
		sum[v] += w;
		v /= 2;
	}
	if (u == v) return;
	while (u != v) {
		sum[u] += w;
		sum[v] += w;
		u /= 2; v /= 2;
	}
}

ll query(ll u, ll v) {
	ll ret = 0;
	int du = get(u), dv = get(v);
	if (du > dv) {
		swap(du, dv);
		swap(u, v);
	}
	for (int i = dv; i > du; i--) {
		ret += sum[v];
		v /= 2;
	}
	if (u == v) return ret;
	while (u != v) {
		ret += sum[u];
		ret += sum[v];
		u /= 2, v /= 2;
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    init();
    SI(q);
    for (int i = 1; i <= q; i++) {
    	int op; SI(op);
    	if (op == 1) {
    		ll u, v, w;
    		scanf("%I64d%I64d%I64d", &u, &v, &w);
    		change(u, v, w);
    	}
    	else if (op == 2) {
    		ll u, v;
    		scanf("%I64d%I64d", &u, &v);
    		printf("%I64d\n", query(u, v));
    	}
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