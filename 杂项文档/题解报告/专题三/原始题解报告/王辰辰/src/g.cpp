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
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
const int M = 300100;
const int N = 3005;

int st, ed;
int head[1005], d[1005];
bool leap[1005];

struct Node {
    int u, v, w, nxt;
}node[200100];

struct Dinic {

    int pnt[M], cap[M], nxt[M], head[N], cnt;

    void init() {
        memset(head, -1, sizeof(head));
        cnt = 0;
    }

    void addedge(int u, int v, int w) {
        pnt[cnt] = v;
        cap[cnt] = w;
        nxt[cnt] = head[u];
        head[u] = cnt++;
    }

    void add_double(int u, int v, int w1, int w2) {
        addedge(u, v, w1);
        addedge(v, u, w2);
    }

    int lev[N], cur[N];
    bool bfs(int s, int t) {
        queue<int> q;
        memset(lev, -1, sizeof(lev));
        q.push(s); lev[s] = 0;
        while(q.size() && lev[t] == -1) {
            int u = q.front(); q.pop();
            for(int i = head[u]; i != -1; i = nxt[i]) {
                int v = pnt[i];
                if(cap[i] > 0 && lev[v] == -1) {
                    lev[v] = lev[u] + 1;
                    q.push(v);
                }
            }
        }
        return lev[t] != -1;
    }

    int dfs(int u, int t, int delta) {
        if(u == t) return delta;
        int ret = 0;
        for(int i = cur[u]; i != -1; i = nxt[i]) {
            int v = pnt[i];
            if(cap[i] > 0 && lev[v] == lev[u] + 1) {
                int d = dfs(v, t, min(delta, cap[i]));
                cur[u] = i;
                ret += d; delta -= d;
                cap[i] -= d;
                cap[i ^ 1] += d;

                if(delta == 0) return ret;
            }
        }
        lev[u] == -1;
        return ret;
    }

    int dinic(int s, int t) {
        int ret = 0;
        while(bfs(s, t)) {
            for(int i = s; i <= t; i++) cur[i] = head[i];
            ret += dfs(s, t, inf);
        }
        return ret;
    }
}ans;

void add_edge(int u, int v, int w, int tot) {
    node[tot].u = u; node[tot].v = v;
    node[tot].w = w;
    node[tot].nxt = head[u];
    head[u] = tot;
}

void dij(int n) {
    memset(leap, false, sizeof(leap));
    for(int i = 1; i <= n; i++) d[i] = inf;
    queue <int> p;
    p.push(st);
    leap[st] = true; d[st] = 0;
    while(p.size()) {
        int u = p.front(); p.pop();
        leap[u] = false;
        for(int i = head[u]; i != -1; i = node[i].nxt) {
            int v = node[i].v;
            if(d[v] > d[u] + node[i].w) {
                d[v] = d[u] + node[i].w;
                if(!leap[v]) {
                    leap[v] = true;
                    p.push(v);
                }
            }
        }
    }
}

inline int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();

    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
    #endif // LOCAL
    int t; scanf("%d", &t);
    while(t--) {
        int n, m; scanf("%d%d", &n, &m);
        if(n == 1 && m == 0) {
            printf("0\n"); continue;
        }
        ans.init();
        memset(head, -1, sizeof(head));
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w, i);
        }
        scanf("%d%d", &st, &ed);
        dij(n);
        for(int u = 1; u <= n; u++) {
            for(int i = head[u]; i != -1; i = node[i].nxt) {
                int v = node[i].v;
                //cout<<i<<" "<<v<<" "<<node[i].w<<endl;
                if(d[v] - d[u] == node[i].w)
                    ans.add_double(u, v, 1, 0);
            }
        }
        ans.add_double(0, st, inf, 0);
        ans.add_double(ed, n + 1, inf, 0);
        printf("%d\n", ans.dinic(0, n + 1));
    }
    return 0;
}
