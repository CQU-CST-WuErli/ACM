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
const int MAXN = 5e5 + 111;
const int MAXM = 2e6 + 111;

struct Edge {
    int u, v, w;
    bool use;
    bool operator < (const Edge &t) const {
        return w < t.w;
    }
}edge[MAXM];
int p[MAXN];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) p[i] = i;
        int u, v, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
            edge[i].use = 0;
        }
        sort(edge, edge + m);
        for (int i = 0; i < m; ++i) {
            int u = find(edge[i].u), v = find(edge[i].v);
            if (u != v) {
                edge[i].use = 1;
                p[u] = v;
            }
        }
        int ans = INF;
        for (int i = 0; i < m; ++i) {
            if (!edge[i].use) {
                ans = min(ans, edge[i].w);
            }
        }
        if (ans == INF) puts("No solution!");
        else printf("%d\n", ans);
    }
    return 0;
}
