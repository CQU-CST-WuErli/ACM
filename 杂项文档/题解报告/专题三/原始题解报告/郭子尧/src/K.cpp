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
const int MAXM = 3e4 + 111;

struct P {
    int n, w;
    bool operator < (const P &t)const {
        if (t.w == w) return n < t.n;
        return w < t.w;
    }
}p[MAXN];
vector<int> G[MAXN];
vector<int> M[MAXN];
int dfn[MAXN], low[MAXN], id[MAXN], sta[MAXN], in[MAXN], w[MAXN], tol[MAXN];
int vis[MAXN];
int scc, top, indx;
int u[MAXM], v[MAXM];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
        M[i].clear();
        vis[i] = 0;
        dfn[i] = 0;
        tol[i] = 0;
        in[i] = 0;
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

    int t = -1;
    if (dfn[u] == low[u]) {
        ++scc;
        do {
            v = sta[--top];
            ++t;
            in[v] = 0;
            id[v] = scc;
        } while (u != v);
        w[scc] = t;
    }
}

void flow(int p, int u) {
    vis[u] = p;
    for (int i = 0; i < M[u].size(); ++i) {
        int v = M[u][i];
        if (vis[v] != p) {
            tol[v] += w[p] + 1;
            //pr(v)
            flow(p, v);
        }
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
            ++u[i], ++v[i];
            G[u[i]].push_back(v[i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) tarjan(i);
        }
        //pr(scc)
        for (int i = 0; i < m; ++i) {
            int x = id[u[i]], y = id[v[i]];
            if (x == y) continue;
            M[x].push_back(y);
        }
        for (int i = 1; i <= scc; ++i) {
            flow(i, i);
        }
        for (int i = 1; i <= n; ++i) {
            p[i].n = i;
            p[i].w = w[id[i]] + tol[id[i]];
        }
        sort(p + 1, p + n + 1);
        printf("Case %d: %d\n", kase, p[n].w);
        for (int i = 1; i <= n; ++i) {
            if (p[i].w != p[n].w) continue;
            printf("%d", p[i].n - 1);
            if (i != n) putchar(' ');
            else putchar('\n');
        }
    }
    return 0;
}
