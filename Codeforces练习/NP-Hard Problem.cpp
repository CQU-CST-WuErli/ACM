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

const int N = 100010;

int cor[N];
vector<int> g[N];
int n, m;

bool dfs(int u, int c) {
	cor[u] = c;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (cor[v] == 0) {
			if (!dfs(v, -c)) return false;
		}
		if (cor[v] == cor[u]) return false;
	}
	return true;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n, m) == 2) {
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= m; i++) {
        	int u, v; SII(u, v);
        	g[u].push_back(v);
        	g[v].push_back(u);
        }
        CLR(cor);
        int flag = 0;
        for (int i = 1; i <= n; i++) {
        	if (cor[i] == 0) {
        		if (!dfs(i, 1)) {
        			flag = 1; break;
        		}
        	}
        }
        if (flag) puts("-1");
        else {
        	vector<int> a, b;
        	for (int i = 1; i <= n; i++) {
        		if (cor[i] == 1) a.push_back(i);
        		else b.push_back(i);
        	}
        	cout << (int)a.size() << endl;
        	for (int i = 0; i < a.size(); i++)
        		cout << a[i] << ' ';
        	cout << endl;
        	cout << (int)b.size() << endl;
        	for (int i = 0; i < b.size(); i++)
        		cout << b[i] << ' ';
        	cout << endl;
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