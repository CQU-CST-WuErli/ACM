#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;
const int MAXM = 1e5 + 111;

vector<int> G[MAXN], G2[MAXN];
int dfn[MAXN], low[MAXN], id[MAXN], sta[MAXN], in[MAXN];
int scc, top, indx;
int u[MAXM], v[MAXM];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
        dfn[i] = 0;
    }
    scc = top = indx = 0;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++indx;
    sta[top++] = u;
    in[u] = 1;
    int v;
    for (int i = 0; i < G[u].size(); ++i) {
        v = G[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {
        ++scc;
        do {
            v = sta[--top];
            in[v] = 0;
            id[v] = scc;
        } while (u != v);
    }
}

int match[MAXN * 2];
bool vis[MAXN * 2];
bool dfs(int u) {
    for (int i = 0; i < G2[u].size(); ++i) {
        int v = G2[u][i];
        if (!vis[v]) {
            vis[v] = 1;
            if (!match[v] || dfs(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int solve() {
    int ret = 0;
    memset(match, 0, sizeof match);
    for (int i = 1; i <= scc; ++i) {
        memset(vis, 0, sizeof vis);
        if (dfs(i)) ++ret;
    }
    return ret;
}


void build(int p, int u) {
    in[u] = 1;
    for (int i = 0; i < G2[u].size(); ++i) {
        int v = G2[u][i];
        if (in[v]) continue;
        G2[p].push_back(v);
        build(p, v);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u[i], &v[i]);
            G[u[i]].push_back(v[i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) tarjan(i);
        }
        for (int i = 1; i <= scc; ++i) G2[i].clear();
        for (int i = 0; i < m; ++i) {
            int x = id[u[i]], y = id[v[i]];
            if (x == y) continue;
            G2[x].push_back(y);
        }
        for (int i = 1; i <= scc; ++i) {
            memset(in, 0, sizeof in);
            for (int j = 0; j < G2[i].size(); ++j) {
                build(i, G2[i][j]);
            }
        }
        printf("Case %d: %d\n", kase, scc - solve());
    }
    return 0;
}
