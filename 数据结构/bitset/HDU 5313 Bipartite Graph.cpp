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

const int N = 10010;

int n, m;
vector<int> g[N];
int num[N][2];
int vis[N];
int cnt0, cnt1;

void dfs(int u, int cnt) {
	vis[u] = cnt;
	if (vis[u] == 1) cnt0++;
	else cnt1++;
	for (auto& v : g[u]) {
		if (!vis[v]) dfs(v, -cnt);
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	SII(n, m);
    	for (int i = 1; i <= n; i++)
    		g[i].clear();
    	for (int i = 1; i <= m; i++) {
    		int u, v; SII(u, v);
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
    	CLR(vis);
    	int cnt = 0;
    	for (int i = 1; i <= n; i++) if (!vis[i]) {
    		cnt0 = cnt1 = 0;
    		dfs(i, 1);
    		num[++cnt][0] = cnt0;
    		num[cnt][1] = cnt1;
    	}
    	// lookln(cnt);
    	bitset<N> dp;
    	dp.set(0);
    	for (int i = 1; i <= cnt; i++) {
    		dp = (dp << num[i][0]) | (dp << num[i][1]);
    	}
    	ll ans = 0;
    	for (int i = n / 2; i >= 1; i--) {
    		if (dp.test(i)) {
    			ans = i;
    			break;
    		}
    	}
    	ans = (n - ans) * ans - m;
    	printf("%lld\n", ans);
    }
	return 0;
}