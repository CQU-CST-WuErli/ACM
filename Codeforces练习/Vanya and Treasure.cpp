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

int n, m, p;
int a[333][333];
vector<pair<int, int> > g[333 * 333];
int dp[333][333];

int d[333][333];

int dis(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

struct P {
	int x, y, val;
	P(int x, int y, int val):x(x), y(y), val(val) {}
	P() {}
	bool operator < (const P& rhs) const {
		return val < rhs.val;
	}
};

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

void bfs(int c) {
	OFF(d);
	vector<P> vc, q;
	for (auto& it : g[c - 1]) {
		vc.push_back(P(it.first, it.second, dp[it.first][it.second]));	}
	sort(vc.begin(), vc.end());
	int cnt = 0, tmp = 1;
	q.push_back(vc[0]);
	d[q[0].x][q[0].y] = dp[q[0].x][q[0].y];
	while(cnt < q.size()) {
	    int x = q[cnt].x, y = q[cnt].y, val = q[cnt].val;
	    cnt++;
	    while (tmp < vc.size() && vc[tmp].val <= val) {
	    	q.push_back(vc[tmp++]);
	    }
	    for (int i = 0; i < 4; i++) {
	    	int tx = x + dir[i][0], ty = y + dir[i][1];
	    	if (tx < 1 || ty < 1 || tx > n || ty > m || d[tx][ty] != -1) continue;
	    	d[tx][ty] = val + 1;
	    	q.push_back(P(tx, ty, d[tx][ty]));
	    }
	}
	for (auto& it : g[c]) {
		dp[it.first][it.second] = d[it.first][it.second];
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SIII(n, m, p) == 3) {
        for (int i = 1; i <= p; i++) g[i].clear();
        MEM(dp, INF_INT);
        int tx, ty;
        for (int i = 1; i <= n; i++) {
        	for (int j = 1; j <= m; j++) {
        		SI(a[i][j]);
        		g[a[i][j]].push_back(make_pair(i, j));
        		if (a[i][j] == 1) {
        			dp[i][j] = i + j - 2;
        		}
        		if (a[i][j] == p)
        			tx = i, ty = j;
        	}
        }
        for (int i = 2; i <= p; i++) {
        	if (g[i].size() * g[i - 1].size() <= m * n) {
        		for (auto& u : g[i]) {
        			for (auto& v : g[i - 1]) {
        				dp[u.first][u.second] = min(dp[u.first][u.second], dp[v.first][v.second] + dis(u, v));
        			}
        		}
        	}
        	else bfs(i);
        }
        cout << dp[tx][ty] << endl;
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