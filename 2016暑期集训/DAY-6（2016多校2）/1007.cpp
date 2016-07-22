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
int color[N];
int mp[N][N];
vector<int> g[N];
int dis[N][N];
int par[N][N];
int vis[N];

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
		if (now.first != now.second) return false;
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



bool solve() {
	read();
	if (!binary_check()) return false;
	if (!num_check()) return false;
	getpre(); floyd();
	// preprocess

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