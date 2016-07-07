//
//  Created by TaoSama on 2016-05-28
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

struct Window {
    int a[4][4];
    bool operator==(const Window& w) const {
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                if(a[i][j] != w.a[i][j]) return false;
        return true;
    }
    void see() {
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                printf("%d%c", a[i][j], " \n"[j == 3]);
        puts("");
    }
};

bool vis[9];
int path[9];
vector<Window> s;
void dfs(int dep, Window w) {
    if(dep == 9) {
        for(int i = 0; i < dep; ++i) printf("%d ", path[i]); puts("");
        w.see();
        s.push_back(w);
        return ;
    }
    for(int i = 0; i < 9; ++i) {
        if(vis[i]) continue;
        Window n = w;
        int x = i / 3, y = i % 3;
        for(int tx = 0; tx < 2; ++tx) {
            for(int ty = 0; ty < 2; ++ty) {
                int nx = x + tx, ny = y + ty;
                n.a[nx][ny] = i;
            }
        }
        path[dep] = i;
        vis[i] = true;
        dfs(dep + 1, n);
        vis[i] = false;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\input.txt", "r", stdin);
    freopen("C:\\Users\\TaoSama\\Desktop\\out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    dfs(0, Window());

    int t; scanf("%d", &t);
    while(t--) {
        Window w;
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                scanf("%d", &w.a[i][j]), --w.a[i][j];

        puts(find(s.begin(), s.end(), w) != s.end() ?
             "Lucky dog!" : "BOOM!");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}

