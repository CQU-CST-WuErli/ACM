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

const int INF = 0x3f3f3f3f;
const int MAXN = 1e4 + 111;
const int MAXM = 1e5 + 111;

struct Edge {
    int to, cap, w, nxt;
}edge[MAXM];
int head[MAXN], dis[MAXN], tol, k;

void init(int n) {
    tol = 0;
    for (int i = 1; i <= n; ++i) {
        head[i] = -1;
    }
}

void addedge(int u, int v, int cap, int w) {
    edge[tol].to = v;
    edge[tol].cap = cap;
    edge[tol].w = w;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

bool in[MAXN];
bool spfa(int s, int n, int up) {
    for (int i = 1; i <= n; ++i) in[i] = 0, dis[i] = INF;
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    in[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to, cap = edge[i].cap, w = edge[i].w;
            if (cap < up) continue;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!in[v]) {
                    q.push(v);
                    in[v] = 1;
                }
            }
        }
    }
    return dis[n] <= k;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d%d", &n, &m, &k);
        init(n);
        int u, v, cap, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d%d", &u, &v, &cap, &w);
            addedge(u, v, cap, w);
            addedge(v, u, cap, w);
        }
        int ans = -1;
        int l = 0, r = 2e9;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (spfa(1, n, mid)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if (ans == -1) {
            puts("Poor RunningPhoton!");
        }
        else printf("%d\n", ans);
    }
    return 0;
}
