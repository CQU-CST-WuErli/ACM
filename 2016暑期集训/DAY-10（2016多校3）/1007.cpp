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

const int N = 100010;

int n;
vector<int> g[N];
int dp[N][2];
int sz[N];
int deg[N];

void init() {
    for (int i = 1; i <= n; i++) g[i].clear();
    CLR(deg);
}

void dfs(int fa, int u) {
    int child = 0;
    sz[u] = 0;
    dp[u][0] = 0; dp[u][1] = INF_INT;
    for(int i = 0; i < g[u].size(); i++) {
    	int v = g[u][i];
        if(v == fa) continue;
        dfs(u, v); child++; sz[u] += sz[v];
        int d = (sz[v] & 1) ? 1 : 2;
        dp[u][0] += dp[v][0] + d;
    }
    for(int i = 0; i < g[u].size(); i++) {
    	int v = g[u][i];
    	if (v == fa) continue;
    	if (child > 1 && sz[v] == 1) dp[u][1] = min(dp[u][1], dp[u][0]); // 链接过来
        if(dp[v][1] == INF_INT) continue; // 自己未更新就不更新
        int d = (sz[v] & 1) ? 1 : -1;
        dp[u][1] = min(dp[u][1], dp[u][0] - dp[v][0] + dp[v][1] + d);
    }
    if(!child) sz[u] = 1;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int T; SI(T);
    while (T--) {
        SI(n);
        init();
        for (int i = 1; i < n; i++) {
            int u, v; SII(u, v);
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        int root = 1, leaf = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i] != 1) root = i;
            else leaf++;
        }
        dfs(-1, root);
        printf("%d\n", dp[root][leaf & 1]);
    }
    return 0;
}