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

const int N = 550;

int deg[N];
int ind[N], outd[N];
int n, m;
vector<int> g[N];
int vis[N];

bool dfs1(int fa, int u) {
	vis[u] = 1;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (vis[v]) continue;
		dfs1(u, v);
	}
}


int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	SII(n, m);
    	CLR(ind); CLR(outd); CLR(deg);
    	for (int i = 0; i <= n; i++) g[i].clear();
    	for (int i = 1; i <= m; i++) {
    		int u, v;
    		SII(u, v);
    		deg[u]++; deg[v]++;
    		outd[u]++; ind[v]++;
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
    	int cnn = 1;
    	CLR(vis);
    	dfs1(-1, 1);
    	for (int i = 1; i <= n; i++) if (vis[i] == 0) cnn = 0;

    	int flag = 0;
    	for (int i = 1; i <= n; i++) if (deg[i] % 2 == 1) flag++;
    	if ((flag == 2 || flag == 0) && cnn) cout << "Yes";
    	else cout << "No";

    	int f1 = 0, f2 = 0, f3 = 0;
    	for (int i = 1; i <= n; i++) {
    		if (ind[i] == outd[i]) f1++;
    		else if (ind[i] == outd[i] + 1) f2++;
    		else if (ind[i] + 1 == outd[i]) f3++;
    	}
    	if (((f1 == n - 2 && f2 == 1 && f3 == 1) || (f1== n && f2 == 0 && f3 == 0)) && cnn) cout << " Yes" << endl;
    	else cout << " No" << endl;
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