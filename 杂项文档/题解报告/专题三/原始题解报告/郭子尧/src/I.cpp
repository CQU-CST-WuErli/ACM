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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 111;
const int MAXM = 4e4 + 111;

struct Edge {
    int to, nxt;
}edge[MAXM];
bool vis[MAXM];
int head[MAXN], dfn[MAXN], low[MAXN];
bool in[MAXN];
int tol, indx, ans;

void init(int n) {
    indx = ans = 0;
    for (int i = 1; i <= n; ++i) {
        dfn[i] = in[i] = 0;
    }
}

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

void tarjan(int u) {
    int v;
    dfn[u] = low[u] = ++indx;
    in[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (vis[i]) continue;
        vis[i] = vis[i^1] = 1;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                ++ans;
            }
        }
        else if (in[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    in[u] = 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        scanf("%d%d", &n, &m);
        tol = 0;
        memset(head, -1, sizeof head);
        init(n);
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) tarjan(i);
        }
        printf("Case %d: %d\n", kase, ans);
    }
    return 0;
}
