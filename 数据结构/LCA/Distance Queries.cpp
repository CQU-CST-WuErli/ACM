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

const int N = 1e5;
int n, m;
struct Edge
{
	int v, w;
	Edge(int v, int w):v(v), w(w){}
};
vector<Edge> g[N];

struct Q
{
	int v, id;
	Q(int v, int id):v(v), id(id){}
};
vector<Q> query[N];

int par[N];
int dis[N];
int vis[N];
int ans[N];

int find(int x) {
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void dfs(int u, int fa, int cnt) {
	dis[u] = cnt;
	par[u] = u;
	vis[u] = 1;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].v;
		int w = g[u][i].w;
		if (v == fa) continue;
		dfs(v, u, cnt + w);
		par[v] = u;
	}
	for (int i =0; i < query[u].size(); i++) {
		Q& q = query[u][i];
		if (vis[q.v]) ans[q.id] = dis[u] + dis[q.v] - 2 * dis[find(q.v)];
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n, m) == 2) {
    	for (int i = 1; i <= n; i++) g[i].clear(), query[i].clear();
        for (int i = 1; i <= m; i++) {
        	int u, v, c;
        	char op;
        	scanf("%d%d%d", &u, &v, &c);
        	// cout << u << ' ' << v << ' ' << c << endl;
        	cin >> op;
        	g[u].push_back(Edge(v, c));
        	g[v].push_back(Edge(u, c));
        }
        int q;
        SI(q);
        for (int i = 1; i <= q; i++) {
            int u, v;
            SII(u, v);
            query[u].push_back(Q(v, i));
            query[v].push_back(Q(u, i));
        }
        CLR(vis); CLR(dis);
        dfs(1, -1, 0);
        for (int i = 1; i <= q; i++) cout << ans[i] << endl;
    }
	return 0;
}