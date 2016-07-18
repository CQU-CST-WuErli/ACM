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

struct P{
	int h, d;
	void read() {
		SII(h, d);
	}
	bool operator < (const P& rhs) const {
		return (h > rhs.h) || (h == rhs.h && d < rhs.d);
	}
};
P p[1010];
int n;

struct MCMF {
	const static int N = 3000;
	const static int M = 5e6 + 100;
	int pnt[M],head[N],nxt[M],cap[M],cost[M],pre[M];
	int cnt;
	int a[N],p[N],vis[N];
	ll d[N];
	void init() {
		OFF(head); cnt = 0;
	}
	void add_edge(int u, int v, int f, int w) {
		pnt[cnt] = v; pre[cnt] = u; nxt[cnt] = head[u]; head[u] = cnt;
		cap[cnt] = f; cost[cnt++] = w;
	}
	bool spfa(int s, int t, int& Flow, ll& Cost) {
		memset(a, 0, sizeof a);
		memset(vis, 0, sizeof vis);
		for (int i = s; i <= t; i++) d[i] = INF_INT;
		stack<int> q;
		vis[s] = 1;
		a[s] = INF_INT;
		d[s] = 0;
		q.push(s);
		while (q.size()) {
			int x = q.top(); q.pop();
			vis[x] = 0;
			for (int i = head[x]; ~i; i = nxt[i]) {
				int v = pnt[i];
				if (d[v] > d[x] + cost[i] && cap[i]) {
					d[v] = d[x] + cost[i];
					p[v] = i;
					a[v] = min(a[x], cap[i]);
					if (!vis[v]) {
						q.push(v);
						vis[v] = 1;
					}
				}
			}
		}
		if (d[t] >= INF_INT) return false;
		Flow += a[t];
		Cost += a[t] * d[t];
		for (int u = t; u != s; u = pre[p[u]]) {
			cap[p[u]] -= a[t];
			cap[p[u] ^ 1] += a[t];
		}
		// lookln(Flow);
		return true;
	}
	ll solve(int s, int t) {
		int Flow = 0;
		ll Cost = 0;
		while (spfa(s, t, Flow, Cost));
		return Cost;
	}
}mfmc;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	SI(n);
    	for (int i = 1; i <= n; i++)
    		p[i].read();
    	sort(p + 1, p + 1 + n);
    	mfmc.init();
    	int supersource = 0;
    	int source = n * 2 + 1;
    	int sink = source + 1;
    	mfmc.add_edge(supersource, source, 2, 0);
    	mfmc.add_edge(source, supersource, 0, 0);
    	for (int i = 1; i <= n; i++) {
    		mfmc.add_edge(source, i, 1, 0);
    		mfmc.add_edge(i, source, 0, 0);
    		mfmc.add_edge(i, i + n, 1, -1);
    		mfmc.add_edge(i + n, i, 0, 1);
    		mfmc.add_edge(i + n, sink, 1, 0);
    		mfmc.add_edge(sink, i + n, 0, 0);
    		int limit = INF_INT;
    		for (int j = i + 1; j <= n; j++) {
    			if (p[i].d <= p[j].d && p[j].d < limit) {
    				// cout << i << ' ' << j << endl;
    				mfmc.add_edge(i + n, j, 1, 0);
    				mfmc.add_edge(j, i + n, 0, 0);
    				mfmc.add_edge(i, j, 1, 0);
    				mfmc.add_edge(j, i, 0, 0);
    				limit = p[j].d;
    			}
    		}
    	}
    	// lookln(mfmc.cnt);
    	printf("%d\n", -mfmc.solve(supersource, sink));
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