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
const int MAXM = 4e6 + 111;

struct P {
    int x, y;
}hate[MAXN], like[MAXN];

struct Edge {
    int to, next;
}edge[MAXM];
int head[MAXN], dfn[MAXN], low[MAXN], sta[MAXN], scc[MAXN];
int dis[MAXN], disab;
bool in[MAXN];
int tol, cnt, top, sccnum;
int n, a, b, up;

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}

void init() {
    cnt = top = sccnum = tol = 0;
    for (int i = 0; i < up; ++i) {
        head[i] = -1;
        dfn[i] = low[i] = scc[i] = in[i] = 0;
    }
}

int getdis(int x, int y, int a, int b) {
    return abs(x - a) + abs(y - b);
}

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    sta[top++] = u;
    in[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        //if (edge[i].w > mx) continue;
        int v = edge[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {
        ++sccnum;
        for (int v; v != u; ) {
            v = sta[--top];
            in[v] = 0;
            scc[v] = sccnum;
        }
    }
}

void build(int mx) {
    init();
    for (int i = 0; i < up; i += 2) {
        for (int j = i + 2; j < up; j += 2) {
            int l1 = dis[i], r1 = dis[i ^ 1];
            int l2 = dis[j], r2 = dis[j ^ 1];
            if (l1 + l2 > mx) {
                addedge(i, j ^ 1);
                addedge(j, i ^ 1);
            }
            if (r1 + r2 > mx) {
                addedge(i ^ 1, j);
                addedge(j ^ 1, i);
            }
            if (l1 + r2 + disab > mx) {
                addedge(i, j);
                addedge(j ^ 1, i ^ 1);
            }
            if (l2 + r1 + disab > mx) {
                addedge(i ^ 1, j ^ 1);
                addedge(j, i);
            }
        }
    }
    for (int i = 0; i < a; ++i) {
        int u = hate[i].x, v = hate[i].y;
        addedge(u, v ^ 1);
        addedge(v, u ^ 1);
        addedge(u ^ 1, v);
        addedge(v ^ 1, u);
    }
    for (int i = 0; i < b; ++i) {
        int u = like[i].x, v = like[i].y;
        addedge(u, v);
        addedge(v, u);
        addedge(u ^ 1, v ^ 1);
        addedge(v ^ 1, u ^ 1);
    }
}

bool ok(int mx) {
    build(mx);
    for (int i = 0; i < up; ++i) {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 0; i < up; i += 2) {
        if (scc[i] == scc[i ^ 1]) return 0;
    }
    return 1;
}

int main()
{
    freopen("in.txt", "r", stdin);
    // freopen("out2.txt", "w", stdout);
    int t, x1, y1, x2, y2, x, y; scanf("%d", &t);
    while (t --) {
        scanf("%d%d%d", &n, &a, &b);
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        up = 2 * n;
        disab = getdis(x1, y1, x2, y2);
        for (int i = 0; i < up; i += 2) {
            scanf("%d%d", &x, &y);
            dis[i] = getdis(x1, y1, x, y);
            dis[i ^ 1] = getdis(x2, y2, x, y);
        }
        for (int i = 0; i < a; ++i) {
            scanf("%d%d", &x, &y);
            --x, --y;
            hate[i].x = x * 2, hate[i].y = y * 2;
            //addedge(x, y^1, disab + min(disa[x] + disb[y], disa[y] + disb[x]));
            //addedge(x^1, y, disab + min(disa[x] + disb[y], disa[y] + disb[x]));
            //addedge(x^1, up, disb[x] + disa[y] + disab);
            //addedge(y, up, disa[y] + disb[x] + disab);
            //addedge(x^1, up + 1, disa[x] + disb[y] + disab);
            //addedge(y, up + 1, disb[y] + disa[x] + disab);
        }
        for (int i = 0; i < b; ++i) {
            scanf("%d%d", &x, &y);
            --x, --y;
            like[i].x = x * 2, like[i].y = y * 2;
            //addedge(x, y, min(disa[x] + disa[y], disb[y] + disb[x]));
            //addedge(x^1, y^1, min(disa[x] + disa[y], disb[y] + disb[x]));
            //addedge(x, up, disa[x] + disa[y]);
            //addedge(y, up, disa[y] + disa[x]);
            //addedge(x, up + 1, disb[x] + disb[y]);
            //addedge(y, up + 1, disb[y] + disb[x]);
        }

        int ans = -1, l = 0, r = 2e7;
        while (l <= r) {
            int mid = (l + r) / 2;
            //pr(mid)
            if (ok(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}