//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
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
int vis[N];
int pre[N],low[N],iscut[N];
int dfs_clock;
int child[N];

int dfs(int fa,int u) {
	low[u] = pre[u] = ++dfs_clock;
	int son = 0;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == fa || pre[v] >= INF_INT);
		if (!pre[v]) {
			son++;
			int lowv = dfs(u, v);
			low[u]= min(low[u], lowv);
			if (lowv >= pre[u])
				child[u]++;
		}
		else low[u] = min(low[u], pre[v]);
	}
	if (fa < 0) child[u]--;
	return low[u];
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n, m) == 2) {
    	for (int i = 0 ; i <= n; i++) g[i].clear();
        for (int i = 1; i <= m; i++) {
        	int u, v;
        	SII(u, v);
        	g[u].push_back(v);
        	g[v].push_back(u);
        }
        int num = 0;
        for (int i = 0; i < n; i++) {
        	CLR(low); CLR(pre); CLR(child); dfs_clock = 0;
        	CLR(iscut);
        	int ans = 0;
        	pre[i] = INF_INT;
        	for (int j = 0; j < n; j++) if (!pre[j] && j != i) {
        		ans++;
        		dfs(-1, j);
        	}
        	for (int j = 0; j < n; j++) if (j != i) num = max(num, ans + child[j]);
        }
        cout << num << endl;
    }
	return 0;
}