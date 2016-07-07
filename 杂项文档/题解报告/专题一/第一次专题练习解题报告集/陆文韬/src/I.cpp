//
//  Created by TaoSama on 2016-05-02
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

int n, m;
char s[55][55];
struct P {
    int x, y, d, c;
    P() {}
    P(int x, int y, int d, int c) : x(x), y(y), d(d), c(c) {}
};
int f[55][55][4][5];
int sx, sy;
int d[][2] = { -1, 0, 0, 1, 1, 0, 0, -1};

int bfs() {
    queue<P> q; q.push(P(sx, sy, 0, 0));
    memset(f, -1, sizeof f);
    f[sx][sy][0][0] = 0;
    while(q.size()) {
        P u = q.front(), v; q.pop();
        if(s[u.x][u.y] == 'T' && u.c == 0) return f[u.x][u.y][u.d][u.c];

//      printf("(%d, %d, %d, %d) = %d\n", u.x, u.y, u.d, u.c, f[u.x][u.y][u.d][u.c]);

        v = u;
        v.d = (v.d + 1) % 4;
        if(f[v.x][v.y][v.d][v.c] == -1) {
            f[v.x][v.y][v.d][v.c] = f[u.x][u.y][u.d][u.c] + 1;
            q.push(v);
        }

        v = u;
        v.d = (v.d + 3) % 4;
        if(f[v.x][v.y][v.d][v.c] == -1) {
            f[v.x][v.y][v.d][v.c] = f[u.x][u.y][u.d][u.c] + 1;
            q.push(v);
        }

        v = u;
        v.x += d[v.d][0];
        v.y += d[v.d][1];
        v.c = (v.c + 1) % 5;
        if(s[v.x][v.y] && s[v.x][v.y] != '#' && f[v.x][v.y][v.d][v.c] == -1) {
            f[v.x][v.y][v.d][v.c] = f[u.x][u.y][u.d][u.c] + 1;
            q.push(v);
        }
    }
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        memset(s, 0, sizeof s);  //自己坑自己。。
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s[i] + 1);
            for(int j = 1; j <= m; ++j)
                if(s[i][j] == 'S') sx = i, sy = j;
        }
        printf("%d\n", bfs());
    }
    return 0;
}
