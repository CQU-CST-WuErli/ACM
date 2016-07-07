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

int n, c, m, a[20];
int f[5005];
pair<int, int> pre[5005];

void print(int u) {
    if(~u) {
        print(pre[u].first);
        int x = a[pre[u].second];
        putchar(x < 10 ? '0' + x : 'A' + x - 10);
    }
}

bool bfs() {
    queue<int> q;
    memset(f, -1, sizeof f);
    for(int i = 1; i <= m; ++i) {
        if(!a[i]) continue;
        int s = a[i] % n;
        if(f[s] == -1) {
            f[s] = 1;
            pre[s] = { -1, i};
            q.push(s);
        }
    }
    while(q.size()) {
        int u = q.front(); q.pop();
        if(f[u] > 500) continue;
        if(u == 0) {
            print(0); puts("");
            return true;
        }
        for(int i = 1; i <= m; ++i) {
            int v = (u * c + a[i]) % n;
            if(f[v] == -1) {
                f[v] = f[u] + 1;
                pre[v] = {u, i};
                q.push(v);
            }
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &c, &m);
        for(int i = 1; i <= m; ++i) {
            char buf[2]; scanf("%s", buf);
            if(isdigit(*buf)) *buf -= '0';
            else *buf -= 'A' - 10;
            a[i] = *buf;
        }
        sort(a + 1, a + 1 + m);
        if(n == 0) {
            if(a[1] == 0) puts("0");
            else puts("BOMB!!!");
        } else if(!bfs()) puts("BOMB!!!");
    }
    return 0;
}
