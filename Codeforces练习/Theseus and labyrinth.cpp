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

const int N = 1010;

int n, m;
int sx, sy, ex, ey;
char mp[N][N];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int vis[N][N][4];
int ok[N][N][4];

struct P {
    int x, y, sta, dis;
    P(int a, int b, int c, int d): x(a), y(b), sta(c), dis(d){}
};

void init() {
	CLR(vis);
	CLR(ok);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; ++j) {
            if (mp[i][j] == '+') ok[i][j][0] = ok[i][j][1] = ok[i][j][2] = ok[i][j][3] = 1;
            else if (mp[i][j] == '-') ok[i][j][1] = ok[i][j][3] = 1;
            else if (mp[i][j] == '|') ok[i][j][0] = ok[i][j][2] = 1;
            else if (mp[i][j] == '^') ok[i][j][0] = 1;
            else if (mp[i][j] == '>') ok[i][j][1] = 1;
            else if (mp[i][j] == 'v') ok[i][j][2] = 1;
            else if (mp[i][j] == '<') ok[i][j][3] = 1;
            else if (mp[i][j] == 'L') ok[i][j][0] = ok[i][j][1] = ok[i][j][2] = 1;
            else if (mp[i][j] == 'R') ok[i][j][0] = ok[i][j][2] = ok[i][j][3] = 1;
            else if (mp[i][j] == 'U') ok[i][j][1] = ok[i][j][2] = ok[i][j][3] = 1;
            else if (mp[i][j] == 'D') ok[i][j][0] = ok[i][j][1] = ok[i][j][3] = 1;
        }
	}
}

int bfs() {
    queue<P> q;
    q.push(P(sx, sy, 0, 0));
    vis[sx][sy][0] = 1;
    while (q.size()) {
        P u = q.front(); q.pop();
        int x = u.x, y = u.y, dis = u.dis, sta = u.sta;
        if (x == ex && y == ey) {
            return dis;
        }
        if (!vis[x][y][(sta + 1) % 4]) {
            vis[x][y][(sta + 1) % 4] = 1;
            q.push(P(x, y, (sta + 1) % 4, dis + 1));
        }
        for (int i = 0; i < 4; i++) {
            if (ok[x][y][(i - sta + 4) % 4]) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (ok[nx][ny][(i - sta + 6) % 4] && !vis[nx][ny][sta]) {
                    vis[nx][ny][sta] = 1;
                    q.push(P(nx, ny, sta, dis + 1));
                }
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SII(n, m) == 2) {
    	for (int i = 1; i <= n; i++)
        	scanf("%s", mp[i] + 1);
    	init();
    	SII(sx, sy);
    	SII(ex, ey);
    	cout << bfs() << endl;
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