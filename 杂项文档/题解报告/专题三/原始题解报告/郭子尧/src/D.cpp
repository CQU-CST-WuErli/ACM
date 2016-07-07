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
const int MAXN = 2e3 + 111;

struct P {
    int a, b;
}hate[MAXN], like[MAXN];
int dis[MAXN], disab, n, a, b;
vector<int> G[MAXN];
int dfn[MAXN], low[MAXN], sta[MAXN], id[MAXN], scc, top, indx;
bool in[MAXN];

void init() {
    for (int i = 0; i < 2 * n; ++i) {
        dfn[i] = in[i] = 0;
        G[i].clear();
    }
    scc = top = indx = 0;
}

int getdis(int x, int y, int x1, int y1) {
    return abs(x - x1) + abs(y - y1);
}

void build(int up) {
    init();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int l1 = dis[i], l2 = dis[j];
            int r1 = dis[i + n], r2 = dis[j + n];
            if (l1 + l2 > up) {
                G[i].push_back(j + n);
                G[j].push_back(i + n);
            }
            if (r1 + r2 > up) {
                G[i + n].push_back(j);
                G[j + n].push_back(i);
            }
            if (l1 + r2 + disab > up) {
                G[i].push_back(j);
                G[j + n].push_back(i + n);
            }
            if (l2 + r1 + disab > up) {
                G[i + n].push_back(j + n);
                G[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < a; ++i) {
        int l = hate[i].a, r = hate[i].b;
        G[l].push_back(r + n);
        G[r].push_back(l + n);
        G[l + n].push_back(r);
        G[r + n].push_back(l);
    }

    for (int i = 0; i < b; ++i) {
        int l = like[i].a, r = like[i].b;
        G[l].push_back(r);
        G[l + n].push_back(r + n);
        G[r].push_back(l);
        G[r + n].push_back(l + n);
    }
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
        } while (v != u);
    }
}

bool ok() {
    for (int i = 0; i < 2 * n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 0; i < n; ++i) {
        if (id[i] == id[i + n]) return 0;
    }
    return 1;
}


int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    int c, d, e, f, g, h, t; scanf("%d", &t);
    while (t --) {
        scanf("%d%d%d", &n, &a, &b);
        scanf("%d%d%d%d", &c, &d, &e, &f);
        disab = getdis(c, d, e, f);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &g, &h);
            dis[i] = getdis(c, d, g, h);
            dis[i + n] = getdis(e, f, g, h);
        }

        for (int i = 0; i < a; ++i) {
            scanf("%d%d", &hate[i].a, &hate[i].b);
            --hate[i].a, --hate[i].b;
        }
        for (int i = 0; i < b; ++i) {
            scanf("%d%d", &like[i].a, &like[i].b);
            --like[i].a, --like[i].b;
        }

        int l = 0, r = 1e7, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            build(mid);
            if (ok()) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
