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

string s;

int get(string& s) {
	int ret = 0;
	for (int i = 0 ; i < s.size(); i++) {
		ret = ret * 10 + s[i] - '0';
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (cin >> s) {
    	if (s == "0e0") {
    		cout << 0 << endl;
    		continue;
    	}
    	int epos, ppos;
    	for (int i = 0; i < s.size(); i++) {
    		if (s[i] == 'e') epos = i;
    		if (s[i] == '.') ppos = i;
    	}
    	string pre;
    	for (int i = 0; i < epos; i++) pre += s[i];

    	string suf;
    	for (int i = epos + 1; i < s.size(); i++) suf += s[i];
    	int tmp = get(suf);

    	int len = pre.size() - 1 - ppos;

    	if (tmp >= len) {
    		tmp -= len;
    		string ans;
    		for (int i = 0; i < pre.size(); i++) {
    			if (pre[i] != '.') ans += pre[i];
    		}
    		while (tmp) {
    			ans += '0';
    			tmp--;
    		}
    		int ok = 0;
    		for (int i = 0; i < ans.size(); i++) {
    			if (ans[i] != '0') ok = 1;
    			if (ok) cout << ans[i];
    		}
    		puts("");
    	}
    	else {
    		while (tmp) {
    			tmp--;
    			swap(pre[ppos], pre[ppos + 1]);
    			ppos++;
    		}
    		// lookln(pre);
    		string ans;
    		int ok = 0;
    		for (int i = 0; i < ppos; i++) {
    			if (pre[i] != 0) ok = 1;
    			if (ok) ans += pre[i];
    		}
    		if (ans.size() == 0) ans = "0";
    		ok = 0;
    		string tt;
    		for (int i = pre.size() - 1; i > ppos; i--) {
    			if (pre[i] != '0') ok = 1;
    			if (ok) tt += pre[i];
    		}
    		reverse(tt.begin(), tt.end());
    		if (tt.size() != 0) ans += '.';
    		ans += tt;
    		cout << ans << endl;
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