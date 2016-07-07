// The essay's link: http://www.docin.com/p-188285204.html
// For reference only
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
const int MAXM = 4e3 + 222;

struct Edge {
    int to, next;
}edge[MAXM];
int n, m, head[MAXN], tol;
struct P {
    int id, deg, toldeg;
    bool operator < (const P &t) const {
        return toldeg > t.toldeg;
    }
}p[MAXN];
bool cut[MAXM];
bool notin[MAXN];
bool vis[MAXN];

void init() {
    tol = 0;
    memset(head, -1, sizeof head);
    memset(cut, 0, sizeof cut);
    memset(vis, 0, sizeof vis);
    memset(notin, 0, sizeof notin);
}

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, u, v; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        int nodenum = 0, ans = 0, edgenum = 0, mxnodenum = n;
        while (edgenum < m) {
            for (int i = 1; i <= n; ++i) {
                p[i].id = i;
                p[i].deg = 0;
                p[i].toldeg = 0;
                vis[i] = 0;
            }
            for (int i = 1; i <= n; ++i) {
                if (!notin[i]) {
                    for (int j = head[i]; ~j; j = edge[j].next) {
                        if (cut[j]) continue;
                        int v = edge[j].to;
                        if (!notin[v] && !vis[v])
                            ++p[i].deg;
                    }
                }
            }
            for (int i = 1; i <= n; ++i) {
                p[i].toldeg = p[i].deg;
                if (!notin[i]) {
                    for (int j = head[i]; ~j; j = edge[j].next) {
                        if (cut[j]) continue;
                        int v = edge[j].to;
                        if (!notin[v] && !vis[v])
                            p[i].toldeg += p[edge[j].to].deg;
                    }
                }
            }
            sort(p + 1, p + 1 + n);
            for (int i = 1; i <= n; ++i) {
                if (p[i].deg == 0) break;
                if (notin[i] || vis[v]) continue;
                ++ans;
                //pr(p[i].id)
                --mxnodenum;
                ++nodenum;
                int u = p[i].id;
                notin[u] = 1;
                for (int j = head[u]; ~j; j = edge[j].next) {
                    if (cut[j]) continue;
                    ++edgenum;
                    int v = edge[j].to;
                    cut[j] = cut[j ^ 1] = 1;
                    if (!notin[v] && !vis[v]) {
                        ++nodenum;
                        vis[v] = 1;
                    }
                }
                if (nodenum >= mxnodenum) break;
            }
        }
        if (ans > 10) printf("Poor lcy\n");
        else printf("%d\n", ans);
    }
    return 0;
}
