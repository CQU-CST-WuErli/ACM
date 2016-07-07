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

string get(ll x) {
    string ret;
    if (x == 0) return ret = "0";
    if (x < 0) {
        x = abs(x);
        while (x) {
            ret += x % 10 + '0';
            x /= 10;
        }
        reverse(ret.begin(), ret.end());
        ret = "-" + ret;
    }
    else {
        while (x) {
            ret += x % 10 + '0';
            x /= 10;
        }
        reverse(ret.begin(), ret.end());
    }
    return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    // cout << get(0) << endl;
    while (SI(n) == 1) {
        priority_queue<int, vector<int>, greater<int> > q;
        vector<string> ans;
        for (int i = 1; i <= n; i++) {
            string op;
            cin >> op;
            int x;
            if (op == "insert") {
                SI(x);
                q.push(x);
                ans.push_back(op + " " + get(x));
            }
            else if (op == "getMin") {
                SI(x);
                if (q.size() && q.top() == x) {
                    ans.push_back(op + " " + get(x));
                    continue;
                }
                while (q.size() && q.top() < x) {
                    ans.push_back("removeMin");
                    q.pop();
                }
                if (q.size() == 0) {
                    ans.push_back("insert " + get(x));
                    q.push(x);
                    ans.push_back(op + " " + get(x));
                }
                else if (q.top() > x) {
                    ans.push_back("insert " + get(x));
                    q.push(x);
                    ans.push_back(op + " " + get(x));
                }
            }
            else if (op == "removeMin") {
                if (q.size() == 0) {
                    q.push(0);
                    ans.push_back("insert 0");
                    q.pop();
                    ans.push_back(op);
                }
                else {
                    ans.push_back(op);
                    q.pop();
                }
            }
        }
        cout << ans.size() << endl;
        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i] << '\n';
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
            佛祖保佑        永无BUG
*/