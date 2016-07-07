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
const int M = 50010 * 2;

int n, m, k;
int pnt[M], nxt[M], w[M], cap[M], head[N], cnt;

void add_edge(int u, int v, int cost, int flow) {
 	pnt[cnt] = v; nxt[cnt] = head[u]; w[cnt] = cost; cap[cnt] = flow; head[u] = cnt++;
}

int vis[N], dis[N];

bool spfa(int mid) {
	MEM(dis, INF_INT);
	CLR(vis);
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	dis[1] = 0;
	while (q.size()) {
		int x = q.front(); q.pop();
		vis[x] = 0;
		// lookln(x);
		for (int i = head[x]; ~i; i = nxt[i]) {
			int v = pnt[i];
			// lookln(v);
			if (cap[i] < mid) continue;
			if (dis[v] > dis[x] + w[i]) {
				dis[v] = dis[x] + w[i];
				if (!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return dis[n] <= k;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	SIII(n, m, k);
    	cnt = 0; OFF(head);
    	for (int i = 1; i <= m; i++) {
    		int u, v, cost, flow;
    		SII(u,v); SII(flow, cost);
    		add_edge(u, v, cost, flow);
    		add_edge(v, u, cost, flow);
    	}
    	int l = 0, r = 2000000001;
    	int ans = -1;
    	while (l <= r) {
    		int mid = l + r >> 1;
    		// lookln(mid);
    		if (spfa(mid)) {
    			ans = mid;
    			l = mid + 1;
    		}
    		else r = mid - 1;
    	}
    	if (ans == -1) puts("Poor RunningPhoton!");
    	else cout << ans << endl;
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