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

const int N = 300030;
int n, q;
int ans[N];
vector<int> g[N];
int par[N], son[N];
int sz[N];

void dfs(int fa, int u) {
	par[u] = fa;
	sz[u] = 1; son[u] = 0;
	ans[u] = u;
	for (auto& v : g[u]) {
		if (v == fa) continue;
		dfs(u, v);
		sz[u] += sz[v];
		if (!son[u] || sz[son[u]] < sz[v]) son[u] = v;
	}
	if (sz[son[u]] * 2 > sz[u]) {
		int tmp = ans[son[u]];
		while ((sz[u] - sz[tmp]) * 2 > sz[u])
			tmp = par[tmp];
		ans[u] = tmp;
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n, q) == 2) {
        for (int i = 1; i <= n; i++) {
        	g[i].clear();
        	ans[i] = -1;
        }
        for (int u = 2; u <= n; u++) {
        	int v; SI(v);
        	g[u].push_back(v);
        	g[v].push_back(u);
        }
        dfs(-1, 1);
        while (q--) {
        	int x;
        	SI(x);
        	printf("%d\n", ans[x]);
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