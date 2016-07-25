//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <algorithm>
#include <cstring>

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

typedef long long  ll;
using namespace std;

const int N = (1 << 16) + 100;

int n;
char op[10];
ll w[N];
vector<int> g[N];
ll val[N];
ll dp[256][256];
ll backup[N][256];

ll opt(ll a, ll b) {
	if (op[0] == 'A') return a & b;
	if (op[0] == 'O') return a | b;
	return a ^ b;
}

void dfs(int fa, int u) {
	ll tmp = 0;
	ll a = w[u] >> 8, b = w[u] & 255;
	for (int i = 0; i < 256; i++) if (dp[i][b] != -1) {
		tmp = max(tmp, dp[i][b] + opt(a, i) * 256);
	}
	val[u] = tmp + w[u];
	copy(dp[a], dp[a] + 256, backup[u]);
    for (int i = 0; i < 256; i++) {
        dp[a][i] = max(dp[a][i], tmp + opt(i, b));
    }
	for (auto& v : g[u]) {
		if (v == fa) continue;
		dfs(u, v);
	}
	copy(backup[u], backup[u] + 256, dp[a]);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T, kase = SI(T_T); kase <= T_T; kase++) {
    	SI(n); scanf("%s", op);
    	for (int i = 1; i <= n; i++)
    		g[i].clear();
    	for (int i = 1; i <= n; i++)
    		scanf("%lld", w + i);
    	for (int i = 2; i <= n; i++) {
    		int fa; SI(fa);
    		g[fa].push_back(i);
    		g[i].push_back(fa);
    	}
    	OFF(dp);
    	dfs(-1, 1);
    	ll ans = 0;
    	for (int i = 1; i <= n; i++) {
            ans = ans + 1LL * i * val[i];
            ans %= MOD;
    	}
    	printf("%lld\n", ans);
    }
	return 0;
}