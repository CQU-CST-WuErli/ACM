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
#include <ctime>
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

const int N = 5e5 + 10;

struct Edge {
	int u, v, w;
	Edge(int u, int v, int w):u(u), v(v), w(w) {}
	Edge() {}
	bool operator < (const Edge& rhs) const {
		return w < rhs.w;
	}
};
vector<Edge> es;
int n, m;
int par[N], rnk[N];

void init() {
	for (int i = 1; i <= n; i++) par[i] = i, rnk[i] = 0;
}

int find(int x) {
	if (par[x] == x)  return x;
	else return par[x] = find(par[x]);
}

bool same(int x, int y) {
	return find(x) == find(y);
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) par[x] = y;
	else {
		par[y] = x;
		if (rnk[x] == rnk[y]) rnk[x]++;
	}
}

int kruskal() {
	init();
	sort(es.begin(), es.end());
	int ret = INF_INT;
	for (int i = 0; i < es.size(); i++) {
		Edge& e = es[i];
		if (!same(e.u, e.v)) {
			unite(e.u, e.v);
		}
		else {
			ret = e.w;
			// BUG;
			break;
		}
	}
	return ret;
}

int main(int argc, char const *argv[]) {
    int t; SI(t);
    while(t--) {
    	SII(n, m);
    	es.clear();
    	for (int i = 1; i <= m; i++) {
    		int u, v, w;
    		SIII(u, v, w);
    		es.push_back(Edge(u, v, w));
    	}
    	int ans = kruskal();
    	if (ans >= INF_INT) puts("No solotion!");
    	else cout << ans << endl;
    }
	return 0;
}