//
//  Created by Running Photon on 2016-05-11
//  Copyright (c) 2015 Running Photon. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <stack>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x,begin())
#define ll long long
#define CLR(x) memset(x, 0, sizeof x)
using namespace std;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;

char mp[55][55];
int stx, sty, edx, edy, n, m;
int vis[55][55][20][4];
struct Pnt {
    int x, y, state, dir;
    Pnt(int _x = 0, int _y = 0, int _state = 0, int _dir = 0) : x(_x), y(_y), state(_state), dir(_dir) {}
};
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] != '#';
}
int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
void bfs() {
    memset(vis, 0x3f, sizeof vis);
    vis[stx][sty][1][0] = 0;
    queue <Pnt> que;
    que.push(Pnt(stx, sty, 1, 0));
    while(que.size()) {
        int x = que.front().x;
        int y = que.front().y;
        int sta = que.front().state;
        int dir = que.front().dir;
        que.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            int nsta = sta << 1;
            if(nsta > 16) nsta = 1;
            int dis = 0;
            if(i != dir) dis++;
            if(abs(i - dir) == 2) dis++;
            if(!check(nx, ny)) continue;
            if(vis[nx][ny][nsta][i] > vis[x][y][sta][dir] + 1 + dis) {
                vis[nx][ny][nsta][i] = vis[x][y][sta][dir] + 1 + dis;
                que.push(Pnt(nx, ny, nsta, i));
//                printf("x = %d  y = %d  sta = %d  dir = %d  dis = %d\n", nx, ny, nsta, i, vis[nx][ny][nsta][i]);
            }
        }
    }
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%s", mp[i] + 1);
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(mp[i][j] == 'S') {
                    stx = i;
                    sty = j;
                }
                if(mp[i][j] == 'T') {
                    edx = i;
                    edy = j;
                }
            }
        }
        bfs();
        int ans = inf;
        for(int i = 0; i < 4; i++)
            ans = min(ans, vis[edx][edy][1][i]);
        if(ans == inf) puts("-1");
        else printf("%d\n", ans);
    }

	return 0;
}
