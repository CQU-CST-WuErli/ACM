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

// 0 green 1 black 2 red 3 blue 4 white
int m, n;
char mp[55][55];
int vis[55][55][5][4];
int dis[55][55][5][4];
int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

struct P
{
	int x, y, id, dir;
	P(int x, int y, int id, int dir):x(x), y(y), id(id), dir(dir) {}
	P() {}
}st, ed;

int bfs() {
	int ret = INF_INT;
	queue<P> q;
	CLR(vis);
	MEM(dis, INF_INT);
	vis[st.x][st.y][st.id][st.dir] = 1;
	dis[st.x][st.y][st.id][st.dir] = 0;
	q.push(st);
	while(q.size()) {
	    P now = q.front(); q.pop();
	    int tid = (now.id + 1) % 5;
	    for (int i = 0; i < 4; i++) {
	    	int tx = now.x + d[i][0], ty = now.y + d[i][1];
	    	if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
	    	if (mp[tx][ty] == '#') continue;
	    	int delta;
	    	if (i == now.dir) delta = 1;
	    	else if ((now.dir + 1) % 4 == i || (now.dir - 1 + 4) % 4 == i) delta = 2;
	    	else delta = 3;
	    	if (dis[tx][ty][tid][i] > dis[now.x][now.y][now.id][now.dir] + delta) {
	    		dis[tx][ty][tid][i] = dis[now.x][now.y][now.id][now.dir] + delta;
	    		if (!vis[tx][ty][tid][i]) {
	    			vis[tx][ty][tid][i] = 1;
	    			q.push(P(tx, ty, tid, i));
	    		}
	    	}
	    }
	}
	return min(min(dis[ed.x][ed.y][0][0],dis[ed.x][ed.y][0][1]),min(dis[ed.x][ed.y][0][2],dis[ed.x][ed.y][0][3]));
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
        SII(n, m);
        for (int i = 1; i <= n; i++) {
        	for (int j = 1; j <= m; j++) {
        		cin >> mp[i][j];
        		if (mp[i][j] == 'S') {
        			st.x = i; st.y = j;st.dir = 0;
        			st.id = 0;
        		}
        		else if (mp[i][j] == 'T') {
        			ed.x = i; ed.y =j;
        			ed.id = 0;
        		}
        	}
        }
        int ans = bfs();
        if (ans >= INF_INT) puts("-1");
        else cout << ans << endl;
    }
	return 0;
}