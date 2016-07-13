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
const long long MOD=4000000017;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

ll n, k;
ll a[100010];


int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (cin >> n >> k) {
    	string s;
    	int op = 0;
    	for (int i = 0; i <= n; i++) {
    		cin >> s;
    		if (s[0] == '?') a[i] = INF_INT;
    		else {
    			op++;
    			ll flag = 1LL;
    			int cnt = 0;
    			if (s[cnt] == '-') flag = -1, cnt++;
    			int tmp = 0;
    			while (cnt < s.size()) {
    				tmp = tmp * 10 + s[cnt++] - '0';
    			}
    			a[i] = tmp * flag;
    		}
    	}
    	if (k == 0) {
    		if (a[0] == 0) puts("Yes");
    		else if (a[0] >= INF_INT) puts(op % 2 == 1 ? "Yes" : "No");
    		else puts("No");
    	}
    	else {
    		if (op < n + 1) puts((n + 1) % 2 == 1 ? "No" : "Yes");
    		else {
    			ll tmp = 0;
    			for (int i = n; i >= 1; i--) {
    				tmp = tmp * k + a[i];
    				tmp %= MOD;
    			}
    			if (tmp % MOD * k * -1 % MOD == a[0] % MOD) puts("Yes");
    			else puts("No");
    		}
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