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

int ans;

string gao1(string& s) {
	int pos = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') pos = i, break;
	}
	if (pos == -1) {
		string ret;
		int ok = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '+') continue;
			if (s[i] == '-') ret += '-';
			if (s[i] != '0') ok = 1;
			if (ok) ret += s[i];
		}
		if (ret.size() == 0 || (ret.size() == 1 && ret[0] == '-')) ret += "0";
		return ret;
	}
	else {
		string ret;
		int ok = 0;
		for (int i = 0; i < pos; i++) {
			if (s[i] == '+') continue;
			if (s[i] == '-') ret += '-';
			if (s[i] != '0') ok = 1;
			if (ok) ret += s[i];
		}
		if (ret.size() == 0 || (ret.size() == 1 && ret[0] == '-')) ret += '0';
		string tmp;
		ok = 0;
		for (int i = pos + 1; i < s.size(); i++) {
			tmp += s[i];
			if (s[i] != '0') ok = 1;
		}
		for (int i = tmp.size(); i >= 0; i--) if (tmp[i] == 0) tmp.erase(tmp.size() - 1, 1);
		if (ok) ret += '.', ret += tmp;
		return ret;
	}
}

string gao2(string& s) {
	string ret;
	int ok = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '0') ok = 1;

	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    string s;
    while (cin >> s) {
    	ans = 0;
    	int pos = 0;
    	for (int i = 0; i < s.size(); i++) {
    		if (s[i] == 'e') pos = i, break;
    	}
    	string a, b;
    	for (int i = 0; i < pos; i++) a += s[i];
    	for (int i = pos + 1; i < s.size(); i++) b += s[i];
    	string a1, a2;
    	a1 = gao1(a);
    	a2 = gao2(b);
    	cout << a <<  'e' << b << endl;
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