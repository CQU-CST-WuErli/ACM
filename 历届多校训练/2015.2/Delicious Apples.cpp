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

int L, n, K;
ll suml[100010], sumr[100010];
vector<ll> l, r;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	SIII(L, n, K);
    	CLR(suml); CLR(sumr);
    	l.clear(); r.clear();
    	for (int i = 1; i <= n; i++) {
    		int x, a;
    		SII(x, a);
    		while (a--) {
    			if (2 * x < L) l.push_back(x);
    			else r.push_back(L - x);
    		}
    	}
    	sort(l.begin(), l.end());
    	sort(r.begin(), r.end());
    	for (int i = 0; i < (int)l.size(); i++) {
    		if (i + 1 <= K) suml[i + 1] = l[i];
    		else suml[i + 1] = suml[i + 1 - K] + l[i];
    	}
    	for (int i = 0; i < (int)r.size(); i++) {
    		if (i + 1 <= K) sumr[i + 1] = r[i];
    		else sumr[i + 1] = sumr[i + 1 - K] + r[i];
    	}
    	int len = l.size(), R = r.size();
    	// for (int i = 1; i <= len; i++) cout << suml[i] << ' ';
    	// 	cout << endl;
    	// for (int i = 1; i <= R; i++) cout << sumr[i] << ' ';
    	// 	cout << endl;
    	ll ans = (suml[len] + sumr[R]) << 1;
    	for (int i = 0; i <= K && i <= len; i++) {
    		ll t1 = suml[len - i];
    		ll t2 = sumr[max(0, R - (K - i))];
    		ll tmp = (t1 + t2) * 2 + L;
    		// cout << t1 << ' ' << t2 << ' ' << tmp <<endl;
    		ans = min(ans, tmp);
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