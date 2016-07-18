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
#include <bitset>
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

int n, m;
vector<int> g[20020];
bitset<20020> bit[20020];
int deg[20020];
int topo[200020];
vector<int> g2[20020];

void topsort() {
	queue<int> q;
	for (int i = 1; i <= n; i++)  {
		if (!deg[i]) q.push(i);
		bit[i].reset();
		bit[i][i] = 1;
	}
	int cnt = 0;
	while (q.size()) {
		int x = q.front(); q.pop();
		topo[++cnt] = x;
		for (int i = 0; i < g[x].size(); i++) {
			int v = g[x][i];
			g2[v].push_back(x);
			if (--deg[v] == 0) q.push(v);
		}
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
    	for (int i = 1; i <= n; i++) {
    		g[i].clear(); deg[i] = 0;
    		g2[i].clear();
    	}
    	for (int i = 1; i <= m; i++) {
    		int u, v;
    		SII(u, v);
    		g[u].push_back(v);
    		deg[v]++;
    	}
    	topsort();
    	int ans = 0;
    	for (int i = 1; i <= n; i++) {
    		int u = topo[i];
    		for (int j = g2[u].size() - 1; j >= 0; j--) {
    			int v = g2[u][j];
    			if (bit[u][v]) ans++;
    			bit[u] |= bit[v];
    		}
    	}
    	cout << ans << endl;
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