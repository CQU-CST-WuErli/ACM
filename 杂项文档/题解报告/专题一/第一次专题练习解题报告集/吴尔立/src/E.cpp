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

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
int n, m, k;
char mp[660][660];
int cnt;
int id[660][660];
int g[660][660];
int d[660][660];
int vis[660][660];
void bfs(int x, int y) {
	CLR(d); CLR(vis);
	queue<pair<int,int> > q;
	q.push(make_pair(x, y));
	d[x][y] = 0;
	vis[x][y] = 1;
	while(q.size()) {
	    pair<int, int> now = q.front(); q.pop();
	    for (int i = 0; i < 4; i++) {
	    	int tx = now.first + dir[i][0];
	    	int ty = now.second + dir[i][1];
	    	if (tx < 1 || ty < 1 || tx > n || ty > m || vis[tx][ty] || mp[tx][ty] == 'W') continue;
	    	vis[tx][ty] = 1;
	    	d[tx][ty] = d[now.first][now.second] + 1;
	    	q.push(make_pair(tx, ty));
	    	if (id[tx][ty] >= 0 && d[tx][ty] < k) {
	    		g[id[x][y]][id[tx][ty]] = g[id[tx][ty]][id[x][y]] = d[tx][ty];
	    	}
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
        SIII(n, m, k);
        OFF(id);
        int tx, ty;
        for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
        cnt = 1;
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) {
    			if (mp[i][j] == 'S') id[i][j] = 0;
    			else if (mp[i][j] == 'R') id[i][j] = cnt++;
    			else if (mp[i][j] == 'E') {
    				tx = i, ty = j;
    			}
    		}
    	}
    	id[tx][ty] = cnt;
    	MEM(g, INF_INT);
    	for (int i = 0; i <= cnt; i++) g[i][i] = 0;
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) {
    			if (mp[i][j] != 'W' && mp[i][j] != '.')
    				bfs(i, j);
    		}
    	}
    	for (int k = 0; k <= cnt; k++) {
    		for (int i = 0; i <= cnt; i++) {
    			for (int j = 0; j <= cnt; j++) {
    				g[i][j] = min(g[i][j] ,g[i][k] + g[k][j]);
    			}
    		}
    	}
    	int ans = g[0][cnt];
    	if (ans >= INF_INT) cout << "Poor RunningPhoton!" << endl;
    	else cout << ans << endl;
    }
    return 0;
}