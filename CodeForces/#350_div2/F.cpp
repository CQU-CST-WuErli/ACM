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

string s, t;
map<char, int> mp;
int zero;

int getnum(int x) {
	if (!x) return 1;
	int ret = 0;
	while(x) {
	    x /= 10;
	    ret++;
	}
	return ret;
}

string getlen(int x){
	string ret = "";
	while(x) {
	    ret += '0' + (x % 10);
	    x /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string get1() {
	if (t[0] == '0') return "INF";
	string ret = t;
	for (int i = 1; i <= zero; i++) ret += '0';
	for (auto& it : mp) {
		if (it.second == 0) continue;
		if (it.first == '0') continue;
		for (int i = 1; i <= it.second; i++)
			ret += it.first;
	}
	return ret;
}

string get2() {
	int flag = 0;
	string ret;
	for (auto& it : mp) {
		if (it.second == 0) continue;
		if (it.first != '0') {
			ret += it.first;
			flag = 1;
			break;
		}
	}
	if (!flag) return "INF";
	for (int i = 1; i <= zero; i++) ret += '0';
	int ok = 0;
	for (auto& it : mp) {
		if (it.second == 0) continue;
		if (it.first == '0') continue;
		if (it.first >= t[0] && !ok) ok = 1, ret += t;
		if (!ok) {
			int num = it.second;
			if (it.first == ret[0]) num--;
			for (int i = 1; i <= num; i++)
				ret += it.first;
		}
		else {
			int num = it.second;
			if (it.first == ret[0]) num--;
			for (int i = 1; i <= num; i++)
				ret += it.first;
		}
	}
	if (!ok) ret += t;
	return ret;
}

string get3() {
	int flag = 0;
	string ret;
	for (auto& it : mp) {
		if (it.second == 0) continue;
		if (it.first != '0') {
			ret += it.first;
			flag = 1;
			break;
		}
	}
	if (!flag) return "INF";
	for (int i = 1; i <= zero; i++) ret += '0';
	int ok = 0;
	for (auto& it : mp) {
		if (it.second == 0) continue;
		if (it.first == '0') continue;
		if (it.first > t[0] && !ok) ok = 1, ret += t;
		if (!ok) {
			int num = it.second;
			if (it.first == ret[0]) num--;
			for (int i = 1; i <= num; i++)
				ret += it.first;
		}
		else {
			int num = it.second;
			if (it.first == ret[0]) num--;
			for (int i = 1; i <= num; i++)
				ret += it.first;
		}
	}
	if (!ok) ret += t;
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(cin >> s) {
		mp.clear();
	    cin >> t;
	    if (s == "01" || s == "10") {
	    	puts("0");
	    	continue;
	    }
	    int len = -1;
	    for (int i = 1; i <= 1000000; i++) {
	    	int tmp = getnum(i);
	    	if (i + tmp == s.size()) {
	    		len = i;
	    		break;
	    	}
	    }
	    // lookln(len);
	    for (char c : s) mp[c]++;
	    string tt = getlen(len);
		// cout << tt << endl;
		for (char c : tt) mp[c]--;
		for (char c : t) mp[c]--;
		zero = 0;
		for (auto& it : mp) {
			if (it.second == 0) continue;
			if (it.first == '0') zero = it.second;
		}
		string str1, str2, str3;
		str1 = get1();
		str2 = get2();
		str3 = get3();
		// cout << str1 << endl;
		// cout << str2 << endl;
		// cout << str3 << endl;
		string ans;
		if (str1 != "INF") ans = str1;
		if (ans.size() == 0 && str2 != "INF") ans = str2;
		else if (str2 != "INF") ans = min(ans, str2);
		if (ans.size() == 0) ans = str3;
		else if (str3 != "INF") ans = min(ans, str3);
		cout << ans << endl;
	}
	return 0;
}