//
//  Created by TaoSama on 2016-05-03
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k, r;
char s[610][610];
int d[160][160], f[610][610];
int dir[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
typedef pair<int, int> P;
vector<P> v;

void bfs(int src, int* d) {
    queue<P> q; q.push(v[src]);

    memset(f, 0x3f, sizeof f);
    int x = v[src].first, y = v[src].second;
    f[x][y] = 0;
    while(q.size()) {
        int x = q.front().first, y = q.front().second; q.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(!s[nx][ny] || s[nx][ny] == 'W') continue;
            if(f[nx][ny] == INF) {
                f[nx][ny] = f[x][y] + 1;
                if(f[nx][ny] >= k) {
                    f[nx][ny] = INF;
                    continue;
                }
                q.push(P(nx, ny));
            }
        }
    }
    for(int i = 0; i < v.size(); ++i) {
        int x = v[i].first, y = v[i].second;
        d[i] = f[x][y];
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\input.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        memset(s, 0, sizeof s);

        v.clear();
        int src, des;
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s[i] + 1);
            for(int j = 1; j <= m; ++j) {
                if(s[i][j] == '.' || s[i][j] == 'W') continue;
                if(s[i][j] == 'S') src = v.size();
                if(s[i][j] == 'E') des = v.size();
                v.push_back(P(i, j));
            }
        }

        for(int i = 0; i < v.size(); ++i) if(i != des) bfs(i, d[i]);
        for(int k = 0; k < v.size(); ++k)
            for(int i = 0; i < v.size(); ++i)
                for(int j = 0; j < v.size(); ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        if(d[src][des] == INF) puts("Poor RunningPhoton!");
        else printf("%d\n", d[src][des]);
    }
    return 0;
}
