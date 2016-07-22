#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ml m
#define mr m + 1
using namespace std;
const int maxn = 1e5 + 15;
const int maxm = 1e6 + 15;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1e9 + 7;

struct Edge {
    int to, next;
} edge[maxm];

int ecnt, head[maxn];

ll quickPow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) res = res * x % mod;
        y >>= 1; x = x * x % mod;
    }
    return res;
}

ll inv(ll x) {
    return quickPow(x, mod - 2);
}

void add(int u, int v) {
    edge[ecnt].to = v;
    edge[ecnt].next = head[u];
    head[u] = ecnt++;
}

ll w[maxn], ans[maxn], val[maxn], Sum;
int dfn[maxn], low[maxn], cnt, vis[maxn];

void init() {
    Sum = cnt = ecnt = 0;
    memset(vis, 0, sizeof vis);
    memset(dfn, 0, sizeof dfn);
    memset(head, -1, sizeof head);
}

void dfs(int u) {
    vis[u] = 1; val[u] = w[u];
    for(int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if(vis[v]) continue; dfs(v);
        val[u] = val[u] * val[v] % mod;
    }
}

ll tarjan(int fa, int u, int root) {
    dfn[u] = low[u] = ++cnt; int chd = 0, fg = 0;
    ll mul, sum, ret;
    mul = w[u]; sum = 0; ret = w[u];
    for(int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if(!dfn[v]) {
            chd++;
            ll tt = tarjan(u, v, root);
            low[u] = min(low[u], low[v]);
            if (!fa) sum = (sum + tt) % mod;
            if(!fa && chd > 1) fg = 1;
            if(fa && low[v] >= dfn[u]) {
                fg = 1;
                mul = mul * tt % mod;
                sum = (sum + tt) % mod;
            }
            ret = ret * tt % mod;
        }
        else if(v != fa)
            low[u] = min(low[u], dfn[v]);
    }
    if(!fg) {
        ans[u] = (Sum - val[root] + mod) % mod;
        if (fa || head[u] != -1)  ans[u] = (ans[u] + val[root] * inv(w[u])) % mod;
    }
    else {
        // cout << "u = " << u << endl;
        ans[u] = (Sum - val[root] + mod) % mod;
        // cout << "ans[u] = " << ans[u] << endl;
        ll pre = val[root] * inv(mul) % mod;
        if (fa) sum = (sum + pre) % mod;
        ans[u] =(ans[u] + sum) % mod;
        // cout << "ans[u] = " << ans[u] << endl;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; scanf("%d", &t);
    while(t--) {
        int n, m; init();
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++) scanf("%lld", w + i);
        for(int i = 1; i <= m; i++) {
            int u, v; scanf("%d %d", &u, &v);
            add(u, v); add(v, u);
        }
        vector<int> vec;
        for(int i = 1; i <= n; i++) {
            if(vis[i]) continue;
            vec.push_back(i); dfs(i);
            Sum = (Sum + val[i]) % mod;
        }
        for(int i = 0; i < vec.size(); i++)
            tarjan(0, vec[i], vec[i]);
        ll S = 0;
        // for (int i = 1; i <=  n; i++)
        //     cout << ans[i] << ' ';
        // cout << endl;
        for(int i = 1; i <= n; i++)
            S = (S + ans[i] * i % mod) % mod;
        printf("%lld\n", S);
    }
    return 0;
}