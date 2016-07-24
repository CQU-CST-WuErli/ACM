//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <bitset>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
typedef pair<int, int> pii;

const int N = 550;
int n, m;
int color[N], mp[N][N];
vector<int> g[N];
int dis[N][N], par[N][N], vis[N];

struct MCMF {
    const static int N = 3000;
    const static int M = 2e6;
    int pnt[M],head[N],nxt[M],cap[M],cost[M],pre[M];
    int cnt;
    int a[N],p[N],vis[N];
    ll d[N];
    void init() {
        OFF(head); cnt = 0;
    }
    void add_edge(int u, int v, int f, int w) {
        pnt[cnt] = v; pre[cnt] = u; nxt[cnt] = head[u]; head[u] = cnt;
        cap[cnt] = f; cost[cnt++] = w;
    }
    bool spfa(int s, int t, int& Flow, ll& Cost) {
        memset(a, 0, sizeof a);
        memset(vis, 0, sizeof vis);
        for (int i = s; i <= t; i++) d[i] = INF_INT;
        stack<int> q;
        vis[s] = 1;
        a[s] = INF_INT;
        d[s] = 0;
        q.push(s);
        while (q.size()) {
            int x = q.top(); q.pop();
            vis[x] = 0;
            for (int i = head[x]; ~i; i = nxt[i]) {
                int v = pnt[i];
                if (d[v] > d[x] + cost[i] && cap[i]) {
                    d[v] = d[x] + cost[i];
                    p[v] = i;
                    a[v] = min(a[x], cap[i]);
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }
        if (d[t] >= INF_INT) return false;
        Flow += a[t];
        Cost += a[t] * d[t];
        for (int u = t; u != s; u = pre[p[u]]) {
            cap[p[u]] -= a[t];
            cap[p[u] ^ 1] += a[t];
        }
        // lookln(Flow);
        return true;
    }
    pair <int, ll> solve(int s, int t) {
        int Flow = 0;
        ll Cost = 0;
        while (spfa(s, t, Flow, Cost));
        return make_pair(Flow, Cost);
    }
}mfmc;

void read() {
    SII(n, m);
    for (int i = 1; i <= n; i++)
        scanf("%1d", color + i);
    MEM(mp, INF_INT);
    for (int i = 1; i <= n; i++)
        mp[i][i] = 0;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= m; i++) {
        int u, v; SII(u, v);
        mp[u][v] = mp[v][u] = 1;
        g[u].push_back(v); g[v].push_back(u);
    }
}

bool dfs1(int fa, int u, int cnt) {
    vis[u] = cnt;
    for (auto & v : g[u]) {
        if (!vis[v]) if (!dfs1(u, v, -cnt)) return false;
        else if (vis[v] == vis[u]) return false;
    }
    return true;
}
bool binary_check() {
    CLR(vis);
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        if (!dfs1(-1, i, 1)) return false;
    }
    return true;
}

pii dfs2(int fa, int u) {
    pii ret(0, 0);
    vis[u] = 1;
    if (color[u] == 0) ret.first++;
    else ret.second++;
    for (auto& v : g[u]) {
        if (v == fa || vis[v]) continue;
        pii tmp = dfs2(u, v);
        ret.first += tmp.first;
        ret.second += tmp.second;
    }
    return ret;
}
bool num_check() {
    CLR(vis);
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        pii now = dfs2(-1, i);
        if (now.first != now.second && now.first + now.second != 1) {
        	return false;
        }
    }
    return true;
}

void getpre() {
    queue<int> q;
    for (int st = 1; st <= n; st++) {
        CLR(vis); MEM(dis[st], INF_INT);
        q.push(st);
        vis[st] = 1; dis[st][st] = 0;
        par[st][st] = st;
        while (q.size()) {
            int u = q.front(); q.pop();
            vis[u] = 0;
            for (auto& v : g[u]) {
                if (dis[st][v] > dis[st][u] + 1) {
                    dis[st][v] = dis[st][u] + 1;
                    par[st][v] = u;
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }
}

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
}

void getPoint(int fa, int u, int cnt, vector<int>&l, vector<int>& r) {
    vis[u] = cnt;
    if (cnt == 1) l.push_back(u);
    else r.push_back(u);
    for (auto & v : g[u]) {
        if (v == fa || vis[v] != 0) continue;
        getPoint(u, v, -cnt, l, r);
    }
}

int gao(vector<int>& l, vector<int>& r, int id, vector<pii>& op) {
    int ret = 0;
    mfmc.init();
    int source = 0, sink = n + 1;
    int cnt1 = 0, cnt2 = 0;
    for (auto& it : l) {
        mfmc.add_edge(source, it, 1, 0);
        mfmc.add_edge(it, source, 0, 0);
    }
    int cnt = 0;
    for (auto& u : l) if (color[u] == id) {
        cnt++;
        for (auto& v : r) if (color[v] == (id ^ 1)) {
            mfmc.add_edge(u, v, 1, mp[u][v]);
            mfmc.add_edge(v, u, 0, -mp[v][u]);
        }
    }
    for (auto& it : r) {
        mfmc.add_edge(it, sink, 1, 0);
        mfmc.add_edge(sink, it, 0, 0);
    }
    pair<int, ll> tmp = mfmc.solve(source, sink);
    if (tmp.first != cnt) return -1;
    for (auto& u : l) {
        for (int i = mfmc.head[u]; ~i; i = mfmc.nxt[i]) {
            int v = mfmc.pnt[i];
            if (v == source || mfmc.cap[i]) continue;
            while (par[u][v] != v) {
                op.push_back(make_pair(v, par[u][v]));
                v = par[u][v];
            }
        }
    }
    return tmp.second;
}

pair<int, bool> match(vector<int>& l, vector<int>& r, vector<pii>& op) {
    vector<pii> tmpa, tmpb;
    int t0 = gao(l, r, 0, tmpa);
    int t1 = gao(l, r, 1, tmpb);
    if (t0 == -1 && t1 == -1) return make_pair(-1, false);
    if (t0 == -1 || t1 < t0) {
        t0 = t1;
        tmpa.swap(tmpb);
    }
    op.insert(op.end(), tmpa.begin(), tmpa.end());
    return make_pair(t0, true);
}

bool solve() {
    read();
    if (!binary_check()) return false;
    if (!num_check()) return false;
    getpre(); floyd();
    // preprocess
    CLR(vis);
    vector<int> l, r;
    vector<pii> ans, op;
    ll times = 0;
    for (int i = 1; i <= n; i++) if (vis[i] == 0) {
        l.clear(); r.clear();
        getPoint(-1, i, 1, l, r);
        op.clear();
        if (l.size() + r.size() == 1) continue;
        pair<int, bool> tt = match(l, r, op);
        if (!tt.second) return false;
        times += tt.first;
        ans.insert(ans.end(), op.begin(), op.end());
    }
    // lookln(times);
    cout << times << endl;
    for (auto& it : ans) {
        printf("%d %d\n", it.first, it.second);
    }
    return true;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T, kase = SI(T_T); kase <= T_T; kase++) {
        if (!solve()) puts("-1");
    }
    return 0;
}