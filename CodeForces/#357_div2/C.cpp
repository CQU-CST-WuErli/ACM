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

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SI(n) == 1) {
    	map<int,int> mp;
    	vector<string> ans1;
    	vector<int> ans2;
    	int x;
    	string op;
    	for (int i = 1; i <= n; i++) {
    		cin >> op;
    		if (op == "insert") {
    			cin >> x;
    			mp[x]++;
    			ans1.push_back(op);
    			ans2.push_back(x);
    		}
    		else if (op == "getMin") {
    			cin >> x;
    			map<int,int>::iterator it = mp.begin();
    			while (it != mp.end() && it->first < x) {
    				mp[it->first]--;
    				if (mp[it->first] == 0) mp.erase(it);
    				ans1.push_back("removeMin");
    				it = mp.begin();
    			}
    			it = mp.begin();
    			if (it == mp.end() || it->first != x) {
    				mp[x]++;
    				ans1.push_back("insert");
    				ans2.push_back(x);
    			}
    			ans1.push_back(op); ans2.push_back(x);
    		}
    		else if (op == "removeMin") {
    			map<int,int>::iterator it = mp.begin();
    			if (it == mp.end()) {
    				ans1.push_back("insert");
    				ans2.push_back(0);
    			}
    			else {
    				mp[it->first]--;
    				if (mp[it->first] == 0) mp.erase(it);
    			}
    			ans1.push_back(op);
    		}
    	}
    	cout << ans1.size() << endl;
    	int tmp = 0;
    	for (int i = 0; i < ans1.size(); i++) {
    		if (ans1[i][0] != 'r') cout << ans1[i] << ' ' << ans2[tmp++] << '\n';
    		else cout << ans1[i] << '\n';
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