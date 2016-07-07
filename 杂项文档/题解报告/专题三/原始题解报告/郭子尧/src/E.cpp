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
const int MAXN = 5e3 + 111;
const int MAXM = 1e5 + 111;

vector<int> G[MAXN];
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
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
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

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u[i], &v[i]);
            G[u[i]].push_back(v[i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) tarjan(i);
        }
        int ans = n;
        for (int i = 1; i <= scc; ++i) G[i].clear();
        for (int i = 0; i < m; ++i) {
            int x = id[u[i]], y = id[v[i]];
            if (x == y) continue;
            G[x].push_back(y + scc);
        }
        printf("%d\n", scc - solve());
    }
    return 0;
}
