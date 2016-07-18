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
const int M = 5e5 + 100;
int n, m;
vector<int> g[N];
map<pair<int, int>, int> mp;
int dfn[N], low[N];
int dfs_clock;
vector<pair<int, int> > es;

int tarjan(int fa, int u) {
    dfn[u] = low[u] = ++dfs_clock;
    int ret = u;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        if (!dfn[v]) {
            int tmp = tarjan(u, v);
            ret = max(ret, tmp);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                mp[make_pair(u, v)] = mp[make_pair(v, u)] = tmp;
            }
        }
        else low[u] = min(low[u], dfn[v]);
    }
    return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	SII(n, m);
        for (int i = 1; i <= n; i++) g[i].clear();
            es.clear();
        for (int i = 1; i <= m; i++) {
            int u, v;
            SII(u, v);
            g[u].push_back(v);
            g[v].push_back(u);
            es.push_back(make_pair(u, v));
        }
        dfs_clock = 0;
        CLR(dfn); CLR(low);
        mp.clear();
        tarjan(-1, n);
        for (int i = 0; i < es.size(); i++) {
            if (mp.find(es[i]) == mp.end()) puts("0 0");
            else {
                printf("%d %d\n", mp[es[i]], mp[es[i]] + 1);
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