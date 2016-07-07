#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;

int n, m, k;
int head[10010],d[10010];
bool leap[10010];
struct Node {
    int u, v, w, cap, nxt;
}node[100100];

void add_edge(int u, int v, int w, int cap, int tot) {
    node[tot].u = u; node[tot].v = v;
    node[tot].w = w; node[tot].cap = cap;
    node[tot].nxt = head[u];
    head[u] = tot;
}

void spfa(int up) {
    for(int i = 1; i <= n; i++) d[i] = inf;
    memset(leap, false, sizeof(leap));
    leap[1] = true; d[1] = 0;
    queue <int> p;
    p.push(1);
    while(p.size()) {
        int u = p.front(); p.pop();
        leap[u] = false;
        for(int i = head[u]; i != -1; i = node[i].nxt) {
            if(node[i].cap < up) continue;
            int v = node[i].v;
            if(d[v] > d[u] + node[i].w) {
                d[v] = d[u] + node[i].w;
                if(!leap[v]) {
                    leap[v] = true; p.push(v);
                }
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
    #endif // LOCAL
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        memset(head, -1, sizeof(head));
        for(int i = 1; i <= m; i++) {
            int u, v, w, cap;
            scanf("%d%d%d%d", &u, &v, &cap, &w);
            add_edge(u, v, w, cap, i * 2 - 1);
            add_edge(v, u, w, cap, i * 2);
        }
        spfa(0);
        if(d[n] == inf || d[n] > k)
            printf("Poor RunningPhoton!\n");
        else {
            int l = 0, r = 2000000001;
            while(r - l > 1) {
                int mid = (l + r) / 2;
                spfa(mid);
                if(d[n] == inf || d[n] > k)
                    r = mid;
                else
                    l = mid;
            }
            printf("%lld\n", l);
        }
    }
    return 0;
}
