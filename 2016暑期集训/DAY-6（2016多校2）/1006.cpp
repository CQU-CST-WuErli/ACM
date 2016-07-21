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

const int N = 400040;

struct Edge {
    int to, next;
} edge[N];

int ecnt, head[N];

ll quickPow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) res = res * x % MOD;
        y >>= 1; x = x * x % MOD;
    }
    return res;
}

ll inv(ll x) {
    return quickPow(x, MOD - 2);
}

void add(int u, int v) {
    edge[ecnt].to = v;
    edge[ecnt].next = head[u];
    head[u] = ecnt++;
}

ll w[N >> 1], ans[N >> 1], val[N >> 1], Sum;
int dfn[N >> 1], low[N >> 1], cnt, vis[N >> 1];

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
        val[u] = val[u] * val[v] % MOD;
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
            if (!fa) sum = (sum + tt) % MOD;
            if(!fa && chd > 1) fg = 1;
            if(fa && low[v] >= dfn[u]) {
                fg = 1;
                mul = mul * tt % MOD;
                sum = (sum + tt) % MOD;
            }
            ret = ret * tt % MOD;
        }
        else if(v != fa)
            low[u] = min(low[u], dfn[v]);
    }
    if(!fg) {
        ans[u] = (Sum - val[root] + MOD) % MOD;
        if (fa || head[u] != -1)  ans[u] = (ans[u] + val[root] * inv(w[u])) % MOD;
    }
    else {
        // cout << "u = " << u << endl;
        ans[u] = (Sum - val[root] + MOD) % MOD;
        // cout << "ans[u] = " << ans[u] << endl;
        ll pre = val[root] * inv(mul) % MOD;
        if (fa) sum = (sum + pre) % MOD;
        ans[u] =(ans[u] + sum) % MOD;
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
            Sum = (Sum + val[i]) % MOD;
        }
        for(int i = 0; i < vec.size(); i++)
            tarjan(0, vec[i], vec[i]);
        ll S = 0;
        // for (int i = 1; i <=  n; i++)
        //     cout << ans[i] << ' ';
        // cout << endl;
        for(int i = 1; i <= n; i++)
            S = (S + ans[i] * i % MOD) % MOD;
        cout << S << endl;
    }
    return 0;
}
