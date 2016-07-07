#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const int maxm = 1e6 + 50;

int n, m, cnt, vis[maxn];
int head[maxn], deg[maxn];
int pnt[maxm], nxt[maxm];

void add_edge(int u, int v) {
    pnt[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}


int main() {
#ifdef LOCAL
	freopen("1.in","r",stdin);
    freopen("out.in","w",stdout);
#endif
      while (~scanf("%d%d", &n, &m)) {
            memset(head, 0xff, sizeof head);
            memset( vis, 0x00, sizeof  vis);

            cnt = 0;
            while (m--) {
                int u,v;
                scanf("%d%d",&u,&v);
                add_edge(u, v);
                deg[v]++;
            }
            queue<int> q;
            int tot = n;
            for (int i = 1; i <= n; i++) {
                if(deg[i]) continue;
                q.push(i);
                tot--;
                vis[i] = 1;
            }
            while (q.size()) {
                int u = q.front();q.pop();
                for (int i = head[u]; ~i; i = nxt[i]) {
                    int v = pnt[i];
                    deg[v]--;
                    if (deg[v] || vis[v]) continue;
                    q.push(v);
                    vis[v] = 1;
                    tot--;
                }
            }
            if (tot) puts("Yes");
            else puts("No");
      }
}