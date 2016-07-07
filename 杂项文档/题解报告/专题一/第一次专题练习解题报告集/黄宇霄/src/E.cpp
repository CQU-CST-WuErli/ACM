//
//  Created by Running Photon on 2016-05-05
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
const int maxn = 600 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;

int n, m, k;
int stx, sty, edx, edy;
char mp[maxn][maxn];
int id[maxn][maxn], cnt;
int dis[maxn][maxn];
int d[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
bool check(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m && mp[x][y] != 'W';
}

int mat[205][205];
typedef pair <int, int> sta;
void bfs(int X, int Y) {
    memset(dis, 0x3f, sizeof dis);
    dis[X][Y] = 0;
    queue <sta> que;
    que.push(sta(X, Y));
    while(que.size()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if(!check(nx, ny)) continue;
            if(dis[nx][ny] == inf) {
                dis[nx][ny] = dis[x][y] + 1;
                que.push(sta(nx, ny));
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(id[i][j] && dis[i][j] < k) {
                mat[id[X][Y]][id[i][j]] = dis[i][j];
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
        cnt = 0;
        scanf("%d%d%d", &n, &m, &k);
        CLR(id); memset(mat, 0x3f, sizeof mat);
        for(int i = 1; i <= n; i++) {
            scanf("%s", mp[i] + 1);
            for(int j = 1; j <= m; j++) {
                if(mp[i][j] == 'S') {
                    stx = i;
                    sty = j;
                }
                if(mp[i][j] == 'E') {
                    edx = i;
                    edy = j;
                }
                if(mp[i][j] == '.' || mp[i][j] == 'W') continue;
                id[i][j] = ++cnt;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(id[i][j]) {
                    bfs(i, j);
                }
            }
        }
        for(int k = 1; k <= cnt; k++) {
            for(int i = 1; i <= cnt; i++) {
                for(int j = 1; j <= cnt; j++) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        int ans = mat[id[stx][sty]][id[edx][edy]];
        if(ans == inf) puts("Poor RunningPhoton!");
        else printf("%d\n", ans);
    }

	return 0;
}
