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

const int N = 10010;
const int M = 20020;
int n, m;
int pnt[M << 1], head[N], nxt[M << 1], flag[M << 1], cnt;

void add_edge(int u, int v) {
	pnt[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
}

int ans;
int pre[N], low[N], dfs_clock;

int dfs(int fa, int u) {
	pre[u] = low[u] = ++dfs_clock;
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = pnt[i];
		if (i == (fa ^ 1)) continue;
		if (!pre[v]) {
			low[v] = dfs(i, v);
			low[u] = min(low[u], low[v]);
			if (low[v] > pre[u]) {
				ans++;
			}
		}
		else low[u] = min(low[u], pre[v]);
	}
	return low[u];
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T, kase = SI(T_T); kase <= T_T; kase++) {
    	SII(n, m);
    	cnt = 0; OFF(head);
    	for (int i = 1; i <= m; i++) {
    		int u, v;
    		SII(u, v);
    		add_edge(u, v);
    		add_edge(v, u);
    	}
    	ans = 0;
    	CLR(low); CLR(pre); dfs_clock = 0;
    	for (int i = 1; i <= n; i++) if (!pre[i]) {
    		dfs(-1, i);
    	}
    	printf("Case %d: %d\n", kase, ans);
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