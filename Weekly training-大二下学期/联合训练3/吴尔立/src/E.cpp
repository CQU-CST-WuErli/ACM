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

const int N = 5010;
const int M = 100010;

int n, m;
int pnt[M], nxt[M], head[N], cnt;

void add_edge(int u, int v) {
	pnt[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
}

int sccno[N], low[N], pre[N], inS[N];
int dfs_clock, scc_cnt;
stack<int> S;

void init() {
	CLR(sccno); CLR(low); CLR(pre); CLR(inS);
	dfs_clock = scc_cnt = 0;
	while (S.size()) S.pop();
}

int dfs(int u) {
	// lookln(u);
	pre[u] = low[u] = ++dfs_clock;
	S.push(u);
	inS[u] = 1;
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = pnt[i];
		if (!pre[v]) {
			low[v] = dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else if (inS[v]) {
			low[u] = min(low[u], pre[v]);
		}
	}
	if (low[u] == pre[u]) {
		scc_cnt++;
		int v;
		do {
			v = S.top(); S.pop();
			inS[v] = 0;
			sccno[v] = scc_cnt;
		}while (v != u);
	}
	return low[u];
}

void find_scc() {
	init();
	for (int i = 1; i <= n; i++) if (!pre[i]) dfs(i);
}

vector<int> g[N];

void buildDAG() {
	for (int i = 0; i <= n; i++) g[i].clear();
	for (int u = 1; u <= n; u++) {
        for (int i = head[u]; ~i; i = nxt[i]){
            int v = pnt[i];
            if (sccno[u] != sccno[v]) {
                g[sccno[u]].push_back(sccno[v]);
            }
        }
    }
}

int match[N], used[N];

int find(int x) {
	for (int i = 0; i < g[x].size(); i++) {
		int v = g[x][i];
		if (used[v]) continue;
		used[v] = 1;
		if (match[v] == -1 || find(match[v])) {
			match[v] = x;
			return 1;
		}
	}
	return 0;
}

int hungary() {
	OFF(match);
	int ret = 0;
	for (int i = 1; i <= scc_cnt; i++) {
		CLR(used);
		if (find(i)) ret++;
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
    	cnt = 0; OFF(head);
    	for (int i = 1; i <= m; i++) {
    		int u, v;
    		SII(u, v);
    		add_edge(u, v);
    	}
    	find_scc();
    	buildDAG();
    	int ans = hungary();
    	cout << scc_cnt - ans << endl;
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