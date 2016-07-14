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

const int N = 1e4 + 111;
const int M = 1e6 + 111;

struct Edge {
    int to, next, w;
}edge[N * 2];
int head[N], tol;

struct Query {
    int to, next, id;
}query[M * 2];
int qhead[N], qtol, ans[M], par[N], dep[N];
bool vis[N];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

void addedge(int u, int v, int w) {
    edge[tol].to = v; edge[tol].next = head[u]; edge[tol].w = w;
    head[u] = tol++;
    edge[tol].to = u; edge[tol].next = head[v]; edge[tol].w = w;
    head[v] = tol++;
}

void qaddedge(int u, int v, int id) {
    query[qtol].to = v; query[qtol].next = qhead[u]; query[qtol].id = id;
    qhead[u] = qtol++;
    query[qtol].to = u; query[qtol].next = qhead[v]; query[qtol].id = id;
    qhead[v] = qtol++;
}

void init(int n) {
    tol = qtol = 0;
    for (int i = 1; i <= n; ++i) par[i] = i, vis[i] = 0;
    memset(head, -1, sizeof head);
    memset(qhead, -1, sizeof qhead);
}

void tarjan(int u, int cnt) {
    dep[u] = cnt;
    vis[u] = 1;
    par[u] = u;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (!vis[v]) {
            tarjan(v, cnt + edge[i].w);
            par[v] = u;
        }
    }

    for (int i = qhead[u]; ~i; i = query[i].next) {
        int v = query[i].to;
        if (vis[v]) ans[query[i].id] = dep[u] + dep[v] - 2 * dep[find(v)];
    }
}

int main() {
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int n, m, c;
    while (~scanf("%d%d%d", &n, &m, &c)) {
        init(n);
        int u, v, w;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
            u = find(u), v = find(v);
            if (u != v) par[u] = v;
        }
        for (int i = 0; i < c; i++) {
            scanf("%d%d", &u, &v);
            if (find(u) != find(v)) ans[i] = -1;
            else qaddedge(u, v, i);
        }

        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                tarjan(i, 0);
            }
        }
        for (int i = 0; i < c; ++i) {
            if (ans[i] == -1) printf("Not connected\n");
            else printf("%d\n", ans[i]);
        }
    }
    return 0;
}