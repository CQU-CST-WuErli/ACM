//
//  Created by TaoSama on 2016-05-29
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



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    vector<int> choice[4][4];
    for(int i = 0; i < 9; ++i) {
        int x = i / 3, y = i % 3;
        for(int tx = 0; tx < 2; ++tx) {
            for(int ty = 0; ty < 2; ++ty) {
                int nx = x + tx, ny = y + ty;
                choice[nx][ny].push_back(i);
            }
        }
    }

    int t; scanf("%d", &t);
    while(t--) {
        vector<int> G[9], in(9, 0);
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                int x; scanf("%d", &x); --x;
                for(int k = 0; k < choice[i][j].size(); ++k) {
                    int y = choice[i][j][k];
                    if(x == y) continue;
                    G[x].push_back(y);
                    ++in[y];
                }
            }
        }

        int topo = 0;
        queue<int> q;
        for(int i = 0; i < 9; ++i) if(!in[i]) q.push(i);
        while(q.size()) {
            int u = q.front(); q.pop();
            ++topo;
            for(int i = 0; i < G[u].size(); ++i) {
                int v = G[u][i];
                if(--in[v] == 0) q.push(v);
            }
        }

        puts(topo == 9 ? "Lucky dog!" : "BOOM!");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
